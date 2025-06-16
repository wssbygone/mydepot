#include <cstddef>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define UNIX_DOMAIN "/home/wss/mydepot/go/uds/sidecar.sock"

int main(void) {
    int listen_fd, com_fd;
    int ret;
    char data_buf[1024];
    struct sockaddr_un srv_addr, clt_addr;
    socklen_t len;

    // 创建 Socket
    listen_fd = socket(PF_UNIX, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("cannot create socket");
        return 1;
    }

    // 绑定地址
    srv_addr.sun_family = AF_UNIX;
    strncpy(srv_addr.sun_path, UNIX_DOMAIN, sizeof(srv_addr.sun_path) - 1);
    unlink(UNIX_DOMAIN); // 确保路径未被占用

    ret = bind(listen_fd, (struct sockaddr*)&srv_addr, sizeof(srv_addr));
    if (ret == -1) {
        perror("cannot bind socket");
        close(listen_fd);
        return 1;
    }

    // 监听
    ret = listen(listen_fd, 5); // 增加 backlog 数量
    if (ret == -1) {
        perror("cannot listen");
        close(listen_fd);
        unlink(UNIX_DOMAIN);
        return 1;
    }

    printf("Server is listening...\n");

    while (1) {
        // 接受连接
        len = sizeof(clt_addr);
        com_fd = accept(listen_fd, (struct sockaddr*)&clt_addr, &len);
        if (com_fd < 0) {
            perror("accept failed");
            continue; // 继续等待新连接
        }

        printf("Client connected.\n");

        // 持续处理客户端请求
        while (1) {
            memset(data_buf, 0, sizeof(data_buf));
            ssize_t n = read(com_fd, data_buf, sizeof(data_buf) - 1);
            if (n <= 0) {
                perror("read error or client closed");
                break;
            }

            printf("Received: %s", data_buf);

            // 回显数据
            if (write(com_fd, data_buf, n) != n) {
                perror("write error");
                break;
            }
        }

        close(com_fd);
        printf("Client disconnected.\n");
    }

    close(listen_fd);
    unlink(UNIX_DOMAIN);
    return 0;
}

