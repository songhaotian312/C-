#include "head.h"

//�������ƥ������
int check(char* str)
{
	Sqstack Sq;
	Sqstack* S = &Sq;
	Initstack(S);
	int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
			Push(S, str[i]);
		}
        else if (str[i] == ')')
        {
            if (S->top == -1)
            {
				return 0;
			}
			Pop(S);
		}
	}
    if (S->top == -1)
    {
		return 1;
	}
    else
    {
		return 0;
	}
}

// ����׺���ʽתΪ��׺���ʽ
char* strshift(char str1[])
{
    int len = strlen(str1);
    char* str2 = (char*)malloc(sizeof(double) * (len + 5));
    if (str2 == NULL)
    {
        printf("�ڴ����ʧ��\n");
        exit(0);
    }
    Sqstack Sq;
    Sqstack* S = &Sq;
    Initstack(S);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (str1[i] == ' ')
        {
            continue;
        }
        else if (str1[i] <= '9' && str1[i] >= '0')
        {
            while (str1[i] <= '9' && str1[i] >= '0')
            {
                str2[j++] = str1[i++];
            }
            i--;
            str2[j++] = '#';
            continue;
        }
        else if (str1[i] == 'x')
        {
            str2[j++] = str1[i];
            continue;
        }
        else if (str1[i] == '(')
        {
            Push(S, str1[i]);
            continue;
        }
        else if (str1[i] == ')')
        {
            while (Gettop(S) != '(')
            {
                str2[j++] = Pop(S);
            }
            Pop(S);
            continue;
        }
        else if (str1[i] == '^')
        {
            while (Gettop(S) == '^' && Gettop(S) != '(')
            {
				str2[j++] = Pop(S);
			}
            Push(S, str1[i]);
			continue;
        }
        else if (str1[i] == '*' || str1[i] == '/')
        {
            while ((Gettop(S) == '*' || Gettop(S) == '/'||Gettop(S)=='^') && Gettop(S) != '(')
            {
                str2[j++] = Pop(S);
            }
            Push(S, str1[i]);
            continue;
        }
        else if (str1[i] == '+' || str1[i] == '-')
        {
            while ((Gettop(S) == '+' || Gettop(S) == '-' || Gettop(S) == '*' || Gettop(S) == '/' || Gettop(S) == '^') && Gettop(S) != '(')
            {
                str2[j++] = Pop(S);
            }
            Push(S, str1[i]);
            continue;
        }
        else
        {
            printf("��ʽ����1\n");
			exit(0);
        }
    }
    while (Gettop(S) != -1)
    {
        str2[j++] = Pop(S);
    }
    str2[j] = '\0';
    return str2;
}

// �����׺���ʽ
double ReversePolishnotation(char *str)
{
    if (str == NULL)
    {
        printf("��ʽ����2\n");
        exit(0);
    }
    Sqstack Sq;
    Sqstack* S = &Sq;
    Initstack(S);
    int len = strlen(str);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] <= '9' && str[i] >= '0')
        {
            int num = 0;
            while (str[i] != '#')
            {
                num += str[i] - 48;
                num *= 10;
                i++;
            }
            Push(S, num / 10);
            continue;
        }
        else if (str[i] == '+' || str[i] == '/' || str[i] == '*' || str[i] == '-'||str[i]=='^')
        {
            double a = Pop(S);
            double b = Pop(S);
            switch (str[i])
            {
            case '+':
                Push(S, (double)a + b);
                break;
            case '-':
                Push(S, (double)b - a);
                break;
            case '*':
                Push(S, (double)b * a);
                break;
            case '/':
                if (a == 0)
                {
					return PI;
				}
                Push(S, (double)b / a);
                break;
            case '^':
                if (b <= 0 && a <= 0)
                {
                    return PI;
                }
				Push(S, pow(b, a));
				break;
            }
        }
    }
    double num = Pop(S);
    if (S->top == -1)
    {
        return num;
    }
    else
    {
        printf("��ʽ����6\n");
        exit(0);
    }
}

// ���㶨���ֵĺ�����ʹ������ɭ����
double integral(char*str,double(*f)(char*,double),double a, double b)  // a �� b �ǻ�����������Ҷ˵�
{
    double h = (b - a) / 100000; // ����
    double s = f(str,a) + f(str,b); // a �� b �ĺ���ֵ

    for (int i = 1; i < 100000; i++)
    {
        double x = a + h * i;
        s += f(str,x) * ((i % 2 == 0) ? 2 : 4); // ���������4��ż�������2
    }

    return s * h / 3;
}

