#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include<graphics.h>
#define MAXSIZE 400
#define Elemtype double
#define PI 3.1415926

// 静态栈
typedef struct
{
    Elemtype data[MAXSIZE];
    int top;
} Sqstack;

//初始屏幕
void Initscreen();

//绘图函数
void Draw(char* str, int scale);

//填充函数
void Fill(double a, double b, char* str, int scale);

//初始化栈
void Initstack(Sqstack* S);

//入栈
void Push(Sqstack* S, Elemtype num);

//出栈
Elemtype Pop(Sqstack* S);

//取栈顶元素
Elemtype Gettop(Sqstack* S);

//实现字符串的部分替换
char* replace_str(char* s, char* t, char* g);

//带入自变量的值
char* strreplace(char str[], double x);

//检测括号匹配
int check(char* str);

//将中缀表达式转换为后缀表达式
char* strshift(char str1[]);

//计算后缀表达式的值
double ReversePolishnotation(char str[]);

//对特殊函数sin cos 等求值
double Recursion_operater(char str[],double x);

//计算定积分
double integral(char* str, double(*f)(char*, double), double a, double b);

//拷贝两地址间的字符串
char* copySubstring(char* start, char* end);

//替换字符串中的子串
char* replaceSubstring(char* str, char* start, char* end, char* newSubstr);



