EESchema Schematic File Version 2
LIBS:Control de temperatura Mega-rescue
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
LIBS:w_device
LIBS:w_transistor
LIBS:w_connectors
LIBS:w_analog
LIBS:w_microcontrollers
LIBS:w_memory
LIBS:w_rtx
LIBS:w_logic
LIBS:w_opto
LIBS:w_relay
LIBS:relays
LIBS:Control de temperatura Mega-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Control de temperatuera amb Arduino Mega"
Date "2017-07-08"
Rev ""
Comp "EV"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L HEADER_8 J2
U 1 1 59614461
P 3750 3200
F 0 "J2" H 3750 3650 60  0000 C CNN
F 1 "Analog input" H 4150 3100 60  0000 C CNN
F 2 "w_pin_strip:pin_socket_8" H 3750 3200 60  0001 C CNN
F 3 "" H 3750 3200 60  0000 C CNN
	1    3750 3200
	1    0    0    -1  
$EndComp
$Comp
L HEADER_8 J1
U 1 1 596144D0
P 3750 2250
F 0 "J1" H 3750 2700 60  0000 C CNN
F 1 "Power" H 4000 2100 60  0000 C CNN
F 2 "w_pin_strip:pin_socket_8" H 3750 2250 60  0001 C CNN
F 3 "" H 3750 2250 60  0000 C CNN
	1    3750 2250
	1    0    0    -1  
$EndComp
$Comp
L HEADER_8 J4
U 1 1 596145C9
P 4700 3200
F 0 "J4" H 4700 3650 60  0000 C CNN
F 1 "Digital/PWM 1" H 5150 3400 60  0000 C CNN
F 2 "w_pin_strip:pin_socket_8" H 4700 3200 60  0001 C CNN
F 3 "" H 4700 3200 60  0000 C CNN
	1    4700 3200
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 59614A6C
P 6550 3950
F 0 "#PWR01" H 6550 3950 30  0001 C CNN
F 1 "GND" H 6550 3880 30  0001 C CNN
F 2 "" H 6550 3950 60  0001 C CNN
F 3 "" H 6550 3950 60  0001 C CNN
	1    6550 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 59614AA1
P 6950 3950
F 0 "#PWR02" H 6950 3950 30  0001 C CNN
F 1 "GND" H 6950 3880 30  0001 C CNN
F 2 "" H 6950 3950 60  0001 C CNN
F 3 "" H 6950 3950 60  0001 C CNN
	1    6950 3950
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR03
U 1 1 59614AB8
P 6550 2150
F 0 "#PWR03" H 6550 2250 30  0001 C CNN
F 1 "VCC" H 6550 2250 30  0000 C CNN
F 2 "" H 6550 2150 60  0001 C CNN
F 3 "" H 6550 2150 60  0001 C CNN
	1    6550 2150
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR04
U 1 1 59614AE3
P 6950 2150
F 0 "#PWR04" H 6950 2250 30  0001 C CNN
F 1 "VCC" H 6950 2250 30  0000 C CNN
F 2 "" H 6950 2150 60  0001 C CNN
F 3 "" H 6950 2150 60  0001 C CNN
	1    6950 2150
	1    0    0    -1  
$EndComp
$Comp
L LED_1 D1
U 1 1 5961DD2B
P 5800 3900
F 0 "D1" V 5800 3800 50  0000 C CNN
F 1 "Verd" V 5850 3750 50  0000 C CNN
F 2 "W_led:Led_3mm_verd" H 5800 3900 50  0001 C CNN
F 3 "" H 5800 3900 50  0001 C CNN
	1    5800 3900
	0    1    1    0   
$EndComp
$Comp
L LED_1 D2
U 1 1 5961DD60
P 6100 3900
F 0 "D2" V 6100 3800 50  0000 C CNN
F 1 "Groc" V 6150 3750 50  0000 C CNN
F 2 "W_led:Led_3mm_groc" H 6100 3900 50  0001 C CNN
F 3 "" H 6100 3900 50  0001 C CNN
	1    6100 3900
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-Control_de_temperatura_Mega R3
U 1 1 5961E27B
P 5800 4200
F 0 "R3" H 5900 4150 50  0000 C CNN
F 1 "470" H 5900 4250 50  0000 C CNN
F 2 "w_pth_resistors:RC05" V 5730 4200 50  0001 C CNN
F 3 "" H 5800 4200 50  0001 C CNN
	1    5800 4200
	-1   0    0    1   
