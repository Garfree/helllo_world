#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <alloc.h>
//#include <mem.h>
#include <errno.h>
/* for getch() */
//#include <conio.h>
//#include<syslib.h>


/*
@����ԭ��:  char *strdup(const char *s); 
��������:  �ַ���������Ŀ�Ŀռ��ɸú�������  
��������:  ָ�򿽱�����ַ���ָ�� 
����˵��:  src-��������Դ�ַ��� 
*/

/*
@��������:  strcpy 
����ԭ��:  char *strcpy(char* dest, const char *src);
��������:  ��str2ָ����ַ���������str1��ȥ 
��������:  ����str1,��ָ��str1��ָ�� 
����˵��:  src��dest��ָ�ڴ����򲻿����ص���dest�������㹻�Ŀռ�������src���ַ�����
*/

/*
@��������:  strncpy 
����ԭ��:  char *strncpy(char *dest, const char *src��intcount);
��������:  ���ַ���src�е�count���ַ��������ַ���dest��ȥ 
��������:  ָ��dest��ָ�� 
����˵��:  dest-Ŀ���ַ�����src-Դ�ַ�����count-�������ַ����� 
ע�⣺strncpyֻ����ָ�����ȵ��ַ��������Զ���ĩβ��'\0'����ָ�����ȳ���Դ�ַ������ȣ������Ĳ��ֲ���\0��
1
*/

int strdup_test()   
{   
    char str[10];
    char *dup_str, *string="abcde";   
    dup_str=strdup(string);   
    printf("strdup get: %s\n", dup_str);   
    
    strcpy(str,dup_str);   
    printf("strcpy get: %s\n",str);
    free(dup_str);   
    
    char*src = "bbbbbbbbbbbbbbbbbbbb";//20 'b's  
    char dest[50] ="aaaaaaaaaaaaaaaaaaaa";//20 'a's    
    puts(dest);
    puts(src);
    strncpy(dest, src, 10);    
    //puts(dest);
    printf("strncpy get:%s\n",dest);
    
    return 0;   
}

/*
@��������:  strcat 
����ԭ��:  char* strcat(char * str1,char * str2); 
��������:  ���ַ���str2�ӵ�str1����,str1����'\0'��ȡ�� 
��������:  str1 
����˵��: 
*/

/*
@��������:  strncat 
����ԭ��:  char *strncat(char *dest, const char *src, size_t maxlen);
��������:  ���ַ���src��ǰmaxlen���ַ����ӵ�dest�� 
��������: 
ע�⣺��strncpy��ͬ���ǣ�strncat���Զ���ĩβ�ӡ�\0������ָ�����ȳ���Դ�ַ������ȣ���ֻ����Դ�ַ������ȼ�ֹͣ
2
*/

int strcat_test()   
{   
    char buffer[80];  
    strcpy(buffer,"Hello ");   
    strcat(buffer,"world");
    puts("Hello");
    puts("world");
    printf("strcat get: %s\n",buffer);   
    
    //strcpy(buffer,"Hello ");   
    strncat(buffer,"string",3);   
    printf("strncat get: %s\n",buffer);   
    strncat(buffer,"*************",3);   
    printf("%s\n",buffer);   
    
    return 0;   
}  

/*
@��������:  strcmp 
����ԭ��:  int strcmp(char * str1,char * str2); 
��������:  �Ƚ������ַ���str1,str2. 
��������:  str1<str2,���ظ���;str1=str2,���� 0;str1>str2,��������.  
����˵��:
*/

/*
@��������:  strncmp 
����ԭ��:  int strncmp(char *str1,char *str2,int count);
��������:  ��str1��str2�е�ǰcount���ַ����ֵ�˳��Ƚ� 
��������:  С��0��str1<str2������0��str1=str2������0��str1>str2 
����˵��:  str1,str2-���Ƚϵ��ַ�����count-�Ƚϵĳ��� 
3
*/

