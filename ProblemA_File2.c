#include <stdio.h>
#include <string.h>

int main() {
    int N, M;
    FILE *file = fopen("testdata.in", "r");
    char firstLine[105];
    fgets(firstLine, sizeof(firstLine), file);
    sscanf(firstLine, "%d %d", &N, &M);
    
    char data[105][15][20];
    char line[105];

    for(int i = 1; i <= N; i++){
        fgets(line, sizeof(line), file);
        line[strcspn(line, "\n")] = 0;
        int col = 0, idx = 0;

        for(int j = 0; line[j]; j++){
            if(line[j] == ';'){
                data[i][col++][idx] = 0;
                idx = 0;
            } 
            else {
                data[i][col][idx++] = line[j];
            }
        }
        data[i][col][idx] = 0;
    }

    int Q;
    fscanf(file, "%d", &Q);

    while (Q--) {
        int x;
        char H[20], S[20];
        fscanf(file, "%d %s %s", &x, H, S);

        if (x == 1) continue;

        int target = -1;
        for (int j = 0; j < M; j++) {
            if (strcmp(data[1][j], H) == 0) {
                target = j;
                break;
            }
        }

        if (target != -1) {
            strcpy(data[x][target], S);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%s;", data[i][j]);
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}
