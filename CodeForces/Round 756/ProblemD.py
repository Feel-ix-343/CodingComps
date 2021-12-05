from collections import deque
from collections import OrderedDict

for _ in range(int(input())):
    n = int(input())
    b = list(map(int, input().split()))
    p = list(map(int, input().split()))

    ordered_b = OrderedDict.fromkeys(b).keys()

    distance = {value: index for index, value in enumerate(p)}
    weights = deque()

    for value, parent in list(enumerate(b))[::-1]:
        value += 1
        if distance[value] < distance[parent]:
            weights = [-1]
            break
        else:
            weights.appendleft(distance[value] - distance[parent])
    print(' '.join(map(str, weights)))
