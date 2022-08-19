#include "Thread.h"
#include <unistd.h>
#include <iostream>
#include <memory>
using namespace std;

class TestThread : public Thread
{
public:
	TestThread(int count) : count_(count)
	{
		cout << "TestThread(int count)" << endl;
	}
	~TestThread()
	{
		cout << "~TestThread()" << endl;
	}
private:
	void Run()
	{
		while(count_--)
		{
			cout << "test thread: " << count_ << endl;
			sleep(1);
		}
	}
private:
	int count_;
};

int main(void)
{
	/*
	TestThread tt(5);
	tt.Start();
	tt.Join();
	*/
	
	TestThread *tt = new TestThread(5);
	//shared_ptr<TestThread> tt(new TestThread(5));
	tt->SetAutoDelete(true);
	tt->Start();
	tt->Join();

	sleep(3);
	return 0;
}