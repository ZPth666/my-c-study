#include <stdio.h>
#include <stdlib.h>

// 判断是否为素数
int isPrime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// 生成前n个素数
int* generatePrimes(int n) {
    int* primes = (int*)malloc(n * sizeof(int));
    int count = 0;
    int num = 2;
    
    while (count < n) {
        if (isPrime(num)) {
            primes[count++] = num;
        }
        num++;
    }
    
    return primes;
}

// 绘制螺旋线并返回裁剪后的数字画
void createSpiral(int n, int*** result, int* rows, int* cols) {
    // 初始化画布
    int canvas[600][600] = {0};
    int x = 299, y = 299; // 中心位置
    
    // 方向: 右, 上, 左, 下
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};
    int dir = 0;
    
    // 记录边界
    int min_x = 299, max_x = 299;
    int min_y = 299, max_y = 299;
    
    int* primes = generatePrimes(n);
    
    for (int i = 0; i < n; i++) {
        int length = primes[i];
        for (int j = 0; j < length; j++) {
             x += dx[dir];
            y += dy[dir];
            // 更新边界
            if (x < min_x) min_x = x;
            if (x > max_x) max_x = x;
            if (y < min_y) min_y = y;
            if (y > max_y) max_y = y;
            
            // 横线(右/左)
            if (dir % 2 == 0) {
                canvas[y][x] = 1;
            }
            // 竖线(上/下)
            else {
                canvas[y][x] = 2;
            }
        }
        dir = (dir + 1) % 4;
    }
    
    free(primes);
    
    // 裁剪画布
    *rows = max_y - min_y + 1;
    *cols = max_x - min_x + 1;
    *result = (int**)malloc(*rows * sizeof(int*));
    
    for (int i = 0; i < *rows; i++) {
        (*result)[i] = (int*)malloc(*cols * sizeof(int));
        for (int j = 0; j < *cols; j++) {
            (*result)[i][j] = canvas[min_y + i][min_x + j];
        }
    }
}

// 打印数字画
void printSpiral(int** spiral, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", spiral[i][j]);
        }
        printf("\n");
    }
}

// 释放内存
void freeSpiral(int** spiral, int rows) {
    for (int i = 0; i < rows; i++) {
        free(spiral[i]);
    }
    free(spiral);
}

int main() {
    int n = 1; // 示例n=5
    int** spiral;
    int rows, cols;
    
    createSpiral(n, &spiral, &rows, &cols);
    printSpiral(spiral, rows, cols);
    freeSpiral(spiral, rows);
    
    return 0;
}