#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


/*
1.fopen�����ļ���
��غ��� fopen��fclose
��ͷ�ļ� #include<stdio.h>
���庯�� FILE * fopen(const char * path,const char * mode);
����˵�� ����path�ַ����������򿪵��ļ�·�����ļ���������mode�ַ��������������̬��
mode�����м�����̬�ַ���:
r 	��ֻ���ļ������ļ�������ڡ�
r+ 	�򿪿ɶ�д���ļ������ļ�������ڡ�
w 	��ֻд�ļ������ļ��������ļ�������Ϊ0�������ļ����ݻ���ʧ�����ļ��������������ļ���
w+ 	�򿪿ɶ�д�ļ������ļ��������ļ�������Ϊ�㣬�����ļ����ݻ���ʧ�����ļ��������������ļ���
a 	�Ը��ӵķ�ʽ��ֻд�ļ������ļ������ڣ���Ὠ�����ļ�������ļ����ڣ�д������ݻᱻ�ӵ��ļ�β�����ļ�ԭ�ȵ����ݻᱻ������
a+ 	�Ը��ӷ�ʽ�򿪿ɶ�д���ļ������ļ������ڣ���Ὠ�����ļ�������ļ����ڣ�д������ݻᱻ�ӵ��ļ�β�󣬼��ļ�ԭ�ȵ����ݻᱻ������
 
��������̬�ַ����������ټ�һ��b�ַ�����rb��wb+��ab������ϣ�����b �ַ��������ߺ�����򿪵��ļ�Ϊ�������ļ������Ǵ������ļ���������POSIXϵͳ������Linux������Ը��ַ�����fopen()�����������ļ������S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH(0666)Ȩ�ޣ����ļ�Ȩ��Ҳ��ο�umaskֵ��
����ֵ �ļ�˳���򿪺�ָ��������ļ�ָ��ͻᱻ���ء������ļ���ʧ���򷵻�NULL�����Ѵ���������errno �С�
����˵�� һ����ԣ����ļ������һЩ�ļ���ȡ��д��Ķ����������ļ�ʧ�ܣ��������Ķ�д����Ҳ�޷�˳�����У�������fopen()�����������жϼ�����
*/

/*
2. fprintf
���ܣ����͸�ʽ�������һ���ļ���
��ͷ�ļ���#include<stdio.h>
����ԭ�ͣ�int fprintf(FILE *stream, char *format[, argument,...]);
FILE* һ��FILE�͵�ָ��
char* ��ʽ�����뺯������printf��ĸ�ʽһ��
����ֵ���ɹ�ʱ����ת�����ֽ�����ʧ��ʱ����һ������
fp = fopen("/local/test.c","a+");
fprintf(fp,"%s\n",str);
*/

/*
3. fscanf
���ܣ���һ������ִ�и�ʽ������,fscanf�����ո�ͻ���ʱ������ע��ո�ʱҲ����������fgets������fgets�����ո񲻽�����
��ͷ�ļ���#include<stdio.h>
����ԭ�ͣ�int fscanf(FILE *stream, char *format[,argument...]);
FILE* һ��FILE�͵�ָ��
char* ��ʽ�������������scanf��ĸ�ʽһ��
����ֵ���ɹ�ʱ����ת�����ֽ�����ʧ��ʱ����һ������
fp = fopen("/local/test.c","a+");
fscanf(fp,"%s",str);
*/

/*add_content_to_file*/
int fprintf_test(){
    FILE * fp;
    time_t t;
  
    fp=fopen("test_file.t","a+");
    //if(fp==NULL) return -1;
	char* str ="=============== 2.fprintf test ===============";
    time(&t); //get current time
	fprintf(fp,"%s@%s",str,ctime(&t));
	
	fseek(fp,0,SEEK_SET);
	char* str1;
	str1 = (char*)malloc(100);
	fscanf(fp,"%s",str1);
	printf("%s\n",str1);
	free(str1);
	
	fclose(fp);
	
    return 0;
} 

/*
4. clearerr������ļ����Ĵ�����꣩
��غ��� feof
��ͷ�ļ� #include<stdio.h>
���庯�� void clearerr(FILE * stream);
����˵�� clearerr�����������streamָ�����ļ�����ʹ�õĴ�����ꡣ
*/

