#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
// 定义学生结构体
typedef struct {
    char id[25];   // 准考证号 
    int total;     // 总分 
} Student;
 
// 排序比较函数：先按分数降序，同分按准考证号升序
int cmp(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    if (s1->total != s2->total) {
        return s2->total - s1->total;  // 分数降序
    }
    return strcmp(s1->id, s2->id);     // 字典序升序
}
 
int main() {
    int n, m, g;
    
    while (1) {
        // 读取考生人数n、题目数m、合格线g 
        scanf("%d", &n);
        if (n == 0) break;  // 结束条件 
        scanf("%d %d", &m, &g);
        
        // 读取每题分值 [8]()
        int scores[15] = {0};  // 题目分值数组（索引0对应题号1）
        for (int i = 0; i < m; i++) {
            scanf("%d", &scores[i]);
        }
        
        // 处理每个考生
        Student stu[1005];     // 学生数组 
        int passCnt = 0;       // 通过人数统计 
        for (int i = 0; i < n; i++) {
            char id[25];
            int t;
            scanf("%s %d", id, &t);  // 读取准考证号和解题数量 
            
            // 计算总分 [16]()
            int total = 0;
            for (int j = 0; j < t; j++) {
                int problem;
                scanf("%d", &problem);
                total += scores[problem-1];  // 题号转下标 
            }
            
            // 筛选通过考生
            if (total >= g) {
                strcpy(stu[passCnt].id, id);
                stu[passCnt].total = total;
                passCnt++;
            }
        }
        
        // 排序 [8]()
        qsort(stu, passCnt, sizeof(Student), cmp);
        
        // 输出结果 [5]()
        printf("%d\n", passCnt);
        for (int i = 0; i < passCnt; i++) {
            printf("%s %d\n", stu[i].id, stu[i].total);
        }
    }
    return 0;
}