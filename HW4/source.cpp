#include<iostream>
#include<ctime>
#include<cstdlib>
#include"arrangment.h"
#include<string>




namespace University{

	
	Student::Student(string na,string su,int st, int le){
		name=na;
		surname=su;
		student_no=st;
		level=le;
		if(level == 1)
			creditRight=20;
		if(level == 2)
			creditRight=21;
		if(level == 3)
			creditRight=22;
		if(level == 4)
			creditRight=23;
	}

	Student::Student( const Student& theS){
		name = theS.name;
		surname = theS.surname;
		student_no = theS.student_no;
		level = theS.level ;
		creditRight = theS.creditRight;
		
	}
	Student& Student::operator=( const Student& theS ){
		name = theS.name;
		surname = theS.surname;
		student_no = theS.student_no;
		level = theS.level ;
		creditRight = theS.creditRight;
	}
	
	Classroom::Classroom( const Classroom& theC ){
		id = theC.id ;
		c_no = theC.c_no ;
		capacity = theC.capacity ;
		student_inroom = theC.student_inroom;
		attendance_size = theC.attendance_size;
		if( theC.cCourses.size() == 0){
		}
		else{
			for( unsigned int i = 0; i<theC.cCourses.size(); i++){
				cCourses.push_back(theC.cCourses[i]);
			}
		}
		if( theC.list == nullptr ){
			list = theC.list;
		}
		else{
			list = new Attendance[attendance_size];
			for( int i =0 ; i<attendance_size; i++){
				list[i].s_name = theC.list[i].s_name ;
				list[i].s_no = theC.list[i].s_no ;
				list[i].course_id = theC.list[i].course_id ;
				list[i].courseOfhours = new int[theC.list[i].hour_count];
				for( int j=0; j<theC.list[i].hour_count; j++){
					list[i].courseOfhours[j] = theC.list[i].courseOfhours[j];
				}
				list[i].hour_count = theC.list[i].hour_count ;
				list[i].class_in_out = theC.list[i].class_in_out ;
			}
		}
	}

	Classroom& Classroom::operator=(const Classroom& theC){
		id = theC.id ;
		c_no = theC.c_no ;
		capacity = theC.capacity ;
		student_inroom = theC.student_inroom;
		attendance_size = theC.attendance_size;
		if( theC.cCourses.size() == 0){
		}
		else{
			cCourses.clear();
			cCourses.shrink_to_fit();
			for( unsigned int i = 0; i<theC.cCourses.size(); i++){
				cCourses.push_back(theC.cCourses[i]);
			}
		}
		if( list == nullptr ){
			if( theC.list == nullptr){

			}
			else{
				list = new Attendance[attendance_size];
				for( int i =0 ; i<attendance_size; i++){
					list[i].s_name = theC.list[i].s_name ;
					list[i].s_no = theC.list[i].s_no ;
					list[i].course_id = theC.list[i].course_id ;
					list[i].courseOfhours = new int[theC.list[i].hour_count];
					for( int j=0; j<theC.list[i].hour_count; j++){
						list[i].courseOfhours[j] = theC.list[i].courseOfhours[j];
					}
					list[i].hour_count = theC.list[i].hour_count ;
					list[i].class_in_out = theC.list[i].class_in_out ;
				}
			}	
		}
		else{
			for( int j = 0; j<attendance_size; j++){
				delete[] list[j].courseOfhours;
			}
			list = new Attendance[attendance_size];
			for( int i =0 ; i<attendance_size; i++){
				list[i].s_name = theC.list[i].s_name ;
				list[i].s_no = theC.list[i].s_no ;
				list[i].course_id = theC.list[i].course_id ;
				list[i].courseOfhours = new int[theC.list[i].hour_count];
				for( int j=0; j<theC.list[i].hour_count; j++){
					list[i].courseOfhours[j] = theC.list[i].courseOfhours[j];
				}
				list[i].hour_count = theC.list[i].hour_count ;
				list[i].class_in_out = theC.list[i].class_in_out ;
			}
		}
		return  *this ;
	}
	Classroom::~Classroom(){
		cCourses.clear();
		cCourses.shrink_to_fit();
		for( int j = 0; j<attendance_size; j++){
			delete[] list[j].courseOfhours;
		}
	}
	void Classroom::set_list( Attendance* temp ){ 
		if( list == nullptr ){
			list = temp ;
		}
		else{
			for( int j = 0; j<attendance_size; j++){
				delete[] list[j].courseOfhours;
			}
			list = temp;
		}
		
	}
	void Classroom::set_list_courseOfhours(int * temp , int location){
		delete[] list[location].courseOfhours;
		list[location].courseOfhours = temp;
	}

