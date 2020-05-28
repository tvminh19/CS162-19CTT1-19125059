#include "header.h"

//is leap year
bool isLeapYear(int y) {
	if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)	return true;
	return false;
}

//day of month
int dayOfMonth(int m, int y) {
	if (m == 4 || m == 6 || m == 9 || m == 11)	return 30;
	else if (isLeapYear(y) && m == 2) return 29;
	else if (!isLeapYear(y) && m == 2) return 28;
	else
		return 31;
}

//return date
Date dateOfWeek(Date root, int dOfWeek) {
	for (int i = 0; i < dOfWeek; ++i) {
		if (dayOfMonth(root.month, root.year) - root.day <= 7) {
			root.day = 7 - (dayOfMonth(root.month, root.year) - root.day);
			root.month++;
		}
		else
			root.day += 7;
		//check month == 13
		if (root.month == 13) {
			root.month = 1;
			root.year++;
		}
	}
	return root;
}