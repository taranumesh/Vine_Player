import numpy as np
import cv2
import time
import sys
import curses
from curses import wrapper

def print_frame(stdscr, frame, aspect_ratio):
	for i in range(aspect_ratio[1]):
		for j in range(aspect_ratio[0]):
			pixel = frame[i][j]
			max_y, max_x = stdscr.getmaxyx()
			if ((i < max_y) and (j*2 < max_x)):
				if (pixel < 50):
					stdscr.addstr(i, j*2, "  ")
				elif (pixel < 100):
					stdscr.addstr(i, j*2, "--")
				elif (pixel < 160):
					stdscr.addstr(i, j*2, "==")
				else:
					stdscr.addstr(i, j*2, "##")

def main(stdscr):
	cap = cv2.VideoCapture("IMG_0428.MOV")
	aspect_ratio = (27, 48)
	stdscr.clear()
	while(cap.isOpened()):
		ret, frame = cap.read()
		if ret==False:
	                break
		frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
		frame = cv2.resize(frame, aspect_ratio)
		# ret, frame = cv2.threshold(frame, 127, 255, cv2.THRESH_BINARY)
		print_frame(stdscr, frame, aspect_ratio)
		stdscr.refresh()
		time.sleep(0.04)
	cap.release()
wrapper(main)
