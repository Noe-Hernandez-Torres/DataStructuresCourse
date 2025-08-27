#include <stdio.h>
#include <stdlib.h>

static inline int idx(int r, int c, int cols) { return r * cols + c; }

int main(void) {
    int rows, cols;
    printf("Enter rows cols (separated by an space): ");
    
    scanf("%d %d", &rows, &cols);
    
    //size_t is the type of data return by size_of
    int *A = (int*)malloc((size_t)rows * (size_t)cols * sizeof(int));
    int *B = (int*)malloc((size_t)rows * (size_t)cols * sizeof(int));
    int *C = (int*)malloc((size_t)rows * (size_t)cols * sizeof(int));
    
    if (A == NULL || B == NULL || C == NULL) { 
        perror("malloc"); 
        free(A); 
        free(B); 
        free(C); 
        return 1; 
        
    }

    printf("Enter %d ints for A (row-wise):\n", rows * cols);
    
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            if (scanf("%d", A + idx(r, c, cols)) != 1) { 
                fprintf(stderr, "Invalid input\n"); 
                free(A); 
                free(B); 
                free(C); 
                return 1; 
                
            }

    printf("Enter %d ints for B (row-wise):\n", rows * cols);
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            if (scanf("%d", B + idx(r, c, cols)) != 1) { 
                fprintf(stderr, "Invalid input\n"); 
                free(A); 
                free(B); 
                free(C); 
                return 1; 
                
            }

    /* C = A + B via pointer arithmetic */
    for (int *pa = A, *pb = B, *pc = C, *end = A + (size_t)rows * (size_t)cols; pa < end; ++pa, ++pb, ++pc) {
        *pc = *pa + *pb;
    }

    printf("A + B =\n");
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) 
            printf("%d%s", *(C + idx(r, c, cols)), (c + 1 < cols ? " " : ""));
            printf("\n");
    }

    free(A); 
    free(B); 
    free(C);
    return 0;
}
