EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:wb
LIBS:isfar2-cache
EELAYER 24 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 6
Title ""
Date "21 may 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 5250 3250 1150 1800
U 537C6A5D
F0 "mainboard" 50
F1 "mainb.sch" 50
F2 "+12V" O R 6400 3700 60 
F3 "+5V" O R 6400 4150 60 
F4 "GND" U R 6400 3850 60 
F5 "SDA" B R 6400 4600 60 
F6 "SCL" B R 6400 4800 60 
$EndSheet
$Sheet
S 8000 4650 900  600 
U 537C6C8E
F0 "sidedriver#2" 50
F1 "sidedriver.sch" 50
F2 "+12V" I R 8900 4800 60 
F3 "+5V" I R 8900 5100 60 
F4 "SDA" B L 8000 4900 60 
F5 "SCL" B L 8000 5050 60 
F6 "GND" U R 8900 4950 60 
$EndSheet
$Sheet
S 8000 5500 900  600 
U 537C6C9B
F0 "sidedriver#3" 50
F1 "sidedriver.sch" 50
F2 "+12V" I L 8000 5600 60 
F3 "+5V" I L 8000 5700 60 
F4 "SDA" B L 8000 5800 60 
F5 "SCL" B L 8000 5950 60 
F6 "GND" U L 8000 6050 60 
$EndSheet
$Sheet
S 2700 3550 1200 1150
U 537C6C9F
F0 "rpicam" 50
F1 "rpicam.sch" 50
$EndSheet
$Sheet
S 8000 3800 900  600 
U 537C6C8A
F0 "sidedriver#1" 50
F1 "sidedriver.sch" 50
F2 "+12V" I R 8900 3950 60 
F3 "+5V" I R 8900 4250 60 
F4 "SDA" B L 8000 4050 60 
F5 "SCL" B L 8000 4200 60 
F6 "GND" U R 8900 4100 60 
$EndSheet
Wire Bus Line
	7700 4050 7700 6000
Entry Wire Line
	7700 4150 7800 4050
Entry Wire Line
	7700 4300 7800 4200
Entry Wire Line
	7700 5000 7800 4900
Entry Wire Line
	7700 5150 7800 5050
Entry Wire Line
	7700 5800 7800 5700
Entry Wire Line
	7700 5900 7800 5800
Wire Wire Line
	7800 4900 8000 4900
Wire Wire Line
	8000 5050 7800 5050
$EndSCHEMATC
