# LETI-OOP
Object-oriented programming class practice.
The goal is to create a GUI application that can calculate all real and complex roots of a 2nd degree polynomial.

# Практическая работа №1
Создать консольное приложение для вычисления корней и значения для заданного аргумента полинома 2-ой степени на множестве вещественных чисел.
	Приложение должно предлагать пользователю следующее меню команд:
- ввод (изменение) коэффициентов полинома,
- запрос на вычисление корней,
- запрос на вычисление значения полинома с вводом значения аргумента,
- запрос на вывод текстового представления полинома,
- выход из программы. 
	Приложение должно включать основной модуль (функция main), модуль «application» и модуль «polinom».

# Практическая работа №2
Создать консольное приложение для вычисления корней и значения полинома 2-ой степени на множестве комплексных чисел. В нем должны быть сохранены все функции из меню команд из 1-ой работы.
Приложение должно включать основной модуль, модуль «application», модуль «polinom» и модуль «complex».
Для этого в проект лабораторной работы №1 следует добавить модуль с описанием и реализацией собственного класса комплексных чисел TComplex. При этом основной модуль, модуль «application» и модуль «polinom» не должны изменяться.

# Практическая работа №3
Создать GUI приложение для вычисления корней и значения полинома 2-ой степени на множестве комплексных чисел. Приложение должно включать основной модуль, модуль «interface», модуль «polinom» и модуль «complex».

# Практическая работа №4
Создать GUI приложение для вычисления корней и значения полинома 2-ой степени на множестве как вещественных, так и комплексных чисел. 
	Для этого необходимо:
- модифицировать интерфейс программы работы №3,
- преобразовать класс TPolinom в параметризованный класс, в котором абстрактный тип number использовать как параметр класса, исключив из проекта файл number.h,
- исключить из проекта файл polinom.cpp, перенеся предварительно реализацию методов параметризованного класса TPolinom в заголовочный файл polinom.h. 
	Диаграмма классов должна соответствовать ДК работы №3, в которой в качестве сервера зависимости будут представлены 2 класса полинома, параметризованные типами double и TComplex.
