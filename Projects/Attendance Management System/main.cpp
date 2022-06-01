#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

int admin_view();
int student_view();
int student_login();
int check_credentials(string username, string password);
int get_all_students_by_rollno();
int delete_all_students();
int delete_all_students_by_rollno();
int check_list_of_students_registered();
int check_presence_count_by_rollno();
int get_list_of_students_with_their_presence_count();
int register_student();
int admin_login();
int mark_my_attendance(string username);
int count_my_attendance(string username);
int delay();

int delay(){
    for(int i=0;i<3;i++){
        for(int j=0;j<1000;j++){
            for(int k=0;k<1000;k++){

            }
        }
    }
    cout<<"\n Exiting Now....";
    for(int i=0;i<3;i++){
        for(int j=0;j<1000;j++){
            for(int k=0;k<1000;k++){

            }
        }
    }
    return 0;
}

int admin_view(){
    int goBack = 0;
    while(1){

        system("cls");
        cout<<"\n 1. Register a Student";
        cout<<"\n 2. Delete all Students Registered";
        cout<<"\n 3. Delete Student by Roll Number";
        cout<<"\n 4. Check list of Student Registered by Username";
        cout<<"\n 5. Check Presence Count of any Student by Username";
        cout<<"\n 6. Get the list of Students with their Attendance count";
        cout<<"\n 0. Go Back<-\n";

        int Choice;
        cout<<"\n Enter your Choice: ";
        cin>>Choice;

        switch(Choice)
        {
        case 1:
            register_student();
            break;
        case 2:
            delete_all_students();
            break;
        case 3:
            delete_all_students_by_rollno();
            break;
        case 4:
            check_list_of_students_registered();
            break;
        case 5:
            check_presence_count_by_rollno();
            break;
        case 6:
            get_list_of_students_with_their_presence_count();
            break;
        case 0:
            goBack = 1;
            break;
        default:
            cout<<"\n Invalid Choice. Enter again";
            getchar();
        }
        if(goBack == 1){
            break;
        }
    }
     return 0;
}

int student_login(){
    system("cls");
    student_view();
    delay();
    return 0;
}

int admin_login(){
    system("cls");
    cout<<"\n----------- Admin Login -----------";
    string username, password;
    cout<<"\n Enter Username: ";
    cin>>username;
    cout<<"\n Enter Password: ";
    cin>>password;
    if(username == "admin" && password == "admin@2"){
        admin_view();
        getchar();
        delay();
    }
    else{
        cout<<"\n Error! Invalid Credentials.....";
        cout<<"\n Press any key for Main menu";
        getchar();
    }
    return 0;
}

