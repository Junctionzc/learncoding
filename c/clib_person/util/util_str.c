#include <stdio.h>

unsigned int strlen(unsigned char *str);
int strcat(unsigned char *s, unsigned char *t);
int char2asciistr(unsigned char ch, unsigned char *ascii_str);
int asciistr2char(unsigned char *ascii_str, unsigned char *p_ch);
int str2asciistr(unsigned char *str, unsigned char *ascii_str);
int asciistr2str(unsigned char *ascii_str, unsigned char *str);

int main()
{
    unsigned char ch = 'A';
    unsigned char ascii_str[128];
    unsigned char str[128] = "GET /index.html";
    unsigned char str1[32] = "hello";
    unsigned char str2[] = " world";
    
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
    asciistr2str(ascii_str, str);
    
    ascii_str[0] = '6';
    ascii_str[1] = '1';
    asciistr2char(ascii_str, &ch);  
    printf("hex:61 = %c\n", ch);
      
    strcat(str1, str2);
    printf("%s\n", str1);
    
      
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

int strcat(unsigned char *s, unsigned char *t)
{
    while (*s != '\0') {
        s++;
    }
    
    while (*t != '\0') {
        *s++ = *t++;
    }
    
    *s = '\0';
    
    return 0;
}

// strlen(ascii_str) = 2
// ch = 'a' -> ascii_str = "61"
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

// ascii_str[2]
// ascii_str = "61" -> *p_ch = 'a'
int asciistr2char(unsigned char *ascii_str, unsigned char *p_ch)
{
    unsigned int i = 0;
    
    *p_ch = '\0';
    
    for (i = 0; i < 2; ++i) {
        if ((ascii_str[i] >= '0' && ascii_str[i] <= '9') || 
            (ascii_str[i] >= 'A' && ascii_str[i] <= 'F')) {
            if (ascii_str[i] <= '9') {
                *p_ch |= (ascii_str[i] - '0') << (4 * (1 - i));
            } else {
                *p_ch |= (ascii_str[i] - 'A' + 10) << (4 * (1 - i));
            }
        } else {
            *p_ch = '\0';
            return -1;
        }
    }
    
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

// strlen(str) = strlen(sacii_str) / 2
int asciistr2str(unsigned char *ascii_str, unsigned char *str)
{
    unsigned int i;
    unsigned int ascii_str_len = strlen(ascii_str);
    
    for (i = 0; i < ascii_str_len; i += 2) {
        asciistr2char(&ascii_str[i], &str[i / 2]);
    }
    str[i / 2] = '\0';
    
    printf("asc string: %s; ", ascii_str);
    printf("str: %s\n", str);
    
    return 0;
}