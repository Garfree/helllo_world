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
@函数原型:  char *strdup(const char *s); 
函数功能:  字符串拷贝，目的空间由该函数分配  
函数返回:  指向拷贝后的字符串指针 
参数说明:  src-待拷贝的源字符串 
*/

/*
@函数名称:  strcpy 
函数原型:  char *strcpy(char* dest, const char *src);
函数功能:  把str2指向的字符串拷贝到str1中去 
函数返回:  返回str1,即指向str1的指针 
参数说明:  src和dest所指内存区域不可以重叠且dest必须有足够的空间来容纳src的字符串。
*/

/*
@函数名称:  strncpy 
函数原型:  char *strncpy(char *dest, const char *src，intcount);
函数功能:  将字符串src中的count个字符拷贝到字符串dest中去 
函数返回:  指向dest的指针 
参数说明:  dest-目的字符串，src-源字符串，count-拷贝的字符个数 
注意：strncpy只复制指定长度的字符，不会自动在末尾加'\0'。若指定长度超过源字符串长度，不够的部分补‘\0’
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
@函数名称:  strcat 
函数原型:  char* strcat(char * str1,char * str2); 
函数功能:  把字符串str2接到str1后面,str1最后的'\0'被取消 
函数返回:  str1 
参数说明: 
*/

/*
@函数名称:  strncat 
函数原型:  char *strncat(char *dest, const char *src, size_t maxlen);
函数功能:  将字符串src中前maxlen个字符连接到dest中 
函数返回: 
注意：与strncpy不同的是，strncat会自动在末尾加‘\0’，若指定长度超过源字符串长度，则只复制源字符串长度即停止
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
@函数名称:  strcmp 
函数原型:  int strcmp(char * str1,char * str2); 
函数功能:  比较两个字符串str1,str2. 
函数返回:  str1<str2,返回负数;str1=str2,返回 0;str1>str2,返回正数.  
参数说明:
*/

/*
@函数名称:  strncmp 
函数原型:  int strncmp(char *str1,char *str2,int count);
函数功能:  对str1和str2中的前count个字符按字典顺序比较 
函数返回:  小于0：str1<str2，等于0：str1=str2，大于0：str1>str2 
参数说明:  str1,str2-待比较的字符串，count-比较的长度 
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
    
    //为使测试程序更简练，此处假定了strncmp只返回-1,0,1三个数  
    char res_info[] = {'<','=','>'};
    //前1个字符比较  
    ret = strncmp(str1, str2, 1);  
    printf("strncmp(str1, str2, 1) get: str1%c str2\n", res_info[ret+1]);
    //前3个字符比较  
    ret = strncmp(str1, str2, 3);
    printf("strncmp(str1, str2, 3) get: str1%c str2\n", res_info[ret+1]);
    
    return 0;   
}  

/*
@函数名称:  strpbrk 
函数原型:  char *strpbrk(const char *s1, const char *s2);
函数功能:  得到s1中第一个“同时也出现在s2中”字符的位置指针 
函数返回:  位置指针 
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
@函数名称:  strcspn 
函数原型:  int strcspn(const char *s1, const char *s2);
函数功能:  统计s1中从头开始直到第一个“来自s2中的字符”出现的长度 
函数返回:  长度 
*/

/*
@函数名称:  strspn 
函数原型:  int strspn(const char *s1, const char *s2);
函数功能:  统计s1中从头开始直到第一个“不来自s2中的字符”出现的长度 
函数返回:  长度
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
@函数名称:  strchr 
函数原型:  char* strchr(char* str,char ch); 
函数功能:  找出str指向的字符串中第一次出现字符ch的位置 
函数返回:  返回指向该位置的指针,如找不到,则返回空指针 
参数说明:  str-待搜索的字符串，ch-查找的字符 

@函数名称:  strrchr 
函数原型:  char *strrchr(const char *s, int c);
函数功能:  得到字符串s中最后一个含有c字符的位置指针 
函数返回:  位置指针 
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
@函数名称:  strstr 
函数原型:  char* strstr(char* str1,char* str2); 
函数功能:  找出str2字符串在str1字符串中第一次出现的位置(不包括str2的串结束符) 
函数返回:  返回该位置的指针,如找不到,返回空指针 
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
@函数名称:  strrev 
函数原型:  char *strrev(char *s);
函数功能:  将字符串中的所有字符颠倒次序排列 
函数返回:  指向s的指针  
8
非标函数，以下为实现源码：
*/
char* strrev(char* s)  
{  
    /* h指向s的头部 */  
    char* h = s;      
    char* t = s;  
    char ch;  
    
    /* t指向s的尾部 */  
    while(*t++){} ;  
    t--;    /* 与t++抵消 */  
    t--;    /* 回跳过结束符'\0' */  
    
    /* 当h和t未重合时，交换它们所指向的字符 */  
    while(h < t)  
    {  
        ch = *h;  
        *h++ = *t;    /* h向尾部移动 */  
        *t-- = ch;    /* t向头部移动 */  
    }  
    return(s);  
}  

