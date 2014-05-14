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
LIBS:Conn-raspberry
LIBS:con-amp-micromatch
LIBS:wb
LIBS:con-molex
LIBS:mainb_v2-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "14 may 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L PBD-26 J1
U 1 1 537217B1
P 8600 5500
F 0 "J1" H 8600 6200 60  0000 C CNN
F 1 "RPI_GPIO" V 8600 5500 50  0000 C CNN
F 2 "" H 8600 5500 60  0000 C CNN
F 3 "" H 8600 5500 60  0000 C CNN
	1    8600 5500
	1    0    0    -1  
$EndComp
$Comp
L RJ45 J2
U 1 1 537218EC
P 1500 1500
F 0 "J2" H 1700 2000 60  0000 C CNN
F 1 "ETH" H 1350 2000 60  0000 C CNN
F 2 "~" H 1500 1500 60  0000 C CNN
F 3 "~" H 1500 1500 60  0000 C CNN
	1    1500 1500
	0    -1   1    0   
$EndComp
$Comp
L 7805 U1
U 1 1 53721A1B
P 3000 3250
F 0 "U1" H 3150 3054 60  0000 C CNN
F 1 "POLOLU-2111" H 3000 3450 60  0000 C CNN
F 2 "~" H 3000 3250 60  0000 C CNN
F 3 "~" H 3000 3250 60  0000 C CNN
	1    3000 3250
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 53721BC1
P 10350 5400
F 0 "D3" H 10350 5500 50  0000 C CNN
F 1 "LED" H 9950 5650 50  0001 C CNN
F 2 "~" H 10350 5400 60  0000 C CNN
F 3 "~" H 10350 5400 60  0000 C CNN
	1    10350 5400
	0    1    1    0   
$EndComp
$Comp
L LED D2
U 1 1 53721BCE
P 10600 5400
F 0 "D2" H 10600 5500 50  0000 C CNN
F 1 "LED" H 10200 5300 50  0001 C CNN
F 2 "~" H 10600 5400 60  0000 C CNN
F 3 "~" H 10600 5400 60  0000 C CNN
	1    10600 5400
	0    1    1    0   
$EndComp
$Comp
L LED D1
U 1 1 53721BD4
P 10850 5400
F 0 "D1" H 10850 5500 50  0000 C CNN
F 1 "LED" H 10450 4950 50  0001 C CNN
F 2 "~" H 10850 5400 60  0000 C CNN
F 3 "~" H 10850 5400 60  0000 C CNN
	1    10850 5400
	0    1    1    0   
$EndComp
$Comp
L CONN_3 J11
U 1 1 53721CC4
P 9850 4850
F 0 "J11" V 9800 4850 50  0000 C CNN
F 1 "UART" V 9900 4850 40  0000 C CNN
F 2 "~" H 9850 4850 60  0000 C CNN
F 3 "~" H 9850 4850 60  0000 C CNN
	1    9850 4850
	0    1    -1   0   
$EndComp
$Comp
L R R9
U 1 1 53721EA6
P 10850 4850
F 0 "R9" V 10930 4850 40  0000 C CNN
F 1 "500" V 10857 4851 40  0000 C CNN
F 2 "~" V 10780 4850 30  0000 C CNN
F 3 "~" H 10850 4850 30  0000 C CNN
	1    10850 4850
	-1   0    0    1   
$EndComp
$Comp
L R R8
U 1 1 53721EAC
P 10600 4850
F 0 "R8" V 10680 4850 40  0000 C CNN
F 1 "500" V 10607 4851 40  0000 C CNN
F 2 "~" V 10530 4850 30  0000 C CNN
F 3 "~" H 10600 4850 30  0000 C CNN
	1    10600 4850
	-1   0    0    1   
$EndComp
$Comp
L R R7
U 1 1 53721EB2
P 10350 4850
F 0 "R7" V 10430 4850 40  0000 C CNN
F 1 "500" V 10357 4851 40  0000 C CNN
F 2 "~" V 10280 4850 30  0000 C CNN
F 3 "~" H 10350 4850 30  0000 C CNN
	1    10350 4850
	-1   0    0    1   
$EndComp
$Comp
L CONN_8 ETH->RPI1
U 1 1 537225D4
P 3100 1500
F 0 "ETH->RPI1" V 3050 1500 60  0000 C CNN
F 1 "CONN_8" V 3150 1500 60  0000 C CNN
F 2 "~" H 3100 1500 60  0000 C CNN
F 3 "~" H 3100 1500 60  0000 C CNN
	1    3100 1500
	1    0    0    -1  
