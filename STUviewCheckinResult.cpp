#include "header.h"
#include "courses.h"
#include "students.h"
#include "staff.h"

// view checkin result
void viewAttendance() {
	//set variable
	char year[20], semester[20], className[20];
	char fileAdd[500] = {};
	Node* phead = nullptr;
	Node* pcur = nullptr;
	Date root;
	Time Stime, Etime;

	//input year semester class course
	inputYSC(year, semester, className);

	//make file address
	makeClassAdd(year, semester, className, fileAdd);

	//load file
	loadCourseEdit(year, semester, className, fileAdd, phead, pcur);

	//show to edit
	print_Schedule(phead);

	//ask and edit
	char course[20] = {};
	askCourse(phead, course);

	//make dir to course
	strcpy(fileAdd, courseDir(year, semester, className, course));

	//clean heap memory
	cleanScheduleNode(phead);

	//open and load to struct
	int numStu;
	loadCourseFile(fileAdd, phead, root, Stime, Etime, numStu);

	//ask num of week and show attendance list
	askNumAndShow(phead, root, Stime, Etime, numStu);

	//clean heap memory
	cleanScoreBoard(phead);
}








