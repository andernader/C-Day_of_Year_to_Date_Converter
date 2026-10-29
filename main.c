#include <stdio.h>

void split_date(int day_of_year, int year, int* month, int* day){
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
        month_days[2 - 1]++;

    int i;
    for(i = 0; day_of_year > month_days[i]; i++){
        day_of_year -= month_days[i];
    }

    *month = i + 1;
    *day  = day_of_year;

    return;
}

int main(void){
    int day_of_year;
    int year;
    int month, day;
    printf("Enter day_of_year: ");
    scanf("%d", &day_of_year);
    printf("Enter year: ");
    scanf("%d", &year);

    split_date(day_of_year, year, &month, &day);

    printf("The date of day %d of %d is: %02d.%02d.%04d\n", day_of_year, year, day, month, year);

    return 0;
}
