#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	
	int p,q;
	for(int i=1 ; i<=n ; i++){
		scanf("%d %d",&p, &q);
		
		int a[p][q];
		for(int l=0 ; l<p ; l++){
			for(int m=0 ; m<q ; m++){
				scanf("%d", &a[l][m]);
			}
		}
	
		long long total=0;
		for(int j=0 ; j<p ; j++){
			int temp=a[j][0];
			for(int k=1 ; k<q ; k++){
				if(temp<a[j][k]){
					temp=a[j][k];
				}
			}
			total+=temp;
		}
		printf("Case #%d: %lld\n", i, total);
	}

	return 0;
}
