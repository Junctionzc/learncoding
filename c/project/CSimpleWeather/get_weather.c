#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
#include <curl/curl.h>
#include "cJSON.h"

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream); 
void copy_file_to_string(FILE *ifp, char *string);
void print_weather_data();

FILE *fp;
char weather_data[1024];

int main(int argc, char *argv[])
{
    CURL *curl;
    struct curl_slist *list = NULL;

    curl_global_init(CURL_GLOBAL_ALL);  
    curl=curl_easy_init();
    
    curl_easy_setopt(curl, CURLOPT_URL, "http://apis.baidu.com/apistore/weatherservice/cityid?cityid=101280601");  
    
    curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);

    list = curl_slist_append(list, "apikey:");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

    if ((fp = fopen("./.buffer_data", "w")) == NULL) {
        curl_easy_cleanup(curl);
        exit(1);
    }

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);  
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    print_weather_data();

    exit(0);
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)  
{
    int written = fwrite(ptr, size, nmemb, (FILE *)fp);
    fclose(fp);
    if ((fp = fopen("./.buffer_data", "r")) == NULL) {
        printf("open file error!\n");
        exit(1);
    } else {
		copy_file_to_string(fp, weather_data);
        fclose(fp);
    }
    return written;
}

void copy_file_to_string(FILE *ifp, char *string)
{
    int c;
    int i = 0;
    while ((c = getc(ifp)) != EOF) {
        string[i++] = c;
    }
    string[i] = '\0';
}

void print_weather_data()
{
    cJSON *json, *json_object, *json_value;

	//printf("%s\n", weather_data);
    json = cJSON_Parse(weather_data);
    if (!json) {
        printf("cJSON parse error\n");
    } else {
        json_object = cJSON_GetObjectItem(json, "retData");
        if (json_object->type == cJSON_Object) {
			printf("---------深圳天气--------\n");
            json_value = cJSON_GetObjectItem(json_object, "weather");
            printf("%s ", json_value->valuestring);
            json_value = cJSON_GetObjectItem(json_object, "temp");
            printf("%s℃\n", json_value->valuestring);
            json_value = cJSON_GetObjectItem(json_object, "l_tmp");
            printf("最低温度：%s℃\n", json_value->valuestring);			
            json_value = cJSON_GetObjectItem(json_object, "h_tmp");
            printf("最高温度：%s℃\n", json_value->valuestring);
            json_value = cJSON_GetObjectItem(json_object, "WD");
            printf("风向：%s\n", json_value->valuestring);
            json_value = cJSON_GetObjectItem(json_object, "WS");
            printf("风力：%s\n", json_value->valuestring);			
            json_value = cJSON_GetObjectItem(json_object, "sunrise");
            printf("日出时间：%s\n", json_value->valuestring);
            json_value = cJSON_GetObjectItem(json_object, "sunset");
            printf("日落时间：%s\n", json_value->valuestring);
            json_value = cJSON_GetObjectItem(json_object, "date");
            printf("发布时间：%s ", json_value->valuestring);
            json_value = cJSON_GetObjectItem(json_object, "time");
            printf("%s\n", json_value->valuestring);			
        }   
        cJSON_Delete(json);
    }
}
