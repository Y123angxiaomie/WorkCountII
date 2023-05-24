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
	printf("请输入需要执行的指令（-c，-w）\n"); 
	gets(type);    
	printf("请输入文件路径：");
	scanf("%s",name);
    if((fp = fopen(name,"r")) == NULL)/*fopen是C语言用于打开文件的函数，r表示该文件以只读形式打开*/
    {
        printf("没有找到此文件 %s\n",name);
        return 0;
    }
	
	if(type[1]=='c'){
		while((ch = fgetc(fp))/*对单个字符读取*/ != EOF){/*EOF表示文件结束符*/
			if((ch>=48 &&ch<=57) || (ch>=65&&ch<=90) || (ch>=97&&ch<=122) || ch==9 || ch==10 || ch==32)/*A~Z，a~z，0~9，32空格，9水平制表符，10换行符*/
				chars++;
			}
		printf("一共有%d个字符",chars);
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
		printf("一共有%d个单词",words);
	}
	return 0;
}
