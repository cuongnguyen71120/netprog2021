#include<stdio.h>
#include<arpa/inet.h>// inet_addr
#include<sys/socket.h>// socket
#include<netdb.h>
#include<string.h>//strlen
#include<stdlib.h>
# define PORT 8784;

int main(){
    struct sockaddr_in severaddr,caddr;
    int sever_family,bind_create,listen_port;
    int clen,accept_create;
    unsigned short port = 8784;
    //create socket
    sever_family=socket(AF_INET,SOCK_STREAM,0);
    if (sever_family<0){
        printf("Could not create socket.....\n");
        exit(0);
    }
    else
    {
        printf("Socket created\n");
    }
    memset(&severaddr,0,sizeof(severaddr));
    severaddr.sin_family=AF_INET;
    severaddr.sin_addr.s_addr=AF_INET;
    severaddr.sin_port=htons(port);
    inet_pton(AF_INET,"0.0.0.0",&severaddr.sin_addr);

    //create the bind
    bind_create=bind(sever_family,(struct sockaddr*)&severaddr,sizeof(severaddr));
    if(bind_create<0){
        printf("Error binding\n");
        exit(0);
    }
    printf("Bind done\n");

    //create the listen 
    listen_port=listen(sever_family,5);
    if(listen_port<0){
        printf("Error listening\n");
        exit(0);

    }
    printf("Successfully listened\n");


    //create the accept function 
    clen=sizeof(caddr);
    accept_create=accept(sever_family,(struct sockaddr*)&caddr,&clen);
    if(accept_create<0){
        printf("Error accept\n");
        exit(0);
    }
    else
    printf("Connection accepted");
    return 0;
}