$EndComp
$Comp
L R-RESCUE-Control_de_temperatura_Mega R4
U 1 1 5961E2CA
P 6100 4200
F 0 "R4" H 6000 4250 50  0000 C CNN
F 1 "470" H 6000 4150 50  0000 C CNN
F 2 "w_pth_resistors:RC05" V 6030 4200 50  0001 C CNN
F 3 "" H 6100 4200 50  0001 C CNN
	1    6100 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 2150 6550 2200
Wire Wire Line
	6550 2200 6600 2200
Wire Wire Line
	6950 2150 6950 2200
Wire Wire Line
	6950 2200 6900 2200
Wire Wire Line
	6600 3900 6550 3900
Wire Wire Line
	6550 3900 6550 3950
Wire Wire Line
	6900 3900 6950 3900
Wire Wire Line
	6950 3900 6950 3950
Wire Wire Line
	6600 3800 6100 3800
Wire Wire Line
	6100 3800 6100 3850
$Comp
L GND #PWR05
U 1 1 5961E68B
P 6100 4400
F 0 "#PWR05" H 6100 4400 30  0001 C CNN
F 1 "GND" H 6100 4330 30  0001 C CNN
F 2 "" H 6100 4400 60  0001 C CNN
F 3 "" H 6100 4400 60  0001 C CNN
	1    6100 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 5961E6B1
P 5800 4400
F 0 "#PWR06" H 5800 4400 30  0001 C CNN
F 1 "GND" H 5800 4330 30  0001 C CNN
F 2 "" H 5800 4400 60  0001 C CNN
F 3 "" H 5800 4400 60  0001 C CNN
	1    5800 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 4000 6100 4050
Wire Wire Line
	6100 4350 6100 4400
Wire Wire Line
	5800 4000 5800 4050
Wire Wire Line
	5800 4350 5800 4400
Text Label 6150 3800 0    60   ~ 0
LedMode
Wire Wire Line
	6600 3700 5800 3700
Wire Wire Line
	5800 3700 5800 3850
Text Label 6150 3700 0    60   ~ 0
LedCale
$Comp
L FINDER-30.22-RESCUE-Control_de_temperatura_Mega RL1
U 1 1 5961F241
P 8150 4400
F 0 "RL1" H 7800 4650 40  0000 C CNN
F 1 "FINDER-30.22" V 8995 4405 40  0000 C CNN
F 2 "w_relay:Rele_30.22" H 8150 4400 60  0001 C CNN
F 3 "" H 8150 4400 60  0001 C CNN
	1    8150 4400
	1    0    0    -1  
$EndComp
$Comp
L 2N2222 Q1
U 1 1 5961F2FA
P 7850 5100
F 0 "Q1" H 8100 5150 50  0000 C CNN
F 1 "2N2222" H 7700 5250 50  0000 C CNN
F 2 "w_to:to18_1" H 7850 5100 60  0001 C CNN
F 3 "" H 7850 5100 60  0000 C CNN
	1    7850 5100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5961F3C8
P 7950 5450
F 0 "#PWR07" H 7950 5450 30  0001 C CNN
F 1 "GND" H 7950 5380 30  0001 C CNN
F 2 "" H 7950 5450 60  0001 C CNN
F 3 "" H 7950 5450 60  0001 C CNN
	1    7950 5450
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-Control_de_temperatura_Mega R5
U 1 1 5961F3F4
P 7350 5100
F 0 "R5" V 7430 5100 50  0000 C CNN
F 1 "56" V 7350 5100 50  0000 C CNN
F 2 "w_pth_resistors:RC05" V 7280 5100 50  0001 C CNN
F 3 "" H 7350 5100 50  0001 C CNN
	1    7350 5100
	0    1    1    0   
