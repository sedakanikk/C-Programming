#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18

int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n') {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}

/* my codes start from here */
void puzzle_map(char grid[DICT_SIZE][DICT_SIZE], char *dict[], int coord[DICT_SIZE][4]) {
	int i, j;
	int random;
	int j_coord, m=0, i_coord;
	/* assigned letters randomly to grid */
	for(i=0; i<DICT_SIZE; i++) {
		for(j=0; j<DICT_SIZE; j++) {
			random = rand()%26+97;
			grid[i][j] = random;
		}
	}
	/* assigns the words in the file to the specified coordinates */
	for(i=0; i<DICT_SIZE; i++) {
		if(coord[i][0]==coord[i][2]) { 
		// word's letters are in the same line
			j_coord=coord[i][1];
			while(j_coord<coord[i][3]) {
				grid[coord[i][0]][j_coord] = dict[i][m++];
				j_coord++;
			}
			while(j_coord>coord[i][3]) {
				grid[coord[i][0]][j_coord] = dict[i][m++];
				j_coord--;
			}
			if(j_coord==coord[i][3]) {
				grid[coord[i][0]][j_coord] = dict[i][m];
			}
			m=0;
		}
		else if(coord[i][1]==coord[i][3]) {
		// word's letters are in the same row
			i_coord=coord[i][0];
			while(i_coord<coord[i][2]) {
				grid[i_coord][coord[i][1]] = dict[i][m++];
				i_coord++;
			}
			while(i_coord>coord[i][2]) {
				grid[i_coord][coord[i][1]] = dict[i][m++];
				i_coord--;
			}
			if(i_coord==coord[i][2]) {
				grid[i_coord][coord[i][1]] = dict[i][m];
			}
			m=0;
		}
		else if(coord[i][0]!=coord[i][2] && coord[i][1]!=coord[i][3]) {
		// word's letters are horizontal
			i_coord=coord[i][0];
			j_coord=coord[i][1];
			while(i_coord<coord[i][2] && j_coord<coord[i][3]) {
				/* if both them i and j values are increasing */
				grid[i_coord][j_coord] = dict[i][m++];
				i_coord++;
				j_coord++;
			}
			while(i_coord>coord[i][2] && j_coord>coord[i][3]) {
				/* if both them i and j values are decreasing */
				grid[i_coord][j_coord] = dict[i][m++];
				i_coord--;
				j_coord--;
			}
			while(i_coord<coord[i][2] && j_coord>coord[i][3]) {
				/* if i value is increasing and j value decreasing */
				grid[i_coord][j_coord] = dict[i][m++];
				i_coord++;
				j_coord--;
			}
			while(i_coord>coord[i][2] && j_coord<coord[i][3]) {
				/* if i value is decreasing and j value increasing */
				grid[i_coord][j_coord] = dict[i][m++];
				i_coord--;
				j_coord++;
			}
			if(i_coord==coord[i][2] && j_coord==coord[i][3]) {
				//assings the last thing
				grid[i_coord][j_coord] = dict[i][m];
			}
			m=0;
		}
	}
}
/* to see the grid */
void print_grid(char grid[DICT_SIZE][DICT_SIZE]) {
	int i, j;
	for(i=0; i<DICT_SIZE; i++) {
		for(j=0; j<DICT_SIZE; j++) {
			printf("%c ", grid[i][j]);
		}
		printf("\n");
	}
}
/* the game starts */
int game_play(char grid[DICT_SIZE][DICT_SIZE], char *dict[]) {
	int i, j, r, c, k, temp=0;
	char word[WORD_LEN];
	int size=0;
	int count=0;	

	printf("row: "); //takes i value
	scanf("%d", &r);
	printf("column: ");//takes j value
	scanf("%d", &c);
	printf("word: ");//takes word 
	scanf("%s", word);

	i=0;
	//calculates word's length
	while(word[i] != '\0'){
		size++;
		i++;
	}
	k=0;
	//if given coordinates are the first letter of the word
	if(grid[r][c] == word[k]) {
		//different r but same c values, vertical
		for(i=r; i<DICT_SIZE; i++) {
			if(grid[i][c] == word[k] && k<=size) {
				k++;
				temp=1;
			}
			if(k==size+1)
				k=size;
		}
		if(k==size && temp==1) {
			k=k-size;
			while(k<size) {
				grid[r++][c] = word[k]-32;
				k++;
			}
			count++;
			k=0;
		}
		//different r but same c values, vertical
		for(i=r+1; i<DICT_SIZE; i++) {
			if(grid[i][c] == word[k] && k<=size) {
				k++;
				temp=2;
			}
			if(k==size+1)
				k=size;
		}
		if(k==size && temp==2) {
			k=k-size;
			while(k<size) {
				grid[r++][c] = word[k]-32;
				k++;
			}
			count++;
		}
		//same r but different c, so horizontal
		for(j=c+1; j<DICT_SIZE; j++) {
			if(grid[r][j] == word[k] && k<=size) {
				k++;
				temp=3;
			}
			if(k==size+1)
				k=size;
		}
		if(k==size && temp==3) {
			k=k-size;
			while(k<size) {
				grid[r][c++] = word[k]-32;
				k++;
			}
			count++;
		}
		//same r and same c, diagonal
		for(i=r+1, j=c+1; i<DICT_SIZE, j<DICT_SIZE; i++, j++) {
			if(grid[i][j] == word[k] && k<=size) {
				k++;
				temp=4;
			}
			if(k==size+1)
				k=size;
		}
		if(k==size && temp==4) {
			k=k-size;
			while(k<size) {
				grid[r++][c++] = word[k]-32;
				k++;
			}
			count++;
		}
		k=0;
		//different r but same c, diagonal
		for(i=r, j=c; i>=0, j<DICT_SIZE; i--, j++) {
			if(grid[i][j] == word[k] && k<=size) {
				k++;
				temp=5;
			}
			if(k==size+1)
				k=size;
		}
		if(k==size && temp==5) {
			k=0;
			while(k<size) {
				grid[r--][c++] = word[k]-32;
				k++;
			}
			count++;
		}
		if(k!=size)
			temp=0;
	}
	//if given coordinates are the last letter of the word
	if(grid[r][c] == word[size-1] && temp!=1 && temp!=2 && temp!=3 && temp!=4 && temp!=5) {
		k=size;
		//different r but same c, vertical
		for(i=r; i>=0; i--) {
			if(grid[i][c] == word[k-1] && k>=0) {
				k--;
				temp=11;
			}
			if(k==-1)
				k=0;
		}
		if(k==0 && temp==11) {
			k=size-1;
			while(k>=0) {
				grid[r--][c] = word[k]-32;
				k--;
			}
			count++;
		}
		k=size;
		//different c but same r, horizontal
		for(j=c; j>=0; j--) {
			if(grid[r][j] == word[k-1] && k>=0) {
				k--;
				temp=12;
			}
			if(k==-1)
				k=0;
		}
		if(k==0 && temp==12) {
			k=size-1;
			while(k>=0) {
				grid[r][c--] = word[k]-32;
				k--;
			}
			count++;
		}
		k=size;
		//different i and j values, horizontal
		for(i=r, j=c; i>=0, j>=0; i--, j--) {
			if(grid[i][j] == word[k-1] && k>=0) {	
				k--;
				temp=13;
			}
			if(k==-1)
				k=0;
		}
		if(k==0 && temp==13) {
			k=size-1;
			while(k>=0) {
				grid[r--][c--] = word[k]-32;
				k--;
			}
			count++;
		}
		k=0;
		//different i and j values, horizontal
		for(i=r, j=c; i<DICT_SIZE, j<DICT_SIZE; i++, j++) {
			if(grid[i][j] == word[k] && k<size) {
				k++;
				temp=14;
			}
		}
		if(k==size-1 && temp==14) {
			while(k>=0) {
				grid[r++][c++] = word[k]-32;
				k--;
			}
			count++;
		}
		k=0;
		//different i and j values, horizontal
		for(i=r, j=c; i<DICT_SIZE, j>=0; i++, j--) {
			if(grid[i][j] == word[k] && k<size) {
				k++;
				temp=15;
			}
		}
		if(k==size-1 && temp==15) {
			while(k>=0) {
				grid[r++][c--] = word[k]-32;
				k--;
			}
			count++;
		}
	}
	//if user writes exit, the game will finishes
	if(word[0]=='e' && word[1]=='x' && word[2]=='i' && word[3]=='t' && temp==0)
		return -1;
	return count;
}

int main(){
	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4];    
    char line[LINE_LEN];
	FILE *fp = fopen("word_hunter.dat", "r");
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);

	//print_dictionary(dict);
	//print_coord(coord);
	
	// WRITE HERE...

	int temp=0, count=0;
	char grid[DICT_SIZE][DICT_SIZE];
	
	puzzle_map(grid, dict, coord);
	do {
		print_grid(grid);
		temp=game_play(grid, dict);
		if(temp==1)
			count++;
		if(temp==-1)
			return 0;
	}while(count<DICT_SIZE-1);
	print_grid(grid);
		
	return 0;
}






