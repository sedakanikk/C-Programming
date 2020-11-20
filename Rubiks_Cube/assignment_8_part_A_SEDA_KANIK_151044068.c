#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void okuma();
void faces(int size, char komutlar[255], int sayilar[255]);

void okuma(){

	int i, j, cube_size;
	char komutlar[255];
	int sayilar[255];

	FILE *input;
	input=fopen("commands.txt","r");

	i=0;
	j=1;
	/* Verilen dosyadadaki verileri komutlar ve sayılar adlı arraylere atıyor.
	Sayılar arrayinin ilk elemanı size olacağı ve tek bir defa farklı düzende okuma yapacağı için öncelikle okunarak 
	arraya atıldı. Sonraki face sayıları ve column/row sayıları atıldı. */
	if((input=fopen("commands.txt","r")) != NULL ){
			fscanf(input,"%d",&sayilar[0]);
			while(!feof(input)){
				fscanf(input,"%s %d %s %d %s",&komutlar[i],&sayilar[j],&komutlar[i+1],&sayilar[j+1],&komutlar[i+2]);
			i=i+2;
			i++;
			j=j+1;
			j++;
			}
			komutlar[i-1]='\0';
			sayilar[j-1]='\0';
	}

	cube_size = sayilar[0];

	fclose(input);
	faces(cube_size, komutlar, sayilar);
}

