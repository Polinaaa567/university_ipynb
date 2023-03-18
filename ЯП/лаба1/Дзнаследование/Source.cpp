#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<cmath>
#include<conio.h>
#include<iostream>
#include<time.h>
#include<cstring>
#include<iomanip>
#include"locale.h"
#include<fstream>
#include<windows.h>
#include"komp.h"

using namespace std;


void Human::Human(string Sec2, string name2, string sur2, string beer2, string sex2)
{
	Secondname = new string;
	*Secondname = Sec2;

	Name = new string;
	*Name = name2;

	Surname = new string;
	*Surname = sur2;

	Birthdate = new string;
	*Birthdate = beer2;

	sex = new string;
	*sex = sex2;
}
Human::~Human() {
	delete Secondname;
	delete Name;
	delete Surname;
	delete Birthdate;
	delete sex;
}


void Employee::Employee() {

}