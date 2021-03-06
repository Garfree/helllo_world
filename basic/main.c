/*commonly used include files in usr/include/. */

//#include <err.h>
//#include <math.h>
#include <stdio.h>
//#include <stdint.h>
//#include <stdlib.h>
#include <string.h>
//#include <strings.h>
//#include <time.h>
//#include <unistd.h>

/*loacl .h file*/
#include "test.h"




/*standard main*/
int main(int argc, char* argv[])
{
    if(NULL == argv[1]){
        printf("Please input a string parameter,like\n\
        \"printf\"\n\
        \"file\"\n\
        \"string\"\n\
		\"list\"\n\
        ...\n");
        return -1;
    }
    printf("=============== start of test ===============\n");
    
    /*printf test*/
    if(!strcmp("printf",argv[1]))
    {
        printf_test();
    }
    
    /*string operate test*/
    if(!strcmp("string",argv[1]))
    {
        string_test();
    }
	
	/*file operate test*/
    if(!strcmp("file",argv[1]))
    {
        file_test();
    }
	
	/*list operate test*/
    if(!strcmp("list",argv[1]))
    {
        list_test();
    }
    
    
    
 
    //int i;
    //for(i=0;i<10;i++)
    
    printf("=============== end of test =================\n");
    
    return 0;
} 

