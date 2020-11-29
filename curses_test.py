import curses
from curses import wrapper
import time

def main(stdscr):
	stdscr.clear()
	for i in range(0, 11):
		v = i-10
		string = "Index: " + chr(i)
		stdscr.addstr(0, 0, "string")
		time.sleep(1)
		stdscr.refresh()
wrapper(main)
