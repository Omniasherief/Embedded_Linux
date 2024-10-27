#!/usr/bin/bash
declare -A colors=(
  [Red]="\e[31m"
  [Green]="\e[32m"
  [Yellow]="\e[33m"
  [Blue]="\e[34m"
  [Magenta]="\e[35m"
  [Cyan]="\e[36m"
  [White]="\e[37m"
  [BOLD]="\e[1m"
  [ITALIC]="\e[3m"
  [UNDERLINE]="\e[4m"
  [RESET]="\e[0m"
)
color_names=("Red" "Green" "Yellow" "Blue" "Magenta" "Cyan" "White" "BOLD" "ITALIC" "UNDERLINE" "RESET")
selected_color=$(printf "%s\n" "${color_names[@]}" | rofi -dmenu -p "Select a color:")
xdotool type --delay 10 "${colors[$selected_color]}"
xdotool type --delay 10 "Hello, World!"
