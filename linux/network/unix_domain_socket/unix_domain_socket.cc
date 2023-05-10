#include <unix_domain_socket.h>

static int setnonblocking(int fd)
{
    int old_option = fcntl( fd, F_GETFL );
    int new_option = old_option | O_NONBLOCK;
    fcntl( fd, F_SETFL, new_option );
    return old_option;
}

int server_init_unix_domain_sock(char *sock_path)
{
    int sock = -1;
    int er_cnt = 0;
    int len = 0;
    int ret = 0;
    struct sockaddr_un addr;

    /* prepare unix socket paths */
    unlink(sock_path);

    /* create sockets */
    sock = socket(PF_UNIX, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        printf("[%s] socket failed, error = %s\n", sock_path, strerror(errno));
        return sock;
    }
    else
    {
        printf("[%s] socket success, sock = %d\n", sock_path, sock);
    }

    /* bind */
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, sock_path);

    len = offsetof(struct sockaddr_un, sun_path) + strlen(addr.sun_path);
    while (1)
    {
        /* care the len of bind */
        ret = bind(sock, (struct sockaddr *)&addr, len);
        if (!ret)
        {
            printf("bind success!\n");
            break;
        }
        else
        {
            if (er_cnt++ > 3)
            {
                printf("sock = %d, bind error = %s, cnt = %d\n", sock, strerror(errno), er_cnt);
            }
            sleep(1);
        }
    }

    return sock;
}

int client_connet_unix_domain_sock(char *sock_path)
{
    int ret = -1;    
    int socket_fd = -1;
	int read_sec = 5, write_sec = 5;
    int keepAlive = 1;      // 开启keepalive属性
	int keepIdle = 60;      // 如该连接在60秒内没有任何数据往来,则进行探测
	int keepInterval = 5;   // 探测时发包的时间间隔为5 秒
	int keepCount = 3;      // 探测尝试的次数.如果第1次探测包就收到响应了,则后2次的不再发.
    int fdopt = -1;
    struct sockaddr_un srv_addr = {};  

    if (access(sock_path, F_OK) != 0)
    {
        printf("sock_path=%s is not exit\n", sock_path); 
        ret = -1;
        goto EXIT1;
    }
   
    socket_fd = socket(PF_UNIX, SOCK_DGRAM, 0);    
    if (socket_fd < 0)    
    {    
        printf("client_connet_unix_domain_sock cannot create communication socket\n"); 
        ret = -1;
        goto EXIT0;    
    }

    setsockopt(socket_fd, SOL_SOCKET, SO_KEEPALIVE, &keepAlive, sizeof(keepAlive));
    setsockopt(socket_fd, SOL_TCP, TCP_KEEPIDLE, &keepIdle, sizeof(keepIdle));
    setsockopt(socket_fd, SOL_TCP, TCP_KEEPINTVL, &keepInterval, sizeof(keepInterval));
    setsockopt(socket_fd, SOL_TCP, TCP_KEEPCNT, &keepCount, sizeof(keepCount));
	setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, &read_sec, sizeof(read_sec));
	setsockopt(socket_fd, SOL_SOCKET, SO_SNDTIMEO, &write_sec, sizeof(write_sec));
    srv_addr.sun_family = AF_UNIX;    
    strcpy(srv_addr.sun_path, sock_path);  
	fdopt = setnonblocking(socket_fd);
    ret = connect(socket_fd,(struct sockaddr*)&srv_addr,sizeof(srv_addr));    
    if (ret)    
    {    
        printf("client_connet_unix_domain_sock connect err!!! errno=%s\n", strerror(errno)); 
        goto EXIT1;
    }
	fcntl(socket_fd, F_SETFL, fdopt); 

    ret = socket_fd;
    return ret;

EXIT1: 
    if (socket_fd >= 0)
    {
        close(socket_fd);
    }
EXIT0:
    return ret;
}

int bl_event_send(char *sock_path, void *send_data, int send_size)
{
    int result = -1;
    int socket_fd = -1;
    struct sockaddr_un sock_addr = {};
    socklen_t sock_addr_len = 0;

    /* check param */
    if (NULL == send_data)
    {
        printf("param send_data is null!\n");
        result = -1;
        goto EXIT0;
    }

    sock_addr.sun_family = AF_UNIX;
    strcpy(sock_addr.sun_path, sock_path);

    socket_fd = socket(PF_UNIX, SOCK_DGRAM, 0);
    if (socket_fd < 0)
    {
        printf("creat sockte fail! err = %s\n", strerror(errno));
        goto EXIT0;
    }

    sock_addr_len = offsetof(struct sockaddr_un, sun_path) + strlen(sock_addr.sun_path);
    result = sendto(socket_fd, send_data, send_size, 0, (struct sockaddr *)&sock_addr, sock_addr_len);
    if (result < 0)
    {
        printf("sendto fail! err = %s\n", strerror(errno));
        goto EXIT0;
    }

    result = -1;
EXIT0:
    if (socket_fd >= 0)
    {
        close(socket_fd);
    }

    return result;
}
