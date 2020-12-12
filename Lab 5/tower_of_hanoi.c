/*	
	DSA Lab 5: Tower of Hanoi problem
	Code written by Sushovan Shakya (THA075BEI046)
*/

#include <stdio.h>
#include <unistd.h>

void TOH(int N, char source, char dest, char aux) {

	if(N < 0) {
		printf("Error, invalid disc number");
		return;
	}

	// If it has only one disc
	if(N == 1) {
	   	printf("Move disc 1 from %c to %c \n", source, dest);	
		sleep(1);
	}
	else {
	   // Making C auxiliary and B destination
		TOH(N - 1, source, aux, dest);
		sleep(1);
		printf("Move disc %d from %c to %c \n", N, source, dest);
		sleep(1);
		
        // make  B the source and A an auxiliary position. 		
		TOH(N - 1, aux, dest, source);
	}
}

int main() {
    int disc_num;
    printf("Enter the number of disks: ");
    scanf("%d", &disc_num);
	TOH(disc_num, '1', '3', '2');		// 1 = source, 2 = auxillary, 3 = destination
	return 0;
}
