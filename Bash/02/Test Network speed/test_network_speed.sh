#!/bin/bash#!/bin/bash
#&>/dev/null: Redirects both stdout and stderr to /dev/null, which discards the output

if ! command -v speedtest-cli &>/dev/null; then
 echo "speedtest-cli is not installed. Please install it using your package manager."
  exit 1
  fi
  # Run the speed test and capture the results
  speedtest_result=$(speedtest-cli)
  echo "Speed Test Results: $speedtest_result"