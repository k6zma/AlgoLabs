# Давай поженимся

## Задача:
В 2077 году на телеканале "Найт-Сити 1" выходит продолжение культовой передачи "Давай поженимся" с новой концепцией, где пары подбираются на основе совместимости натальных карт. У каждого участника вычислен индивидуальный коэффициент натальной карты, а совместимость пары определяется суммой коэффициентов невесты и жениха. Вы хотите начать просмотр с \( k \)-й серии, которая представляет собой пару с \( k \)-ой по величине суммой коэффициентов. Определите эту сумму.

## Входные данные:
1. Два числа \( n \) и \( k \) (1 ≤ \( n \) ≤ 10^5, 1 ≤ \( k \) ≤ \( n^2 \)) — количество участников и номер интересующей серии.
2. \( n \) чисел, обозначающих коэффициенты натальных карт женщин (1 ≤ coef ≤ 10^9).
3. \( n \) чисел, обозначающих коэффициенты натальных карт мужчин (1 ≤ coef ≤ 10^9).

## Выходные данные:
Одно число — \( k \)-ая по величине сумма коэффициентов пары.

## Примеры:

### Ввод:
```
5 10
3 2 1 5 2
4 8 3 1 2
```
### Вывод:
```
5
```