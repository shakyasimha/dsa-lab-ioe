/*
	DSA Lab 5: Recursive algorithm for factorial
	Code written by Sushovan Shakya (THA075BEI046)
*/

#include <stdio.h>

unsigned long long int factorial(int n) {

	if(n < 0) {
		return -1;
	}
	else {
		if(n == 0 || n == 1)
			return 1;
		else {
			return (n * factorial(n - 1));
		}
	}
}

int main() {
	int input_num;
	unsigned long int fact;

	printf("Enter any number: ");
	scanf("%d", &input_num);

	fact = factorial(input_num);
	printf("Factorial of %d : %llu\n", input_num, fact);

	return 0;
}
