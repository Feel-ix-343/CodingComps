n_of_inputs = int(input())
teams = [map(int, input().split()) for _ in range(n_of_inputs)]

for team in teams:
    team = sorted(team, reverse=True)
    if team[1] * 3 <= team[0]:
        print(team[1])
    elif team[0] - team[1] < 2:
        print(team[1] // 2)
    else:
        x = (team[1] - team[0]) // -2
        team[0] -= x * 3
        team[1] -= x

        print(x + team[1] // 2)

