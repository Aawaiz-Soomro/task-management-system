#ifndef USER_H
#define USER_H

#include <iostream>
#include "project_team.h"
using namespace std;



class User {
    private:
    static int user_count_;
    int user_id_;
    static int vacant_id_slots_ [10];
    static int vacant_id_slots_counter_;
    string user_name_;
    string user_email_;
    string user_password_;
    string user_role_;
    int project_count_;
    
    public:
    User(string username,string email,string password):user_name_(username),user_email_(email),user_password_(password) {
        bool vacant_id_found = 0;
        for (int i=0; i<10 ; i++) 
        if ( vacant_id_slots_ [i] != 0 && vacant_id_slots_ [i] < (user_count_ + 1) ) {
            vacant_id_slots_ [i] == user_id_;
            vacant_id_found = 1;
            break;
        }
        if (!vacant_id_found)
        user_id_ = user_count_ + 1;

        user_count_++;
    }
    
    User()
    {
        user_id_ = user_count_ + 1;
        user_name_="";
        user_email_="";
        user_password_="";
        user_count_ ++;
    }
    
    bool
    authenticateUser (string check_email, string check_password) {
        if ( check_email == this->user_email_ )
        if ( check_password == this->user_password_ )
        return 1;
    }

    void
    displayUserDetails () {
        cout<<"User id: "<<user_id_
            <<"User Name: "<<user_name_
            <<"User Email: "<<user_email_
            <<"User Password: "<<user_password_;
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

    /* ProjectManagement& get_project(int index) {
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

        cout << "1. Change Name: " <<endl;
        cout << "2. Change Email" <<endl;
        cout << "3. Change Password" <<endl;
        
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
    addProject (ProjectManagement newproject ) {
        project_ [ project_count_ ] = newproject;
        project_count_++;
    } */

    void
    setUser (string username,string email,string password) {
        bool vacant_id_found = 0;
        for (int i=0; i<10 ; i++) 
        if ( vacant_id_slots_ [i] != 0 && vacant_id_slots_ [i] < (user_count_ + 1) ) {
            vacant_id_slots_ [i] == user_id_;
            vacant_id_found = 1;
            break;
        }
        if (!vacant_id_found)
        user_id_ = user_count_ + 1;
        user_name_="";
        user_email_="";
        user_password_="";
        user_count_ ++;
    }
    void
    removeUser () {
        vacant_id_slots_ [vacant_id_slots_counter_] = user_id_;
        user_id_ = 0;
        user_name_="n/a";
        user_email_="n/a";
        user_password_="n/a";
        user_count_ --;
    }



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