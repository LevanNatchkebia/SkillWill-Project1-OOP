#include <iostream>

using namespace std;

class AbstractSkillwill {
    string name;
    string lastname;
    string subject;
    public: 
    AbstractSkillwill() {
        name = "default_name";
        lastname = "default_lastname";
        subject = "default_subject";
    }
    AbstractSkillwill (string name, string lastname, string subject) {
        this->name = name;
        this-> lastname = lastname;
        this-> subject = subject;
    }
    string getname (){
        return name;
    }
    void setname(string name){
        this->name = name;
    }
    string getlastname () {
        return lastname;
    }
    void setlastname (string lastname) {
        this->lastname = lastname;
    }
    string getsubject(){
        return subject;
    }
    void setsubject (string subject){
        this-> subject = subject;
    }
    
};

class AbstractSubject {
    protected:
    string lesson;
    string date;
    public: 
    string name;
    string duration;
    
    void namedur (string name, string duration, string date) {
          cout << "Name of subject: " << name << endl;
          cout << "duration: " << duration << endl;
          cout << "Starting date: " << date << endl;
      }
    
    
    string getlesson(){
        return lesson;
    }
    void setlesson(string lesson) {
        this->lesson = lesson;
    }
    string getdate() {
        return date;
    }
    void setdate(string date) {
        this->date = date;
    }
    
    
    string info [3][4] = {{"17/02/23", "sql", "Nugo", "Mchedlishvili"},
                            {"19/02/23","git", "Lika", "Sikharulia"},
                            {"20/02/23", "wordpress", "Nika", "Kublashvili"}};
    
     void lecture ( string date,string lesson) {
            cout << "Enter date: ";
            cin >> date ;
            cout << "Enter lesson: ";
            cin >> lesson;
        for (int i=0; i<3; i++) {
            if (date==info[i][0] && lesson==info[i][1]){
                cout<<info[i][2]<<" "<<info[i][3]<<endl;
                break;
            }
            else {
                cout<<"Enter The correct properties"<<endl;
                break;
            }
            
        }
    }
};

class SkillwillLecturer: public AbstractSkillwill {
    public:
    string chapter;
    string level;
    
    SkillwillLecturer (string name, string lastname, string subject, string chapter, string level): AbstractSkillwill (name, lastname, subject) {
       this-> chapter = chapter;
       this-> level = level;
    }
     SkillwillLecturer():AbstractSkillwill(){
        string chapter = "default_chapter";
       
        string level = "default_level";
    }
    
    string lecturer[3][5]={{"Lika", "Sikharulia", "Git", "PHP", "Senior Developer"},
                            {"Nugo","Mchedlishvili", "SQL","Python", "Middle level Developer"},
                            {"Nika", "Kublashvili", "Wordpress", "Wordpress", "Senior Developer"}};
    
   
   void lecturerinfo (string name, string lastname) {
       cout<<"Get info about lecturers chapter and level"<<endl;
       cout<<"=========================================="<<endl;
       cout<<"Enter Lecturer's Name: ";
       cin>>name;
       cout<<"Enter Lecturer's Lastname: ";
       cin>>lastname;
       for(int i=0; i<3; i++) {
           if (name==lecturer[i][0] && lastname==lecturer[i][1]) {
               cout<<"Chapter: "<<lecturer[i][3]<<endl;
               cout<<"Level: "<<lecturer[i][4]<<endl;
           }
       }
   }
    void explaining (string explaining) {
        cout<<"The lecturer conducts a lecture."<<endl;
    }
};

class SkillwillStudent: public AbstractSkillwill {
    public: 
    string section;
    int age;
    int score;
    string course;

    SkillwillStudent():AbstractSkillwill(){
        section = "default_section";
        age = 0;
        score = 0;
        string course = "default_course";
    }
    
    SkillwillStudent (string name, string lastname, string subject, string section, int age, int score, string course): AbstractSkillwill (name, lastname, subject) {
        this->section = section;
        this->age = age;
        this->score = score;
        this-> course = course;
        
    }
    
   
};
 void attend (SkillwillStudent students[]) {
        string name, lastname, course, section;
        int score, age;
        cout<<"Enter student name: ";
        cin>>name;
        cout<<"Enter student lastname: ";
        cin>>lastname;
        cout<<"Enter the course: ";
        cin>>course;
        cout<<"Section: b"<<endl;
        cout<<"Score is: 100"<<endl;
        
        
        for(int i=0; i<6; i++) {

            if (name==students[i].getname() && lastname == students[i].getlastname() && course==students[i].course) {
                cout<<section<<endl;
                cout<<name<<" is attending "<<course<<endl;
                return;
            }
        }
        cout<<name<<" is not attending "<<course<<endl;
    }


int main()
{
  AbstractSubject showdata;
      showdata.lecture("date", "lesson");
    showdata.namedur("python", "1month", "21/09/22");

    SkillwillStudent *students = new SkillwillStudent[6];
    students[0] = SkillwillStudent ("mamuka", "bzhalava", "python", "b-section", 29, 100, "python");
    students[1] = SkillwillStudent ("levan", "natchkebia", "react", "b-section", 23, 100, "web-development");
    students[2] = SkillwillStudent ("davit"," madzgharashvili", "react", "b-section", 32, 100, "web-development");
    students[3] = SkillwillStudent ("natia", "salukvadze", "react", "b-section", 26, 100, "web-development");
    students[4] = SkillwillStudent ("reziko", "natchkebia", "react", "b-section", 18, 100, "web-development");
    students[5] = SkillwillStudent ("anano", "edzgveradze", "python", "b-section", 21, 100, "python");
    attend(students);
    SkillwillLecturer lecturer;
    lecturer.lecturerinfo("name", "lastname");
    lecturer.explaining("lecture");
    
    return 0;
}