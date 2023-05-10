
#ifndef __UNIX_DOMAIN_SOCKET_H
#define __UNIX_DOMAIN_SOCKET_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <netinet/tcp.h>

int server_init_unix_domain_sock(char *sock_path);
int client_connet_unix_domain_sock(char *sock_path);
int bl_event_send(char *sock_path, void *send_data, int send_size);

#endif

