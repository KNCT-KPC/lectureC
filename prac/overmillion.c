#include<stdio.h>

void main(){
	int x = 1;
	
	while(x <= 10000){
		//自由にxの値を計算してください。
		x = x * x + 1;
		printf("%d\n", x);
	}
}
