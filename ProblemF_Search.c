#include <stdio.h>
#include <string.h>

char shortW[105][55];
char longW[105][55];

int main(){
	FILE *fp = fopen("testdata.in", "r");
	if(!fp) return 0;
	
	int T; 
	fscanf(fp, "%d", &T);
	
	for(int i = 0; i < T; i++) {
		fscanf(fp, " %[^#]#%s", shortW[i], longW[i]);
	}
	
	int TC;
	fscanf(fp, "%d", &TC);
	fgetc(fp);
	
	for(int cs = 1; cs <= TC; cs++) {
		char sentence[205];
		fgets(sentence, sizeof(sentence), fp);
		
		sentence[strcspn(sentence, "\n")] = '\0';
		
		printf("Case #%d:\n", cs);
		
		char *word = strtok(sentence, " ");
		int first = 1; 
		
		while(word != NULL) {
			int found = 0;
			for(int i = 0; i < T; i++) {
				if(strcmp(word, shortW[i]) == 0){
					if(!first) printf(" ");
					printf("%s", longW[i]);
					found = 1;
					break;
				}
			}
			if(!found){
				if(!first) printf(" ");
				printf("%s", word);
			}
			
			first = 0;
			word = strtok(NULL, " ");
		}
		
		printf("\n");
	}
	
	return 0;
}
