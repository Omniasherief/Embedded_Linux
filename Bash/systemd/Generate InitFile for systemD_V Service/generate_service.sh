#!/bin/bash

: << generate_systemd_service
--Function to generate systemd service file

--tee takes the input (from your script or the terminal) and writes it into /etc/systemd/system/$service_name.service.
Any output that would appear on the screen is discarded with > /dev/null 
--StandardOutput=journal , StandardError=journal
 allows the service to log its standard output and errors to the systemd journal
-- to test it after generation ->   journalctl -u $service_name.service -xe
--StartLimitInterval=10s    # Time window for counting failures
StartLimitBurst=5          # Maximum failures allowed within the time window
generate_systemd_service

generate_systemd_service() {
  cat <<EOF | sudo tee /etc/systemd/system/$service_name.service > /dev/null
[Unit]
Description=$description

[Service]
Type=simple
ExecStart="$exec_path" $start_option
#User="$user"
#Group="$group"
Restart=on-failure
StartLimitInterval=10s
StartLimitBurst=5

[Install]
WantedBy=multi-user.target
EOF
  echo "SystemD service file created at /etc/systemd/system/$service_name.service"
}


# Function to generate SystemV init script
generate_systemv_script() {
  cat <<EOF | sudo tee /etc/init.d/$service_name > /dev/null
#!/bin/bash
### BEGIN INIT INFO
# Provides:          $service_name
# Required-Start:    \$remote_fs \$syslog
# Required-Stop:     \$remote_fs \$syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: $description
### END INIT INFO

start() {
    echo "Starting $service_name..."
    su -c "$exec_path $start_option &" -s /bin/bash $user
}

stop() {
    echo "Stopping $service_name..."
    pkill -f "$exec_path"
}

restart() {
    stop
    sleep 1
    start
}

case "\$1" in
  start) start ;;
  stop) stop ;;
  restart) restart ;;
  *) echo "Usage: \$0 {start|stop|restart}" ;;
esac

exit 0
EOF

  sudo chmod +x /etc/init.d/$service_name
  echo "SystemV init script created at /etc/init.d/$service_name"
}

# Function to prompt for service type
get_service_type() {
  while true; do
    read -p "Choose service type (systemD/systemV): " service_type
    if [[ "$service_type" == "systemD" || "$service_type" == "systemV" ]]; then
      break
    else
      echo "Invalid input. Please enter 'systemD' or 'systemV'."
    fi
  done
}


find_executable() {
  if [[ -d "$exec_path" ]]; then
    echo "Checking directory: $exec_path"
    # Look for the first executable file in the directory
    exec_file=$(find "$exec_path" -maxdepth 1 -type f -executable | head -n 1)
    if [[ -n "$exec_file" ]]; then
      echo "Executable found: $exec_file"
      exec_path="$exec_file"
    else
      echo "Error: No executable found in the directory '$exec_path'." >&2
      exit 1
    fi
  elif [[ -x "$exec_path" ]]; then
    echo "Executable found: $exec_path"
  else
    echo "Error: '$exec_path' is not a valid executable or directory." >&2
    exit 1
  fi
}
#main






# Get service type
get_service_type

# Get the actual system type
actual_system_type=$(ps --no-headers -o comm 1 | xargs)

# Debug output to check actual system type
echo "Actual system type: $actual_system_type"

# Check for SystemD
if [[ "$actual_system_type" == "systemd" ]]; then
  if [[ "$service_type" == "systemV" ]]; then
    echo "You are running on a system that uses SystemD. Please choose 'systemD'."
    exit 1
  fi
# Check for SystemV
elif [[ "$actual_system_type" == "init" ]]; then
  if [[ "$service_type" == "systemD" ]]; then
    echo "You are running on a system that uses SystemV. Please choose 'SystemV'."
    exit 1
  fi
else
  echo "Unknown system type. Please check your system configuration."
  exit 1
fi



read -p "Enter service name: " service_name
# Validate service name
if [[ -z "$service_name" ]]; then
  echo "Error: Service name cannot be empty." >&2
  exit 1
fi

read -p "Enter description: " description

read -p "Enter executable path: " exec_path


find_executable
####comment
if false;then
echo "Checking path: $exec_path"
if [[ ! -e "$exec_path" ]]; then
  echo "Error: Executable '$exec_path' does not exist." >&2
  exit 1
else
  echo "Executable found."
fi
fi

read -p "Enter start option (optional): " start_option
read -p "Enter user to run the service (optional, default: root):  " user
user=${user:-root}  #Parameter expansion. If the user leaves the input blank, it defaults to root.

read -p "Enter group to run the service (optional, default: root):  " group
group=${group:-root}

if [ "$service_type" == "systemD" ]; then
  generate_systemd_service
  sudo systemctl daemon-reload
  sudo systemctl enable $service_name
elif [ "$service_type" == "systemV" ]; then
  generate_systemv_script
  sudo update-rc.d $service_name defaults
else
  echo "Invalid service type. Please choose either systemD or systemV."
  exit 1
fi

echo "Service configuration completed."