#include <stdio.h>

#define MAX_SIZE 100
char hesap(int parantez_sayisi, int j);
int eksi(int k, int parantez_sayisi);

char hesap(int parantez_sayisi, int j){
	char b[MAX_SIZE];
	int i=0, k=0, eleman_sayisi=0;
	FILE *in;
	in=fopen("input.txt","r");
	/* verilen input dosyasındaki karakterler b arrayinde tutuluyor. */
	if( (in=fopen("input.txt","r"),"r") != NULL){
		while(!feof(in)){
			b[i]=fgetc(in);		
			i++;
		}
		eleman_sayisi=i-1;
		b[eleman_sayisi]='\0';
	}
		/* b arrayinin elemanlarıyla ilgileneceğimiz için, j değeri 0'dan başlıyor, eğer b arrayinin eleman sayısından
		küçük ise döngüye giriyor. */
		if(j<eleman_sayisi){
			/* eğer kontrol edilen eleman harf veya parantez ise döngüye girecek.
			eğer açılmış parantez ise parantez sayısını ve arrayin indexi olan j'yi arttıracak.
			eğer harf ise parantez sayısı kadar '-' basacak ve harfi basacak. - basmak için de eksi fonksiyonuna 
			gidecek ve ordakileri yapacak.
			eğer kapanmış parantez ise parantez sayısını azaltacak ve j değerini arttıracak */
			if( (b[j]>='a' && b[j]<='z') || (b[j]>='A' && b[j]<='Z') || b[j]=='(' || b[j]==')' ){
				if(b[j]=='('){
					parantez_sayisi = hesap(parantez_sayisi+1,j+1);

				}
				else if((b[j]>='a' && b[j]<='z') || (b[j]>='A' && b[j]<='Z')){
					if(k<parantez_sayisi){
						eksi(k+1, parantez_sayisi);
					}
					printf("%c\n",b[j]);
					hesap(parantez_sayisi,j+1);
				}
				else if(b[j]==')'){
					parantez_sayisi = hesap(parantez_sayisi-1,j+1);
				}
			}
			/*eğer kontrol edilen şey yukarıdakilerden hiçbiri değilse yani virgülse j değerini arttıracak. */
			else{
				hesap(parantez_sayisi,j+1);
			}
		}
		return(parantez_sayisi);
}
/* - basmak için geleceği bu fonksiyonda, parantez sayısı kadar - basacağı için arguman olarak herhangi bir k değeri ve 
parantez sayısını alıyor.
eğer k değeri parantez sayısından küçükse tekran bu fonksiyona  değerini arttırarak geliyor ve koşul sağlanmadığında 
k değerini return ederek fonksiyondan çıkıyor.*/
int eksi(int k, int parantez_sayisi){
	printf("-");
	if(k<parantez_sayisi){
		eksi(k+1, parantez_sayisi);
	}
	return(k);
}



int main()
{
	/* öncelikle parantez sayısı ve j değeri burada sıfırlanıyor ve fonksiyona bu şekilde gönderiliyor. */
	hesap(0,0);
	return 0;
}