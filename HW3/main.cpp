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
	Administrator leader;
	string readWord , sortWord;
	int count=0 , i =0 ;

	ifstream inStream;
	inStream.open("lecturers.txt");


	if( !inStream.is_open() ){
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
					vClassroom[count].id = stoi( readWord );
					inStream>>readWord;
					vClassroom[count].c_no = readWord;
					inStream>>readWord;
					vClassroom[count].capacity = stoi ( readWord );
					inStream>>readWord;
					count++;
				}
			}
			else
				cout<<"there is no classrooms and courses in txt"<<endl; 
		}

		
	}
	inStream.close();



	cout<<"Enter your test scenario"<<endl;
	readWord="entrey";
	while ( readWord != "exit"){
		getline( cin, readWord);
		sortWord.clear();
		i=0;
		while( readWord[i] != ' ' && readWord[i] != '\0'){
			sortWord += readWord[i];
			i++;
		}
		count=0;
		if ( sortWord == "propose"){

			sortWord.clear();
			i++;
			while( readWord[i] != ' '){
				sortWord += readWord[i];
				i++;
			}
			for( unsigned int j=0; j<vLecturer.size(); j++){
				if( vLecturer[j].get_personal_id() == stoi ( sortWord )){
					vLecturer[j].proposeCourse( readWord );
					count++;
				}
			}
			if( count == 0){
				cout<<"Error: no lecturer id"<<endl;
			}
			
		}
		else if( sortWord == "assign"){

			sortWord.clear();
			i=0;
			count=0;
			while ( readWord[i] != '\0'){
				while ( readWord[i] != ' ' &&  readWord[i] != '\0')
					i++;
				count++;
				if( readWord[i] != '\0')
					i++;
			}
			if ( count == 1){
				for( unsigned int j=0; j<vLecturer.size() ; j++){
					vLecturer[j].assignCourse( vCourse );
				}
			}
			else if ( count == 3){
				i=0;
				count=0;
				while ( readWord[i] != ' ')
					i++;
				i++;
				while ( readWord[i] != ' '){
					sortWord += readWord[i];
					i++;
				}
				int x = stoi ( sortWord );
				for ( unsigned int j=0; j<vLecturer.size() ; j++){
					if ( vLecturer[j].get_personal_id() ==   x ){
						i++;
						sortWord.clear();
						while ( readWord[i] != '\0'){
							sortWord += readWord[i];
							i++;
						}
						vLecturer[j].assignCourse( vCourse , stoi( sortWord ) );
						count++;
					}
				}
				if( count == 0){
					cout<<"Error: no lecturer"<<endl;
					
				}
	
			}
			else 
				cout<<"Wrong entry";
		}
		else if( sortWord ==  "timetable"){
			sortWord.clear();
			i=0;
			count=0;
			while ( readWord[i] != '\0'){
				while ( readWord[i] != ' ' &&  readWord[i] != '\0')
					i++;
				count++;
				if( readWord[i] != '\0')
					i++;
			}
			if( count == 1){
				leader.arrangeTimeTable( vLecturer);
			}
			else if( count == 2){
				i=0;
				while( readWord[i] != '\0' ){
					sortWord.clear();
					while ( readWord[i] != ' ' &&  readWord[i] != '\0'){
						sortWord +=readWord[i];
						i++;
					}
					if( readWord[i] != '\0')
						i++;
				}
				leader.arrangeTimeTable( vLecturer , stoi( sortWord ) );
			}
			else{
				cout<<"Wrong entry";
			}
			for( unsigned int j=0; j<vLecturer.size(); j++ ){
				for( unsigned int  k =0; k<vLecturer[j].get_vCourses().size(); k++){
					cout<<vLecturer[j].get_vCourses()[k].name<<" ";
					for( unsigned int l=0; l<vLecturer[j].get_vCourses()[k].lecture_dates.size() ; l++){
						vector<date>& copy =vLecturer[j].get_vCourses()[k].lecture_dates;
						cout<<copy[l].day<<"_"<<copy[l].hourB<<"-"<<copy[l].hourE<<" ";
					}
					cout<<endl;
					
				}
			}

		}
		else if(  sortWord == "arrangeC"){
			sortWord.clear();
			i=0;
			count=0;

			while ( readWord[i] != '\0'){
				while ( readWord[i] != ' ' &&  readWord[i] != '\0' && readWord[i] != ',')
					i++;
				count++;
				if( readWord[i] != '\0')
					i++;
			}
			if( count == 1){
				leader.arrangeClassroom( vLecturer , vClassroom );
				for( unsigned int j=0; j<vLecturer.size(); j++ ){
				for( unsigned int  k =0; k<vLecturer[j].get_vCourses().size(); k++){
					cout<<vLecturer[j].get_vCourses()[k].name<<" ";
					for( unsigned int l=0; l<vLecturer[j].get_vCourses()[k].lecture_dates.size() ; l++){
						cout<<"in "<<vLecturer[j].get_vCourses()[k].c_name[0]<<" "<<"at ";
						vector<date>& copy =vLecturer[j].get_vCourses()[k].lecture_dates;
						cout<<copy[l].day<<"_"<<copy[l].hourB<<"-"<<copy[l].hourE<<" ";
					}
					cout<<endl;
					
				}
			}

			}
			else if( count == 3){
				sortWord.clear();
				i=0;
				while ( readWord[i] != ' '){
					i++;
				}
				i++;
				while ( readWord[i] != ' '){
					sortWord += readWord[i] ;
					i++;
				}
				int getid = stoi( sortWord );
				sortWord.clear();
				i++;
				while ( readWord[i] != '\0'){
					sortWord += readWord[i] ;
					i++;
				}
				leader.arrangeClassroom( vLecturer , vClassroom , getid , sortWord );
			}
			else if( count == 4){
				sortWord.clear();
				i=0;
				while ( readWord[i] != ' '){
					i++;
				}
				i++;
				while ( readWord[i] != ' '){
					sortWord += readWord[i] ;
					i++;
				}
				int getid = stoi( sortWord );
				sortWord.clear();
				i++;
				while ( readWord[i] != ','){
					sortWord += readWord[i] ;
					i++;
				}
				string getc = sortWord ;
				sortWord.clear();
				i++;
				while ( readWord[i] != '\0'){
					sortWord += readWord[i] ;
					i++;
				}
				leader.arrangeClassroom( vLecturer , vClassroom , getid, getc , sortWord  );

			}
			else
				cout<<"wrong entry"<<endl;	

		}
		else if( sortWord == "exit"){

		}
		else {
			cout<<"wrong entry"<<endl;	
		}
	
	}



	return 0;
		
}