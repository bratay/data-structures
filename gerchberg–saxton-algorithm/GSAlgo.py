import numpy as np
import sys

fileName =  str(sys.argv[1]) 

data = open(fileName, "r")

n = int(data.readline())

temp = []
for x in data:
    temp.append(x.rstrip())

del temp[0]
del temp[n]

result = []
s = []  # matrix with married couples # 0 base
mp = []  # men pref matrix # 0 based but w is 1 based
wp = []  # women pref matrix # 0 based but m is 1 based
wr = []  # women rank matrix # 0 based but m is 1 based

singleMen = []  # get men pref matrix
numProposed = []  # how many times have they proposed

for i in range(0, n):
    row = temp[i]
    result.append(i)
    s.append(-1)
    singleMen.append(i)
    numProposed.append(0)
    mp.append(row.split(','))
    wr.append(row.split(','))

for i in range(n, n+n):
    row = temp[i]
    wp.append(row.split(','))

for i in range(n):
    for j in range(n):
        theMan = wp[i][j]
        wr[i][int(theMan) - 1] = j

data.close()

while(len(singleMen) != 0 and numProposed[singleMen[0]] < n):
    man = singleMen.pop(0)  # 0 base

    # highest ranked woman in the man preference that he hasnt proposed to
    w = int(mp[man][numProposed[man]]) - 1
    numProposed[man] = numProposed[man] + 1

    if(s[w] == -1):
        # getEngaged(man, w)
        s[w] = man
    else:  # w is engaged to curMan
        curMan = s[w]  # get current husband

        if(wr[w][curMan] < wr[w][man]):  # w prefers curMan over man
            # man stays free
            singleMen.append(man)
        else:  # w prefers man to curMan
            # getEngaged(man, w)
            s[w] = man
            # unengaged( curMan )
            singleMen.append(curMan)
            
#reformat and print results
for i in range(n):
    result[ s[i] ] = i+1

for i in range(n):
    print(str( i + 1) + ", " + str(result[i]))
