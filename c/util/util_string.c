#include <stdio.h>
#include <string.h>

int char2asciistr(unsigned char ch, unsigned char *ascii_str);
int str2ascstr(unsigned char *str, unsigned int str_len, unsigned char *ascii_str, unsigned int *ascii_str_len);

int main()
{
    unsigned char ch = 'A';
    unsigned char ascii_str[128];
    unsigned char str[] = "GET /index.html";
    unsigned int str_len = strlen(str); 
    unsigned int ascii_str_len = 128;
    
    char2asciistr(ch, ascii_str);
    
    ch = 'Z';
    char2asciistr(ch, ascii_str);
    
    ch = 'a';
    char2asciistr(ch, ascii_str);
    
    ch = 'z';
    char2asciistr(ch, ascii_str); 
    
    ch = '\r';
    char2asciistr(ch, ascii_str);    
    
    ch = '\n';
    char2asciistr(ch, ascii_str);

    ch = '0';
    char2asciistr(ch, ascii_str);
 
    ch = '9';
    char2asciistr(ch, ascii_str); 
    
    ch = ' ';
    char2asciistr(ch, ascii_str); 
    
    str2ascstr(str, str_len, ascii_str, &ascii_str_len);  
      
    return 0;
}

int char2asciistr(unsigned char ch, unsigned char *ascii_str)
{
    unsigned char num2hexchartab[16] = {'0', '1', '2', '3', '4', '5', 
                                        '6', '7', '8', '9', 'A', 'B', 
                                        'C', 'D', 'E', 'F'};
    
    ascii_str[0] = num2hexchartab[ch / 16];
    ascii_str[1] = num2hexchartab[ch % 16];
    ascii_str[2] = '\0';
    
    printf("char: %c; ", ch);
    printf("asc string: %s\n", ascii_str);
    
    return 0;      
}

int str2ascstr(unsigned char *str, unsigned int str_len, 
               unsigned char *ascii_str, unsigned int *ascii_str_len)
{
    int i;
    
    for (i = 0; i < str_len; ++i) {
        char2asciistr(str[i], &ascii_str[i * 2]);
    } 
    
    *ascii_str_len = str_len * 2;
    
    printf("str: %s; ", str);
    printf("asc string: %s\n", ascii_str);
    
    return 0;
}