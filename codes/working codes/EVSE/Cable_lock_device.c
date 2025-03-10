/*
 * Cable_lock_device.c
 *
 *  Created on	: 31.03.2016
 *      Author	: melanie
 * 	Edited by 	: Jiztom Francis
 *  Modified on : 08.02.2017
 */

# include "hardware.h"
# include <stdio.h>
# include "interface.h"
# include "EVSE_main.h"
# include "transfer.h"
# include "ISO_EVSE_main.h"

#define UNLOCK 0
#define LOCK 1
#define CHECK 2

char data[6];
	char result[6];

static void Change_cable(int fd, int state){

	data[0]=0x02;
	data[1]=0x04;
	data[2]=0x00;
	data[3]=0x17;
	data[4] = state;	//query
	data[5]=build_checksum(data,5);
	uart_send_data(fd,data,6);
	read(fd,result,6);
}
int Lock_Cable(int fd){

	int errn = -1;

# if CODE_EXAMPLE == CODE_EXAMPLE_HARDWARE
		Change_cable(fd, LOCK);
		if (result[4] == LOCK){
			if((result[0]==0x02)&& ((result[3] == 0x97)|(result[3] == 0x98)))
			{
				printf("Lock Status %x\n",(result[4]));
				errn = 1;
			}
		sendd(sockfd , CABLE_LOCK);
		////////---------->>>>>>>event CABLE_LOCK
		}

# else

		errn =1;
# endif

		return (errn);
}

int Unlock_Cable(int fd){
	int errn =-1;
# if CODE_EXAMPLE == CODE_EXAMPLE_HARDWARE
		Change_cable(fd, UNLOCK);
		if (result[4] == UNLOCK){
			if((result[0]==0x02)&& ((result[3] == 0x97)|(result[3] == 0x98)))
			{
				printf("Lock Status %x\n",(result[4]));
				sendd(sockfd , CABLE_UN_LOCK);
				errn = 1;
			}
		
		/////------------->>>>>>>>event CABLE_UNLOCK
		}

# else

		errn =1;
# endif

		return (errn);
}
