#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char* str1 = "hello";
    char* str2 = "world";
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    printf("%s\n", str1);
    printf("%d\n", len1);
    printf("%s\n", str2);
    printf("%d\n", len2);


    return 0;
}
