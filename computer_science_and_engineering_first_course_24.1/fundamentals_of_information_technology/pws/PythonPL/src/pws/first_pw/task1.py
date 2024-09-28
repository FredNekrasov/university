# Дано два числа a и b. Сделать так, чтобы их значения поменялись местами.
a = input("input a = ")
b = input("input b = ")
print(f"old a = {a}, old b = {b}")
c = a
a = b
b = c
print(f"new a = {a}, new b = {b}")