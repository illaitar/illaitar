                                                                           Алутис Никита группа 207

/--------------------------------------------------------------------------------------------------\
|                                                                                                  |
|                                           Калькулятор                                            |
|                                                                                                  |
\--------------------------------------------------------------------------------------------------/

----------------------------------------------------------------------------------------------------
                                            Предисловие
----------------------------------------------------------------------------------------------------
Рекомендуется читать readme в окне не меньше чем в 100 символов в ширину

Этот код написан студентом второго курса ВМК МГУ Алутисом Никитой Арвидасовичем.

Программа позволяет считать результат выражений содержащих числа типа double, переменных состоящих
Не более чем из шести символов и операторов:
+
-
*
/
(
)

Как работать с программой:
    После запуска вводим в строке выражение. Далее либо найдется синтаксическая ошибка, либо можно
    вводить значения переменных в формате:
    a=5
    Где а - переменная, 5 - значение.
    После того как пользователь введет столько переменных, сколько захочет, он вводит '=' на
    отдельной строке. После этой строки выражение вычислится и выдастся его результат.
    Чтобы завершить работу с программой она должна встретить EOF (в случае stdin достаточно ввести 
    ctrl + D)

Внимание 1!!!
    переменные должны содержать не больше 6 символов, начинаться с большой или маленькой латинской 
    буквы и содержать только большие и маленькие латинские буквы, цифры и символ "_"

Внимание 2!!!
    контроль ввода переменных не осуществляется! они должны быть введены в вышеуказанном формате
    для корректной работы

Внимание 3!!!
    если одна из переменных не инициализированна, но уже вызвано '=', то будет выдана ошибка!

Внимание 4!!!
    если переменная была введена раньше, то при очередной инициализации ее значение перезапишется!

Внимание 5!!!
    осуществляется следущий контроль ввода выражения:
        1)Нарушение баланса скобок
        2)Некорректный ввод числа (должно вводиться как double в стандарте языка си)
        3)Слишком длинное имя переменной (>6)
        4)Лишний некорректный символ наподобие ^ в записи выражения
        5)Пропущен операнд
        6)Пропущена операция
        7)Некорректное название переменной (симовол кроме a-z, A-z, 1-9 и "_")
        8)Ошибка выделения памяти


Структура архива:
    tests_readme.txt - описание тестов и покрытия
    test - папка с тестами
    syntax.c - основной файл калькулятора
    polis.c - модуль работы с полисом
    stack.c - модуль работы со стеком
----------------------------------------------------------------------------------------------------
                                            Реализация
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
                                             Stack.h
----------------------------------------------------------------------------------------------------
Модуль работы со стеком


Основной тип:
    typedef struct Stack{
        size_t size;
        size_t cap;
        char *data;
    } Stack;

Функция инициализации:
    int stack_init(Stack* stack);

Функция финализации:
    void stack_finalize(Stack *stack);

Функция получения элемента из конца стека
    int stack_pop(Stack *stack, void *res, size_t size_res);

Функция пуша элемента на вершину стека
    int stack_push(Stack *stack, void *var, size_t size_var);

----------------------------------------------------------------------------------------------------
                                             Polis.h
----------------------------------------------------------------------------------------------------
Модуль работы с полизом и переменными

Тип элемента списка переменных:
    typedef struct variable_l{
        struct variable_l *next;
        double value;
        char name[7];
    } variable_l;

Тип списка переменных:
    typedef variable_l *variables;

Добавить переменную в список переменных или перезаписать ее значение:
    void add_list(variable_l **root, char what[7], double value);

Очистить список переменных:
    void free_list(variable_l *root);

Глобальная таблица переменных:
    variables vars;

Основной тип полиза:
    typedef struct{
	size_t size;
	void *data;
    } Polis;

Полиз - байтовый массив:
    typedef char Size_elem;

Тип функции вычисления элемента:
    typedef int (*Calculate_elem)(const void *elem, Size_elem size, Stack *stack);

Инициализация полиза:
    int blank(Polis *polis);

Добавить что-либо в полиз (я реализовал универсальную байтовую запись, потому в syntax.c я кладу в 
полиз последовательно размер, ссылку на функцию-обработчик и сам элемент, а не все вместе):
    int add(Polis *polis, const void *elem, Size_elem size);

Очистка полиза:
    void clear(Polis *polis);

Вычисление значения полиза:
    int calculate_polis(const Polis *, void* , size_t size_res);
----------------------------------------------------------------------------------------------------
                                             Syntax.c
----------------------------------------------------------------------------------------------------
Основной модуль - сначала парсинг строки с помощью функции получения очередной лексемы, затем
цикл ввода переменных и вычисления значения переменных

Функция сложения для полиза:
    add_func(const void *elem, Size_elem size, Stack *stack)

Функция вычитания для полиза:
    sub_func(const void *elem, Size_elem size, Stack *stack)

Функция умножения для полиза:
    multi_func(const void *elem, Size_elem size, Stack *stack)

Функция деления для полиза:
    div_func(const void *elem, Size_elem size, Stack *stack)

Функция числа для полиза:
    num_func(const void *elem, Size_elem size, Stack *stack)

Функция переменной для полиза:
    var_func(const void *elem, Size_elem size, Stack *stack)

Функция получения следущей лексемы из stdin:
    void next1(int *otype, char** lexem){
