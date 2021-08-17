import csv
import sys


def main():
    
    
    teams = {}
    names = []
    # TODO: Read teams into memory from file
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        next(reader)
        for row in reader:
            a = row['team']
            print(a)
            # teams[row['team'] = teams['rating']

            
            names.append(teams)
            
    
    for i in range(0, len(names),2):
        
        print(names[i])

main()