/*
5.fclose���ر��ļ���
��غ��� fclose��fflush��fopen��setbuf
��ͷ�ļ� #include<stdio.h>
���庯�� int fclose(FILE * stream);
����˵�� fclose()�����ر���ǰfopen()�򿪵��ļ����˶������û������ڵ�����д���ļ��У����ͷ�ϵͳ���ṩ���ļ���Դ��
����ֵ �����ļ������ɹ��򷵻�0���д�����ʱ�򷵻�EOF���Ѵ������浽errno��
������� EBADF��ʾ����stream���Ѵ򿪵��ļ���
���� ��ο�fopen������
*/

/* 
6.fdopen�����ļ�������תΪ�ļ�ָ�룩
��غ��� fopen��open��fclose
��ͷ�ļ� #include<stdio.h>
���庯�� FILE * fdopen(int fildes,const char * mode);
����˵�� fdopen()�Ὣ����fildes ���ļ������ʣ�ת��Ϊ��Ӧ���ļ�ָ��󷵻ء�����mode �ַ�����������ļ�ָ�������̬������̬�����ԭ���ļ������ʶ�дģʽ��ͬ������mode �ַ�����ʽ��ο�fopen()��
����ֵ ת���ɹ�ʱ����ָ��������ļ�ָ�롣ʧ���򷵻�NULL�����Ѵ���������errno�С�
*/

int fdopen_test(){
    //FILE * fp =fdopen(STDIN_FILENO,"w+");
    FILE * fp =fdopen(1,"w+");
    if(fp == NULL){
        printf("fdopen return NULL !\n");
        return -1;
    }
    fprintf(fp,"%s\n","hello!");
    fclose(fp);
    return 0;
} 

/* 
7.feof������ļ����Ƿ�������ļ�β��
��غ��� fopen��fgetc��fgets��fread
��ͷ�ļ� #include<stdio.h>
���庯�� int feof(FILE * stream);
����˵�� feof()��������Ƿ��ȡ�����ļ�β��β��streamΪfopen����������֮�ļ�ָ�롣����ѵ��ļ�β�򷵻ط���ֵ�������������0��
����ֵ ���ط���ֵ�����ѵ����ļ�β��
 */

/* ��
8.fflush�����»�������
��غ��� write��fopen��fclose��setbuf
��ͷ�ļ� #include<stdio.h>
���庯�� int fflush(FILE* stream);
����˵�� fflush()��ǿ�Ƚ��������ڵ�����д�ز���streamָ�����ļ��С��������streamΪNULL��fflush()�Ὣ���д򿪵��ļ����ݸ��¡�
����ֵ �ɹ�����0��ʧ�ܷ���EOF������������errno�С�
������� EBADF ����stream ָ�����ļ�δ���򿪣����״̬Ϊֻ���������������ο�write������ 
*/

/* 
9.fgetc�����ļ��ж�ȡһ���ַ���
��غ��� fopen��fread��fscanf��fgetc
��ͷ�ļ� include<stdio.h>
���庯�� int fgetc(FILE * stream);
����˵�� fgetc()�Ӳ���stream��ָ���ļ��ж�ȡһ���ַ����������ļ�β��������ʱ�㷵��EOF��
����ֵ getc()�᷵�ض�ȡ�����ַ���������EOF���ʾ�����ļ�β��
*/

int fgetc_test(){
    FILE *fp;
    int c;
    fp=fopen("test_file.t","r");
    if(fp ==NULL) {
        printf("test_file not exist!\n");
        return -1;
    }
    while((c=fgetc(fp))!=EOF)
    printf("%c",c);
    fclose(fp);
    return 0;
} 

/* 
10.fgets�����ļ��ж�ȡһ�ַ�����
��غ��� open��fread��fscanf��fgetc
��ͷ�ļ� include<stdio.h>
���庯�� har * fgets(char * s,int size,FILE * stream);
����˵�� fgets()�����Ӳ���stream��ָ���ļ��ڶ����ַ����浽����s��ָ���ڴ�ռ䣬ֱ�����ֻ����ַ��������ļ�β�����Ѷ���size-1���ַ�Ϊֹ���������NULL��Ϊ�ַ���������
����ֵ gets()���ɹ��򷵻�sָ�룬����NULL���ʾ�д�������
*/

int fgets_test()
{
    char s[80];
    fputs(fgets(s,80,stdin),stdout);
    return 0;
}

