# Дано натуральное число. Определить будет ли это число: чётным, кратным 10

number = int(input("input number "))
if number % 2 == 0 and number % 10 == 0:
    print("number is even and multiple of 10")
else:
    print("number is not even and not multiple of 10")