# Дано вещественное число. Определить какое это число: положительное, отрицательное, ноль

number = float(input("input number "))
if number > 0:
    print("number is positive")
elif number < 0:
    print("number is negative")
else:
    print("number is zero")