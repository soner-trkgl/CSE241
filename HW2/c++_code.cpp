#include<iostream>
#include<vector>
#include<string>
#include<fstream>


/* Author : Soner Türkoðlu
 *
 *
 *
 */

using namespace std;

struct Course{
	int id;
	string name;
	int code;
	int credit;
	int total_hours;
	string lecture_dates;
	string field;
};

struct Classroom{
	int c_no;
	string  id;
	int capacity;
	int student_inroom;
};

class Student{
	public:
		Student(string ,string,int,int);
		Student();
		string get_name()const;
		string get_surname()const;
		int get_student_no()const;
		int enrollCourse(const Course&);
		int disenroll(const Course&);
		string exractSchedule()const;
		void enterClassroom(Classroom&);
		void quitClassroom(Classroom&);

	private:
		string name;
		string surname;
		int student_no;
		int level;
		int creditRight;
		vector<string> lectureName;
		
};



int main(){
	
	int i=0;
	int count=0;
	int controlInt;
	int i_student_no,i_level;
	string s_name,s_surname,s_student_no,s_level;
	string controlString;
	string word;
	fstream file;

	vector<Course>course;					// vector for course , class , student
	vector<Classroom> classroom;
	vector<Student> student;

	char x='a';								// getting a character terminal



	file.open("courses_classrooms.txt",ios::in);					// read the file and register course and classroom
	file>>word;
	if(word == "COURSES" || word == "CLASSROOMS"){ 
		if(word == "COURSES"){
			file>>word;
			while(word != "CLASSROOMS"){
				course.push_back(Course());
				course[count].id=stoi( word );
				file>>word;
				course[count].name=word;
				file>>word;
				course[count].code=stoi( word );
				file>>word;
				course[count].credit=stoi( word );
				file>>word;
				course[count].total_hours=stoi( word );
				file>>word;
				course[count].lecture_dates=word;
				file>>word;
				++count;
			}

		}
		if(word == "CLASSROOMS"){
			count=0;
			while(file>>word){
				classroom.push_back( Classroom() );
				classroom[count].c_no=stoi( word.c_str() );
				file>>word;
				classroom[count].id=word;
				file>>word;
				classroom[count].capacity=stoi( word.c_str() );
				++count;
			}
		}
		
	}
	else {
		cout<<"There is no classrooms and courses"<<endl;
	}
	
	
	file.close();
	
	cout<<"Enter your test scenarios: "<<endl;						//  getting the input from user
	while (x != 'o'){
		getline(cin,word);
		x=word[1];
		switch (x){

			case 'n':
				count=0;
				i=4;
				while(i<word.length()){
					s_name+=word[i];
					i++;
					if(word[i] == ' '){
						break;
					}
				}
				while(i<word.length() ){
					s_surname+=word[i];
					i++;
					if(word[i] == ' '){
						break;
					}
				}
				while(i<word.length() ){
					s_student_no+=word[i];
					i++;
					if(word[i] == ' '){
						break;
					}
				}
				i_student_no=stoi( s_student_no );
				while(i<word.length() ){
					s_level+=word[i];
					i++;
					if(word[i] == ' '){
						break;
					}
				}
				i_level=stoi( s_level.c_str() );
				student.push_back( Student( s_name, s_surname, i_student_no, i_level ) );
				s_name.clear();
				s_surname.clear();
				s_student_no.clear();
				s_level.clear();
				break;

			case 'l':
				for(unsigned int j=0; j < course.size(); j++){
					cout<<" ("<< course[j].id <<") " << course[j].name <<" ";
				}
				cout<<endl;
				break;

			case 'e':
				i=3;
				count=0;
				while ( word[i] != ' ')
				{
					controlString+=word[i];
					i++;
				}
				controlInt=stoi(controlString);
				for (int j = 0; j < student.size(); ++j)
				{
					if(student[j].get_student_no() == controlInt){
						controlString.clear();
						i++;
						while(word[i] != '\0'){
							controlString+=word[i];
							i++;
						}
						controlInt=stoi(controlString);
						for(int k=0; k<course.size(); k++){
							if(course[k].id == controlInt){
								student[j].enrollCourse(course[k]);
							}
						}
						count++;
					}
				}
				if(count == 0){
					cout<<"BLOCK! because there is no student"<<endl;
				}
				controlString.clear();
				break;

			case 'd':
				i=4;
				count=0;
				controlString.clear();
				while ( word[i] != ' ')
				{
					controlString+=word[i];
					i++;
				}
				controlInt=stoi(controlString);
				controlString.clear();
				for (int j = 0; j < student.size(); ++j)
				{
					if(student[j].get_student_no() == controlInt){
						i++;
						while(word[i] != '\0'){
							controlString+=word[i];
							i++;
						}
						controlInt=stoi(controlString);
						for(int k=0; k<course.size(); k++){
							if(course[k].id == controlInt){
								student[j].disenroll(course[k]);
							}
						}
						count++;
					}
				}	
				if(count == 0){
					cout<<"BLOCK! because there is no student"<<endl;
				}
				controlString.clear();
				break;
			case 'o':
				i=0;
				count =0;
				while( word[i] !='\0'){
					i++;
					while(word[i] != ' ' && word[i] != '\0'){
						i++;
					}	
					count++;
				}

				if(count == 1){
					for(i=0; i<student.size(); i++){
						cout<<student[i].exractSchedule()<<endl;
					}
				}
				else if(count == 2){
					i=3;
					controlString.clear();
					while( word[i] != '\0'){
						controlString += word[i];
						i++;
					}
					controlInt=stoi( controlString );
					
					for(unsigned int j =0; j<student.size(); j++){
						if(student[j].get_student_no() == controlInt)
							cout<<student[j].exractSchedule()<<endl;
					}

				}
				else if (count == 3){
					i=6;
					controlString.clear();
					while(word[i] != '\0'){
						controlString+=word[i];
						i++;
					}
					file.open(controlString.c_str() , ios::out);
					for(i=0; i<student.size(); i++)
						file<<student[i].exractSchedule()<<endl;
					file.close();

				}
				else{
					i=6;
					controlString.clear();
					while(word[i] != ' '){
						controlString+=word[i];
						i++;
					}
					controlInt=stoi( controlString );
					controlString.clear();
					i++;
					while(word[i] != '\0'){
						controlString+=word[i];
						i++;
					}
					for(i=0; i<student.size(); i++){
						if(student[i].get_student_no() == controlInt){
							file.open(controlString.c_str() , ios::out);
							file<<student[i].exractSchedule()<<endl;
							file.close();
						}	
					}

				}
				break;
			default:
				return 0;

		}
	}
	


	return 0;
}

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

