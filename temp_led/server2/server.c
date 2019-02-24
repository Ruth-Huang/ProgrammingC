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
#include "i2c_api.h"
#include "MPU9255.h"

float getTemperature(int fd)
{
        u8 byte1 = read_byte(fd, DEVICE_ADDRESS, TEMPERATURE_DATA_REG);
        u8 byte2 = read_byte(fd, DEVICE_ADDRESS, TEMPERATURE_DATA_REG + 1);

        if(byte1 < 0 || byte2 < 0)
        {
                printf("error reading temperature.\n");
                exit(1);
        }

        short result = (byte1 << 8) | byte2;

        return ((float) result - 21.0) / 333.87 + 21.0;
}


int main(int argc, char *argv[])
{
int port_num, sockfd, connfd, n, fd;
float temperature;
//char buf[100];
  if(argc != 2) {
	fprintf(stderr, "Usage: %s <port_num>\n", argv[0]);
	exit(1);
  }

  port_num = atoi(argv[1]);
  if(port_num < 2048) {
	fprintf(stderr, "Invalid port number: %d\n", port_num);
	exit(1);
  }
  fd = open_i2c();
  setup_io();
  setgpiofunc(7, 0);
  sockfd = setup_server_socket(port_num);
  connfd = accept_client_connection(sockfd);

/*while(1){
  fgets(buf, 100, stdin);
  write(connfd, &buf, 99);
  sleep(1);
}*/

/*  while(1){
  n = read_from_gpio(7);
  if(n == 0){
    write(connfd, "1", 2);
  }else {
    write(connfd, "0", 2);
   }
  usleep(100000);
  }*/

while(1){
  temperature = getTemperature(fd);

  n = temperature;
  if(n > 30){
    write(connfd, "1", 2);
  }else{
    write(connfd, "0", 2);
  }
  printf("The temperature is %f degrees.\n", temperature);
  usleep(100000);

  }

  close(connfd);
}
