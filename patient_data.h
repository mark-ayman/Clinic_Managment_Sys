#ifndef PATIENT_DATA_H_INCLUDED
#define PATIENT_DATA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char                     u8 ;
typedef signed char                     s8 ;
typedef unsigned short int               u16 ;
typedef unsigned long int                u32 ;
typedef unsigned long long int           u64 ;

typedef enum gender {
	male=0,
	female=1
}gender;

typedef struct patientData{
		u8 name[20];
		u16 ID;
		u8 age;
		//gender patient_gender ;
		u8 gender;
		struct patientData* next;
}patient;

typedef struct listData{
	patient* head;
}List;


void patient_voidInit	(List * Clinic_List );						//Done
void patient_voidAdd	(List * Clinic_List);						//Done
u8 patient_voidEdit	(List * Clinic_List,u16 local_u8IDpatient);		//Done
void patient_voidView	(List * Clinic_List,u16 local_u8IDpatient);	//Done
//void patient_voidDelete	(List * Clinic_List,u8 local_u8IDpatient);
u8 patientList_IsEmpty	(List * Clinic_List);						//Done
u8 patientList_GetSize	(List * Clinic_List);						//Done
void patient_voidViewAll(List * Clinic_List);						//Done
void patient_voidCreateData(patient * patient_pointer); 			//Done
u8 patient_u8SearchID	(List * Clinic_List,u16 local_u8IDpatient);	//Done
void patient_voidEnterID(patient * patient_pointer);				//Done
void patient_voidprintData (patient * patient_pointer);				//Done



#endif // PATIENT_DATA_H_INCLUDED
