#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "parsing.h"

/*
*Michal Chorobik 0937145
*CIS 2500
*mchorobi@uofguelph.mail.ca
*April 3, 2016
*/

Food * fileParsing(FILE * dataFile) {

	Food * head = NULL;

	char name[50];
	char foodGroup[50];
	char caloriesStr[10];			//i add all the numbers scaned to the calories string and convert them into calories int
	char type;
	char line[256];

//help count from 0->end of that string
	int a;
	int b;
	int c;

//must declare them here cause u cant declare two variables in one for loop like for(int y=0,int z=0) is invalid!!
	int i;
	int x;
	int y;

	while (fgets(line, 256, dataFile) != NULL) {
		for(i=0;i<strlen(line);i++) {
			if(line[i]== ',') {
				for(a = 0;a<i;a++) {
					name[a]=line[a];
				}
				for(x = i+1, b=0;x<strlen(line);x++, b++) {
					foodGroup[b]=line[x];
					if(line[x]==',') {

						for(y = x+1, c=0 ;y<strlen(line);y++, c++) {
								caloriesStr[c]=line[y];
								if(line[y]==',') {
									type=line[y+1];
									break;
								}
						}
						break;
					}
				}	
				break;
			}
		}
				name[i] = '\0';				
				foodGroup[b]='\0';
				caloriesStr[c]='\0';

				int calories;
				calories=atoi(caloriesStr);
				if(calories<0){
					calories=0;
				}

				Food * record = NULL;
				record = createRecord(name, foodGroup, calories, type);

				
				if (record->type == 'h') {
							head = addToFront(head,record);
				} else if (record->type == 'j') {
							head = addToBack(head,record);
				}


//just prints out the calories in the order that the list is in and it motherfucking works bithches!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*	Food * temp = head;
	while(temp!=NULL){
		printf("%d",temp->calories);
		temp=temp->next;
	}
	printf("\n");
*/
				//destroyRecord(record);
				//Pass them here cause they will get overwritten if u dont
	}
				return(head);
}
int totalCal(Food * theList) {

	int calCount=0;

	if(theList!=NULL) {
		while(theList->next!=NULL) {
			calCount+=theList->calories;
			theList=theList->next;
		}
	calCount+=theList->calories;
	}

	return calCount;
}
int listLength(Food * theList) {

	int count=0;

	if(theList!=NULL) {
		while(theList->next!=NULL) {
			count++;
			theList=theList->next;
		}
	count++;
	}

	return count;
}
void itemPrint(Food * theList) {

	if(theList!=NULL) {
		while(theList->next!=NULL) {

			printf("%s\n",theList->name);
			printf("%s\n",theList->foodGroup);
			printf("%d\n",theList->calories);
			printf("%c\n",theList->type);

			theList=theList->next;
		}
			printf("%s\n",theList->name);
			printf("%s\n",theList->foodGroup);
			printf("%d\n",theList->calories);
			printf("%c\n",theList->type);
	}

}
void average (Food * theList){

	double vegfruit=0;
	double vegfruitCount=0;
	double meat=0;
	double meatCount=0;
	double dairy=0;
	double dairyCount=0;
	double grains=0;
	double grainsCount=0;
	double fat=0;
	double fatCount=0;

	if(theList!=NULL) {
		while(theList->next!=NULL) {
			if(strcmp(theList->foodGroup ,"vegfruit")==0) {
				vegfruit+=theList->calories;
				vegfruitCount++;

			} else if (strcmp(theList->foodGroup ,"meat")==0) {
				meat+=theList->calories;
				meatCount++;

			} else if (strcmp(theList->foodGroup ,"dairy")==0) {
				dairy+=theList->calories;
				dairyCount++;

			} else if (strcmp(theList->foodGroup ,"grains")==0) {
				grains+=theList->calories;
				grainsCount++;

			} else if (strcmp(theList->foodGroup ,"fat")==0) {
				fat+=theList->calories;
				fatCount++;

			}
			theList=theList->next;
		}
	}

	if(vegfruitCount!=0){
		printf("%0.2f\n",vegfruit/vegfruitCount);
	}else{
		printf("%0.2f\n",vegfruitCount);
	}

	if(meatCount!=0){
		printf("%0.2f\n",meat/meatCount);
	}else{
		printf("%0.2f\n",meatCount);
	}

	if(dairyCount!=0){
		printf("%0.2f\n",dairy/dairyCount);
	}else{
		printf("%0.2f\n",dairyCount);
	}

	if(grainsCount!=0){
		printf("%0.2f\n",grains/grainsCount);
	}else{
		printf("%0.2f\n",grainsCount);
	}

	if(fatCount!=0){
		printf("%0.2f\n",fat/fatCount);
	}else{
		printf("%0.2f\n",fatCount);
	}

}