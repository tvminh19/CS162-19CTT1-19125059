#pragma once
#include "header.h"
#include "score.h"
#include "students.h"

struct score {
	float midterm;
	float final;
	float bonus;
	float total;
};

struct scoreboard {
	student* stu;
	int isActive;
	score* sco;
	int went2class[12];
};