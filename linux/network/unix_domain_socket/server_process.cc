#include <unix_domain_socket.h>

int main(void)
{
    int serverfd = server_init_unix_domain_sock((char*)"./tmp.sock");
    char buf[8] = {0};
    read(serverfd, buf, 8);
    printf("%s\n", buf);

    return 0;
}