#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};

    // Input string
    printf("Enter string: ");
    scanf("%s", s);

    int len = strlen(s);

    // Count frequency
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    // Find first non-repeating character
    for (int i = 0; i < len; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // If no non-repeating character found
    printf("$\n");

    return 0;
}