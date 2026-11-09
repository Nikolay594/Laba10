#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ROW 7
#define COL 7

int check(double x, double y);
void pint(char symbol_1, char symbol_0);  // исправлена сигнатура: char вместо int, void вместо int

int main(void)  // main должен возвращать int (стандарт C)
{
    setlocale(LC_CTYPE, "RUS");

    int flag;
    double x, y;
    char c_1, c_0;
    char buf[4];

    printf("__________*Программа для нахождения точек в фигуре*__________\n");

    while (1)
    {
        printf("\nВыберите, какую программу хотите выполнить:\n"
               " 1. Определение нахождения точки на плоскости\n"
               " 2. Нарисовать фигуру\n"
               " 3. Закрыть программу\n");
        if (scanf("%d", &flag) != 1) {
            while (getchar() != '\n');  // очистка буфера при некорректном вводе
            continue;
        }
        switch (flag)
        {
        case 1:
            printf("\nВведите координаты точки для определения, лежит ли она в фигуре: \n");
            scanf("%lf %lf", &x, &y);
            if (check(x, y))
                printf("Точка находится в области фигуры\n");
            else
                printf("Точка вне области фигуры\n");
            break;  // добавлен break

        case 2:
            printf("Введите сначала символ для точек в фигуре, а после символ для точек вне фигуры: \n");
            // очистка буфера перед чтением символов
            while (getchar() != '\n');
            scanf("%c %c", &c_1, &c_0);
            pint(c_1, c_0);
            break;  // добавлен break

        case 3:
            printf("Спасибо за использование программы\n");
            return 0;  // корректный выход из программы

        default:
            printf("Программы под этим номером нет(\n");
            break;
        }
    }

    return 0;
}

int check(double x, double y)
{
    return (x >= 2.0 && x * x + y * y <= 36.0);
}

void pint(char symbol_1, char symbol_0)  // добавлены типы параметров
{
    int row, col;
    for (row = -7; row <= ROW; row++)
    {
        for (col = -4; col <= COL; col++)
        {
            if (check(col, row))
                putchar(symbol_1);
            else
                putchar(symbol_0);
        }
        printf("\n");
    }
}
