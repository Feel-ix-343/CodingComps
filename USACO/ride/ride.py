"""
ID: felixaz1
LANG: PYTHON3
TASK: ride
"""
from functools import reduce
fin = open("ride.in", "r")
fout = open("ride.out", "w")
m1, m2 = [reduce(lambda x, y: x * y, map(lambda x: ord(x) - 64, x.replace('\n', ''))) % 47 for x in fin.readlines()]
fout.write('GO\n') if m1 == m2 else fout.write('STAY\n')
fout.close()
