import os
import random
f = open("mat3.txt", mode="w")
f.write("6 5\n")
for i in range(6):
    li = []
    for j in range(5):
        li.append(random.randint(1, 1000))
    f.write(" ".join(list(map(str, li))) + '\n')