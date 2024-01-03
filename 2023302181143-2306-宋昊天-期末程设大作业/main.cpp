#include"head.h"


int main()
{
    // 初始化图形窗口
    initgraph(900, 600, EX_SHOWCONSOLE);
    Initscreen();
    printf("请在sin,cos,ln后添加括号以便识别\n");
    printf("请用零减正数来代替负数\n\n");
    printf("请输入缩放比例(整数),大于一表示放大，小于一表示缩小\n");
    printf("缩放比例为1时一单元格表示1\n");
    int scale = 0;
    int ks=scanf("%d", &scale);
    while (ks != 1)
    {
		printf("输入错误，请重新输入\n");
		while (getchar() != '\n')
			continue;
		ks = scanf("%d", &scale);
	}
    while (getchar() != '\n')
        continue;
    char str1[30] = { 0 };
    sprintf(str1, "倍率：%d", scale);
    settextcolor(BLACK);
    outtextxy(420, 0, str1);
    //输入函数主体
    printf("输入函数y=f(x)的表达式：\n");
    printf("y=");
    char* str = (char*)malloc(sizeof(char) * 30);
    gets_s(str, 30);
    while (check(str) == 0)
    {
		printf("括号匹配失败，请重新输入\n");
		while (getchar() != '\n')
			continue;
		gets_s(str, 30);
	}
    Draw(str, scale);
    double a=0, b=0;
    //鼠标消息
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
					sprintf(str1, "倍率：%d", scale);
                    printf("倍率加\n");
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
					sprintf(str1, "倍率：%d", scale);
                    printf("倍率减\n");
					settextcolor(BLACK);
					outtextxy(420, 0, str1);
					Draw(str, scale);
					Fill(a, b, str, scale);
				}
                else if (x >= 800 && x <= 900 && y >= 100 && y <= 200)
                {
                    printf("输入积分区间的左右端点：\n");
                    ks=scanf_s("%lf %lf", &a, &b);
                    while (ks != 2)
                    {
                        printf("输入错误，请重新输入\n");
                        while (getchar() != '\n')
							continue;
                    }
                    double result = integral(str, Recursion_operater, a, b);
                    printf("结果为%.3lf\n", result);
                    clearrectangle(0, 0, 800, 600);
                    Initscreen();
                    scale = scale;
                    sprintf(str1, "倍率：%d", scale);
                    settextcolor(BLACK);
                    outtextxy(420, 0, str1);
                    Draw(str, scale);
                    Fill(a, b, str, scale);
                }
			}
		}
	}
}