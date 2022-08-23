#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
题目：
	江南皮革厂卖鞋，宣传只要找到连续的顺序的(从左到右必须是左右脚的)整双鞋就可以按照一双鞋的价格出售，，请编程实现找出最长的顺序
	个整双鞋的数量。
	假设不区分款式，以'<'表示左脚拖鞋，'>'表示右脚拖鞋，则"><<><>"的最长顺序个整双鞋为"<><>".
	
	输入：
		只包含'<'和'>'的字符串，长度不超过1000.
	输出：
		第一行：最长的包含顺序个整双鞋的数量
		第二行：用'<'和'>字符表示的最长子串。'
		
*/


int JiangNan(char *InputShoes, char *OutputShoes)
{
	int		MaxNumOfShoes	= 0;
	int		CountOfShoes	= 0;
	char	*IndexOffset	= NULL;
	char	*EveTimesRet	= NULL;
	char	*OffsetOfShoes	= NULL;

	if (NULL == InputShoes || NULL == OutputShoes)
	{
		return -1;
	}

	/* 强制对齐 */
	if (NULL != (EveTimesRet = strstr(InputShoes, "<>")))
	{
		InputShoes = EveTimesRet;
	}
	else
	{
		return 0;
	}


	while (NULL != (EveTimesRet = strstr(InputShoes, "<>")))
	{
		if (InputShoes == EveTimesRet)
		{
			CountOfShoes++;
			if (1 == CountOfShoes)
			{
				IndexOffset = EveTimesRet;
			}
			InputShoes = EveTimesRet + strlen("<>");
		}
		else
		{
			if (CountOfShoes > MaxNumOfShoes)
			{
				MaxNumOfShoes	= CountOfShoes;
				OffsetOfShoes	= IndexOffset;
				InputShoes		= EveTimesRet;		/* 强制对齐 */
				CountOfShoes	= 0;
			}
			else
			{
				InputShoes = EveTimesRet;			/* 强制对齐 */
				CountOfShoes = 0;
			}
		}
	}

	/* 最后一次跳出循环要判断下 */
	if (CountOfShoes > MaxNumOfShoes)
	{
		MaxNumOfShoes = CountOfShoes;
		OffsetOfShoes = IndexOffset;
	}

	if (0 != MaxNumOfShoes)
	{
		strncpy(OutputShoes, OffsetOfShoes, strlen("<>") * MaxNumOfShoes);
	}

	return MaxNumOfShoes;
}

int main(void)
{
	int NumOfShoes = 0;
	char OutputShoes[1000] = { 0 };
	//char *InputShoes = "<<><><>>>>>><>>>>";
	//char *InputShoes = "<<><><>>>>><>>>><>>>>";
	char *InputShoes = "<<<>>>><><>><>>><><><><>>";

	NumOfShoes = JiangNan(InputShoes, OutputShoes);

	printf("NumOfShoes = %d\n", NumOfShoes);
	printf("InputShoes = %s\n", InputShoes);
	printf("OutputShoes = %s\n", OutputShoes);

	system("pause");
	return 0;
}