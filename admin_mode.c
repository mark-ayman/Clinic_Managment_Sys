#include<stdio.h>
#include<stdlib.h>
#include"patient_data.h"
//#include"reservation_data.h"

extern patient * Mypatient;
extern List * Mylist;
/*
extern slot *Myslots;
extern table *Mytable;
*/
typedef unsigned char                    u8 ;
typedef signed char                     s8 ;
typedef unsigned short int               u16 ;
typedef unsigned long int                u32 ;
typedef unsigned long long int           u64 ;

void admin_Voidmode(){

    u8 local_u8AdminCategry ;
	u8 local_u8IDpatient;
	printf("....Welcome to Clinical Managment System Admin page....\n");
	while(1){
		printf("Please Enter Letter for Choosing Mode.\n ");
		printf("A Please Enter Letter for Add New Patient.\n ");
		printf("E Please Enter Letter for User  Mode.\n ");
		printf("D Please Enter Letter for Display Reservation Slots.\n ");
		printf("C Please Enter Letter for Cancel Reservation Slot.\n ");
		printf("Q Please Enter Letter for Quit Admin Mode.\n ");
		printf("Please Enter Letter for Category :\n ");
		scanf(" %c",&local_u8AdminCategry);
		switch(local_u8AdminCategry){
			case 'A' :
					patient_voidAdd(Mylist);
					break;
			case 'E' :
					printf("Plrease Enter ID of patient want to Edit his Data : ");
					scanf(" %d",&local_u8IDpatient);
					patient_voidEdit(Mylist,local_u8IDpatient);
					break;
			case 'D' :
					//slots_Display(Mytable);
					break;
			case 'C' :
					printf("Plrease Enter ID of patient want to Cancel his Reservation: ");
					scanf(" %d",&local_u8IDpatient);
					//patient_voidEdit(Mylist,local_u8IDpatient);
					break;
			default: printf("Wrong Choice.\n");
		}
		if(local_u8AdminCategry=='Q'){
		   break;
		}
	}
	return 0;
}
