// C検定6-1(51回).cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//----------------------------------
//51回　問５（文字列の検索
//----------------------------------
#include <stdio.h>
#include<math.h>
#include<iostream>
#define MATCH_SIZE 6
int main(void) {
#if 1
	//検索される文字列
	char match[MATCH_SIZE][6] = {
		"AA",//0
		"ABBBA",//1
		"AB",//2
		"AABBA",//3
		"AC",//4
		"AABB"//5
	};
	char target[6];//入力文字（検索する文字列）
	int i, j;//ループカウンター
	int max;//文字列の最大値
	int find[MATCH_SIZE];//検索文字とみつかったときの文字数を入力する
	printf(" 探索文字列：");
	scanf("%s", target);//入力文字（最大６まで入力することが）
	max = -1;//最大値を初期化（すなわち最大値を最小値にしておく）
	//最初の最大値を強制的に最大値するため-1を入れる	
//tagetとmatchの配列をループで調べる
	for (i = 0; i < MATCH_SIZE; i++) {
		find[i] = -1;
		//\0は文字の終端文字
		//左から一文字ずつ同じであるか調べる
		//        mathc     target 
		// i=0  AA          AAB
		// i=1  ABBBA    AAB
		//以下略
		for (j = 0; target[j] != '\0'; j++) {
			//target（入力）と検索される文字列
			if (target[j] != match[i][j])//33（エ）（targetとmatchを一つずつマッチング）
			{
				find[i] = 0;//同じでないならすぐループから脱出
				break;
			}
		}//end of for
		if (find[i] == -1) {//34見つかったなら
			//matchの字数を調べる
			while (match[i][j] != '\0') {//一致した文字をカウント
				j++;//文字数をカウントする
			}
			//-------------------------------------------
			find[i] = j;//一致した文字を配列に入れる
			if (max < j) {//35　文字列がそれまでの最大値より大きければ
				max = j;//maxの値は更新する
			}
		}// end of if
	}//end of for
	printf("\n[%s]で始まる文字列は", target);
	//max=-1のままということは見つからなかった
	if (max == -1) {//36
		printf("みつかりません");
	}
	//見つかったとき
	else {
		for (i = 0; i < MATCH_SIZE; i++) {
			if (find[i] != 0) {
				printf("\n\t[%s]", match[i]);
				if (find[i] == max) {//37みつかった文字の中でmaxと等しい
					printf(" *");//アスタリスクをつける
				}
			}
		}
		printf("\nでした");
	}
#else
	//５１回　問５
	printf("[%04x]\n", 0XCD);
	printf("[%-4d]\n", 291);
	printf("[%8s]\n", "CAT");
	printf("[%-3s]\n", "TIGER");
	printf("[%-6.4s]\n", "ELEPHANT");
#endif
}