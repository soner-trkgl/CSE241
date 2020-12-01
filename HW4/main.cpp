#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"arrangment.h"

using namespace std;
using namespace University;


int main(){

	vector<Lecturer> vLecturer;
	vector<Course> vCourse;
	vector<Classroom> vClassroom;
	vector<Student> vStudent;
	Administrator leader;
	string readWord , sortWord;
	int count=0 , i =0 ;

	ifstream inStream;
	inStream.open("lecturers.txt");


	if( !inStream.is_open() ){										// reading the txt file and constituting the object
		cout<<"file is not opened"<<endl;														  
	}
	else{
		inStream>>readWord;
		while( !inStream.eof() ){
			vLecturer.push_back( Lecturer() );
			vLecturer[count].set_personal_id( stoi (readWord) );
			inStream>>readWord;
			vLecturer[count].set_name( readWord );
			inStream>>readWord;
			vLecturer[count].set_surname( readWord );
			inStream>>readWord;
			vLecturer[count].set_title( readWord );
			inStream>>readWord;
			vLecturer[count].set_profession( readWord );
			inStream>>readWord;
			count++;
		}
		if ( count == 0){
			cout<<"there is no lecturer in txt"<<endl;
		}
	}
	
	inStream.close();

	inStream.open("courses_classrooms.txt");
	if( !inStream.is_open() ){
		cout<<"file is not opened"<<endl;
	}
	else{

		inStream>>readWord;
		while( !inStream.eof() ){
			if(readWord == "COURSES"){
				count=0;
				inStream>>readWord;
				while(readWord != "CLASSROOMS" && !inStream.eof() ){
					vCourse.push_back( Course() );
					vCourse[count].id = stoi( readWord );
					inStream>>readWord;
					vCourse[count].name = readWord;
					inStream>>readWord;
					vCourse[count].code = stoi( readWord );
					inStream>>readWord;
					vCourse[count].credit = stoi( readWord );  
					inStream>>readWord;
					vCourse[count].total_hours = stoi( readWord );
					inStream>>readWord;
					vCourse[count].field = readWord;
					vCourse[count].isMandatory = true;
					inStream>>readWord;
					count++; 
				}
					
			}
			else if ( readWord == "CLASSROOMS" ){
				count=0;
				inStream>>readWord;
				while( readWord != "COURSES" && !inStream.eof() ){
					vClassroom.push_back ( Classroom() );
					vClassroom[count].set_id( stoi( readWord ) ) ;
					inStream>>readWord;
					vClassroom[count].set_c_no( readWord ) ;
					inStream>>readWord;
					vClassroom[count].set_capacity( stoi ( readWord ) ) ;
					inStream>>readWord;
					count++;
				}
			}
			else
				cout<<"there is no classrooms and courses in txt"<<endl; 
		}																								

		
	}
	inStream.close();

	vLecturer[6].proposeCourse( "-propose 7 COMPUTER_PROGRAMMİNG 104 8 4 PROG" );				// for unsufficient lecture extra object
	vLecturer[6].proposeCourse( "-propose 7 PROGRAMMİNG_LANGUAGE 302 5 3 PROG" );
	vLecturer[6].proposeCourse( "-propose 7 MECMACH 402 6 4 MACH" );
	vLecturer[6].proposeCourse( "-propose 7 INSIDEMACH 222 3 2 MACH" );
	vLecturer[6].proposeCourse( "-propose 7 PROGRAMMİNG_METHODOLOGY 215 6 3 PROG" );

	for( unsigned int j=0; j<vLecturer.size() ; j++){											// for automatically assign lecture timetable and classroom
		vLecturer[j].assignCourse( vCourse );
	}

 	leader.arrangeTimeTable( vLecturer);														// for automatically timetable
	leader.arrangeClassroom( vLecturer , vClassroom );

	cout<<"                        ---------COURSE SCHEDULE----------"<<endl;

	for( unsigned int j=0; j<vLecturer.size(); j++ ){											// for automatically assign classroom
		for( unsigned int  k =0; k<vLecturer[j].get_vCourses().size(); k++){
			cout<<"course id : "<<vLecturer[j].get_vCourses()[k].id<<" "<<vLecturer[j].get_vCourses()[k].name<<" "<<"in"<<" ";
			for( unsigned int m = 0; m<vClassroom.size(); m++ ){
				for( unsigned int n = 0; n<vClassroom[m].get_cCourses().size(); n++ ){
					if( vClassroom[m].get_cCourses()[n].name == vLecturer[j].get_vCourses()[k].name)
						cout<<vClassroom[m].get_c_no();
				}
			}
			for( unsigned int l=0; l<vLecturer[j].get_vCourses()[k].lecture_dates.size() ; l++){
				vector<date>& copy =vLecturer[j].get_vCourses()[k].lecture_dates;
				cout<<" "<<"at"<<" "<<copy[l].day<<"_"<<copy[l].hourB<<"-"<<copy[l].hourE;
			}
			cout<<endl;			
		}
	}


	cout<<endl<<endl;																		// showing the menu
	cout<<"Enter your test scenario"<<endl;
	cout<<"-ns [name] [surname] [student_no] [level]                ( add new student ) "<<endl;
	cout<<"-enter [student_no] [classroom_c_no] [hour_of_week]        ( student enter classroom)"<<endl;
	cout<<"-quit [student_id]                                       ( student quit classroom)"<<endl;
	cout<<"-attendance [course_id]                                  ( student's attendance)"<<endl;
	cout<<"-exit                                                    ( terminate program ) "<<endl;
	readWord="entrey";
	count = 0;
	while ( readWord != "-exit"){													// getting input from user 
		getline( cin, readWord);
		sortWord.clear();
		i=0;
		while( readWord[i] != ' ' && readWord[i] != '\0'){
			sortWord += readWord[i];
			i++;
		}
		if ( sortWord == "-ns"){										
			sortWord.clear();
			i++;
			vStudent.push_back( Student() );
			while(readWord[i] != ' '){
				sortWord+=readWord[i];
				i++;	
			}
			vStudent[count].set_name( sortWord );
			i++;
			sortWord.clear();
			while(readWord[i] != ' '){
				sortWord+=readWord[i];
				i++;
			}
			vStudent[count].set_surname( sortWord );
			sortWord.clear();
			i++;
			while(readWord[i] != ' '){
				sortWord+=readWord[i];
				i++;
			}
			vStudent[count].set_student_no( stoi (sortWord) );
			sortWord.clear();
			i++;
			while(readWord[i] != '\0'){
				sortWord+=readWord[i];
				i++;
			}
			vStudent[count].set_level( stoi (sortWord) );
			count++;
		}
		else if( sortWord == "-enter"){
			sortWord.clear();
			i++;
			string cNo;
			int hour;
			int num = 0;
			int flag;
			while(readWord[i] != ' '){
				sortWord+=readWord[i];
				i++;	
			}
			for( unsigned int j = 0; j<vStudent.size(); j++){
				if( vStudent[j].get_student_no() == stoi( sortWord )){
					num++;
					flag = j;
				}
			}
			if( num == 0){
				cout<<"Error: no Student "<<endl;
			}
			else{
				sortWord.clear();
				i++;
				num=0;
				while(readWord[i] != ' '){
					sortWord+=readWord[i];
					i++;	
				}
				cNo=sortWord;
				i++;
				sortWord.clear();
				while(readWord[i] != '\0'){
					sortWord+=readWord[i];
					i++;	
				}
				hour = stoi( sortWord );
				vStudent[flag].enterClassroom( vClassroom , cNo , hour );
			}
			
			
		}
		else if( sortWord ==  "-quit"){
			sortWord.clear();
			i++;
			int flag;
			int num = 0;
			while(readWord[i] != '\0'){
				sortWord+=readWord[i];
				i++;	
			}
			for( unsigned int j = 0; j<vStudent.size(); j++){
				if( vStudent[j].get_student_no() == stoi( sortWord )){
					num++;
					flag = j;
				}
			}
			if( num == 0){
				cout<<"Error: no Student "<<endl;
			}
			else{
				vStudent[flag].quitClassroom( vClassroom , stoi(sortWord));
			}
		}
		else if(  sortWord == "-attendance"){
			sortWord.clear();
			i++;
			while(readWord[i] != '\0'){
				sortWord+=readWord[i];
				i++;	
			}
			takeAttendance( vClassroom , stoi(sortWord));
		}
		else if( sortWord == "-exit"){
		}
		else {
			cout<<"wrong entry"<<endl;	
		}
	
	}



	return 0;
		
}