Student::Student(){
	name="Soner";
	surname="Soner";
	student_no=100;
	level=1;
}

string Student::get_name()const{
	return name;
}
string Student::get_surname()const{
	return surname;
}
int Student::get_student_no()const{
	return student_no;
}

int Student::enrollCourse(const Course& c){
	string takeLecture;
	string temp,temp1;
	string compareLecture;
	string dayGet,hours;
	int hours1Get,hours2Get;
	string dayCom;
	int hours1Com,hours2Com;
	int i=0 , j =0,k=0;
	int count=0;
	int total_hours=0;

	takeLecture=c.name + "(" + to_string( c.credit ) + ") " + c.lecture_dates;
	for(int i=0; i<lectureName.size(); i++){
		if( lectureName[i] == takeLecture){
			cout<<"can not take because of second taking"<<endl;
			return creditRight;
		}
		
	};
	if(creditRight-c.credit < 0){
		cout<<"can not take because of credit not sufficient"<<endl;
		return creditRight;
	}
	
	for( i=0; i<lectureName.size(); i++){
		temp=c.lecture_dates;
		count=0;
		total_hours=0;
		while( temp[j] !='\0'){
			total_hours=0;
			dayGet.clear();
			hours.clear();
			k=0;
			j++;
			compareLecture.clear();
			while( temp[j] != '_'){
				dayGet+=temp[j];
				j++;
			}
			j++;
			while( temp[j] != '-' ){
				hours+=temp[j];
				j++;
			}
			hours1Get=stoi( hours );
			j++;
			hours.clear();
			while( temp[j] != ',' && temp[j] != '\0'){
				hours+=temp[j];
				j++;
			}
			hours2Get=stoi( hours );
			hours.clear();
			total_hours+=( hours2Get - hours1Get );
			temp1=lectureName[i];
			while(temp1[k] != ' '){
					k++;
			}
			k++;
			while(temp1[k] != '\0'){
				compareLecture+=temp1[k];
				k++;
			}
			temp1.clear();
			k=0;
			while( compareLecture[k] != '\0'){
				dayCom.clear();
				k++;
				while(compareLecture[k] != '_'){
					dayCom+=compareLecture[k];
					k++;
				}
				k++;
				while(compareLecture[k] != '-'){
					hours+=compareLecture[k];
					k++;
				}
				hours1Com=stoi( hours );
				k++;
				hours.clear();
				while(compareLecture[k] != ',' && compareLecture[k] != '\0'){
					hours+=compareLecture[k];
					k++;
				}
				hours2Com=stoi( hours );
				hours.clear();
				k++;
				if( dayGet == dayCom){
					for(int a=hours1Get +1; a<=hours2Get; a++){
						for(int b=hours1Com+1; b<hours2Com; b++){
							if(a == b)
								count++;
						}
					}
				}
			}
			count=0;

		}
		if( ( total_hours / 2 ) < count){
			cout<<"BLOCK! can not take because of overlap"<<endl;
			return creditRight;
		}
	}
	lectureName.push_back(takeLecture);
	creditRight-=c.credit;
	cout<<"DONE!"<<endl;
	return creditRight;

}

int Student::disenroll(const Course& c){
	int index=0;
	string temp,result;
	
	for(int i=0; i<lectureName.size(); i++){
		temp=lectureName[i];
		int j=0;
		while(temp[j] != '('){
			result+=temp[j];
			j++;
		}
		if(result == c.name){
			index=j;
		}
	}
	lectureName.erase( lectureName.begin() + index);
	cout<<"DONE!"<<endl;
	return creditRight + c.credit;
}
string Student::exractSchedule()const{
	string output;
	string temp;
	int j=0;
	output=name + " " + surname + ": [";
	for (int i = 0; i < lectureName.size(); ++i)
	{
		j=0;
		output+= " ";
		temp=lectureName[i];
		while(temp[j] != ' '){
			output+=temp[j];
			j++;
		}
		 output+=" ";
	}
	output+="] ";
	if(level == 1)
		output+= "total credits:" + to_string(20-creditRight) + " credit right: " + "20";
	else if(level == 2)
		output+= "total credits:" + to_string(21-creditRight) + " credit right: " + "21";
	else if(level == 3)
		output+= "total credits:" + to_string(22-creditRight) + " credit right: " + "22";
	else
		output+= "total credits:" + to_string(23-creditRight) + " credit right: " + "23";

	return output;

}
void Student::enterClassroom(Classroom& c){
	c.student_inroom+=1;
}
void Student::quitClassroom(Classroom& c){
	c.student_inroom-=1;
}
