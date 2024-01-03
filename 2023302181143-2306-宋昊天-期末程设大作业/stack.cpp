#include"head.h"


void Initstack(Sqstack* S)
{
    S->top = -1;
}

void Push(Sqstack* S, Elemtype num)
{
    if (S->top == MAXSIZE - 1)
    {
        printf("已满，无法入栈\n");
        return;
    }
    S->data[++(S->top)] = num;
}

Elemtype Pop(Sqstack* S)
{
    if (S->top == -1)
    {
        return PI;
    }
    Elemtype num = S->data[(S->top)--];
    return num;
}

Elemtype Gettop(Sqstack* S)
{
    if (S->top == -1)
    {
        return -1;
    }
    Elemtype num = S->data[S->top];
    return num; 
}