#include <thread>
#include <unistd.h>
#include <iostream>
using namespace std;

class AsynReporter
{
public:
	AsynReporter() {
		_thr = std::thread(&AsynReporter::workthread, this);
	}
	virtual ~AsynReporter() {
		_thr.join();
	}
private:
	virtual void block_report() = 0;

private:
	std::thread _thr;
	void workthread(void) 
	{
		sleep(2);
		block_report();
	}
};

class AsynReporterHttp : public AsynReporter
{
public:
	AsynReporterHttp() :AsynReporter(){}
	virtual ~AsynReporterHttp() {}
protected:
	virtual void block_report() override
	{
		cout << "AsynReporterHttp" << endl;
	}
};

class KoalaOnlineStorage : public AsynReporterHttp
{
public:
	KoalaOnlineStorage() :AsynReporterHttp(){}
	virtual ~KoalaOnlineStorage() {}
protected:
	virtual void block_report() override
	{
		cout << "KoalaOnlineStorage" << endl;
	}
};

// 无父类指针指向子类对象，也就没有发生多态，用继承解释

int main(void)
{
	KoalaOnlineStorage kos_01;

	sleep(4);
	return 0;
}