/*  
11.fileno�������ļ�����ʹ�õ��ļ������ʣ�
��غ��� fopen��fopen
��ͷ�ļ� #include<stdio.h>
���庯�� int fileno(FILE * stream);
����˵�� fileno()����ȡ�ò���streamָ�����ļ�����ʹ�õ��ļ������ʡ�
����ֵ �����ļ������ʡ�
 */

int fileno_test(){
    FILE * fp;
    int fd;
    fp=fopen("test_file.t","r");
    if(fp == NULL){
        printf("test_file not exist!\n");
        return -1;
    }
    fd=fileno(fp);
    printf("test_file.t fd=%d\n",fd);
    fclose(fp);
    return 0;
} 

/* 
12.fputc����һָ���ַ�д���ļ����У�
��غ��� fopen��fwrite��fscanf��fputc
��ͷ�ļ� #include<stdio.h>
���庯�� int fputc(int c,FILE * stream);
����˵�� fputc �Ὣ����c תΪunsigned char ��д�����stream ָ�����ļ��С�
����ֵ fputc()�᷵��д��ɹ����ַ���������c��������EOF�����д��ʧ�ܡ�
 */

int fputc_test(){
    FILE * fp;
    char a[26]="abcdefghijklmnopqrstuvwxyz";
    int i;
    fp= fopen("test_file.txt","w");
    for(i=0;i<26;i++)
        fputc((int)a,fp);
    fclose(fp);
    return 0;
} 

/* 
13.fputs����һָ�����ַ���д���ļ��ڣ�
��غ��� fopen��fwrite��fscanf��fputc��putc
��ͷ�ļ� #include<stdio.h>
���庯�� int fputs(const char * s,FILE * stream);
����˵�� fputs()����������s��ָ���ַ���д�뵽����stream��ָ���ļ��ڡ�
����ֵ ���ɹ��򷵻�д�����ַ�����������EOF���ʾ�д�������
 */

/* 
14.fread�����ļ�����ȡ���ݣ�
��غ��� fopen��fwrite��fseek��fscanf
��ͷ�ļ� #include<stdio.h>
���庯�� size_t fread(void * ptr,size_t size,size_t nmemb,FILE * stream);
����˵�� fread()�������ļ����ж�ȡ���ݡ�����streamΪ�Ѵ򿪵��ļ�ָ�룬����ptr ָ������Ŷ�ȡ���������ݿռ䣬��ȡ���ַ����Բ���size*nmemb��������Fread()�᷵��ʵ�ʶ�ȡ����nmemb��Ŀ�������ֵ�Ȳ���nmemb ����С���������ܶ������ļ�β���д���������ʱ������feof()��ferror()����������ʲô�����
����ֵ ����ʵ�ʶ�ȡ����nmemb��Ŀ��
 */

#define nmemb 3
struct test{
char name[20];
int size;
}s[nmemb];

int fread_test(){
    FILE * stream;
    int i;
    stream = fopen("test_file.t","r");
    if(stream == NULL){
        printf("test_file not exist!\n");
        return -1;
    }
    fread(s,sizeof(struct test),nmemb,stream);
    fclose(stream);
    for(i=0;i<nmemb;i++)
        printf("name[%d]=%-20s:size[%d]=%d\n",i,s[i].name,i,s[i].size);
    return 0;
} 

/* 
15.freopen�����ļ���
��غ��� fopen��fclose
��ͷ�ļ� #include<stdio.h>
���庯�� FILE * freopen(const char * path,const char * mode,FILE * stream);
����˵�� ����path�ַ����������򿪵��ļ�·�����ļ���������mode��ο�fopen()˵��������streamΪ�Ѵ򿪵��ļ�ָ�롣Freopen()�Ὣԭstream���򿪵��ļ����رգ�Ȼ��򿪲���path���ļ���
����ֵ �ļ�˳���򿪺�ָ��������ļ�ָ��ͻᱻ���ء�����ļ���ʧ���򷵻�NULL�����Ѵ���������errno �С�
 */

int freopen_test(){
    FILE * fp;
    fp=fopen("/etc/passwd","r");
    fp=freopen("/etc/group","r",fp);
    fclose(fp);
    return 0;
} 

