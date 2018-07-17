#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
	int a;
	int x = 1;
	srand((unsigned int)time(NULL));

	while(x != 0){
		x = rand() % 50;
		printf("%d\n", x);
	}

	scanf("%d", &a);
	return 0;
}

//確認用にどうぞ。