int strcmp_test()   
{
    char *str1="aaa", *str2="abb",*str3="cbc";   
    int ret;
    puts(str1);
    puts(str2);
    puts(str3);    
    ret=strcmp(str3, str1);   
    printf("strcmp(str3,str1) get: %d\n",ret);
    
    //Ϊʹ���Գ�����������˴��ٶ���strncmpֻ����-1,0,1������  
    char res_info[] = {'<','=','>'};
    //ǰ1���ַ��Ƚ�  
    ret = strncmp(str1, str2, 1);  
    printf("strncmp(str1, str2, 1) get: str1%c str2\n", res_info[ret+1]);
    //ǰ3���ַ��Ƚ�  
    ret = strncmp(str1, str2, 3);
    printf("strncmp(str1, str2, 3) get: str1%c str2\n", res_info[ret+1]);
    
    return 0;   
}  

/*
@��������:  strpbrk 
����ԭ��:  char *strpbrk(const char *s1, const char *s2);
��������:  �õ�s1�е�һ����ͬʱҲ������s2�С��ַ���λ��ָ�� 
��������:  λ��ָ�� 
4
*/

int strpbrk_test()   
{   
    char *p="Find all vowels";
    printf("Find all vowels:\n");
    p=strpbrk(p+1,"aeiouAEIOU");  
    while(p)  
    {  
        printf("%s\n",p);  
        p=strpbrk(p+1,"aeiouAEIOU");  
    }  
    return 0;   
}  


/*
@��������:  strcspn 
����ԭ��:  int strcspn(const char *s1, const char *s2);
��������:  ͳ��s1�д�ͷ��ʼֱ����һ��������s2�е��ַ������ֵĳ��� 
��������:  ���� 
*/

/*
@��������:  strspn 
����ԭ��:  int strspn(const char *s1, const char *s2);
��������:  ͳ��s1�д�ͷ��ʼֱ����һ����������s2�е��ַ������ֵĳ��� 
��������:  ����
5
*/

int strspn_test()   
{   
    char * str1="abcbcadef";
    char * str2="cba";
    puts(str1);
    puts(str2);
    printf("strcspn --str2's c in str1 pos: %d\n",strcspn(str1,str2));

    printf("strspn --str2's c not in str1 pos: %d\n",strspn(str1,str2));
    //printf("%d\n",strspn("xxxbcadef","cba"));  
    //printf("%d\n",strspn("123456789","cba"));  
    return 0;
}  

/*
@��������:  strchr 
����ԭ��:  char* strchr(char* str,char ch); 
��������:  �ҳ�strָ����ַ����е�һ�γ����ַ�ch��λ�� 
��������:  ����ָ���λ�õ�ָ��,���Ҳ���,�򷵻ؿ�ָ�� 
����˵��:  str-���������ַ�����ch-���ҵ��ַ� 

@��������:  strrchr 
����ԭ��:  char *strrchr(const char *s, int c);
��������:  �õ��ַ���s�����һ������c�ַ���λ��ָ�� 
��������:  λ��ָ�� 
6
*/

int strchr_test()   
{   
    char *str = "This is a string!";  
    char ch;  
    char *p;
    char *ptr;    
    getchar();//Enter
    puts(str);
    while(1)  
    {  
        printf("Please input a char:");  
        ch = getchar();  
        p  = strchr(str, ch);
        ptr= strrchr(str,ch);
        if(p)
            printf("strchr: %c is the %d character of\"%s\"\n",ch, (int)(p-str+1),str);
        else
            printf("strchr: Not found!\n");
        
        if(ptr)
            printf("strrchr: %c is the %d character of\"%s\"\n",ch, (int)(ptr-str+1),str);
        else
            printf("strrchr: Not found!\n");
        
        
        printf("Press ESC to quit!\n\n");  
        if(27 == getchar()) //getch()  
            break;  
        fflush(stdin);  
    }  
    
    return 0;   
}  

/*
@��������:  strstr 
����ԭ��:  char* strstr(char* str1,char* str2); 
��������:  �ҳ�str2�ַ�����str1�ַ����е�һ�γ��ֵ�λ��(������str2�Ĵ�������) 
��������:  ���ظ�λ�õ�ָ��,���Ҳ���,���ؿ�ָ�� 
7
*/

