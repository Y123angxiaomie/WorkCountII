#include<stdio.h>
int main(){
	int chars=0;
	int words=0;
	int ch=0;
	int ch1=0;
	int judge=0;
	FILE *fp;
	char name[100]={0};
	char type[2];
	printf("��������Ҫִ�е�ָ�-c��-w��\n"); 
	gets(type);    
	printf("�������ļ�·����");
	scanf("%s",name);
    if((fp = fopen(name,"r")) == NULL)/*fopen��C�������ڴ��ļ��ĺ�����r��ʾ���ļ���ֻ����ʽ��*/
    {
        printf("û���ҵ����ļ� %s\n",name);
        return 0;
    }
	
	if(type[1]=='c'){
		while((ch = fgetc(fp))/*�Ե����ַ���ȡ*/ != EOF){/*EOF��ʾ�ļ�������*/
			if((ch>=48 &&ch<=57) || (ch>=65&&ch<=90) || (ch>=97&&ch<=122) || ch==9 || ch==10 || ch==32)/*A~Z��a~z��0~9��32�ո�9ˮƽ�Ʊ����10���з�*/
				chars++;
			}
		printf("һ����%d���ַ�",chars);
	}
	else if(type[1]=='w'){
		while((ch = fgetc(fp)) != EOF){
			if((ch>=48 &&ch<=57) || (ch>=65&&ch<=90) || (ch>=97&&ch<=122) || ch==10 || ch==9){
				if(judge==0){
					words++;
					judge++;
				}
			}
			else if(ch==32 || ch==44){
				judge=0;
			}
		}
		printf("һ����%d������",words);
	}
	return 0;
}
