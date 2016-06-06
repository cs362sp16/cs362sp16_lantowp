#!/usr/bin/python
#
#Paul Lantow
#
#Colors from http://stackoverflow.com/questions/287871/print-in-terminal-with-colors-using-python
#File line count from http://stackoverflow.com/questions/845058/how-to-get-line-count-cheaply-in-python
#Calling make http://stackoverflow.com/questions/4256107/running-bash-commands-in-python

import string
import random
from random import choice
import sys
import subprocess
import os
import numpy as np

class colors:
    green = '\033[92m'
    yellow = '\033[93m'
    red = '\033[91m'
    close = '\033[0m'


def file_len(file_name):
    with open(file_name) as f:
        for i, l in enumerate(f):
            pass
    return i + 1

def failure_counter(failure_count, output_name):
    failure_flag = 0
    output_lines = []
    offset = 6

    with open(output_name) as f:
        output_lines = f.readlines()

    if output_lines[0] == "FAIL\n":
        failure_flag = 1

    for index in range(offset,len(output_lines)):
        if failure_flag == 1:
            if output_lines[index][8] != '#' and output_lines[index][8] != '-':
                if failure_count[index-offset] == 0 or failure_count[index-offset] == -1:
                    failure_count[index-offset] = 2
        else:
            if output_lines[index][8] != '#' and output_lines[index][8] != '-':
                if failure_count[index-offset] == 2:
                    failure_count[index-offset] = 1
                elif failure_count[index-offset] != 1:
                    failure_count[index-offset] = 0

    return failure_count


def print_tarantula(failure_count, dominion_code):
    file_write = open("tarantula.out", 'w')
    dominion_lines = []

    with open(dominion_code) as f:
        dominion_lines = f.readlines()

    for index in range(len(failure_count)):
        #Potential
        if failure_count[index] == 1:
            file_write.write(colors.yellow + dominion_lines[index] + colors.close + "\n")
        #Failure
        elif failure_count[index] == 2:
            file_write.write(colors.red + dominion_lines[index] + colors.close + "\n")
        #Pass
        elif failure_count[index] == 0:
            file_write.write(colors.green + dominion_lines[index] + colors.close + "\n")
        #Untouched
        else:
            file_write.write(dominion_lines[index] + "\n")


#main
dominion_code = "dominion.c"
testnames = ["unit_test1","unit_test2","unit_test3","unit_test4","card_test1",
        "card_test2","card_test3","card_test4"]
failure_count = []
offset = 6

#generate outputs
os.system("make tarantulaTest")

#Fill the initial failure_count
for index in range(file_len(testnames[0]+".out")-offset):
    failure_count.append(-1)

#Count the inputs
for test in range(len(testnames)):
    failure_count = failure_counter(failure_count, testnames[test]+".out")

#Add color
print_tarantula(failure_count, dominion_code)

#Display
print "TARANTULA:"
os.system("cat tarantula.out")
