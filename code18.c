#include <stdio.h>

void reverseString(char s[], int n) {
    int left = 0;
    int right = n - 1;
    char temp;

    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main() {
    char s[100000];
    int i, n = 0;

    scanf("%s", s);

    while (s[n] != '\0') {
        n++;
    }

    reverseString(s, n);

    for (i = 0; i < n; i++) {
        printf("%c ", s[i]);
    }

    return 0;
}