$EndComp
$Comp
L VCC #PWR08
U 1 1 5961F48C
P 7950 3950
F 0 "#PWR08" H 7950 4050 30  0001 C CNN
F 1 "VCC" H 7950 4050 30  0000 C CNN
F 2 "" H 7950 3950 60  0001 C CNN
F 3 "" H 7950 3950 60  0001 C CNN
	1    7950 3950
	1    0    0    -1  
$EndComp
$Comp
L DIODE-RESCUE-Control_de_temperatura_Mega D3
U 1 1 5961F4B1
P 7600 4400
F 0 "D3" V 7700 4450 40  0000 C CNN
F 1 "1N4007" V 7550 4550 40  0000 C CNN
F 2 "w_pth_diodes:diode_do35" H 7600 4400 60  0001 C CNN
F 3 "" H 7600 4400 60  0000 C CNN
	1    7600 4400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7950 3950 7950 4100
Wire Wire Line
	7950 4700 7950 4900
Wire Wire Line
	7950 5300 7950 5450
Wire Wire Line
	7500 5100 7650 5100
Wire Wire Line
	7600 4300 7600 4050
Wire Wire Line
	7600 4050 7950 4050
Connection ~ 7950 4050
Wire Wire Line
	7600 4450 7600 4750
Wire Wire Line
	7600 4750 7950 4750
Connection ~ 7950 4750
Wire Wire Line
	7200 5100 7150 5100
Wire Wire Line
	7150 5100 7150 3800
Wire Wire Line
	7150 3800 6900 3800
Text Label 7000 3800 0    60   ~ 0
ReleCale
$Comp
L HEADER_3 J10
U 1 1 5961F7C7
P 9250 3950
F 0 "J10" H 9250 4150 60  0000 C CNN
F 1 "Calefacció" H 9600 3950 60  0000 C CNN
F 2 "w_conn_mkds:mkds_1,5-3" H 9250 3950 60  0001 C CNN
F 3 "" H 9250 3950 60  0000 C CNN
	1    9250 3950
	1    0    0    1   
$EndComp
Wire Wire Line
	8500 4100 8500 3850
Wire Wire Line
	8500 3850 9150 3850
Wire Wire Line
	8300 4100 8300 3950
Wire Wire Line
	8300 3950 9150 3950
Wire Wire Line
	9150 4050 9050 4050
Wire Wire Line
	9050 4050 9050 4900
Wire Wire Line
	8400 4700 8400 4900
$Comp
L HEADER_3 J6
U 1 1 5961FF2C
P 6000 2050
F 0 "J6" H 6000 2250 60  0000 C CNN
F 1 "Sensor DHT22" H 6450 2050 60  0000 C CNN
F 2 "w_pin_strip:pin_socket_3" H 6000 2050 60  0001 C CNN
F 3 "" H 6000 2050 60  0000 C CNN
	1    6000 2050
	-1   0    0    -1  
$EndComp
$Comp
L VCC #PWR09
U 1 1 596200B0
P 6150 1900
F 0 "#PWR09" H 6150 2000 30  0001 C CNN
F 1 "VCC" H 6150 2000 30  0000 C CNN
F 2 "" H 6150 1900 60  0001 C CNN
F 3 "" H 6150 1900 60  0001 C CNN
	1    6150 1900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6150 1900 6150 2050
Wire Wire Line
	6150 2050 6100 2050
$Comp
L GND #PWR010
U 1 1 59620198
P 6150 2200
F 0 "#PWR010" H 6150 2200 30  0001 C CNN
F 1 "GND" H 6150 2130 30  0001 C CNN
F 2 "" H 6150 2200 60  0001 C CNN
F 3 "" H 6150 2200 60  0001 C CNN
	1    6150 2200
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6100 2150 6150 2150
Wire Wire Line
	6150 2150 6150 2200
Wire Wire Line
	6100 1950 7050 1950
Wire Wire Line
	7050 1950 7050 2300
