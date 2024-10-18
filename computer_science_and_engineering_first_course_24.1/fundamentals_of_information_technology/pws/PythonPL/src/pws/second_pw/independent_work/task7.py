# Можно ли из бревна, имеющего диаметр поперечного сечения D, выпилить квадратный брус шириной А?

a = int(input("input a "))
d = int(input("input d "))
if d / 2 >= a:
    print("yes")
else:
    print("no")