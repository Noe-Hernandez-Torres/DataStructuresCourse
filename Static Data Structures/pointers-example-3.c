#include <stdio.h>

int main()
{
    int t = 32;
    int *ptrInt;

    printf("\n t's address: %p",&t);
    printf("\n t's value: %d", t);
    
    //address cannot be changed
    //it is assigned by the OS
    
    t = 12;
    prtInt = &t;
    
    printf("\n t's address: %p", ptrInt);
    printf("\n t's value: %d\n", *ptrInt);
    return 0;
}