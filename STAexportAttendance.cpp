#include "header.h"
#include "staff.h"
#include "courses.h"

//ask where to keep the file
void fileKeep(char a[]){
    cout << "Where do you want to keep the file? \n";
    cout << "(include file's name): ";
    cin.ignore(500, '\n');
    cin.get(a, 500, '\n');
}

//create csv file
void createExportFile(char fileAdd[], Node* phead, int numStu){
    //ask where do user keep the file
    char a[500] = {};
    fileKeep(a);

    //output
    ofstream out(a);
    out << "No,Full Name,";
    for (int i = 0; i < 9; ++i){
        out << "Week " << i + 1 << ",";
    }
    out << "Week 10\n";
    for (int i = 0; i < numStu; ++i){
        out << i + 1 << ",";
        out << phead->scb->stu->name << ",";
        for (int j = 0; j < 9; ++j){
            out << phead->scb->went2class[j] << ",";
        }
        out << phead->scb->went2class[9] << "\n";
		phead = phead->next;
    }
    out.close();
}

//export attendance to csv file
void exportAttLs() {
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

	//creating...
	createExportFile(fileAdd, phead, numStu);

    //show done
    introDone();

	//clean heap memory
	cleanScoreBoard(phead);
}
