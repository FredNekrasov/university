# Преобразовать дату в «компьютерном» представлении (системную дату) в «российский» формат, т.е. dd.mm.yyyy (например, 17/05/2009).
from datetime import date

today = str(date.today())
print(f"sys date = {today}")
today = today.split("-")
today.reverse()
today = ".".join(str(i) for i in today)
print(today)