#define _CRT_SECURE_NO_WARNINGS

#define SEEK_SET    0   /* ファイルの先頭を基準にする */
#define SEEK_CUR    1   /* その時点でのファイルポインタの位置を基準にする */
#define SEEK_END    2   /* ファイルの終端を基準にする */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE* fp;
	char mojiretsu[1000], command[10], k = '\n',buff[100];
	int c, d, moji = 0/*文字数カウンタ*/, line = 0/*文字列カウンタ*/, n;
	fpos_t ft/*文字位置*/;

	fp = fopen("memo.txt", "r"); // ファイル読み込み
	if (fp == NULL)
	{
		printf("memo.txt を新規作成して書き込みます\n");
		fp = fopen("memo.txt", "w");//書き込みモードでファイル生成
		fclose(fp);//ファイルを閉じる
	}
	else {
		printf("memo.txt に書き込みます\n");
		fclose(fp);//ファイルを閉じる
	}

	fp = fopen("memo.txt", "r");
	printf("ファイルの内容は↓\n");
	while (fgets(buff, 100, fp) != NULL)
	{
		printf("%s", buff);
	}
	printf("\n");
	fclose(fp);

	fp = fopen("memo.txt", "r");
	//ファイルポインタを末尾まで移動
	fseek(fp, 0, SEEK_END);
	//ファイルポインタの位置を取得
	fgetpos(fp, &ft);
	printf("現在のファイルポインタの位置は「%d」です。\n", ft);
	fclose(fp);

	//fp = fopen("memo.txt", "r+");
	while (true)
	{
		printf("コマンドを入力\n");
		scanf("%s", command);


		if (strcmp(command, "end") == 0)//終了
		{
			break;
		}
		else if (strcmp(command, "kaigyou") == 0)//改行
		{
			fp = fopen("memo.txt", "a");//追加書き込み
			fprintf(fp, "%c", k);
			fclose(fp);//ファイルを閉じる
		}
		else if (strcmp(command, "up") == 0)//1文字上に移動
		{
			
		}
		else if (strcmp(command, "right") == 0)//1文字右に移動
		{
			fp = fopen("memo.txt", "r");
			fseek(fp, 1, SEEK_CUR);
			fgetpos(fp, &ft);
			printf("現在のファイルポインタの位置は「%d」です。\n", ft);
			fclose(fp);
		}
		else if (strcmp(command, "down") == 0)//1文字下に移動
		{

		}
		else if (strcmp(command, "left") == 0)//1文字左に移動
		{
			fp = fopen("memo.txt", "r");
			fgetpos(fp, &ft);
			printf("現在のファイルポインタの位置は「%d」です。\n", ft);
			fseek(fp, -1, SEEK_END);
			fgetpos(fp, &ft);
			n = (int)ft;
			printf("現在のファイルポインタの位置は「%d」です。\n", ft);
			fclose(fp);
		}
		else if(strcmp(command, "enter") == 0)//入力モード
		{
			printf("入力\n");
			scanf("%s", mojiretsu);

			fp = fopen("memo.txt", "a");//追加書き込み
			fseek(fp, n, SEEK_SET);
			fprintf(fp, "%s", mojiretsu);
			memset(mojiretsu, '\0', sizeof(mojiretsu));//文字列初期化
			fclose(fp);//ファイルを閉じる
		}
		fp = fopen("memo.txt", "r");
		printf("ファイルの内容は↓\n");
		while (fgets(buff, 100, fp) != NULL)
		{
			printf("%s", buff);
		}
		printf("\n");
		fclose(fp);
	}
	//fclose(fp);//ファイルを閉じる
	return 0;
}