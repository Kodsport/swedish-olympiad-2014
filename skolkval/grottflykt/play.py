#!/usr/bin/python3

# Interactive script used to play a level
#
# Example usage:
# python play.py data/sample/sample01.in

import curses
import sys
from cave import Cave

global cave_instance

def main(screen):
    cave_instance.print_cave(screen)
    moves = {}
    moves[curses.KEY_UP] = Cave.UP
    moves[curses.KEY_RIGHT] = Cave.RIGHT
    moves[curses.KEY_DOWN] = Cave.DOWN
    moves[curses.KEY_LEFT] = Cave.LEFT
    while True:
        c = screen.getch()
        if c == 10 or cave_instance.is_won() or cave_instance.is_lost():
            break
        if c in moves:
            cave_instance.move(moves[c])
            screen.clear()
            cave_instance.print_cave(screen)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print "Usage: python play.py MAP_FILE"
        exit()
    f = open(sys.argv[1], mode='r')
    cave_instance = Cave.parse(f)
    f.close()
    curses.wrapper(main)
