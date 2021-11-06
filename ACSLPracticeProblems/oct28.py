from functools import reduce
num = input("Enter a num: ")
length = lambda x: print(len(x))
first_last_sum = lambda x: print(int(str(x)[0]) + int(str(x)[-1]))
swap_first_last = lambda x: print(int(str(x)[-1] + str(x)[1:-1] + str(x)[0]))
calculate_sum_of_digits = lambda x: print(sum([int(i) for i in x]))
product_of_digits = lambda x: print(reduce(lambda a, b: int(a) * int(b), x))
reverse_order = lambda x: print(int(''.join([x[-i] for i in range(1, len(x) + 1)])))
is_palendrome = lambda x: print(int(''.join([x[-i] for i in range(1, len(x) + 1)])) == int(x))
frequency_of_digits = lambda x: print(' times, '.join(sorted([': '.join([i, str(x.count(i))]) for i in list(set(x))])) + " times")

for i in dict(locals()): locals()[i](num) if type(locals()[i]).__name__ == "function" else None


