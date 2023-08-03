//
//  main.c
//  获取当前时间（毫秒）
//
//  Created by Dynasty Dream on 2023/8/3.
//

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
void currentTime(char ** printfStr){
    // 获取当前的时间（包括秒和微秒）
    struct timeval tv;
    gettimeofday(&tv, NULL);
    *printfStr = malloc(100*sizeof(char));
    // 将秒数转为本地时间
    struct tm *timeinfo = localtime(&tv.tv_sec);
    char str[100];
    sprintf(str,"[time : %d:%d:%d:%03d]",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,tv.tv_usec/1000);
    strcpy(*printfStr, str);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char * priStr = NULL;
    currentTime(&priStr);
    
    printf("Hello, World! %s\n",priStr);
    return 0;
}
