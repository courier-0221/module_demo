#include "Thread.h"
#include <iostream>
using namespace std;

Thread::Thread(func threadFunc) : autoDelete_(false), thread_func_(threadFunc)
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
}

void Thread::Join()
{
	pthread_join(threadId_, NULL);
}

void* Thread::ThreadRoutine(void* arg)
{
	Thread* thread = static_cast<Thread*>(arg);
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
