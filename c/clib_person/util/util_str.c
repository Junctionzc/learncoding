#include <stdio.h>
#include <string.h>

int char2asciistr(unsigned char ch, unsigned char *ascii_str);
int asciistr2char(unsigned char *ascii_str, unsigned char *p_ch);
int str2asciistr(unsigned char *str, unsigned char *ascii_str);
int asciistr2str(unsigned char *ascii_str, unsigned char *str);
int http_pop_body(char *http_full_str, char *http_body_str);
int int2str(unsigned int num, unsigned char str[6]);
int str2float(unsigned char *str, float *f);
int str_strip(unsigned char *str, unsigned char strip_ch);
int json_get_value(unsigned char *json_str, unsigned char *key, unsigned char *value);

int main()
{
    unsigned char ch = 'A';
    unsigned char ascii_str[128];
    unsigned char str[128] = "GET /index.html";
    unsigned char str1[32] = "hello";
    unsigned char str2[] = " world";
    unsigned char http_full_str[] = "HTTP/1.1 200 OK\r\nServer: Apache-Coyote/1.1\r\nCache-Control: no-store\r\nContent-Length: 11\r\nDate: Wed, 03 Aug 2016 02:53:35 GMT\r\n\r\nunactivated";
    unsigned char http_body_str[128];
    unsigned char str3[6] = "";
    unsigned char json_str[] = "{\"event_type\": \"0\",\"event_data\": {\"total_amount\":0.01}}";
    unsigned char str4[] = "  a b  c  ";
    unsigned char json_value[128] = "";
    unsigned char str5[] = "12.0123";
    float f = 0.0;

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
    
    http_pop_body(http_full_str, http_body_str);
    printf("%s\n", http_body_str);
    
    int2str(655355, str3);
    printf("%s\n", str3);
      
    printf("%s\n", str4);  
    str_strip(str4, ' ');  
    printf("%s\n", str4);  
      
    printf("%s\n", json_str);  
    json_get_value(json_str, "event_type", json_value);  
    printf("%s\n", json_value);
    json_get_value(json_str, "event_data", json_value);  
    printf("%s\n", json_value);
    json_get_value(json_value, "total_amount", json_value);
    printf("%s\n", json_value);
    
    str2float(str5, &f);
    printf("%f\n", f);

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

int str_pop_data(char *src_str, char *tar_str) 
{
    char *data_beg;
    char *data_end;
    char data_len = 0;
    
    data_beg = strstr(src_str, "5\r\ndata:\r\n");
    
    if (data_beg == NULL) {
        tar_str[0] = '\0';
        return -1;
    } else {
        data_end = strstr(data_beg, "2\r\n\n\n\r\n");
        
        if (data_end != NULL) {
            data_len = data_end - data_beg + 7;
            
            strncpy(tar_str, data_beg, data_len);
            tar_str[data_len] = '\0';
            *data_beg = '\0';
            strcat(data_beg, data_end + 7);
            
        } else {
            tar_str[0] = '\0';
            return -1;
        }
    }

    return 0;
}

int str_get_data(char *src_str)
{
    int i = 0;
    int j = 0;
    int enter_count = 0;
    char tar_str[1024];

    if (strlen((const char *)src_str) >= 1024) {
        return -1;
    }

    while (i < strlen((const char *)src_str)) {
        if (src_str[i] == '\n') {
            enter_count++;
        }
        
        i++;
        
        if (enter_count == 3) {
            while ((i < strlen((const char *)src_str)) && (src_str[i] != '\r')) {
                tar_str[j++] = src_str[i++];
            }
            
            break;
        }
    }
    
    tar_str[j] = '\0';

    strcpy((char *)src_str, (const char *)tar_str);

    return 0;
}

int http_pop_body(char *http_full_str, char *http_body_str) 
{
    char *http_header_end;
    
    http_header_end = strstr(http_full_str, "\r\n\r\n");
    
    if (http_header_end == NULL) {
        http_body_str[0] = '\0';
        return -1;
    } else {
        strcpy(http_body_str, http_header_end + 4);
    }

    return 0;
}

int int2str(unsigned int num, unsigned char str[6])
{
    str[0] = num % 100000 / 10000 + '0';
    str[1] = num % 10000 / 1000 + '0';
    str[2] = num % 1000 / 100 + '0';
    str[3] = num % 100 / 10 + '0';
    str[4] = num % 10 + '0';
    str[5] = '\0';
    
    return 0;
}

int str_strip(unsigned char *str, unsigned char strip_ch)
{ 
    unsigned char *p = str;
    unsigned int str_len = strlen(str);
    unsigned int i = 0;
    
    while ((*p) != '\0') {
        if ((*p) == strip_ch) {
            for (i = 0; i < str_len - (p - str) + 1; i++) {
                str[p - str + i] = str[p - str + i + 1];
            }
            
            str_len = strlen(str); 
        }
        
        if (*p != strip_ch) {
            p++;
        }
    }
    
    return 0;
}

int json_get_value(unsigned char *json_str, unsigned char *key, unsigned char *value)
{
    unsigned int json_str_len = 0;
    unsigned char *key_beg = NULL;
    unsigned char *key_end = NULL;
    unsigned char *value_beg = NULL;
    unsigned char *value_end = NULL;    
    unsigned int value_len = 0;
    
    json_str_len = strlen(json_str);
    
    if (json_str[0] != '{' || json_str[json_str_len - 1] != '}') {
        return -1;
    }
    
    str_strip(json_str, ' ');
    json_str_len = strlen(json_str);
    
    key_beg = strstr(json_str, key);
    
    if (key_beg != NULL) {
        value_beg = strstr(key_beg, ":");
        
        if (value_beg != NULL) {
            value_beg += 1;
            
            if (*value_beg == '{') {
                value_end = strstr(value_beg, "}");
                
                if (value_end != NULL && (*(value_end + 1) == '}' || *(value_end + 1) == ',')) {
                    value_len = value_end - value_beg + 1;
                    strncpy(value, value_beg, value_len);
                    value[value_len] = '\0';
                } else {
                    return -1;
                }
            } else {
                value_end = strstr(value_beg, ",");
                
                if (value_end != NULL) {
                    value_len = value_end - value_beg;
                    strncpy(value, value_beg, value_len);
                    value[value_len] = '\0';
                } else {
                    value_end = strstr(value_beg, "}");
                    
                    if (value_end != NULL) {
                        value_len = value_end - value_beg;
                        strncpy(value, value_beg, value_len);
                        value[value_len] = '\0';
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            return -1;
        }
    } else {
        return -1;
    }
    
    return 0;
}

int str2float(unsigned char *str, float *f)
{
    unsigned int str_len = strlen(str);
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int str_has_point = 0;
    unsigned int point_index = 0;
    float dec_buf = 0.0;

    (*f) = 0.0;

    for (i = 0; i < str_len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            if (str_has_point == 0) {
                (*f) = (*f) * 10 + (str[i] - '0');
            } else {
                dec_buf = str[i] - '0';

                for (j = 0; j < i - point_index; j++) {
                    dec_buf /= 10;
                }
    
                (*f) = (*f) + dec_buf;
            }
        } else if (str[i] == '.') {
            str_has_point = 1;
            point_index = i;
        } else {
            return -1;
        }
    }
    
    return 0;
}