/* 
16.fseek���ƶ��ļ����Ķ�дλ�ã�
��غ��� rewind��ftell��fgetpos��fsetpos��lseek
��ͷ�ļ� #include<stdio.h>
���庯�� int fseek(FILE * stream,long offset,int whence);
����˵�� fseek()�����ƶ��ļ����Ķ�дλ�á�����streamΪ�Ѵ򿪵��ļ�ָ�룬����offsetΪ���ݲ���whence���ƶ���дλ�õ�λ������
���� whenceΪ��������һ��:
SEEK_SET�Ӿ��ļ���ͷoffsetλ����Ϊ�µĶ�дλ�á�SEEK_CUR ��Ŀǰ�Ķ�дλ����������offset��λ������
SEEK_END����дλ��ָ���ļ�β��������offset��λ������
��whenceֵΪSEEK_CUR ��SEEK_ENDʱ������offset����ֵ�ĳ��֡�
�����ǽ��ر��ʹ�÷�ʽ:
1) ������дλ���ƶ����ļ���ͷʱ:fseek(FILE *stream,0,SEEK_SET);
2) ������дλ���ƶ����ļ�βʱ:fseek(FILE *stream,0,0SEEK_END);
����ֵ �����óɹ�ʱ�򷵻�0�����д����򷵻�-1��errno���Ŵ�����롣
����˵�� fseek()����lseek()�᷵�ض�дλ�ã���˱���ʹ��ftell()��ȡ��Ŀǰ��д��λ�á�
 */

int fseek_test(){
    FILE * stream;
    long offset;
    fpos_t pos;
    stream=fopen("test_file.t","r");
    if(stream == NULL){
        printf("test_file not exist!\n");
        return -1;
    }
    fseek(stream,5,SEEK_SET);
    printf("offset=%d\n",ftell(stream));
    rewind(stream);
    fgetpos(stream,&pos);
    printf("offset=%d\n",pos);
    pos=10;
    fsetpos(stream,&pos);
    printf("offset = %d\n",ftell(stream));
    fclose(stream);
    return 0;
} 

/* 
17.ftell��ȡ���ļ����Ķ�ȡλ�ã�
��غ��� fseek��rewind��fgetpos��fsetpos
��ͷ�ļ� #include<stdio.h>
���庯�� long ftell(FILE * stream);
����˵�� ftell()����ȡ���ļ���Ŀǰ�Ķ�дλ�á�����streamΪ�Ѵ򿪵��ļ�ָ�롣
����ֵ �����óɹ�ʱ�򷵻�Ŀǰ�Ķ�дλ�ã����д����򷵻�-1��errno���Ŵ�����롣
������� EBADF ����stream��Ч����ƶ���дλ�õ��ļ�����
*/

/* 
18.fwrite��������д���ļ�����
��غ��� fopen��fread��fseek��fscanf
��ͷ�ļ� #include<stdio.h>
���庯�� size_t fwrite(const void * ptr,size_t size,size_t nmemb,FILE * stream);
����˵�� fwrite()����������д���ļ����С�����streamΪ�Ѵ򿪵��ļ�ָ�룬����ptr ָ����д������ݵ�ַ���ܹ�д����ַ����Բ���size*nmemb��������Fwrite()�᷵��ʵ��д���nmemb��Ŀ��
����ֵ ����ʵ��д���nmemb��Ŀ��
 */

#define set_s(x,y) {strcpy(s[x].name,y);s[x].size=strlen(y);}

int fwrite_test(){
    FILE * stream;
    set_s(0,"Linux!");
    set_s(1,"FreeBSD!");
    set_s(2,"Windows2000.");
    stream=fopen("test_file.t","a+");
    fwrite(s,sizeof(struct test),nmemb,stream);
    fclose(stream);
    return 0;
} 

/* 
19.getc�����ļ��ж�ȡһ���ַ���
��غ��� fread��fopen��fread��getc
��ͷ�ļ� #include<stdio.h>
���庯�� int getc(FILE * stream);
����˵�� getc()�����Ӳ���stream��ָ���ļ��ж�ȡһ���ַ����������ļ�β��������ʱ�㷵��EOF����Ȼgetc()��fgetc()������ͬ����getc()Ϊ�궨�壬�������ĺ������á�
����ֵ getc()�᷵�ض�ȡ�����ַ���������EOF���ʾ�����ļ�β��
���� �ο�fgetc()��
�� */


