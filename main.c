#include<stdio.h>
#include<stdlib.h>
#include"admin_mode.h"
#include"user_mode.h"
#include"security_data.h"
#include"patient_data.h"
#include"reservation_data.h"

/*
extern slot *Myslots;
extern table *Mytable;
*/

typedef unsigned char                    u8 ;
typedef signed char                     s8 ;
typedef unsigned short int               u16 ;
typedef unsigned long int                u32 ;
typedef unsigned long long int           u64 ;

patient MainPatient;
List MainList;
extern patient * Mypatient=&MainPatient;
extern List * Mylist=&MainList;

extern u8 slots_arr[NO_SLOTS]={0,0,0,0,0};//carry status of slot and index is time of slot as its arranging
extern u32 patient_slots_arr[NO_SLOTS]={0,0,0,0,0};//carry patient ID

int main(){

	u8 mode ;
	patient_voidInit(Mylist);
	//void create_Table_Reservation(table *Clinic_table);
    //void table_Init(table *Clinic_table);
	printf("....Welcome to Clinical Managment System....\n");
	while(1){
		printf("Please Enter Letter for Choosing Mode .\n ");
		printf("Please Enter Letter for Admin Mode  A .\n ");
		printf("Please Enter Letter for User  Mode  U .\n ");
		printf("Please Enter Letter for Mode : ");
		scanf(" %c",&mode);
		switch(mode){
			case 'A' :
					if(!secur_Init()){
                        printf("You tried 3 times.System is Closed");
						goto Exit;
					}
					//call admin mode
					admin_Voidmode();
					break;
			case 'U' :
					//call user mode
					user_Voidmode();
					break;
		}
	}
	Exit:
	return 0;
}
