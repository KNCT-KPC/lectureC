#include<stdio.h>

void main(){
   double weight;
   double temperture;
   double moisture;
   double evaporation;

   printf("あなたの体重を教えてね\n");
   scanf("%lf", &weight);
   printf("あなたの体温を教えてね\n");
   scanf("%lf", &temperture);

   if(weight < 0 || temperture <= 35 || 37.5 <= temperture){
      printf("不正な値です");
   }else{
    moisture = weight * 33;
    evaporation = weight * 15 + 200 * (temperture - 36.8);

    printf("あなたが飲まなければいけない水の量は %lf ml/day です！\n", moisture);
    printf("あなたが一日に体から失う水の量は %lf ml/day です！\n", evaporation);
   }
}
