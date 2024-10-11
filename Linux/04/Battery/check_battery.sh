#!/bin/bash
battery_status=$(upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep state | awk '{print $2}')
battery_capacity=$(upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep percentage | awk '{print $2}')

echo "Battery Status: $battery_status" >> battery_log.txt
echo "Battery Capacity: $battery_capacity" >> battery_log.txt
