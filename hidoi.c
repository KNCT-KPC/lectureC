#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define K 10

int main(void){
    // Here your code !
    int r;
    srand((unsigned)time(NULL));
    int a = K+1;
    int c[K] = {};
    
    
    printf("Welcome to ようこそ ジャパリパーク 今日も\n");
    
    while(1){
        r = rand() % K;
        
        switch(r){
            case 0:
                printf("どったん");
                break;
            case 1:
                printf("ばったん");
                break;
            case 2:
                printf("ぎっこん");
                break;
            case 3:
                printf("ばっこん");
                break;
            case 4:
                printf("ずっこん");
                break;
            case 5:
                printf("ばっこん");
                break;
            case 6:
                printf("べっこん");
                break;
            case 7:
                printf("ぼっこん");
                break;
            case 8:
                printf("がったん");
                break;
            case 9:
                printf("ごっとん");
                break;
        }
        
        if(a == r-1) break;
        a = r/2;
        c[r]++;
    }
    
    printf("\nお・お・さ・わ・ぎ♪\n");
    
    printf("\n 集計結果\n%d どったん, %d ばったん, %d ぎっこん, %d ずっこん, %d ばっこん, %d べっこん, %d ぼっこん, %d がったん, %d ごっとん", c[0], c[1], c[2], c[4], c[3]+c[5], c[6], c[7], c[8], c[9]);
    return(a);
}
