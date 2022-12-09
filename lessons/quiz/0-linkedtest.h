#ifndef MAIN_HEAD
#define MAIN_HEAD

#include <stdio.h>
#include <stdlib.h>

/** 
 * StudentData - struct of student data
 *
 * Description: this structure is used to handle data about each
 * candidate of the examination and is stored as data in the
 * 'Records' node
 */

struct StudentData
{
	char firstName[30];
	char lastName[30];
};


/**
 * ExamData - struct of examination data
 *
 * Description: this struct is used to handle data about examination
 * and is stored as data in the 'Records' node
 */

struct ExamData
{
	char examDate[30];
	int termNumber;
	char subject[30];
	int score;
};


/**
 * Records - struct of records
 *
 * Description: this struct combines data about students and
 * examination and store them. This struct is used to create
 * nodes for the linked list.
 */

struct Records
{
	struct StudentData studentData;
	struct ExamData examData;
	struct Records *next;
};

#endif /* MAIN_HEAD */
