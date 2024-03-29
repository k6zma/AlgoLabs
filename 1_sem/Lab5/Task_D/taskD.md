# Ёлки-палки

На Новый год в ИТМО возле входа в вуз ставится большая красиво украшенная ёлка. Прошлый год не был исключением, но поскольку ИТМО - первый неклассический вуз, то вместо обычной ёлки решили установить ёлку в виде бинарного дерева, где в каждой вершине свое количество украшений согласно свойствам бинарного дерева. К сожалению, со временем дерево накренилось вправо, из-за чего было принято решение снять самые правые украшения на каждом уровне.

## Входные данные

Первая строчка содержит число \( n \) \((1 \leq n \leq 10^3)\) - количество вершин в дереве.

Вторая строчка содержит \( n \) чисел \((-10^9 \leq a_i \leq 10^9)\), задающие количество украшений в каждой вершине дерева, построенного через последовательный `insert`.

## Выходные данные

Вывести через пробел количество украшений самых правых вершин на каждом уровне, начиная с первого уровня.

### Пример

#### STDIN
```
11
100 50 20 19 18 17 25 24 57 160 110
```

#### STDOUT
```
100 160 110 25 24 17
```