#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 1000
#define ID_LENGTH 11
#define NAME_LENGTH 21

typedef struct {
    char id[ID_LENGTH];
    char name[NAME_LENGTH];
} Student;

void sortStudents(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(students[j].id, students[j + 1].id) > 0) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *file = fopen("testdata.in", "r");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }
    
    int N;
    fscanf(file, "%d", &N);
    
    Student students[MAX_STUDENTS];
    
    for (int i = 0; i < N; i++) {
        fscanf(file, "%s %s", students[i].id, students[i].name);
    }
    
    fclose(file);
    
    sortStudents(students, N);
    
    for (int i = 0; i < N; i++) {
        printf("%s %s\n", students[i].id, students[i].name);
    }
    
    return 0;
}
