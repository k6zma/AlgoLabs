# Грязные игры

## Задача:
В уездном городке N проводятся скачки на лошадях с возможностью ставок. Результаты скачек предопределены владельцами лошадей, которые могут менять порядок лошадей, платя за это. Владельцы лошадей стремятся к тому, чтобы впереди их лошадей не было лошадей беднее хозяев. Помогите организаторам узнать, существует ли порядок финиширования лошадей, удовлетворяющий всех богачей.

## Входные данные:
1. Число \( N \) (N < 10^6) — количество лошадей.
2. \( N \) чисел, указывающих количество тугриков у хозяев лошадей в порядке, определенном жребием.

## Выходные данные:
Выведите через пробел количество тугриков каждого богатея в порядке финиша их лошадей. Если требуемый порядок не существует, выведите ":(".

## Примеры:

### Ввод:
```
5
10 9 7 10 6
```
### Вывод:
```
:(
```

### Ввод:
```
3
12 3 3
```
### Вывод:
```
4 4 10
```

## Примечание:
Использование встроенных сортировок или контейнеров запрещено.