int check_credentials(string username, string password){
    ifstream read;
    read.open("db.txt");
    if(read){
        int recordFound=0;
        string line;
        string temp = username + password + ".txt";
        cout<<"\n File name is: "<<temp;
        while(getline(read, line)){
            if(line==temp){
                recordFound = 1;
                break;
            }
        }
        if(recordFound == 0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}

int get_all_students_by_name(){
    cout<<"\n List of all Students by their Name\n";
    cout<<"\n Press any key to continue....";
    getchar();
    getchar();
    return 0;
}

int get_all_students_by_rollno(){
    cout<<"\n List of all Students by their Roll Number\n";
    cout<<"\n Press any key to continue....";
    getchar();
    getchar();
    return 0;
}

int delete_all_students_by_rollno(){
    cout<<"\n Delete any Student by their Roll Number";
    cout<<"\n Press any key to continue....";
    getchar();
    getchar();\
    return 0;
}

int check_presence_count_by_rollno(){
    cout<<"\n Check Presence count of any student by Roll Number no.\n";
    cout<<"\n Press any key to continue....";
    getchar();
    getchar();
    return 0;
}

int check_all_presence_count_by_rollno(){
    cout<<"\n Check Presence count of all student by Roll Number no.\n";
    cout<<"\n Press any key to continue....";
    getchar();
    getchar();
    return 0;
}

int student_view(){
    cout<<"\n----------- Student Login -----------";
    string username, password;
    cout<<"\n Enter Username: ";
    cin>>username;
    cout<<"\n Enter Password: ";
    cin>>password;

    int res = check_credentials(username, password);
    if(res == 0){
        cout<<"\n Invalid Credentials! ";
        cout<<"\nPress any key for Main menu....";
        getchar();
        getchar();
        return 0;
    }
    int goBack=0;
    while(1){
        system("cls");
        cout<<"\n 1. Mark Attendance for Today";
        cout<<"\n 2. Count My Attendance";
        cout<<"\n 0. Go Back <-\n";
        int Choice;
        cout<<"Enter your Choice: ";
        cin>>Choice;

        switch(Choice)
        {
        case 1:
            mark_my_attendance(username);
            break;
        case 2:
            count_my_attendance(username);
            break;
        case 3:
            goBack=1;
            break;
        default:
            cout<<"\n Invalid Choice. Enter Again";
            getchar();
        }
        if(goBack==1){
            break;
        }
    }
}

int mark_my_attendance(string username){
    cout<<"\n Mark My Attendance for Today";
    cout<<"\n Press any key to continue....";
    getchar();
    getchar();
    return 0;
}

int count_my_attendance(string username){
    cout<<"\n Count My Attendance for Today";
    cout<<"\n Press any key to continue....";
    getchar();
    getchar();
    return 0;
}

int delete_all_students(){
    cout<<"\n Delete all Students!!";
    cout<<"\n Press any key to continue....";
    getchar();
    getchar();
    return 0;
}

int check_list_of_students_registered(){
    cout<<"\n List of all Students Registered ";
    cout<<"\n Press any key to continue....";
    getchar();
    getchar();
    return 0;
}

int get_list_of_students_with_their_presence_count(){
    cout<<"\n Check list of Students Registered by Username";
    ifstream read;
    read.open("db.txt");

    if(read){
        int recordFound = 0;
        string line;
        while(getline(read, line)){
            char name[100];
            strcpy(name, line.c_str());
            char onlyname[100];
            strncpy(onlyname, name,(strlen(name)-4));
            cout<<"\n"<<onlyname;
        }
        read.close();
    }
    else{
        cout<<"\n No Record Found!! ";
    }
    cout<<"\n Press any key to continue....";
    getchar();
    getchar();
    return 0;
}

int register_student(){
    cout<<"\n-----------Form to Register Student-----------";
    string name, username, password, rollno, address, father, mother;
    cout<<"\n Enter Name: ";
    cin>>name;
    cout<<"\n Enter Password: ";
    cin>>password;
    cout<<"\n Enter Roll No.: ";
    cin>>rollno;
    getchar();
    char add[100];
    cout<<"\n Enter Address: ";
    cin.getline(add, 100);
    cout<<"\n Enter Father's Name: ";
    cin>>father;
    cout<<"\n Enter Mother's Name: ";
    cin>>mother;

    ifstream read;
    read.open("db.txt");
    if(read){
        int recordFound=0;
        string line;
        while(getline(read, line)){
            if(line==username+".txt")
            {
               recordFound=1;
               break;
            }
        }
        if(recordFound==1){
            cout<<"\n Username already registered. Please choose another Username";
            getchar();
            getchar();
            read.close();
            return 0;
        }
    }
    read.close();
    ofstream out;
    out.open("db.txt", ios::app);
    out<<username+".txt"<<"\n";
    out.close();

    ofstream out1;
    string temp = username+".txt";
    out1.open(temp.c_str());
    out1<<name<<"\n";
    out1<<username <<"\n";
    out1<<password<<"\n";
    out1<<rollno<<"\n";
    out1<<add<<"\n";
    out1<<father<<"\n";
    out1<<mother<<"\n";
    out1.close();

    cout<<"\n Student Registered Successfully! ";
    cout<<"\n Press any key to Continue....";
    getchar();
    getchar();
    return 0;
}

int main()
{
    while(1){
        system("cls");
        cout<<"\n Attendance Management System \n";
        cout<<"--------------------------------------\n";
        cout<<"1. Student Login\n";
        cout<<"2. Admin Login\n";
        cout<<"3. Exit\n";
        int choice;
        cout<<"\n Enter your Choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            student_login();
            break;
        case 2:
            admin_login();
            break;
        case 0:
            while(1){
                system("cls");
                cout<<"Do you want to Exit? (Y/N): ";
                char ex;
                cin>>ex;
                if(ex=='Y' || ex=='y'){
                    exit(0);
                }
                else if(ex=='N' || ex=='n'){
                    break;
                }
                else{
                    cout<<"\n Invalid Choice!!";
                    getchar();
                }
            }
            break;
        default:
            cout<<"\n Invalid Choice. Enter Again";
            getchar();
        }
    }
    return 0;
}
