/*

Author1 : Gayrav Pathak
Author2 : Jaydeep Kumar

*/


#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 
   
int main(int argc, char const *argv[]) 
{ 
    struct sockaddr_in address; 
    int sock = 0, valread,valread1; 
    struct sockaddr_in serv_addr; 
    int c; char sc[16];
    printf("Enter the cvv number:");
    scanf("%d",&c);
    sprintf(sc,"%d",c);
    char buffer[1024] = {0}; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    }
    char temp[1024],buffer1[10]={0}; int sh,fees;
    send(sock , sc ,strlen(sc) , 0 ); 
    printf("Hello message sent\n"); 
    valread = read( sock , buffer, 1024); 
    printf("%s\n",buffer );
    printf("Enter the OTP:");
    scanf("%d",&sh);
    sprintf(buffer1,"%d",sh);
    send(sock,buffer1,strlen(buffer1),0);
    valread1=read(sock,buffer,1024);
    printf("Enter the amount ");
    scanf("%d",&fees);
    sprintf(temp,"%d",fees);
    send(sock,temp,strlen(temp),0);
    return 0; 
} 
