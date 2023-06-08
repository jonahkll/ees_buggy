#!/bin/bash

# Set the project directory
project_dir="/home/pi/buggy"

# Set the file extensions to be formatted
file_extensions=("cpp" "hpp" "c" "h")

# Find all files with the specified extensions in the project directory
files=$(find "$project_dir" -type f -name "*.${file_extensions[0]}")
for extension in "${file_extensions[@]:1}"; do
    files+=" "$(find "$project_dir" -type f -name "*.${extension}")
done

# Format each file using clang-format
for file in $files; do
    clang-format -i "$file"
    echo "Formatted: $file"
done

echo "Formatting complete!"
