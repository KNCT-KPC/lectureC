#include<stdio.h>

void main(){
	int x = 1;
	
	while(x <= 10000){
		//���R��x�̒l���v�Z���Ă��������B
		x = x * x + 1;
		printf("%d\n", x);
	}
}
