#include<stdio.h>

//int main(void)
void main(){
	int S;
	int i;

	for(i = 0; i <= 4 ; i++){
		switch(i){
			case 1:
				printf("第一象限は「0 ~ π/2」です。\n");
				break;
			case 2:
				printf("第二象限は「π/2 ~ π」です。\n");
				break;
			case 3:
				printf("第三象限は「π ~ 3π/2」です。\n");
				break;
			case 4:
				printf("第四象限は「3π/2 ~ 2π」です。\n");
				break;
		}
	}
}
