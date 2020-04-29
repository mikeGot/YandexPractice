count = int(input())
array = [int(i) for i in input().split()]

infinity = float("inf")
array.sort()
array.append(infinity)
array.append(infinity)

ar = []

for a in range(1, count + 1):
    if array[a - 1] != a:
        array.insert(a - 1, a)
        ar.append(a)

print(" ".join(map(str, ar)))
