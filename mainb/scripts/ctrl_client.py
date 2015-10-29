#!/usr/bin/env python2
import socket
import sys
import pygame

#TODO:
#pygame.init()
#j = pygame.joystick.Joystick(0)
#j.init()

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = ('150.254.47.163', 5000)
message = '0 0 0 0 0'

try:
    print '-> "%s"' % message
    sent = sock.sendto(message, server_address)

finally:
    print 'closing socket'
    sock.close()
