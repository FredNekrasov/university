# Дан номер места в плацкартном вагоне. Определить, какое это место: верхнее или нижнее, в купе или боковое.

number = int(input("input number "))

if number % 2 == 0:
    print("upper")
else:
    print("lower")
if number in range(1, 36):
    print("cup")
else:
    print("side")