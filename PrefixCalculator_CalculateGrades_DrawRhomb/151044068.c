#include <stdio.h>
#include <string.h>
#include <math.h>

/*part1's functions*/
int sub(int *number1, int *number2);
int mult(int *number1, int *number2);
int power(int *number1, int *number2);
int mod(int *number1, int *number2);
int add(int *number1, int *number2);
int doit( int f(int *number1, int *number2), int number1, int number2 );

/*************PART1*************/
/*calculate sub for given two numbers*/
int sub(int *number1, int *number2) {
	*number1 = (*number1)-(*number2);
	return (*number1);
}
/*calculate mult for given two numbers*/
int mult(int *number1, int *number2) {
	*number1 = (*number1)*(*number2);
	return (*number1);
}
/*calculate power for given two numbers*/
int power(int *number1, int *number2) {
	*number1 = pow((double)(*number1),(double)(*number2));
	return (*number1);
}
/*calculate division for given two numbers*/
int div(int *number1, int *number2) {
	*number1 = (*number1)/(*number2);
	return (*number1);
}
/*calculate mod for given two numbers*/
int mod(int *number1, int *number2) {
	*number1 = (*number1)%(*number2);
	return (*number1);
}
/*calculate add for given two numbers*/
int add(int *number1, int *number2) {
	*number1 = (*number1)+(*number2);
	return (*number1);
}
/*all the methods whic calculate, comes here and goes the rigth function with given numbers*/
int doit( int f(int *number1, int *number2), int number1, int number2 ) {
	int s = 0;
	s=f(&number1, &number2);
	return s;
}
/*************PART2*************/
/* takes homework and lab grades from user */
int take_grades(int arr[]);
/* takes midterm and final grades from user */
int take_exam_grades(int arr[]); 

//calculates homework average and returns it
double calculate_homework(int arr[]); 
//calculates lab average and returns it
double calculate_lab(int arr[]);
//calculates homework's, lab's, midterm and final's last average and returns it
double calculate_all(int hw_average, int arr[], int lab_average);

int take_grades(int arr[]) {
	int i=0;
	/* grade number is 10 and takes from user while the number of grades is 10 */
	while(i<10) {
		printf("grade %d: ", i+1);
		scanf("%d", &arr[i]);
		i++;
	}
	return 1;
}
int take_exam_grades(int arr[]) {
	/* takes midterm grade from user and assigns to the array */
	printf("midterm grade:  ");
	scanf("%d", &arr[0]);
	/* takes final grade from user and assigns to the array */
	printf("final grade:  ");
	scanf("%d", &arr[1]);
	return 1;
}
double calculate_homework(int arr[]) {
	int i=0;
	double average=0.0;
	/*calculates the average of homework grades*/
	for(i=0; i<10; i++){
		average+=arr[i];
	}
	average=average/10.0;
	average = (average*10.0)/100.0;
	return average;
}
double calculate_lab(int arr[]) {
	int i=0;
	double average=0.0;
	/* claculates the average of lab grades */
	for(i=0; i<10; i++){
		average+=arr[i];
	}
	average=average/10.0;
	average = (average*20.0)/100.0;
	return average;
}
double calculate_all(int hw_average, int arr[], int lab_average) {
	/* calculates the last sum of homework, lab, midterm and final grades */
	double midterm_average = (arr[0]*30.0)/100.0;
	double final_average = (arr[1]*40.0)/100.0;
	return (hw_average+lab_average+midterm_average+final_average);
}

int x=0;

void menu(){
	/* prints on screen menu and takes user's choice */
	printf("***** MENU *****\n");
	printf("1. Part1-Calculator\n");
	printf("2. Part2-Calculate Grade\n");
	printf("3. Part3-Diamond\n");
	printf("4. Exit\n");
	printf("Choice: ");
	scanf("%d", &x);
	/* if user's choice is not valid, again and again asks the user */
	/* if user choice the others, the game will start */
	switch(x){
		case 1:
			printf("don't use 'enter', write same line with white spaces. like '+ 12 23'\n");
			printf("to add --> +\n");
			printf("to sub --> -\n");
			printf("to mult --> *\n");
			printf("to div --> /\n");
			printf("to power --> **\n");
			printf("to mod --> %%\n");
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			while( x!=1 && x!=2 && x!=3 && x!=4 ){
				printf("This is an invalid choice. Try again!.\n");
				printf("***** MENU *****\n");
				printf("1. Part1-Calculator\n");
				printf("2. Part2-Calculate Grade\n");
				printf("3. Part3-Diamond\n");
				printf("4. Exit\n");
				printf("Choice: ");
				scanf("%d", &x);
			}
	}
}
/* global somethings:) */
int numbers[] = {0, 0};	
int n1=0, n2=0;
int k=1;

