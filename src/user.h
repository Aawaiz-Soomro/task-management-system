#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include "project.h"
#include "tasks.h"
using namespace std;
class Project;
const int MAX_PROJECTS=10;
const int MAX_NO_OF_USER_TASKS = 5;
class User {
    private:
    int user_id_;
    static int vacant_id_slots_ [10];
    static int vacant_id_slots_counter_;
    string user_name_;
    string user_email_;
    string user_password_;
    int project_count_;
    Task user_tasks [MAX_NO_OF_USER_TASKS];
    // Project user_projects[MAX_PROJECT_USERS];
    public:
    string user_role_;
    static int user_count_;
    int task_count_;

    User(string username,string email,string password):user_name_(username),user_email_(email),user_password_(password) {
        
        bool vacant_id_found = 0;
        for (int i=0; i<10 ; i++) 
        if ( vacant_id_slots_ [i] != 0 ) {
            user_id_ = vacant_id_slots_ [i] ;
            vacant_id_slots_ [i] = 0;
            vacant_id_found = 1;
            break;
        }
        if (!vacant_id_found)
        user_id_ = user_count_ + 1;

        user_count_++;
    }
    
    User()
    {
        bool vacant_id_found = 0;
        /* for (int i=0; i<10 ; i++) 
        if ( vacant_id_slots_ [i] != 0 && vacant_id_slots_ [i] < (user_count_ + 1) ) {
            user_id_ == vacant_id_slots_ [i] ;
            vacant_id_slots_ [i] = 0;
            vacant_id_found = 1;
            break;
        }
        if (!vacant_id_found)
        user_id_ = 0;
    */
        user_name_="";
        user_email_="";
        user_password_="";
        user_role_ = "" ;
        user_id_ = 0;
    //    user_count_ ++;
    } 
    
    int
    authenticateUser (string check_email, string check_password) {
        ifstream userFile("users.txt");
        if (userFile.is_open()) {
        string field, stored_email, stored_password;

            while (userFile >> field) {
                if (field == "Email:") {
                    userFile >> stored_email;
                } else if (field == "Password:") {
                    userFile >> stored_password;
                    // Check the credentials
                    if (check_email == stored_email && check_password == stored_password) {
                        userFile.close();
                        return user_id_;
                    }
                    else
                        return 0;
                }
            }

        userFile.close();
        } else {
            cout << "Error: Unable to open the file." << endl;
        }
            return false; // User authentication failed
        }
      /*
        if ( check_email == this->user_email_ ) {

            if ( check_password == this->user_password_ ) {
                return 1;
            } 
            else {
                return 0;
            }
        }    
        else {
            return 0;
        }*/
    
    
        

    void
    displayUserDetails () {
        cout<<"User id: "<<user_id_ <<endl
            <<"User Name: "<<user_name_ <<endl
            <<"User Email: "<<user_email_ <<endl; 
        }

    int 
    get_user_id() {
        return user_id_;
    }
    int
    get_project_count() {
        return project_count_;
    }
    string 
    get_user_name() {
        return user_name_;
    }
    void 
    set_user_email(string email) {
        user_email_=email;
    }
    void
    set_user_password(string password) {
        user_password_=password;
    }
    void 
    set_user_name(string name) {
        user_name_=name;
    }
    /* Project& get_project(int index) {
        return project_[index];
    } */

    /*void
    display_projects_ () {
        for (int i=0 ; i < project_count_ ; i++) {
        cout <<endl <<get_project(i).get_project_id_ () <<" - " <<get_project(i).get_project_name_ () ;  
        }
    } */
    void
    viewProfile () {
        string name;
        string email;
        string password;
        int view_profile_options;

        cout <<"User Details: " <<endl ;
        displayUserDetails();
        cout <<endl;
        cout << "Current Project: " <<endl;
        // displayCurrentProjectDetails();
        cout << "Tasks Assigned: " <<endl <<endl;
        displayAssignedTasks();

        do {

        cout << "1. Change Name " <<endl
             << "2. Change Email" <<endl
             << "3. Change Password" <<endl
             << "4. Exit" <<endl;
        cout << "Enter your choice."<<endl;
        cin>>view_profile_options;
            switch(view_profile_options) {
                case 1: //Change Name
                cout<<"Enter New Name: ";
                cin>>name;
                set_user_name(name);
                cout<<"Name changed successfully."<<endl;
                cout<<name;
                break;

                case 2: //Change Email
                cout << "Enter New Email: ";
                cin >> email;
                set_user_email(email);
                cout << "Email changed successfully." << endl;
                cout<<email;
                break;

                case 3: //Change Password
                cout << "Enter New Password: ";
                cin >> password;
                set_user_password(password);
                cout << "Password changed successfully." << endl;
                break;

                case 4: //Exit
                cout << "Exiting profile view." << endl;
                break;

                default:
                cout << "Invalid option. Please try again." << endl;
                break;

            }
        cout<<endl;
        } while(view_profile_options!=4);
    }
    
    /*
    void
    displayCurrentProjectDetails(int id,string name,string due_date) {
        cout<<"Current Project Details: "<<endl;
        for(int i=0;i<project_count_;i++)
        {
            cout << "Project ID: " << user_projects[i].get_project_id_()<< endl;
            cout << "Project Name: " << user_projects[i].get_project_name_() << endl;
            cout << "Project Due Date: " << user_projects[i].get_due_date() << endl;

        }
    }*/
    void
    displayAssignedTasks() {

    }
    void
    generateReport () {
        cout <<"User Details: " <<endl <<endl ;
        cout <<"ID: " ;
        cout << this -> user_id_ <<endl;
        cout <<"Name: " ;
        cout << this-> user_name_ <<endl;
        cout <<"Email: " ;
        cout << this-> user_email_ <<endl;

        cout << "Current Project: " <<endl;
        // current_project.displayProjectDetails () ;

        cout << "Tasks Assigned: " <<endl <<endl;
        /* for (int i=0; i < 5 ; i++) {

        } */
    }


    /* void
    addProject (Project newproject ) {
        project_ [ project_count_ ] = newproject;
        project_count_++;
    } */

    /* void
    createUser (string username,string email,string password) {
        bool vacant_id_found = 0;
        for (int i=0; i<10 ; i++) 
        if ( vacant_id_slots_ [i] != 0 && vacant_id_slots_ [i] < (user_count_ + 1) ) {
            vacant_id_slots_ [i] == user_id_;
            vacant_id_found = 1;
            break;
        }
        if (!vacant_id_found)
        user_id_ = user_count_ + 1;

        user_name_=username;
        user_email_=email;
        user_password_= password;
        user_count_ ++;
    } */

    void
    removeUser () {
        vacant_id_slots_ [vacant_id_slots_counter_] = user_id_;
        user_id_ = 0;
        user_name_="n/a";
        user_email_="n/a";
        user_password_="n/a";
        user_count_ --;
    }

    void
    AddTask (int task_id) {
        // int user_task_count = project_users_[user_id - 1].task_count_;
        // use friend member to access project tasks
        //user_tasks [task_count_] = ;
    }


    friend class Project;
    friend class Task;
};
int
User :: user_count_ = 0;
int
User :: vacant_id_slots_ [] = {0};
int
User :: vacant_id_slots_counter_ = 0;

class UserMember : public User {

};

class UserAdmin : public UserMember {
    
};
#endif