Wire Wire Line
	7050 2300 6900 2300
Text Label 6400 1950 0    60   ~ 0
DHT22
$Comp
L GND #PWR011
U 1 1 59620842
P 3550 2700
F 0 "#PWR011" H 3550 2700 30  0001 C CNN
F 1 "GND" H 3550 2630 30  0001 C CNN
F 2 "" H 3550 2700 60  0001 C CNN
F 3 "" H 3550 2700 60  0001 C CNN
	1    3550 2700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3650 2400 3550 2400
Wire Wire Line
	3550 2400 3550 2700
Wire Wire Line
	3650 2500 3550 2500
Connection ~ 3550 2500
NoConn ~ 3650 2600
NoConn ~ 3650 2200
NoConn ~ 3650 2100
NoConn ~ 3650 2000
NoConn ~ 3650 1900
$Comp
L NodeMCU_ESP12E U1
U 1 1 596264A0
P 2350 4700
F 0 "U1" H 3800 4850 60  0000 C CNN
F 1 "NodeMCU_ESP12E" H 3000 3150 60  0000 C CNN
F 2 "w_pth_circuits:NodeMCU_ESP12E" H 3300 3200 60  0001 C CNN
F 3 "" H 3300 3200 60  0001 C CNN
	1    2350 4700
	1    0    0    -1  
$EndComp
NoConn ~ 4800 3550
NoConn ~ 4800 3450
$Comp
L HEADER_8 J5
U 1 1 59626CAE
P 4700 4150
F 0 "J5" H 4700 4600 60  0000 C CNN
F 1 "Comunicació" H 5100 4500 60  0000 C CNN
F 2 "w_pin_strip:pin_socket_8" H 4700 4150 60  0001 C CNN
F 3 "" H 4700 4150 60  0000 C CNN
	1    4700 4150
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 59626D8A
P 2200 6200
F 0 "#PWR012" H 2200 6200 30  0001 C CNN
F 1 "GND" H 2200 6130 30  0001 C CNN
F 2 "" H 2200 6200 60  0001 C CNN
F 3 "" H 2200 6200 60  0001 C CNN
	1    2200 6200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 59626DC8
P 4250 5350
F 0 "#PWR013" H 4250 5350 30  0001 C CNN
F 1 "GND" H 4250 5280 30  0001 C CNN
F 2 "" H 4250 5350 60  0001 C CNN
F 3 "" H 4250 5350 60  0001 C CNN
	1    4250 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 5300 4250 5300
Wire Wire Line
	4250 5300 4250 5350
Wire Wire Line
	2350 5600 2200 5600
Wire Wire Line
	2200 5600 2200 6200
Wire Wire Line
	2350 6000 2200 6000
Connection ~ 2200 6000
Wire Wire Line
	2350 6100 2250 6100
Wire Wire Line
	2250 6100 2250 4600
Text GLabel 5000 4300 2    60   Input ~ 0
Rx1
Text GLabel 5550 5900 2    60   Input ~ 0
Rx1
Text GLabel 5000 4200 2    60   Input ~ 0
Tx1
Text GLabel 5550 5800 2    60   Input ~ 0
Tx1
Wire Wire Line
	4800 4200 5000 4200
Wire Wire Line
	4800 4300 5000 4300
Wire Wire Line
	4500 5800 5150 5800
NoConn ~ 4150 5700
NoConn ~ 4150 5600
NoConn ~ 4150 5500
NoConn ~ 4150 5400
NoConn ~ 4150 5200
NoConn ~ 4150 5100
NoConn ~ 4150 5000
NoConn ~ 4150 4900
NoConn ~ 4150 4800
NoConn ~ 4150 4700
NoConn ~ 2350 4700
NoConn ~ 2350 4800
NoConn ~ 2350 4900
NoConn ~ 2350 5000
NoConn ~ 2350 5100
NoConn ~ 2350 5200
NoConn ~ 2350 5300
NoConn ~ 2350 5400
NoConn ~ 2350 5500
NoConn ~ 2350 5700
NoConn ~ 2350 5800
NoConn ~ 2350 5900
NoConn ~ 4150 6100
NoConn ~ 4800 4100
NoConn ~ 4800 4000
NoConn ~ 4800 3900
NoConn ~ 4800 3800
$Comp
L R-RESCUE-Control_de_temperatura_Mega R1
U 1 1 59633689
P 5300 5800
F 0 "R1" V 5200 5750 50  0000 C CNN
F 1 "470" V 5300 5800 50  0000 C CNN
F 2 "w_pth_resistors:RC05" V 5230 5800 50  0001 C CNN
F 3 "" H 5300 5800 50  0001 C CNN
	1    5300 5800
	0    1    1    0   
