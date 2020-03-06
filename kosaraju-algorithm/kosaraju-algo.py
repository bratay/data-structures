# import numpy as np
import sys

graph = {} 

def dfs():
    result = []

    return result


def findStrongComponents():
    result = []

    return result


def initialize():
    # fileName = str(sys.argv[1])
    fileName = "test-inputs/input_size_3.txt"

    data = open(fileName, "r")

    n = int(data.readline())

    temp = []
    for x in data:
        temp.append(x.rstrip())

    del temp[0]
    # del temp[n]
    print(str(n))
    print(temp)
    
    curRow = []
    for x in range(0, n):
        for i in range(0 , len(temp[x]) ):
            num = temp[x][i]

            if( num != " " ):
                curRow.append( int(num) )
                
        graph[ x+1 ] = curRow
        curRow = []

    data.close()
    findStrongComponents()
    
    
    
    
initialize()