	void Student::enterClassroom( vector<Classroom>& thevClassroom , string thec_no , int hour ){
		string dayR;
		int flag = 0 , flag1 = 0;
		int num , num1;
		int count = 0;
		int c_id;
		Attendance* temp = nullptr;
		int* temp1 = nullptr;
		

		for( int i = 0; i<thevClassroom.size(); i++){
			if( thevClassroom[i].get_c_no() == thec_no ){
				count++;
				flag = i ;
			}
			else{
				for( int j = 0 ; j<thevClassroom[i].get_attendance_size(); j++){
					if( thevClassroom[i].get_list()[j].class_in_out == true &&  thevClassroom[i].get_list()[j].s_no == student_no ){
						flag1++;
					}
				}
			}
		}
		if( count == 0){
			cout<<"ERROR: no class"<<endl;
		}
		else if( count != 0 && flag1 != 0 ){
			cout<<"BLOCK: s/he is at another classroom"<<endl;
		}
		else{
			count =0;
			num = hour / 8 ;
			num1 = ( hour % 8  ) + 9;
			if( 0 == num){
				dayR = "Mon";
			}
			else if(1 == num){
				dayR = "Tue";
			}
			else if(2 == num ){
				dayR = "Wed";
			}
			else if(3 == num ){
				dayR = "Thu";
			}
			else if(4 == num ){
				dayR = "Fri";
			}
			int a = 0;
			for( unsigned int i = 0; i<thevClassroom[flag].get_cCourses().size(); i++){
				for( unsigned int j = 0; j<thevClassroom[flag].get_cCourses()[i].lecture_dates.size(); j++){
					if( thevClassroom[flag].get_cCourses()[i].lecture_dates[j].day == dayR){
						for( unsigned int k = 0; k<thevClassroom[flag].get_cCourses()[i].lecture_dates.size(); k++){
							if( j != k ){
								for( int l=thevClassroom[flag].get_cCourses()[i].lecture_dates[j].hourB; l<thevClassroom[flag].get_cCourses()[i].lecture_dates[j].hourE; l++){
									
									if( l == num1 ){
										++a;
									}
								}
							}
						}
						for( int k=thevClassroom[flag].get_cCourses()[i].lecture_dates[j].hourB; k<thevClassroom[flag].get_cCourses()[i].lecture_dates[j].hourE; k++){
							
							if( k == num1 ){
								c_id = thevClassroom[flag].get_cCourses()[i].id ;
								++count;
							}
						}
						
					}
					
				}
			}
			if( count == 0 ){
				cout<<"Wrong hours choice"<<endl;
			}
			else{
				if( thevClassroom[flag].get_list() == nullptr ){
					temp = new Attendance;
					temp[0].s_name=name;
					temp[0].course_id=c_id;
					temp[0].s_no=student_no;
					temp[0].courseOfhours = new int ;
					temp[0].courseOfhours[0] = num1 ;
					temp[0].hour_count = 1;
					temp[0].class_in_out = true ;
					thevClassroom[flag].set_list( temp );
					thevClassroom[flag].set_attendance_size( thevClassroom[flag].get_attendance_size() + 1 ) ;
					thevClassroom[flag].set_student_inroom( thevClassroom[flag].get_student_inroom() + 1 ) ;
					cout<<thevClassroom[flag].get_student_inroom()<<" (student_inroom)"<<endl;
				}
				else{
					int x = 0 , y = 0 , z = 0  , t = 0;
					for( int i = 0; i<thevClassroom[flag].get_attendance_size() ; i++){
						if( thevClassroom[flag].get_list()[i].s_no == student_no ){
							x++;
							if( thevClassroom[flag].get_list()[i].course_id == c_id ){
								y++;
								for( int j = 0; j<thevClassroom[flag].get_list()[i].hour_count; j++){
									if( thevClassroom[flag].get_list()[i].courseOfhours[j] == num1 ){
										t++;
									}
								}
							}
							else{
								if( thevClassroom[flag].get_list()[i].class_in_out == true){
									z++;
								}
								
							}
						}
						else{
							
						}
					}
					if( t != 0 ){
						cout<<"you have already this hour"<<endl;
					}
					else if( z != 0){
						cout<<"BLOCK: s/he is at another classroom"<<endl;
					}
					else if( x == 0 ){
						temp = new Attendance[ thevClassroom[flag].get_attendance_size() + 1];
						for( int j = 0; j<thevClassroom[flag].get_attendance_size(); j++){
							temp[j].s_name = thevClassroom[flag].get_list()[j].s_name;
							temp[j].course_id = thevClassroom[flag].get_list()[j].course_id;
							temp[j].s_no = thevClassroom[flag].get_list()[j].s_no;
							temp[j].hour_count = thevClassroom[flag].get_list()[j].hour_count ;
							temp[j].courseOfhours = new int[thevClassroom[flag].get_list()[j].hour_count] ;
							for( int k =0 ; k<thevClassroom[flag].get_list()[j].hour_count; k++){
								temp[j].courseOfhours[k] = thevClassroom[flag].get_list()[j].courseOfhours[k];
							}
							temp[j].class_in_out = thevClassroom[flag].get_list()[j].class_in_out ;
						}
						temp[thevClassroom[flag].get_attendance_size()].s_name = name;
						temp[thevClassroom[flag].get_attendance_size()].course_id = c_id;
						temp[thevClassroom[flag].get_attendance_size()].s_no = student_no;
						temp[thevClassroom[flag].get_attendance_size()].courseOfhours = new int;
						temp[thevClassroom[flag].get_attendance_size()].courseOfhours[0] = num1;
						temp[thevClassroom[flag].get_attendance_size()].hour_count =1;	
						temp[thevClassroom[flag].get_attendance_size()].class_in_out = true ;
						thevClassroom[flag].set_list( temp );
						thevClassroom[flag].set_attendance_size( thevClassroom[flag].get_attendance_size() + 1);
						thevClassroom[flag].set_student_inroom( thevClassroom[flag].get_student_inroom() + 1 ) ;
						cout<<thevClassroom[flag].get_student_inroom()<<" (student_inroom)"<<endl;
					}
					else if( y == 1 && z == 0){
						for( int j = 0; j<thevClassroom[flag].get_attendance_size(); j++){
							if( thevClassroom[flag].get_list()[j].course_id == c_id && thevClassroom[flag].get_list()[j].s_no == student_no ){
								temp1 = new int[thevClassroom[flag].get_list()[j].hour_count + 1];
								for( int k =0 ; k<thevClassroom[flag].get_list()[j].hour_count; k++){
									temp1[k] = thevClassroom[flag].get_list()[j].courseOfhours[k];
								}
								temp1[thevClassroom[flag].get_list()[j].hour_count] = num1 ;
								thevClassroom[flag].get_list()[j].hour_count++;
								thevClassroom[flag].set_list_courseOfhours(temp1 , j) ;
							}
						}
						cout<<thevClassroom[flag].get_student_inroom()<<" (student_inroom)"<<endl;
					}
					else if( x == 1 && z == 0 ){
						temp = new Attendance[ thevClassroom[flag].get_attendance_size() + 1 ];
						for( int j = 0; j<thevClassroom[flag].get_attendance_size(); j++){
							temp[j].s_name = thevClassroom[flag].get_list()[j].s_name;
							temp[j].course_id = thevClassroom[flag].get_list()[j].course_id;
							temp[j].s_no = thevClassroom[flag].get_list()[j].s_no;
							temp[j].hour_count = thevClassroom[flag].get_list()[j].hour_count ;
							temp[j].courseOfhours = new int[thevClassroom[flag].get_list()[j].hour_count ] ;
							for( int k =0 ; k<thevClassroom[flag].get_list()[j].hour_count; k++){
								temp[j].courseOfhours[k] = thevClassroom[flag].get_list()[j].courseOfhours[k];
							}
							temp[j].class_in_out = thevClassroom[flag].get_list()[j].class_in_out ;
						}	
						temp[thevClassroom[flag].get_attendance_size()].s_name = name;
						temp[thevClassroom[flag].get_attendance_size()].course_id = c_id;
						temp[thevClassroom[flag].get_attendance_size()].s_no = student_no ;
						temp[thevClassroom[flag].get_attendance_size()].courseOfhours = new int;
						temp[thevClassroom[flag].get_attendance_size()].courseOfhours[0] = num1;
						temp[thevClassroom[flag].get_attendance_size()].hour_count =1;
						temp[thevClassroom[flag].get_attendance_size()].class_in_out = true ; 
						thevClassroom[flag].set_list( temp );
						thevClassroom[flag].set_attendance_size( thevClassroom[flag].get_attendance_size() + 1 ) ;
						thevClassroom[flag].set_student_inroom( thevClassroom[flag].get_student_inroom() + 1 ) ;
						cout<<thevClassroom[flag].get_student_inroom()<<" (student_inroom)"<<endl;

					}

				}
				
			}
		}
	}

