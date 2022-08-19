#include<iostream>
#include<string>
#include<fstream>
#include"lm.helloworld.pb.h"

// g++ lm.helloworld.pb.cc  write.cc -std=c++11 -pthread -lprotobuf -lpthread

using namespace std;

int main(int argc, char *argv[])
{

	lm::helloworld msg;
	msg.set_id(100);
	msg.set_str("hello");
	msg.set_opt(200);

    // 1. 使用string序列化	
	string buff;
	msg.SerializeToString(&buff);
    cout << buff.size() << endl;	

	// 2. 使用文件序列化
    fstream out("msg.pb", ios::out | ios::binary | ios::trunc );
    msg.SerializeToOstream(&out);
    out.close();	

    // Optional:  Delete all global objects allocated by libprotobuf.
	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}

