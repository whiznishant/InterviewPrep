#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<iostream>
#include<fstream>
#include<arpa/inet.h>
#include<unistd.h>


int main(int argc, char **argv)
{

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);
    std::fill(&server.sin_zero[0],&(server.sin_zero[0]) + 8,0);

    //Create socket
    int clientSock = socket(AF_INET,SOCK_STREAM,0);
    if ( clientSock == -1 )
    {
        perror("Socket Error: ");
        exit(-1);
    }
    
    int cret = connect(clientSock,(struct sockaddr *)&server,sizeof(server));
    if(cret == -1)
    {
        perror("Connect Error: ");
        exit(-1);
    }
    char recvdString[100];
    while(1)
    {
        int len = recv(clientSock,recvdString,100,MSG_WAITALL);
        if(len > 0 )
            std::cout<<std::endl<<recvdString;
        else 
            perror("Client:");
    }   
    close(clientSock);
   

}





