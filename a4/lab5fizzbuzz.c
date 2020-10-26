//lab5
//luying cai

#include <stdio.h>
int fuzzbizz_for_goto(unsigned int n){
	int i = 1; //init
	loop: 
		{
			if (i % 3 == 0) //if i div 3 equal to zero
				printf("fizz ");//print fizz
			else if (i % 5 == 0) // if i div 5 equal to 0
				printf("buzz ");//print buzz
			else
				printf("%d ", i);//print num
			
		}
	i++;// update i
	if (i < n + 1) // if i in range(1,n+1)
		goto loop; // goto loop
	done:
		return 0;
}
int main() {
	fuzzbizz_for_goto(10);//1 2 fizz 4 buzz fizz 7 8 fizz buzz
}