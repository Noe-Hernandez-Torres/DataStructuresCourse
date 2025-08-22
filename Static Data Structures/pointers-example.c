#include <stdio.h>

int main()
{
    int t = 32;
    
    printf("\n t's address: %p",&t);
    printf("\n t's value: %d", t);
    
    //address cannot be changed
    //it is assigned by the OS
    t = 12;
    printf("\n t's address: %p", &t);
    printf("\n t's value: %d\n", t);
    return 0;
}