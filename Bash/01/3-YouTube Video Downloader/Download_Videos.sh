#!/bin/bash
if ! command -v yt-dlp &> /dev/null; then  #&> /dev/null: Redirects both stdout and stderr to /dev/null to suppress output.
    echo "yt-dlp not found Installing ..."
    sudo apt update && sudo apt install -y yt-dlp
fi
echo "Enter YouTube video URL: "
read url
echo "Downloading..."
yt-dlp "$url" --output "%(title)s.%(ext)s"