$EndComp
Text Label 2300 1150 0    60   ~ 0
TX+
Text Label 2300 1250 0    60   ~ 0
TX-
Text Label 2300 1350 0    60   ~ 0
RX+
Text Label 2300 1650 0    60   ~ 0
RX-
Text GLabel 2100 950  1    60   Input ~ 0
PoE+
Text GLabel 2100 2100 3    60   Output ~ 0
PoE-
$Comp
L GND #PWR01
U 1 1 53722805
P 3000 3550
F 0 "#PWR01" H 3000 3550 30  0001 C CNN
F 1 "GND" H 3000 3480 30  0001 C CNN
F 2 "" H 3000 3550 60  0000 C CNN
F 3 "" H 3000 3550 60  0000 C CNN
	1    3000 3550
	1    0    0    -1  
$EndComp
Text GLabel 1000 3900 0    60   Input ~ 0
AKU+
$Comp
L FBR51 REL3
U 1 1 53722EB5
P 1750 4000
F 0 "REL3" H 1400 4250 60  0000 C CNN
F 1 "FBR51" H 1850 3750 60  0000 C CNN
F 2 "~" H 1750 4000 60  0000 C CNN
F 3 "~" H 1750 4000 60  0000 C CNN
	1    1750 4000
	1    0    0    -1  
$EndComp
$Comp
L FBR51 REL2
U 1 1 53722EC2
P 4250 4750
F 0 "REL2" H 3900 5000 60  0000 C CNN
F 1 "FBR51" H 4350 4500 60  0000 C CNN
F 2 "~" H 4250 4750 60  0000 C CNN
F 3 "~" H 4250 4750 60  0000 C CNN
	1    4250 4750
	1    0    0    -1  
$EndComp
$Comp
L FBR51 REL1
U 1 1 53722EC8
P 4250 3300
F 0 "REL1" H 3900 3550 60  0000 C CNN
F 1 "FBR51" H 4350 3050 60  0000 C CNN
F 2 "~" H 4250 3300 60  0000 C CNN
F 3 "~" H 4250 3300 60  0000 C CNN
	1    4250 3300
	1    0    0    -1  
$EndComp
$Comp
L BC546 Q1
U 1 1 53723242
P 4800 4050
F 0 "Q1" H 4800 3901 40  0000 R CNN
F 1 "BC337" H 4800 4200 40  0000 R CNN
F 2 "TO92" H 4700 4152 29  0000 C CNN
F 3 "~" H 4800 4050 60  0000 C CNN
	1    4800 4050
	-1   0    0    -1  
$EndComp
$Comp
L BC546 Q2
U 1 1 5372325B
P 4800 5550
F 0 "Q2" H 4800 5401 40  0000 R CNN
F 1 "BC337" H 4800 5700 40  0000 R CNN
F 2 "TO92" H 4700 5652 29  0000 C CNN
F 3 "~" H 4800 5550 60  0000 C CNN
	1    4800 5550
	-1   0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 53723298
P 5300 5550
F 0 "R5" V 5380 5550 40  0000 C CNN
F 1 "R" V 5307 5551 40  0000 C CNN
F 2 "~" V 5230 5550 30  0000 C CNN
F 3 "~" H 5300 5550 30  0000 C CNN
	1    5300 5550
	0    1    -1   0   
$EndComp
$Comp
L R R4
U 1 1 5372329E
P 5300 4050
F 0 "R4" V 5380 4050 40  0000 C CNN
F 1 "R" V 5307 4051 40  0000 C CNN
F 2 "~" V 5230 4050 30  0000 C CNN
F 3 "~" H 5300 4050 30  0000 C CNN
	1    5300 4050
	0    1    -1   0   
$EndComp
$Comp
L DIODE D4
U 1 1 53723323
P 4150 3750
F 0 "D4" H 4150 3850 40  0000 C CNN
F 1 "1N4148" H 4150 3650 40  0000 C CNN
F 2 "~" H 4150 3750 60  0000 C CNN
F 3 "~" H 4150 3750 60  0000 C CNN
	1    4150 3750
	-1   0    0    1   
$EndComp
$Comp
L DIODE D5
U 1 1 537237E6
P 4150 5200
F 0 "D5" H 4150 5300 40  0000 C CNN
F 1 "1N4148" H 4150 5100 40  0000 C CNN
F 2 "~" H 4150 5200 60  0000 C CNN
F 3 "~" H 4150 5200 60  0000 C CNN
	1    4150 5200
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR02
U 1 1 5372399B
P 3600 3100
F 0 "#PWR02" H 3600 3190 20  0001 C CNN
F 1 "+5V" H 3600 3190 30  0000 C CNN
F 2 "" H 3600 3100 60  0000 C CNN
F 3 "" H 3600 3100 60  0000 C CNN
	1    3600 3100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR03
