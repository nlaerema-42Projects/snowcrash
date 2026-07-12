#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

int main(void)
{
    int server_fd;
    struct sockaddr_in addr;

    // Création de la socket TCP
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("socket");
        return 1;
    }

    // Écouter sur toutes les interfaces
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(6969);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Associer la socket au port 6969
    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        perror("bind");
        close(server_fd);
        return 1;
    }

    // Mise en écoute
    if (listen(server_fd, 10) == -1)
    {
        perror("listen");
        close(server_fd);
        return 1;
    }

    printf("Serveur en écoute sur le port 6969...\n");

    while (1)
    {
        fd_set readfds;

        FD_ZERO(&readfds);
        FD_SET(server_fd, &readfds);

        // Attend qu'une connexion arrive
        if (select(server_fd + 1, &readfds, NULL, NULL, NULL) == -1)
        {
            perror("select");
            break;
        }

        if (FD_ISSET(server_fd, &readfds))
        {
            printf("Nouvelle connexion détectée !\n");

            //system("ln -sf /home/user/level10/token /tmp/access");

            int client_fd = accept(server_fd, NULL, NULL);
            if (client_fd == -1)
            {
                perror("accept");
                continue;
            }

            printf("Connexion acceptée.\n");

            char buffer[2048];
            ssize_t n;

            while ((n = recv(client_fd, buffer, sizeof(buffer) - 1, 0)) > 0)
            {
                buffer[n] = '\0';
                printf("Reçu : %s", buffer);
            }

            printf("Client déconnecté.\n");
            close(client_fd);
        }
    }

    close(server_fd);
    return 0;
}