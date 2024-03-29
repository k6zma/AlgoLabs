# Предки - наше всё

Компания OOO "Предки - наше все" занимается построением генеалогического древа. Так оказалось, что вместо стажировки в Яндексе вы решили пойти работать в эту компанию для того, чтобы оплатить свое образование. К несчастью, данные о предках ваших клиентов постоянно меняются, поэтому часто приходится его редактировать. Удивительным образом вы заметили, что генеалогическое древо для текущего клиента является бинарным деревом, где в вершине значение является возрастом данного человека. Дабы автоматизировать процесс и ускорить подготовку проекта, вы решили запрограммировать все редактирование и трассировку с помощью следующих команд:

- `insert x` — добавить нового человека с возрастом \( x \) в древо. Если в дереве уже есть человек с возрастом \( x \), то добавлять нового не надо.
- `delete x` — удалить из дерева человека с возрастом \( x \). Если человека с возрастом \( x \) в древе нет, ничего делать не надо.
- `exists x` — если есть человек с возрастом \( x \) в древе, вывести "true", если нет - "false".
- `next x` — вывести минимальный возраст в древе, строго больший \( x \), или "none", если такого нет.
- `prev x` — вывести максимальный возраст в древе, строго меньший \( x \), или "none", если такого нет.

В древо помещаются и извлекаются только целые числа, не превышающие по модулю \( 10^9 \).

## Входные данные

Операций с древом, их количество не превышает

100.

## Выходные данные

Выведите последовательно результат выполнения всех операций `exists`, `next`, `prev`. Каждый ответ на новой строчке.

### Пример

#### STDIN
```
insert 2
insert 5
insert 3
exists 2
exists 4
next 4
prev 4
delete 5
next 4
prev 4
```

#### STDOUT
```
true
false
5
3
none
3
```