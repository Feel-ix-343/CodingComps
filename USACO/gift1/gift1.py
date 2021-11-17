"""
ID: felixaz1
LANG: PYTHON3
TASK: gift1
"""
fin = open("gift1.in", 'r')
fout = open('gift1.out', 'w')

n_of_names = int(fin.readline().rstrip())
people = {fin.readline().rstrip(): 0 for _ in range(n_of_names)}
for _ in range(n_of_names):
    person = fin.readline().rstrip()
    money, n_of_people = map(int, fin.readline().rstrip().split())
    for _ in range(n_of_people):
        people[fin.readline().rstrip()] += money // n_of_people
    people[person] -= money - (money % n_of_people) if n_of_people != 0 else 0

for name, money in people.items():
    fout.write(name + " " + str(money) + '\n')
