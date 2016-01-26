#!/usr/bin/env python2
import socket
import sys
import pygame

# M1 -> 0x0A
# M2 -> 0x09
# M3 -> 0x0B

# view from behind
#    M1      M2
#        M3


class Robot:
    m1 = 0
    m2 = 0
    m3 = 0
    k1 = 0
    k2 = 0
    ipaddr = ('150.254.47.149', 5000)

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


def simple_mix(a1, a2, a3):
    m1 = int(-2500*a1) + int(2500 * a2)
    m3 = int(-2500*a1)
    m2 = int(-2500*a1) + int(-2500 * a2)
    return m1, m2, m3

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
            (r.m1, r.m2, r.m3) = simple_mix(axes[1], axes[2], axes[3]);
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
