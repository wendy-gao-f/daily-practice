#include"stdio.h"
struct student {
	char number[10];
	char name[15];
	char sex[1];
	char address[20];
	char telephone[11];
};
int compare(char temp[10],char input[10]);
int main() {
	int sum = 0,n = 1,flag = 0;
	char input[10],temp[10];
	struct student s[100],*output = new struct student;
	FILE* fp = fopen("rec.txt", "w+");
	if (fp == NULL) {
		printf("Fail to open file!\n");
		return 0;
	}
	printf("����ѧ������\n");
	scanf("%d", &sum);
	printf("����ѧ����Ϣ:ѧ�� ���� �Ա� ��ַ �ֻ���\nע��0�������ԣ�1����Ů��\n");
	for (int i = 0; i < sum; i++) {
		scanf("%s %s %s %s %s", s[i].number, s[i].name, s[i].sex, s[i].address,s[i].telephone);
		fprintf(fp,"%s %s %s %s %s\n", s[i].number, s[i].name, s[i].sex, s[i].address,s[i].telephone);	
	}
	printf("�������\n");
	printf("��ʼ��ѯ\n");
	rewind(fp);
		printf("��������ѯѧ����ѧ��\n");
		for (int i = 0; i < 10; i++) {
			scanf("%c", &input[i]);
		}
	while (n<=sum) {
		fread(temp, sizeof(char), 10, fp);
		fseek(fp, -10, SEEK_CUR);
		for(int i = 0;i<10;i++){
			printf("input:%c temp:%c",input[i],temp[i]);
			if(temp[i] == input[i]) flag++;
		}
		printf("flag:%d",flag);
		if(flag == 9) {
			printf("ok\n");
			fread(output, sizeof(struct student), 1, fp);
			printf("%c %c %c %c %c\n", output->number, output->name, output->sex, output->address, output->telephone);
			for(int i = 0;i<10;i++){
				printf("%c",output->number[i]);
			}
			for(int i = 0;i<15;i++){
				printf("%c",output->name[i]);
			}
			for(int i = 0;i<1;i++){
				printf("%c",output->sex[i]);
			}
			for(int i = 0;i<20;i++){
				printf("%c",output->address[i]);
			}
			for(int i = 0;i<11;i++){
				printf("%c",output->telephone[i]);
			}
			break;
		}
		else {
			fseek(fp, sizeof(struct student), SEEK_CUR);
			n++;
		}
	}
	if (n > sum) printf("��ѯʧ��");
	fclose(fp);
}




