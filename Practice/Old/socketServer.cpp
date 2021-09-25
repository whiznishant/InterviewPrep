#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<iostream>
#include<fstream>
#include<arpa/inet.h>
#include<unistd.h>


int main()
{
    int socketfd, clientfd;
    struct sockaddr_in server,client;

    server.sin_family = AF_INET;
    server.sin_port = htons(8000);
    server.sin_addr.s_addr = INADDR_ANY;
    std::fill(&server.sin_zero[0],&(server.sin_zero[0]) + 8,0);

    //Create a socket
    socketfd = socket(AF_INET,SOCK_STREAM,0);
    if ( socketfd == -1 )
    {
        perror("Socket Error: ");
        exit(-1);
    }
    
    //Bind the socket
    int bret = bind(socketfd, (struct sockaddr *)&server,sizeof(server));
    if( bret == -1)
    {
        perror("Bind Error: ");
        exit(-1);
    }
    
    //Listen on this socket.
    int ret = listen(socketfd,5);
    if(ret == -1)
    {
        perror("Listen Error: ");
        exit(-1);
    }

    //Accept client connection
    while(1)
    {
        uint len = sizeof(client);
        clientfd = accept(socketfd,(struct sockaddr *)&client,(socklen_t* )&len);
        if( clientfd == -1 )
        {
            perror("ClientConnect Error:");
        }
        std::cout<<std::endl<<"Client connected:"<< inet_ntoa(client.sin_addr) << std::endl;

        //Send Data to client
        char message[1000]= "This is an Echo Server !! \n";
        send(clientfd,message,strlen(message),0);
      

        //Close client connection
        std::cout<<"Closing client connection";
        close(clientfd);
    }
    
    return 0;
}


