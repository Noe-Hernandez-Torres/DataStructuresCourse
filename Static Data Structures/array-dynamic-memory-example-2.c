#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    
    printf("\nPlease, enter the amount of elements in the array: ");
    scanf("%d",&n);
    printf("\n");
    
    int *arrayInts = (int *) malloc (n * sizeof(int));
    
    if(arrayInts == NULL) {
        printf("\n Fail to obtain the required memory!\n");
        return -1;
    }
    
    printf("\n Memory successfully obtained\n");
    
    printf("\n Please, enter the %d ints separated by space: ",n);
    
    for(int i = 0; i < n; i++)
        scanf("%d", (arrayInts + i)); //using the pointer
    
    printf("\n Here your %d ints (in reverse order): ",n);
    
    for(int i = n-1; i >= 0; i--)
        printf("%d",*(arrayInts + i));
    
    
    free(arrayInts);
    
    return 0;
}