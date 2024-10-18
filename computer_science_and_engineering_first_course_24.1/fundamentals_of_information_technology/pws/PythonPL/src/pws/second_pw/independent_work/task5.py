# Имеется коробка со сторонами: АхВхС. Определить пройдёт ли она в дверь с размерами МхК

a = int(input("input a "))
b = int(input("input b "))
c = int(input("input c "))
m = int(input("input m "))
k = int(input("input k "))

if a < m and b < k or a < k and b < m:
    print("пройдёт")
elif c < m and b < k or c < k and b < m:
    print("пройдёт")
elif a < m and c < k or a < k and c < m:
    print("пройдёт")
else:
    print("не пройдёт")