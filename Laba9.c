#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>
#define ROW 7
#define COL 7

int check(double x, double y);
int pint(double x, double y);

void main()
{
	setlocale(LC_CTYPE, "RUS");

	int flag;
	double x, y;
	char c_1, c_0;
	
	printf("__________*Программа для нахождения точек в фигуре*__________\n");

	while (1)
	{
		printf("\nВыберите, какую программу хотите выполнить:\n 1. Определение нохождение точки на плоскости\n 1. Определение нохождение точки на плоскости\n 1. Определение нохождение точки на плоскости");
	}
	printf("\nВведите координаты точки для опредиления лежит ли она в фигуре: \n");
	scanf("%lf %lf", &x, &y);
	if(check(x, y))
	{
		printf("Точка находится в области фигуры\n");
	}
	else 
	{
		printf("Точка вне области фигуры\n");
	}

	printf("\nХотите ли вы нарисовать фигуру на плоскости?(1-да, 0-нет) \n");
	scanf("%d", &flag);


	if (flag)
	{
		printf("Введите сначала символ для точек в фигуре, а после символ для точек вне фигуры: \n");
		scanf("%c %c", &c_1, &c_0);
		pint(c_1, c_0);
		printf("\nСпасибо за использование программы");
	}
	else 
	{
		printf("Спасибо за использование программы");
	}

}

int check(double x, double y)
{
	return (x >= 2.0 && x * x + y * y <= 36.0);
}

int pint(symbol_1, symbol_0)
{
	int row, col;
	for (row = -7; row <= ROW; row++)
	{
		for (col = -4; col <= COL; col++)
		{
			if (check(col, row))
			{
				putchar(symbol_1);
			}
			else
			{
				putchar(symbol_0);
			}
		}
		printf("\n");
	}
}
//int figure()
//{
//	double x, y;
//
//	scanf("%lf %lf", &x, &y);
//
//	if (x >= 2.0 && x * x + y * y <= 36.0) 
//	{
//		printf("YES");
//	}
//	else 
//	{
//		printf("NO");
//	}
//
//	return 0;
//}
//printf("Введите координаты точки для опредиления лежит ли она в фигуре: \n");
	//scanf("%lf %lf", &x, &y);


	//if(check(x, y))
	//{
	//	printf("Точка находится в области фигуры");
	//}
	//else 
	//{
	//	printf("Точка вне области фигуры");
	//}