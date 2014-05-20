touch -A -000001 -a bomb.txt
stat -s bomb.txt | cut -c112- | rev | cut -c104- | rev
