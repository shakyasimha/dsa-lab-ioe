/*
    DSA Lab 5: GCD of two numbers using recursion
    Code written by Sushovan Shakya (THA075BEI046)
*/

#include <stdio.h>

int gcd(int A, int B) {
    if(B != 0) 
        return gcd(B, A % B);
    else
        return A;
}

int main() {
    int in_num_1, in_num_2, hcf;
    
    printf("Enter any two numbers: \n");
    scanf("%d %d", &in_num_1, &in_num_2);
    
    hcf = gcd(in_num_1, in_num_2);
    printf("GCD of %d and %d is %d\n", in_num_1, in_num_2, hcf);

    return 0;
}
