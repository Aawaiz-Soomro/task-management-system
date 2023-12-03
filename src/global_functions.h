#ifndef GLOBAL_FUNCTIONS_H
#define GLOBAL_FUNCTIONS_H
#include <iostream>
#include <string>
#include <ctime>
#include "project.h"
#include "tasks.h"
#include "user.h"
using namespace std;

void
loginMenu (int &login_switch) {
    cout<<"******************* LOGIN MENU *************************"<<endl;
    cout<< "1. Create New User" <<endl
    << "2. Login" <<endl 
    << "3. Exit Program" <<endl ;
    cout<<"********************************************************"<<endl;
    cin >> login_switch;}

void
signupForm (User &newuser, Project &c_project) {
    cout<<"******************* SIGNUP MENU *************************"<<endl;
    string temp_user_name;
    string temp_user_email;
    string temp_user_password;

    cout << "Enter Username: "  ;
    cin >> temp_user_name;
    cout << "Enter Email: " ;
    cin >> temp_user_email;
    cout << "Enter Password: " ;
    cin >> temp_user_password;

    c_project.createUser(temp_user_name,temp_user_email,temp_user_password) ;

    cout<<"New user created successfully."<<endl;
    cout <<endl;
    cout<<"*********************************************************"<<endl;
}

void
loginForm (User &newuser, bool &user_login) {
    cout<<"******************* LOGIN FORM *************************"<<endl;
    string temp_user_email;
    string temp_user_password;

    cout << "Enter E-Mail: " ;
    cin >> temp_user_email;
    cout << "Enter Password: " ;
    cin >> temp_user_password;

    
    if ( newuser.authenticateUser (temp_user_email, temp_user_password) ) {
        cout << "Logged into the account successfully." << endl;
        user_login = 1;
    } 
    else {
        cout << "Login failed. Please try again." << endl;
    }

    cout << endl;
    cout<<"********************************************************"<<endl;
}

void
projectMenu (int &project_switch) {
    cout<<"******************* PROJECT MENU *************************"<<endl;
    cout
        /* << "1. Create a Project" <<endl
        << "2. Add Project" <<endl */
        << "3. Manage Project" <<endl
        << "4. View Profile" <<endl
        << "5. Go Back"<<endl
        << "6. Logout"<<endl;
    
    cin >> project_switch;
    cout<<"**********************************************************"<<endl;
}
void 
createProject() {
        string project_name;
        string project_due_date;
        TaskTeam team;
        cout<<"Enter Project Name: "; 
        cin>>project_name;
        cout<<"Enter Project Due Date: ";
        cin>>project_due_date;    

    //    user.addProject(Project(project_name,0, team,project_due_date));
        cout<<"Project have been successfully created."<<endl;
        cout<<endl;
}
void
editTasks(User& newUser){
    cout<<"*******************  EDIT TASKS *************************"<<endl;
    int edit_task_option;
    do {
        
        cout<< "1. Search for the Task"<<endl
        << "2. Add Tags"<<endl
        << "3. Notes and Comments"<<endl
        << "4. Go Back"<<endl;
    
        cin>>edit_task_option;
        switch(edit_task_option) {
            case 1:  //Search for the task
            cout<<"Searching for the task. "<<endl;
            break;

            case 2:  //Add tags
            cout<<"Adding tags. "<<endl;
            break;

            case 3:  //Notes and comments
            cout<<"Notes and comments. "<<endl;
            break;

            case 4:  //Go Back
            cout<<"Going back to the previous menu."<<endl;
            break;

            default:
            cout<< "Invalid option. Please try again." << endl;        
        }   
    
    }while (edit_task_option!=4);
    cout<<"*********************************************************"<<endl;
    } 
    
void
manageProjects(User& newUser) {
    int project_options;

  //  cout<<"Projects for User: "<<user.get_user_name()<<endl;
   // for(int i=0;i<user.get_project_count();i++) {
    //    cout<<user.get_project(i).get_project_id_()<<" - "<<user.get_project(i).get_project_name_()<<endl;

    //}
    
     //cout<<"Select a Project: "<<endl;
    // cin>>project_options;

    Project selected_project;
    /* for(int i=0;i<user.get_project_count();i++)
    {
        if(user.get_project(i).get_project_id_() == project_options)
        {
            selected_project= user.get_project(i);
            break;
        }
    } */
   //  if (selected_project.get_project_id_() !=0)
    //  {
        int tasks_options;
    do {
        
            cout<< "1. Create a Task" << endl
                << "2. Edit a Task" << endl
                << "3. Go Back" << endl;

            cin>>tasks_options;

            switch(tasks_options)
            {
                case 1:  //Create a Task
                cout<<"Creating a task. "<<endl;
                break;

                case 2:  //Edit a Task
                editTasks(newUser);
                break;

                case 3: //Go Back
                cout<<"Going back to the previous menu."<<endl;
                break;

                default:
                cout<<"Invalid option. Please try again." << endl;
                

           }
         }
      //   else {
       //    cout << "Invalid project selection. Please try again." << endl;
      //  }
        
     while(tasks_options!=3);
   }
#endif