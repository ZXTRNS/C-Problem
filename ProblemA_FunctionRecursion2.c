#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b){
  double A = *(double*)a;
  double B = *(double*)b;
  if(A<B){
    return - 1;
  } else if(A>B){
    return 1;
  } else{
    return 0;
  }
}

int main(){
  int t,i,j,n;
  double datas[5001];
  double rataan, median;
  scanf("%d", &t);

  i=0;
  while(i<t){
    rataan = 0;
    scanf("%d", &n);
    for(j=0;j<n;j++){
      scanf("%lf", &datas[j]);
      rataan+=datas[j];
    }
    qsort(datas,n,sizeof(double),comp);

    if(n%2==0){
      median = (datas[(n/2)-1]+datas[(n/2)])/2;
    }else{
      median = datas[(n/2)];
    }
    rataan /= n;

    printf("Case #%d:\n", i+1);
    printf("Mean : %.2lf\n", rataan);
    printf("Median : %.2lf\n", median);

    i++;
  } 

  return 0;
}