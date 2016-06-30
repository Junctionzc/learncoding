#include <stdio.h>

unsigned int strlen(unsigned char *str);
int char2asciistr(unsigned char ch, unsigned char *ascii_str);
int str2asciistr(unsigned char *str, unsigned char *ascii_str);

int main()
{
    unsigned char ch = 'A';
    unsigned char ascii_str[128];
    unsigned char str[] = "GET /index.html";
    
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
    
    str2asciistr(str, ascii_str);  
      
    return 0;
}

unsigned int strlen(unsigned char *str) 
{
    unsigned int i = 0;
    
    while (str[i] != '\0') {
        ++i;
    }
        
    return i;
}

// strlen(ascii_str) = 2
int char2asciistr(unsigned char ch, unsigned char *ascii_str)
{
    unsigned char num2hexchartab[16] = {'0', '1', '2', '3', '4', '5', 
                                        '6', '7', '8', '9', 'A', 'B', 
                                        'C', 'D', 'E', 'F'};
    
    ascii_str[0] = num2hexchartab[ch / 16];
    ascii_str[1] = num2hexchartab[ch % 16];
    ascii_str[2] = '\0';
    
    return 0;      
}

// strlen(ascii_str) = strlen(str) * 2 
int str2asciistr(unsigned char *str, unsigned char *ascii_str)
{
    unsigned int i;
    unsigned int str_len = strlen(str);
    
    for (i = 0; i < str_len; ++i) {
        char2asciistr(str[i], &ascii_str[i * 2]);
    } 
    
    printf("str: %s; ", str);
    printf("asc string: %s\n", ascii_str);
    
    return 0;
}