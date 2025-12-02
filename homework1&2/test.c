#include<stdio.h>

int main()
{
int a;
int n=0;
int m=0;
while (scanf("%d", &n)!=EOF){
	if(n<1||n>1000000){
		break;
	}
	for (a=6;a<9999999;a++){
		int q =a%6;
		int x =a%10;
		int y =(a/10)%10;
		int z =(a/100)%10;
		if(q==0||x==6||y==6||z==6){
			m++;
			if(m==n){
				printf("%d\n",a);
				m=0;
				break;
		}	
	}
		
	}
}	
return 0;	
}