#include <stdio.h>

int area(int n, int jml[]){
    int blok = 0;
    for(int i = 0; i < n; i++){
        blok = blok + jml[i];
    }
    return 2*2*blok;
}

int klg(int n, int jml[]){
    int sum = 0;
    sum = 2*n;
    sum = sum + 2*n;
    sum = sum + (2*jml[0]);
    for(int i = 1; i < n; i++){
        if(jml[i-1] > jml[i]){
            sum = sum + (2*(jml[i-1] - jml[i]));
        }
        else if(jml[i] > jml[i-1]){
            sum = sum + (2*(jml[i] - jml[i-1]));
        }
        else sum = sum;
    }

    sum = sum + 2*(jml[n-1]);


    return sum;
}

int main(){
    FILE *fp = fopen("testdata.in", "r");

    int t;
    fscanf(fp, "%d\n", &t);

    for(int tc = 0; tc < t; tc++){
        int n = 0;
        fscanf(fp, "%d\n", &n);
        int jml[101];
        for(int i = 0; i < n; i++){
            fscanf(fp, "%d", &jml[i]);
        }
        //area
        int luas = area(n, jml);

        //keliling
        int peri = klg(n, jml);

        printf("Case #%d: %d %d\n", tc+1, peri, luas);
    }

    return 0;
}