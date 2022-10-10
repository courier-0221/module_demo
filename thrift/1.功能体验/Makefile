
client:
	g++ -g -o client -I./gen-cpp client.cc gen-cpp/Serv.cpp gen-cpp/student_types.cpp -lthrift -std=c++11

server:
	g++ -g -o server -I./gen-cpp server.cc gen-cpp/Serv.cpp gen-cpp/student_types.cpp -lthrift -std=c++11

clean-s:
	rm server -rf
clean-c:
	rm client -rf