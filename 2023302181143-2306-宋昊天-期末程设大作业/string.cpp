#include"head.h"

char* replace_str(char* str, char* oldSubstr, char* newSubstr)
{
    char* result;
    int i, count = 0;
    int newSubstr_len = strlen(newSubstr);
    int oldSubstr_len = strlen(oldSubstr);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (strstr(&str[i], oldSubstr) == &str[i])
        {
            count++;
            i += oldSubstr_len - 1;
        }
    }

    result = (char*)malloc(i + count * (newSubstr_len - oldSubstr_len) + 1);
    if (result == NULL)
    {
        printf("内存分配失败\n");
        exit(0);
    }
    i = 0;
    while (*str)
    {
        if (strstr(str, oldSubstr) == str)
        {
            strcpy(&result[i], newSubstr);
            i += newSubstr_len;
            str += oldSubstr_len;
        }
        else
            result[i++] = *str++;
    }
    result[i] = '\0';
    return result;
}


char* copySubstring(char* start, char* end) 
{
    if (start == NULL || end == NULL || start >= end) {
        return NULL;
    }
    int len = end - start - 1;
    char* result = (char*)malloc((len + 1) * sizeof(char));
    strncpy(result, start + 1, len);
    result[len] = '\0';

    return result;
}

char* replaceSubstring(char* str, char* start, char* end, char* newSubstr)
{
    if (str == NULL || start == NULL || end == NULL || start > end)
    {
        return NULL;
    }
    int len = start - str + strlen(newSubstr) + strlen(end + 1) + 1;
    char* result = (char*)malloc(len * sizeof(char));
    if (result == NULL)
    {
        return NULL;
    }
    strncpy(result, str, start - str);
    strcpy(result + (start - str), newSubstr);
    strcpy(result + (start - str) + strlen(newSubstr), end + 1);
    return result;
}

char* strreplace(char str[], double x)
{
    char str1[30] = { 0 };
    if (x >= 0)
    {
        sprintf(str1, "(%d/1000000)", (int)(x * 1000000));
    }
    else
    {
        sprintf(str1, "(0%d/1000000)", (int)(x * 1000000));
    }
    char* str2 = replace_str(str, (char*)"x", str1);
    char* str3 = replace_str(str2, (char*)"e", (char*)"(2718282/1000000)");
    free(str2);
    return str3;
}
