#!/usr/bin/env python2
import socket
import sys
import pygame

class Robot:
    m1 = 0
    m2 = 0
    m3 = 0
    k1 = 0
    k2 = 0
    ipaddr = ('150.254.47.163', 5000)

    def __init__(self):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    def prn(self):
        print "[", self.m1, self.m2, self.m3, "] [", self.k1, self.k2, "]"

    def sync(self):
        #receive
        if self.k1 < 0:
            self.k1 = 0
        if self.k2 < 0:
            self.k2 = 0
        msg = str(self.m1) + " " + str(self.m2) + " " + str(self.m3) + " "\
            + str(self.k1) + " " + str(self.k2)
        self.prn()
        self.sock.sendto(msg, self.ipaddr)

    def stop(self):
        self.m1 = 0
        self.m2 = 0
        self.m3 = 0
        self.k1 = 0
        self.k2 = 0
        self.sync()

    def bye(self):
        print "bye bye"
        self.stop()
        self.sock.close()


pygame.init()
j = pygame.joystick.Joystick(0)
j.init()
axes = [ 0.0 ] * j.get_numaxes()

r = Robot()

try:
    while True:
        event = pygame.event.wait()
        if event.type == pygame.JOYAXISMOTION:
            e = event.dict
            axes[e['axis']] = e['value']
        elif event.type == pygame.JOYBUTTONDOWN:
            e = event.dict
            if e['button'] == 5:
                r.k1 = r.k1 + 10
            if e['button'] == 7:
                r.k1 = r.k1 - 10
            if e['button'] == 4:
                r.k2 = r.k2 + 10
            if e['button'] == 6:
                r.k2 = r.k2 - 10
            if e['button'] == 9:
                r.stop()
        r.sync()


except KeyboardInterrupt:
    r.bye()
    sys.exit(0)
