#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int left, right;

    scanf("%s", s);

    left = 0;
    right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            printf("NO");
            return 0;
        }
        left++;
        right--;
    }

    printf("YES");
    return 0;
}
