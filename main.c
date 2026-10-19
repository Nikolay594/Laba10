#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "timing.h"


int main(void)
{
    setlocale(LC_CTYPE, "RUS");

    char code;
    int start_sec, end_sec;
    
    printf("Система хронометража\n");

    while (1) {
        printf("Код спортсмена: ");
        scanf(" %c", &code);

        if (code == '!')
            break;

        printf("Время старта (сек): ");
        scanf("%d", &start_sec);

        printf("Время финиша (сек): ");
        scanf("%d", &end_sec);

        printf("Спортсмен '%c': ", code);
        process_stage(start_sec, end_sec);
        printf("\n");
    }

    printf("Работа программы завершена.\n");
    return 0;
}