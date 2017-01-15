#ifndef __PARSING_H__
#define __PARSING_H__

/*
*Michal Chorobik 0937145
*CIS 2500
*mchorobi@uofguelph.mail.ca
*April 3, 2016
*/

Food * fileParsing(FILE * dataFile);
int totalCal(Food * theList);
int listLength(Food * theList);
void itemPrint(Food * theList);
void average (Food * theList);

#endif
