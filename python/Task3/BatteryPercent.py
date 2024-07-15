#notify2 
from plyer import notification

import psutil

# Get battery percentage
battery = psutil.sensors_battery()
percent = battery.percent

# Create and display notification (adjust app_name as needed)
notification.notify(
    title="Battery Percentage",
    message=str(percent) + "% Remaining",
    app_name="Battery Percent",  # Replace with your desired app name
    timeout=10  # Optional: Notification duration in seconds (default is 4)
)

print(percent)