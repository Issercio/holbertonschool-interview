#!/usr/bin/python3
"""
Log parsing script that reads stdin and computes metrics
"""
import sys


def print_stats(total_size, status_codes):
    """Print statistics"""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


if __name__ == "__main__":
    total_size = 0
    status_codes = {200: 0, 301: 0, 400: 0, 401: 0,
                    403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        for line in sys.stdin:
            try:
                parts = line.split()
                if len(parts) < 2:
                    continue

                file_size = int(parts[-1])
                status_code = int(parts[-2])

                total_size += file_size

                if status_code in status_codes:
                    status_codes[status_code] += 1
                    line_count += 1

                    if line_count % 10 == 0:
                        print_stats(total_size, status_codes)
            except (ValueError, IndexError):
                continue
    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        raise

    print_stats(total_size, status_codes)
