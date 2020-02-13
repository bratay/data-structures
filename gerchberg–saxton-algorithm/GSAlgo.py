import numpy as np
import sys
fileName = "test-inputs/input_size_3.txt"  # str(sys.argv)[1]

# data = open("test-inputs/input_size_3.txt","r")
data = open(fileName, "r")

n = int(data.readline())

temp = []
for x in data:
    temp.append(x.rstrip())

del temp[0]
del temp[n]

s = []  # matrix with married couples
mp = []  # men pref matrix
wp = []  # women pref matrix
wr = []  # women rank matrix

singleMen = []  # get men pref matrix
numProposed = []  # how many times have they proposed

for i in range(0, n):
    row = temp[i]
    s.append( [ -1, -1] )
    singleMen.append(i)
    numProposed.append(0)
    mp.append(row.split(','))
    
for i in range(n, n+n):
    row = temp[i]
    wp.append(row.split(','))


data.close()

while( len(singleMen) != 0 and numProposed[singleMen[0]] <  n):
    man = singleMen.pop(0)

    # highest ranked woman in the man preference that he hasnt proposed to
    w = mp[man][ numProposed[man] ]
    numProposed[man] += numProposed[man] + 1

    if( s[w][0] == -1):
        # getEngaged(man, w)
        s[w] = [man, w]
    else: # w is engaged to curMan
        curMan = s[w][0] #get current husband

        if( wr[w][ curMan ] > wr[w][ man ] ): # w prefers curMan over man
            # man stays free
            singleMen.append(man)
        else: # w prefers man to curMan
            # getEngaged(man, w)
            s[w] = [man, w]
            # unengaged( curMan )
            s[curMan] = [-1, -1]

print(s)
