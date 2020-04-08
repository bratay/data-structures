import sys


# temp = []
# n = 0

# for x in data:
#     temp.append(x.rstrip())
#     n += 1

# input = [[None]] * n
# print(input)
# print(temp)

# for i in range(0, n):
#     for j in range(0, n * 2 - 1):
#         if(temp[i][j] != " "):
#             input[i].append( temp[i][j] )
            
            
            
            
            
# fileName = str(sys.argv[1])
fileName = 'Input_Output_Files/sm_input_10.txt'
data = open(fileName, "r")

n = 0

temp = []
for x in data:
    temp.append(x.rstrip())
    n += 1

input = []

length = len(temp)
for x in range( 0 , n - length ):
    temp.append("")
   
num = "" 
curRow = []
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
    

data.close()    
        
sortedWeight = [[None]] * n


# for i in range(0, n):
#     for j in range( i + 1, n):
#         if(input[i][j] != 0):
#             sortedWeight[ input[i][j] ].append( [i,j] )


