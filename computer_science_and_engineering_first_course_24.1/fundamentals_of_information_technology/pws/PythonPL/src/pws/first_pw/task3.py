# Имеется четыре числа, которые требуется просуммировать (обозначим их переменными a, b, c и d соответственно). Сумму их значений обозначим S1.
# Требуется найти также величину S2 = S1 + b и определить отношение S2/S1  (обозначим это отношение переменной res).
# В результате нужно вывести значения переменных S1 и res.
a = int(input("input a\n"))
b = int(input("input b\n"))
c = int(input("input c\n"))
d = int(input("input d\n"))
s_1 = a + b + c + d
s_2 = s_1 + b
result = s_2 / s_1
print(f"s1 = {s_1}, res = {result}")