/* 
20.getchar���ɱ�׼�����豸�ڶ���һ�ַ���
��غ��� fopen��fread��fscanf��getc
��ͷ�ļ� #include<stdio.h>
���庯�� int getchar(void);
����˵�� getchar()�����ӱ�׼�����豸�ж�ȡһ���ַ���Ȼ�󽫸��ַ���unsigned charת����int�󷵻ء�
����ֵ getchar()�᷵�ض�ȡ�����ַ���������EOF���ʾ�д�������
����˵�� getchar()����������������getc(stdin)�궨�塣
 */

int getchar_test(){
    FILE * fp;
    int c,i;
    for(i=0;i<5;i++){
        c=getchar();
        putchar(c);
    }
    return 0;
} 

/* 
21.gets���ɱ�׼�����豸�ڶ���һ�ַ�����
��غ��� fopen��fread��fscanf��fgets
��ͷ�ļ� #include<stdio.h>
���庯�� char * gets(char *s);
����˵�� gets()�����ӱ�׼�豸�����ַ����浽����s��ָ���ڴ�ռ䣬ֱ�����ֻ����ַ�������ļ�βΪֹ��������NULL��Ϊ�ַ���������
����ֵ gets()���ɹ��򷵻�sָ�룬����NULL���ʾ�д�������
����˵�� ����gets()�޷�֪���ַ���s�Ĵ�С���������������ַ����ļ�β�Ż�������룬���������ɻ�������İ�ȫ�����⡣����ʹ��fgets()ȡ����
���� �ο�fgets()
�� */


/* 
22.mktemp������Ψһ����ʱ�ļ�����
��غ��� tmpfile
��ͷ�ļ� #include<stdlib.h>
���庯�� char * mktemp(char * template);
����˵�� mktemp()��������Ψһ����ʱ�ļ���������template��ָ���ļ������ַ�������������ַ�������XXXXXX����������ļ�������ַ���ָ�뷵�ء�
����ֵ �ļ�˳���򿪺�ָ��������ļ�ָ��ͻᱻ���ء�����ļ���ʧ���򷵻�NULL�����Ѵ���������errno�С�
����˵�� ����template��ָ���ļ������ַ�����������Ϊ���飬��:
char template[ ]=��template-XXXXXX����
������char * template=��template-XXXXXX����
������
 
#include<stdlib.h>
int main(){
    char template[]="template-XXXXXX";
    mktemp(template);
    printf("template=%s/n",template);
    return 0;
}  
*/

/* 
23.putc����һָ���ַ�д���ļ��У�
��غ��� fopen��fwrite��fscanf��fputc
��ͷ�ļ� #include<stdio.h>
���庯�� int putc(int c,FILE * stream);
����˵�� putc()�Ὣ����cתΪunsigned char��д�����streamָ�����ļ��С���Ȼputc()��fputc()������ͬ����putc()Ϊ�궨�壬�������ĺ������á�
����ֵ putc()�᷵��д��ɹ����ַ���������c��������EOF�����д��ʧ�ܡ�
���� �ο�fputc������
�� */

/* 
24.putchar����ָ�����ַ�д����׼����豸��
��غ��� fopen��fwrite��fscanf��fputc
��ͷ�ļ� #include<stdio.h>
���庯�� int putchar (int c);
����˵�� putchar()����������c�ַ�д����׼����豸��
����ֵ putchar()�᷵������ɹ����ַ���������c��������EOF��������ʧ�ܡ�
����˵�� putchar()����������������putc(c��stdout)�궨�塣
���� �ο�getchar()��
�� */

/* 
25.rewind�������ļ����Ķ�дλ��Ϊ�ļ���ͷ��
��غ��� fseek��ftell��fgetpos��fsetpos
��ͷ�ļ� #include<stdio.h>
���庯�� void rewind(FILE * stream);
����˵�� rewind()�������ļ����Ķ�дλ�������ļ���ͷ������streamΪ�Ѵ򿪵��ļ�ָ�롣�˺����൱�ڵ���fseek(stream,0,SEEK_SET)��
����ֵ
���� �ο�fseek()
 */

/* 
26.setbuf�������ļ����Ļ�������
��غ��� setbuffer��setlinebuf��setvbuf
��ͷ�ļ� #include<stdio.h>
���庯�� void setbuf(FILE * stream,char * buf);
����˵�� �ڴ��ļ����󣬶�ȡ����֮ǰ������setbuf()�������������ļ����Ļ�����������streamΪָ�����ļ���������bufָ���Զ��Ļ�������ʼ��ַ���������bufΪNULLָ�룬��Ϊ�޻���IO��Setbuf()�൱�ڵ���:setvbuf(stream,buf,buf?_IOFBF:_IONBF,BUFSIZ)
����ֵ
�� */

