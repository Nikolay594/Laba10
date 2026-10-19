#include <stdio.h>
#include "timing.h"

int get_duration(int start_sec, int end_sec)
{
    return end_sec - start_sec;
}

int check_status(int duration_sec)
{
    if (duration_sec < 30) //Дисквалификация
    {
        return -1;
    }

    if (duration_sec < 45) //Рекорд
    {
        return 1;
    }

    return 0;
}

int get_full_minutes(int total_sec)
{
    return total_sec / 60; //Секунды в минуты
}

void print_time_mm_ss(int minutes, int seconds)
{
    printf("%02d:%02d", minutes, seconds);
}

void process_stage(int start_sec, int end_sec)
{
    int duration = get_duration(start_sec, end_sec);
    int status = check_status(duration);
    int minutes = get_full_minutes(duration);
    int seconds = duration % 60;

    print_time_mm_ss(minutes, seconds);

    if (status == -1) 
    {
        printf("Дисквалификация");
    }
    else
    {
        if (status == 1) 
        {
            printf("Рекорд!");
        }
        else
        {
            printf("Норма");
        }      
    }       
}