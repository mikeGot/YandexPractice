from itertools import combinations
number = int(input())
array = [int(i) for i in input().split()]
two_num_array = []
numeric = [a for a in range(0, number)]

for j in combinations(numeric, 3):
    new = list(j)
    two_num_array.append(array[new[0]] + array[new[1]] + array[new[2]])

print(min(two_num_array, key=lambda a: abs(a - number)))
