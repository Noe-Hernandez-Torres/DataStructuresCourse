/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
    printf("\n t's value: %d", t);
    return 0;
}