U 1 1 537239AA
P 9400 4700
F 0 "#PWR03" H 9400 4790 20  0001 C CNN
F 1 "+5V" H 9400 4790 30  0000 C CNN
F 2 "" H 9400 4700 60  0000 C CNN
F 3 "" H 9400 4700 60  0000 C CNN
	1    9400 4700
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR04
U 1 1 537239E6
P 5450 4600
F 0 "#PWR04" H 5450 4550 20  0001 C CNN
F 1 "+12V" H 5450 4700 30  0000 C CNN
F 2 "" H 5450 4600 60  0000 C CNN
F 3 "" H 5450 4600 60  0000 C CNN
	1    5450 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 53723C0B
P 4700 4400
F 0 "#PWR05" H 4700 4400 30  0001 C CNN
F 1 "GND" H 4700 4330 30  0001 C CNN
F 2 "" H 4700 4400 60  0000 C CNN
F 3 "" H 4700 4400 60  0000 C CNN
	1    4700 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 53723C11
P 9950 5300
F 0 "#PWR06" H 9950 5300 30  0001 C CNN
F 1 "GND" H 9950 5230 30  0001 C CNN
F 2 "" H 9950 5300 60  0000 C CNN
F 3 "" H 9950 5300 60  0000 C CNN
	1    9950 5300
	1    0    0    -1  
$EndComp
$Comp
L +5C #PWR07
U 1 1 53723E85
P 5450 3150
F 0 "#PWR07" H 5450 3100 20  0001 C CNN
F 1 "+5C" H 5450 3250 30  0000 C CNN
F 2 "" H 5450 3150 60  0000 C CNN
F 3 "" H 5450 3150 60  0000 C CNN
	1    5450 3150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 53723EFC
P 9400 6200
F 0 "#PWR08" H 9400 6200 30  0001 C CNN
F 1 "GND" H 9400 6130 30  0001 C CNN
F 2 "" H 9400 6200 60  0000 C CNN
F 3 "" H 9400 6200 60  0000 C CNN
	1    9400 6200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 53723F5B
P 2350 4700
F 0 "#PWR09" H 2350 4700 30  0001 C CNN
F 1 "GND" H 2350 4630 30  0001 C CNN
F 2 "" H 2350 4700 60  0000 C CNN
F 3 "" H 2350 4700 60  0000 C CNN
	1    2350 4700
	1    0    0    -1  
$EndComp
Text GLabel 2350 4600 1    60   Input ~ 0
PoE-
Text GLabel 2200 4300 3    60   Output ~ 0
PoE+
$Comp
L DS1307Z U3
U 1 1 53731133
P 8750 1600
F 0 "U3" H 8400 1900 70  0000 C CNN
F 1 "DS1307Z" H 8950 1300 70  0000 C CNN
F 2 "~" H 8750 950 60  0000 C CNN
F 3 "~" H 8750 950 60  0000 C CNN
	1    8750 1600
	-1   0    0    -1  
$EndComp
$Comp
L ADS1110 U2
U 1 1 53731381
P 8550 3550
F 0 "U2" H 8200 3850 70  0000 C CNN
F 1 "ADS1110" H 8750 3250 70  0000 C CNN
F 2 "~" H 8550 2900 60  0000 C CNN
F 3 "~" H 8550 2900 60  0000 C CNN
	1    8550 3550
	-1   0    0    -1  
$EndComp
$Comp
L BATTERY BATT1
U 1 1 5373142D
P 7900 2150
F 0 "BATT1" H 7900 2350 50  0000 C CNN
F 1 "CR2303" H 7900 1960 50  0000 C CNN
F 2 "~" H 7900 2150 60  0000 C CNN
F 3 "~" H 7900 2150 60  0000 C CNN
	1    7900 2150
	0    -1   1    0   
$EndComp
Entry Wire Line
	7450 4900 7550 5000
Entry Wire Line
	7450 5000 7550 5100
$Comp
L GND #PWR010
U 1 1 53731A2E
P 7800 6200
F 0 "#PWR010" H 7800 6200 30  0001 C CNN
F 1 "GND" H 7800 6130 30  0001 C CNN
F 2 "" H 7800 6200 60  0000 C CNN
F 3 "" H 7800 6200 60  0000 C CNN
	1    7800 6200
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR011
U 1 1 53731AEF
P 9600 2750
F 0 "#PWR011" H 9600 2700 20  0001 C CNN
F 1 "+12V" H 9600 2850 30  0000 C CNN
F 2 "" H 9600 2750 60  0000 C CNN
F 3 "" H 9600 2750 60  0000 C CNN
	1    9600 2750
	-1   0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 53731AF5
P 9600 3100
F 0 "R1" V 9680 3100 40  0000 C CNN
F 1 "??" V 9607 3101 40  0000 C CNN
F 2 "~" V 9530 3100 30  0000 C CNN
F 3 "~" H 9600 3100 30  0000 C CNN
	1    9600 3100
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 53731AFB
P 9600 3800
F 0 "R2" V 9680 3800 40  0000 C CNN
F 1 "??" V 9607 3801 40  0000 C CNN
F 2 "~" V 9530 3800 30  0000 C CNN
F 3 "~" H 9600 3800 30  0000 C CNN
	1    9600 3800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 53731CB5
