#include "Thread.h"
#include <iostream>
using namespace std;

Thread::Thread(func threadFunc) : autoDelete_(false), thread_func_(threadFunc), _mutex(), _condition(_mutex)
{
	cout << "Thread()" << endl;
}

Thread::~Thread()
{
	cout << "~Thread()" << endl;
}

void Thread::Start()
{
	pthread_create(&threadId_, NULL, ThreadRoutine, this);
    // 等待线程启动并切有足够的时间从调用上下文中获取所需的一切
    _condition.wait();
}

void Thread::Join()
{
	pthread_join(threadId_, NULL);
}

void* Thread::ThreadRoutine(void* arg)
{
	Thread* thread = static_cast<Thread*>(arg);
    // 线程已经启动，已从主线程中获取到了需要的参数内容
    thread->_condition.notify();
	
    thread->Run();
	//thread->thread_func_();
	if (thread->autoDelete_)
		delete thread;
	return NULL;
}

void Thread::SetAutoDelete(bool autoDelete)
{
	autoDelete_ = autoDelete;
}

void Thread::Run()
{
	thread_func_();
}
