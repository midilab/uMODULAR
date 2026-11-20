EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 8 8
Title "MIDI-IO-5v"
Date ""
Rev "01"
Comp "midilab"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Isolator:6N138 U?
U 1 1 63E8955E
P 5600 4350
F 0 "U?" H 5600 4817 50  0000 C CNN
F 1 "6N138" H 5600 4726 50  0000 C CNN
F 2 "" H 5890 4050 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/HCPL2731-D.pdf" H 5890 4050 50  0001 C CNN
	1    5600 4350
	1    0    0    -1  
$EndComp
$Comp
L Connector:DIN-5_180degree J?
U 1 1 63E8E3AF
P 5600 2700
F 0 "J?" H 5600 2425 50  0000 C CNN
F 1 "MIDI_OUT" H 5600 2334 50  0000 C CNN
F 2 "" H 5600 2700 50  0001 C CNN
F 3 "http://www.mouser.com/ds/2/18/40_c091_abd_e-75918.pdf" H 5600 2700 50  0001 C CNN
	1    5600 2700
	1    0    0    -1  
$EndComp
Text HLabel 5600 2050 1    50   Input ~ 0
GND
Text HLabel 5100 2050 1    50   Input ~ 0
VCC
Text HLabel 6150 2050 1    50   Input ~ 0
UART_TX
$Comp
L Device:R_US R?
U 1 1 63E95881
P 6150 2300
AR Path="/63DA3C68/63E95881" Ref="R?"  Part="1" 
AR Path="/63E892DF/63E95881" Ref="R?"  Part="1" 
F 0 "R?" V 5945 2300 50  0000 C CNN
F 1 "220R" V 6036 2300 50  0000 C CNN
F 2 "" V 6190 2290 50  0001 C CNN
F 3 "~" H 6150 2300 50  0001 C CNN
	1    6150 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R?
U 1 1 63E95A03
P 5100 2300
AR Path="/63DA3C68/63E95A03" Ref="R?"  Part="1" 
AR Path="/63E892DF/63E95A03" Ref="R?"  Part="1" 
F 0 "R?" V 4895 2300 50  0000 C CNN
F 1 "220R" V 4986 2300 50  0000 C CNN
F 2 "" V 5140 2290 50  0001 C CNN
F 3 "~" H 5100 2300 50  0001 C CNN
	1    5100 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 2050 6150 2150
Wire Wire Line
	5100 2050 5100 2150
Wire Wire Line
	5300 2600 5100 2600
Wire Wire Line
	5100 2600 5100 2450
Wire Wire Line
	5900 2600 6150 2600
Wire Wire Line
	6150 2600 6150 2450
Wire Wire Line
	5600 2050 5600 2400
Text HLabel 6300 4150 2    50   Input ~ 0
VCC
Text HLabel 6300 4550 2    50   Input ~ 0
GND
Text HLabel 6300 4250 2    50   Input ~ 0
GND
$Comp
L Device:R_US R?
U 1 1 63EA7797
P 6100 4250
AR Path="/63DA3C68/63EA7797" Ref="R?"  Part="1" 
AR Path="/63E892DF/63EA7797" Ref="R?"  Part="1" 
F 0 "R?" V 6050 4100 50  0000 C CNN
F 1 "4.7k" V 6200 4250 50  0000 C CNN
F 2 "" V 6140 4240 50  0001 C CNN
F 3 "~" H 6100 4250 50  0001 C CNN
	1    6100 4250
	0    1    1    0   
$EndComp
Wire Wire Line
	5900 4150 6300 4150
Wire Wire Line
	6300 4250 6250 4250
Wire Wire Line
	5950 4250 5900 4250
Wire Wire Line
	5900 4550 6300 4550
Text HLabel 6700 4050 1    50   Input ~ 0
VCC
Text HLabel 6900 4450 2    50   Input ~ 0
UART_RX
Wire Wire Line
	5900 4450 6700 4450
$Comp
L Device:R_US R?
U 1 1 63EB2898
P 6700 4250
AR Path="/63DA3C68/63EB2898" Ref="R?"  Part="1" 
AR Path="/63E892DF/63EB2898" Ref="R?"  Part="1" 
F 0 "R?" H 6600 4200 50  0000 C CNN
F 1 "1k" H 6600 4300 50  0000 C CNN
F 2 "" V 6740 4240 50  0001 C CNN
F 3 "~" H 6700 4250 50  0001 C CNN
	1    6700 4250
	-1   0    0    1   
$EndComp
Wire Wire Line
	6700 4050 6700 4100
Wire Wire Line
	6700 4400 6700 4450
Connection ~ 6700 4450
Wire Wire Line
	6700 4450 6900 4450
Wire Wire Line
	5300 4450 5200 4450
Wire Wire Line
	5200 4450 5200 4600
Wire Wire Line
	5200 4750 6100 4750
$Comp
L Diode:1N4148 D?
U 1 1 63EB9124
P 5000 4600
F 0 "D?" H 5000 4817 50  0000 C CNN
F 1 "1N4148" H 5000 4726 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 5000 4425 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/1N4148_1N4448.pdf" H 5000 4600 50  0001 C CNN
	1    5000 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 4600 5200 4600
Connection ~ 5200 4600
Wire Wire Line
	5200 4600 5200 4750
Wire Wire Line
	5300 4250 4800 4250
Wire Wire Line
	4800 4250 4800 4600
Wire Wire Line
	4850 4600 4800 4600
Connection ~ 4800 4600
$Comp
L Device:R_US R?
U 1 1 63EC7E9B
P 4800 5000
AR Path="/63DA3C68/63EC7E9B" Ref="R?"  Part="1" 
AR Path="/63E892DF/63EC7E9B" Ref="R?"  Part="1" 
F 0 "R?" V 4595 5000 50  0000 C CNN
F 1 "220R" V 4686 5000 50  0000 C CNN
F 2 "" V 4840 4990 50  0001 C CNN
F 3 "~" H 4800 5000 50  0001 C CNN
	1    4800 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 4600 4800 4850
$Comp
L Connector:DIN-5_180degree J?
U 1 1 63E8EFB3
P 5600 5450
F 0 "J?" H 5600 5175 50  0000 C CNN
F 1 "MIDI_IN" H 5600 5084 50  0000 C CNN
F 2 "" H 5600 5450 50  0001 C CNN
F 3 "http://www.mouser.com/ds/2/18/40_c091_abd_e-75918.pdf" H 5600 5450 50  0001 C CNN
	1    5600 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 5350 4800 5350
Wire Wire Line
	4800 5350 4800 5150
Wire Wire Line
	6100 4750 6100 5350
Wire Wire Line
	6100 5350 5900 5350
$EndSCHEMATC
