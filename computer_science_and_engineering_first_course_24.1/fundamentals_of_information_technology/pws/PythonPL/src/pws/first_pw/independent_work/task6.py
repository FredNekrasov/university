# Определить значение функции Z=1/(XY) при X и Y не равных 0.
#6
x = int(input("input x "))
y = int(input("input y "))
if y != 0 and x != 0:
    z = 1 / (x * y)
    print(f"result/z = {z}")
else: print("error")