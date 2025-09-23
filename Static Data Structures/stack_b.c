#include <stdio.h>
#define MAX 100
int isEmptyP(int top){ 
	return top==-1; 
}
int isFullP(int top,int cap){ 
	return top==cap-1; 
}
int sizeP(int top){ 
	return top+1; 
}
int pushP(int a[],int *top,int x,int cap){ 
	if(isFullP(*top,cap)) 
		return 0; 
	a[++(*top)]=x; 
	return 1; 
}
int popP(int a[],int *top,int *out){ 
	if(isEmptyP(*top)) 
		return 0; 
	*out=a[(*top)--]; return 1; 
}

int peekP(int a[],int top,int *out){ 
	if(isEmptyP(top)) 
		return 0; 
	*out=a[top]; 
	return 1; 
}
void printStackP(int a[],int top){ 
	printf("Stack[size=%d]: ", sizeP(top)); 
	for(int i=top;i>=0;--i) 
		printf("%d ",a[i]); 
		printf("\n"); 
}
int main(void){ 
	int a[MAX], 
	top=-1, v; 
	pushP(a,&top,5,MAX); 
	pushP(a,&top,7,MAX); 
	pushP(a,&top,9,MAX); 
	printStackP(a,top); 
	if(peekP(a,top,&v)) 
		printf("peek=%d\n",v); 
	if(popP(a,&top,&v)) 
	printf("pop=%d\n",v); 
	printStackP(a,top); 
}
