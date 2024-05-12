#include<stdio.h>

void main(){
	int x;
	int i;

	scanf("%d", &x);

	for(i=0; i <= x; i++){
		if(i % 3 == 0){
			printf("%d \n", i);
		}
	}
}
