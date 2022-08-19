#include<iostream>
#include<string>
#include<fstream>
#include"lm.helloworld.pb.h"

// g++ lm.helloworld.pb.cc  read.cpp -std=c++11 -pthread -lprotobuf -lpthread

using namespace std;

int main(int argc, char *argv[])
{

	lm::helloworld msg;

	fstream in("msg.pb", ios::in | ios::binary);
	if(!msg.ParseFromIstream(&in)){
		cerr << "parse mgs.pb failed" << endl;
		in.close();
		return -1;
	}

	cout << "ID:" << msg.id() << endl;

	cout << "str:" << msg.str() << endl;

	cout << "opt:" << msg.opt() << endl;

	// Optional:  Delete all global objects allocated by libprotobuf.
	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}

