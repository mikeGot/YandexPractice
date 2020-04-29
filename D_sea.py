Q = str(input())
N = int(input())
field = []

shot_coord = []

len_ship = []

killed = 0
injured = 0

for c in range(0, N):
    array = [int(i) for i in input().split()]
    coord1 = [array[0], array[1]]
    coord2 = [array[2], array[3]]
    boat = []

    if abs(coord2[0] - coord1[0]) > 0:
        for i in range(coord1[0], coord2[0] + 1):
            boat.append([i, coord2[1]])
    elif abs(coord2[1] - coord1[1]) > 0:
        for i in range(coord1[1], coord2[1] + 1):
            boat.append([coord2[0], i])
    else:
        boat.append([coord1[0], coord1[1]])

    len_ship.append(len(boat))
    field.append(boat)

M_shot = int(input())
for i in range(0, M_shot):
    ar = [int(i) for i in input().split()]
    shot_coord.append(ar)


for temp in shot_coord:
    for sh in field:
        for q in sh:
            if temp == q:
                sh.remove(q)
            if len(sh) == 0:
                killed = killed + 1

for i in range(0, len(field)):
    if len_ship[i] != len(field[i]) and len(field[i]) != 0:
        injured = injured + 1


print(str(injured) + " " + str(killed))




