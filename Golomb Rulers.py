# https://open.kattis.com/problems/golombrulers
import sys

for line in sys.stdin:
    marks = list(map(int, line.split()))
    dist = [0] * (max(marks) + 1)
    ruler = True
    for a in marks:
        for b in marks:
            if a < b:
                dist[b-a] += 1
            if dist[b-a] > 1:
                ruler = False

    if ruler is False:
        print('not a ruler')
    else:
        count = []
        for a in range(1, max(marks)):
            if dist[a] != 1:
                count.append(a)

        if count:
            print("missing " + " ".join(map(str, count)))
        else:
            print("perfect")
