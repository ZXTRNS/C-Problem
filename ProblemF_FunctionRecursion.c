#include <stdio.h>
#include <string.h>

int main(){
	long long duit_awal;
	scanf("%lld", &duit_awal);
	
	int k,d,a;
	scanf("%d %d %d", &k, &d, &a);
	
	long long count_k = k*200;
	long long count_a = a*100;
	
	int round;
	scanf("%d", &round);
	if(round==-1){
		duit_awal+=1900;
	} else if(round==0){
		duit_awal+=3000;
	} else if(round==1){
		duit_awal+=3000+300;
	}
	
	long long duit_akhir=duit_awal + count_k + count_a;
	
	char senjata[2][11];
	int harga_senjata[2]={0,0};
	for(int i=0 ; i<2 ; i++){
		scanf("%s", senjata[i]);
		 if (strcmp(senjata[i], "Vandal")==0 || strcmp(senjata[i], "Phantom")==0){
            harga_senjata[i]=2900;
        } else if (strcmp(senjata[i], "Operator")==0) {
            harga_senjata[i]=4700;
        } else if (strcmp(senjata[i], "Marshal")==0) {
            harga_senjata[i]=950;
        } else {
            harga_senjata[i]=1600;
        }
    }
	
	if (duit_akhir>=harga_senjata[0]+harga_senjata[1]){
        printf("SURE!\n");
    } else if (duit_akhir>=harga_senjata[0] || duit_akhir>=harga_senjata[1]){
        printf("SORRY!\n");
    } else {
        printf("REQUEST!\n");
    }
	
	return 0;
}
