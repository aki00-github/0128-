#define _CRT_SECURE_NO_WARNINGS

#define SEEK_SET    0   /* �t�@�C���̐擪����ɂ��� */
#define SEEK_CUR    1   /* ���̎��_�ł̃t�@�C���|�C���^�̈ʒu����ɂ��� */
#define SEEK_END    2   /* �t�@�C���̏I�[����ɂ��� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE* fp;
	char mojiretsu[1000], command[10], k = '\n',buff[100];
	int c, d, moji = 0/*�������J�E���^*/, line = 0/*������J�E���^*/, n;
	fpos_t ft/*�����ʒu*/;

	fp = fopen("memo.txt", "r"); // �t�@�C���ǂݍ���
	if (fp == NULL)
	{
		printf("memo.txt ��V�K�쐬���ď������݂܂�\n");
		fp = fopen("memo.txt", "w");//�������݃��[�h�Ńt�@�C������
		fclose(fp);//�t�@�C�������
	}
	else {
		printf("memo.txt �ɏ������݂܂�\n");
		fclose(fp);//�t�@�C�������
	}

	fp = fopen("memo.txt", "r");
	printf("�t�@�C���̓��e�́�\n");
	while (fgets(buff, 100, fp) != NULL)
	{
		printf("%s", buff);
	}
	printf("\n");
	fclose(fp);

	fp = fopen("memo.txt", "r");
	//�t�@�C���|�C���^�𖖔��܂ňړ�
	fseek(fp, 0, SEEK_END);
	//�t�@�C���|�C���^�̈ʒu���擾
	fgetpos(fp, &ft);
	printf("���݂̃t�@�C���|�C���^�̈ʒu�́u%d�v�ł��B\n", ft);
	fclose(fp);

	//fp = fopen("memo.txt", "r+");
	while (true)
	{
		printf("�R�}���h�����\n");
		scanf("%s", command);


		if (strcmp(command, "end") == 0)//�I��
		{
			break;
		}
		else if (strcmp(command, "kaigyou") == 0)//���s
		{
			fp = fopen("memo.txt", "a");//�ǉ���������
			fprintf(fp, "%c", k);
			fclose(fp);//�t�@�C�������
		}
		else if (strcmp(command, "up") == 0)//1������Ɉړ�
		{
			
		}
		else if (strcmp(command, "right") == 0)//1�����E�Ɉړ�
		{
			fp = fopen("memo.txt", "r");
			fseek(fp, 1, SEEK_CUR);
			fgetpos(fp, &ft);
			printf("���݂̃t�@�C���|�C���^�̈ʒu�́u%d�v�ł��B\n", ft);
			fclose(fp);
		}
		else if (strcmp(command, "down") == 0)//1�������Ɉړ�
		{

		}
		else if (strcmp(command, "left") == 0)//1�������Ɉړ�
		{
			fp = fopen("memo.txt", "r");
			fgetpos(fp, &ft);
			printf("���݂̃t�@�C���|�C���^�̈ʒu�́u%d�v�ł��B\n", ft);
			fseek(fp, -1, SEEK_END);
			fgetpos(fp, &ft);
			n = (int)ft;
			printf("���݂̃t�@�C���|�C���^�̈ʒu�́u%d�v�ł��B\n", ft);
			fclose(fp);
		}
		else if(strcmp(command, "enter") == 0)//���̓��[�h
		{
			printf("����\n");
			scanf("%s", mojiretsu);

			fp = fopen("memo.txt", "a");//�ǉ���������
			fseek(fp, n, SEEK_SET);
			fprintf(fp, "%s", mojiretsu);
			memset(mojiretsu, '\0', sizeof(mojiretsu));//�����񏉊���
			fclose(fp);//�t�@�C�������
		}
		fp = fopen("memo.txt", "r");
		printf("�t�@�C���̓��e�́�\n");
		while (fgets(buff, 100, fp) != NULL)
		{
			printf("%s", buff);
		}
		printf("\n");
		fclose(fp);
	}
	//fclose(fp);//�t�@�C�������
	return 0;
}