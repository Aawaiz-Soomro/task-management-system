#ifndef PROJECT_TEAM_H
#define PROJECT_TEAM_H
#include <iostream>
#include "tasks.h"
#include "user.h"
using namespace std;


class TaskTeam  {
    private:
    User team_members_ [5] ;
    int team_members_count_;

    public:

    void
    addTeamMember (User new_team_member) {
        team_members_ [team_members_count_] = new_team_member; 
    }
    
    void
    removeTeamMember () {
        cout << "Who do you want to remove?" <<endl;
        int removed_person_choice = 0;
        for ( int i=0; i<5 ; i++) {
        cout <<i <<". " <<team_members_ [i].get_user_name () <<" - " <<team_members_ [i].get_user_id () <<endl ;
        }
        cout << "Enter Your Choice: ";
        cin >> removed_person_choice;

        team_members_ [removed_person_choice].removeUser (); 
    }

    void
    displayTaskTeam () {
        for (int i=0 ; i<5 ; i++) {
        cout <<"User " <<i <<": " <<endl; 
        team_members_[i].displayUserDetails();
        }
    }

    User
    searchUser (int id) {
        for (int i=1 ; i<=team_members_count_ ; i++) {
            if (id == team_members_[i].get_user_id ()) {
            team_members_[i].displayUserDetails ();
            return team_members_ [i] ;
            }
        }
    }

    User
    searchUser (string user_name) {
        for (int i=1 ; i<=team_members_count_ ; i++) {
            if (user_name == team_members_[i].get_user_name ()) {
            team_members_[i].displayUserDetails ();
            return team_members_ [i] ;        
            }
        }
    }

};
const int MAX_NO_OF_TASKS = 5;
const int MAX_PROJECT_USERS = 20;
    class ProjectManagement {
    private:
    string project_name_;
    int project_id_;
    string project_due_date_;
    int no_of_tasks_;
    User project_users [MAX_PROJECT_USERS];
    Task project_tasks [MAX_NO_OF_TASKS] ;
    public:
    ProjectManagement()
    {
        project_name_="";
        project_id_=0;
        project_due_date_="";
    }
    ProjectManagement(string name,int id,string due_date)
    {
        project_name_=name;
        project_id_=id;
        project_due_date_=project_due_date_;
    }
    
    string
    get_project_name_ () {
        return project_name_;
    }

    int
    get_project_id_ () {
        return project_id_;
    }
    
    void
    displayProjectDetails () {
        cout <<"Project Name: " <<project_name_ <<endl;
        cout <<"Project ID: " <<project_id_ <<endl;
        cout <<"Project Due Date: " <<project_due_date_ <<endl;
    }

    friend class User;

    
};
//ProjectManagement current_project;
#endif