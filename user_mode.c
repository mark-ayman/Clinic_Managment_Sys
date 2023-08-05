#include<stdio.h>
#include<stdlib.h>
#include"patient_data.h"
//#include"reservation_data.h"

extern patient * Mypatient;
extern List * Mylist;

typedef unsigned char                    u8 ;
typedef signed char                     s8 ;
typedef unsigned short int               u16 ;
typedef unsigned long int                u32 ;
typedef unsigned long long int           u64 ;

void user_Voidmode(){

	u8 local_u8UserCategry ;
	u8 local_u8IDpatient;
	printf("....Welcome to Clinical User Interface System User page....\n");
	while(1){
		printf("Please Enter Letter for Choosing Mode.\n ");
		printf("V Please Enter Letter for View Patient Record.\n ");
		printf("R Please Enter Letter for Reservation today.\n ");
		printf("Q Please Enter Letter for Quit User Mode.\n ");
		printf("Please Enter Letter for Category :\n ");
		scanf(" %c",&local_u8UserCategry);
		switch(local_u8UserCategry){
			case 'V' :
					printf("Plrease Enter ID of patient want to View his Data : ");
					scanf(" %d",&local_u8IDpatient);
					//patient_voidView(Mylist,local_u8IDpatient);
					break;
			case 'R' :
					//display reservation today
					break;
			default:
                    printf("Wrong Choice.\n");
		}
		if(local_u8UserCategry=='Q'){
		   break;
		}
	}
	return 0;
}
