#include <stdio.h>

main(){
  int a[10] = {9, 72, 7, 29, 765, 560, 551, 81, 16, 23};
  int c,i,j,z;
  int x = 0;

  printf("何回足し算を行いますか？\n");
  scanf("%d", &c);

  printf("%d 回計算します。\n\n", c);

  for(i=1; i<=c; i++){
    for(j=0; j<10; j++){
      printf("[%d] ", a[j]);
    }
    printf("\n%d回目は何番目の数字を足しますか？\n", i);
    scanf("%d", &z);
    printf("%d番目が選択されました。%dを加算します。\n", z, a[z-1]);

    x += a[z-1];
  }

  printf("計算結果は%dです。\n", x);
}
