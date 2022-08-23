#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

static int* GetAnyRedBlueBall(int *redball, int rednum, int *blueball, int bluenum);
static void GetUserInput(int *redball, int *rednum, int *blueball, int *bluenum);

int main(void)
{
	int RedNum = 0, BlueNum = 0;
	int RedBall[26] = { 0 }, BlueBall[15] = { 0 };
	int *PreResults = NULL;

	GetUserInput(RedBall, &RedNum, BlueBall, &BlueNum);
	PreResults = GetAnyRedBlueBall(RedBall, RedNum, BlueBall, BlueNum);
	if (NULL != PreResults)
	{
		int i = 0;
		printf("************************************************\n");
		printf("REDBALL IS :\n");
		for (i = 0; i<6; i++)
		{
			printf("%d\t", PreResults[i]);
		}
		printf("\nBLUEBALL IS :\n");
		printf("%d\n", PreResults[6]);
		printf("************************************************\n");
	}
	free(PreResults);
	PreResults = NULL;

	printf("Congratulations !!!\n");
	system("pause");
	return 0;
}


static int* GetAnyRedBlueBall(int *redball, int rednum, int *blueball, int bluenum)
{
	if ((NULL == redball) || (NULL == blueball))
	{
		printf("[%s]->[%d]\n", __FUNCTION__, __LINE__);
		return NULL;
	}
	/*
	int z = 0;
	printf("\n临时测试\n");
	for (z = 0; z<rednum; z++)
	{
		printf("%d\t", redball[z]);
	}
	printf("\n临时测试\n");
	for (z = 0; z<bluenum; z++)
	{
		printf("%d\t", blueball[z]);
	}
	printf("\n");
	*/

	int *PreResults = (int *)malloc(sizeof(int)* 7);
	if (NULL == PreResults)
	{
		printf("[%s]->[%d]\n", __FUNCTION__, __LINE__);
		return NULL;
	}
	memset(PreResults, 0, sizeof(int)* 7);

	srand(time(NULL));
	int i = 0, j = 0;
	/*选出6个红球*/
	while (i < 6)
	{
		int RedBallTmp = rand() % 33 + 1;
		int NotFindInInPutFlag = 0;
		int NotFindInPreResFlag = 0;
		for (j = 0; j < rednum; j++)
		{
			if (RedBallTmp == redball[j])
			{
				NotFindInInPutFlag = 1;
				break;
			}
			else
			{
				NotFindInInPutFlag = 0;
			}
		}

		/* 在以预测的结果里面有没有，有的话重新找。 */
		for (j = 0; j < i; j++)
		{
			if (RedBallTmp == PreResults[j])
			{
				NotFindInPreResFlag = 1;
				break;
			}
			else
			{
				NotFindInPreResFlag = 0;
			}
		}

		if ((NotFindInInPutFlag == 1) || (NotFindInPreResFlag == 1))
		{
			continue;
		}
		else
		{
			PreResults[i] = RedBallTmp;
			i++;
		}
	}

	i = 0, j = 0;
	/*选出1个蓝球*/
	while (i < 1)
	{
		int BlueBallTmp = rand() % 16 + 1;
		int NotFindFlag = 0;
		for (j = 0; j < bluenum; j++)
		{
			if (BlueBallTmp == blueball[j])
			{
				NotFindFlag = 1;
				break;
			}
			else
			{
				NotFindFlag = 0;
			}
		}
		if (NotFindFlag == 1)
		{
			continue;
		}
		else
		{
			PreResults[6] = BlueBallTmp;
			i++;
		}
	}

	/*
	printf("临时测试\n");
	for(i=0;i<7;i++)
	{
		printf("%d\t",PreResults[i]);
	}
	printf("\n");
	*/

	return PreResults;
}

static void GetUserInput(int *redball, int *rednum, int *blueball, int *bluenum)
{
	if ((NULL == redball) || (NULL == blueball) || (NULL == rednum) || (NULL == bluenum))
	{
		printf("[%s]->[%d]\n", __FUNCTION__, __LINE__);
		exit(-1);
	}

	int i = 0, RedNum = 0, BlueNum = 0;

	printf("Please enter the number of red balls.\n");
	scanf("%d", &RedNum);
	*rednum = RedNum;
	printf("Please enter the red ball number.\n");
	for (i = 0; i<RedNum; i++)
	{
		int tmp = 0;
		scanf("%d", &tmp);
		redball[i] = tmp;
	}

	/*
	{
		printf("Test\n");
		printf("%d\n",RedNum);
		int j=0;
		for(j=0;j < RedNum; j++)
		{
			printf("%d\n", redball[j]);
		}
	}
	*/
	printf("Please enter the number of blue balls.\n");
	scanf("%d", &BlueNum);
	*bluenum = BlueNum;
	printf("Please enter the blue ball number.\n");
	for (i = 0; i<BlueNum; i++)
	{
		int tmp = 0;
		scanf("%d", &tmp);
		blueball[i] = tmp;
	}
	/*
	{
		printf("Test\n");
		printf("%d\n",BlueNum);
		int j=0;
		for(j=0;j < BlueNum; j++)
		{
			printf("%d\n", blueball[j]);
		}
	}
	*/
}
