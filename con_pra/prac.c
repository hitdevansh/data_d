#include<stdio.h>
int main()
{
    char *argv[3];
    scanf("%s %s %s ",&argv[0],&argv[1],&argv[2]);
    printf("%c",*argv[0]);
    printf("%c",*argv[1]);
    printf("%c",*argv[2]);
}