$EndComp
NoConn ~ 3650 2850
NoConn ~ 3650 2950
NoConn ~ 3650 3050
NoConn ~ 3650 3150
NoConn ~ 3650 3250
NoConn ~ 3650 3350
NoConn ~ 3650 3450
NoConn ~ 3650 3550
NoConn ~ 4800 3350
NoConn ~ 4800 3250
NoConn ~ 4800 3150
NoConn ~ 4800 3050
NoConn ~ 4800 2950
NoConn ~ 4800 2850
NoConn ~ 4800 2600
NoConn ~ 4800 2500
NoConn ~ 4800 2400
NoConn ~ 4800 2300
NoConn ~ 4800 2200
NoConn ~ 4800 2100
NoConn ~ 4800 2000
NoConn ~ 4800 1900
NoConn ~ 6600 2300
NoConn ~ 6900 3700
$Comp
L HEADER_2x2 J7
U 1 1 596351C9
P 6750 2250
F 0 "J7" H 6750 2400 60  0000 C CNN
F 1 "Digital_1" H 7300 2250 60  0000 C CNN
F 2 "w_pin_strip:pin_strip_2x2" H 6750 2250 60  0001 C CNN
F 3 "" H 6750 2250 60  0000 C CNN
	1    6750 2250
	1    0    0    -1  
$EndComp
$Comp
L HEADER_3x2 J8
U 1 1 59635222
P 6750 3800
F 0 "J8" H 6750 4000 60  0000 C CNN
F 1 "Digital_2" H 6750 3500 60  0000 C CNN
F 2 "w_pin_strip:pin_strip_3x2" H 6750 3800 60  0001 C CNN
F 3 "" H 6750 3800 60  0000 C CNN
	1    6750 3800
	1    0    0    -1  
$EndComp
Wire Notes Line
	6700 2350 6700 3650
Wire Notes Line
	6700 3650 6800 3650
Wire Notes Line
	6800 3650 6800 2350
Wire Notes Line
	6800 2350 6700 2350
$Comp
L VDD #PWR014
U 1 1 596388E6
P 3550 2250
F 0 "#PWR014" H 3550 2350 30  0001 C CNN
F 1 "VDD" H 3550 2360 30  0000 C CNN
F 2 "" H 3550 2250 60  0001 C CNN
F 3 "" H 3550 2250 60  0001 C CNN
	1    3550 2250
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR015
U 1 1 59638A10
P 2250 4600
F 0 "#PWR015" H 2250 4700 30  0001 C CNN
F 1 "VDD" H 2250 4710 30  0000 C CNN
F 2 "" H 2250 4600 60  0001 C CNN
F 3 "" H 2250 4600 60  0001 C CNN
	1    2250 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 2300 3550 2300
Wire Wire Line
	3550 2300 3550 2250
Text Label 4800 5800 0    60   ~ 0
RxD0
Text Label 4800 5900 0    60   ~ 0
TxD0
$Comp
L DS1307 U2
U 1 1 596E0D4D
P 9150 2300
F 0 "U2" H 9750 2900 60  0000 C CNN
F 1 "DS1307" H 9650 2250 60  0000 C CNN
F 2 "w_pth_circuits:dil_8-300_socket" H 9150 2300 60  0001 C CNN
F 3 "" H 9150 2300 60  0001 C CNN
	1    9150 2300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 596E0FB4