	void Student::quitClassroom( vector<Classroom>& thevClassroom , int theS_no ){
		int count = 0;
		int flag1 , flag2;
		for( unsigned int i = 0; i<thevClassroom.size() ; i++){
			for( int j = 0; j<thevClassroom[i].get_attendance_size(); j++){
				if( thevClassroom[i].get_list()[j].class_in_out == true &&  thevClassroom[i].get_list()[j].s_no == student_no ){
					count ++ ;
					flag1 = i ;
					flag2 = j ;
				}

			}
			
		}
		if(count == 0){
			cout<<"Student has not current classroom"<<endl;
		}
		else{
			thevClassroom[flag1].get_list()[flag2].class_in_out = false ;
		}
	}
	void takeAttendance( vector<Classroom>& thevClassroom , int theC_id ){
		int count = 0;
		for( unsigned int i =0 ; i<thevClassroom.size(); i++){
			for( int j = 0; j<thevClassroom[i].get_attendance_size(); j++){
				if( thevClassroom[i].get_list()[j].course_id == theC_id ){
					cout<<thevClassroom[i].get_list()[j].s_name<<' '<<thevClassroom[i].get_list()[j].hour_count<<' ';
					count++;
				}

			}
		}
		if( count == 0){
			cout<<"Attendance list is empty"<<endl;
		}
		cout<<endl;

	}