int strstr_test()   
{   
    char *str1="Open Watcom C/C++",*str2="Watcom",*ptr;   
    puts(str1);
    puts(str2);
    ptr=strstr(str1,str2);   
    printf("The substring is:%s\n",ptr);   
    return 0;   
}  

/*
@��������:  strrev 
����ԭ��:  char *strrev(char *s);
��������:  ���ַ����е������ַ��ߵ��������� 
��������:  ָ��s��ָ��  
8
�Ǳ꺯��������Ϊʵ��Դ�룺
*/
char* strrev(char* s)  
{  
    /* hָ��s��ͷ�� */  
    char* h = s;      
    char* t = s;  
    char ch;  
    
    /* tָ��s��β�� */  
    while(*t++){} ;  
    t--;    /* ��t++���� */  
    t--;    /* ������������'\0' */  
    
    /* ��h��tδ�غ�ʱ������������ָ����ַ� */  
    while(h < t)  
    {  
        ch = *h;  
        *h++ = *t;    /* h��β���ƶ� */  
        *t-- = ch;    /* t��ͷ���ƶ� */  
    }  
    return(s);  
}  

int strrev_test()   
{   
    char forward[]="string"; //ԭ���ж���Ϊchar*�ǲ��Եģ�ָ�����ε�ָ�������ǲ��ɱ��  
    printf("Before strrev(): %s\n",forward);   
    strrev(forward);   
    printf("Afterstrrev(): %s\n",forward);   
    return 0;   
}  


/*
@��������:  strnset 
����ԭ��:  char *strnset(char *s, int ch, size_t n);
��������:  ���ַ���s��ǰn���ַ�����Ϊch��ֵ 
��������:  ָ��s��ָ�� 


@��������:  strset 
����ԭ��:  char *strset(char *s, int ch);
��������:  ���ַ���s�������ַ�����Ϊch��ֵ 
��������:  ָ��s��ָ��  
9
*/
char *strnset(char *str, int c, size_t n)  
{  
    char* pnew = str;
    //size_t num =n;
    while(n--)
    {
        if(*pnew != '\0')
            *pnew++=c;
    }
}

char *strset(char *str, char c)  
{  
    for (char* pnew = str; *pnew != '\0'; *pnew=c,pnew++) 
    { }
}


int strset_test()   
{   
    char string[10]="123456789";   
    char symbol='c';   
    printf("Before strset(): %s\n", string);   
    strset(string, symbol);   
    printf("After strset(): %s\n", string);   
    
    char letter='x';  
    printf("string before strnset: %s\n",string);  
    strnset(string,letter,5);  
    printf("string after strnset: %s\n",string);  
    
    return 0;   
}  

/*
@��������:  strtok 
����ԭ��:  char *strtok(char *s1, const char *s2);
��������:  �ֽ�s1�ַ���Ϊ���ض��ָ����ָ��Ķ���ַ���(һ�����ڽ�Ӣ�ľ�ֽ�Ϊ����) 
��������:  �ַ���s1���״γ���s2�е��ַ�ǰ�����ַ���ָ�� 
����˵��:  s2һ������Ϊs1�еķָ��ַ� 
        �涨�����ӵ���ʱ�����ָ�s1�ĵڶ������������Ӵ�����һ����������NULL 
        ��ÿһ��ƥ��ɹ��󣬽�s1�зָ�����Ӵ�λ���滻ΪNULL(ժ�����е�һ����)�����s1���ƻ��� 
        ���������ָ��λ���Թ���һ�ε��� 
10
*/
//PS�����ݲ��ԣ�������ʱ��strtok�ĵ�һ����������һ���µ��ַ�������ʼ���ַ����ķָ�

int strtok_test()   
{   
    char *p;   
    char *buffer;   
    char *delims={ " .," };  
    buffer=strdup("Find words, all of them.");   
    printf("%s |devide with ",buffer);
    puts(delims);
    p=strtok(buffer,delims);   
    while(p!=NULL){   
        printf("word: %s\n",p);   
        p=strtok(NULL,delims);   
    }   
    printf("%s\n",buffer);
    free(buffer);
    
    return 0;   
}

