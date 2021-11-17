import numpy as np
fib_nums = [1, 1]
for _ in range(100):
    fib_nums.append(bin(fib_nums[-1] + fib_nums[-2]))[1:])

for i in fib_nums:
    print(i)
