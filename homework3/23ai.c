#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int type;
    int num;
    char str;
} note;

int max(int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

int isprime(int x) {
    if (x < 2) return 0;
    if (x == 2) return 1;
    if (x % 2 == 0) return 0;
    
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) return 0;
    }
    return 1;
}

// 检查数字的各位之和是否为素数
int is_digit_sum_prime(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return isprime(sum);
}

// 检查数字的各位中是否有素数数字
int has_prime_digit(int x) {
    if (x == 0) return 0;
    
    while (x > 0) {
        int digit = x % 10;
        if (isprime(digit)) return 1;
        x /= 10;
    }
    return 0;
}

int main() {
    char s[10005] = "";
    int m;
    
    while (scanf("%s %d", s, &m) != EOF) {
        int len = strlen(s);
        
        // 分割数字
        int nums[10005] = {0};
        int num_count = 0;
        
        for (int i = 0; i < len; i += m) {
            int num = 0;
            for (int j = 0; j < m && i + j < len; j++) {
                num = num * 10 + (s[i + j] - '0');
            }
            nums[num_count++] = num;
        }
        
        // 分类
        int type[10005] = {0}; // 0=未分类, 1=第1类, 2=第2类, 3=第3类, 4=第4类
        int count[5] = {0}; // 每类的数量
        
        for (int i = 0; i < num_count; i++) {
            if (type[i] == 0 && isprime(nums[i])) {
                type[i] = 1;
                count[1]++;
            }
            if (type[i] == 0 && is_digit_sum_prime(nums[i])) {
                type[i] = 2;
                count[2]++;
            }
            if (type[i] == 0 && has_prime_digit(nums[i])) {
                type[i] = 3;
                count[3]++;
            }
            if (type[i] == 0) {
                type[i] = 4;
                count[4]++;
            }
        }
        
        // 分离各类数字
        int class1[10005] = {0}, idx1 = 0;
        int class2[10005] = {0}, idx2 = 0;
        int class3[10005] = {0}, idx3 = 0;
        int class4[10005] = {0}, idx4 = 0;
        
        for (int i = 0; i < num_count; i++) {
            switch (type[i]) {
                case 1: class1[idx1++] = nums[i]; break;
                case 2: class2[idx2++] = nums[i]; break;
                case 3: class3[idx3++] = nums[i]; break;
                case 4: class4[idx4++] = nums[i]; break;
            }
        }
        
        // 计算k值
        int max_count = max(count[1], max(count[2], max(count[3], count[4])));
        int k = 3;
        
        // 计算四个三角形的容量
        while (1) {
            int half = k / 2;
            
            // 上三角形容量 (不包括对角线)
            int up_capacity = 0;
            for (int i = 0; i < half; i++) {
                up_capacity += k - 2 - 2 * i;
            }
            
            // 左三角形容量 (不包括对角线)
            int left_capacity = 0;
            for (int i = 1; i <= half; i++) {
                left_capacity += i;
            }
            for (int i = half - 1; i >= 1; i--) {
                left_capacity += i;
            }
            
            // 右三角形容量 (与左三角形对称)
            int right_capacity = left_capacity;
            
            // 下三角形容量 (与上三角形对称)
            int down_capacity = up_capacity;
            
            if (up_capacity >= count[1] && left_capacity >= count[2] && 
                right_capacity >= count[3] && down_capacity >= count[4]) {
                break;
            }
            k += 2;
            if (k > 101) {
                k = 101;
                break;
            }
        }
        
        // 创建并初始化表格
        note **form = (note **)malloc(k * sizeof(note *));
        for (int i = 0; i < k; i++) {
            form[i] = (note *)malloc(k * sizeof(note));
            for (int j = 0; j < k; j++) {
                form[i][j].type = 0;
                form[i][j].num = 0;
                form[i][j].str = ' ';
            }
        }
        
        // 画对角线
        for (int i = 0; i < k; i++) {
            form[i][i].str = '*';
            form[i][i].type = 1;
            form[i][k - 1 - i].str = '*';
            form[i][k - 1 - i].type = 1;
        }
        
        // 填充上三角形 (第1类)
        int pos1 = 0;
        for (int i = 0; i < k / 2; i++) {
            for (int j = i + 1; j < k - 1 - i; j++) {
                if (form[i][j].str != '*') {
                    form[i][j].num = (pos1 < idx1) ? class1[pos1] : 0;
                    pos1++;
                }
            }
        }
        
        // 填充左三角形 (第2类)
        int pos2 = 0;
        for (int i = 1; i < k - 1; i++) {
            int limit = (i <= k / 2) ? i : k - 1 - i;
            for (int j = 0; j < limit; j++) {
                if (form[i][j].str != '*') {
                    form[i][j].num = (pos2 < idx2) ? class2[pos2] : 0;
                    pos2++;
                }
            }
        }
        
        // 填充右三角形 (第3类)
        int pos3 = 0;
        for (int i = 1; i < k - 1; i++) {
            int start = (i <= k / 2) ? k - i : i + 1;
            for (int j = start; j < k; j++) {
                if (form[i][j].str != '*') {
                    form[i][j].num = (pos3 < idx3) ? class3[pos3] : 0;
                    pos3++;
                }
            }
        }
        
        // 填充下三角形 (第4类)
        int pos4 = 0;
        for (int i = k / 2 + 1; i < k - 1; i++) {
            for (int j = k - i; j < i; j++) {
                if (form[i][j].str != '*') {
                    form[i][j].num = (pos4 < idx4) ? class4[pos4] : 0;
                    pos4++;
                }
            }
        }
        
        // 输出结果
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (form[i][j].str == '*') {
                    printf("%5c", '*');
                } else {
                    printf("%5d", form[i][j].num);
                }
            }
            printf("\n");
        }
        printf("\n");
        
        // 释放内存
        for (int i = 0; i < k; i++) {
            free(form[i]);
        }
        free(form);
    }
    
    return 0;
}