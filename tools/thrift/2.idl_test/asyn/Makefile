client:
	g++ -g -o client -I./gen-cpp client.cc gen-cpp/Regist.cpp gen-cpp/clientInfo_types.cpp -lthrift -lthriftz -lthriftnb -levent -Wl,-rpath,/usr/local/lib -std=c++11
server:
	g++ -g -o server -I./gen-cpp server.cc gen-cpp/Regist.cpp gen-cpp/clientInfo_types.cpp -lthrift -lthriftz -lthriftnb -levent -Wl,-rpath,/usr/local/lib -std=c++11

cs: client server

clean-s:
	rm server -rf
clean-c:
	rm client -rf

clean-all: clean-s clean-c