#include <stdio.h>
#define MAX 1000

int isEmpty(int top){
	return top==-1; 
}

int isFull(int top,int cap){ 
	return top==cap-1; 
}

int main(void){ 
	char s[MAX]; 
	if(!fgets(s,sizeof s,stdin)) 
		return 0; 
	char st[MAX]; 
	int top=-1, ok=1; 
	for(int i=0; s[i] && s[i]!='\n'; ++i){ 
		char c=s[i]; 
		if(c=='('||c=='['||c=='{'){ 
			if(isFull(top,MAX)){ 
				ok=0; 
				break; 
			} 
			st[++top]=c; 
		} else if(c==')'||c==']'||c=='}'){ 
			if(isEmpty(top)){ 
				ok=0; 
				break; 
			} 
			char t=st[top--]; 														
			if((c==')'&&t!='(')||(c==']'&&t!='[')||(c=='}'&&t!='{')){
	 			ok=0; 
				break; 
			} 
		} 
	} 
	if(!isEmpty(top)) 
		ok=0; 
	printf(ok?"BALANCED\n":"NOT BALANCED\n"); 
}
