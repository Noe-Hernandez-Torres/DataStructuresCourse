#include <stdio.h>
#define MAX 100

int stack[MAX]; 
int top = -1;

int isEmpty(void){ 
	return top==-1; 
}

int isFull(void){ 
	return top==MAX-1; 
}

int size(void){ 
	return top+1; 

}

void push(int x){ 
	if(isFull()){ 
		printf("overflow\n"); return; 
	} 
	stack[++top] = x; 
}

int pop(void){ 
	if(isEmpty()){ 
		printf("underflow\n"); 
		return 0; 
	} 
	return stack[top--]; 
}

int peek(void){ 
	if(isEmpty()){ 
		printf("empty\n"); 
		return 0; 
	} 
	return stack[top]; 
}

void printStack(void){ 
	printf("Stack[size=%d]: ", size()); 
	for(int i=top;i>=0;--i) 
		printf("%d ",stack[i]); 
	printf("\n"); 
}


int main(void){ 
	push(10); 
	push(20); 
	push(30); 
	printStack(); 
	printf("peek=%d\n",peek()); 
	printf("pop=%d\n",pop()); printStack(); 
}
