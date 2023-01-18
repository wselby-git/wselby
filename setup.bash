// Author: William Selby
// Linux initial setup script

#!/bin/bash

#update and upgrade packages
sudo apt-get update
sudo apt-get upgrade

#install packages
sudo apt-get install memtool mesa-utils nmap tor lynx wireshark

#enable SELinux
sudo setenforce 1

#encrypt hard drive
sudo cryptsetup luksFormat /dev/sda1
sudo cryptsetup luksOpen /dev/sda1 my_luks

#enable firewall
sudo ufw enable

echo "Packages updated, installed, and configured successfully!"
