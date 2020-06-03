#ifndef _CLASS_H_
#define _CLASS_H_

// 2.1 Import class from a csv file
void importAndSave();
bool importClass(StuNode*& pHead, int& n);
void takeFileAdd(char fileAdd[]);
Student importStudent(char str[]);
char* getID(char str[], int& index);
char* getsName(char str[], int& index);
Date getDOB(char str[], int& index);
char* getsClass(char str[], int& index);
int getGender(char str[], int& index);
char* genPassword(Date DOB);
void saveClass(StuNode* pHead, const int& n, char fileAdd[]);
void loadClass(StuNode*& pHead, int& n, char fileAdd[]);
void mergeList(StuNode*& pH1, StuNode*& pH2, int& added);
void displayClass(StuNode* pHead, const int& n);
void deleteStuNodes(StuNode*& pHead);
bool findStuNode(StuNode* pHead, StuNode* pStu);

//2.2 Manually add a student to the class

void addNewStudent();
Student inputStudent();
void addStuNode(StuNode*& pHead, StuNode* pNew);
bool stuNodeExists(StuNode* pHead, char* ID);
StuNode* removeStuNode(StuNode*& pHead, char* ID, bool& res);

//2.3 Edit a student in a class

void editStudent();
StuNode* findStuNode(StuNode* pHead, char* ID);

#endif // !_CLASS_H_