	Lecturer::~Lecturer(){
		profession.clear();
		profession.shrink_to_fit();
		vElective.clear();
		vElective.shrink_to_fit();
		vCourses.clear();
		vCourses.shrink_to_fit();
	}
	Lecturer::Lecturer(string theName,string theSurname,int thePersonal_id,string theTitle){
		name=theName;
		surname=theSurname;
		personal_id=thePersonal_id;
		title=theTitle;
	}
	Lecturer::Lecturer(){
		name="empty";
		surname="empty";
		personal_id=0;
		title="empty";
	}
	Lecturer::Lecturer(const Lecturer& theL){
		name = theL.name ;
		surname = theL.surname ;
		personal_id = theL.personal_id ;
		title = theL.title ;
		if( theL.profession.size() == 0 ){

		}
		else{
			for( unsigned int i = 0; i<theL.profession.size(); i++){
				profession.push_back( theL.profession[i] );
			}
		}
		if( theL.vCourses.size() == 0 ){

		}
		else{
			for( unsigned int i = 0; i<theL.vCourses.size(); i++){
				vCourses.push_back( theL.vCourses[i] );
			}
		}
		if( theL.vElective.size() == 0 ){

		}
		else{
			for( unsigned int i = 0; i<theL.vElective.size(); i++){
				vElective.push_back( theL.vElective[i] );
			}
		}
	}
	Lecturer& Lecturer::operator=(const Lecturer& theL){
		name = theL.name ;
		surname = theL.surname ;
		personal_id = theL.personal_id ;
		title = theL.title ;
		if( profession.size() != 0){
			profession.clear();
			profession.shrink_to_fit();
			for( unsigned int i = 0; i<theL.profession.size(); i++){
				profession.push_back( theL.profession[i] );
			}
		}
		else{
			if( theL.profession.size() == 0 ){

			}
			else{
				for( unsigned int i = 0; i<theL.profession.size(); i++){
					profession.push_back( theL.profession[i] );
				}
			}
		}
		if( vCourses.size() != 0 ){
			vCourses.clear();
			vCourses.shrink_to_fit();
			for( unsigned int i = 0; i<theL.vCourses.size(); i++){
				vCourses.push_back( theL.vCourses[i] );
			}
		}
		else{
			if( theL.vCourses.size() == 0 ){

			}
			else{
				for( unsigned int i = 0; i<theL.vCourses.size(); i++){
					vCourses.push_back( theL.vCourses[i] );
				}
			}
		}
		if( vElective.size() != 0){
			vElective.clear();
			vElective.shrink_to_fit();
			for( unsigned int i = 0; i<theL.vElective.size(); i++){
				vElective.push_back( theL.vElective[i] );
			}
		}
		else{
			if( theL.vElective.size() == 0 ){

			}
			else{
				for( unsigned int i = 0; i<theL.vElective.size(); i++){
					vElective.push_back( theL.vElective[i] );
				}
			}
		}
		return  *this ;
			
	}

