import numpy as np
import cv2
import time
from matplotlib import pyplot as plt
import sys

def print_frame(frame, aspect_ratio):
	for i in range(aspect_ratio[1]):
		for j in range(aspect_ratio[0]):
			pixel = frame[i][j]
			if (pixel < 50):
				sys.stdout.write("  ")
			elif (pixel < 100):
				sys.stdout.write("--")
			elif (pixel < 160):
				sys.stdout.write("==")
			else:
				sys.stdout.write("##")
		sys.stdout.write("\n")



cap = cv2.VideoCapture("IMG_0428.MOV")
aspect_ratio = (27, 48)
while(cap.isOpened()):
	ret, frame = cap.read()
	if ret==False:
                break
	frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
	frame = cv2.resize(frame, aspect_ratio)
	# ret, frame = cv2.threshold(frame, 127, 255, cv2.THRESH_BINARY)
	print_frame(frame, aspect_ratio)
	# plt.subplot(2, 3, 1), plt.imshow(thresh, 'gray')
	# plt.show();
	time.sleep(0.04)
cap.release()
