#!/bin/python3

import pyautogui as auto
import time
import os
import threading
import readline

def check() -> bool:
    for i in range(readline.get_current_history_length()):
        print (readline.get_history_item(i + 1))
    return True

def run_tests() -> list[bool]:
    array = []
    time.sleep(1)
    with open('tests/macro.txt') as f:
        lines = f.readlines()
        for line in lines:
            line = line.replace('\n', '')
            if line.startswith("> "):
                array.append(check())
                continue
            auto.press(line)
    return array

if __name__ == "__main__":
    table = threading.Thread(target=run_tests).start()
    os.system("./my_sokoban tests/map.txt")
    print(table)