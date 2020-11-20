#include <stdio.h>
#include <time.h>

#define TRIAL 10

/* these are functions */
void menu();
int make_a_guess (int trial, int min, int max);
void show_scores(int score_human, int score_program);
void draw_hourglass (int height);
void draw_mountain_road (int length, int max_radius);


/* to use every function */
int score = 0;
int oyun_sayisi = 0;
int choice = 0;
int s=0;


/****************************Part1 Function****************************/	

void menu(){
	printf("***** MENU *****\n");
	printf("1. Play Lucky Number\n");
	printf("2. Draw Hourglass\n");
	printf("3. Draw Mountain Road\n");
	printf("4. Exit\n");
	printf("Choice: ");
	scanf("%d", &choice);
	/* if user's choice is not valid, again and again asks the user */
	/* if user choice the others, the game will start */
	switch(choice){
		case 1:
			oyun_sayisi++;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			while( choice!=1 && choice!=2 && choice!=3 && choice!=4 ){
				printf("This is an invalid choice. Try again!.\n");
				printf("***** MENU *****\n");
				printf("1. Play Lucky Number\n");
				printf("2. Draw Hourglass\n");
				printf("3. Draw Mountain Road\n");
				printf("4. Exit\n");
				printf("Choice: ");
				scanf("%d", &choice);
			}
	}
}

/****************************Part2 Functions****************************/	
/* keep the datas which takes from user or random, and prints on screen this values and takes one guess from user and returns it*/
int make_a_guess (int trial, int min, int max){
	int guess;
	printf("(Trial: %d) Make a guess between %d and %d: ", trial, min, max);
	scanf("%d", &guess);

	return guess;
}

/* to print results on screen */
void show_scores(int score_human, int score_program){
	printf("Your Score: %d Program Score: %d\n", score_human, score_program);
}

/****************************Part3 Function****************************/	
/* prints on screen hourglass */
void draw_hourglass (int height){
	int i, j, k;
	int temp;
	/* prints for decreasing number of star(*) and increasing number of white space except to stay last one in line on screen */
	for(i=0; i<=height-2; i+=2){
		for(j=height; j>height-i;j-=2){
			printf(" ");
		}
		for(j=0; j<height-i;j++){
			printf("*");
		}
		printf("\n");
	}
	/* last point is temp */
	temp=i;
	/* prints from zero to last point, increasing number of star(*) and decreasing number of white space on screen */
	for(i=0; i<=temp/2; i++){
		for(j=0; j<temp/2-i;j++){
			printf(" ");
		}
		for(k=0; k<height-(j*2); k++){
			printf("*");
		}
		printf("\n");
	}
}

/****************************Part4 Function****************************/	
/* prints a draw mountain road on screen */
void draw_mountain_road (int length, int max_radius){
	int i, j, k, temp=0, temp1=0;
	/* in homework file, road figures begin with / and how can I do that? */
	/* in this form I could do that :) */
	if((s+1)%2 == 1){
		temp1 = temp;
		/* to print white spaces on screen*/
		for(i=0; i<max_radius; i++)
			printf(" ");
		/* to make bend */
		printf("|\n");
		/* to print white spaces and then slashes(/) on screen */
		for(i=0; i<length; i++){
			for(j=0; j<max_radius-i-1;j++){
				printf(" ");
			}
			printf("/");
			printf("\n");
		}
		temp=j;
		/* again to print some white spaces in screen */
		for(i=0; i<temp-1; i++){
			printf(" ");
		}
		/* to make bend */
		printf("|");
		printf("\n");
		temp=i;
		/* again to print some white spaces and back slashes(\) in screen */
		for(i=0; i<length; i++){
			for(j=max_radius-1; j>=length-i;j--){
				printf(" ");
			}
			printf("\\");
			printf("\n");
		}
		temp = j;
	}
	else{
		if(s != 1){
			/* to make bend */
			for(i=0; i<max_radius; i++)
				printf(" ");
			printf("|\n");
			temp = i;
			/* to print white spaces and then slashes(/) on screen */
			for(i=0; i<length; i++){
				for(j=0; j<temp-i-1;j++){
					printf(" ");
				}
				printf("/");
				printf("\n");
			}
			temp1=j;
			/* to make bend */
			for(i=0; i<temp1-1; i++)
				printf(" ");
			printf("|");
			printf("\n");
			/* again to print some white spaces and back slashes(\) in screen */
			for(i=0; i<length; i++){
				for(j=max_radius-1; j>=length-i;j--){
					printf(" ");
				}
				printf("\\");
				printf("\n");
			}
				temp=i;
			temp = i;

		}
		/* if s is not 1 */
		else{
			/* to print white spaces and then slashes(/) on screen */
			for(i=0; i<length; i++){
				for(j=0; j<max_radius-i-1;j++){
					printf(" ");
				}
				printf("/");
				printf("\n");
			}
			temp1 = j;
			/* to make bend */
			for(i=0; i<temp1-1; i++)
				printf(" ");
			printf("|");
			printf("\n");
			/* again to print some white spaces and back slashes(\) in screen */
			for(i=0; i<length; i++){
				for(j=max_radius-1; j>=length-i;j--){
					printf(" ");
				}
				printf("\\");
				printf("\n");
			}
				temp=i;
			temp = i;
		}
	}
}


