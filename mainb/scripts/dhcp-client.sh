systemctl stop dhcpcd.service
ip route del default
dhcpcd -f /etc/dhcpcd-client.conf eth0
