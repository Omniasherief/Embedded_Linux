#!/bin/bash

# Define the output file for the report
output_file="system_report.txt"

# Create or overwrite the output file
# shellcheck disable=SC2188
> "$output_file"

# Helper function to add section headers to the report
add_section() {
    echo "$1" >> "$output_file"
    echo "------------------------------" >> "$output_file"
}

# Add report header with the current date and time
add_section "System Report - $(date)"

# Hostname and User Information
add_section "Hostname and User Information"
{
   # echo "Hostname and User Information"
    hostname
    whoami
    echo -e "\n"
} >> "$output_file"

# System Information
add_section "System Information"
{
    uname -a
    echo -e "\n"
} >> "$output_file"

# CPU Information
add_section "CPU Information"
{
    lscpu
    echo -e "\n"
} >> "$output_file"

# Memory Information
add_section "Memory Information"
{
    free -h
    echo -e "\n"
} >> "$output_file"

# Disk Usage
add_section "Disk Usage"
{
    df -h
    echo -e "\n"
} >> "$output_file"

# Network Information
add_section "Network Information"
{
    ip a  # Use 'ip a' instead of deprecated 'ifconfig'
    echo -e "\n"
} >> "$output_file"

# Print a message indicating where the report is saved
echo "System report generated: $output_file"
