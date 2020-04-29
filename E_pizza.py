from functools import reduce
from itertools import combinations


def count_cover(pizza_x, pizza_y, Rad, N):
    cover_liner = []
    pizza_y_ = pizza_y

    R_ = Rad

    while pizza_y_ != -1:
        for i in range(pizza_x - R_, pizza_x + R_ + 1):
            if i >= 0 and i < N:
                # print([i, pizza_y_])
                cover_liner.append(pizza_y_ * N + i)
        pizza_y_ = pizza_y_ - 1
        R_ = R_ - 1
   
    pizza_y_ = pizza_y + 1
    R_ = Rad - 1

    while pizza_y_ != N:
        for i in range(pizza_x - R_, pizza_x + R_ + 1):
            if i >= 0 and i < N:
                # print([i, pizza_y_])

                cover_liner.append(pizza_y_ * N + i)
        pizza_y_ = pizza_y_ + 1
        R_ = R_ - 1
        

    return cover_liner


info = [int(i) for i in input().split()]


count_pizza_house = info[1]
end_array = []

array_for_intersection = []

for a in range(0, count_pizza_house):
    pizza = [int(i) for i in input().split()]
    end_array.append(count_cover(pizza[0] - 1, pizza[1] - 1, pizza[2], info[0]))
    
    pizza.clear()


numeric = [a for a in range(count_pizza_house - 1, -1, -1)]


pizza.clear()
info.clear()

for i in range(count_pizza_house, 0, -1):
    for j in combinations(numeric, i):
        info.append(list(j))

array_for_intersection.clear()

for i_mass in info:
    for q in i_mass:
        array_for_intersection.append(end_array[q])
    intersection = list(reduce(lambda u, v: u & v, (set(x) for x in array_for_intersection)))
    if len(intersection) > 0:
        print(len(array_for_intersection))
        break
   
    array_for_intersection.clear()

