#include "stdio.h"


/*
1 类型（type）
d/i     int             输出十进制有符号32bits整数，i是老式写法
o       unsigned int    无符号8进制(octal)整数(不输出前缀0)
u       unsigned int    无符号10进制整数
x/X     unsigned int    无符号16进制整数，x对应的是abcdef，X对应的是ABCDEF（不输出前缀0x)
f/lf    float(double)   单精度浮点数用f,双精度浮点数用lf(printf可混用，但scanf不能混用)
e/E     float(double)   科学计数法，使用指数(Exponent)表示浮点数，此处”e”的大小写代表在输出时“e”的大小写
g       float(double)   根据数值的长度，选择以最短的方式输出，%f或%e
G       float(double)   根据数值的长度，选择以最短的方式输出，%f或%E
c       char            字符型。可以把输入的数字按照ASCII码相应转换为对应的字符
s       char*           字符串。输出字符串中的字符直至字符串中的空字符（字符串以空字符’\0‘结尾）
S       wchar_t*        宽字符串。输出字符串中的字符直至字符串中的空字符（宽字符串以两个空字符’\0‘结尾）
p       void*           以16进制形式输出指针
n       int*            什么也不输出。%n对应的参数是一个指向signed int的指针，在此之前输出的字符数将存储到指针所指的位置
%       字符%           输出字符‘%’（百分号）本身 
m       无打印         errno值对应的出错内容
a/A     float(double)   十六进制p计数法输出浮点数，a为小写，A为大写 

注意： 
 （1）使用printf输出宽字符时，需要使用setlocale指定本地化信息并同时指明当前代码的编码方式。除了使用%S，还可以使用%ls。  （2）%a和%A是C99引入的格式化类型，采用十六进制p计数法输出浮点数。p计数法类似E科学计数法，但不同。数以0x开头，然后是16进制浮点数部分，接着是p后面是以2为底的阶码。以上面输出的15.15为例，推算输出结果。15.15转换成二进制为1111.00 1001 1001 1001 1001 ...，因为二进制表示数值的离散特点，计算机对于小数有时是不能精确表示的，比如0.5可以精确表示为0.1 2  ，而0.15却不能精确表示。将15.15对应的二进制右移三位，为1.1110 0100 1100 1100 1100 ...转换对应的十六进制就是0x1.e4ccccccccccd，注意舍入时向高位进了1位。由于右移三位，所以二进制阶码就是3。最后的结果就是0x1.e4ccccccccccdp+3。
（3）格式控制字符串除了指明输出的数据类型，还可以包含一些其它的可选的格式说明，依序有 flags, width, .precision and length。
*/
void print_type()
{
    printf("------ print_type ------\n");
    printf("%i\n",123);  //输出123
    printf("0%o\n",123); //输出0123
    printf("%u\n",123); //输出123 
    printf("0x%x 0x%X\n",123,123); //输出0x7b 0x7B 
    printf("%.9f %.9lf\n",0.000000123,0.000000123); //输出0.000000123 0.000000123。默认精确到小数点后六位 
    printf("%e %E\n",0.000000123,0.000000123); //输出1.230000e-07 1.230000E-07 
    printf("%g %g\n",0.000000123,0.123); //输出1.23e-07 0.123 
    printf("%G %G\n",0.000000123,0.123); //输出1.23E-07 0.123 
    printf("%c\n",64); //输出A 
    printf("%s\n","测试test"); //输出：测试test 
    //setlocale(LC_ALL,"zh_CN.UTF-8");wchar_t wtest[]=L"测试Test";printf("%S\n",wtest);//输出：测试test 
    printf("%010p\n","lvlv");//输出：0x004007e6 
    int num=4;printf("lvlv%n",&num);printf("num:%d\n",num); //输出:lvlvnum:4 
    printf("%%\n");//输出:% 
    printf("%m\n");
    printf("%a %A\n",15.15,15.15); //输出：0x1.e4ccccccccccdp+3 0X1.E4CCCCCCCCCCDP+3 
    
    
    
    
}

