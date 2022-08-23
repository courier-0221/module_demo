#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
��Ŀ��
	����Ƥ�ﳧ��Ь������ֻҪ�ҵ�������˳���(�����ұ��������ҽŵ�)��˫Ь�Ϳ��԰���һ˫Ь�ļ۸���ۣ�������ʵ���ҳ����˳��
	����˫Ь��������
	���費���ֿ�ʽ����'<'��ʾ�����Ь��'>'��ʾ�ҽ���Ь����"><<><>"���˳�����˫ЬΪ"<><>".
	
	���룺
		ֻ����'<'��'>'���ַ��������Ȳ�����1000.
	�����
		��һ�У���İ���˳�����˫Ь������
		�ڶ��У���'<'��'>�ַ���ʾ����Ӵ���'
		
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

	/* ǿ�ƶ��� */
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
				InputShoes		= EveTimesRet;		/* ǿ�ƶ��� */
				CountOfShoes	= 0;
			}
			else
			{
				InputShoes = EveTimesRet;			/* ǿ�ƶ��� */
				CountOfShoes = 0;
			}
		}
	}

	/* ���һ������ѭ��Ҫ�ж��� */
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