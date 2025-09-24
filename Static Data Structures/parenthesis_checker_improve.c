#include <stdio.h>
#define MAX 10000

int isEmpty(int top){ return top == -1; }
int isFull (int top, int cap){ return top == cap - 1; }

int match(char open, char close){
    return (open=='(' && close==')') ||
           (open=='[' && close==']') ||
           (open=='{' && close=='}');
}

int main(void){
    char s[MAX];
    if (!fgets(s, sizeof s, stdin)) return 0;

    char st[MAX];    // bracket stack
    int  idx[MAX];   // index of each opener
    int top = -1;

    for (int i = 0; s[i] && s[i] != '\n'; ++i){
        char c = s[i];
        if (c=='('||c=='['||c=='{'){
            if (isFull(top, MAX)){ printf("ERROR %d\n", i); return 0; }
            st[++top] = c;
            idx[top]  = i;  // remember where it opened
        } else if (c==')'||c==']'||c=='}'){
            if (isEmpty(top)){ printf("ERROR %d\n", i); return 0; }
            if (!match(st[top], c)){ printf("ERROR %d\n", i); return 0; }
            --top;
        }
        // else ignore non-brackets
    }
    if (!isEmpty(top)){               // first unmatched opener
        printf("ERROR %d\n", idx[0]);
    } else {
        printf("OK\n");
    }
    return 0;
}