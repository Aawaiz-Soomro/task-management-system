#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>

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
    int user_task_count_;

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
    
    bool
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
                        cout << "Stored Email: " <<stored_email;
                        cout << "Stored Password: " <<stored_password;
                        userFile.close();
                        cout <<"Logged In" <<endl;
                        return 1;
                    }
                    else
                        cout <<"Login failed, User not found " <<endl;
                        return 0;
                }
            }

        userFile.close();
        } else {
            cout << "Error: Unable to open the file." << endl;
        }
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
    
    
        
    // Function to update user details in the file
    void updateDetailsInFile(const User& updatedUser) {
    ifstream inFile("users.txt");
    ofstream tempFile("temp_users.txt");

    if (inFile.is_open() && tempFile.is_open()) {
        int stored_user_id;
        string stored_user_name, stored_user_email, stored_user_password;

        while (inFile >> stored_user_id >> stored_user_name >> stored_user_email >> stored_user_password) {
            if (stored_user_id == updatedUser.get_user_id()) {
                // Update user details in the file
                tempFile << "ID: " << stored_user_id << endl;
                tempFile << "Name: " << updatedUser.get_user_name() << endl;
                tempFile << "Email: " << updatedUser.get_user_email() << endl;
                tempFile << "Password: " << updatedUser.get_user_password() << endl;
            } else {
                // Copy other users' details to the temporary file
                tempFile << "ID: " << stored_user_id << endl;
                tempFile << "Name: " << stored_user_name << endl;
                tempFile << "Email: " << stored_user_email << endl;
                tempFile << "Password: " << stored_user_password << endl;
            }
        }

        inFile.close();
        tempFile.close();

        // Replace the original file with the temporary file
        remove("users.txt");
        rename("temp_users.txt", "users.txt");
    } else {
        cout << "Error: Unable to open the file." << endl;
    }
    }


    void displayUserDetails() {
     ifstream userFile("users.txt",ios::in);
    if(userFile.is_open())
    {
        int stored_user_id;
        string stored_user_name, stored_user_email, stored_user_password;

        while (userFile >> stored_user_id >> stored_user_name >> stored_user_email >> stored_user_password) {
            // Display user details
            cout << "User ID: " << stored_user_id << endl
                 << "User Name: " << stored_user_name << endl
                 << "User Email: " << stored_user_email << endl;
        }

        if (!userFile.eof()) {
            cout << "Error: Failed to read all data from 'users.txt'." << endl;
        }

        userFile.close();
    } else {
        cout << "Error: Unable to open the file." << endl;
    }
    }
    

    void
    displayUsersDetails () {
        cout << "User ID: "<< user_id_ << endl
             << "Name: "   << user_name_ <<endl
             << "Email: "  << user_email_ << endl;

    }

    int 
    get_user_id() const{
        return user_id_;
    }
    int
    get_project_count() const{
        return project_count_;
    }
    string 
    get_user_name() const{
        return user_name_;
    }
    string
    get_user_email () const{
        return user_email_;
    }
    string 
    get_user_password () const  {
        return user_password_;
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
    void
    set_user_id (int id) {
        user_id_=id;
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
        string new_name;
        string new_email;
        string new_password;
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
                cin>>new_name;
                set_user_name(new_name);
                cout<<"Name changed successfully."<<endl;
                cout<<new_name;
                break;

                case 2: //Change Email
                cout << "Enter New Email: ";
                cin >> new_email;
                set_user_email(new_email);
                cout << "Email changed successfully." << endl;
                cout<<new_email;
                break;

                case 3: //Change Password
                cout << "Enter New Password: ";
                cin >> new_password;
                set_user_password(new_password);
                cout << "Password changed successfully." << endl;
                break;

                case 4: //Exit
                cout << "Exiting profile view." << endl;
                break;

                default:
                cout << "Invalid option. Please try again." << endl;
                break;

            }
             // Update user details in the file if changes were made
            if (view_profile_options >= 1 && view_profile_options <= 3) {
                User updatedUser( new_name, new_email, new_password);
                updateDetailsInFile(updatedUser);
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
    sendDueDateAlert () {
        for (int i=0 ; i < user_task_count_ ; i++) { 
        user_tasks[i].sendDueDateAlert(user_email_);
        }
    }


    /* void
    AddTask (int task_id) {
        // int user_task_count = project_users_[user_id - 1].task_count_;
        // use friend member to access project tasks
        //user_tasks [task_count_] = ;
    } */

    void
    AddTask (Task add_task) {
        cout <<"User ID: " <<user_id_ <<"  " <<"Task ID: " <<add_task.get_task_id () ;
        if(user_id_ > 0 && add_task.get_task_id () > 0 && add_task.get_task_id () <= MAX_NO_OF_TASKS) {
            user_tasks [user_task_count_] = add_task ;
            user_tasks [user_task_count_].set_task_id (user_task_count_ + 1);
            user_task_count_++;
            cout<<"Task added successfully."<<endl;
        } 
        else {
            cout << "Invalid user_id or task_id." << endl;
        }
    }

    void
    displayAssignedTasks () {
        for (int i=0 ; i < user_task_count_ ; i++) {
        user_tasks[user_task_count_ - 1].displayTaskDetails();
        }
    }

    void
    changeTaskStatus (int task_id, string task_status) {
        user_tasks[task_id].changeTaskStatus (task_status);
    }

    void
    addTaskNotes (int task_id, PrivateNotes add_note) {
        // user id not working properly (fixed but need to re-check)
        user_tasks [task_id].addTaskNotes(add_note);
    }

    void
    addTaskTags ( int task_id, Tags new_task_tag) {
        user_tasks [task_id-1]. Task:: addTaskTags (new_task_tag);
    }

    void
    displayPrivateNotes (int task_id) {
        user_tasks [task_id].displayPrivateNotes();
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