P 9600 4200
F 0 "#PWR012" H 9600 4200 30  0001 C CNN
F 1 "GND" H 9600 4130 30  0001 C CNN
F 2 "" H 9600 4200 60  0000 C CNN
F 3 "" H 9600 4200 60  0000 C CNN
	1    9600 4200
	-1   0    0    -1  
$EndComp
Entry Wire Line
	7550 3500 7450 3600
Entry Wire Line
	7550 3600 7450 3700
$Comp
L GND #PWR013
U 1 1 53731F92
P 1150 4400
F 0 "#PWR013" H 1150 4400 30  0001 C CNN
F 1 "GND" H 1150 4330 30  0001 C CNN
F 2 "" H 1150 4400 60  0000 C CNN
F 3 "" H 1150 4400 60  0000 C CNN
	1    1150 4400
	1    0    0    -1  
$EndComp
Text GLabel 1000 4250 0    60   Input ~ 0
AKU-
Text Label 9500 5200 0    60   ~ 0
TX
Text Label 9500 5300 0    60   ~ 0
RX
Text GLabel 7650 5400 0    60   Output ~ 0
REL#1
Text GLabel 7650 5550 0    60   Output ~ 0
REL#2
Text GLabel 5650 5550 2    60   Input ~ 0
REL#1
Text GLabel 5650 4050 2    60   Input ~ 0
REL#2
$Comp
L GND #PWR014
U 1 1 537324EA
P 9500 2000
F 0 "#PWR014" H 9500 2000 30  0001 C CNN
F 1 "GND" H 9500 1930 30  0001 C CNN
F 2 "" H 9500 2000 60  0000 C CNN
F 3 "" H 9500 2000 60  0000 C CNN
	1    9500 2000
	-1   0    0    -1  
$EndComp
$Comp
L +5V #PWR015
U 1 1 537324F0
P 9500 900
F 0 "#PWR015" H 9500 990 20  0001 C CNN
F 1 "+5V" H 9500 990 30  0000 C CNN
F 2 "" H 9500 900 60  0000 C CNN
F 3 "" H 9500 900 60  0000 C CNN
	1    9500 900 
	-1   0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 537324F6
P 9200 1000
F 0 "C2" H 9200 1100 40  0000 L CNN
F 1 "100n" H 9206 915 40  0000 L CNN
F 2 "~" H 9238 850 30  0000 C CNN
F 3 "~" H 9200 1000 60  0000 C CNN
	1    9200 1000
	0    1    -1   0   
$EndComp
$Comp
L GND #PWR016
U 1 1 537324FC
P 8900 1100
F 0 "#PWR016" H 8900 1100 30  0001 C CNN
F 1 "GND" H 8900 1030 30  0001 C CNN
F 2 "" H 8900 1100 60  0000 C CNN
F 3 "" H 8900 1100 60  0000 C CNN
	1    8900 1100
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 53732805
P 7900 2600
F 0 "#PWR017" H 7900 2600 30  0001 C CNN
F 1 "GND" H 7900 2530 30  0001 C CNN
F 2 "" H 7900 2600 60  0000 C CNN
F 3 "" H 7900 2600 60  0000 C CNN
	1    7900 2600
	-1   0    0    -1  
$EndComp
$Comp
L +5V #PWR018
U 1 1 5373298C
P 7900 800
F 0 "#PWR018" H 7900 890 20  0001 C CNN
F 1 "+5V" H 7900 890 30  0000 C CNN
F 2 "" H 7900 800 60  0000 C CNN
F 3 "" H 7900 800 60  0000 C CNN
	1    7900 800 
	-1   0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 53732A14
P 7900 1100
F 0 "R6" V 7980 1100 40  0000 C CNN
F 1 "??" V 7907 1101 40  0000 C CNN
F 2 "~" V 7830 1100 30  0000 C CNN
F 3 "~" H 7900 1100 30  0000 C CNN
	1    7900 1100
	1    0    0    -1  
$EndComp
Entry Wire Line
	7550 1450 7450 1550
Entry Wire Line
	7550 1550 7450 1650
