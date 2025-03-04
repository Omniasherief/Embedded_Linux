#!/bin/bash


PC_USER="omnia"
PC_IP="192.168.1.21"
DEST_PATH="/home/omnia/EL/Rasp/03/project_read(temp,Humidity)"

# Send the CSV file every 60 minutes
while true; do
    scp sensor_data.csv $PC_USER@$PC_IP:$DEST_PATH
    echo "CSV file transferred at $(date)"
    #sleep 3600  # Wait for 60 minutes
    sleep 10
done
