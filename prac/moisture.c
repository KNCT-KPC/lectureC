#include <stdio.h>

int main(void){
    double weight;
    double temperature;
    double moisture;
    double evaporation;

    printf("���Ȃ��̑̏d�������Ă�\n");
    scanf("%lf", &weight);
    printf("���Ȃ��̑̉��������Ă�\n");
    scanf("%lf", &temperature);

   if(weight < 0 || temperature <= 35 || 37.5 <= temperature){
      printf("�s���Ȓl�ł�");
   }else{
    moisture = weight * 33;
    evaporation = weight * 15 + 200 * (temperature - 36.8);

    printf("���Ȃ������܂Ȃ���΂����Ȃ����̗ʂ� %lf ml/day �ł��I\n", moisture);
    printf("���Ȃ�������ɑ̂��玸�����̗ʂ� %lf ml/day �ł��I\n", evaporation);
   }
}
