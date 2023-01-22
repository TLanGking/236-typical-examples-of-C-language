#include <stdio.h>

int main()		
{
	//C language built-in types
	printf("size of int:%ld\n", sizeof(int));	
	printf("size of long int:%ld\n", sizeof(long int));
	printf("size of long long:%ld\n", sizeof(long long));
	printf("size of short:%ld\n", sizeof(short));
	printf("size of char:%ld\n", sizeof(char));
	printf("size of float:%ld\n", sizeof(float));
	printf("size of double:%ld\n", sizeof(double));
	//array
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("size of arr1:%ld\n", sizeof(arr1));
	int arr2[][3] = { { 1, 2, 3 } , { 4, 5, 6 } , { 7, 8, 9 } };
	printf("size of arr2:%ld\n", sizeof(arr2));

	return 0;
}
