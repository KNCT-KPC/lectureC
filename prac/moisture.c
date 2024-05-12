#include <stdio.h>

int main(void){
    double weight;
    double temperature;
    double moisture;
    double evaporation;

    printf("あなたの体重を教えてね\n");
    scanf("%lf", &weight);
    printf("あなたの体温を教えてね\n");
    scanf("%lf", &temperature);

   if(weight < 0 || temperature <= 35 || 37.5 <= temperature){
      printf("不正な値です");
   }else{
    moisture = weight * 33;
    evaporation = weight * 15 + 200 * (temperature - 36.8);

    printf("あなたが飲まなければいけない水の量は %lf ml/day です！\n", moisture);
    printf("あなたが一日に体から失う水の量は %lf ml/day です！\n", evaporation);
   }
}
