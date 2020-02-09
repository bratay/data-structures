
s = set of all engaged pairs

while( (a man is free) and (has not proposed to every woman) ):
    man = choose a man
    
    w = highest ranked woman in the man preference that he hasnt proposed to
    
    if( w is free ):
        getEngaged(man, w)
    else: # w is engaged to m-
        if( w prefers m- over man):
            man stays free
        else: # w prefers man to m-
            getEngaged(man, w)
            unengaged( m- )
            
return s