//
//  main.c
//  cte
//
//  Created by Dynasty Dream on 2023/7/14.
//
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
int main(void) {
    int64_t num = 1234567890;
    printf("%" PRId64 "\n", num);
    char str[20]; // 定义足够大的字符数组来存储结果
    sprintf(str, "%" PRId64, num);
    printf("拼接的字符串: %s\n", str);
    
    char str1[30] = "seek event : pos ",str2[20];
    sprintf(str2, "%" PRId64, num);
    strcat(str1, str2);
    printf("拼接的字符串: %s\n", str1);
    
    char str3[40] = "seek event : starttime ";
    sprintf(str2, "%" PRId64, num);
    strcat(str3, str2);
    printf("拼接的字符串: %s\n", str3);
    return 0;
}
