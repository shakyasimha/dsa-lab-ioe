/*
    DSA Lab 5: N term of Fibonacci series using Recursion
    Code written by Sushovan Shakya (THA075BEI046)
*/

#include <stdio.h>

unsigned long long int Fibonacci(int N) {
    if(N == 0)
        return 0;
    else if(N == 1)
        return 1;
    else
        return Fibonacci(N - 1) + Fibonacci(N - 2);
}

int main() {
    int input_num;
    unsigned long long int fibo;
    printf("Enter any number to find nth Fibonacci term: ");
    scanf("%d", &input_num);
    fibo = Fibonacci(input_num);
    printf("Fibonacci term at %d is %llu\n", input_num, fibo);
    return 0;
}
