# Log Parsing

This project implements a script that reads log entries from stdin and computes metrics.

## Problem Description

The script reads stdin line by line and computes metrics from log entries.

### Input Format
```
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
```

Lines that don't match this format are skipped.

### Output

After every 10 lines and/or a keyboard interruption (CTRL + C), the script prints:

1. **Total file size**: Sum of all file sizes from processed lines
   ```
   File size: <total size>
   ```

2. **Number of lines by status code**:
   - Only tracks these status codes: 200, 301, 400, 401, 403, 404, 405, 500
   - Status codes are printed in ascending order
   - Only prints status codes that have appeared
   - Format: `<status code>: <number>`

## Algorithm

1. Read stdin line by line
2. Parse each line to extract status code and file size
3. Skip lines that don't match the expected format
4. Update metrics (total file size and status code counts)
5. Print statistics every 10 lines
6. Handle keyboard interruption (CTRL+C) gracefully by printing current stats

## Files

- `0-stats.py` - Main log parsing script

## Usage

```bash
./0-generator.py | ./0-stats.py
```

### Example Output

```
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
File size: 11320
200: 3
301: 2
400: 1
401: 2
403: 3
404: 4
405: 2
500: 3
^CFile size: 17146
200: 4
301: 3
400: 4
401: 2
403: 6
404: 6
405: 4
500: 4
```

## Requirements

- Python 3.4.3
- Ubuntu 14.04 LTS
- PEP 8 style (version 1.7.x)
- Script must be executable
- Code should not execute when imported

## Features

- Handles malformed log lines gracefully
- Responds to keyboard interrupts (CTRL+C)
- Efficient line-by-line processing
- No imports required except sys