P 9450 2600
F 0 "#PWR016" H 9450 2600 30  0001 C CNN
F 1 "GND" H 9450 2530 30  0001 C CNN
F 2 "" H 9450 2600 60  0001 C CNN
F 3 "" H 9450 2600 60  0001 C CNN
	1    9450 2600
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-Control_de_temperatura_Mega R7
U 1 1 596E12F7
P 8850 1750
F 0 "R7" H 8950 1700 50  0000 C CNN
F 1 "4K7" H 8950 1800 50  0000 C CNN
F 2 "w_pth_resistors:RC05" V 8780 1750 50  0001 C CNN
F 3 "" H 8850 1750 50  0001 C CNN
	1    8850 1750
	-1   0    0    1   
$EndComp
$Comp
L R-RESCUE-Control_de_temperatura_Mega R6
U 1 1 596E1375
P 8600 1750
F 0 "R6" H 8500 1800 50  0000 C CNN
F 1 "4K7" H 8500 1700 50  0000 C CNN
F 2 "w_pth_resistors:RC05" V 8530 1750 50  0001 C CNN
F 3 "" H 8600 1750 50  0001 C CNN
	1    8600 1750
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 596E1758
P 9300 1350
F 0 "Y1" H 9300 1500 50  0000 C CNN
F 1 "32768" H 9300 1200 50  0000 C CNN
F 2 "Crystals:Crystal_AT310_d3.0mm_l10.0mm_Horizontal" H 9300 1350 50  0001 C CNN
F 3 "" H 9300 1350 50  0001 C CNN
	1    9300 1350
	1    0    0    -1  
$EndComp
$Comp
L BAT-RESCUE-Control_de_temperatura_Mega BAT1
U 1 1 596E17D1
P 10050 2400
F 0 "BAT1" H 10195 2430 50  0000 C CNN
F 1 "CR2025 3V" H 10300 2350 50  0000 C CNN
F 2 "w_battery_holders:keystone_103" H 10050 2400 60  0001 C CNN
F 3 "" H 10050 2400 60  0000 C CNN
	1    10050 2400
	1    0    0    -1  
$EndComp
Text GLabel 8400 2200 0    60   Input ~ 0
SDA
Text GLabel 8400 2000 0    60   Input ~ 0
SCL
Wire Wire Line
	8600 1500 8600 1600
Wire Wire Line
	8850 1600 8850 1550
Wire Wire Line
	8850 1550 8600 1550
Connection ~ 8600 1550
Wire Wire Line
	8400 2200 8950 2200
Wire Wire Line
	8850 1900 8850 2200
Connection ~ 8850 2200
Wire Wire Line
	9600 1500 9600 1550
Wire Wire Line
	9450 2400 9450 2600
Wire Wire Line
	10050 2500 10050 2550
Wire Wire Line
	10050 2550 9450 2550
Connection ~ 9450 2550
Wire Wire Line
	10000 2200 10050 2200
Wire Wire Line
	10050 2200 10050 2300
Wire Wire Line
	9350 1650 9500 1650
Wire Wire Line
	9500 1650 9500 1350
Wire Wire Line
	9500 1350 9450 1350
Wire Wire Line
	9250 1650 9100 1650
Wire Wire Line
	9100 1650 9100 1350
Wire Wire Line
	9100 1350 9150 1350
Text GLabel 5000 1800 2    60   Input ~ 0
SDA
Text GLabel 5000 1700 2    60   Input ~ 0
SCL
Wire Wire Line
	8400 2000 8950 2000
Wire Wire Line
	8600 1900 8600 2000
Connection ~ 8600 2000
NoConn ~ 10000 2000
$Comp
L HEADER_10 J3
U 1 1 59614694
P 4700 2150
F 0 "J3" H 4700 2700 60  0000 C CNN
F 1 "Digital/PWM 2" H 5150 2200 60  0000 C CNN
F 2 "w_pin_strip:pin_socket_10" H 4700 2150 60  0001 C CNN
F 3 "" H 4700 2150 60  0000 C CNN
	1    4700 2150
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4800 1700 5000 1700
Wire Wire Line
	4800 1800 5000 1800
