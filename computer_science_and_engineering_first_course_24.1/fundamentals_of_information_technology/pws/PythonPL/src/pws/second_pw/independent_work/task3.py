# Дано натуральное число. Определить будет ли это число: нечётным, кратным 7.

number = int(input("input number "))
if number % 2 == 1 and number % 7 == 0:
    print("number is odd and multiple of 7")
else:
    print("number is not odd and not multiple of 7")