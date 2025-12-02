#include <stdio.h>
#include <string.h>
int sum[500000];

void store() {
    memset(sum, 0, sizeof(sum));
    for (int a = 1; a <= 500000; a++) { 
        for (int b = 2 * a; b <= 500000; b += a) { 
            sum[b] += a; 
        }
    }
}

int main() {
    store(); 
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n < 1 || n > 500000) continue;
        if(n==1) printf("1\n");
        else printf("%d\n", sum[n]);
    }
    return 0;
}