#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 
#include "server_api.h"
#include "gpio.h"





int main(int argc, char *argv[])
{
int port_num, sockfd, connfd;
char buf[1000];
int n;

  if(argc != 2) {
	fprintf(stderr, "Usage: %s <port_num>\n", argv[0]);
	exit(1);
  }

  port_num = atoi(argv[1]);
  if(port_num < 2048) {
	fprintf(stderr, "Invalid port number: %d\n", port_num);
	exit(1);
  }

  setup_io();
  setgpiofunc(7, 0);

  sockfd = setup_server_socket(port_num);
  connfd = accept_client_connection(sockfd);

while(1){
  n = read_from_gpio(7);
  
  if(n == 0) write(connfd, "0", 2);
  else write(connfd, "1", 2);
  usleep(100000);
}

  close(connfd);
}
