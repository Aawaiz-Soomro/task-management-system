#ifndef PROJECT
#define PROJECT
#include <iostream>
#include "tasks.h"
#include "user.h"
using namespace std;



class User;
const int MAX_PROJECT_USERS = 20;
    class Project {
    private:
    int project_id_;
    string project_name_;
    string project_description_;
    string project_due_date_;
    int no_of_tasks_;
    User project_users_ [MAX_PROJECT_USERS];
    Task project_tasks_ [MAX_NO_OF_TASKS] ;
    
    public:
    Project()
    {
        project_id_=0;
        project_name_="My First Project";
        project_description_ = "This is my first project";
        project_due_date_="22042024";
        
    }
    Project(string name,int id,string project_desc, string due_date)  
    {
        project_name_=name;
        project_id_=id;
        project_description_ = project_desc;
        project_due_date_= due_date;
    }
    
    string
    get_project_name_ () {
        return project_name_;
    }

    int
    get_project_id_ () {
        return project_id_;
    }
    string 
    get_due_date () {
        return project_due_date_;
    }

    void
    viewProfile (int user_id) {
        project_users_[user_id].viewProfile ();
    }

    int
    createUser (string username,string email,string password,string role) {
        // project_users_[0].User :: createUser (username, email,password) ;
        bool vacant_id_found = 0;
        int user_index = 0;
        int new_user_id = 0;
        for (int i=0; i<10 ; i++) 
        if ( project_users_[0].vacant_id_slots_ [i] != 0 )  {
            user_index = project_users_[0].vacant_id_slots_ [i] - 1;
            project_users_[user_index].user_id_ = project_users_[0].vacant_id_slots_ [i] ;

            project_users_[user_index].user_name_=username;
            project_users_[user_index].user_email_=email;
            project_users_[user_index].user_password_= password;
            project_users_[user_index].user_role_ = role;
            vacant_id_found = 1;
            new_user_id = project_users_[user_index].user_id_;
            break;
        }
        if (!vacant_id_found) {
        
        int temp_user_count = project_users_[0].user_count_; 
        project_users_[temp_user_count].user_id_ = temp_user_count + 1;
        project_users_[temp_user_count].user_email_ = email;
        project_users_[temp_user_count].user_password_ = password;
        project_users_[temp_user_count].user_role_ = role;
        new_user_id = project_users_[temp_user_count + 1].user_id_;
        }

        project_users_[0].user_count_ ++;

        return new_user_id; 
    }

    bool
    authenticateUser (string check_email, string check_password) {
        for (int i=1; i < project_users_[0].user_count_ ; i++ ) {
            if  (project_users_[i].authenticateUser (check_email, check_password)) {
                return i;
            }
        }
    }

    void
    displayProjectDetails () {
        cout <<"Project Name: " <<project_name_ <<endl;
        cout <<"Project ID: " <<project_id_ <<endl;
        cout <<"Project Due Date: " <<project_due_date_ <<endl;
    }

    void
    displayAllProjectUsers () {
        int temp_users_count = project_users_ [0].user_count_;
        for (int i=0 ; i < temp_users_count - 1 ; i++) {
        project_users_->displayUserDetails();
        }
    }

    void
    displayUserDetails (int id) {
        project_users_[id].displayUserDetails();
    }

    void
    generateReport (int id) {
        project_users_ [id].generateReport();
    }

    int
    createTask (string name, string due_date) {
        int temp_task_count = project_tasks_ [0].task_count;
        int task_id = project_tasks_[temp_task_count].Task:: createTask (name, due_date);
        project_tasks_ [0].task_count++;
        return task_id;
        
    }


    void
    AddTask (int user_id, int task_id) {
        project_users_ [user_id-1].AddTask (project_tasks_ [task_id - 1]);
    }

    void
    addTaskTags (int user_id, int task_id, Tags new_task_tag) {
        project_tasks_[task_id - 1]. Task:: addTaskTags (new_task_tag);
        project_users_[user_id - 1]. User:: addTaskTags (task_id,new_task_tag);

    }

    void
    changeTaskStatus (int user_id, int task_id, string task_status) {
        project_tasks_[task_id-1].Task :: changeTaskStatus (task_status);
        project_users_[user_id-1].User :: changeTaskStatus (task_id, task_status);
    }


    void
    displayTasks () {
        int temp_tasks_count = project_tasks_ [0].task_count;
        for (int i=0 ; i < temp_tasks_count ; i++) {
        project_tasks_[i].displayTaskDetails();
        }
    }

    void
    displayUserTasks ( int user_id ) {
        project_users_[user_id-1].displayAssignedTasks ();
    }

    void
    addTaskNotes (int user_id, int task_id, PublicNotes add_note) {
        cout << "Entering addTaskNotes for Public function in Project class" << endl;
        project_tasks_ [task_id - 1].addTaskNotes(add_note);
        
    }

    void
    addTaskNotes (int user_id, int task_id, PrivateNotes add_note) {
        cout << "Entering addTaskNotes for Private function in Project class" << endl;
         //project_users_ [user_id - 1].User::addTaskNotes (task_id, add_note);
        project_users_ [user_id - 1].addTaskNotes (task_id, add_note);
    }

    void
    displayPublicNotes (int task_id) {
        project_tasks_ [task_id - 1].displayPublicNotes();
    }

    void
    displayPrivateNotes (int user_id, int task_id) {
        project_users_ [user_id - 1].displayPrivateNotes(task_id);
    }


    void
    editTaskDueDate (int task_id,string new_due_date) {
        project_tasks_[task_id].Task::editTaskDueDate(new_due_date);
    }

    void
    sendDueDateAlert (int user_id) {
        project_users_ [user_id].sendDueDateAlert ();
    }
    bool taskExists(int task_id)  {
    for ( Task& task : project_tasks_) {
        if (project_tasks_[task_id].get_task_id() == task_id) {
            return true;
        }
    }
    return false;
    }
    User
    searchUser (int id) {
        for (int i=1 ; i<= project_users_[0].user_count_ ; i++) {
            if (id == project_users_[i].get_user_id ()) {
            project_users_[i].displayUsersDetails();
            return project_users_ [i] ;
            }
        }
    }

    User
    searchUser (string user_name) {
        for (int i=1 ; i<= project_users_[0].user_count_ ; i++) {
            if (user_name == project_users_[i].get_user_name ()) {
            project_users_->displayUsersDetails();
            return project_users_ [i] ;
            }
        }
    } 


    friend class User;

    
};
//Project current_project;
#endif