//Luying Cai A3 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IntArray {
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int length){
	// build a new pointer to access members 
	struct IntArray *newptr;
	// allocating memory for number of struct IntArray.
	newptr = (struct IntArray *)(malloc(sizeof(struct IntArray)));
	// allocating memory for each int type dataPtr.
	newptr->dataPtr = (int *)malloc(length * sizeof(int));
	//assign length value to structure length.
	newptr->length = length;
	//return new pointer
	return newptr;

}

void freeIntArray(struct IntArray *arrayPtr){
	//free the instence and free the instance's dataPtr.
	
	free(arrayPtr->dataPtr);
	arrayPtr->length = 0;
	free(arrayPtr);
	
}
//cite: fgets:https://www.programiz.com/c-programming/c-strings
//cite: strtol: https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm
void readIntArray(struct IntArray *array){
	//initialize:
	char input[BUFSIZ];
	char *ptr;
	int integer;
	
	
	//read one int for each array index
	for(int i = 0; i < array->length; i++){
		printf("Enter int: ");//prompts and reads positive ints from the user.
		fgets(input, BUFSIZ, stdin);// get input from stdin/
		integer = strtol(input, &ptr, 10);//change char to decimal assign to int integer.
		if (integer <= 0)//if integer less or equal to 0, give error message.
			printf(" Invalid input\n");
			i--;
			continue;
		else
			array->dataPtr[i] = integer; 
	}
}

//cite:https://www.programiz.com/dsa/selection-sort
void swap(int *xp, int *yp){
	//swap xp and yp through a cash.(from slide)
	int t0 = *xp; 
	int t1 = *yp;
	*xp = t1;
	*yp = t0;
}
// selection sort the input array in ascending order.
void sortIntArray(struct IntArray *array){
	//reduce the array length one by each iteration.
	for (int i = 0; i < array->length - 1; i++){
		int min = i;// store the minimum element, assume the first element is minimum.
		for (int j = min + 1; j < array->length; j++){ 
			if (array->dataPtr[j] < array->dataPtr[min]) //find the minimum element.
				min = j; //update minimum element.
		}
	swap(&array->dataPtr[min], &array->dataPtr[i]); // swap to keep ascending order.
	}
}

void printIntArray(struct IntArray *array){
	printf("[ "); 
	for(int i = 0; i < array->length; i++){ //when i < array's length, print each element in array.
		printf("%d", array->dataPtr[i]);
		if ( i != array->length - 1) // if not last one, print , after each elemnt.
			printf(","); 
		else
			printf(" ]\n"); // last print ]. 
	}
}

int main() {
	char input[BUFSIZ];
	char *ptr;
	int integer;
	printf("Enter length: ");//prompt the user to input a positive (>0) int length from the user
	fgets(input, BUFSIZ, stdin); 
	integer = strtol(input, &ptr, 10);
	while (integer <= 0){
		printf("Invalid input !\n");// print error message if not positive number.
		printf("Enter length: ");
		fgets(input, BUFSIZ, stdin); //again if input valid number
		integer = strtol(input, &ptr, 10);
		
	}
	
	struct IntArray* newArray = mallocIntArray(integer);
	readIntArray(newArray);
	sortIntArray(newArray);
	printIntArray(newArray);
	freeIntArray(newArray);
	
	
}