$Comp
L GND #PWR019
U 1 1 53732D65
P 9350 4050
F 0 "#PWR019" H 9350 4050 30  0001 C CNN
F 1 "GND" H 9350 3980 30  0001 C CNN
F 2 "" H 9350 4050 60  0000 C CNN
F 3 "" H 9350 4050 60  0000 C CNN
	1    9350 4050
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 53732D6B
P 7750 4050
F 0 "#PWR020" H 7750 4050 30  0001 C CNN
F 1 "GND" H 7750 3980 30  0001 C CNN
F 2 "" H 7750 4050 60  0000 C CNN
F 3 "" H 7750 4050 60  0000 C CNN
	1    7750 4050
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR021
U 1 1 5373307C
P 8350 3100
F 0 "#PWR021" H 8350 3100 30  0001 C CNN
F 1 "GND" H 8350 3030 30  0001 C CNN
F 2 "" H 8350 3100 60  0000 C CNN
F 3 "" H 8350 3100 60  0000 C CNN
	1    8350 3100
	-1   0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 53733082
P 8050 3000
F 0 "C1" H 8050 3100 40  0000 L CNN
F 1 "100n" H 8056 2915 40  0000 L CNN
F 2 "~" H 8088 2850 30  0000 C CNN
F 3 "~" H 8050 3000 60  0000 C CNN
	1    8050 3000
	0    1    -1   0   
$EndComp
$Comp
L +5V #PWR022
U 1 1 53733088
P 7750 2900
F 0 "#PWR022" H 7750 2990 20  0001 C CNN
F 1 "+5V" H 7750 2990 30  0000 C CNN
F 2 "" H 7750 2900 60  0000 C CNN
F 3 "" H 7750 2900 60  0000 C CNN
	1    7750 2900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9250 5900 10850 5900
Wire Wire Line
	9250 5700 10600 5700
Wire Wire Line
	9250 5600 10350 5600
Wire Wire Line
	9250 5300 9850 5300
Wire Wire Line
	9250 5200 9750 5200
Wire Wire Line
	9850 5300 9850 5200
Wire Wire Line
	9950 5200 9950 5300
Wire Wire Line
	10600 5700 10600 5600
Wire Wire Line
	10850 5900 10850 5600
Wire Wire Line
	10850 5200 10850 5100
Wire Wire Line
	10600 5200 10600 5100
Wire Wire Line
	10350 5200 10350 5100
Wire Wire Line
	7800 4900 7950 4900
Wire Wire Line
	7800 4500 7800 4900
Wire Wire Line
	10350 4500 10350 4600
Wire Wire Line
	10600 4500 10600 4600
Wire Wire Line
	7800 4500 10850 4500
Connection ~ 10350 4500
Wire Wire Line
	10850 4500 10850 4600
Wire Wire Line
	9250 4900 9400 4900
Wire Wire Line
	1950 1150 2750 1150
Wire Wire Line
	1950 1250 2550 1250
Wire Wire Line
	2550 1250 2550 1350
Wire Wire Line
	2550 1350 2750 1350
Wire Wire Line
	2750 1450 2500 1450
Wire Wire Line
	2500 1450 2500 1350
Wire Wire Line
	2500 1350 1950 1350
Wire Wire Line
	1950 1450 2100 1450
Wire Wire Line
	2100 950  2100 1550
Wire Wire Line
	2100 1550 1950 1550
Connection ~ 2100 1450
Wire Wire Line
	1950 1650 2750 1650
Wire Wire Line
	1950 1850 2100 1850
Wire Wire Line
	2100 1750 2100 2100
Wire Wire Line
	1950 1750 2100 1750
Connection ~ 2100 1850
Wire Wire Line
	3000 3550 3000 3500
Wire Wire Line
	1000 3900 1250 3900
Wire Wire Line
	2150 3950 2500 3950
Wire Wire Line
	2500 4650 3750 4650
Connection ~ 2500 3950
Connection ~ 3600 3200
Wire Wire Line
	2500 3200 2600 3200
Wire Wire Line
	2500 3200 2500 4650
Wire Wire Line
	3600 4850 3750 4850
Connection ~ 3600 4650
Wire Wire Line
	5000 4050 5050 4050
Wire Wire Line
	5000 5550 5050 5550
Wire Wire Line
	4700 4250 4700 4400
Wire Wire Line
	4700 4850 4700 5350
Wire Wire Line
	4650 3400 4700 3400
Wire Wire Line
	4700 3400 4700 3850
Wire Wire Line
	4350 3750 4700 3750
Connection ~ 4700 3750
Connection ~ 3600 3400
Wire Wire Line
	3600 3750 3950 3750
Wire Wire Line
	3600 3100 3600 3750
Wire Wire Line
	3600 3400 3750 3400
Wire Wire Line
	3400 3200 3750 3200
Wire Wire Line
	4350 5200 4700 5200
Connection ~ 4700 5200
Wire Wire Line
	4650 4850 4700 4850
Connection ~ 3600 4850
Wire Wire Line
	1250 4100 1150 4100
Wire Wire Line
	1150 4100 1150 3900
Connection ~ 1150 3900
Wire Wire Line
	3600 5200 3950 5200
Wire Wire Line
	3600 4650 3600 5200