	void Lecturer::set_name(string theName){
		name=theName;
	}

	void Lecturer::set_surname(string theSurname){
		surname=theSurname;
	}

	void Lecturer:: set_personal_id(int thePersonal_id){
		personal_id=thePersonal_id;
	}

	void Lecturer::set_title(string theTitle){
		title=theTitle;
	}

	void Lecturer::set_profession(string thProfession){
		int i=0;
		string readWord;
		while( thProfession[i] != '\0' ){
			readWord.clear();
			while( thProfession[i] != '\0' && thProfession[i] != ','){
				readWord += thProfession[i];
				i++;
			}
			if( thProfession[i] != '\0')
				i++;
			profession.push_back( readWord );
		}
	}

	int Lecturer::get_personal_id()const{
		return personal_id;
	}

	vector<Course>& Lecturer::get_vCourses() {
		return vCourses;
	}
	vector<Course>& Lecturer::get_vElective() {
		return vElective;
	}


	void Lecturer::proposeCourse(const string& theString){
		int i=0 , count = 0;
		string readWord;
		while( theString[i] != '\0'){
			readWord.clear();
			while( theString[i] != '\0' && theString[i] != ' '){
				readWord += theString[i];
				i++;
			}
			if( theString[i] != '\0' )
				i++;
		}
		for( unsigned int j=0; j<profession.size(); j++){
			if( profession[j] == readWord ){
				vElective.push_back( Course() );
				readWord.clear();
				i=0;
				while( theString[i] != ' '){
					i++;
				}
				i++;
				while( theString[i] != ' '){
					i++;
				}
				i++;
				vElective[ vElective.size() -1 ].id = vElective.size() ;
				while( theString[i] != ' '){
					readWord += theString[i];
					i++;
				}
				vElective[ vElective.size() - 1].name = readWord;
				i++;
				readWord.clear();
				while( theString[i] != ' '){
					readWord += theString[i] ;
					i++;
				}
				vElective[ vElective.size() - 1].code = stoi( readWord );
				i++;
				readWord.clear();
				while( theString[i] != ' '){
					readWord += theString[i] ;
					i++;
				}
				vElective[ vElective.size() - 1].credit = stoi( readWord );
				i++;
				readWord.clear();
				while( theString[i] != ' '){
					readWord += theString[i] ;
					i++;
				}
				vElective[ vElective.size() - 1].total_hours = stoi( readWord );
				i++;
				readWord.clear();
				while( theString[i] != '\0'){
					readWord += theString[i] ;
					i++;
				}
				vElective[ vElective.size() - 1].field = readWord ;
				vElective[ vElective.size() - 1].isMandatory = false;
				count++;
			}

		}
		if( count == 0){
			cout<<"Block: field and profession mismatch"<<endl;
		}

				
	}

