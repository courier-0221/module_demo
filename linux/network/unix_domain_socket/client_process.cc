#include <unix_domain_socket.h>

int main(void)
{
    int serverfd = client_connet_unix_domain_sock((char*)"./tmp.sock");
    char buf[16] = "12345678";
    write(serverfd, buf, 8);
    //char buf[16] = "12345678";
    //bl_event_send((char*)"./tmp.sock", buf, 8);

    return 0;
}