Wire Wire Line
	4650 4700 5450 4700
Wire Wire Line
	5450 4700 5450 4600
Wire Wire Line
	5450 3250 4650 3250
Wire Wire Line
	5450 3150 5450 3250
Wire Wire Line
	9250 5100 9400 5100
Wire Wire Line
	9400 5100 9400 6200
Wire Wire Line
	2150 4100 2200 4100
Wire Wire Line
	7950 5100 7550 5100
Wire Wire Line
	7950 5000 7550 5000
Wire Wire Line
	9250 5800 9400 5800
Connection ~ 9400 5800
Wire Wire Line
	9250 5500 9400 5500
Connection ~ 9400 5500
Wire Wire Line
	9400 5000 9250 5000
Wire Wire Line
	9400 4700 9400 5000
Connection ~ 9400 4900
Wire Wire Line
	7950 5300 7800 5300
Wire Wire Line
	7800 5300 7800 6200
Wire Wire Line
	7950 6100 7800 6100
Connection ~ 7800 6100
Wire Wire Line
	9600 3350 9600 3550
Wire Wire Line
	9600 2850 9600 2750
Wire Wire Line
	9250 3450 9600 3450
Connection ~ 9600 3450
Wire Wire Line
	9600 4050 9600 4200
Wire Wire Line
	9350 3650 9250 3650
Wire Wire Line
	7850 3600 7550 3600
Wire Wire Line
	7850 3500 7550 3500
Wire Wire Line
	1000 4250 1150 4250
Wire Wire Line
	1150 4250 1150 4400
Wire Wire Line
	7650 5550 7750 5550
Wire Wire Line
	7750 5550 7750 5500
Wire Wire Line
	7750 5500 7950 5500
Wire Wire Line
	7650 5400 7950 5400
Wire Wire Line
	5650 5550 5550 5550
Wire Wire Line
	5550 4050 5650 4050
Wire Wire Line
	8050 1750 7900 1750
Wire Wire Line
	7900 1750 7900 1850
Wire Wire Line
	9750 1650 9450 1650
Wire Wire Line
	9750 1550 9450 1550
Wire Wire Line
	9400 1000 9500 1000
Wire Wire Line
	9000 1000 8900 1000
Wire Wire Line
	8900 1000 8900 1100
Wire Wire Line
	9500 1450 9450 1450
Connection ~ 9500 1000
Wire Wire Line
	9450 1750 9500 1750
Wire Wire Line
	9500 1750 9500 2000
Wire Wire Line
	9750 1650 9750 1850
Wire Wire Line
	9750 1850 10400 1850
Wire Wire Line
	10400 1850 10400 1550
Wire Wire Line
	10400 1550 10350 1550
Wire Wire Line
	7900 2600 7900 2450
Wire Wire Line
	9500 900  9500 1450
Wire Wire Line
	8050 1650 7900 1650
Wire Wire Line
	7900 1650 7900 1350
Wire Wire Line
	7900 850  7900 800 
Wire Wire Line
	8050 1450 7550 1450
Wire Wire Line
	8050 1550 7550 1550
Wire Bus Line
	7450 1550 7450 5000
Wire Wire Line
	7750 4050 7750 3700
Wire Wire Line
	7750 3700 7850 3700
Wire Wire Line
	9350 3650 9350 4050
Wire Wire Line
	7850 3000 7750 3000
Wire Wire Line
	7750 2900 7750 3400
Wire Wire Line
	7750 3400 7850 3400
Connection ~ 7750 3000
Wire Wire Line
	8250 3000 8350 3000
Wire Wire Line
	8350 3000 8350 3100
Wire Wire Line
	2200 4100 2200 4300
Wire Wire Line
	2350 4600 2350 4700
Text Label 7600 5100 0    60   ~ 0
SCL
Text Label 7600 5000 0    60   ~ 0
SDA
Text Label 7600 3500 0    60   ~ 0
SDA
Text Label 7600 3600 0    60   ~ 0
SCL
Text Label 7600 1550 0    60   ~ 0
SCL
Text Label 7600 1450 0    60   ~ 0
SDA
Connection ~ 10600 4500
Entry Wire Line
	7350 3100 7450 3000
Entry Wire Line
	7350 3250 7450 3150
Text GLabel 7100 3100 0    60   Output ~ 0
SCL
Text GLabel 7100 3250 0    60   Output ~ 0
SDA
Wire Wire Line
	7100 3250 7350 3250
Wire Wire Line
	7100 3100 7350 3100
Text GLabel 3050 6550 2    60   Input ~ 0
SCL
Text GLabel 3050 6700 2    60   Input ~ 0
SDA
$Comp
L +12V #PWR023
U 1 1 5373388C
P 5250 7250
F 0 "#PWR023" H 5250 7200 20  0001 C CNN
F 1 "+12V" H 5250 7350 30  0000 C CNN
F 2 "" H 5250 7250 60  0000 C CNN
F 3 "" H 5250 7250 60  0000 C CNN
	1    5250 7250
	0    1    -1   0   
