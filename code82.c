#include <stdio.h>

int leastInterval(char tasks[], int tasksSize, int n) {
    int freq[26] = {0};

    // Count frequency of tasks
    for(int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    // Find maximum frequency
    int maxFreq = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > maxFreq)
            maxFreq = freq[i];
    }

    // Count tasks with max frequency
    int maxCount = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] == maxFreq)
            maxCount++;
    }

    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int minIntervals = partCount * partLength + maxCount;

    if(minIntervals > tasksSize)
        return minIntervals;
    else
        return tasksSize;
}

int main() {
    int n, size;

    printf("Enter number of tasks: ");
    scanf("%d", &size);

    char tasks[size];

    printf("Enter tasks (A-Z):\n");
    for(int i = 0; i < size; i++) {
        scanf(" %c", &tasks[i]);
    }

    printf("Enter cooling interval n: ");
    scanf("%d", &n);

    int result = leastInterval(tasks, size, n);

    printf("Minimum CPU intervals required: %d\n", result);

    return 0;
}