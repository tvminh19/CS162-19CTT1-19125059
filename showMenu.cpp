/* -------------------- this is Vu's file for functions ------------------- */
#include "header.h"
#include "class.h"
#include "courses.h"
#include "students.h"
#include "lecturer.h"
#include "score.h"
#include "AllRoles.h"
#include "staff.h"

//W01----------------------------------------------------------------------------------------------------

void notCorrect()
{
	system("cls");
	cout << "ALERT" << endl;
	cout << "       Your choice is not correct!" << endl;
	cout << "       Please input again!" << endl;
	Sleep(2000);
	system("cls");
}

void menuStudent(char ID[])
{
	system("cls");
	string s;
	cout << "--------------- MENU ---------------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. Check-in." << endl;
	cout << "[2]. View check-in result." << endl;
	cout << "[3]. View schedule." << endl;
	cout << "[4]. View your scores of a coure." << endl << endl;
	cout << "Input your choice (0-4) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		char a[100];
		displayAllroles(1, a);
	}

	else if (strcmp(c, "1") == 0) {
		//7.1
		StuCheckin(ID);
	}

	else if (strcmp(c, "2") == 0) {
		//7.2
		StuViewCheckin(ID);
	}

	else if (strcmp(c, "3") == 0) {
		//7.3
		StuViewCheckin();
	}

	else if (strcmp(c, "4") == 0) {
		//7.4
		view_result(ID);
	}

	else {
		notCorrect();
	}
	menuStudent(ID);
	delete[] c;
}

void menuLecturer()
{
	system("cls");
	string s;

	cout << "----------------------- MENU -----------------------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. View list of courses in the current semester." << endl;
	cout << "[2]. View list of students of a course." << endl;
	cout << "[3]. View attendance list of a course." << endl;
	cout << "[4]. Edit an attendance." << endl;
	cout << "[5]. Import scoreboard of a course from a csv file." << endl;
	cout << "[6]. Edit grade of a student." << endl;
	cout << "[7]. View a scoreboard." << endl << endl;
	cout << "Input your choice (0-7) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		char a[100];
		displayAllroles(2, a);
	}

	else if (strcmp(c, "1") == 0) {
		//6.1
		view_Courses();
	}

	else if (strcmp(c, "2") == 0) {
		//6.2
		void view_Student();
	}

	else if (strcmp(c, "3") == 0) {
		//6.3
		viewAttendance();
	}

	else if (strcmp(c, "4") == 0) {
		//6.4
	}

	else if (strcmp(c, "5") == 0) {
		//6.5
		import_scoreboard();
	}

	else if (strcmp(c, "6") == 0) {
		//6.6
		edit_grade();
	}

	else if (strcmp(c, "7") == 0) {
		//6.7
		view_scoreboard();
	}

	else {
		notCorrect();
	}
	menuLecturer();
	delete[] c;
}

//-----------------------------------------------------------------------------------------

void Staff_class()
{
	system("cls");
	string s;

	cout << "------------- Academic Staff-class -------------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. Import students of a class from a csv file." << endl;
	cout << "[2]. Manually add a new student to a class." << endl;
	cout << "[3]. Edit an existing student." << endl;
	cout << "[4]. Remove a student." << endl;
	cout << "[5]. Change students from class A to class B." << endl;
	cout << "[6]. View list of classes." << endl;
	cout << "[7]. View list of students in a class." << endl << endl;
	cout << "Input your choice (0-7) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		menuStaffRole();
	}

	else if (strcmp(c, "1") == 0) {
		//2.1
		importAndSave();
	}

	else if (strcmp(c, "2") == 0) {
		//2.2
		addNewStudent();
	}

	else if (strcmp(c, "3") == 0) {
		//2.3
		editStudent();
	}

	else if (strcmp(c, "4") == 0) {
		//2.4
		removeStudent();
	}

	else if (strcmp(c, "5") == 0) {
		//2.5
		changeStudentClass();
	}

	else if (strcmp(c, "6") == 0) {
		//2.6
		displayClassList();
	}

	else if (strcmp(c, "7") == 0) {
		//2.7
		displayStudentsInClass();
	}

	else {
		notCorrect();
	}
	Staff_class();
	delete[] c;
}

void Staff_course()
{
	system("cls");
	string s;

	cout << "------------------------------ Academic Staff-course ------------------------------" << endl;
	cout << "[0].  Back" << endl;
	cout << "[1].  Create / Delete / View academic years (2019-2020) and semesters." << endl;
	cout << "[2].  From a semester, import courses from a csv file." << endl;
	cout << "[3].  Manually add a new course." << endl;
	cout << "[4].  Edit an existing course." << endl;
	cout << "[5].  Remove a course." << endl;
	cout << "[6].  Remove a specific student from a course." << endl;
	cout << "[7].  Add a specific student to a course." << endl;
	cout << "[8].  View list of courses in the current semester." << endl;
	cout << "[9].  View list of students of a course." << endl;
	cout << "[10]. View attendance list of a course." << endl;
	cout << "[11]. View all lecturers." << endl << endl;
	cout << "Input your choice (0-11) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		menuStaffRole();
	}

	else if (strcmp(c, "1") == 0) {
		//3.1
		Year_Semester();
	}

	else if (strcmp(c, "2") == 0) {
		//3.2
		inputCourse();
	}

	else if (strcmp(c, "3") == 0) {
		//3.3
		addANewCourse();
	}

	else if (strcmp(c, "4") == 0) {
		//3.4
		editcourse();
	}

	else if (strcmp(c, "5") == 0) {
		//3.5
		removeCourse();
	}

	else if (strcmp(c, "6") == 0) {
		//3.6
	}

	else if (strcmp(c, "7") == 0) {
		//3.7
	}

	else if (strcmp(c, "8") == 0) {
		//3.8
		view_Courses();
	}

	else if (strcmp(c, "9") == 0) {
		//3.9
		view_Student();
	}

	else if (strcmp(c, "10") == 0) {
		//3.10
		viewAttendance();
	}

	else if (strcmp(c, "11") == 0) {
		//3.11
		view_Lecturers();
	}

	else {
		notCorrect();
	}
	Staff_course();
	delete[] c;
}

