// ..................................................  
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2 
// ..................................................

#include <iostream>
#include <string>
#include "CDate.h"

CDate::CDate(void){
	m_year = m_month = m_day = 0;
}

CDate::CDate(int year, int month, int day){
	setDate( year, month, day );        
}

CDate::CDate(int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	setDate( year, monthStr2Num(month), day ); 
}

bool CDate::isValidDate(int year, int month, int day){
	// TODO you need to fill in the code here        ********
	return isValidDay(year, month, day);	
}

bool CDate::isValidDate(int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	return isValidDay(year, monthStr2Num(month), day);
}

int CDate::monthStr2Num(std::string month){
	// TODO you need to fill in the code here        ********
	int mth = 0;	
	if (month == "January"){
		mth = 1;
	} else if (month == "February"){
		mth= 2; 
	} else if (month == "March"){
		mth = 3;
	} else if (month == "April"){
		mth = 4;
	} else if (month == "May"){
		mth = 5;
	} else if (month == "June"){
		mth= 6; 
	} else if (month == "July"){
		mth = 7;
	} else if (month == "August"){
		mth = 8;
	} else if (month == "September"){
		mth = 9;
	} else if (month == "October"){
		mth= 10; 
	} else if (month == "November"){
		mth = 11;
	} else if (month == "December"){
		mth = 12;
	} 
	return mth;
}

bool CDate::isValidDay(int year, int month, int day){
	if ((day < 1) || (day > 31)) return false;
	if (year < 0) return false;

	bool valid = false;
	switch (month) {
		case 1: 
		case 3: 
		case 5: 
		case 7:
		case 8: 
		case 10: 
		case 12: valid = true; break;
			// TODO you need to fill in the code here        ********
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				valid = (day <=28);
			} else if ((year % 400) == 0) {
				valid = (day <= 29);
			} else if ((year % 100) == 0) {
				valid = (day <= 28);
			} else {
				valid = (day <= 29);
			}
			break;
		case 4: 
		case 6: 
		case 9: 
		case 11: valid = (day <= 30); break;
			// TODO you need to fill in the code here        ********
		default:
			// TODO you need to fill in the code here        ********
			valid = true;
			break; 
	}
	return valid;
}

void CDate::setDate(int year, int month, int day){
	if(isValidDate(year, month, day)){    
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}

void CDate::setDate(int year, std::string month, int day){
	// TODO you need to fill in the code here        ********
	setDate(year, monthStr2Num(month), day);
}

void CDate::print(void){
	std::cout << m_year << "/" << m_month << "/" << m_day << std::endl;
}

int CDate::getDate(void){
	return (m_year * 10000) + (m_month * 100) + m_day;
}

