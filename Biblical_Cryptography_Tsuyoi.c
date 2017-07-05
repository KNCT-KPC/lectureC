/*
 * 参考
 * 配列を自由自在に作る, "http://9cguide.appspot.com/19-01.html".
 * 5.文字列の操作, "http://www.wakhok.ac.jp/~kanayama/C/02/node148.html".
 */

#include<stdio.h>

#include<stdlib.h>	// malloc()
#include<string.h>	// strlen()

#define ML 512	

void bible(char *s){	// 自作関数　"型 関数名(引数の型 引数名)" で宣言します
	char alp[26] = {'a','b','c','d','e','f','g','h','i','j','k','n','m','l','o','p','q','r','s','t','u','v','w','x','y','z'};
	char ALP[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	int j;
	int n;

	while(*s != NULL){
		for(j=0; j<26; j++){
			if(*s == ' '){
				*s = ' ';
				break;
			}else if(*s == alp[j]){
				n = (26 - j) - 1;
				*s = alp[n];
				break;
			}else if(*s == ALP[j]){
				n = (26 - j) - 1;
				*s = ALP[n];
				break;
			}
		}
		printf("%c", *s);
		*s++;
	}
}


int main(void)
{
	char spell[512];	//512文字分の配列(512文字を超える場合を考えてない)
	char *s;

	int y;
	gets(spell);
	s = (char *)malloc( strlen(spell) + 1);
	
	if(s == NULL) exit(0);	//メモリ確保失敗したら強制的に終了しようね

	strcpy(s, spell);
	
	bible(s);	//聖書

	free(s);	//メモリ使い終わったら解放しようね

	scanf("%d", &y);
	return 0;
}
