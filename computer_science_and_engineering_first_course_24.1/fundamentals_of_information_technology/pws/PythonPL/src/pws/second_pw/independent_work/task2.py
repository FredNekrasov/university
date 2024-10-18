# Дано натуральное число. Определить будет ли это число: нечётным, кратным 5.

number = int(input("input number "))
if number % 2 == 1 and number % 5 == 0:
    print("number is odd and multiple of 5")
else:
    print("number is not odd and not multiple of 5")