/*
2 标志（flags）
flags规定输出样式，取值和含义如下：

- 减号        结果左对齐，右边填空格。默认是右对齐，左边填空格。 
+ 加号        输出符号(正号或负号) 
space 空格    输出值为正时加上空格，为负时加上负号 
# 井号        type是o、x、X时，增加前缀0、0x、0X。
type是a、A、e、E、f、g、G时，一定使用小数点。默认的，如果没有小数部分则不输出小数点。
type是g、G时，尾部的0保留。 
0 数字零       将输出的前面补上0，直到占满指定列宽为止（不可以搭配使用“-”） 
*/
void print_flags()
{
    printf("\n------ print_flags ------\n");
    printf("%5d\n",1000);               //默认右对齐,左边补空格
    printf("%-5d\n",1000);              //左对齐,右边补空格
    printf("%+d %+d\n",1000,-1000);     //输出正负号
    printf("% d % d\n",1000,-1000);     //正号用空格替代，负号输出
    printf("%x %#x\n",1000,1000);       //输出0x
    printf("%.0f %#.0f\n",1000.0,1000.0);//当小数点后没有值时依然输出小数点
    printf("%g %#g\n",1000.0,1000.0);   //保留小数点后后的0
    printf("%05d\n",1000);              //前面补01
}
/*
3 输出最小宽度（width）
数值 十进制整数 
* 星号。不显示指明输出最小宽度，而是以星号代替，在printf的输出参数列表中给出 
*/
void print_width()
{
    printf("\n------ print_width ------\n");
    printf("%06d",1000); //输出:001000 
    printf("%0*d",6,1000); //输出:001000 
}
/*
4 精度（.precision）
.数值 十进制整数。
(1)对于整型（d,i,o,u,x,X）,precision表示输出的最小的数字个数，不足补前导零，超过不截断。
(2)对于浮点型（a, A, e, E, f ），precision表示小数点后数值位数，默认为六位，不足补后置0，超过则截断。
(3)对于类型说明符g或G，表示可输出的最大有效数字。
(4)对于字符串（s），precision表示最大可输出字符数，不足正常输出，超过则截断。
precision不显示指定，则默认为0 
.* 以星号代替数值，类似于width中的*，在输出参数列表中指定精度。 

输出结果：
00001000
1000.12345679
1000.12345600
1000.1235
abcdefgh1

注意，在对浮点数和整数截断时，存在四舍五入。
*/
void print_precision()
{
    printf("\n------ print_precision ------\n");
    printf("%.8d\n",1000);  //不足指定宽度补前导0，效果等同于%06d
    printf("%.8f\n",1000.123456789);    //超过精度，截断
    printf("%.8f\n",1000.123456);   //不足精度，补后置0
    printf("%.8g\n",1000.123456);   //最大有效数字为8位
    printf("%.8s\n","abcdefghij");  //超过指定长度截断1

}

/*
5 类型长度（length）
类型长度指明待输出数据的长度。因为相同类型可以有不同的长度，比如整型有16bits的short int，32bits的int，也有64bits的long int，浮点型有32bits的单精度float和64bits的双精度double。为了指明同一类型的不同长度，于是乎，类型长度（length）应运而生，成为格式控制字符串的一部分。

输出结果：
65
193
32767
65535
9223372036854775807
184467440737095516151

注意： 
long int到底是32bits还是64bits跟生成的程序是32bits还是64bits一一对应，如果使用g++编译程序的话，可通过-m32或-m64选项分别生成32bits和64bits的程序。
*/
void print_length()
{
    printf("\n------ print_length ------\n");
    printf("%hhd\n",'A');       //输出有符号char
    printf("%hhu\n",'A'+128);   //输出无符号char
    printf("%hd\n",32767);      //输出有符号短整型short int
    printf("%hu\n",65535);      //输出无符号短整型unsigned short int
    printf("%ld\n",0x7fffffffffffffff);     //输出有符号长整型long int
    printf("%lu\n",0xffffffffffffffff);     //输出有符号长整型unsigned long int1
}

/*
6 转义字符（）
转义字符在字符串中会被自动转换为相应操作命令。printf()使用的常见转义字符如下：
转义字符    意义

\a 警报（响铃）符 
\b 回退符 
\f 换页符 
\n 换行符 
\r 回车符 
\t 横向制表符 
\v 纵向制表符 
\\ 反斜杠 
\” 双引号 
*/
void print_esc()
{
}
/*
7 关于printf缓冲
在printf的实现中，在调用write之前先写入IO缓冲区，这是一个用户空间的缓冲。系统调用是软中断，频繁调用，需要频繁陷入内核态，这样的效率不是很高，而printf实际是向用户空间的IO缓冲写，在满足条件的情况下才会调用write系统调用，减少IO次数，提高效率。

printf在glibc中默认为行缓冲，遇到一下几种情况会刷新缓冲区，输出内容： 
 （1）缓冲区填满； 
 （2）写入的字符中有换行符\n或回车符\r； 
 （3）调用fflush手动刷新缓冲区； 
 （4）调用scanf要从输入缓冲区中读取数据时，也会将输出缓冲区内的数据刷新。

可使用setbuf(stdout,NULL)关闭行缓冲，或者setbuf(stdout,uBuff)设置新的缓冲区，uBuff为自己指定的缓冲区。也可以使用setvbuf(stdout,NULL,_IOFBF,0);来改变标准输出为全缓冲。全缓冲与行缓冲的区别在于遇到换行符不刷新缓冲区。

printf在VC++中默认关闭缓冲区，且只能设置全缓冲。输出时会及时的输到屏幕  。因为微软闭源，所以无法研究printf函数的实现源码。
linux和Windows下的缓冲区管理可见：C的全缓冲、行缓冲和无缓冲。
*/
void print_buffer()
{
}

/*print all test example*/
void printf_test(void)
{
    print_type();
    print_flags();
    print_width();
    print_precision();
    print_length();
    //print_esc();
    //print_buffer();
}