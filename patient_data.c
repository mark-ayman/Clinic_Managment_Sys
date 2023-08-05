#include <stdio.h>
#include <stdlib.h>
#include"patient_data.h"


typedef unsigned char                    u8 ;
typedef signed char                     s8 ;
typedef unsigned short int               u16 ;

void patient_voidInit	(List * Clinic_List){
	Clinic_List->head=NULL;
}

void patient_voidAdd(List * Clinic_List){

    patient* prev_patient;
	patient* new_patient=(patient*)malloc(sizeof(patient));     //create new node of data

	if (!patientList_IsEmpty(Clinic_List)){
        prev_patient=Clinic_List->head;
        patient* next_patient=prev_patient->next;
		//ADD Element at last of last
		while(next_patient!=NULL){
			next_patient=next_patient->next;
		}
        next_patient=new_patient;
		new_patient->next=NULL;
		//create data of Element
		//First Enter ID for check its Existance
        // patient_voidCreateData(new_patient);
       // patient_voidEnterID(new_patient);
       	u16 local_ID;
        printf("Please Enter Patient ID : ");
        scanf(" %d",&(local_ID));
        new_patient->ID=local_ID;
		//search ID if Exist
		while(1){
			if((patient_u8SearchID(Clinic_List,new_patient->ID))){
			// One for Found
			printf("This ID is Exist , Please Enter another One .\n");
			patient_voidEnterID(new_patient);
			}
			else{
			// Zero for Not Found
			printf("This ID is NOT Exist , Please Enter Rest Data of OUR Patient .\n");
			break;
			}
		}
		//Complete Enter Data of patient
		patient_voidCreateData(new_patient);
		//view all list
		patient_voidViewAll(Clinic_List);

	}
	else{
        //ADD First Element Patient Data
        Clinic_List->head=new_patient;
                                                //make node address (Zero) carry address of new node
		new_patient->next=NULL;                 //make next of new first node point to null
		//Enter ID of Patient
		//patient_voidEnterID(new_patient);     //send new patient to enter ID
		//create data of Element               //dangling pointer Y/N?
		patient_voidCreateData(new_patient);   //send new patient to enter Data
		//view all list
		patient_voidViewAll(Clinic_List);  //send new patient to view data
	}
}

u8 patient_voidEdit(List * Clinic_List,u8 local_u8IDpatient){
	u8 local_returnedval;
	patient * current_patient=Clinic_List->head;
	patient * next_patient=current_patient->next;
	while(1){
		if(current_patient->next!=NULL){
			if(current_patient->ID==local_u8IDpatient){
				local_returnedval=0;
				patient_voidEditPatientName	 (current_patient);
				patient_voidEditPatientage	 (current_patient);
				patient_voidEditPatientGender(current_patient);
				patient_voidEditPatientID	 (current_patient);
				while((patient_u8SearchID(Clinic_List,current_patient->ID))){
					printf("Error \nThis already Exist ID \nPlease Re-Enter ID");
					patient_voidEditPatientID	 (current_patient);
				}
			}
			else{
				current_patient=next_patient;
				next_patient=current_patient->next;
			}
		}
		else{
			local_returnedval=0;
			printf("Not Exist ID please Enter Right ID \n");
			break;
		}
	}
	return local_returnedval;
}

void patient_voidView(List * Clinic_List,u8 local_u8IDpatient){
	patient* current_patient=Clinic_List->head;
	patient* next_patient=current_patient->next;
	/*
	patient* next_patient;
	current_patient->next=next_patient;
	*/
	while(1){
		if(current_patient->ID==local_u8IDpatient){
			patient_voidprintData (current_patient);
		}
		else{
			current_patient=next_patient;
			next_patient=current_patient->next;
		}
	}

}

/*
void patient_voidDelete(List * Clinic_List,u8 local_u8IDpatient){

}
*/

u8 patientList_IsEmpty(List * Clinic_List){
	u8 local_u8ReturnedVal=0;
	if(Clinic_List->head==NULL){
		local_u8ReturnedVal=1;
	}
	return local_u8ReturnedVal;
}

u8 patientList_GetSize(List * Clinic_List){
	u8 counter = 0;
	patient * current_patient=Clinic_List->head;
	while(current_patient!=NULL){
		current_patient=current_patient->next;
		counter++;
	}
	return  counter;
}

void patient_voidViewAll(List * Clinic_List){

	patient * current_patient=Clinic_List->head;
	patient * next_patient;
	//next_patient=current_patient->next;
	while(1){
		if(current_patient!=NULL){
			patient_voidprintData (current_patient);
			next_patient=current_patient->next;
			current_patient=next_patient;
			//next_patient=current_patient->next;
		}
		else{
            printf("No Patient Record Founded Rest.\n ");
			break;
		}
	}
}

void patient_voidCreateData(patient * patient_pointer){
    u8 name[20];
    u8 age;
    u8 gender_type;
    u8 i =0;
    //ID
    u16 local_ID;
	printf("Please Enter Patient ID : ");
	scanf(" %d",&(local_ID));
	patient_pointer->ID=local_ID;
	//Enter Name
	printf("\nEnter Patient Name : ");
	scanf(" %s",&name);
	while(name[i]!='\0'){
     patient_pointer->name[i]=name[i];
     i++;
	}
	//Enetr age
	printf("\nEnter Patient age :");
	scanf(" %d",&age);
	patient_pointer->age=age;
	//Enter Gender
	printf("\nEnter Patient Gender (M/F) :");
	scanf(" %c",&gender_type);
	patient_pointer->gender=gender_type;
}

u8 patient_u8SearchID(List * Clinic_List,u16 copy_u8PatientID){

	u8 local_u8ReturnedFlag=0;
	patient* current_patient=Clinic_List->head;
	patient* next_patient;
	/*patient* next_patient=current_patient->next;*/
	while(1){
		if((current_patient->ID)!=(copy_u8PatientID)){
		next_patient=current_patient;
		current_patient=next_patient->next;
		}
		else{
			local_u8ReturnedFlag=1;
			break;
		}
	}

	return local_u8ReturnedFlag;
}

void patient_voidEnterID(patient * patient_pointer){
	u16 local_ID;
	printf("Please Enter Patient ID : ");
	scanf(" %d",&(local_ID));
	patient_pointer->ID=local_ID;
}

void patient_voidprintData (patient * patient_pointer){
	u8 counter =0;
	printf("Patient ID is : %d \n", patient_pointer->ID);
	printf("Patient Name is :");
	while(patient_pointer->name[counter]!='\0'){
		printf("%c",patient_pointer->name[counter++]);
	}
	printf("\n");
	printf("Patient age is : %d \n",patient_pointer->age);
	printf("Patient Gender is :%c \n", patient_pointer->gender);
}

void patient_voidEditPatientName(patient * patient_pointer){
	printf("Enter Edited Name For Patient : ");
	scanf(" %s ",patient_pointer->name[20]);
}

void patient_voidEditPatientage(patient * patient_pointer){
	printf("Enter Edited age For Patient : ");
	scanf(" %d ",patient_pointer->age);
}

void patient_voidEditPatientGender(patient * patient_pointer){
	printf("Enter Edited Gender (M/F) For Patient : ");
	scanf(" %c ",patient_pointer->gender);
}

void patient_voidEditPatientID(patient * patient_pointer){
	printf("Enter Edited ID For Patient : ");
	scanf(" %d ",patient_pointer->ID);
}

