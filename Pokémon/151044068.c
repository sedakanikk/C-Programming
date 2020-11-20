#include <stdio.h>
#include <math.h>

#define PI 3

#define SQUARE 1
#define RECTENGULAR 2
#define CIRCULAR 3

#define RED 0
#define YELLOW 1
#define BLUE 2
#define BLACK 3
#define WHITE 4

double CreateBody(int shape);
int SetColor(int color);
double LoadMoves(int shape, double body_size);
int SetAttackPower(int lower_bound, int upper_bound);
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power);

/*takes the edge or edges from user and calculates the area of the shape*/
double CreateBody(int shape)
{
	double area;
	double edge1, edge2;
	//if the shape is square
	if(shape == 1){
		printf("Edge is: ");
		scanf("%lf", &edge1);
		area = edge1*edge1;
	}
	//if the shape is rectangle
	else if(shape == 2){
		printf("Edge1 is: ");
		scanf("%lf", &edge1);
		printf("Edge2 is: ");
		scanf("%lf", &edge2);
		area = edge1*edge2;
	}
	//if the shape is circle
	else if(shape == 3){
		printf("Radius is: ");
		scanf("%lf", &edge1);
		area = PI*edge1*edge1;
	}
	return area;
}
/*takes color number as parameter and returns the code number of color*/
int SetColor(int color)
{
	if(color>0 && color<1000)
		return (color%5);
	return 1;
}
/*takes shape and the area and returns the perimeter of the shape*/
double LoadMoves(int shape, double body_size){
	//if the shape is square
	if(shape == SQUARE){
		body_size = sqrt(body_size)*4;
	}
	//if the shape is rectangle
	else if(shape == RECTENGULAR){
		body_size = (5*2) + ((body_size/5)*2); 
	}
	//if the shape is circle
	else if(shape == CIRCULAR){
		body_size = 2*PI*sqrt(body_size/PI);
	}
	return body_size;
}
/*takes two numbers and creates random number to return the attack power*/
int SetAttackPower(int lower_bound, int upper_bound){
	int attack_power;
	attack_power = rand();
	//if the attack_number smaller than lower_bound and bigger than upper_bound, something is wrong, create new one and do it until the random number is useful
	while( (attack_power<lower_bound || attack_power>upper_bound) )
		attack_power = rand();
	return attack_power;
}
/*takes all the thing and prints the shape and texts*/
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power){
	int i, j, edge1, edge2;
	int count, c;
	//if the shape is square
	if(shape == SQUARE){
		//the edge is square root of the area
		edge1 = sqrt(body_size);
		//prints Xs on screen from 0 to edge's size
		for(i=0; i<edge1; i++){
			for(j=0; j<edge1; j++)
				printf("X");
		printf("\n");
		}
	}
	//if the edge is rectangle
	else if(shape == RECTENGULAR){
		//edge1 is 5
		edge1 = 5;
		//edge2 is area/edge1
		edge2 = body_size/edge1;
		//prints Xs on screen from 0 to edges's size
		for(i=0; i<edge1; i++){
			for(j=0; j<edge2; j++)
				printf("X");
		printf("\n");
		}
	}
	//if the shape is circle
	else if(shape == CIRCULAR){
		//the radius is square root of area/PI
		edge1 = sqrt(body_size/PI);
		//if the radius is even
		if(edge1%2 == 0){
			//for leading tabs for the first line decreasing
			for(i=1; i<(edge1/2); i++)
				printf("	");
			//for leading white spaces for the first line
			printf("    ");
			//first and only X from first line
			printf("X");
			//next line
			printf("\n");
			//prints the X and tabs out of first line 
			for(i=1; i<edge1/2+1; i++){
				count = 0;
				//for every line, as line number increases, leading tabs decreasing. so starts from the i to same point(edge1/2)
				for(j=i; j<edge1/2; j++){
					printf("	");
					count++;
				}
				//prints the first X
				printf("X");
				if(i != 0){
					//prints the tabs after first Xs of line
					for( c=0; c<((edge1/2)-count)*2-1; c++ ) {
						printf("	");
					}
					//then prints the last Xs of line
					printf("X");
				}
				//next line
				printf("\n");
			}
			//for leading tabs for the first line increasing
			for(i=1; i<edge1/2; i++){
				if(i != 0){
					//for every line, as line number increases, leading tab increasing. so starts from 0 to same point(count) prints tabs
					for( c=0; c<=count; c++ ) {
						printf("	");
					}
					//prints the first Xs after tabs
					printf("X");
				}
				count++;
				//prints the tabs after first Xs of line
				for(j=i-1; j<edge1-count-2; j++){
					printf("	");
				}
				//then prints the last Xs of line
				printf("X");
				//next line
				printf("\n");
			}
			//for the last X, prints tabs for the last line increasing 
			for(i=1; i<(edge1/2); i++)
				printf("	");
			//for leading white spaces for the last line
			printf("    ");
			//first and only X from last line
			printf("X");
			//next line
			printf("\n");
		}
		//if the radius is odd
		else{
			//for leading tabs for the first line decreasing
			for(i=1; i<=(edge1/2); i++)
				printf("	");
			//first and only X from first line
			printf("X");
			//next line
			printf("\n");
			//prints the X and tabs out of first line 
			for(i=1; i<edge1/2+1; i++){
				count = 0;
				//for every line, as line number increases, leading tabs decreasing. so starts from the i to same point(edge1/2)
				for(j=i; j<edge1/2; j++){
					printf("	");
					count++;
				}
				//prints the first X
				printf("X");
				if(i != 0){
					//prints the tabs after first Xs of line
					for( c=0; c<=((edge1/2)-count)*2-1; c++ ) {
						printf("	");
					}
					//then prints the last Xs of line
					printf("X");
				}
				//next line
				printf("\n");
			}
			//for leading tabs for the first line increasing
			for(i=1; i<edge1/2; i++){
				if(i != 0){
					//for every line, as line number increases, leading tab increasing. so starts from 0 to same point(count) prints tabs
					for( c=0; c<=count; c++ ) {
						printf("	");
					}
					//prints the first Xs after tabs
					printf("X");
				}
				count++;
				//prints the tabs after first Xs of line
				for(j=i-1; j<=edge1-count-3; j++){
					printf("	");
				}
				//then prints the last Xs of line
				printf("X");
				//next line
				printf("\n");
			}
			//for the last X, prints tabs for the last line increasing 
			for(i=1; i<=(edge1/2); i++)
				printf("	");
			//for leading white spaces for the last line
			printf("X");
			//next line
			printf("\n");
		}
	}


/**********************************************************************/
/*prints the things on screen according to the options.*/
	if(shape == 1){
		printf("Name: Square Pokémon\n");
		printf("Size: %.2lf\n", body_size);
	}
	else if(shape == 2){
		printf("Name: Rectangular Pokémon\n");
		printf("Size: %.2lf\n", body_size);
	}
	else if(shape == 3){
		printf("Name: Circular Pokémon\n");
		printf("Size: %.2lf\n", body_size);
	}

	if(color == 0)
		printf("Color: Red\n");
	else if(color == 1)
		printf("Color: Yellow\n");
	else if(color == 2)
		printf("Color: Blue\n");
	else if(color == 3)
		printf("Color: Black\n");
	else if(color == 4)
		printf("Color: White\n");
	
	printf("Move: %.2lf\n", move_length);
	printf("Attack Power: %d\n", attack_power);
/**********************************************************************/
}

int main ()
{
	int shape, color, attack_power;
	double size_of_body, move_length;
	shape = CIRCULAR;
	size_of_body = CreateBody(shape);
	color = 798;
	color = SetColor(color);
	move_length = LoadMoves(shape, size_of_body);
	attack_power = SetAttackPower (0, 150);
	ShowPokemon(shape, size_of_body, color, move_length, attack_power);
	return 0;
}
