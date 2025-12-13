#include <stdio.h>
#include <string.h>

int main() {
    char s[51];
    int len, i, j;
    
    scanf("%s", s);
    len = strlen(s);
    
    for (i = 0, j = len - 1; i < j; i++, j--) {
        // If both are '_', they don't match
        if (s[i] == '_' && s[j] == '_') {
            printf("No\n");
            return 0;
        }
        // If characters are different and neither is '_', they don't match
        if (s[i] != s[j] && s[i] != '_' && s[j] != '_') {
            printf("No\n");
            return 0;
        }
        // All other cases are valid:
        // 1. s[i] == s[j] (normal match)
        // 2. s[i] == '_' && s[j] != '_' (special match)
        // 3. s[i] != '_' && s[j] == '_' (special match)
    }
    
    printf("Yes\n");
    return 0;
}