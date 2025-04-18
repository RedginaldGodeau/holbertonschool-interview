# Log Parsing

This script reads stdin line by line and computes metrics.

Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

After every 10 lines and/or a keyboard interruption (CTRL + C), it prints the following statistics:

- Total file size: File size: <total size>
- Number of lines by status code:
  - <status code>: <number>
