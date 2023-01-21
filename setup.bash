// Author: William Selby
// Linux initial setup script


#!/bin/bash

# Update and upgrade the system
sudo apt-get update && sudo apt-get upgrade

# Install software
sudo apt-get install gcc python python-pip nmap netcat wireshark memtool tor lynx firefox build-essential cmake libboost-all-dev git

# Enable SELinux
sudo setenforce 1

# Enable the firewall
sudo ufw enable

# Encrypt the hard drive
sudo cryptsetup luksFormat /dev/sda1

# Create a backup of the hard drive and encrypt it
sudo dd if=/dev/sda1 of=/backup/sda1.img
sudo cryptsetup luksFormat /backup/sda1.img

# Set up the crontab to monitor uptime, disk space and users one a day at 4 am
echo "0 4 * * * /usr/bin/uptime; /bin/df -h; /usr/bin/who" | sudo crontab -