/*
@��������:  strupr 
����ԭ��:  char *strupr(char *s); 
��������:  ���ַ���s�е��ַ���Ϊ��д 
��������: 
*/

/*
@��������:  strlwr 
����ԭ��:  char *strlwr(char *s); 
��������:  ���ַ����е��ַ���ΪСд�ַ� 
��������:  ָ��s��ָ�� 
11 
*/

int strupr_test()   
{   
    char string[]="abcdefghijklmnopqrstuvwxyz",*ptr; //��Ӱ��ԭ�ַ������ڴ棬��char[]������  
    puts(string);
    ptr=strupr(string);   
    printf("strupr get: %s\n",ptr);
    
    printf("strlwr get: %.*s\n",10,strlwr(ptr));
    return 0;   
}  

/*
@��������:  strerror 
����ԭ��:  char *strerror(int errnum);
��������:  �õ�������Ϣ��������Ϣ 
��������:  ������ʾ��Ϣ�ַ���ָ�� 
����˵��:  errnum-������ 
12
*/

int strerror_test()   
{   
    char *buffer;
    for(int i=1;i<11;i++)
    {
        buffer=strerror(i);   
        printf("Error %d: %s\n",i,buffer);   
    }
    return 0;   
}  

/*
@��������:  memcpy 
����ԭ��:  void *memcpy(void *dest, const void *src, size_t n);
��������:  �ַ������� 
��������:  ָ��dest��ָ�� 
����˵��:  src-Դ�ַ�����n-��������󳤶� 
�����ļ�:  <string.h>,<mem.h>

@��������:  memccpy 
����ԭ��:  void *memccpy(void *dest, const void *src, int c, size_t n);
��������:  �ַ�����������ָ�����Ȼ�����ָ���ַ�ʱֹͣ���� 
��������: 
����˵��:  src-Դ�ַ���ָ�룬c-��ֹ��������ַ���n-����,dest-������Ŀ���ַ���ָ�� 
�����ļ�:  <string.h>,<mem.h>
PS��ָ���ַ������Ƶ�dest�У�memccpy������dest��ָ���ַ�����һ���ĵ�ַ������NULL��ʾδ����ָ���ַ� 
13
*/

int memcpy_test()   
{   
    char src[]="******789*********************";   
    char dest[]="abcdefghijlkmnopqrstuvwxyz0123456709";   
    char *ptr;   
    printf("destination before memcpy:%s\n",dest);   
    ptr=memcpy(dest,src,strlen(src));   
    if (ptr)   
        printf("destination after memcpy:%s\n",dest);   
    else   
        printf("memcpy failed");   
    //
    ptr=memccpy(dest,src,'7',strlen(src));   
    if (ptr)   
    {   
        *ptr='\0';   
        printf("The character was found:%s\n",dest);   
    }   
    else   
        printf("The character wasn't found");   
    
    return 0;   
}  


/*
@��������:  memchr 
����ԭ��:  void *memchr(const void *s, int c, size_t n); 
��������:  ���ַ����п�ʼ��n���ַ���Ѱ��ĳ���ַ�c��λ�� 
��������:  ����c��λ��ָ�룬����NULLʱ��ʾδ�ҵ� 
����˵��:  s-Ҫ�������ַ�����c-ҪѰ�ҵ��ַ���n-ָ������ 
14
*/

int memchr_test()   
{   
    char str[17];   
    char *ptr;   
    strcpy(str,"This is a string");   
    ptr=memchr(str,'r',strlen(str));   
    if (ptr)   
        printf("The character 'r' is at position:%d\n",ptr-str);   
    else   
        printf("The character was not found");   
    return 0;   
}  

