#include<stdio.h>
#include <stdlib.h>


#include"patient_data.h"
#include"reservation_data.h"
extern List * Mylist;
extern patient * Mypatient;

typedef unsigned char                    u8 ;
typedef signed char                     s8 ;
typedef unsigned short int               u16 ;

 u8 Slot_Name[5][25]={{"2pm to 2:30pm"},{"2:30pm to 3pm"},{" 3pm to 3:30pm"},{" 4pm to 4:30pm"},{"4:30pm to 5:00"}};


extern u8 slots_arr[NO_SLOTS];//carry status of slot and index is time of slot as its arranging
extern  u32 patient_slots_arr[NO_SLOTS];//carry patient ID

void slots_Display(/*u8 *slots_arr,u16 *patient_slots_arr*/){
    u8 counter=0;
    u8 choice_Reserve;
    u8 slot_index;
    u8 m=0;
    for(counter=0;counter<NO_SLOTS;counter++){
        if(slots_arr[counter]==0){
                m=0;
         while(m!=24){
            printf("%c",Slot_Name[counter][m]);
            m++;
            }
            printf("\n");
        }
    }
    printf("Press 'R' if U want to Reserve 'Q' if U want to Quit :");
    scanf(" %c",&choice_Reserve);
    if(choice_Reserve=='R'){
      while(1){
        printf("Enter index of slot U want to Reserve :");
        scanf("%d",&slot_index);
        if(!index_u8slotFound(slot_index)){
        slots_Reserve(Mylist,/*slots_arr,patient_slots_arr,*/slot_index);
        break;
        }
        else{
            printf("Please ,Re-Enter index that entered already exist ");
        }
      }
    }
    else if(choice_Reserve=='Q') {

    }
    else{
        printf("Wrong Choice . IT Will Quit !");
    }
}

void slots_Reserve(List * Clinic_List,/*u8 *slots_arr1,u32 *patient_slots_arr1,*/u8 slot_index){
    u16 local_patientID;
    u8 counter;
    printf("Enter ID  of patient want to Reserve slot : ");
    scanf(" %d",&local_patientID);

    patient* current_patient=(patient*)malloc(sizeof(patient));
    current_patient=Clinic_List->head;
    while(current_patient->ID!=local_patientID){
        current_patient=current_patient->next;
    }
    //condition of index btn no of slots
    //check if index of null in array
    slots_arr[slot_index]=1;
    patient_slots_arr[slot_index]=local_patientID;
}

u8 index_u8slotFound(u8 slot_index){
    u8 flag=0;
    for(u8 i=0;i<NO_SLOTS;i++){
        if(i==slot_index){
            if(slots_arr[i]==1){
               flag=1;
            }
        }
    }
    return flag;
}

void slots_CancelReserve(List * Clinic_List,u16 local_patientID){
    u8 counter ;
    patient* current_patient=(patient*)malloc(sizeof(patient));
    current_patient=Clinic_List->head;
    while(current_patient->ID!=local_patientID){
        current_patient=current_patient->next;
    }
    for(counter=0;counter <NO_SLOTS;counter++){
        if(patient_slots_arr[counter]==local_patientID){
            slots_arr[counter]=0;
            break;
        }
    }
}

void slots_Display_PatientSlots(){
    u8 counter=0;
    u8 m=0;
    for(counter=0;counter<NO_SLOTS;counter++){
        if(slots_arr[counter]==0){
                m=0;
         while(m!=24){
            printf("%c",Slot_Name[counter][m]);
            m++;
            }
            printf("%d",patient_slots_arr[counter]);
            printf("\n");
        }
    }
}
