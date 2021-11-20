"""
ID: felixaz1
LANG: PYTHON3
TASK: test
"""
fin = open("friday.in", "r")
fout = open("friday.out", "w")

days = [0 for _ in range(7)]
day_counter, year, day, month = 0, 1900, 1, 1

for y in range(int(fin.readline().strip())):
    for month in range(1, 13):
        if month in [4, 6, 9, 11]:
            days = 30
        elif month == 2 and month
        for day in range(days):



