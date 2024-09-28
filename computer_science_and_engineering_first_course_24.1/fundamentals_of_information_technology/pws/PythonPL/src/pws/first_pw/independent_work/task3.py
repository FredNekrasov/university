# Известны длины трёх сторон треугольника.
# Вычислить периметр треугольника и площадь по формуле Герона (указание: использовать библиотеку math и функцию sqrt()).
import math

a = int(input("input a "))
b = int(input("input b "))
c = int(input("input c "))
p = (a + b + c) / 2
s = math.sqrt(p * (p - a) * (p - b) * (p - c))
print(f"периметр = {round(p, 2)}, площадь = {round(s, 2)}")