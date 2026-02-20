#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefixSum = 0;
    long long count = 0;

    int size = 200001;
    long long *freq = (long long*)calloc(size, sizeof(long long));

    int offset = 100000;

    freq[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(prefixSum + offset >= 0 && prefixSum + offset < size) {
            count += freq[prefixSum + offset];
            freq[prefixSum + offset]++;
        }
    }

    printf("%lld\n", count);

    free(freq);
    return 0;
}