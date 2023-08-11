#ifndef RESERVATION_DATA_H
#define RESERVATION_DATA_H

#include"patient_data.h"

#define NO_SLOTS 5
typedef unsigned char                    u8 ;
typedef signed char                     s8 ;
typedef unsigned short int               u16 ;
typedef unsigned long int                u32 ;
typedef unsigned long long int           u64 ;

u8 index_u8slotFound(u8 slot_index);

void slots_Display(/*u8 *slots_arr*/);
void slots_Reserve(List * Clinic_List,/*u8 *slots_arr_ptr,u32 *patient_slots_arr_ptr,*/u8 slot_index);

void slots_CancelReserve(List * Clinic_List,u16 local_patientID);


#endif
