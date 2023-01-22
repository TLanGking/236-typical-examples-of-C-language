#include <stdio.h>

//date structure
struct Date
{
	int year;
	int month;
	int day;
};

//Determine whether the year is a leap year
int isLeapYear(int year)
{
	if ((year % 400) == 0 || ((year % 4) == 0 && (year % 100) != 0))
		return 1;
	return 0;
}

//Calculate the number of days in a certain year and month
int dayOfMonth(int year, int month)
{
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return isLeapYear(year) ? 29 : 28;
		default:
			return 0;
	}
}

//user input date function
void inputDate(struct Date* date)
{
	int year = 0, month = 0, day = 0;
	while (1)
	{
		printf("Please enter the last date(Year Monyh Day):\n");
		scanf("%d %d %d", &year, &month, &day);
		if (year >= 1992 && month >= 1 && month <= 12 && day >= 1 && day <=31)
		{
			if (day <= dayOfMonth(year, month))
			{
				date->year = year;
				date->month = month;
				date->day = day;
				return;
			}
			else
			{
				printf("date wrong!\n");
			}
		}
		else
		{
			printf("Such date not exist!\n");
		}
	}
}

//judge two days whether same
int isDateSame(int y, int m, int d, struct Date* date)
{
	if (y == date->year && m == date->month && d == date->day)
		return 1;
	return 0;
}

//calculate the days between two dates
int dayDifference(struct Date* date1, struct Date* date2)
{
	int year, month, day, count = 0;
	year = date1->year;
	month = date1->month;
	day = date1->month;
      	while (!isDateSame(year, month, day, date2))
	{
		if (day != dayOfMonth(year, month))
		{
			day++;
		}
		else
		{
			if (month != 12)
			{
				month++;
				day = 1;
			}
			else
			{
				year++;
				month = 1;
				day = 1;
			}
		}
		count++;
	}	
	printf("The difference of two days is %d\n", count);
	return count;
}

//judge the last day that is fish  or net
void fishNet(int days)
{
	int temp = days % 5;
	if (temp == 0 || temp == 4)
	{
		printf("net\n");
	}
	else
		printf("fish\n");
}

//main function
int main()		
{	
	struct Date firstDay = { 1992, 1, 1 };
	struct Date lastDay;
	inputDate(&lastDay);
	int day_num = dayDifference(&firstDay, &lastDay);	
	fishNet(day_num);
	return 0;
}
