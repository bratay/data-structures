import sys

def merge(verOne, verTwo):
    posOne = -1
    posTwo = -1
    
    for x in range( 0, len(verGroups) ) :
        for y in range( 0, len(verGroups[x]) ):
            if(verGroups[x][y] == verOne):
                posOne = x
            elif(verGroups[x][y] == verTwo):
                posTwo = x
                
    verGroups[posOne] = verGroups[posOne] + verGroups[posTwo]
    verGroups.pop(posTwo)
    return

def sameGroup(verOne, verTwo):
    posOne = -1
    posTwo = -1
    
    for x in range( 0, len(verGroups) ) :
        for y in range( 0, len(verGroups[x]) ):
            if(verGroups[x][y] == verOne):
                posOne = x
            elif(verGroups[x][y] == verTwo):
                posTwo = x
                
                
    return posOne == posTwo
             
fileName = str(sys.argv[1])
data = open(fileName, "r")

n = 0
temp = []

for x in data:
    temp.append(x.rstrip())
    n += 1

data.close()

length = len(temp)

for x in range( 0 , n - length ):
    temp.append("")
   
num = "" 
curRow = []
input = []

for x in range(0, n):
    for i in range(0, len(temp[x])):
        if(temp[x][i] == " "):
            continue
        
        num += temp[x][i]
        if( i + 1 != len(temp[x]) and temp[x][i+1] != " "):
            continue

        curRow.append(int(num))
        num = ""
    input.append(curRow)   
    curRow = [] 
    

sortedWeight = []
verGroups = []# the grouped vertexs

for x in range(0, n + 1):
    sortedWeight.append([])
    verGroups.append( [x] )

verGroups.pop( len(verGroups) - 1 )

for i in range(0, n):
    for j in range( i + 1, n):
        if(input[i][j] != 0):
            sortedWeight[ input[i][j] ].append( [i,j] )
            
sortedWeight.pop(0)
result = []

while( len(sortedWeight) != 0 and len(verGroups) != 1):
    lowestWeight = sortedWeight[0]
    sortedWeight.pop(0)
    
    if(lowestWeight == []):
        continue
    
    while( len(lowestWeight) != 0 and len(verGroups) != 1 ):
        curEdge = lowestWeight[0]
        lowestWeight.pop(0)
        
        if( sameGroup(curEdge[0], curEdge[1]) == False ):
            merge(curEdge[0], curEdge[1])
            result.append(curEdge)
            

for cur in result:
    print(str(cur[0]) + " " + str(cur[1]) ) 
     