/* -------------------- this is Vu's file for functions ------------------- */
#include "Header.h"

//W01
void notCorrect()
{
	system("cls");
	cout << "ALERT" << endl;
	cout << "       Your choice is not correct!" << endl;
	cout << "       Please input again!" << endl;
	Sleep(2000);
	system("cls");
}

void menuStudent()
{
	system("cls");
	char c[5];
	cout << "--------------- MENU ---------------" << endl;
	cout << "0. Back" << endl;
	cout << "1. Check-in." << endl;
	cout << "2. View check-in result." << endl;
	cout << "3. View schedule." << endl;
	cout << "4. View your scores of a coure." << endl << endl;
	cout << "Input your choice (0-4) > ";
	cin.ignore();
	cin.get(c, 3, '\n');

	if (strcmp(c, "0") == 0) {
		//Back
		displayAllroles(1);
	}

	else if (strcmp(c, "1") == 0) {
		//7.1
	}

	else if (strcmp(c, "2") == 0) {
		//7.2
	}

	else if (strcmp(c, "3") == 0) {
		//7.3
	}

	else if (strcmp(c, "4") == 0) {
		//7.4
	}

	else {
		notCorrect();
		menuStudent();
	}
}

void menuLecturer()
{
	system("cls");
	char c[5];
	cout << "----------------------- MENU -----------------------" << endl;
	cout << "0. Back" << endl;
	cout << "1. View list of courses in the current semester." << endl;
	cout << "2. View list of students of a course." << endl;
	cout << "3. View attendance list of a course." << endl;
	cout << "4. Edit an attendance." << endl;
	cout << "5. Import scoreboard of a course from a csv file." << endl;
	cout << "6. Edit grade of a student." << endl;
	cout << "7. View a scoreboard." << endl << endl;
	cout << "Input your choice (0-7) > ";
	cin.ignore();
	cin.get(c, 3, '\n');

	if (strcmp(c, "0") == 0) {
		//Back
		displayAllroles(2);
	}

	else if (strcmp(c, "1") == 0) {
		//6.1
	}

	else if (strcmp(c, "2") == 0) {
		//6.2
	}

	else if (strcmp(c, "3") == 0) {
		//6.3
	}

	else if (strcmp(c, "4") == 0) {
		//6.4
	}

	else if (strcmp(c, "5") == 0) {
		//6.5
	}

	else if (strcmp(c, "6") == 0) {
		//6.6
	}

	else if (strcmp(c, "7") == 0) {
		//6.7
	}

	else {
		notCorrect();
		menuLecturer();
	}
}

//-----------------------------------------------------------------------------------------

void Staff_class()
{
	system("cls");
	char c[5];
	cout << "------------- Academic Staff-class -------------" << endl;
	cout << "0. Back" << endl;
	cout << "1. Import students of a class from a csv file." << endl;
	cout << "2. Manually add a new student to a class." << endl;
	cout << "3. Edit an existing student." << endl;
	cout << "4. Remove a student." << endl;
	cout << "5. Change students from class A to class B." << endl;
	cout << "6. View list of classes." << endl;
	cout << "7. View list of students in a class." << endl << endl;
	cout << "Input your choice (0-7) > ";
	cin.ignore();
	cin.get(c, 3, '\n');

	if (strcmp(c, "0") == 0) {
		//Back
		menuStaffRole();
	}

	else if (strcmp(c, "1") == 0) {
		//2.1
	}

	else if (strcmp(c, "2") == 0) {
		//2.2
	}

	else if (strcmp(c, "3") == 0) {
		//2.3
	}

	else if (strcmp(c, "4") == 0) {
		//2.4
	}

	else if (strcmp(c, "5") == 0) {
		//2.5
	}

	else if (strcmp(c, "6") == 0) {
		//2.6
	}

	else if (strcmp(c, "7") == 0) {
		//2.7
	}

	else {
		notCorrect();
		Staff_class();
	}
}

