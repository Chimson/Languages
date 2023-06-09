# lab1.py
  
def numsIncreasing():
    nums = []
    while True:

        ans = input("Please enter a number: ")
        if ans == "":
            break
        else:
            nums.append( eval(ans) )
    # note that numsSorted = nums.sort() does NOT work
    # because sort does not return. If sort is used, then a
    # COPY must be made first, by using list() or equivalent
    # numsSorted = list(nums)
    # numsSorted.sort()
    numsSorted = sorted(nums)
    if len(nums)== 0:
        print("No numbers were entered.")
    elif nums == numsSorted:
        print("Numbers were entered in increasing order.")
    else:
        print("Numbers were not entered in increasing order.")

def avgWordLength(filename):

    # students may not use with, that is ok
    with open(filename) as file:

        contents = file.read()
        words = len(contents.split())
        # could also remove whitespace and then take len
        chars = len(contents) - contents.count(' ') - contents.count('\n')

    return chars/words
        
def wordCounts(wordList):

    counts = {}

    for word in wordList:
        first = word[0].upper()
        if first not in counts:
            counts[ first ] = 1
        else:
            counts[ first ] +=1
    return counts
            


if __name__=='__main__':
    import doctest
    print( doctest.testfile( 'lab1TEST.py' ))
    


    
