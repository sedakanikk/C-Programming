#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 250
#define MAX_NUM_OF_ROWS 100

void numberofRows();
void bulma(char a[MAX_NUM_OF_ROWS][MAX_LENGTH]);

/* row sayısını hesaplayacak olan ve a arrayinin ilk boyutuna bunu atacak olan fonksiyon.
	Eğer verilen input.txt dosyası boş değilse if döngüsüne girerek her whitespace gördüğünde while döngüsüne girecek ve 
	i'yi arttırarak satır sayısını a'nın ilk boyutu olan i'sine atmış olacak.
	İlk boyutuna satırları atarken ikinci boyutuna da satırlardaki karakterleri teker teker atmış olacak.*/
void numberofRows(){
	int i=0;
	char a[MAX_NUM_OF_ROWS][MAX_LENGTH];
	FILE *in;
	in=fopen("input.txt","r");

	if( (in=fopen("input.txt","r")) != NULL ){
		while(!feof(in)){
			fscanf(in, "%s", a[i]);
			i++;
		}
	}
	fclose(in);
	bulma(a);
}
/* Ödevde verilen kelimelerin horizontal veya vertical olup olmadığını buluyor.
for döngülerini a arrayinin iki boyutu için başlatıp ilk önce aranan kelimenin her harfi için 
kelimelerin yatay sırayla bulunduğu ikinci boyuta kelimenin her harfi için artan j sayısınca bakacak. 
Eğer yataysa; kelimeyi, kelimenin bulunduğu yeri ve yataylığını ekrana yazdıracak
Eğer kelime yatayda değilse, dikeyde aramak için a arrayinde satırların sırasıyla bulunduğu ilk boyutta kelimenin her harfi için 
artan i sırasınca bakacak.
Eğer dikeyse; kelimeyi, kelimenin bulunduğu yeri ve dikeyliğini ekrana yazdıracak */
void bulma(char a[MAX_NUM_OF_ROWS][MAX_LENGTH]){
	int i=0, j=0;

	for(i=0;i<MAX_NUM_OF_ROWS;i++){
		for(j=0;j<MAX_LENGTH;j++){
			if(a[i][j]=='X' && a[i][j+1]=='a' && a[i][j+2]=='n' && a[i][j+3]=='t' && a[i][j+4]=='h' && a[i][j+5]=='o' && a[i][j+6]=='s'){
				printf("Xanthos (%d,%d) Horizontal\n",i+1,j+1);
			}
			else if(a[i][j]=='X' && a[i+1][j]=='a' && a[i+2][j]=='n' && a[i+3][j]=='t' && a[i+4][j]=='h' && a[i+5][j]=='o' && a[i+6][j]=='s'){
				printf("Xanthos (%d,%d) Vertical\n",i+1,j+1);
			}
		}
	}
	for(i=0;i<MAX_NUM_OF_ROWS;i++){
		for(j=0;j<MAX_LENGTH;j++){
			if(a[i][j]=='P' && a[i][j+1]=='a' && a[i][j+2]=='t' && a[i][j+3]=='a' && a[i][j+4]=='r' && a[i][j+5]=='a'){
				printf("Patara (%d,%d) Horizontal\n",i+1,j+1);
			}
			else if(a[i][j]=='P' && a[i+1][j]=='a' && a[i+2][j]=='t' && a[i+3][j]=='a' && a[i+4][j]=='r' && a[i+5][j]=='a'){
				printf("Patara (%d,%d) Vertical\n",i+1,j+1);
			}
		}
	}
	for(i=0;i<MAX_NUM_OF_ROWS;i++){
		for(j=0;j<MAX_LENGTH;j++){
			if(a[i][j]=='M' && a[i][j+1]=='y' && a[i][j+2]=='r' && a[i][j+3]=='a'){
				printf("Myra (%d,%d) Horizontal\n",i+1,j+1);
			}
			else if(a[i][j]=='M' && a[i+1][j]=='y' && a[i+2][j]=='r' && a[i+3][j]=='a'){
				printf("Myra (%d,%d) Vertical\n",i+1,j+1);
			}
		}
	}
	for(i=0;i<MAX_NUM_OF_ROWS;i++){
		for(j=0;j<MAX_LENGTH;j++){
			if(a[i][j]=='A' && a[i][j+1]=='r' && a[i][j+2]=='y' && a[i][j+3]=='c' && a[i][j+4]=='a' && a[i][j+5]=='n' && a[i][j+6]=='d' && a[i][j+7]=='a'){
				printf("Arycanda (%d,%d) Horizontal\n",i+1,j+1);
			}
			else if(a[i][j]=='A' && a[i+1][j]=='r' && a[i+2][j]=='y' && a[i+3][j]=='c' && a[i+4][j]=='a' && a[i+5][j]=='n' && a[i+6][j]=='d' && a[i+7][j]=='a'){
				printf("Arycanda (%d,%d) Vertical\n",i+1,j+1);
			}
		}
	}
	for(i=0;i<MAX_NUM_OF_ROWS;i++){
		for(j=0;j<MAX_LENGTH;j++){
			if(a[i][j]=='P' && a[i][j+1]=='h' && a[i][j+2]=='a' && a[i][j+3]=='s' && a[i][j+4]=='e' && a[i][j+5]=='l' && a[i][j+6]=='i' && a[i][j+7]=='s'){
				printf("Phaselis (%d,%d) Horizontal\n",i+1,j+1);
			}
			else if(a[i][j]=='P' && a[i+1][j]=='h' && a[i+2][j]=='a' && a[i+3][j]=='s' && a[i+4][j]=='e' && a[i+5][j]=='l' && a[i+6][j]=='i' && a[i][j+7]=='s'){
				printf("Phaselis (%d,%d) Vertical\n",i+1,j+1);
			}
		}
	}
}
int main(){
	numberofRows();
	return 0;
}