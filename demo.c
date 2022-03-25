#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isNumber(char* s){
    if (strspn(s, "0123456789")==strlen(s)){
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    char* s = (char*)malloc(sizeof(char));
    scanf("%s", s);
    printf("%d", isNumber(s));

    unsigned int a = (unsigned)atoi(s);
    printf("%d", a);

    return 0;
}