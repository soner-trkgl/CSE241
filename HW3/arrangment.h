#ifndef ARRANGMENT_H
#define ARRANGMENT_H
#include<iostream>
#include<string>
#include<vector>

using namespace std;




namespace University{


	struct date{
		string day;
		int hourB;
		int hourE;
	};

	struct Course
	{
		int id;
		string name;
		int code;
		int credit;
		int total_hours;
		vector<date> lecture_dates;
		string field;
		bool isMandatory;
		vector<string> c_name;
	};

	struct Classroom
	{
		int id;
		string c_no;
		int capacity;
		int student_inroom;
		
	};

	



	class Lecturer{
		public:
			Lecturer(string,string,int,string);
			Lecturer();
			void set_name(string);
			void set_surname(string);
			void set_personal_id(int);
			void set_title(string);
			void set_profession(string);
			int get_personal_id()const;
			vector<Course>& get_vCourses() ;
			vector<Course>& get_vElective();
			void proposeCourse(const string&);
			void assignCourse(vector <Course>& thevCourse, int getId = 0);
			

			

		private:
			string name;
			string surname;
			int personal_id;
			string title;
			vector<string> profession;
			vector<Course> vCourses;
			vector<Course> vElective;
		
	};

	class Administrator{
		public:
			void arrangeTimeTable( vector<Lecturer>& thevLecturer , int getId=0 ) const;
			void arrangeClassroom(  vector<Lecturer>& thevLecturer , const vector<Classroom>& thevClassroom ,int getId = 0 , string getC1 = "" , string getC2 = "")const;
		
		private:
			int pid;
			int password;
		
	};



}


#endif