void Staff_course()
{
	system("cls");
	char c[5];
	cout << "---------------------------- Academic Staff-course ----------------------------" << endl;
	cout << "0. Back" << endl;
	cout << "1. Create / Update / Delete / view academic years (2019-2020) and semesters." << endl;
	cout << "2. From a semester, import courses from a csv file." << endl;
	cout << "3. Manually add a new course." << endl;
	cout << "4. Edit an existing course." << endl;
	cout << "5. Remove a course." << endl;
	cout << "6. Remove a specific student from a course." << endl;
	cout << "7. Add a specific student to a course." << endl;
	cout << "8. View list of courses in the current semester." << endl;
	cout << "9. View list of students of a course." << endl;
	cout << "10. View attendance list of a course." << endl;
	cout << "11. Create / Update / Delete / View all lecturers." << endl << endl;
	cout << "Input your choice (0-11) > ";
	cin.ignore();
	cin.get(c, 3, '\n');

	if (strcmp(c, "0") == 0) {
		//Back
		menuStaffRole();
	}

	else if (strcmp(c, "1") == 0) {
		//3.1
	}

	else if (strcmp(c, "2") == 0) {
		//3.2
	}

	else if (strcmp(c, "3") == 0) {
		//3.3
	}

	else if (strcmp(c, "4") == 0) {
		//3.4
	}

	else if (strcmp(c, "5") == 0) {
		//3.5
	}

	else if (strcmp(c, "6") == 0) {
		//3.6
	}

	else if (strcmp(c, "7") == 0) {
		//3.7
	}

	else if (strcmp(c, "8") == 0) {
		//3.8
	}

	else if (strcmp(c, "9") == 0) {
		//3.9
	}

	else if (strcmp(c, "10") == 0) {
		//3.10
	}

	else if (strcmp(c, "11") == 0) {
		//3.11
	}

	else {
		notCorrect();
		Staff_course();
	}

}

void Staff_scoreboard()
{
	system("cls");
	char c[5];
	cout << "---------- Academic Staff-scoreboard ----------" << endl;
	cout << "0. Back" << endl;
	cout << "1. Search and view the scoreboard of a course" << endl;
	cout << "2. Export a scoreboard to a csv file" << endl << endl;
	cout << "Input your choice (0-2) > ";
	cin.ignore();
	cin.get(c, 3, '\n');

	if (strcmp(c, "0") == 0) {
		//Back
		menuStaffRole();
	}

	else if (strcmp(c, "1") == 0) {
		//4.1
	}

	else if (strcmp(c, "2") == 0) {
		//4.2
	}

	else {
		notCorrect();
		Staff_scoreboard();
	}
}

void Staff_attendanceList()
{
	system("cls");
	char c[5];
	cout << "---------- Academic Staff-attendance list ----------" << endl;
	cout << "0. Back" << endl;
	cout << "1. Search and view attendance list of a course." << endl;
	cout << "2. Export a attendance list to a csv file." << endl;
	cout << "Input your choice (0-2) > ";
	cin.ignore();
	cin.get(c, 3, '\n');

	if (strcmp(c, "0") == 0) {
		//Back
		menuStaffRole();
	}

	else if (strcmp(c, "1") == 0) {
		//5.1
	}

	else if (strcmp(c, "2") == 0) {
		//5.2
	}

	else {
		notCorrect();
		Staff_attendanceList();
	}
}

void menuStaffRole()
{
	system("cls");
	char c[5];
	cout << "--------------- MENU ---------------" << endl;
	cout << "0. Back" << endl;
	cout << "1. Academic staff-Class." << endl;
	cout << "2. Academic staff-Course." << endl;
	cout << "3. Academic staff-Scoreboard." << endl;
	cout << "4. Academic staff-Attendance list." << endl << endl;
	cout << "Input your choice (0-4) > ";
	cin.ignore();
	cin.get(c, 3, '\n');

	if (strcmp(c, "0") == 0) {
		//Back
		displayAllroles(3);
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
}

void showMenu(int typeAccount)
{
	system("cls");

	//student
	if (typeAccount == 1) {
		menuStudent();
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

void displayAllroles(int typeAccount)
{
	system("cls");
	char c[5];

	//All roles
	cout << "1. Show menu" << endl;
	cout << "2. View profile info" << endl;
	cout << "3. Change password" << endl;
	cout << "4. Logout" << endl << endl;
	cout << "Input your choice (1-4) > ";
	cin.ignore();
	cin.get(c, 3, '\n');

	//Show menu
	if (strcmp(c, "1") == 0) {
		//1.2
		showMenu(typeAccount);
	}

	//View profile info
	else if (strcmp(c, "2") == 0) {
		//1.3
	}

	//Change password
	else if (strcmp(c, "3") == 0) {
		//1.4
	}

	//Logout
	else if (strcmp(c, "4") == 0) {
		//1.5
		cin.ignore();
		menu(typeAccount);
	}

	else {
		notCorrect();
		displayAllroles(typeAccount);
	}
}