int main (){
	/* firstly goes the menu and user choice some of them. according to user's choice the game will start */
	menu();

/*************PART2*************/
	while(x==2) {
		int lab_arr[10], hw_arr[10], midterm_final_arr[2];
		/* goes the function why takes lab, homework, midterm and final grades from user */
		printf("for lab grades:\n");
		take_grades(lab_arr);
		printf("for homework grades:\n");
		take_grades(hw_arr);
		take_exam_grades(midterm_final_arr);
		/* calculates of grades average for each one */
		double hw_average = calculate_homework(hw_arr);
		printf("%lf\n", hw_average);
		double lab_average = calculate_lab(lab_arr);
		printf("%lf\n", lab_average);
		double average_all = calculate_all(hw_average, midterm_final_arr, lab_average);
		printf("%lf\n", average_all);
		/* calculates the average of these all */
		printf("average all: %lf \n", average_all);
		/* then calls main again */
		main();
	}

/*************PART3*************/
	while(x==3) {
		int height;
		int i, j, k;
		int temp;
		/* takes height from user for diamond */
		printf("height = ");
		scanf("%d", &height);
		/* for increasing sort */
		for(i=0; i<height; i++){
			for(j=0; j<height-1-i; j++){
				printf(" ");
			}
			printf("/");
			temp = j;
			for(j=temp*2; j<(height-1)*2; j++)
				printf("*");
			printf("\\");
			printf("\n");
		}
		temp = j;
		/* for decreasing sort */
		for(i=0; i<height; i++){
			for(j=(height-1); j>height-1-i; j--)
				printf(" ");
			
			printf("\\");
			temp = j;
			for(j=0; j<temp*2; j++)
				printf("*");
			printf("/");
			printf("\n");
		}
		main();
	}



/*************PART1*************/

	char arr[10];

	int i, j;
	int size, toplam=0;
	/* if user's choice is 1 */
	while(x<3){
		/* user's choice takes with gets method */
		i=0;
		k=1;
		gets(arr);
		size = strlen(arr);
		for(i=size-1; i>0; i--){
			j=0;
			/* ignore white spaces */
			while(((int)arr[i])>32){
				j++;
				toplam += (int)(arr[i]%48) * pow((double)10, (double)j-1);
				i--;
			}
			numbers[k] = toplam;
			toplam = 0;
			k--;
		}
		/* if user enters two numbers after operation, assing variables by given order */
		if( k==-1 || k==-2){
			n1 = numbers[0];
			n2 = numbers[1];
		}
		/* if user enters one number after operation, assing variable by last one */
		else{
			n2 = numbers[1];
		}

		for(i=0; i<size; i++){
			/* if operator is '*' */
			if((int)arr[i] == 42 && (int)arr[i+1] == 32){
				numbers[0] = doit( mult, n1, n2);
				n1=numbers[0];
				printf("%d \n", numbers[0]);
				break;
			}
			else if((int)arr[i] == 42 && (int)arr[i+1] == 42){
				/* if operator is '**' */
				numbers[0] = doit( power, n1, n2);
				n1=numbers[0];
				printf("%d \n", numbers[0]);
				break;
			}
			if((int)arr[i] == 37 && (int)arr[i+1] == 32){
				/* if operator is '*' */
				numbers[0] = doit( mod, n1, n2);
				n1=numbers[0];
				printf("%d \n", numbers[0]);
				break;
			}
			else if((int)arr[i] == 43 && (int)arr[i+1] == 32){
				/* if operator is '+' */
				numbers[0] = doit( add, n1, n2);
				n1=numbers[0];
				printf("%d \n", numbers[0]);
				break;
			}
			else if((int)arr[i] == 45 && (int)arr[i+1] == 32){
				/* if operator is '-' */
				numbers[0] = doit( sub, n1, n2);
				n1=numbers[0];
				printf("%d \n", numbers[0]);
				break;	}
			else if((int)arr[i] == 47 && (int)arr[i+1] == 32){
				/* if operator is '/' */
				numbers[0] = doit( div, n1, n2);
				n1=numbers[0];
				printf("%d \n", numbers[0]);
				break;
			}
		}
		x++;
	}
	/* then calls the main */
	main();
	return 0;
}