for _ in range(int(input())):
    n, l, r, k = map(int, input().split())
    bar_prices = sorted([int(i) for i in input().split() if l <= int(i) <= r])
    if bar_prices:
        for index, price in enumerate(bar_prices):
            k -= price
            if k < 0:
                print(index)
                break
            if index == len(bar_prices) - 1:
                print(index + 1)
    else:
        print(0)
