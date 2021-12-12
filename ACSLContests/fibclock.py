from datetime import time

def findTime(*spaces):
    hours, minutes = 0, 0
    spaces = [([1, 1, 2, 3, 5][index], color) for index, color in enumerate(spaces)]
    for fibVal, color in spaces:
        if color == "R":
            hours += fibVal
        elif color == "G":
            minutes += fibVal
        elif color == "B":
            hours += fibVal
            minutes += fibVal
    minutes *= 5
    if minutes == 60:
        minutes = 0
        hours += 1
    if hours >= 12:
        hours -= 12
    return time(hour=hours, minute=minutes).strftime("%H:%M")

print(findTime("R", "W", "G", "B", "G"))

    