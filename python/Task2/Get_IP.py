import requests
import pprint
#GET IP
response=requests.get("https://api.ipify.org/?format=json")
IP=response.json().get("ip")
# Get location
url = f"https://ipinfo.io/{IP}/geo"
location_data = requests.get(url).json()

# Print formatted location data
pprint.pprint(location_data)

