#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int damage;
} Weapon;

// Comparison function for qsort
int compareWeapons(const void *a, const void *b) {
    Weapon *weaponA = (Weapon *)a;
    Weapon *weaponB = (Weapon *)b;
    
    if(weaponA->damage < weaponB->damage) return -1;
    if(weaponA->damage > weaponB->damage) return 1;
    return 0;
}

int main() {
    int T;
    
    // Read number of weapons
    scanf("%d", &T);
    
    // Dynamically allocate array based on T
    Weapon *weapons = (Weapon *)malloc(T * sizeof(Weapon));
    if(weapons == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Read weapon data
    for(int i = 0; i < T; i++) {
        scanf("%s %d", weapons[i].name, &weapons[i].damage);
    }
    
    // Sort weapons by damage
    qsort(weapons, T, sizeof(Weapon), compareWeapons);
    
    // Display sorted weapons
    for(int i = 0; i < T; i++) {
        printf("%s %d\n", weapons[i].name, weapons[i].damage);
    }
    
    // Free allocated memory
    free(weapons);
    
    return 0;
}