/*
 * appHandEXIDatatypesDecoder.c
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */

# include "ErrorCodes.h"
# include "appHandEXIDatatypesDecoder.h"
# include "appHandEXIDatatypes.h"
# include "EXIHeaderDecoder.h"
# include "EXITypes.h"
# include "DecoderChannel.h"


/** event-code */
static uint32_t eventCode;
static int errn;
static uint32_t uint32;



/* Complex type name='urn:iso:15118:2:2010:AppProtocol,AppProtocolType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(ProtocolNamespace,VersionNumberMajor,VersionNumberMinor,SchemaID,Priority)',  derivedBy='RESTRICTION'.  */
static int decode_appHandAppProtocolType(bitstream_t* stream, struct appHandAppProtocolType* appHandAppProtocolType) {
	int grammarID = 0;
	int done = 0;

	while(!done) {
		switch(grammarID) {
		case 0:
			/* FirstStartTag[START_ELEMENT(ProtocolNamespace)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &appHandAppProtocolType->ProtocolNamespace.charactersLen);
							if (errn == 0) {
								errn =  (appHandAppProtocolType->ProtocolNamespace.charactersLen - 2) <= appHandAppProtocolType_ProtocolNamespace_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (appHandAppProtocolType->ProtocolNamespace.charactersLen >= 2) {
									appHandAppProtocolType->ProtocolNamespace.charactersLen = (uint16_t)(appHandAppProtocolType->ProtocolNamespace.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, appHandAppProtocolType->ProtocolNamespace.charactersLen, appHandAppProtocolType->ProtocolNamespace.characters);
								} else {
									/* string table hit */
									errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
								}
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT(ProtocolNamespace) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 1;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 1:
			/* Element[START_ELEMENT(VersionNumberMajor)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger32(stream, &appHandAppProtocolType->VersionNumberMajor);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT(VersionNumberMajor) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 2;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 2:
			/* Element[START_ELEMENT(VersionNumberMinor)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger32(stream, &appHandAppProtocolType->VersionNumberMinor);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT(VersionNumberMinor) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 3;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 3:
			/* Element[START_ELEMENT(SchemaID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 8, &(uint32));
							appHandAppProtocolType->SchemaID = (uint8_t)(uint32 + 0);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT(SchemaID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 4;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 4:
			/* Element[START_ELEMENT(Priority)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &(uint32));
							appHandAppProtocolType->Priority = (uint8_t)(uint32 + 1);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT(Priority) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2010:AppProtocol,#AnonType_supportedAppProtocolReq',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(AppProtocol{1-20})',  derivedBy='RESTRICTION'.  */
static int decode_appHandAnonType_supportedAppProtocolReq(bitstream_t* stream, struct appHandAnonType_supportedAppProtocolReq* appHandAnonType_supportedAppProtocolReq) {
	int grammarID = 7;
	int done = 0;

	appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 7:
			/* FirstStartTag[START_ELEMENT(AppProtocol)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 8;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 8:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 9;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 9:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 10;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 10:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 11;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 11:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 12;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 12:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 13;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 13:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 14;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 14:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 15;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 15:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 16;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 16:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 17;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 17:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 18;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 18:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 19;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 19:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 20;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 20:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 21;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 21:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 22;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 22:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 23;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 23:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 24;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 24:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 25;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 25:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 26;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 26:
			/* Element[START_ELEMENT(AppProtocol), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen < appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE) {
						errn = decode_appHandAppProtocolType(stream, &appHandAnonType_supportedAppProtocolReq->AppProtocol.array[appHandAnonType_supportedAppProtocolReq->AppProtocol.arrayLen++]);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 5;
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2010:AppProtocol,#AnonType_supportedAppProtocolRes',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(ResponseCode,SchemaID{0-1})',  derivedBy='RESTRICTION'.  */
static int decode_appHandAnonType_supportedAppProtocolRes(bitstream_t* stream, struct appHandAnonType_supportedAppProtocolRes* appHandAnonType_supportedAppProtocolRes) {
	int grammarID = 27;
	int done = 0;

	appHandAnonType_supportedAppProtocolRes->SchemaID_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 27:
			/* FirstStartTag[START_ELEMENT(ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							appHandAnonType_supportedAppProtocolRes->ResponseCode = (appHandresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT(ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 28;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 28:
			/* Element[START_ELEMENT(SchemaID), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 8, &(uint32));
							appHandAnonType_supportedAppProtocolRes->SchemaID = (uint8_t)(uint32 + 0);
							appHandAnonType_supportedAppProtocolRes->SchemaID_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT(SchemaID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 6;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

int decode_appHandExiDocument(bitstream_t* stream, struct appHandEXIDocument* exiDoc) {
	errn = readEXIHeader(stream);



	if(errn == 0) {
		/* DocContent[START_ELEMENT({urn:iso:15118:2:2010:AppProtocol}supportedAppProtocolReq), START_ELEMENT({urn:iso:15118:2:2010:AppProtocol}supportedAppProtocolRes), START_ELEMENT_GENERIC] */
		exiDoc->supportedAppProtocolReq_isUsed = 0u;
		exiDoc->supportedAppProtocolRes_isUsed = 0u;

		errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
		if(errn == 0) {
			switch(eventCode) {
			case 0:
				/* START_ELEMENT({urn:iso:15118:2:2010:AppProtocol}supportedAppProtocolReq) */
				errn = decode_appHandAnonType_supportedAppProtocolReq(stream, &exiDoc->supportedAppProtocolReq);
				exiDoc->supportedAppProtocolReq_isUsed = 1u;
				break;
			case 1:
				/* START_ELEMENT({urn:iso:15118:2:2010:AppProtocol}supportedAppProtocolRes) */
				errn = decode_appHandAnonType_supportedAppProtocolRes(stream, &exiDoc->supportedAppProtocolRes);
				exiDoc->supportedAppProtocolRes_isUsed = 1u;
				break;
			default:
				errn = EXI_ERROR_UNEXPECTED_EVENT_LEVEL1;
				break;
			}
		}

	}

	return errn;
}
