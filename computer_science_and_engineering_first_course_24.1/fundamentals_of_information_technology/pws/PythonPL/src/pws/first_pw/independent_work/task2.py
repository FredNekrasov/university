# Даны действительные числа А, В, С. Найти максимальное и минимальное из этих чисел.
a = int(input("input a "))
b = int(input("input b "))
c = int(input("input c "))
maximum = max(a, b, c)
minimum = min(a, b, c)
print(f"min = {minimum}, max = {maximum}")