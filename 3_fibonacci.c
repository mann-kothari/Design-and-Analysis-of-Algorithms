#include<stdio.h>
void fibonacci(int n, int *calls){
	(*calls)++;
    static int n1=0,n2=1,n3;    
    if(n>0){    
         n3 = n1 + n2;    
         n1 = n2;    
         n2 = n3;    
         printf("%d ",n3);    
         fibonacci(n-1, calls);
    }    
}    
int main()
{
	 int n;
	 int n1=0, n2=1;
	 int calls=0;
	 printf("enter the value of n: ");
	 scanf("%d", &n);
	 printf("%d %d\t", n1,n2);
	 fibonacci(n-2, &calls);
	 printf("\nnumber of calls are %d", calls);
	 return 0;
}
