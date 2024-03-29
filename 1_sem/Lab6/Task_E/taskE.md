# Три друга 2: возвращение

Три друга списывают лабораторную работу, каждый из них списывает по \( n \) различных задач. Поскольку друзья не очень умные, они не меняют названия отправляемых на проверку файлов.

По истечении времени, отведенного на написание лабораторной, преподаватель запускает бан-машину и ставит баллы по следующим правилам:

- Если задача написана только у одного студента, то этот студент получает 3 балла, поскольку эту задачу он не списывал и не давал списывать.
- Если задача списана ровно у двух студентов, то каждый из них получает по 1 утешительному баллу.
- Если задача списана всеми тремя студентами, то за нее баллы не начисляются никому.

Вывед

ите финальное количество баллов у каждого студента.

В рамках этой задачи будем считать, что Бан-машина считает решения списанными, если у них полностью совпадают имена файлов.

## Входные данные

В первой строке входных данных дается число \( n \) \((1 \leq n \leq 100000)\) - количество задач в лабораторной.

Следующие три строки содержат по \( n \) различных слов в каждой — названия файлов с решениями, отправленных каждым из студентов.

## Выходные данные

Необходимо вывести 3 числа - количество баллов у первого, второго и третьего студента соответственно.

### Пример

#### STDIN
```
3
fir sec thi
thi fir sec
aaa sec bbb
```

#### STDOUT
```
2 2 6
```

### Примечание

Решения, написанные при помощи сортировок, бинпоиска или встроенных деревьев не засчитываются. Set, Map и т.п. - запрещены.

В реальности бан-машина работает намного сложнее ;)
