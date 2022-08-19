#include "Thread.h"
#include <unistd.h>
#include <iostream>
#include <memory>
using namespace std;

void threadTestFunc()
{
	int count = 5;
	while(count--)
	{
		cout << "threadTestFunc: " << count << endl;
		sleep(1);
	}
}

int main(void)
{
	Thread *tt = new Thread(threadTestFunc);
	
	tt->SetAutoDelete(true);
	tt->Start();
	tt->Join();

	sleep(3);
	return 0;
}