$EndComp
$Comp
L +5C #PWR024
U 1 1 53733892
P 1400 6500
F 0 "#PWR024" H 1400 6450 20  0001 C CNN
F 1 "+5C" H 1400 6600 30  0000 C CNN
F 2 "" H 1400 6500 60  0000 C CNN
F 3 "" H 1400 6500 60  0000 C CNN
	1    1400 6500
	1    0    0    -1  
$EndComp
$Comp
L MiniIMU-9 U4
U 1 1 5373C0E5
P 6350 2300
F 0 "U4" H 6000 2600 70  0000 C CNN
F 1 "MiniIMU-9" H 6550 2000 70  0000 C CNN
F 2 "" H 6350 1650 60  0000 C CNN
F 3 "" H 6350 1650 60  0000 C CNN
	1    6350 2300
	1    0    0    -1  
$EndComp
Entry Wire Line
	7350 2150 7450 2050
Entry Wire Line
	7350 2250 7450 2150
Wire Wire Line
	7350 2250 7050 2250
Wire Wire Line
	7050 2150 7350 2150
$Comp
L GND #PWR025
U 1 1 5373CCC9
P 5550 2550
F 0 "#PWR025" H 5550 2550 30  0001 C CNN
F 1 "GND" H 5550 2480 30  0001 C CNN
F 2 "" H 5550 2550 60  0000 C CNN
F 3 "" H 5550 2550 60  0000 C CNN
	1    5550 2550
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5550 2550 5550 2450
Wire Wire Line
	5550 2450 5650 2450
Text Label 7150 3100 0    60   ~ 0
SCL
Text Label 7150 3250 0    60   ~ 0
SDA
Text Label 7150 2250 0    60   ~ 0
SCL
Text Label 7150 2150 0    60   ~ 0
SDA
Text Label 1050 4250 0    60   ~ 0
GND
NoConn ~ 9250 5400
NoConn ~ 9250 6000
NoConn ~ 9250 6100
NoConn ~ 7950 6000
NoConn ~ 7950 5900
NoConn ~ 7950 5800
NoConn ~ 7950 5600
NoConn ~ 7950 5200
$Comp
L CONN_3 J6
U 1 1 5373B48C
P 2800 7250
F 0 "J6" V 2750 7250 50  0000 C CNN
F 1 "I2C" V 2850 7250 40  0000 C CNN
F 2 "~" H 2800 7250 60  0000 C CNN
F 3 "~" H 2800 7250 60  0000 C CNN
	1    2800 7250
	0    1    1    0   
$EndComp
$Comp
L CONN_3 J5
U 1 1 5373B4D9
P 2400 7250
F 0 "J5" V 2350 7250 50  0000 C CNN
F 1 "I2C" V 2450 7250 40  0000 C CNN
F 2 "~" H 2400 7250 60  0000 C CNN
F 3 "~" H 2400 7250 60  0000 C CNN
	1    2400 7250
	0    1    1    0   
$EndComp
$Comp
L CONN_3 J4
U 1 1 5373B4DF
P 2000 7250
F 0 "J4" V 1950 7250 50  0000 C CNN
F 1 "I2C" V 2050 7250 40  0000 C CNN
F 2 "~" H 2000 7250 60  0000 C CNN
F 3 "~" H 2000 7250 60  0000 C CNN
	1    2000 7250
	0    1    1    0   
$EndComp
$Comp
L GND #PWR026
U 1 1 5373B527
P 1200 6800
F 0 "#PWR026" H 1200 6800 30  0001 C CNN
F 1 "GND" H 1200 6730 30  0001 C CNN
F 2 "" H 1200 6800 60  0000 C CNN
F 3 "" H 1200 6800 60  0000 C CNN
	1    1200 6800
	0    1    1    0   
$EndComp
$Comp
L CONN_4 J3
U 1 1 5373B53F
P 1550 7250
F 0 "J3" V 1500 7250 50  0000 C CNN
F 1 "I2C" V 1600 7250 50  0000 C CNN
F 2 "~" H 1550 7250 60  0000 C CNN
F 3 "~" H 1550 7250 60  0000 C CNN
	1    1550 7250
	0    1    1    0   
$EndComp
Wire Wire Line
	2900 6900 2900 6700
Wire Wire Line
	1700 6700 3050 6700
Wire Wire Line
	2500 6700 2500 6900
Connection ~ 2900 6700
Wire Wire Line
	2100 6700 2100 6900
Connection ~ 2500 6700
Wire Wire Line
	1700 6700 1700 6900
