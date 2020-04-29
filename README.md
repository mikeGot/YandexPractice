# YandexPractice
Яндекс.Практикум. Алгоритмы
A. Найди id
В медиа-сервисе зарегистрировано n пользователей. Все пользователи, за исключением двух, в последние два месяца посещали сайт. Нужно определить id пользователей, которые сайт не посещали.
Формат ввода:
Первая строка содержит число n — количество зарегистрированных пользователей. Это целое число в диапазоне от 2 до 
Во второй строке через пробел заданы различные n — 2 целых числа. Каждое из них не превосходит n и больше нуля.
Формат вывода:
Нужно в одной строке вывести по возрастанию два пропущенных числа, разделённые пробелом.
Пример
Ввод:
7
6 4 1 2 3
Вывод:
5 7
В примечании было сказано, что алгоритм должен работать не дольше, чем O(n).
Краткий алгоритм:
1. Сортируем введенный массив
2. В цикле проверяем на совпадение итератора и значения массива
3. При несовпадении — добавляем недостающий элемент, а также этот элемент добавляем в другой массив.

B. Три фишки
Маша и Медведь играют в игру. У Маши есть фишки с указанным на них количеством очков. На каждой фишке — k очков, k находится в промежутке от  до . Медведь называет число, а Маша должна выбрать три фишки, сумма очков на которых наиболее близка с заданному числу.
Формат ввода:
Первая строка содержит целое число n в диапазоне от  до  число, названное первым участником. Во второй строке через пробел заданы целые числа в диапазоне от  до  — очки для фишек второго участника. Их количество может быть от 3 до 
Формат вывода:
Нужно вывести целое число — сумму очков трёх фишек, наиболее близкую к n.
Пример
Ввод:
6
-1 -1 -9 -7 3 -6
Вывод:
1