/* Asıl işlemi yapacak olan foksiyon. */
void faces(int size, char komutlar[255], int sayilar[255]){

	int i, j, k, l;
	/* Önceden dosyadan okunan size uzunluğunda, her face için iki boyutlu arrayler tanımlandı. 
	Row/column değişimleri sırasında kolaylık olması için bir boş array tanımlandı.*/
	int face0[size][size], face1[size][size], face2[size][size], 
		face3[size][size], face4[size][size], face5[size][size], face_bos[size][size];

	FILE *output;
	output=fopen("result.txt","w");

	/*Her face için her row ve column için kendi face numaraları atandı.
	Boş olan arraye de random bir değer atandı.*/
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			face0[i][j]=0;
			face1[i][j]=1;
			face2[i][j]=2;
			face3[i][j]=3;
			face4[i][j]=4;
			face5[i][j]=5;
			face_bos[i][j]=9;
		}
	}
	/* Sayılar arrayinin 0. elemanı size olduğu için k değeri 1'den başladı */
	k=1;
	for(j=0;j<255;j++){
		/* Kısaltmalı ifade kullandım. bu döngü rotate .. row .. right olup olmadığını kontrol ediyor. */
		if(komutlar[j]=='r' && komutlar[j+1]=='r' && komutlar[j+2]=='r'){
			/* Sayılar arrayinde görülen ilk sayı face id olduğu için if döngülerinde onun kontrolü yapılıyor. */
			/* Eğer face id değerleri koşulu sağlıyorsa bu döngülere girilecek. 
			Sonrasındaki sayının bulunduğu konumdan (row konumu) başlayarak size boyunca yer değiştirecek. */
			if(sayilar[k]==0){
				for(l=0;l<size;l++){

					face_bos[sayilar[k+1]][l]=face0[sayilar[k+1]][l];

					face0[sayilar[k+1]][l]=face3[sayilar[k+1]][l];
					face3[sayilar[k+1]][l]=face2[sayilar[k+1]][l];
					face2[sayilar[k+1]][l]=face1[sayilar[k+1]][l];
					face1[sayilar[k+1]][l]=face_bos[sayilar[k+1]][l];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==1){
				for(l=0;l<size;l++){
	
					face_bos[sayilar[k+1]][l]=face1[sayilar[k+1]][l];

					face1[sayilar[k+1]][l]=face0[sayilar[k+1]][l];
					face0[sayilar[k+1]][l]=face3[sayilar[k+1]][l];
					face3[sayilar[k+1]][l]=face2[sayilar[k+1]][l];
					face2[sayilar[k+1]][l]=face_bos[sayilar[k+1]][l];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==2){
				for(l=0;l<size;l++){

					face_bos[sayilar[k+1]][l]=face2[sayilar[k+1]][l];

					face2[sayilar[k+1]][l]=face1[sayilar[k+1]][l];
					face1[sayilar[k+1]][l]=face0[sayilar[k+1]][l];
					face0[sayilar[k+1]][l]=face3[sayilar[k+1]][l];
					face3[sayilar[k+1]][l]=face_bos[sayilar[k+1]][l];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==3){
				for(l=0;l<size;l++){

					face_bos[sayilar[k+1]][l]=face3[sayilar[k+1]][l];

					face3[sayilar[k+1]][l]=face2[sayilar[k+1]][l];
					face2[sayilar[k+1]][l]=face1[sayilar[k+1]][l];
					face1[sayilar[k+1]][l]=face0[sayilar[k+1]][l];
					face0[sayilar[k+1]][l]=face_bos[sayilar[k+1]][l];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==4){
				for(l=0;l<size;l++){

					face_bos[sayilar[k+1]][l]=face4[sayilar[k+1]][l];

					face4[sayilar[k+1]][l]=face3[l][sayilar[k+1]];
					face3[l][sayilar[k+1]]=face5[size-1-sayilar[k+1]][l];
					face5[size-1-sayilar[k+1]][l]=face1[l][size-1-sayilar[k+1]];
					face1[l][size-1-sayilar[k+1]]=face_bos[sayilar[k+1]][l];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==5){
				for(l=0;l<size;l++){

					face_bos[sayilar[k+1]][l]=face5[sayilar[k+1]][l];

					face5[sayilar[k+1]][l]=face3[l][size-1-sayilar[k+1]];
					face3[l][size-1-sayilar[k+1]]=face4[size-1-sayilar[k+1]][l];
					face4[size-1-sayilar[k+1]][l]=face1[l][sayilar[k+1]];
					face1[l][sayilar[k+1]]=face_bos[sayilar[k+1]][l];
				}
				k=k+1;
				k++;
			}
			j=j+2;
		}
			
		/* Bu döngü rotate .. row .. left olup olmadığını kontrol ediyor. 
		Eğer komutlarda bunların baş harflerini yani rrl'yi görürse bu döngüye giriyor.*/
		else if(komutlar[j]=='r' && komutlar[j+1]=='r' && komutlar[j+2]=='l'){

			/* Face numaralarını kontrol ediyor.*/
			/* Eğer face numaraları koşulu sağlarsa bu döngülere giriyor ve sırasıyla belirli row'u ve 
			buna bağlı row'ları left ediyor. */
			if(sayilar[k]==0){
				for(l=0;l<size;l++){

					face_bos[sayilar[k+1]][l]=face0[sayilar[k+1]][l];

					face0[sayilar[k+1]][l]=face1[sayilar[k+1]][l];
					face1[sayilar[k+1]][l]=face2[sayilar[k+1]][l];
					face2[sayilar[k+1]][l]=face3[sayilar[k+1]][l];
					face3[sayilar[k+1]][l]=face_bos[sayilar[k+1]][l];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==1){
				for(l=0;l<size;l++){

					face_bos[sayilar[k+1]][l]=face1[sayilar[k+1]][l];

					face1[sayilar[k+1]][l]=face2[sayilar[k+1]][l];
					face2[sayilar[k+1]][l]=face3[sayilar[k+1]][l];
					face3[sayilar[k+1]][l]=face0[sayilar[k+1]][l];
					face0[sayilar[k+1]][l]=face_bos[sayilar[k+1]][l];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==2){
				for(l=0;l<size;l++){

					face_bos[sayilar[k+1]][l]=face2[sayilar[k+1]][l];

					face2[sayilar[k+1]][l]=face3[sayilar[k+1]][l];
					face3[sayilar[k+1]][l]=face0[sayilar[k+1]][l];
					face0[sayilar[k+1]][l]=face1[sayilar[k+1]][l];
					face1[sayilar[k+1]][l]=face_bos[sayilar[k+1]][l];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==3){
				for(l=0;l<size;l++){

					face_bos[sayilar[k+1]][l]=face3[sayilar[k+1]][l];

					face3[sayilar[k+1]][l]=face0[sayilar[k+1]][l];
					face0[sayilar[k+1]][l]=face1[sayilar[k+1]][l];
					face1[sayilar[k+1]][l]=face2[sayilar[k+1]][l];
					face2[sayilar[k+1]][l]=face_bos[sayilar[k+1]][l];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==4){
				for(l=0;l<size;l++){

					face_bos[sayilar[k+1]][l]=face4[sayilar[k+1]][l];

					face4[sayilar[k+1]][l]=face1[l][size-1-sayilar[k+1]];
					face1[l][size-1-sayilar[k+1]]=face5[size-1-sayilar[k+1]][l];
					face5[size-1-sayilar[k+1]][l]=face3[l][sayilar[k+1]];
					face3[l][sayilar[k+1]]=face_bos[sayilar[k+1]][l];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==5){
				for(l=0;l<size;l++){

					face_bos[sayilar[k+1]][l]=face5[sayilar[k+1]][l];

					face5[sayilar[k+1]][l]=face1[l][sayilar[k+1]];
					face1[l][sayilar[k+1]]=face4[size-1-sayilar[k+1]][l];
					face4[size-1-sayilar[k+1]][l]=face3[l][size-1-sayilar[k+1]];
					face3[l][size-1-sayilar[k+1]]=face_bos[sayilar[k+1]][l];
				}
				k=k+1;
				k++;
			}
			j=j+2;
		}

		/* Bu döngü rotate .. column .. up olup olmadığını kontrol ediyor. 
		Eğer komutlarda bunların baş harflerini yani rcu'yu görürse bu döngüye giriyor.*/
		else if(komutlar[j]=='r' && komutlar[j+1]=='c' && komutlar[j+2]=='u'){

			/* Face numaralarını kontrol ediyor.*/
			/* Eğer face numaraları koşulu sağlarsa bu döngülere giriyor ve sırasıyla belirli column'ı ve 
			buna bağlı olan column'ları up ediyor. */
			if(sayilar[k]==0){
				for(l=0;l<size;l++){

					face_bos[l][sayilar[k+1]]=face0[l][sayilar[k+1]];

					face0[l][sayilar[k+1]]=face5[l][sayilar[k+1]];
					face5[l][sayilar[k+1]]=face2[size-1-l][size-1-sayilar[k+1]];
					face2[size-1-l][size-1-sayilar[k+1]]=face4[l][sayilar[k+1]];
					face4[l][sayilar[k+1]]=face_bos[l][sayilar[k+1]];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==1){
				for(l=0;l<size;l++){

					face_bos[l][sayilar[k+1]]=face1[l][sayilar[k+1]];

					face1[l][sayilar[k+1]]=face5[sayilar[k+1]][l];
					face5[sayilar[k+1]][l]=face3[l][size-1-sayilar[k+1]];
					face3[l][size-1-sayilar[k+1]]=face4[size-1-sayilar[k+1]][l];
					face4[size-1-sayilar[k+1]][l]=face_bos[l][sayilar[k+1]];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==2){
				for(l=0;l<size;l++){

					face_bos[l][sayilar[k+1]]=face2[l][sayilar[k+1]];

					face2[l][sayilar[k+1]]=face5[l][size-1-sayilar[k+1]];
					face5[l][size-1-sayilar[k+1]]=face0[l][size-1-sayilar[k+1]];
					face0[l][size-1-sayilar[k+1]]=face4[l][size-1-sayilar[k+1]];
					face4[l][size-1-sayilar[k+1]]=face_bos[l][sayilar[k+1]];
					
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==3){
				for(l=0;l<size;l++){

					face_bos[l][sayilar[k+1]]=face3[l][sayilar[k+1]];

					face3[l][sayilar[k+1]]=face5[size-1-sayilar[k+1]][l];
					face5[size-1-sayilar[k+1]][l]=face1[l][size-1-sayilar[k+1]];
					face1[l][size-1-sayilar[k+1]]=face4[sayilar[k+1]][l];
					face4[sayilar[k+1]][l]=face_bos[l][sayilar[k+1]];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==4){
				for(l=0;l<size;l++){

					face_bos[l][sayilar[k+1]]=face4[l][sayilar[k+1]];

					face4[l][sayilar[k+1]]=face0[l][sayilar[k+1]];
					face0[l][sayilar[k+1]]=face5[l][sayilar[k+1]];
					face5[l][sayilar[k+1]]=face2[size-1-l][sayilar[k+1]];
					face2[size-1-l][sayilar[k+1]]=face_bos[l][sayilar[k+1]];
				}
				k=k+1;
				k++;
			}
			else if(sayilar[k]==5){
				for(l=0;l<size;l++){

					face_bos[l][sayilar[k+1]]=face5[l][sayilar[k+1]];

					face5[l][sayilar[k+1]]=face2[size-1-l][sayilar[k+1]];
					face2[size-1-l][sayilar[k+1]]=face4[l][sayilar[k+1]];
					face4[l][sayilar[k+1]]=face0[l][sayilar[k+1]];
					face0[l][sayilar[k+1]]=face_bos[l][sayilar[k+1]];
					
				}
				k=k+1;
				k++;
			}
			j=j+2;
		}

		/* Bu döngü rotate .. column .. down olup olmadığını kontrol ediyor. 
		Eğer komutlarda bunların baş harflerini yani rcd'yu görürse bu döngüye giriyor.*/
		else if(komutlar[j]=='r' && komutlar[j+1]=='c' && komutlar[j+2]=='d'){

			/* Face numaralarını kontrol ediyor.*/
			/* Eğer face numaraları koşulu sağlarsa bu döngülere giriyor ve sırasıyla belirli column'ı ve 
			buna bağlı olan column'ları down ediyor. */
			if(sayilar[k]==0){
				for(l=0;l<size;l++){

					face_bos[l][sayilar[k+1]]=face0[l][sayilar[k+1]];

					face0[l][sayilar[k+1]]=face4[l][sayilar[k+1]];
					face4[l][sayilar[k+1]]=face2[size-1-l][size-1-sayilar[k+1]];
					face2[size-1-l][size-1-sayilar[k+1]]=face5[l][sayilar[k+1]];					
					face5[l][sayilar[k+1]]=face_bos[l][sayilar[k+1]];
				}
				k=k+1;
				k++;
			}
			if(sayilar[k]==1){
				for(l=0;l<size;l++){

					face_bos[l][sayilar[k+1]]=face1[l][sayilar[k+1]];

					face1[l][sayilar[k+1]]=face4[size-1-sayilar[k+1]][l];
					face4[size-1-sayilar[k+1]][l]=face3[l][size-1-sayilar[k+1]];
					face3[l][size-1-sayilar[k+1]]=face5[sayilar[k+1]][l];
					face5[sayilar[k+1]][l]=face_bos[l][sayilar[k+1]];
				}
				k=k+1;
				k++;
			}
			if(sayilar[k]==2){
				for(l=0;l<size;l++){

					face_bos[l][sayilar[k+1]]=face2[l][sayilar[k+1]];

					face2[l][sayilar[k+1]]=face4[size-1-l][sayilar[k+1]];
					face4[size-1-l][sayilar[k+1]]=face0[size-1-l][sayilar[k+1]];
					face0[size-1-l][sayilar[k+1]]=face5[size-1-l][sayilar[k+1]];
					face5[size-1-l][sayilar[k+1]]=face_bos[l][sayilar[k+1]];
					
				}
				k=k+1;
				k++;
			}
			if(sayilar[k]==3){
				for(l=0;l<size;l++){

					face_bos[l][sayilar[k+1]]=face3[l][sayilar[k+1]];

					face3[l][sayilar[k+1]]=face4[sayilar[k+1]][l];
					face4[sayilar[k+1]][l]=face1[l][size-1-sayilar[k+1]];
					face1[l][size-1-sayilar[k+1]]=face5[size-1-sayilar[k+1]][l];
					face5[size-1-sayilar[k+1]][l]=face_bos[l][sayilar[k+1]];
				}
				k=k+1;
				k++;
			}
			if(sayilar[k]==4){
				for(l=0;l<size;l++){

					face_bos[l][sayilar[k+1]]=face4[l][sayilar[k+1]];

					face4[l][sayilar[k+1]]=face2[size-1-l][sayilar[k+1]];
					face2[size-1-l][sayilar[k+1]]=face5[l][sayilar[k+1]];
					face5[l][sayilar[k+1]]=face0[l][sayilar[k+1]];					
					face0[l][sayilar[k+1]]=face_bos[l][sayilar[k+1]];
				}
				k=k+1;
				k++;
			}
			if(sayilar[k]==5){
				for(l=0;l<size;l++){

					face_bos[l][sayilar[k+1]]=face5[l][sayilar[k+1]];


					face5[l][sayilar[k+1]]=face0[l][sayilar[k+1]];
					face0[l][sayilar[k+1]]=face4[l][sayilar[k+1]];
					face4[l][sayilar[k+1]]=face2[size-1-l][sayilar[k+1]];
					face2[size-1-l][sayilar[k+1]]=face_bos[l][sayilar[k+1]];
				}
				k=k+1;
				k++;
			}
			j=j+2;
		}

	}

	/* Dosyanın içerisine bütün face'leri sırasıyla yazdırıyor. */
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			fprintf(output,"%d",face0[i][j]);
		}
		fprintf(output,"\n");
	}
	fprintf(output,"\n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			fprintf(output,"%d",face1[i][j]);
		}
		fprintf(output,"\n");
	}
	fprintf(output,"\n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			fprintf(output,"%d",face2[i][j]);
		}
		fprintf(output,"\n");
	}
	fprintf(output,"\n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			fprintf(output,"%d",face3[i][j]);
		}
		fprintf(output,"\n");
	}
	fprintf(output,"\n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			fprintf(output,"%d",face4[i][j]);
		}
		fprintf(output,"\n");
	}
	fprintf(output,"\n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			fprintf(output,"%d",face5[i][j]);
		}
		fprintf(output,"\n");
	}
	fprintf(output,"\n");

}


int main()
{
	okuma();
	return 0;
}
