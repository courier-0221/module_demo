#include <thrift/transport/TTransportUtils.h>
#include <thrift/transport/TSocket.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include "Regist.h"

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace  ::vnmp;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

int main()
{
	std::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
	std::shared_ptr<TTransport> transport(new TFramedTransport(socket));
	std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	RegistClient client(protocol);
	transport->open();

    struct timeval tv;
	
    ClientInfo cliInfo;
    cliInfo.name = "zhangsan";
    cliInfo.realIP = "192.168.1.100";
    cliInfo.vpnIP = "10.10.5.9";
    cliInfo.type = ClientType::DOM_MANAGER;
    cliInfo.description = "waiting for ...";
    
    // 调用时计时
    memset(&tv, 0, sizeof(tv));
    gettimeofday(&tv, NULL);
    printf("start call registClient... second=%ld\n", tv.tv_sec);
	auto ret_registClient = client.registClient(cliInfo);
    // 函数返回时计时
    memset(&tv, 0, sizeof(tv));
    gettimeofday(&tv, NULL);
    std::cout << "registClient return=" << ret_registClient << std::endl;
    printf("end call registClient... second=%ld\n", tv.tv_sec);

    printf("\n");

    // 调用时计时
    memset(&tv, 0, sizeof(tv));
    gettimeofday(&tv, NULL);
    printf("start call heartbeat... second=%ld\n", tv.tv_sec);
    auto ret_heartbeat = client.heartbeat("zhangsan", ClientType::DOM_MANAGER);
    // 函数返回时计时
    memset(&tv, 0, sizeof(tv));
    gettimeofday(&tv, NULL);
    std::cout << "heartbeat return=" << ret_heartbeat << std::endl;
    printf("end call heartbeat... second=%ld\n", tv.tv_sec);

    transport->close();
	return 0;
}
