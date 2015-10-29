#!/usr/bin/env python
import socket
import sys
import smbus

#udp
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = ('150.254.47.163', 5000)
sock.bind(server_address)

#i2c
bus = smbus.SMBus(1)

def mctrl(v):
    print "mctrl: ", v
    for i in range(len(v)):
        if v[i] < 0:
            v[i] = 0xFFFF + v[i] + 1
    bus.write_word_data(0x09, 0x02, v[0])
    bus.write_word_data(0x0a, 0x02, v[1])
    #bus.write_word_data(0x0b, 0x02, v[2])

def tctrl(v):
    print "tctrl: ", v
    for i in range(len(v)):
        if v[i] < 0:
            v[i] = 0xFFFF + v[i] + 1
    bus.write_word_data(0x09, 0x06, v[0])
    bus.write_word_data(0x0a, 0x06, v[1])


while True:
    data, address = sock.recvfrom(4096)
    args = data.split()

    if len(args) < 5:
        print "Too few arguments..."
        sys.exit(0)

    mctrl(map(int ,[args[0], args[1], args[2]]))
    tctrl(map(int ,[args[3], args[4]]))
