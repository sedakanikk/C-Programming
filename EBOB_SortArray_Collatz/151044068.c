#include <stdio.h>

// takes what user want
int menu();
//for part 1
void find_factors(int number1, int number2, int arr1[], int arr2[]);
int common(int arr1[], int arr2[], int *result);
//for part 2
void sorting(int arr[], int first, int middle, int last);
void mergeSort(int arr[], int first, int last);
//for part 3
int find_nums(int number);
int number_of_digit(int number, int size);
int power(int base, int n);
//for part 4
int check_theFormula(int number, int size, int sum);
//for part 5
char find_first_capital(char arr[], int *found, int size);

/* implementations */
//menu asks user to choice about which part will be do
int menu() {
	int choice;
	printf("***** MENU *****\n");
	printf("1. Part1-Common Divisor\n");
	printf("2. Part2-Merge Sort\n");
	printf("3. Part3-Calculate Function\n");
	printf("4. Part4-Is Equal or Not\n");
	printf("5. Part5-Find First Capital Letter\n");
	printf("6. Exit\n");
	printf("Choice: ");
	scanf("%d", &choice);
	return choice;
}
/*********************PART1*********************/
// helper function
// finds all divisor of given two numbers and stores them in arrays
void find_factors(int number1, int number2, int arr1[], int arr2[]) {
	int i, k=0;
	for(i=2; i<=number1;) {
		if(number1%i == 0) { // if number can divided by inreasing i
			number1=number1/i;
			arr1[k++] = i; // assigns them array
		}
		else
			i++;
	}
	k=0;
	for(i=2; i<=number2;) {
		if(number2%i == 0) {
			number2=number2/i; // if number can divided by inreasing i
			arr2[k++] = i; // assigns them array
		}
		else
			i++;
	}
}
// recursive function
// calculates common divisors
int common(int arr1[], int arr2[], int *result) {
	if(arr1[0]=='\0' || arr2[0]=='\0') // if array is empty 
		return *result; // returns result
	if(arr1[0] == arr2[0]) { // if elements are equal 
		(*result)*=arr1[0]; // multiple by this number
		common(&arr1[1], &arr2[1], result); // then call from next elements
	}
	else if(arr1[0] > arr2[0]) // if first array's element is bigger than other's
		common(arr1, &arr2[1], result); // then call from other's next element
	else if(arr1[0] < arr2[0]) // if other array's element is bigger than first's
		common(&arr1[1], arr2, result); // then call from first's next elements
	return *result; // then return result
}
/*********************PART2*********************/
// helper function
void sorting(int arr[], int first, int middle, int last) {
	int i, j, index, first_part[middle-first+1], second_part[last-middle];
	// assign arr's elements from first to middle position to array which first_part 
	for (i = 0; i <= middle-first; i++)
		first_part[i] = arr[first+i];
	// assign arr's elements from middle to last position to array which second_part
	for (j = 0; j < last-middle; j++)
		second_part[j] = arr[middle+j+1];
	// among the size from zero
	for(i=0, j=0, index=first; i<=middle-first && j<last-middle;) {
		if (first_part[i] <= second_part[j]) // if first_part's element is smaller than or equal to second_part's element
			arr[index++] = first_part[i++]; // add this element to array which will be sorted
		else // if first_part's element is bigger than second_part's element
			arr[index++] = second_part[j++]; // add this element to array which will be sorted
	}
	// among the size for second_part
	for (;j<last-middle;j++)
		arr[index++] = second_part[j];
	// among the size for first_part
	for (;i<=middle-first;i++)
		arr[index++] = first_part[i];
}
// recursive function
void mergeSort(int arr[], int first, int last) { 
	if (first < last) { // if first index is smaller than last index
		mergeSort(arr, first, (first+last)/2); // last index is these length's middle index
		mergeSort(arr, (first+last)/2+1, last); // then from middle index to last index

		sorting(arr, first, (first+last)/2, last); // then sort specified merge
	} 
}
/*********************PART3*********************/
// recursive function
// calculates function
int find_nums(int number) {
	printf("%d ", number);
	if(number == 1) // if number is one
		return number; // then returnes number
	if(number%2 == 0) { // number's mod by 2 is 0 calculates given formula
		find_nums(number/2);
	}
	if(number%2 == 1) { // number's mod by 2 is 1 calculates given formula
		find_nums(3*number+1);
	}
	return number;
}
/*********************PART4*********************/
// helper function
// calculates power of given number
int power(int base, int n) {
	int i, result=1;
	for(i=1; i<=n; i++) {
		result*=base;
	}
	return result;
}
// recursive function
// finds digit's number
int number_of_digit(int number, int size) {
	if(number == 0) { // if number is zero, then return size which is zero
		return size;
	}
	return number_of_digit(number/10, ++size); // divide by 10 and send the number to function
}
// calculates given formula
int check_theFormula(int number, int size, int sum) {
	if(number == 0) // if number is zero return number
		return number;
	sum+=check_theFormula(number/10, size, sum); // sum is equal to sum of all the elements's nth power
	return sum+power(number%10, size); 
}

