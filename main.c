#include <stdio.h>
#include <stdlib.h>

int get_1st_weekday(int year)
{
    int day;
    day = (((year-1)*365) + ((year-1)/4) - ((year-1)/100) + ((year/400)+1)) % 7;
    return day;
}

int main()
{
    system("Color 3");

    int year, weekDay = 0, startingDay;

    printf("Enter your desired calender year: ");
    scanf("%d",&year);

    char *months[]={"January","February","March","April","May","June","July","August","September",
                           "October","November","December"};
    int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};

    if((year%4==0 && year%100!=0) || year%400==0)
    {
        monthDays[1]=29;
    }

    startingDay = get_1st_weekday(year);

    for(int month=0; month<12; month++)
    {
        int daysInMonth = monthDays[month];

        printf("\n\n-----------%s-----------",months[month]);
        printf("\n Sun   Mon   Tues   Wed   Thus   Fri   Sat\n");

        for(weekDay=0; weekDay<startingDay; weekDay++)
        {
            printf("    ");
        }

        for(int day=1; day<=daysInMonth; day++)
        {
            printf("%6d",day);


            if(++weekDay > 6)
            {
                printf("\n");
                weekDay = 0;
            }

            startingDay = weekDay;
        }
    }


}
