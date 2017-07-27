# basic programming #
[hello world](https://github.com/Garfree/helllo_world)

## basic ##
### Stdio ###
- **printf** explain in detail

`int printf ( const char * format, ... );
`

---
**file** related operations

- fopen
`
FILE * fopen(const char * path,const char * mode);
`
- fclose 
`
int fclose( FILE *fp );
`
- fread
`
size_t fread(void * ptr,size_t size,size_t nmemb,FILE * stream);
`
- fwrite
`
size_t fwrite(const void * ptr,size_t size,size_t nmemb,FILE * stream);
`
- fseek
`
int fseek(FILE * stream,long offset,int whence);
`
- feof
`
int feof(FILE * stream);
`

--- 
### String ###
    char *strdup(const char *s); 
    char *strcpy(char* dest, const char *src);
    char *strncpy(char *dest, const char *src，intcount);
    char* strcat(char * str1,char * str2); 
    char *strncat(char *dest, const char *src, size_t maxlen);
    int strcmp(char * str1,char * str2); 
    int strncmp(char *str1,char *str2,int count);
    char *strpbrk(const char *s1, const char *s2);
    int strcspn(const char *s1, const char *s2);
    int strspn(const char *s1, const char *s2);
    char* strchr(char* str,char ch); 
    char *strrchr(const char *s, int c);
    char* strstr(char* str1,char* str2); 
    char *strrev(char *s);
    char *strnset(char *s, int ch, size_t n);
    char *strset(char *s, int ch);
    char *strtok(char *s1, const char *s2);
    char *strupr(char *s); 
    char *strlwr(char *s); 
    char *strerror(int errnum);
    void *memcpy(void *dest, const void *src, size_t n);
    void *memccpy(void *dest, const void *src, int c, size_t n);
    void *memchr(const void *s, int c, size_t n); 
    int memcmp(const void *s1, const void *s2,size_t n);
    int memicmp(const void *s1, const void *s2, size_t n); 
    void *memmove(void *dest, const void *src, size_t n);
    void *memset(void *s, int c, size_t n); 

### Pointer ###
### Memory ###
### Lib ###




## data structure ##

## algorithm ##



