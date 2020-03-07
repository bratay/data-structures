import sys

graph = {}
graphInverse = {}
n = 0

result = []
vis = {}
stack = []
curGroup = []

def inverseDfs(start):
    if(vis[start] == True):
        return 
    
    vis[start] = True
    
    curGroup.append( int(start) )
    
    for child in range(0, len(graphInverse[start])):
        inverseDfs(graphInverse[start][child])

def dfs(start):
    if(vis[start] == True):
        return 
    vis[start] = True

    for child in range(0, len(graph[start])):
        dfs( graph[start][child] )

    stack.append(start)


def findStrongComponents(length):
    for x in range(1, length + 1):
        vis[x] = False

    dfs(1)

    for x in range(1, length + 1):
        vis[x] = False

    while( len(stack) != 0 ):
        first = stack[len(stack) - 1]
        stack.pop(len(stack) - 1)
        
        if(vis[first] == False):
            inverseDfs(first)
            curGroup.sort()
            
            for cur in curGroup:
                print(str(cur) + " ", end = '')
            print("")
        curGroup.clear()


def initialize():
    fileName = str(sys.argv[1])

    data = open(fileName, "r")

    n = int(data.readline())

    temp = []
    for x in data:
        temp.append(x.rstrip())

    del temp[0]
    for x in range(1, n + 1):
        graph[x] = []
        graphInverse[x] = []

    length = len(temp)
    for x in range( 0 , n - length ):
        temp.append("")
        
    curRow = []
    for x in range(0, n):
        for i in range(0, len(temp[x])):
            num = temp[x][i]

            if(num != " "):
                curRow.append(int(num))
                graphInverse[int(num)].append( x+1 )

        graph[x+1] = curRow
        curRow = []

    data.close()
    findStrongComponents(n)


initialize()
