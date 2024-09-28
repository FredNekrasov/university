# Известен объем информации в байтах. Перевести в Кбайты, Мбайты.
#5
byte_size = int(input("Введите объем информации в байтах: "))
kilobytes = byte_size / 1024
megabytes = kilobytes / 1024
print(f"Объем в Кбайтах: {round(kilobytes, 2)} KB")
print(f"Объем в Мбайтах: {round(megabytes, 6)} MB")