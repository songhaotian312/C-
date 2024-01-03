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

// ��̬ջ
typedef struct
{
    Elemtype data[MAXSIZE];
    int top;
} Sqstack;

//��ʼ��Ļ
void Initscreen();

//��ͼ����
void Draw(char* str, int scale);

//��亯��
void Fill(double a, double b, char* str, int scale);

//��ʼ��ջ
void Initstack(Sqstack* S);

//��ջ
void Push(Sqstack* S, Elemtype num);

//��ջ
Elemtype Pop(Sqstack* S);

//ȡջ��Ԫ��
Elemtype Gettop(Sqstack* S);

//ʵ���ַ����Ĳ����滻
char* replace_str(char* s, char* t, char* g);

//�����Ա�����ֵ
char* strreplace(char str[], double x);

//�������ƥ��
int check(char* str);

//����׺���ʽת��Ϊ��׺���ʽ
char* strshift(char str1[]);

//�����׺���ʽ��ֵ
double ReversePolishnotation(char str[]);

//�����⺯��sin cos ����ֵ
double Recursion_operater(char str[],double x);

//���㶨����
double integral(char* str, double(*f)(char*, double), double a, double b);

//��������ַ����ַ���
char* copySubstring(char* start, char* end);

//�滻�ַ����е��Ӵ�
char* replaceSubstring(char* str, char* start, char* end, char* newSubstr);