/*
@��������:  memcmp 
����ԭ��:  int memcmp(const void *s1, const void *s2,size_t n);
��������:  ���ֵ�˳��Ƚ�������s1��s2��ǰn���ֽ�  
��������:  <0,=0,>0�ֱ��ʾs1<,=,>s2 
����˵��:  s1,s2-Ҫ�Ƚϵ��ַ�����n-�Ƚϵĳ��� 

@��������:  memicmp 
����ԭ��:  int memicmp(const void *s1, const void *s2, size_t n); 
��������:  ���ֵ�˳�򡢲�������ĸ��Сд���ַ���s1,s2ǰn���ַ��Ƚ� 
��������:  <0,=0,>0�ֱ��ʾs1<,=,>s2 
����˵��:  s1,s2-Ҫ�Ƚϵ��ַ�����n-�Ƚϵĳ��� 

15
*/
int memcmp_test()    
{    
    char *buf1="ABCDE123";    
    char *buf2="abcde456";    
    puts(buf1);
    puts(buf2);
    int stat;    
    stat=memcmp(buf1,buf2,5);    
    printf("memcmp -> The strings to position 5 are");    
    if(stat) 
        printf(" not ");    
    printf("the same\n");    
    
    /*
    stat=memicmp(buf1,buf2,5);   
    printf("memicmp -> The strings to position 5 are");   
    if(stat) 
        printf("not");   
    printf("the same");  
    */
    return 0;    
}   

/*
@��������:  memmove 
����ԭ��:  void *memmove(void *dest, const void *src, size_t n);
��������:  �ַ������� 
��������:  ָ��dest��ָ�� 
����˵��:  src-Դ�ַ�����n-��������󳤶� 
�����ļ�:  <string.h>,<mem.h>
PS����memcpy��ͬ���ǣ�memmove���Դ���Ŀ���ַ�����Դ�ַ�����ַ�ռ�����ص���������ɱ�֤�����Ƶ����ݲ����ƻ���
16
*/

int memmove_test()   
{   
    char dest[40]="abcdefghijklmnopqrstuvwxyz0123456789";   
    printf("destination prior to memmove:%s\n",dest);   
    memmove(dest+3,dest,35);   
    printf("destination aftermemmove:%s",dest);   
    return 0;   
}  

/*
@��������:   memset 
����ԭ��:   void *memset(void *s, int c, size_t n); 
��������:   �ַ����е�n���ֽ���������Ϊc 
��������: 
����˵��:   s-Ҫ���õ��ַ�����c-���õ����ݣ�n-���� 
17
*/
  
int memset_test()  
{  
    char buffer[]="Hello world";  
    printf("Buffer before memset: %s\n",buffer);  
    memset(buffer,'*',strlen(buffer)-1);  
    printf("Buffer after memset: %s\n",buffer);  
    return 0;  
} 


/*file operation test */
void string_test(void)
{
    int n;
    
    while(1)
    {
        printf("\n------------------------------\n");
        printf(" 1.strdup\t 2.strcat\t 3.strcmp\t 4.strpbrk\t 5.strspn\t 6.strchr\t 7.strstr\t 8.strrev\n \
9.strset\t 10.strtok\t 11.strupr\t 12.strerror\t 13.memcpy\t 14.memchr\t 15.memcmp\t 16.memmove\n \
17.memset\t ...\t \n");
        printf("Choose string test option :");
        fscanf(stdin,"%d",&n);
        switch(n)
        {
        case 1:
            strdup_test();
        break;
        case 2:
            strcat_test();
        break;
        case 3:
            strcmp_test();
        break;
        case 4:
            strpbrk_test();
        break;
        case 5:
            strspn_test();
        break;
        case 6:
            strchr_test();
        break;
        case 7:
            strstr_test();
        break;
        case 8:
            strrev_test();
        break;
        case 9:
            strset_test();
        break;
        case 10:
            strtok_test();
        break;
        case 11:
            strupr_test();
        break;
        case 12:
            strerror_test();
        break;
        case 13:
            memcpy_test();
        break;
        case 14:
            memchr_test();
        break;
        case 15:
            memcmp_test();
        break;
        case 16:
            memmove_test();
        break;
        case 17:
            memset_test();
        break;
       
        default:
            //file_mtest();
            break;
        }
        getchar();
        if(0 == n)
            break;
    }
    //fgets_test();
    //fileno_test();
}