void Staff_scoreboard()
{
	system("cls");
	string s;

	cout << "---------- Academic Staff-scoreboard ----------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. Search and view the scoreboard of a course" << endl;
	cout << "[2]. Export a scoreboard to a csv file" << endl << endl;
	cout << "Input your choice (0-2) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		menuStaffRole();
	}

	else if (strcmp(c, "1") == 0) {
		//4.1
		view_scoreboard();
	}

	else if (strcmp(c, "2") == 0) {
		//4.2
		export_Score();
	}

	else {
		notCorrect();
	}
	Staff_scoreboard();
	delete[] c;
}

void Staff_attendanceList()
{
	system("cls");
	string s;

	cout << "---------- Academic Staff-attendance list ----------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. Search and view attendance list of a course." << endl;
	cout << "[2]. Export a attendance list to a csv file." << endl;
	cout << "Input your choice (0-2) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		menuStaffRole();
	}

	else if (strcmp(c, "1") == 0) {
		//5.1
		viewAttendance();
	}

	else if (strcmp(c, "2") == 0) {
		//5.2
		exportAttLs();
	}

	else {
		notCorrect();
	}
	Staff_attendanceList();
	delete[] c;
}

void menuStaffRole()
{
	system("cls");
	string s;

	cout << "--------------- MENU ---------------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. Academic staff-Class." << endl;
	cout << "[2]. Academic staff-Course." << endl;
	cout << "[3]. Academic staff-Scoreboard." << endl;
	cout << "[4]. Academic staff-Attendance list." << endl << endl;
	cout << "Input your choice (0-4) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		char a[100];
		displayAllroles(3, a);
	}

	else if (strcmp(c, "1") == 0) {
		Staff_class();
	}

	else if (strcmp(c, "2") == 0) {
		Staff_course();
	}

	else if (strcmp(c, "3") == 0) {
		Staff_scoreboard();
	}

	else if (strcmp(c, "4") == 0) {
		Staff_attendanceList();
	}

	else {
		notCorrect();
		menuStaffRole();
	}
	delete[] c;
}

void showMenu(int typeAccount, char ID[])
{
	system("cls");

	//student
	if (typeAccount == 1) {
		menuStudent(ID);
	}

	//lecturer
	else if (typeAccount == 2) {
		menuLecturer();
	}

	//staff
	else if (typeAccount == 3) {
		menuStaffRole();
	}
}

void displayAllroles(int typeAccount, char ID[])
{
	system("cls");
	string s;

	//All roles
	cout << "======== MENU ========" << endl;
	cout << "[1]. Show menu" << endl;
	cout << "[2]. View profile info" << endl;
	cout << "[3]. Change password" << endl;
	cout << "[4]. Logout" << endl << endl;
	cout << "Input your choice (1-4) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	//Show menu
	if (strcmp(c, "1") == 0) {
		//1.2
		showMenu(typeAccount, ID);
	}

	//View profile info
	else if (strcmp(c, "2") == 0) {
		//1.3
		viewProfile(typeAccount, ID);
	}

	//Change password
	else if (strcmp(c, "3") == 0) {
		//1.4
		system("cls");
		cin.ignore();
		changePassword(typeAccount, ID);
	}

	//Logout
	else if (strcmp(c, "4") == 0) {
		//1.5
		cin.ignore(100, '\n');
		logout();
		return;
	}

	else {
		notCorrect();
	}
	char a[100];
	displayAllroles(typeAccount, ID);
	delete[] c;
}

//W02----------------------------------------------------------------------------------------------------

void Year_Semester()
{
	system("cls");
	string s;

	cout << "-------------------- MENU --------------------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. Create an academic year and semesters" << endl;
	cout << "[2]. Delete an academic year and semesters" << endl;
	cout << "[3]. View an academic year and semesters" << endl << endl;
	cout << "Input your choice (0-4) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		Staff_course();
	}

	else if (strcmp(c, "1") == 0) {
		//Create
		create_Year_Semester();
	}

	else if (strcmp(c, "2") == 0) {
		//Delete
		delete_Year_Semester();
	}

	else if (strcmp(c, "3") == 0) {
		//View
		view_Year_Semester();
	}

	else {
		notCorrect();
	}
	Year_Semester();
	delete[] c;
}