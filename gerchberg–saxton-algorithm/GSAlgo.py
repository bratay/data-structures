# import sys
# fileName = str(sys.argv)[1]

data = open("test-inputs/input_size_3.txt","r")
data.close()

numOfCouples = 0

s = [] #matrix with married couples

mp = [] # men pref matrix
wp = [] #women pref matrix
wr = [] # women rank matrix

singleMen = [] #get men pref matrix
numProposed = [] #how many times have they proposed

while( len(singleMen) != 0 and numProposed[singleMen[0]] <  numOfCouples):
    man = singleMen.pop(0)
    
    # highest ranked woman in the man preference that he hasnt proposed to
    w = mp[man][ numProposed[man] ]
    numProposed[man] += numProposed[man] + 1
    
    if( s[w][0] == -1):
        # getEngaged(man, w)
        s[w] = [man, w]
    else: # w is engaged to m-
        m- = s[w][0] #get current husband
        
        if( wr[ m- ] > wr[ man ] ): # w prefers m- over man
            # man stays free
            singleMen.append(man)
        else: # w prefers man to m-
            # getEngaged(man, w)
            s[w] = [man, w]
            # unengaged( m- )
            s[m-] = [-1, -1]
            
return s