	void Lecturer::assignCourse( vector <Course>& thevCourse , int getId  ){

		vector<Course> theCopy=thevCourse;
		string word;
		char x;
		int i=0 , count = 1  , number = 0 , del=0 ;
		srand(time(nullptr));

		if ( getId == 0){
			
			for(unsigned int j=0 ; j<theCopy.size() ; j++){
				del=0;
				for ( unsigned int k=0; k<profession.size(); k++){
					if ( theCopy[j].field == profession[k] ){
						del++;
					}
				}
				if(del != 1){
					theCopy.erase( theCopy.begin() + j);
					j--;
				}
				
			}
			while( vCourses.size() != 3 && theCopy.size() != 0){
				if( vCourses.size() < 3 ){
					number= rand() % theCopy.size() ;
					word=theCopy[number].field;
					vCourses.push_back( Course( theCopy[number] ) );
					for( unsigned int t=0; t<thevCourse.size(); t++){
						if( thevCourse[t].name == theCopy[number].name )
							thevCourse[t].field += "+";
					}
					theCopy.erase( theCopy.begin() + number);
					for( unsigned int k=0 ; k<theCopy.size() ; k++){
						if( theCopy[k].field == word  ){
							if( profession.size() <= 2){
							}
							else{
								theCopy.erase( theCopy.begin() + k);
								k--;
							}
							
						}
					}
				}
			}
			if( vCourses.size() < 3 ){
				if( vElective.size() < 3 - vCourses.size() ){

					cout<<" ( "<<name<<" "<<surname<<" ) "<<"Mandatory lecture is not sufficient add elective lecture"<<endl;
				}
				else{
					int a = 19 ;
					while(  vCourses.size() != 3){

						number= rand() % vElective.size() ;
						vCourses.push_back( Course( vElective[number] ) );
						vCourses[ vCourses.size() - 1].id=a;
						vElective.erase( vElective.begin() + number);
						a++;
					}
				}
				
			}

		}
		else {
			if( vCourses.size() < 3){
				for( unsigned int j=0; j<theCopy.size(); j++){
					if ( theCopy[j].id == getId){
						for( unsigned int k=0; k<profession.size(); k++){
							if( theCopy[j].field == profession[k] ){
								vCourses.push_back( Course( theCopy[j] ) );
								thevCourse[j].field += "+";
								count++;
							}	
						}
						count++;
					}
				}
				if( count == 0 ){
					cout<<"Error: no course"<<endl;
				}
				else if( count == 1){
					cout<<"profession mismatch or already have"<<endl;
				}
				else
					cout<<"DONE!!!"<<endl;

			}
			else{
				cout<<"Lecturer course is full"<<endl;
			}	
			
		}

	}

	
	void Administrator::arrangeTimeTable(  vector<Lecturer>& thevLecturer , int getId ) const {
		int count=0 , approval=0;
		int hour1,hour2, sumHours = 0;
		int rand_num = 0 ;
		string dayC ;
		srand( time(nullptr) );
		for( unsigned int i=0; i<thevLecturer.size(); i++){
			if ( thevLecturer[i].get_vCourses().size() != 3 ){
				count++;
			}
		}
		if( count == 0){

			if( getId == 0){
			
				for (unsigned int i=0; i<thevLecturer.size(); i++){
					vector<Course>& copyCourses = thevLecturer[i].get_vCourses();
					for ( unsigned int j = 0; j<copyCourses.size() ; j++){
						if( copyCourses[j].lecture_dates.size() == 0){
							sumHours=0;
							while ( sumHours != copyCourses[j].total_hours ){
								approval=0;
								rand_num = ( rand() % 5 ) + 1 ;
								if( 1 == rand_num ){
									dayC = "Mon";
								}
								else if(2 == rand_num ){
									dayC = "Tue";
								}
								else if(3 == rand_num ){
									dayC = "Wed";
								}
								else if(4 == rand_num ){
									dayC = "Thu";
								}
								else if(5 == rand_num ){
									dayC = "Fri";
								}
								hour1 = ( rand() % ( copyCourses[j].total_hours - sumHours ) ) + 1;
								hour2 = ( rand() % ( 9 - hour1 ) ) +  9  ;
								for ( unsigned int k=0; k<copyCourses.size() ; k++){
									if( copyCourses[k].lecture_dates.size() != 0 ){
										for( unsigned int t=0; t<copyCourses[k].lecture_dates.size(); t++ ){
											if( dayC == copyCourses[k].lecture_dates[t].day ){
												for( int r=hour2; r<hour2+hour1; r++){
													for( int l = copyCourses[k].lecture_dates[t].hourB ; l<copyCourses[k].lecture_dates[t].hourE ; l++){
														if( r == l){
															approval++;
														}
													}
												}
											}
										}	
									}
								}
								if( approval == 0) {
									copyCourses[j].lecture_dates.push_back( date() );
									copyCourses[j].lecture_dates[ copyCourses[j].lecture_dates.size() - 1 ].day = dayC ;
									copyCourses[j].lecture_dates[ copyCourses[j].lecture_dates.size() - 1 ].hourB = hour2;
									copyCourses[j].lecture_dates[ copyCourses[j].lecture_dates.size() - 1 ].hourE = hour2 + hour1;
									sumHours +=  hour1 ;
								}
							}
						}
					}
				}
			}
			else{
				for( unsigned int i=0; i<thevLecturer.size(); i++ ){
					vector<Course>& copyCourses = thevLecturer[i].get_vCourses();
					for ( unsigned int j = 0; j<copyCourses.size() ; j++){
						if( copyCourses[j].id == getId ){
							if( copyCourses[j].lecture_dates.size() == 0 ){
								sumHours=0;
								while ( sumHours == copyCourses[j].total_hours ){
									approval=0;
									rand_num = ( rand() % 5 ) + 1 ;
									if( 1 == rand_num){
										dayC = "Mon";
									}
									else if(2 == rand_num){
										dayC = "Tue";
									}
									else if(3 == rand_num ){
										dayC = "Wed";
									}
									else if(4 == rand_num ){
										dayC = "Thu";
									}
									else if(5 == rand_num ){
										dayC = "Fri";
									}
									hour1 = ( rand() % ( copyCourses[j].total_hours - sumHours ) ) + 1;
									hour2 = ( rand() % ( 9 - hour1 ) ) +  9  ;
									for ( unsigned int k=0; k<copyCourses.size() ; k++){
										if( copyCourses[k].lecture_dates.size() != 0 ){
											for( unsigned int t=0; t<copyCourses[k].lecture_dates.size(); t++ ){
												if( dayC == copyCourses[k].lecture_dates[t].day ){
													for( int r=hour2; r<hour2+hour1; r++){
														for( int l = copyCourses[k].lecture_dates[t].hourB ; l<copyCourses[k].lecture_dates[t].hourE ; l++){
															if( r == l){
																approval++;
															}
														}
													}
												}
											}	
										}
									}
									if( approval == 0) {
										copyCourses[j].lecture_dates.push_back( date() );
										copyCourses[j].lecture_dates[ copyCourses[j].lecture_dates.size() - 1 ].day = dayC ;
										copyCourses[j].lecture_dates[ copyCourses[j].lecture_dates.size() - 1 ].hourB = hour2;
										copyCourses[j].lecture_dates[ copyCourses[j].lecture_dates.size() - 1 ].hourE = hour2 + hour1;
										sumHours +=  hour1 ;
									}
								}
							}
							else{
								cout<<"Assigned before ("<<getId<<") "<<copyCourses[j].name<<" ";
								for(unsigned int k =0; k< copyCourses[j].lecture_dates.size(); k++){
									cout<<copyCourses[j].lecture_dates[k].day<<"_";
									cout<<copyCourses[j].lecture_dates[k].hourB<<"-"<<copyCourses[j].lecture_dates[k].hourB;
									if( k>1)
										cout<<",";
								}
							}
						}

					}
				}
				if ( count == 0 ){
					cout<<"Error: no course"<<endl;
				}

			}


		}
		else {
			cout<<"lecture  have not  assigned yet "<<endl;
		}



	}

