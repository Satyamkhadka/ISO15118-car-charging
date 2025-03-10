/*
 * v2gtp.c
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */

#include <stdio.h>
# include <netinet/in.h>
#include "v2gtp.h"


int write_v2gtpHeader(uint8_t* outStream, uint16_t outStreamLength, uint16_t payloadType)
{

	/* write v2gtp version number 1=byte */
	outStream[0]=V2GTP_VERSION;

	/* write inverse v2gtp version */
	outStream[1]=V2GTP_VERSION_INV;


	/* write payload type */
	outStream[3] = (uint8_t)(payloadType & 0xFF);
	outStream[2] = (uint8_t)(payloadType >> 8 & 0xFF);

	/* write payload length */
	outStream[7] = (uint8_t)(outStreamLength & 0xFF);
	outStream[6] = (uint8_t)(outStreamLength>>8 & 0xFF);
	outStream[5] = (uint8_t) 0; /* uint16 only, no need for (outStreamLength>>16 & 0xFF); */
	outStream[4] = (uint8_t) 0; /* uint16 only, no need for (outStreamLength>>24 & 0xFF); */

	/* here, the outStream length have to be resized by the v2gtp offset*/
	/**outStreamLength += V2GTP_HEADER_LENGTH;*/

	return 0;
}

int read_v2gtpHeader(uint8_t* inStream, uint16_t* payloadLength)
{
	uint16_t payloadType=0;


	/* check, if we support this v2gtp version */
	if(inStream[0]!=V2GTP_VERSION || inStream[1]!=V2GTP_VERSION_INV)
		return -1;


	/* check, if we support this payload type*/
	payloadType = inStream[2];
	payloadType = (payloadType << 8 | inStream[3]);

	if(payloadType != V2GTP_EXI_TYPE)
		return -1;


	/* determine payload length*/
	*payloadLength = inStream[4];
	*payloadLength = (*payloadLength << 8 | inStream[5]);
	*payloadLength = (*payloadLength << 8 | inStream[6]);
	*payloadLength = (*payloadLength << 8 | inStream[7]);

	/* if((*payloadLength+V2GTP_HEADER_LENGTH)!=inStreamLength)
		return -1; */

	return 0;
}


