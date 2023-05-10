client:
	gcc -g -o client -I./ client_process.cc unix_domain_socket.cc
server:
	gcc -g -o server -I./ server_process.cc unix_domain_socket.cc
all-cs: client server

clean-s:
	rm server -rf
clean-c:
	rm client -rf
clean-all: clean-s clean-c