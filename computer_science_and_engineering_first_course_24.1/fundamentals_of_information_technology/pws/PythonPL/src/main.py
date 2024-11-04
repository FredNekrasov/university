# Алиса и Боб играют в камни. Они выстроили ряд из n камней, каждому из которых присвоили значение.
# То есть у них есть массив целых чисел stones, где stones[i] — значение i-го камня.
# Алиса и Боб играют по очереди, Алиса ходит первой. На каждом ходу можно убрать любой камень из stones.
# Если сумма значений всех убранных камней делится на 3, участник проигрывает. Алиса также проигрывает, если камни заканчиваются.
# Предполагая, что игроки выбрали оптимальные стратегии, верните true, если победит Алиса, и false, если победит Боб.
from random import randint

def generate_stones(size):
    return [randint(0, size) for _ in range(size)]

def select_stone(stones, removed_stone):
    for stone in stones:
        if (stone + removed_stone) % 3 != 0:
            return stone
    return None

def main():
    n = int(input("Введите количество камней: "))
    stones = generate_stones(n)
    removed_stones = 0
    step = 0
    while True:
        print(f"Текущие камни: {stones}. Количество убранных камней: {removed_stones}")
        selected_stone = select_stone(stones, removed_stones)
        if selected_stone is not None:
            removed_stones += selected_stone
            stones.remove(selected_stone)
        else:
            win = "Боб выиграл!" if step % 2 == 0 else "Алиса выиграла!"
            print(win)
            break
        if not stones:
            print("Камни закончились! Боб выиграл!")
            break
        step += 1
main()