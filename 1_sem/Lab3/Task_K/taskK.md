# Скрепышовая многоножка

## Задача:
В рамках рекламной кампании компании “Магнит” участникам онлайн-конкурса предлагается найти цикл в связанных скрепышах. Каждый скрепыш соединен с другим, и задача заключается в определении наличия и длины цикла в этой цепочке.

## Входные данные:
1. Число \( n \) (1 ≤ \( n \) ≤ 10^6) — количество скрепышей.
2. \( n \) чисел, где каждое число \( a_i \) указывает на номер скрепыша, закрепленного следующим за \( i \)-м скрепышом. Индексация начинается с 1.

## Выходные данные:
Длина цикла в цепочке скрепышей. Если цикла нет, выведите -1.

## Примеры:

### Ввод 1:
```
6
3 4 5 5 6 2
```
### Вывод 1:
```
4
```

### Ввод 2:
```
3
2 3
```
### Вывод 2:
```
-1
```

## Примечание:
Не допускается использование map, set или массива подсчета. Задача должна быть решена с построением списка. Петля (самоссылка) не считается циклом.