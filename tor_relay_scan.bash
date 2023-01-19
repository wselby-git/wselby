#!/bin/bash
# This is a script to scan the Tor network for relays

# Get a list of all relays
curl -s -o- https://check.torproject.org/exit-addresses | grep -E -o 'ExitAddress [0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}' | awk '{print $2}' > relay_list

# Create a variable to store the number of relays
num_relays=`wc -l < relay_list`

# Print out the number of relays
echo "$num_relays relays found"

# Loop through each relay
for ip_address in $(cat relay_list); do
  # Perform a port scan on the relay
  nmap -Pn -p 22,80,443 $ip_address

  # Print out the results of the scan
  echo -e "\nScan results for $ip_address:"
  grep -E -o 'open.*[0-9]{2,5}/tcp'
done

# Delete the relay list file
rm relay_list