int strrev_test()   
{   
    char forward[]="string"; //原文中定义为char*是不对的，指向代码段的指针内容是不可变的  
    printf("Before strrev(): %s\n",forward);   
    strrev(forward);   
    printf("Afterstrrev(): %s\n",forward);   
    return 0;   
}  


/*
@函数名称:  strnset 
函数原型:  char *strnset(char *s, int ch, size_t n);
函数功能:  将字符串s中前n个字符设置为ch的值 
函数返回:  指向s的指针 


@函数名称:  strset 
函数原型:  char *strset(char *s, int ch);
函数功能:  将字符串s中所有字符设置为ch的值 
函数返回:  指向s的指针  
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
@函数名称:  strtok 
函数原型:  char *strtok(char *s1, const char *s2);
函数功能:  分解s1字符串为用特定分隔符分隔的多个字符串(一般用于将英文句分解为单词) 
函数返回:  字符串s1中首次出现s2中的字符前的子字符串指针 
参数说明:  s2一般设置为s1中的分隔字符 
        规定进行子调用时（即分割s1的第二、三及后续子串）第一参数必须是NULL 
        在每一次匹配成功后，将s1中分割出的子串位置替换为NULL(摘下链中第一个环)，因此s1被破坏了 
        函数会记忆指针位置以供下一次调用 
10
*/
//PS：根据测试，可以随时给strtok的第一个参数输入一个新的字符串，开始新字符串的分隔

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
@函数名称:  strupr 
函数原型:  char *strupr(char *s); 
函数功能:  将字符串s中的字符变为大写 
函数返回: 
*/

/*
@函数名称:  strlwr 
函数原型:  char *strlwr(char *s); 
函数功能:  将字符串中的字符变为小写字符 
函数返回:  指向s的指针 
11 
*/

int strupr_test()   
{   
    char string[]="abcdefghijklmnopqrstuvwxyz",*ptr; //会影响原字符串的内存，用char[]来声明  
    puts(string);
    ptr=strupr(string);   
    printf("strupr get: %s\n",ptr);
    
    printf("strlwr get: %.*s\n",10,strlwr(ptr));
    return 0;   
}  

/*
@函数名称:  strerror 
函数原型:  char *strerror(int errnum);
函数功能:  得到错误信息的内容信息 
函数返回:  错误提示信息字符串指针 
参数说明:  errnum-错误编号 
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
@函数名称:  memcpy 
函数原型:  void *memcpy(void *dest, const void *src, size_t n);
函数功能:  字符串拷贝 
函数返回:  指向dest的指针 
参数说明:  src-源字符串，n-拷贝的最大长度 
所属文件:  <string.h>,<mem.h>

@函数名称:  memccpy 
函数原型:  void *memccpy(void *dest, const void *src, int c, size_t n);
函数功能:  字符串拷贝，到指定长度或遇到指定字符时停止拷贝 
函数返回: 
参数说明:  src-源字符串指针，c-中止拷贝检查字符，n-长度,dest-拷贝底目的字符串指针 
所属文件:  <string.h>,<mem.h>
PS：指定字符被复制到dest中，memccpy返回了dest中指定字符的下一处的地址，返回NULL表示未遇到指定字符 
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
@函数名称:  memchr 
函数原型:  void *memchr(const void *s, int c, size_t n); 
函数功能:  在字符串中开始第n个字符中寻找某个字符c的位置 
函数返回:  返回c的位置指针，返回NULL时表示未找到 
参数说明:  s-要搜索的字符串，c-要寻找的字符，n-指定长度 
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
@函数名称:  memcmp 
函数原型:  int memcmp(const void *s1, const void *s2,size_t n);
函数功能:  按字典顺序比较两个串s1和s2的前n个字节  
函数返回:  <0,=0,>0分别表示s1<,=,>s2 
参数说明:  s1,s2-要比较的字符串，n-比较的长度 

@函数名称:  memicmp 
函数原型:  int memicmp(const void *s1, const void *s2, size_t n); 
函数功能:  按字典顺序、不考虑字母大小写对字符串s1,s2前n个字符比较 
函数返回:  <0,=0,>0分别表示s1<,=,>s2 
参数说明:  s1,s2-要比较的字符串，n-比较的长度 

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
@函数名称:  memmove 
函数原型:  void *memmove(void *dest, const void *src, size_t n);
函数功能:  字符串拷贝 
函数返回:  指向dest的指针 
参数说明:  src-源字符串，n-拷贝的最大长度 
所属文件:  <string.h>,<mem.h>
PS：与memcpy不同的是，memmove可以处理目的字符串与源字符串地址空间出现重叠的情况，可保证待复制的内容不被破坏。
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
@函数名称:   memset 
函数原型:   void *memset(void *s, int c, size_t n); 
函数功能:   字符串中的n个字节内容设置为c 
函数返回: 
参数说明:   s-要设置的字符串，c-设置的内容，n-长度 
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