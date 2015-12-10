#include<stdio.h>

double weight;
double height;

void ask(){
  printf("あなたの体重(kg)は？ ");
  scanf("%lf", &weight);

  printf("あなたの身長(cm)は？　");
  scanf("%lf", &height);
}

double keisan(){
  double BMI;
  
  height = height / 100;
  BMI = weight / (height * height);
  printf("あなたの肥満度は %lf です。\n", BMI);
  return(BMI);
}

void check(double x){
  if(x < 18.5){
    printf("あなたは痩せぎみです。\n");
  } else if(x >= 18.5 && x <25){
    printf("あなたは標準的な体型です。\n");
  } else {
    printf("あなたは太りぎみです。\n");
  }
}

void main(){
  double bmi;
  ask();
  bmi = keisan();
  check(bmi);
}

/*
今回は勉強のために身長と体重の変数をフィールド変数として扱いました。
しかし、このコードを見ていると、どうやら変数bmiもフィールド変数にしてもよさそうですね。
ローカル変数として扱っていることによって、main()とkeisan()で同じ値を扱う変数を別々に宣言しています。（bmiとBMIのこと）
複数のメソッドで扱う変数はフィールド変数にしてしまうのが便利だということがわかりますか？

ただし、なんでもかんでもフィールド変数にしてしまえばいいとは限りませんので、乱用には注意しましょう。
*/
