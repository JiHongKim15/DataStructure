#ifndef _STUDENTDATA_H_
#define _STUDENTDATA_H_

#include <iostream>
#include <cstring>
#include <fstream>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

/*  ※ 과제 제출 시 본 주석 삭제
구현 편의성을 위해 함수에 코드가 작성되어 있으며, 해당 코드는 이용 또는 삭제, 변경이 가능함.
또한, 일부 코드는 과제 요구사항에 맞게 변경이 필요할 수 있음
*/

class StudentData{
private:
	int			StudentID;		// 학번
	char		Name[10];		// 이름
	int			Year;				// 학년
	double	AvgGrade;		// 평점

public:
	StudentData(){
		StudentID = 0;
		memset(Name, 0, 10);
		Year = 0;
		AvgGrade = 0;
	};
	~StudentData(){};

	void	setStudentID(int id)			{ StudentID = id; }
	void	setName(char* name)		{ strcpy(Name, name); }
	void	setYear(int year)				{ Year = year; }	
	void	setAvgGrade(char *a, char *b, char *c){
		/* 아래 작성된 코드는 이용 또는 삭제, 변경이 가능함 -- 과제 제출 시 본 주석 삭제*/
		AvgGrade = getGrade(a) + getGrade(b) + getGrade(c);
		AvgGrade /= 3;
		int tmp = AvgGrade * 1000;
		int tmp2 = tmp / 10;
		if(tmp % 10 > 4){
			AvgGrade = (tmp2 + 1) / 100.0 ;
		}else{
			AvgGrade = tmp2 / 100.0;
		}
	}

	int			getYear()				{ return Year; }
	int			getStudentID()		{ return StudentID; }
	char*		getName()				{ return Name; }
	double	getAvgGrade()			{ return AvgGrade; }

	double	getGrade(char *ch){
		/* 아래 작성된 코드는 이용 또는 삭제, 변경이 가능함 -- 과제 제출 시 본 주석 삭제*/
		if(strcmp(ch, "A+") == 0){
			return 4.5;
		}else if(strcmp(ch, "A0") == 0){
			return 4.0;
		}else if(strcmp(ch, "B+") == 0){
			return 3.5;
		}else if(strcmp(ch, "B0") == 0){
			return 3.0;
		}else if(strcmp(ch, "C+") == 0){
			return 2.5;
		}else if(strcmp(ch, "C0") == 0){
			return 2;
		}else if(strcmp(ch, "D+") == 0){
			return 1.5;
		}else if(strcmp(ch, "D0") == 0){
			return 1.0;
		}else{
			return 0;
		}
		return 0;
	}

	/*
	virtual 함수 추가
	*/
};

bool compare( pair< pair< double, int>, StudentData* > a, pair< pair< double, int>, StudentData* > b );

#endif