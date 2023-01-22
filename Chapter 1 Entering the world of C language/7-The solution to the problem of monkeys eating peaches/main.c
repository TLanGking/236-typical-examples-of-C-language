#include <stdio.h>

int main()		
{
	int peach = 0, count = 0;
	printf("Please enter the last amount of peach:");
	scanf("%d", &peach);
	printf("Please enter the count of eating peach:");
	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		peach += 1;
		peach *= 2;
	}	
	printf("The origin amount of prach is %d\n", peach);
	return 0;
}
