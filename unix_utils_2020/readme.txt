                                                                         Алутис Никита группа 207

/--------------------------------------------------------------------------------------------------\
|                                                                                                  |
|                                           Утилиты (P4)                                           |
|                                                                                                  |
\--------------------------------------------------------------------------------------------------/

----------------------------------------------------------------------------------------------------
                                            Предисловие
----------------------------------------------------------------------------------------------------
 Я реализовал cp, grep и tail. Они соответственно располагаются в папках со своими названиями.
Чтобы проверить покрытие, нужно запустить make test
 Примечание:
Ошибка write вызывает abort()
----------------------------------------------------------------------------------------------------
                                            cp
----------------------------------------------------------------------------------------------------
Есть три режима работы:
    1:копировать содержимое файла_1 в файл_2
    2:копировать файлы в директорию, идущую последним аргументом
    3:копировать содержимое stdin в файл_1
Ошибки:
    1: Неверный флаг(Wrong flag)
    2: Недостаточно аргументов(Not enough arguments)
    3: Слишком много аргументов(Too many arguments)
    4: Аргумент не файл и не директория(Error with argument)
    5: Не получилось открыть файл(File open error)
    6: Не получилось создать файл(File creating error)
Примеры команд:
    1:
        ./main text1.txt text2.txt
    (Скопировать содержимое test1.txt в test2.txt)
    2:
        ./main text1.txt text2.txt         ./main text1.txt dir_to_copy
    (Скопировать файлы test1.txt и test2.txt в директорию dir_to_copy)
    3:
        ./main text1.txt
    (Скопировать содержимое stdin в test1.txt)
Флаги:
    Не реализованы
----------------------------------------------------------------------------------------------------
                                            Grep
----------------------------------------------------------------------------------------------------
Есть два режима работы:
    1:если аргумента (не считая флагов) 2 - ищем включения аргумент_1 в файле аргумент_2
    2:если аргумент 1 - ищем включения аргумент_1 в stdin. Ввод заканчивается ctrl+d
Ошибки:
    1: Неверный флаг(Wrong flag)
    2: Слишком много аргументов(Too many arguments)
    3: Нет аргументов(No arguments)
    4: Не получилось открыть файл(File open error)
Примеры команд:
    1:
        ./main life test1.txt
    (Найти вхождения слова "life" в test1.txt)
    2:
        ./main life
    (Найти вхождения слова "life" в stdin)
    3:
        ./main -n life
    (Найти вхождения слова "life" в stdin и пронумеровать)
    4:
        ./main -v life
    (Найти строки без вхождения слова "life" в stdin)
Флаги:
    1:-v - инвертирование поиска, выводит все строки без вхождения строки
    2:-n - выводит номер строки
Особенность ввода флагов:
    Можно вводить сложные флаги по типу -vn(активирует оба флага)
----------------------------------------------------------------------------------------------------
                                            Tail
----------------------------------------------------------------------------------------------------
Есть два режима работы:
    1:если аргумент (не считая флагов) 1 - выводим последние 10 строк файла аргумент_1 
    2:если аргументов нет - выводим последние 10 строк stdin. Ввод заканчивается ctrl+d
Ошибки:
    1: Введено не число после флага -n или +n (line count must be a number)
    2: После флага -n не шло число(flag -n must contain number)
    3: После флага +n не шло число(flag +n must contain number)
    4: Слишком много аргументов(Too many arguments)
    5: Не получилось создать временный файл(File creating error)
    6: Не получилось открыть файл(File open error)
Примеры команд:
    1:
        ./main test1.txt
    (Вывести последние 10 строк test1.txt)
    2:
        ./main
    (Вывести последние 10 строк stdin)
    3:
        ./main -n 3
    (Вывести последние 3 строки stdin)
    4:
        ./main +n 4
    (Вывести строки начиная с 4 из stdin)
Флаги:
    1:-n аргумент_числа - будет выведено аргумент_числа последних строк
    2:+n аргумент_числа - будут выведены строки начиная с аргумент_числа
Особенность ввода флагов:
    После флагов обязательно идет число