	void Administrator::arrangeClassroom( const vector<Lecturer>& thevLecturer , vector<Classroom>& thevClassroom , int getId , string getC1  , string getC2  ){
		vector<Lecturer> theCopy = thevLecturer ;
		srand( time(nullptr));
		int number=0 , search=0 ;
		int rand_num1 = 0 , rand_num2 = 0 , rand_num3 = 0 ;
		int count = 0;
		for ( unsigned int i = 0; i<theCopy.size() ; i++){
			for( unsigned int j=0; j<theCopy[i].get_vCourses().size( ); j++)
			{
				if( theCopy[i].get_vCourses()[j].lecture_dates.size() == 0 ){
					count++;
				}
			}
			if( theCopy[i].get_vCourses().size() == 0 ){
				count++;
			}
			
		}
		
		if ( count == 0){
			if( getId == 0 ){
				while( theCopy.size() != 0 ){
					search = 0;
					
					rand_num1 = rand() % thevClassroom.size() ;
					rand_num2 = rand() % theCopy.size();
					rand_num3 = rand() % theCopy[rand_num2].get_vCourses().size() ;

					if( thevClassroom[rand_num1].get_cCourses().size() == 0 ){
						thevClassroom[rand_num1].get_cCourses().push_back( theCopy[rand_num2].get_vCourses()[rand_num3] ) ;
						theCopy[rand_num2].get_vCourses().erase( theCopy[rand_num2].get_vCourses().begin() +  rand_num3 );
						if( theCopy[rand_num2].get_vCourses().size() == 0){
							theCopy.erase( theCopy.begin() + rand_num2 );
						}
					}
					else{
						for( unsigned int i =0 ; i< thevClassroom[rand_num1].get_cCourses().size(); i++){
							for( unsigned int j =0 ; j<thevClassroom[rand_num1].get_cCourses()[i].lecture_dates.size(); j++){
								for( unsigned int k=0; k< theCopy[rand_num2].get_vCourses()[rand_num3].lecture_dates.size(); k++ ){
									if( thevClassroom[rand_num1].get_cCourses()[i].lecture_dates[j].day == theCopy[rand_num2].get_vCourses()[rand_num3].lecture_dates[k].day ){
										for( int l = thevClassroom[rand_num1].get_cCourses()[i].lecture_dates[j].hourB ; l < thevClassroom[rand_num1].get_cCourses()[i].lecture_dates[j].hourE; l++){
											for( int m = theCopy[rand_num2].get_vCourses()[rand_num3].lecture_dates[k].hourB; m < theCopy[rand_num2].get_vCourses()[rand_num3].lecture_dates[k].hourE ; m++ ){
												if( l == m){
													search ++ ;
												}
											}
										}
									}
								}
							}
						}

						if( search == 0 ){
							thevClassroom[rand_num1].get_cCourses().push_back( theCopy[rand_num2].get_vCourses()[rand_num3] ) ;
							theCopy[rand_num2].get_vCourses().erase( theCopy[rand_num2].get_vCourses().begin() +  rand_num3 );
							if( theCopy[rand_num2].get_vCourses().size() == 0){
								theCopy.erase( theCopy.begin() + rand_num2 );
							}
						}

					}
				}
				
			}
			else{
				if( getC2 == ""){
					for( unsigned int i =0; i<thevLecturer.size(); i++){
						if( thevLecturer[i].get_personal_id() != getId){
							search++;
						}

					}
					for( unsigned int i=0; i<thevClassroom.size(); i++){
						if( thevClassroom[i].get_c_no() != getC1 ){
							search++;
						}
					}
					if( search != 0){
						cout<<"Error: no class or no course"<<endl;
					}
				}
			}

		}
		else{
			cout<<"timetable not arranged yet"<<endl;
		}

	}

}