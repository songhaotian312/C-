#include"head.h"


int main()
{
    // ��ʼ��ͼ�δ���
    initgraph(900, 600, EX_SHOWCONSOLE);
    Initscreen();
    printf("����sin,cos,ln����������Ա�ʶ��\n");
    printf("����������������渺��\n\n");
    printf("���������ű���(����),����һ��ʾ�Ŵ�С��һ��ʾ��С\n");
    printf("���ű���Ϊ1ʱһ��Ԫ���ʾ1\n");
    int scale = 0;
    int ks=scanf("%d", &scale);
    while (ks != 1)
    {
		printf("�����������������\n");
		while (getchar() != '\n')
			continue;
		ks = scanf("%d", &scale);
	}
    while (getchar() != '\n')
        continue;
    char str1[30] = { 0 };
    sprintf(str1, "���ʣ�%d", scale);
    settextcolor(BLACK);
    outtextxy(420, 0, str1);
    //���뺯������
    printf("���뺯��y=f(x)�ı��ʽ��\n");
    printf("y=");
    char* str = (char*)malloc(sizeof(char) * 30);
    gets_s(str, 30);
    while (check(str) == 0)
    {
		printf("����ƥ��ʧ�ܣ�����������\n");
		while (getchar() != '\n')
			continue;
		gets_s(str, 30);
	}
    Draw(str, scale);
    double a=0, b=0;
    //�����Ϣ
    ExMessage msg={0};
	while (1)
	{
        if (peekmessage(&msg,EX_MOUSE))
        {
            if (msg.message == WM_QUIT)
            {
				break;
			}
            else if (msg.message == WM_LBUTTONDOWN)
            {
				int x = msg.x;
				int y = msg.y;
                if (x >= 800 && x <= 900 && y >= 500 && y <= 600)
                {
                    clearrectangle(0, 0, 800, 600);
                    Initscreen();
					scale = scale + 1;
					sprintf(str1, "���ʣ�%d", scale);
                    printf("���ʼ�\n");
					settextcolor(BLACK);
					outtextxy(420, 0, str1);
					Draw(str, scale);
					Fill(a, b, str, scale);
				}
                else if (x >= 800 && x <= 900 && y >= 0 && y <= 100)
                {
                    clearrectangle(0, 0, 800, 600);
                    Initscreen();
                    scale=scale>=2?scale-1:scale;
					sprintf(str1, "���ʣ�%d", scale);
                    printf("���ʼ�\n");
					settextcolor(BLACK);
					outtextxy(420, 0, str1);
					Draw(str, scale);
					Fill(a, b, str, scale);
				}
                else if (x >= 800 && x <= 900 && y >= 100 && y <= 200)
                {
                    printf("���������������Ҷ˵㣺\n");
                    ks=scanf_s("%lf %lf", &a, &b);
                    while (ks != 2)
                    {
                        printf("�����������������\n");
                        while (getchar() != '\n')
							continue;
                    }
                    double result = integral(str, Recursion_operater, a, b);
                    printf("���Ϊ%.3lf\n", result);
                    clearrectangle(0, 0, 800, 600);
                    Initscreen();
                    scale = scale;
                    sprintf(str1, "���ʣ�%d", scale);
                    settextcolor(BLACK);
                    outtextxy(420, 0, str1);
                    Draw(str, scale);
                    Fill(a, b, str, scale);
                }
			}
		}
	}
}