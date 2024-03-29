# Юность в сапогах

## Задача:
Алексей, первокурсник ИСа, пришел в военкомат и увидел большую толпу людей. Он решил контролировать очередь, чтобы предотвратить вклинивание людей. Вам нужно помочь ему в этом, обрабатывая операции добавления и удаления людей из очереди.

## Входные данные:
1. Число \( n \) (1 ≤ \( n \) ≤ 10^6) — количество операций в списке.
2. Операции двух видов:
   - "+ \( x \)" — добавить нового человека в очередь с номером \( x \) (−10^9 ≤ \( x \) ≤ 10^9).
   - "−" — вычеркнуть человека из начала списка.

## Выходные данные:
Выведите номера людей в порядке их удаления из списка, каждый номер на новой строке.

## Примеры:

### Ввод:
```
4
+ 1
+ 10
-
-
```
### Вывод:
```
1
10
```

## Примечание:
Необходимо реализовать свою структуру данных для очереди на связных списках. Решение на массивах оценивается в 0 баллов, использовать встроенные структуры данных нельзя.