Connection ~ 2100 6700
Wire Wire Line
	2800 6900 2800 6550
Wire Wire Line
	1600 6550 3050 6550
Wire Wire Line
	2400 6550 2400 6900
Connection ~ 2800 6550
Wire Wire Line
	2000 6550 2000 6900
Connection ~ 2400 6550
Wire Wire Line
	1600 6550 1600 6900
Connection ~ 2000 6550
Wire Wire Line
	1500 6900 1500 6800
Wire Wire Line
	1200 6800 2700 6800
Wire Wire Line
	1400 6500 1400 6900
Wire Wire Line
	1900 6900 1900 6800
Connection ~ 1500 6800
Wire Wire Line
	2300 6900 2300 6800
Connection ~ 1900 6800
Wire Wire Line
	2700 6800 2700 6900
Connection ~ 2300 6800
$Comp
L +5C #PWR027
U 1 1 5373BE09
P 5250 7050
F 0 "#PWR027" H 5250 7000 20  0001 C CNN
F 1 "+5C" H 5250 7150 30  0000 C CNN
F 2 "" H 5250 7050 60  0000 C CNN
F 3 "" H 5250 7050 60  0000 C CNN
	1    5250 7050
	0    1    -1   0   
$EndComp
$Comp
L GND #PWR028
U 1 1 5373BE0F
P 3800 7350
F 0 "#PWR028" H 3800 7350 30  0001 C CNN
F 1 "GND" H 3800 7280 30  0001 C CNN
F 2 "" H 3800 7350 60  0000 C CNN
F 3 "" H 3800 7350 60  0000 C CNN
	1    3800 7350
	-1   0    0    -1  
$EndComp
$Comp
L CONN_3 J9
U 1 1 5373BE26
P 4600 6550
F 0 "J9" V 4550 6550 50  0000 C CNN
F 1 "PWR" V 4650 6550 40  0000 C CNN
F 2 "~" H 4600 6550 60  0000 C CNN
F 3 "~" H 4600 6550 60  0000 C CNN
	1    4600 6550
	0    1    -1   0   
$EndComp
$Comp
L CONN_3 J8
U 1 1 5373BE43
P 4200 6550
F 0 "J8" V 4150 6550 50  0000 C CNN
F 1 "PWR" V 4250 6550 40  0000 C CNN
F 2 "~" H 4200 6550 60  0000 C CNN
F 3 "~" H 4200 6550 60  0000 C CNN
	1    4200 6550
	0    1    -1   0   
$EndComp
$Comp
L CONN_3 J7
U 1 1 5373BE49
P 3800 6550
F 0 "J7" V 3750 6550 50  0000 C CNN
F 1 "PWR" V 3850 6550 40  0000 C CNN
F 2 "~" H 3800 6550 60  0000 C CNN
F 3 "~" H 3800 6550 60  0000 C CNN
	1    3800 6550
	0    1    -1   0   
$EndComp
$Comp
L CONN_3 J10
U 1 1 5373BE63
P 5000 6550
F 0 "J10" V 4950 6550 50  0000 C CNN
F 1 "PWR" V 5050 6550 40  0000 C CNN
F 2 "~" H 5000 6550 60  0000 C CNN
F 3 "~" H 5000 6550 60  0000 C CNN
	1    5000 6550
	0    1    -1   0   
$EndComp
Wire Wire Line
	3900 7050 5250 7050
Wire Wire Line
	5100 7050 5100 6900
Wire Wire Line
	3700 7250 5250 7250
Wire Wire Line
	4900 7250 4900 6900
Wire Wire Line
	4500 7250 4500 6900
Connection ~ 4900 7250
Wire Wire Line
	4100 7250 4100 6900
Connection ~ 4500 7250
Wire Wire Line
	3700 7250 3700 6900
Connection ~ 4100 7250
Wire Wire Line
	4700 7050 4700 6900
Connection ~ 5100 7050
Wire Wire Line
	4300 7050 4300 6900
Connection ~ 4700 7050
Wire Wire Line
	3900 7050 3900 6900
Connection ~ 4300 7050
Wire Wire Line
	3800 6900 3800 7350
Wire Wire Line
	4200 6900 4200 7150
Wire Wire Line
	3800 7150 5000 7150
Wire Wire Line
	4600 7150 4600 6900
Connection ~ 4200 7150
Wire Wire Line
	5000 7150 5000 6900
Connection ~ 4600 7150
Connection ~ 3800 7150
$Comp
L CRYSTAL X1
U 1 1 5373BB22
P 10050 1550
F 0 "X1" H 10050 1700 60  0000 C CNN
F 1 "CRYSTAL" H 10050 1400 60  0000 C CNN
F 2 "~" H 10050 1550 60  0000 C CNN
F 3 "~" H 10050 1550 60  0000 C CNN
	1    10050 1550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
