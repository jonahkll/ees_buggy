#include "buggy_driver.h"

/*---------------------------------------Funktionen der
 * Motoren---------------------------------------*/
// Initialisieren von Adafruit Motor HAT und den Motoren 1 und 4
AdafruitMotorHAT motorHat = AdafruitMotorHAT();

std::shared_ptr<AdafruitDCMotor> motorLeft = motorHat.getMotor(1);
std::shared_ptr<AdafruitDCMotor> motorRight = motorHat.getMotor(4);

// Buggy fährt vorwärts
void driveForward(int speed) {
    motorLeft->setSpeed(speed);
    motorRight->setSpeed(speed);
    motorLeft->run(AdafruitDCMotor::kForward);
    motorRight->run(AdafruitDCMotor::kBackward);
}

// Buggy fährt rückwärts
void driveBackward(int speed) {
    motorLeft->setSpeed(speed);
    motorRight->setSpeed(speed);
    motorLeft->run(AdafruitDCMotor::kBackward);
    motorRight->run(AdafruitDCMotor::kForward);
}

// Buggy macht eine ca 90 Grad Links-Kurve
void turnLeft(int speed) {
    motorRight->setSpeed(speed);
    motorRight->run(AdafruitDCMotor::kBackward);
}

// Buggy macht eine ca 90 Grad Rechts-Kurve
void turnRight(int speed) {
    motorLeft->setSpeed(speed);
    motorLeft->run(AdafruitDCMotor::kForward);
}

// Alle Motoren werden gestoppt
void stopMotors() {
    motorLeft->setSpeed(0);
    motorRight->setSpeed(0);
    motorLeft->run(AdafruitDCMotor::kRelease);
    motorRight->run(AdafruitDCMotor::kRelease);
}

/*---------------------------------------Funktionen der
 * LED---------------------------------------*/
// LED wird angeschaltet
void turnLEDON(int led) { digitalWrite(led, HIGH); }

// LED wird ausgeschaltet
void turnLEDOFF(int led) { digitalWrite(led, LOW); }

/*---------------------------------------Funktionen des
 * HC-SR04---------------------------------------*/
// Die Distanz wird gemessen und in cm zurückgegeben
double measureDistance(int trigger, int echo) {
    // Sende ein 10us Trigger-Signal
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    // Warten auf das Echo-Signal
    unsigned long startTime = micros();
    while (digitalRead(echo) == LOW && micros() - startTime < 30000)
        ; // timeout

    // Messung der Zeit für das Echo-Signal
    startTime = micros();
    while (digitalRead(echo) == HIGH)
        ;
    unsigned long endTime = micros();

    // Berechnung der Entfernung anhand der gemessenen Zeit
    double duration = endTime - startTime;
    double distance =
        duration * 0.0343 / 2; // 0.0343 cm/us als Umrechnungsfaktor

    std::cout << "Entfernung: " << distance << " cm" << std::endl;

    return distance;
}

// Mit dem HC-SR04 Sensor wird geprüft, ob sich vor dem Buggy ein Hindernis
// befindet
bool checkForObstacle(int distance, int trigger, int echo, int led) {
    distance = measureDistance(trigger, echo);
    // Bei einer Distanz von kleiner 6cm aktiviert die rote LED und der
    // Ausweichvorgang wird gestartet
    if (distance < 6.0) {
        turnLEDON(led);
        stopMotors();
        // Kurzer Stop, damit das Leuchten der LED besser zur Geltung kommt
        delay(200);
        return true;
    } else {
        return false;
    }
}

// Der Buggy fährt so lange zurück bis vor dem Sensor wieder Platz ist, dann
// wird mit einer rechts Kurve ausgewichen
void avoidObstacle(double distance, int trigger, int echo, int led) {
    driveBackward(100);
    while (1) {
        distance = measureDistance(trigger, echo);
        // Wenn die Distanz größer als 6cm ist, wird eine rechts Kurve
        // ausgeführt und die LED ausgeschaltet
        if (distance > 6.0) {
            turnRight(100);
            turnLEDOFF(led);
            delay(650);
            return;
        }
        delay(20);
    }
}