#include <stdio.h>
#define MAX 50

int isEmptyP(int top){ 
	return top==-1; 
}
int isFullP(int top,int c){ 
	return top==c-1; 
}
int sizeP(int top){ 
	return top+1; 
}
int pushP(int a[],int *top,int x,int c){ 
	if(isFullP(*top,c)) 
		return 0;
	a[++(*top)]=x; 
	return 1; 
}
int popP(int a[],int *top,int *out){ 
	if(isEmptyP(*top)) 
		return 0; 
	*out=a[(*top)--]; 
return 1; 
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
	printf("\n"); }
int main(void){ 
	int a[MAX], top=-1, ch,x,ok; 
	while(1){ 
		printf("\n1)push 2)pop 3)peek 4)size 5)print 0)exit\n> ");
		if(scanf("%d",&ch)!=1) 
			return 0; 
		if(ch==0) 
			break; 
		
		switch(ch){ 
			case 1: printf("value: "); 
					if(scanf("%d",&x)!=1) 
						return 0; 
					ok=pushP(a,&top,x,MAX); 
					if(!ok) printf("overflow\n"); 
						break; 
			case 2: ok=popP(a,&top,&x); 
					if(ok)
						printf("pop=%d\n",x); 
					else 
						printf("underflow\n"); 
						break; 
			case 3: ok=peekP(a,top,&x); 
					if(ok) 
						printf("peek=%d\n",x); 
					else 
						printf("empty\n"); 
						break; 
			case 4: printf("size=%d\n", sizeP(top)); 
					break; 
			case 5: printStackP(a,top); 
					break; 
			default: printf("invalid\n"); 
		} 
	} 
}
