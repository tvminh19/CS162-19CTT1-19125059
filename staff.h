#ifndef _STAFF_H_
#define _STAFF_H_

//5.1 View attendance list
void viewAttendance();
void cleanScoreBoard(Node*& phead);
void askNumAndShow(Node* phead, Date root, Time Stime, Time Etime, int numStu);
void showAttendanceList(int numOfWeek, Node* phead, Date root, Time Stime, Time Etime, int numStu);
int numOfWeek();
void loadCourseFile(char fileAdd[], Node*& phead, Date& root, Time& Stime, Time& Etime, int& numStu);
void getNodeScoreBoard(ifstream& in, Node*& phead, Node*& pcur);
char* courseDir(char year[], char semester[], char className[], char course[]);
void askCourse(Node*& phead, char a[]);

//5.1 export attendance list to csv file
void exportAttLs();
void createExportFile(char fileAdd[], Node* phead, int numStu);

#endif // !_STAFF_H_








