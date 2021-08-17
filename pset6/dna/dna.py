import sys
import csv
import re

def main():
    if len(sys.argv) != 3:
        sys.exit ("Error: Please insert the name of database.csv and str.txt to be read: ")

    names = []
    dna = []
    results = []
    with open(sys.argv[1]) as database:
        reader = csv.DictReader(database)
        for row in reader:
            names.append(row)

    with open(sys.argv[2], 'r') as strs:
        read = strs.readline().strip()
        # for i in strs:
        #     read = i


    for i in range(1,len(names[0])):
        key = list(names[0].keys())[i]
        dna.append(key)
    
    # match = re.search('AGATC', read)
    # if match:
    #     process(match)
    for i in range(len(dna)):
        lenght = len(dna[i])
        result = check(dna[i],read,lenght)
        results.append(result)
    
    
    final = "No Match." 
    for row in names:
        
        x = 0
        for i in range(len(dna)):
        # if results[0] == int(row[dna[0]]) and results[1] == int(row[dna[1]]) and results[2] == int(row[dna[2]]):
        #     final = row['name']   
            if results[i] == int(row[dna[i]]):
                x += 1
            

        if x == len(dna):
            final = row['name'] 
    print (final)
        
        
        
        

def check (dna,read,lenght):
    x = 0
    
    startpos = 0
    while True:
        
        pattern = re.compile(dna)
        index = pattern.search(read,startpos)
        if index != None:
            y = 0
            startpos = (index.span()[0])
            endpos = (index.span()[1])
            while dna in read[startpos:endpos]:
                
                y += 1
                startpos +=lenght
                endpos +=lenght
            if x < y:
                x = y
        if index == None:
            break
      
      
      
        
    # while endpos > 2 and endpos < len(read)-5:
    #     x += 1
    #     for row in range(startpos, len(read),lenght):
    #         ans1 = re.match(read,startpos,endpos)
	   #     if ans:
	   #         x += 1
            
            
    return x
    




main()