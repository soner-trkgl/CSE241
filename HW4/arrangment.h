#ifndef ARRANGMENT_H
#define ARRANGMENT_H
#include<iostream>
#include<string>
#include<vector>

using namespace std;


namespace University{


	struct date{			// for lecture date
		string day;
		int hourB;
		int hourE;
	};

	struct Attendance		// for attendance list
	{
		string s_name ;
		int s_no ;
		int course_id;
		int * courseOfhours ;
		int hour_count;
		bool class_in_out ;

	};
	

	struct Course {
		int id;
		string name;
		int code;
		int credit;
		int total_hours;
		vector<date> lecture_dates;
		string field;
		bool isMandatory;
	};


	class Classroom {

		public:
			Classroom () : id(0) , c_no("empty") , capacity(0) , student_inroom (0) , attendance_size (0) , list(nullptr) {}
			Classroom(int id , string c_no , int capacity , int student_inroom ) : id(id) , c_no(c_no) , capacity(capacity) , student_inroom(student_inroom)  {}
			Classroom( const Classroom& );
			Classroom& operator=(const Classroom&);
			void set_id(int theId) { id = theId ; }
			void set_c_no(string theC_no) { c_no = theC_no ; }
			void set_capacity(int theCapacity) { capacity = theCapacity ; }
			void set_student_inroom(int theStudent_inroom ) { student_inroom = theStudent_inroom ; }
			void set_attendance_size( int theAttendance_size ) { attendance_size = theAttendance_size ; }
			void set_list( Attendance* ) ; 
			void set_list_courseOfhours(int * , int );
			int get_id()const{ return id ;}
			string get_c_no()const { return c_no ; }
			int get_capacity()const { return capacity ; }
			int get_student_inroom()const { return student_inroom ; }
			int get_attendance_size() const { return attendance_size ; }
			Attendance* get_list()  { return list ; }
			vector<Course>& get_cCourses() { return cCourses ; }
			~Classroom();
		private:
			int id;
			string c_no;
			int capacity;
			int student_inroom;
			vector<Course> cCourses;
			int attendance_size;
			Attendance* list;
		
	};


	class Student{
		public:
			Student(string ,string,int,int);
			Student() : name("empty") , surname("empty") , student_no(0) , level(0) , creditRight(0) {}
			Student(const Student&);
			Student& operator=(const Student&);
			string get_name()const { return name ; }
			string get_surname()const { return surname ; }
			int get_student_no()const { return student_no ; }
			int get_level()const { return level ; }
			int get_creditRight()const { return creditRight ; }
			void set_name(string theName) { name = theName ; }
			void set_surname(string theSurname) { surname = theSurname ; }
			void set_student_no(int theNo) { student_no = theNo ; }
			void set_level(int theLevel) { level = theLevel ; }
			void set_creditRight(int theCreditRight) { creditRight = theCreditRight ; }
			void enterClassroom( vector<Classroom>& , string , int  );
			void quitClassroom( vector<Classroom>& , int );
			~Student(){}
		
		private:
			string name;
			string surname;
			int student_no;
			int level;
			int creditRight;	
	};


	class Lecturer{
		public:
			Lecturer(string,string,int,string);
			Lecturer();
			Lecturer(const Lecturer&);
			Lecturer& operator=(const Lecturer&);
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
			~Lecturer();
			
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
			Administrator(int pid , int password ) : pid(pid) , password(password) {}
			Administrator(): pid(0) , password(0) {}
			Administrator(const Administrator& theA) { pid = theA.pid ; password = theA.password ;}
			Administrator& operator=(const Administrator& theA ) { pid = theA.pid ; password = theA.password ; return  *this ;}
			void set_pid(int);
			void set_password(int);
			int get_pid()const{ return pid ; }
			int get_password()const{ return password ; }
			void arrangeTimeTable( vector<Lecturer>& thevLecturer , int getId=0 ) const;
			void arrangeClassroom( const vector<Lecturer>& thevLecturer , vector<Classroom>& thevClassroom ,int getId = 0 , string getC1 = "" , string getC2 = "");
			~Administrator(){}

		private:
			int pid;
			int password;
		
	};
	void takeAttendance( vector<Classroom>& , int  );


}


#endif