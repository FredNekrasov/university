# Дано натуральное число. Определить будет ли это число: чётным, кратным 4.

number = int(input("input number "))
if number % 2 == 0 and number % 4 == 0:
    print("number is even and multiple of 4")
else:
    print("number is not even and not multiple of 4")
