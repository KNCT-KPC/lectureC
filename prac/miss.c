#include<stdio.h>

void main(){
   double weight;
   double temperture;
   double moisture;
   double evaporation;

   printf("���Ȃ��̑̏d�������Ă�\n");
   scanf("%lf", &weight);
   printf("���Ȃ��̑̉��������Ă�\n");
   scanf("%lf", &temperture);

   if(weight < 0 || temperture <= 35 || 37.5 <= temperture){
      printf("�s���Ȓl�ł�");
   }else{
    moisture = weight * 33;
    evaporation = weight * 15 + 200 * (temperture - 36.8);

    printf("���Ȃ������܂Ȃ���΂����Ȃ����̗ʂ� %lf ml/day �ł��I\n", moisture);
    printf("���Ȃ�������ɑ̂��玸�����̗ʂ� %lf ml/day �ł��I\n", evaporation);
   }
}
