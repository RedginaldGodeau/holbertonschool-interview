#!/usr/bin/python3
"""
make a resume of request
"""
import sys
import signal
import re


def print_result(dictstatus: dict[str, int], filesize: int):
    print(f"File size: {filesize}")
    array_keys: [str] = []
    for k in dictstatus.keys():
        array_keys.append(k)
    array_keys.sort()
    for keys in array_keys:
        print(f"{keys}: {dictstatus[keys]}")


def denied(_signalno, _stack):
    print_result(d, fileSize)
    sys.exit(0)

if __name__ == '__main__':
    fileSize: int = 0
    status: str = ""
    d: dict[str, int] = {}
    nbLine: int = 0

    signal.signal(signal.SIGTERM, denied)
    signal.signal(signal.SIGINT, denied)

    for line in sys.stdin:
        if re.search("^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3} - \[\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}.\d+\] \"GET \/projects\/260 HTTP\/1\.1\" \d{3} \d{1,4}$", line) is None:
            print(f"skipped: {line}")
            continue
        if line == "":
            continue
        inputSplit = line.split(" ")
        n: str = inputSplit.pop()
        if '\n' not in n:
            continue
        fileSize += int(n.replace('\n', ""))
        status = inputSplit.pop()
        value = d.get(status)
        if value:
            d[status] = value + 1
        else:
            d[status] = 1

        nbLine += 1
        if nbLine % 10 == 0:
            print_result(d, fileSize)
    print_result(d, fileSize)