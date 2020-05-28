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

#endif // !_CLASS_H_

