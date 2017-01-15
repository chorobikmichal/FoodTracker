#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "parsing.h"

/*
*Michal Chorobik 0937145
*CIS 2500
*mchorobi@uofguelph.mail.ca
*April 3, 2016
*/

int main(int argc, char *argv[]){

	Food * head = NULL;
	//Food * curr = NULL;
	//Food * last = NULL;

	FILE * dataFile;
	dataFile = fopen(argv[1],"r");

	//createRecord is called through this function once for every linein the file So multiple times
	head = fileParsing(dataFile);

	printf("%d\n",totalCal(head));
	average(head);
	printf("%d\n",listLength(head));
	itemPrint(head);

	destroyList(head);


	//head=removeFromFront(head);
	//printf("\n%s\n",head->name);
	//printf("%s", printRecord(head));	  
	//last = removeFromBack(head);
	//printf("%s", printRecord(last));	  

	//getFirstItem(record);

	return 0;

}