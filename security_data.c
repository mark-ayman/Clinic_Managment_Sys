#include <stdlib.h>
#include <stdio.h>
//#include"reservation_data.h"

#include"security_data.h"

typedef unsigned char                    u8 ;
typedef signed char                     s8 ;
typedef unsigned short int               u16 ;
typedef unsigned long int                u32 ;
typedef unsigned long long int           u64 ;

u8 secur_Init(){

    u16 pass=1234;
	u8 local_ReturnedVal=0;
	u16 local_pass;
	u8 counter;

	for(counter=0;counter<max;counter++){
		printf("Please Enter Admin Password : ");
		scanf(" %d",&local_pass);
		if((local_pass) == (1234)){
			printf("....Welcome MR.ADMIN.....");
			local_ReturnedVal=1;
			break;
		}
		else{
			printf("..Wrong Password.Try Again..\n");
		}
	}
	return local_ReturnedVal;
}
