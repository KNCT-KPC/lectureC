#include<stdio.h>

int main(void)
{
	char alp[26] = {'a','b','c','d','e','f','g','h','i','j','k','n','m','l','o','p','q','r','s','t','u','v','w','x','y','z'};
	char ALP[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char text[12] = {'I',' ','h','a','v','e',' ','a',' ','p','e','n'};
	char ango[12];
	int i,j;
	int n;

	for(i=0; i<12; i++){
		for(j=0; j<26; j++){
			if(text[i] == ' '){
				ango[i] = ' ';
				break;
			}else if(text[i] == alp[j]){
				n = (26 - j) - 1;
				ango[i] = alp[n];
				break;
			}else if(text[i] == ALP[j]){
				n = (26 - j) - 1;
				ango[i] = ALP[n];
				break;
			}
		}
		printf("%c", ango[i]);
	}

	scanf("%d", &i);
	return 0;
}

\\問題:このプログラムは"平文→暗号文"とするものです. そこで"暗号文→平文"と復号するプログラムを追加しましょう.
