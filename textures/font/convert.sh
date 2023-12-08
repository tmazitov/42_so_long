#!/bin/bash

# Input file
input_file="font.xpm"

# Output directory
output_dir="output/"

# Create output directory if it doesn't exist
mkdir -p "$output_dir"

# Read each line from the input file
while IFS= read -r line; do
    # Check if the line starts with "static char * letter_" (indicating the start of a new symbol)
    if [[ "$line" =~ ^static\ char\ \*\ letter_([a-zA-Z0-9])\[\]\ \=\ \{$ ]]; then
        # Extract the symbol name (captured by the regular expression)
        symbol_name="${BASH_REMATCH[1]}"
        # Output file name
        output_file="${output_dir}${symbol_name}.xpm"
        # Write the current line to the output file
        echo "$line" > "$output_file"
    else
        # Continue writing to the current output file
        echo "$line" >> "$output_file"
    fi
done < "$input_file"

echo "Files successfully split into individual symbols in the '$output_dir' directory."

