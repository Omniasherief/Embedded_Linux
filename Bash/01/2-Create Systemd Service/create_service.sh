#!/bin/bash

# Prompt for service name
echo "Enter service name: "
read service_name

# Create the Systemd service file with root permissions
sudo bash -c "cat <<EOF > /etc/systemd/system/${service_name}.service
[Unit]
Description=Simple Systemd Service Example

[Service]
ExecStart=/usr/bin/bash /home/$USER/${service_name}.sh
Restart=always

[Install]
WantedBy=multi-user.target
EOF"

# Create the service script in the user's home directory
echo "#!/bin/bash" > "/home/$USER/${service_name}.sh"
echo "echo 'Service Running!'" >> "/home/$USER/${service_name}.sh"

# Make the script executable
chmod +x "/home/$USER/${service_name}.sh"

echo "Systemd service ${service_name}.service created."
echo "Enable with: sudo systemctl enable ${service_name}"
echo "Start with: sudo systemctl start ${service_name}"
