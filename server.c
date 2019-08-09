/*
Author1 : Garurav Pathak

Author2 : Jaydeep Kumar


*/


#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 

int i,n; char bin[256];
int ext(FILE *f){   // extracting amount of the cvv given
        fscanf(f,"%d",&i);
        return i;
}

int binary(int x){  // changing to binary
        int k=0,p; char popo[256];
        while(x>0){
                int s=x%2;
		popo[k]=s+'0';
                x=x/2;
                k++;
        }
	for(p=0;p<k;p++){
		bin[p]=popo[k-p-1];
	}
	return k;
}
//***************hash Part*********************************

char binaryhex[100];
int hashf(int power,char seed[17])
{
int i;
FILE *f,*f1;
int flag=0;
for(i=0;i<power;i++){
f=fopen("seedf.txt","w+");
fputs(seed,f);
fclose(f);
system("md5sum seedf.txt >> tex1.txt");
f1=fopen("tex1.txt","r+");
char hex[5];
fgets(hex,5,(FILE*)f1);
char bin1[65] = "";
int i = 0;
for(i=0; hex[i]!='\0'; i++)
    {
        switch(hex[i])
        {
            case '0':
                strcat(bin1, "0000");
                break;
            case '1':
                strcat(bin1, "0001");
                break;
            case '2':
                strcat(bin1, "0010");
                break;
            case '3':
                strcat(bin1, "0011");
                break;
            case '4':
                strcat(bin1, "0100");
                break;
            case '5':
                strcat(bin1, "0101");
                break;
            case '6':
                strcat(bin1, "0110");
                break;
            case '7':
                strcat(bin1, "0111");
                break;
            case '8':
                strcat(bin1, "1000");
                break;
            case '9':
                strcat(bin1, "1001");
                break;
            case 'a':
            case 'A':
                strcat(bin1, "1010");
                break;
            case 'b':
            case 'B':
                strcat(bin1, "1011");
                break;
            case 'c':
            case 'C':
                strcat(bin1, "1100");
                break;
            case 'd':
            case 'D':
                strcat(bin1, "1101");
                break;
            case 'e':
            case 'E':
                strcat(bin1, "1110");
                break;
            case 'f':
            case 'F':
                strcat(bin1, "1111");
                break;
            default:
                printf("Invalid hexadecimal input.");
        }
    }
for(i=0;i<16;i++)
{
seed[i]=bin1[i];
}
remove("tex1.txt");
flag++;
}
if(flag==power)
{for(i=0;i<16;i++)
binaryhex[i]=seed[i];
}
fclose(f1);
}
//*************************************************

void updatefile(int amt,int c){
	FILE *new; FILE *f;
            new=fopen("acc.txt","a+");
            f=fopen("data.txt","r");
            for(n=0;n<16;n++){
                fscanf(f,"%d",&i);
                if(i==c){
			fprintf(new,"%d\n",i);
		        fprintf(new,"%d\n",amt);
			fscanf(f,"%d",&amt);
                }
                else{
                        fprintf(new,"%d\n",i);
                }
            }
            fclose(f);
            fclose(new);
            new=fopen("acc.txt","r");
            f=fopen("data.txt","w");
            for(n=0;n<16;n++){
                fscanf(new,"%d",&i);
                fprintf(f,"%d\n",i);
            }
            fclose(f);
            fclose(new);
            remove("acc.txt");
}

//**********************************************

int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024]={0}; 
    char *hello="PART 3 Completed";
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    valread = read( new_socket , buffer, 1024);// got the cvv number
    
    //********* account part*****

    printf("%s\n",buffer ); // printing the cvv number
    int c;
    sscanf(buffer,"%d",&c);

// **************** here starts*****************
   
   system("pgrep -u gaurav firefox >> pid.txt");
   FILE *pid; int fpid,amt,cvvn,power,test;
   pid=fopen("pid.txt","a+");
   fscanf(pid,"%d",&fpid);
   FILE *f;
   f=fopen("data.txt","a+");
        for(n=0;;n++){
                fscanf(f,"%d",&i);
                cvvn=i;
                if(i==c){
                       amt= ext(f);
		       power=ext(f);
                        break;
                }
        }
        system("date +%s >> timestamp.txt");
        FILE *time; int tstamp;
        time=fopen("timestamp.txt","a+");
        fscanf(time,"%d",&tstamp);
        int first=fpid+cvvn*n+tstamp;
        int binarycon=first;
        int len=binary(binarycon);
	fclose(f);
	fclose(time);
	fclose(pid);

//**************************** Jaydeep Part *****************************
    
    int v,co,b[16]; char bf[256];
    int p[5]={19,21,23,27,25};
    int k,temp,a[10];
    for(k=0;k<len;k++){
        a[k]=bin[k]-'0'; // from str array to int array
    }
    for(v=0;v<(sizeof(p)/sizeof(p[0]));v++)
    {
        co=p[v]; // position from perm. table
        b[v]=a[co]; // new array form (permutated)
    }
    b[5]=1;      //START PADDING
    for(v=6;v<16;v++)
    {
        b[v]=0;
    }
    for(v=0;v<16;v++){
	bf[v]=b[v]+'0';
    }

//***************************Circular Shift*************************
for(v=0; v<8; v++)
 {
  if(v==7)
   bf[v]=bf[0];
  else
   bf[v]=bf[v+1];   
 }
 //Performing LS-1 on second half of temp
 for(v=8; v<16; v++)
 {
  if(v==15)
   bf[v]=bf[8];
  else
   bf[v]=bf[v+1];   
 }
//******************************************************************
       
   int fee; long binary_val,rem,decimal_val=0,base=1,otp;
   char buffer1[1024]={0},strf[1024]={0},dec_char[256];	
	FILE *new;
	hashf(power,bf);   // updating power variable
	f=fopen("data.txt","r");
	new=fopen("acc.txt","a+");
	for(n=0;n<16;n++){
                fscanf(f,"%d",&i);
                if(i==c){
                       fprintf(new,"%d\n",i);
		       fprintf(new,"%d\n",i);
                       fprintf(new,"%d\n",power-1);
                       fscanf(f,"%d",&power);
		       fscanf(f,"%d",&power);
                }
                else{
                        fprintf(new,"%d\n",i);
                }
            }
            fclose(f);
            fclose(new);
            new=fopen("acc.txt","r");
            f=fopen("data.txt","w");
            for(n=0;n<16;n++){
                fscanf(new,"%d",&i);
                fprintf(f,"%d\n",i);
            }
            fclose(f);
            fclose(new);
            remove("acc.txt");
	sscanf(binaryhex,"%ld",&otp);  // binary to decimal
	binary_val = otp;
    while (otp > 0)
    {
        rem = otp % 10;
        decimal_val = decimal_val + rem * base;
        otp = otp / 10 ;
        base = base * 2;
    }
	sprintf(dec_char,"%ld",decimal_val);
//********************************************************************    
    send(new_socket ,dec_char, strlen(dec_char),0);
    int valread1=read(new_socket,buffer1,1024);
    if(strcmp(dec_char,buffer1)==0){
	    printf("OTP Matched\n");
	    send(new_socket,hello,strlen(hello),0);
	    int valread2=read(new_socket,strf,1024);
	    sscanf(strf,"%d",&fee);
	    amt=amt-fee;
	    updatefile(amt,c);
    }
    else{
	    printf("OTP NOT MATCHED EXITING...");
	    exit(0);
    }
    return 0;
}