int main(){

/******************Part1******************/	
	menu();

/******************Part2******************/	
	/* if user's choice is 1 and user wants to continue the game */
	while(choice == 1) {
		int trial = 1;
		int count;
		int lucky_number, guess=1;
		int num1=1024, num2=1;
		int distance=1;
		//gets random lucky number
		srand(time(NULL));
		lucky_number = rand()%1023+1;
		printf("%d\n",lucky_number);
		/* the game continues until trial number is equal to given global number and distance is smaller than 0 */
		while(trial<=TRIAL && distance>0){
			/* the function is calling */
			guess = make_a_guess(trial, num2, num1);
			/* if user's guess's is smaller than lucky number lower bound will be guess */
			/* if user's guess's is bigger than lucky number upper bound will be guess */	
			if(guess<lucky_number){
				num2 = guess;
			}
			else{
				num1 = guess;
			}

			/* the distance this */
			distance = lucky_number-guess;
			if(distance<0)
				distance=(-1)*distance;
			/* if the distance is between the given values, according to these values, distance will be print on screen */
			if(distance>=512 &&  distance<=1024)
				printf("Distance is 10.\n");
			else if(distance>=256 &&  distance<=511)
				printf("Distance is 9.\n");
			else if(distance>=128 &&  distance<=255)
				printf("Distance is 8.\n");
			else if(distance>=64 &&  distance<=127)
				printf("Distance is 7.\n");
			else if(distance>=32 &&  distance<=63)
				printf("Distance is 6.\n");
			else if(distance>=16 &&  distance<=31)
				printf("Distance is 5.\n");
			else if(distance>=8 &&  distance<=15)
				printf("Distance is 4.\n");
			else if(distance>=4 &&  distance<=7)
				printf("Distance is 3.\n");
			else if(distance>=2 &&  distance<=3)
				printf("Distance is 2.\n");
			else if(distance==1)
				printf("Distance is 1.\n");
			else if(distance==0)
				printf("Distance is 0. You win!\n");

			++trial;
			/* if user wins the game, its score will increase */
			if(distance == 0){
				score++;
			}
			/* if the game is over, shows the scores and get the menu on screen */
			if(trial-1 == TRIAL || distance == 0){
				show_scores(score, oyun_sayisi-score);
				menu();
			}
		}
	}

/******************Part3******************/	
	/* if user's choice is 2 and user wants to continue the game */
	while(choice == 2) {
		int height;
		/* takes odd height value from user and calls the function which draws a hour glass */
		printf("Height = ");
		scanf("%d", &height);
		while(height%2 != 1){
			printf("Not valid. Enter valid height!\n");
			printf("Height = ");
			scanf("%d", &height);
		}
		draw_hourglass(height);
		menu();
	}
/******************Part4******************/	
	int length;
	int n;
	int max_radius;
	/* if user's choice is 3 and user wants to continue the game */
	while(choice == 3) {
		/* takes a number from user for N and R until max radius value will be acceptable*/
		printf("N = ");
		scanf("%d", &n);
		printf("R = ");
		scanf("%d", &max_radius);
		while(max_radius<=0){
			printf("wrong radius\n");
			printf("R = ");
			scanf("%d", &max_radius);
		}
		s=0;
		/* lengt is a rondom number, and create a lengt and calls the function */
		while(s<n){
			length = rand()%(max_radius-1)+1;
			s++;
			draw_mountain_road(length, max_radius);
		}
		menu();
	}
	return 0;
}