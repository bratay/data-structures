# import numpy as np
import sys

graph = {}
graphInverse = {}
n = 0

result = []
vis = {}
stack = []


def printResult():
    return


def inverseDfs(start):
    return


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

    for x in range(1, n + 1):
        vis[x] = False

    first = stack[len(stack) - 1]
    stack.pop(len(stack) - 1)
    inverseDfs(first)

    printResult()


def initialize():
    # fileName = str(sys.argv[1])
    fileName = "test-inputs/input_size_3.txt"

    data = open(fileName, "r")

    n = int(data.readline())

    temp = []
    for x in data:
        temp.append(x.rstrip())

    del temp[0]

    curRow = []
    for x in range(0, n):
        for i in range(0, len(temp[x])):
            num = temp[x][i]

            if(num != " "):
                curRow.append(int(num))

        graph[x+1] = curRow
        curRow = []

    data.close()
    findStrongComponents(n)


initialize()
