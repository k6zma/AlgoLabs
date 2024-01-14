# Может ты скажешь ей, что ты не Леонтий?

Недавно вошедшие в список форбс 24 до 24-ех Леонид и Семен решили открыть новый бизнес. Для этого они нашли знаменитую предпринимательницу Лизу, которая стала спонсором их стартапа. Для успешного трейдинга ребята создали один основной аккаунт и один дополнительный.

Для хорошей отчетности перед инвестором все рискованные сделки они проводят со второго аккаунта. Как только второй аккаунт выходит в положительный баланс, то ребята сливают все акции на основной аккаунт, а второй портфель очищается.

Вы - первый разработчик в их стартапе, перед Вами стоит сложная задача реализации придуманной Семой и Лёвой системы.

С аккаунтами могут происходить следующие операции:

- `buy account id` — купить акции с номером `id` в портфель `account` (может быть для обоих аккаунтов).
- `sell account id` — продать акции с номером `id` из портфеля `account` (может быть для обоих аккаунтов).
- `merge` — сливать все акции в основной портфель.

После каждого объединения товарищи проводят показ результатов Лизе, поэтому при этой операции требуется выводить `id` акций в отсортированном виде без пробела на конце.

## Входные данные

В первой строке подается число `n` \((1 \leq n \leq 10^7)\) - количество операций.

В следующих `n` строках подаются команды одного из 3 видов (buy, sell, merge). Гарантируется, что номер акции: \(0 \leq id \leq 10^9\).

## Выходные данные

При каждой операции merge вывести `id` акций в отсортированном виде.

### Пример

#### STDIN
```
1
buy 1 1
```

#### STDOUT
```
```

#### STDIN
```
2
buy 1 2
merge
```

#### STDOUT
```
2
```

### Примечание

Если портфель пуст, то выводить ничего не требуется.