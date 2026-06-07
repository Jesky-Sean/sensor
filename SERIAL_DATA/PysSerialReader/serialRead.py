#code from github-lightly modifica 

import serial

#Windows
#PORT COM16
#LINUX
PORT = "/dev/ttyUSB0"

serialR = serial.Serial(PORT, 921600)

with open("serialData.txt", "ab", buffering=((1024*2)*2)) as files:
	while True:
		files.write(serialR.readline())
