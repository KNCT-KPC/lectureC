#include<stdio.h>

void main(){
	double weight;
	double height;
	double bmi;

	printf("���Ȃ��̑̏d�������Ă�\n");
	scanf("%lf", &weight);

	printf("���Ȃ��̐g���������Ă�\n");
	scanf("%lf", &height);

	if(weight < 0 || height < 0){
		printf("�s���Ȓl�ł��B");
	} else {
		height = height / 100;
		bmi = weight / (height * height);

		printf("���Ȃ���BMI�́@%lf �ł��I", bmi);

		if(bmi < 18.5){
			printf("���Ȃ��͑����C���ł��B");
		} else if(18.5 <= bmi && bmi < 25){
			printf("���Ȃ��͕W���I�ȑ̌^�ł��B");
		} else {
			printf("���Ȃ��͑���C���ł��B");
		}
	}
}
