#!/usr/bin/python3
import sys
import re

total_size = 0
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
line_count = 0

try:
    for line in sys.stdin:
        line = line.strip()
        match = re.match(r'(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}) - \[.+\] "GET \/projects\/260 HTTP\/1\.1" (\d+) (\d+)', line)
        if match:
            status_code = match.group(2)
            file_size = int(match.group(3))

            total_size += file_size
            if status_code in status_codes:
                status_codes[status_code] += 1

            line_count += 1

            if line_count % 10 == 0:
                print("File size: {}".format(total_size))
                for code in sorted(status_codes.keys()):
                    if status_codes[code] > 0:
                        print("{}: {}".format(code, status_codes[code]))

except KeyboardInterrupt:
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))
