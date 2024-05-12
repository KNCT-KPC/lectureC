#include<stdio.h>
#include<math.h>

void main(){
	int i,a,b,c,d;
	a = 1;
	c = 0;

	printf("What are you counted?\n");
	scanf("%d", &d);
	printf("\n");
	
	while(c < d){
		b = 0;
		for(i=2; i <= sqrt(a); i++){
			if((a % i) == 0){
				b = 1;
				break;		
			}
		}

		if(b == 0){
			c++;
			printf("%d  %d\n", a, c);
			
		}	
		a++;		
	}
}
