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

def failure_counter(failure_count, output_name, pass_count, total_fails):
    failure_flag = 0
    output_lines = []
    offset = 6

    with open(output_name) as f:
        output_lines = f.readlines()

    if output_lines[0] == "FAIL\n":
        failure_flag = 1
        total_fails += 1

    for index in range(offset,len(output_lines)):
        if failure_flag == 1:
            if output_lines[index][8] != '#' and output_lines[index][8] != '-':
                #Remove untouched flag
                if failure_count[index-offset] == -1:
                    failure_count[index-offset] = 1
                else:
                    failure_count[index-offset] += 1
        else:
            if output_lines[index][8] != '#' and output_lines[index][8] != '-':
                #Remove flag
                if pass_count[index-offset] == -1:
                    pass_count[index-offset] = 1
                else:
                    pass_count[index-offset] += 1

    return failure_count, pass_count, total_fails


def print_tarantula(failure_count, dominion_code, pass_count, total_fails, total_pass):
    file_write = open("tarantula.out", 'w')
    dominion_lines = []
    supicious = 0.1

    with open(dominion_code) as f:
        dominion_lines = f.readlines()

    for index in range(len(failure_count)):
        #Untouched
        if failure_count[index] == -1 and pass_count[index] == -1:
            file_write.write(dominion_lines[index] + "\n")
        #Only passes
        elif failure_count[index] == -1:
            file_write.write(colors.green + dominion_lines[index] + colors.close + "\n")
        else:
            supicious = (failure_count[index] / (total_fails+0.0)) / (pass_count[index] / (total_pass+0.0) + failure_count[index] / (total_fails+0.0))
            #Wary
            if supicious < 0.5:
                file_write.write(colors.yellow + dominion_lines[index] + colors.close + "\n")
            #Dangerous
            else:
                file_write.write(colors.red + dominion_lines[index] + colors.close + "\n")



#main
dominion_code = "dominion.c"
testnames = ["unit_test1","unit_test2","unit_test3","unit_test4","card_test1",
        "card_test2","card_test3","card_test4"]
failure_count = []
pass_count = []
offset = 6
total_fails = 0

#generate outputs
os.system("make tarantulaTest")

#Fill the initial failure_count
for index in range(file_len(testnames[0] + ".out") - offset):
    failure_count.append(-1)

#Fill the initial pass_count
for index in range(file_len(testnames[0] + ".out") - offset):
    pass_count.append(-1)

#Count the inputs
for test in range(len(testnames)):
    failure_count, pass_count, total_fails = failure_counter(failure_count, testnames[test]+".out", pass_count, total_fails)

#Add color
print_tarantula(failure_count, dominion_code, pass_count, total_fails, len(testnames) - total_fails)

#Display
print "TARANTULA:"
os.system("cat tarantula.out")
