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

// int isZero(char* s){
//     if (isNumber(s)){
//         unsigned int s_int = (unsigned)atoi(s);
//         if (s_int==0)
//             return 1;
//         else
//             return 0;
//     }else
//         return 0;
// }