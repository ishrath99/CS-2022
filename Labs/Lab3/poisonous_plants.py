#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'poisonousPlants' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY p as parameter.
#

def poisonousPlants(p):
    #initialize stack & days
    stack = [] #2d list: 1st element = pesticide level, 2nd = days to die
    days = 0
    
    #iterate through the plant list
    #calculate after how many days each plant dies
    #and update days
    for plant in p:
        days_to_die = 0
        
        #if the plant has lower pesticide level
        #than to it's previous ones pop the prev ones from stack 
        #day to die = maximum of the prevous plants' life
        while stack and stack[-1][0] >= plant:
            days_to_die = max(days_to_die, stack.pop()[1])
            
        #if stack is empty: days to die = 0
        #else: days ++
        if stack:
            days_to_die += 1
        else:
            days_to_die = 0
            
        days = max(days, days_to_die)
        stack.append([plant, days_to_die])
        
        # print(stack)
        
    return days
    
    
    
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    p = list(map(int, input().rstrip().split()))

    result = poisonousPlants(p)

    fptr.write(str(result) + '\n')

    fptr.close()