// �����⺯��sin cos ����ֵ
double Recursion_operater(char* str, double x)
{
    int i = 0;
    while(str[i]!='\0')
    {
        if (str[i] == 's' && str[i + 1] == 'i' && str[i+2] == 'n' && str[i+3] == '(')
        {
            char*p0 = &str[i];
            char* p1= &str[i+3];
            Sqstack Sq;
            Sqstack* S = &Sq;
            Initstack(S);
            i = i + 3;
            int temp = i;
            while (S->top != -1||temp==i)
            {
                if (str[i] == '(')
                {
					Push(S, str[i]);
				}
                else if (str[i] == ')')
                {
					Pop(S);
				}
				i++;
            }
            char* p2 = &str[i - 1];
            char* strcopy = copySubstring(p1, p2);
            double num = Recursion_operater(strcopy, x);//�ݹ�����
            if (num == PI)
            {
				return PI;
			}
            num = sin(num);
            free(strcopy);
            char str1[30] = { 0 };
            if (num >= 0)
            {
                sprintf(str1, "(%d/10000000)", (int)(num * 10000000));
            }
            else
            {
                sprintf(str1, "(0%d/10000000)", (int)(num * 10000000));
            }
            char* str2 = replaceSubstring(str, p0, p2, str1);
            str = str2;
            i = 0;
            
        }
        if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's' && str[i + 3] == '(')
        {
			char* p0 = &str[i];
			char* p1 = &str[i + 3];
			Sqstack Sq;
			Sqstack* S = &Sq;
			Initstack(S);
			i = i + 3;
			int temp = i;
            while (S->top != -1 || temp == i)
            {
                if (str[i] == '(')
                {
					Push(S, str[i]);
				}
                else if (str[i] == ')')
                {
					Pop(S);
				}
				i++;
			}
			char* p2 = &str[i - 1];
			char* strcopy = copySubstring(p1, p2);
			double num = Recursion_operater(strcopy, x);//�ݹ�����
            if (num == PI)
            {
                return PI;
            }
			num = cos(num);
			free(strcopy);
			char str1[30] = { 0 };
            if (num >= 0)
            {
				sprintf(str1, "(%d/10000000)", (int)(num * 10000000));
			}
            else
            {
				sprintf(str1, "(0%d/10000000)", (int)(num * 10000000));
			}
			char* str2 = replaceSubstring(str, p0, p2, str1);
			str = str2;
            i = 0;
		}
        if (str[i] == 't' && str[i + 1] == 'a' && str[i + 2] == 'n' && str[i + 3] == '(')
        {
            char* p0 = &str[i];
            char* p1 = &str[i + 3];
            Sqstack Sq;
            Sqstack* S = &Sq;
            Initstack(S);
            i = i + 3;
            int temp = i;
            while (S->top != -1 || temp == i)
            {
                if (str[i] == '(')
                {
                    Push(S, str[i]);
                }
                else if (str[i] == ')')
                {
                    Pop(S);
                }
                i++;
            }
            char* p2 = &str[i - 1];
            char* strcopy = copySubstring(p1, p2);
            double num = Recursion_operater(strcopy, x);//�ݹ�����
            if (num == PI)
            {
                return PI;
            }
            num = tan(num);
            free(strcopy);
            char str1[30] = { 0 };
            if (num >= 0)
            {
                sprintf(str1, "(%d/10000000)", (int)(num * 10000000));
            }
            else
            {
                sprintf(str1, "(0%d/10000000)", (int)(num * 10000000));
            }
            char* str2 = replaceSubstring(str, p0, p2, str1);
            str = str2;
            i = 0;
        }
        if (str[i] == 'l' && str[i + 1] == 'n' && str[i + 2] == '(')
        {
			char* p0 = &str[i];
			char* p1 = &str[i + 2];
			Sqstack Sq;
			Sqstack* S = &Sq;
			Initstack(S);
			i = i + 2;
			int temp = i;
            while (S->top != -1 || temp == i)
            {
                if (str[i] == '(')
                {
					Push(S, str[i]);
				}
                else if (str[i] == ')')
                {
					Pop(S);
				}
				i++;
			}
			char* p2 = &str[i - 1];
			char* strcopy = copySubstring(p1, p2);
			double num = Recursion_operater(strcopy, x);//�ݹ�����
            if (num == PI)
            {
                return PI;
            }
            else if (num > 0)
            {
				num = log(num);
			}
            else
            {
				return PI;
			}
			free(strcopy);
			char str1[30] = { 0 };
            if (num >= 0)
            {
				sprintf(str1, "(%d/10000000)", (int)(num * 10000000));
			}
            else
            {
				sprintf(str1, "(0%d/10000000)", (int)(num * 10000000));
			}
			char* str2 = replaceSubstring(str, p0, p2, str1);
			str = str2;
            i = 0;
        }
        i++;
    }
    char* str1 = strreplace(str, x);
    char* str2 = strshift(str1);
    free(str1);
    double num = ReversePolishnotation(str2);
    free(str2);
    return num;
}
