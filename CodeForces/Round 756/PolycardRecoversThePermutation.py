from collections import deque
n_of_test = int(input())
tests = [[input(), list(map(int, input().split()))][-1] for _ in range(n_of_test)]

for p in tests:
    if max(p) != p[0] and max(p) != p[-1]:
        print(-1)
    else:
        a, p = deque(), deque(p)
        for i in range(len(p)):
            if p[0] > p[-1]:
                a.appendleft(p.popleft())
            else:
                a.append(p.pop())
        print(' '.join(map(str, a)))
