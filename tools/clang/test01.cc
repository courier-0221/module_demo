#include <stdio.h>
#include <malloc.h>

// scan-build gcc test01.cc
// scan-build clang test01.cc
// 使用不同的编译工具scan-build都可以对源码做静态分析
// 使用clang编译出的内容同样可以使用gdb调试

int main(int argc, char **argv) {

	int i;
	i = 10;
	printf("%s\n", i);

    char *buf = (char*)malloc(10);

	return 0;
}
