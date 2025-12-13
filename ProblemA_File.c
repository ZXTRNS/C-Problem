#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Plants{
    char NameFriend[41];
    char Tree[41];
};

int main(){
    FILE *file = fopen("testdata.in", "r");
    if(file == NULL){
        puts("Case #%d: N/A");
        return 0;
    }
    
    int records;
    fscanf(file, "%d\n", &records);
    
    struct Plants data[records];
    
    for(int i = 0; i < records; i++){
        fscanf(file, "%[^#]#%[^\n]\n", data[i].NameFriend, data[i].Tree);
    }
    
    int testcase;
    fscanf(file, "%d\n", &testcase);
    
    char Name[101];
    
    for(int i = 0; i < testcase; i++){
        fscanf(file, "%[^\n]\n", Name);
        int found = 0;
        
        for(int j = 0; j < records; j++){
            if(strcmp(Name, data[j].NameFriend) == 0){
                printf("Case #%d: %s\n", i+1, data[j].Tree);
                found = 1;
                break;
            }
        }
        
        if(!found){
            printf("Case #%d: N/A\n", i+1);
        }
    }

    fclose(file);
    return 0;
}