/*********************PART5*********************/
//finds the first capital letter from given text by user
char find_first_capital(char arr[], int *found, int size) {
	if(size==0 && arr[0]>=65 && arr[0]<=90) { // if first element is between ASCII values of capital letters and size is zero
		*found=1; // then to some filter, assign 1 to found
		return arr[0];
	}
	else if(size==0) // return null if size is zero
		return ;
	if(arr[0]>=65 && arr[0]<=90) { // if first element is between ASCII values of capital letters
		*found=1; // then to some filter, assign 1 to found
		return arr[0];
	}
	else
		return find_first_capital(&arr[1], found, --size); // then call the function from arr's first element, decreasing size value
}
/* main part */
int main() {
	int choice = menu();
/*********************PART1*********************/
	// while user's choice is specified numbers
	while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5) {
		if(choice == 1) { // if user's choice is 1
			int number1, number2, i, result=1, arr1[1000], arr2[1000], temp;
			printf("Input: "); // takes two number from user
			scanf("%d %d", &number1, &number2);

			find_factors(number1, number2, arr1, arr2); // call this function

			printf("Factors of %d { ", number1);
			for(i=0; arr1[i]!='\0'; i++)
				printf("%d ", arr1[i]); // list elements among the arr's size
			printf("}\n");

			printf("Factors of %d { ", number2);
			for(i=0; arr2[i]!='\0'; i++)
				printf("%d ", arr2[i]); // list elements among the arr's size
			printf("}\n");

			common(arr1, arr2, &result);
			if(result == 1)
				printf("There is no common multipliers\n"); // if there is no common element
			else
				printf("Output: %d\n", result); // if there is common element
		}
/*********************PART2*********************/
		else if(choice == 2) { // if user's choice is 2
			int length=0;
			printf("Enter the length of the list: "); // user enters length
			scanf("%d", &length);
			int arr[1000];
			printf("Enter the elements of the list: \n"); // user enters elements
			int i;
			for(i=0; i<length; i++) {
				scanf("%d", &arr[i]); // among the length, takes elements from user
			}
		    mergeSort(arr, 0, length-1); // then call the funtion to sort these list
		    printf("Sorted array is: ");
			for(i=0; i<length; i++) {
				printf("%d ", arr[i]); // then, print sorted list
			}
			printf("\n");
		}

/*********************PART3*********************/
		else if(choice == 3) { // if user's choice is 3
			int number;
			printf("Input: "); // takes input from user
			scanf("%d", &number);
			printf("Output: ");
			find_nums(number); // calls he function to calculates formula
			printf("\n");
		}

/*********************PART4*********************/
		else if(choice == 4) { // if user's choice is 4
			int number, n=0, f=0, sum=0;
			printf("Input: "); // takes input from user
			scanf("%d", &number);

			n = number_of_digit(number, n); // n is the digit number
			f = check_theFormula(number, n, sum); // then calculate all the formula

			if(f == number)
				printf("Output: Equal\n"); // if user's number is equals given formula
			else
				printf("Output: Not Equal\n"); // if user's number is equals given formula
		}
/*********************PART5*********************/
		else if(choice == 5) { // if user's choice is 5
			int size, found=0, i=0;
			char res, str[1000];
			printf("Input: "); // takes input from user
			scanf("%s", str);

			//to calculate given string's size
			for(i=0; str[i] != '\0'; i++) {
			}
			res = find_first_capital(str, &found, i); // calls the function and calculates first capital letter
			if(found == 1)
				printf("Output: %c\n", res);
			else
				printf("there is no capital letter in the string\n");
		}
		choice = menu();
	}
	return 0;
}