/* 
27.setbuffer�������ļ����Ļ�������
��غ��� setlinebuf��setbuf��setvbuf
��ͷ�ļ� #include<stdio.h>
���庯�� void setbuffer(FILE * stream,char * buf,size_t size);
����˵�� �ڴ��ļ����󣬶�ȡ����֮ǰ������setbuffer()�����������ļ����Ļ�����������streamΪָ�����ļ���������bufָ���Զ��Ļ�������ʼ��ַ������sizeΪ��������С��
����ֵ
 */

/* 
28.setlinebuf�������ļ���Ϊ���Ի�������
��غ��� setbuffer��setbuf��setvbuf
��ͷ�ļ� #include<stdio.h>
���庯�� void setlinebuf(FILE * stream);
����˵�� setlinebuf()���������ļ����Ի���Ϊ���ݵ��޻���IO���൱�ڵ���:setvbuf(stream,(char * )NULL,_IOLBF,0);��ο�setvbuf()��
����ֵ
 */

/* 
29.setvbuf�������ļ����Ļ�������
��غ��� setbuffer��setlinebuf��setbuf
��ͷ�ļ� #include<stdio.h>
���庯�� int setvbuf(FILE * stream,char * buf,int mode,size_t size);
����˵�� �ڴ��ļ����󣬶�ȡ����֮ǰ������setvbuf()�������������ļ����Ļ�����������streamΪָ�����ļ���������bufָ���Զ��Ļ�������ʼ��ַ������sizeΪ��������С������mode�����м���
_IONBF �޻���IO
_IOLBF �Ի���Ϊ���ݵ��޻���IO
_IOFBF ��ȫ�޻���IO���������bufΪNULLָ�룬��Ϊ�޻���IO��
����ֵ
 */

/* 
30.ungetc����ָ���ַ�д���ļ����У�
��غ��� fputc��getchar��getc
��ͷ�ļ� #include<stdio.h>
���庯�� int ungetc(int c,FILE * stream);
����˵�� ungetc()������c�ַ�д�ز���stream��ָ�����ļ��������д�ص��ַ�������һ����ȡ�ļ����ĺ���ȡ�á�
����ֵ �ɹ��򷵻�c �ַ������д����򷵻�EOF��
 */


int file_mtest(){
	FILE *fp = NULL;
	char* str;
	char re;
	int num = 10;
	str = (char*)malloc(100);
	//snprintf(str, 10,"test: %s", "0123456789012345678");
	//printf("str=%s\n", str);
	fp = fopen("test_file.t","a+");
	
	//fseek(fp,-1,SEEK_END);
	num = ftell(fp);
	printf("test file long:%d\n",num);
	//fscanf(fp,"%s",str);
	//printf("str = %s\n",str);
	while ((re=getc(fp))!=EOF){//getc��������fgetc��
		printf("%c",re);
	}
    
	//fread(str,10,10,fp);
	fgets(str,100,fp);
	printf("str: %s\n",str);
	//sprintf(str,"xiewei test is:%s", "ABCDEFGHIGKMNI");
	//printf("str2=%s\n", str);
	//fprintf(fp,"%s\n",str);
	fwrite(str,2,10,fp);
	num = ftell(fp);
	if(str!=NULL){
		free(str);
	}
	fclose(fp);
	return 0;
}


/*file operation test */
void file_test(void)
{
    int n;
    
    while(1)
    {
        printf("\n2.fprintf\t 6.fdopen\t 9.fgetc\t 11.fileno\t 14.fread\t 16.fseek\t 18.fwrite\t \n");
        printf("Choose file test option :");
        fscanf(stdin,"%d",&n);
        switch(n)
        {
        case 2:
            fprintf_test();
        break;
        case 6:
            fdopen_test();
        break;
        case 9:
            fgetc_test();
        break;
        case 11:
            fileno_test();
        break;
        case 14:
            fread_test();
        break;
        case 16:
            fseek_test();
        break;
        case 18:
            fwrite_test();
        break;
        
        default:
            file_mtest();
            break;
        }
        getchar();
        if(0 == n)
            break;
    }
    //fgets_test();
    //fileno_test();
}