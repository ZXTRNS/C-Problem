/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Convert{
    char num;
    char huruf;
}tabel[] = {
    {'0', 'O'},
    {'1', 'I'},
    {'3', 'E'},
    {'4', 'A'},
    {'5', 'S'},
    {'6', 'G'},
    {'7', 'T'},
    {'8', 'B'}
};

int Tabel = 8;

char ConvertNum(char c){
    for(int i = 0; i < Tabel; i++){
        if(c == tabel[i].num)		// kalau karakter ada di tabel angka ke-i
            return tabel[i].huruf;	// convert ke huruf di tabel tersebut
    }
    return c; // kalau bukan angka di tabel
}   

char shiftBack(char c, int k){
    if(c >= 'A' && c <= 'Z'){
        return 'A' + ((c - 'A' - k + 26) % 26);
    }
    return c;
}


int main(){
    FILE *file = fopen("testdata.in", "r");
    if(file == NULL){
        return 0;
    }

    int testcase;
    fscanf(file, "%d\n", &testcase);
    
    for(int t = 1; t <= testcase; t++){
        int shift;
        fscanf(file, "%d\n", &shift);
        
        char S[1001];
        fscanf(file, "%[^\n]\n", S);
        
	// step 1: angka --> huruf
        for(int i = 0; S[i]; i++){
            S[i] = ConvertNum(S[i]);
        }
        
	// step 2: huruf di-shift back k kali
        for(int i = 0; S[i]; i++){
            S[i] = shiftBack(S[i], shift);
        }
        printf("Case #%d: %s\n", t, S);
    }
    
    fclose(file);
    return 0;
}