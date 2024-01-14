# Сдвинь меня, если сможешь

**Задача**: Вам необходимо реализовать циклический сдвиг массива на \( K \) элементов. Если \( K > 0 \), то сдвиг происходит вправо (т.е последний элемент приходит в начало, а предпоследний оказывается последним), если же \( K < 0 \), то сдвиг происходит влево (т.е первый элемент уходит в конец, а второй оказывается первым).

## Входные данные

В первой строке даны два числа - \( N \) ( \( 1 \leq N \leq 10^3 \) ) и \( K \) ( \( -10^9 \leq K \leq 10^9 \) ) - количество чисел и сам сдвиг.

Во второй строке дано \( N \) чисел, не превосходящие \( 10^9 \) и разделенные пробелом.

## Выходные данные

Вывести последовательность чисел на \( K \) элементов

### Примеры

#### Пример 1

**STDIN**
```
5 3
1 6 2 4 22
```

**STDOUT**
```
2 4 22 1 6
```

#### Пример 2

**STDIN**
```
5 -2
1 6 2 4 22
```

**STDOUT**
```
2 4 22 1 6
```

## Примечание

**Пояснение к первому примеру**:

- сдвиг на 1 вправо: 22 1 6 2 4
- сдвиг на 2 вправо: 4 22 1 6 2
- сдвиг на 3 вправо: 2 4 22 1 6

**Пояснение ко второму примеру**:

- сдвиг на 1 влево: 6 2 4 22 1
- сдвиг на 2 влево: 2 4 22 1 6