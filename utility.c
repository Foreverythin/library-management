#include <stdlib.h>
#include <string.h>

#include "utility.h"

int isNumber(char* s){
    if (strspn(s, "0123456789")==strlen(s)){
        return 1;
    }else{
        return 0;
    }
}
