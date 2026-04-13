#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXN 15
#define INF INT_MAX

int n;
int cost[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

// TSP function using Bitmask DP
int tsp(int mask, int pos) {
    // All cities visited
    if (mask == (1 << n) - 1)
        return cost[pos][0];

    // Already computed
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    // Try all unvisited cities
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = cost[pos][city] +
                         tsp(mask | (1 << city), city);

            if (newAns < ans)
                ans = newAns;
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    // Input number of cities
    scanf("%d", &n);

    // Input cost matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize DP table
    memset(dp, -1, sizeof(dp));

    // Start from city 0
    int result = tsp(1, 0);

    printf("%d\n", result);

    return 0;
}