$Comp
L VDD #PWR017
U 1 1 596F2819
P 8600 1500
F 0 "#PWR017" H 8600 1600 30  0001 C CNN
F 1 "VDD" H 8600 1610 30  0000 C CNN
F 2 "" H 8600 1500 60  0001 C CNN
F 3 "" H 8600 1500 60  0001 C CNN
	1    8600 1500
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR018
U 1 1 596F29D8
P 9600 1500
F 0 "#PWR018" H 9600 1600 30  0001 C CNN
F 1 "VDD" H 9600 1610 30  0000 C CNN
F 2 "" H 9600 1500 60  0001 C CNN
F 3 "" H 9600 1500 60  0001 C CNN
	1    9600 1500
	1    0    0    -1  
$EndComp
NoConn ~ 4800 4400
NoConn ~ 4800 4500
$Comp
L GND #PWR019
U 1 1 59C4CFA6
P 5050 6200
F 0 "#PWR019" H 5050 6200 30  0001 C CNN
F 1 "GND" H 5050 6130 30  0001 C CNN
F 2 "" H 5050 6200 60  0001 C CNN
F 3 "" H 5050 6200 60  0001 C CNN
	1    5050 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 6150 5050 6200
Wire Wire Line
	5050 5900 5050 6000
Connection ~ 5050 5900
$Comp
L DIODE-RESCUE-Control_de_temperatura_Mega D4
U 1 1 59C65AF1
P 5050 6100
F 0 "D4" V 5150 6050 40  0000 C CNN
F 1 "1N4007" V 5050 5950 40  0000 C CNN
F 2 "w_pth_diodes:diode_do35" H 5050 6100 60  0001 C CNN
F 3 "" H 5050 6100 60  0000 C CNN
	1    5050 6100
	0    -1   -1   0   
$EndComp
$Comp
L HEADER_4 J9
U 1 1 59C6A16D
P 4550 6300
F 0 "J9" V 4550 6550 60  0000 C CNN
F 1 "Desconnexió Serial" V 4700 6300 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x04_Pitch2.54mm" H 4550 6300 60  0001 C CNN
F 3 "" H 4550 6300 60  0000 C CNN
	1    4550 6300
	0    -1   1    0   
$EndComp
Wire Wire Line
	5450 5800 5550 5800
Wire Wire Line
	4700 5900 5550 5900
Wire Wire Line
	4700 6200 4700 5900
Wire Wire Line
	4150 5900 4600 5900
Wire Wire Line
	4600 5900 4600 6200
Wire Wire Line
	4400 5800 4150 5800
NoConn ~ 4150 6000
Wire Wire Line
	4400 6200 4400 6100
Wire Wire Line
	4400 6100 4500 6000
Wire Wire Line
	4500 6000 4500 5800
Wire Wire Line
	4500 6200 4500 6100
Wire Wire Line
	4500 6100 4400 6000
Wire Wire Line
	4400 6000 4400 5800
$Comp
L GND #PWR?
U 1 1 59DDDB67
P 8750 4800
F 0 "#PWR?" H 8750 4800 30  0001 C CNN
F 1 "GND" H 8750 4730 30  0001 C CNN
F 2 "" H 8750 4800 60  0001 C CNN
F 3 "" H 8750 4800 60  0001 C CNN
	1    8750 4800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 59DDDBC0
P 8950 4100
F 0 "#PWR?" H 8950 4100 30  0001 C CNN
F 1 "GND" H 8950 4030 30  0001 C CNN
F 2 "" H 8950 4100 60  0001 C CNN
F 3 "" H 8950 4100 60  0001 C CNN
	1    8950 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 4100 8650 4050
Wire Wire Line
	8650 4050 8950 4050
Wire Wire Line
	8950 4050 8950 4100
Wire Wire Line
	8850 4100 8850 4050
Connection ~ 8850 4050
Wire Wire Line
	8750 4700 8750 4800
Wire Wire Line
	8400 4900 9050 4900
$EndSCHEMATC
