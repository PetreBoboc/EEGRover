from NeuroPy import NeuroPy
from time import sleep
import serial
import os

neuropy = NeuroPy("COM4", 57600) 
arduino = serial.Serial("COM6", 9600)

neuropy.start()

while True:
    print "Attention: ", neuropy.attention
    #print "Meditation: ", neuropy.meditation
    print "rawValue: ", neuropy.rawValue
    #print "delta: ", neuropy.delta
    #print "theta: ", neuropy.theta
    #print "lowAlpha: ", neuropy.lowAlpha
    #print "highAlpha: ", neuropy.highAlpha
    #print "lowBeta: ", neuropy.lowBeta
    #print "highBeta: ", neuropy.highBeta
    #print "lowGamma: ", neuropy.lowGamma
    #print "midGamma: ", neuropy.midGamma
    #print "poorSignal: ", neuropy.poorSignal
    #print "blinkStrenght: ", neuropy.blinkStrength
    if neuropy.attention > 50:
        arduino.write(b'1\r\n')
    else:
        arduino.write(b'0\r\n')
    