#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

/*
*Michal Chorobik 0937145
*CIS 2500
*mchorobi@uofguelph.mail.ca
*April 3, 2016
*/

Food * createRecord(char * name, char * group, int calories, char theType){

	Food * foodRecord = malloc(sizeof(Food));

	foodRecord->name=malloc((sizeof(char)*50) +1);
	strcpy(foodRecord->name,name);
	foodRecord->foodGroup=malloc((sizeof(char)*50) +1);
	strcpy(foodRecord->foodGroup,group);
	foodRecord->calories=calories;
	foodRecord->next=NULL;

	if ((theType == 'h') || (theType == 'j')) {
		foodRecord->type=theType;
	} else {
	return NULL;	
	}

	//destroyRecord(foodRecord); //why would u do that??

	return foodRecord;
}
char * printRecord(Food * toPrint){

	char * stingToPrint = malloc(sizeof(char) * 50);
	char cal[5];
	int i;
	int a;
	int b;
	int c=0;

	for(i=0;i<strlen(toPrint->name);i++) {
		stingToPrint[i]=toPrint->name[i];
	}
	stingToPrint[i]=' ';
	i++;
	stingToPrint[i]='(';
	i++;

	for(a=0;a<strlen(toPrint->foodGroup);a++) {
		stingToPrint[i+a]=toPrint->foodGroup[a];
	}
	stingToPrint[i+a]=')';
	a++;
	stingToPrint[i+a]=':';
	a++;

	sprintf(cal, "%d", toPrint->calories);

	for(b=0;b<strlen(cal);b++) {
		stingToPrint[i+a+b]=cal[b];
	}
	stingToPrint[i+a+b+c]='[';

	c++;
	stingToPrint[i+a+b+c]=toPrint->type;

	c++;
	stingToPrint[i+a+b+c]=']';

	c++;
	stingToPrint[i+a+b+c]='\0';
	

	return(stingToPrint);

}
void destroyRecord(Food * toDie){
	free(toDie);
}
Food * addToFront(Food * theList, Food * toBeAdded){
	
	if(theList!=NULL) {
		toBeAdded->next = theList;
		return toBeAdded;
	} else {
		theList=toBeAdded;
		theList->next=NULL;
		return theList;
	}

}
Food * addToBack(Food * theList, Food * toBeAdded){

	Food * temp = theList;

	if(temp!=NULL) {

	while(temp->next!=NULL) {
		temp=temp->next;
	}

		temp->next = toBeAdded;
		return theList;
	} else {
		theList = toBeAdded;
		theList->next=NULL;
		return theList;
	}

}
Food * removeFromFront(Food * theList){

	Food * temp = theList;

	temp=temp->next;
	destroyRecord(theList);

	return temp;

}
Food * removeFromBack(Food * theList){
	
	int noMore=0;
	Food * temp1=theList;
	Food * temp2=theList;

	if(temp1!=NULL) {

		while(temp1->next!=NULL) {

			if(noMore!=1)
				temp2=temp1;

			temp1=temp1->next;

			if(temp1->next==NULL) {
				noMore=1;
			}
		}

	}

	temp2->next=NULL;
	return temp2;

}
Food * getLastItem(Food * theList){

	Food * temp=theList;

	if(temp!=NULL) {

		while(temp->next!=NULL) {
			temp=temp->next;
		}
	}

		return temp;

}
Food * getFirstItem(Food * theList){

	return theList;
}
int isEmpty(Food * theList){
 
	if(theList==NULL) {
		return 1;
	} else {
		return 0;
	}

}
void printList(Food * theList){

	Food * temp = theList;

	while(temp != NULL) {
	printf("%s, %s, %d, %c\n", theList->name,theList->foodGroup,theList->calories,theList->type);	  
	temp = temp->next;
	}

	printf("\n");

}
void destroyList(Food * theList){

	Food * temp;

	while(theList->next!=NULL) {
		if(isEmpty(theList)==1) {
			printf("\nfuck\n");
			return;
		} else {
			temp=theList->next;
			destroyRecord(theList);
			theList=temp;
		}
	}
	destroyRecord(theList);


}