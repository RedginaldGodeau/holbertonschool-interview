#!/usr/bin/python3
"""
This script reads stdin line by line and computes metrics.

Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

After every 10 lines and/or a keyboard interruption (CTRL + C), it prints the following statistics:

*   Total file size: File size: <total size>
*   Number of lines by status code:
    *   <status code>: <number>
"""
import sys
import re

# Initialize total file size
total_size = 0

# Initialize status code counts
status_codes = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}

# Initialize line count
line_count = 0

try:
    # Read input line by line from stdin
    for line in sys.stdin:
        # Remove leading/trailing whitespace
        line = line.strip()
        # Use regex to match the input format
        match = re.match(r'(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}) - \[.+\] "GET \/projects\/260 HTTP\/1\.1" (\d+) (\d+)', line)
        # If the line matches the expected format
        if match:
            # Extract status code and file size from the matched groups
            status_code = match.group(2)
            file_size = int(match.group(3))

            # Update total file size
            total_size += file_size
            # Update status code count if it's a valid status code
            if status_code in status_codes:
                status_codes[status_code] += 1

            # Increment line count
            line_count += 1

            # Print statistics every 10 lines
            if line_count % 10 == 0:
                print("File size: {}".format(total_size))
                for code in sorted(status_codes.keys()):
                    if status_codes[code] > 0:
                        print("{}: {}".format(code, status_codes[code]))

# Handle keyboard interruption (CTRL + C)
except KeyboardInterrupt:
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))
