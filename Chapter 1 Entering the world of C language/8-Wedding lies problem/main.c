#include <stdio.h>

int main()		
{
	int a, b, c;
	for (a = 1; a <= 3; a++)
		for (b = 1; b <= 3; b++)
			for (c = 1; c <= 3; c++)
			{
				if (a != 1 && c != 1 && c != 3 && a != b && b != c && a != c)
				{
					printf("%c marry A\n", ('X' + a - 1));
					printf("%c marry B\n", ('X' + b - 1));
					printf("%c marry C\n", ('X' + c - 1));
				}
			}	
	return 0;
}
