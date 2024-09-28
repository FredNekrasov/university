# Известны оклад (зарплата) и ставка процента подоходного налога. Определить размер подоходного налога и сумму, получаемую на руки.
oklad = int(input("введите оклад\n"))
procent = int(input("введите ставку подоходного налога в %\n"))
nalog = (oklad * procent) / 100
summa = oklad - nalog
print(f"nalog = {nalog}, summa na ruki = {summa}")