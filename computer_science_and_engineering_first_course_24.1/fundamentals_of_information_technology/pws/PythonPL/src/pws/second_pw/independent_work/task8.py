# Можно ли в квадратном зале площадью S поместить круглую сцену радиусом R так, чтобы от стены до сцены был проход не менее К?

s = int(input("input s "))
r = int(input("input r "))
k = int(input("input k "))

if (s - 2 * r) >= k:
    print("yes")
else:
    print("no")