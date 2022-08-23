#include <stdio.h>
#include <assert.h>

/*
题目：
	判断字符串是否含有回文字符子串
思路：
	枚举字符串的每个位置，作为回文串的中间位置(分偶数奇数两种情况)，
	如果找到或者找不到都会立即停止，所以总的复杂度不超过O(n)
*/

int if_huiwen(const char *str)
{
	assert(str);
	char *strbak = str + 1;
	while (*strbak != 0){
		
		if (*strbak == *(strbak - 1)){				//偶数情况
			return 1;
		}
		else if(*(strbak - 1) == *(strbak + 1)){	//奇数情况
			return 1;
		}
		strbak++;
	}
	return 0;
}

int main(void)
{

	if (if_huiwen("sdg121fh") == 1){
		printf("该串中含有回文\n");
	}
	else{
		printf("该串中不含有回文\n");
	}


	system("pause");
	return 0;
}
