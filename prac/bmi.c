#include<stdio.h>

void main(){
	double weight;
	double height;
	double bmi;

	printf("あなたの体重を教えてね\n");
	scanf("%lf", &weight);

	printf("あなたの身長を教えてね\n");
	scanf("%lf", &height);

	if(weight < 0 || height < 0){
		printf("不正な値です。");
	} else {
		height = height / 100;
		bmi = weight / (height * height);

		printf("あなたのBMIは　%lf です！", bmi);

		if(bmi < 18.5){
			printf("あなたは痩せ気味です。");
		} else if(18.5 <= bmi && bmi < 25){
			printf("あなたは標準的な体型です。");
		} else {
			printf("あなたは太り気味です。");
		}
	}
}
