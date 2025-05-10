#include "gen-cpp/Regist.h"
#include <string>
#include <iostream>
#include <functional>
#include <unistd.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/Thread.h>
#include <thrift/async/TAsyncChannel.h>
#include <thrift/async/TEvhttpClientChannel.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/protocol/TProtocol.h>
#include <event.h>

using namespace  ::apache::thrift;
using namespace  ::apache::thrift::transport;
using namespace  ::apache::thrift::protocol;
using namespace  ::apache::thrift::async;
using namespace  ::apache::thrift::concurrency;
using namespace  ::vnmp;

class MyClient : public RegistCobClient
{
public:
	MyClient(::std::shared_ptr<TAsyncChannel> channel, TProtocolFactory* protocolFactory)
		: RegistCobClient(channel, protocolFactory)
	{

	}
	virtual ~MyClient(){}

	virtual void completed__(bool success)
	{
		if (success)
		{
			std::cout << "completed" << std::endl;
		}
		else
		{
			std::cout << "completed failed" << std::endl;
		}
	}
    void recv_registClient_cb()
	{
		std::cout << "recv_registClient_cb" << std::endl;
		std::cout << "recv_registClient ret=" << recv_registClient() << std::endl;
	}

    void recv_heartbeat_cb()
	{
		std::cout << "recv_heartbeat_cb" << std::endl;
		std::cout << "recv_heartbeat ret=" << recv_heartbeat() << std::endl;
	}
private:

};

class ClientThread : public Runnable
{
public:
	ClientThread(event_base* base, std::string & host, int port)
		: _base(base), _host(host), _port(port)
	{
	}
	virtual ~ClientThread(){}
	virtual void run()
	{
		std::shared_ptr<TAsyncChannel>  channel(new TEvhttpClientChannel(_host, "/", _host.c_str(), _port, _base));
		MyClient client(channel, new TBinaryProtocolFactory());

        struct timeval tv;
	
        ClientInfo cliInfo;
        cliInfo.name = "zhangsan";
        cliInfo.realIP = "192.168.1.100";
        cliInfo.vpnIP = "10.10.5.9";
        cliInfo.type = ClientType::DOM_MANAGER;
        cliInfo.description = "waiting for ...";
        printf("start call registClient...\n");
        client.registClient(std::bind(&MyClient::recv_registClient_cb, &client), cliInfo);
        printf("end call registClient...\n");

        printf("\n");

        printf("start call heartbeat...\n");
        client.heartbeat(std::bind(&MyClient::recv_heartbeat_cb, &client),"zhangsan", ClientType::DOM_MANAGER);
        printf("end call heartbeat...\n");

		sleep(10);
	}
protected:
private:
	event_base* _base;
	std::string _host;
	int _port;
};

int main()
{
	std::string host = "127.0.0.1";
	int port = 9090;

	event_base* base = event_base_new();

	std::shared_ptr<ThreadFactory> threadFactory = std::shared_ptr<ThreadFactory>(new ThreadFactory());
	std::shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(10);

	threadManager->threadFactory(threadFactory);
	threadManager->start();

	std::shared_ptr<Thread> thread = threadFactory->newThread(std::shared_ptr<ClientThread>(new ClientThread(base, host, port)));
	thread->start();

	event_base_dispatch(base);
	event_base_free(base);

	return 0;
}
