#include <stdio.h>
#include <stdlib.h>

#define MAX_M 100
#define MAX_N 100000
#define INF 1e9

typedef struct {
    int id;
    double price;
} Product;

int main() {
    int M, N;

    while (scanf("%d %d", &M, &N), M || N) {
        int list[MAX_M];
        Product products[MAX_N];
        double dp[MAX_M + 1];
        
        for (int i = 0; i < M; i++) {
            scanf("%d", &list[i]);
        }

        for (int i = 0; i < N; i++) {
            scanf("%d %lf", &products[i].id, &products[i].price);
        }

        for (int i = 0; i <= M; i++) {
            dp[i] = INF;
        }
        dp[0] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = M - 1; j >= 0; j--) {
                if (products[i].id == list[j] && dp[j] < INF) {
                    if (dp[j] + products[i].price < dp[j + 1]) {
                        dp[j + 1] = dp[j] + products[i].price;
                    }
                }
            }
        }

        if (dp[M] < INF) {
            printf("%.2lf\n", dp[M]);
        } else {
            printf("Impossible\n");
        }
    }

    return 0;
}