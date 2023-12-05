#ifndef GLOBAL_FUNCTIONS_H
#define GLOBAL_FUNCTIONS_H
#include <iostream>
#include <fstream>

#include <string>
#include "project.h"
#include "tasks.h"
#include "user.h"
using namespace std;

void
loginMenu (int &login_switch) {
    cout<<"******************* LOGIN MENU *************************"<<endl;
    cout<< "1. Create New User" <<endl
        << "2. Login" <<endl 
        << "3. Exit Program" <<endl 
        <<"********************************************************"<<endl;
    cin >> login_switch;}

void
signupForm (User& loginUser, Project &c_project) {
    cout<<"******************* SIGNUP MENU *************************"<<endl;
    string temp_user_name;
    string temp_user_email;
    string temp_user_password;
    string temp_user_role;

    cout << "Enter Username: "  ;
    cin >> temp_user_name;
    cout << "Enter Email: " ;
    cin >> temp_user_email;
    cout << "Enter Password: " ;
    cin >> temp_user_password;
    cout << "Enter UserRole: " ;
    cin >> temp_user_role;



    // Save the user to a file
    ofstream userFile("users.txt", ios::app);  // Open file in append mode
    if (userFile.is_open()) {
        userFile << "Username: " << temp_user_name << endl
                 << "Email: " << temp_user_email <<endl
                 << "Password: " << temp_user_password << endl
                 << "UserRole: " << temp_user_role << endl
                 << "------------------------------"<<endl;
        userFile.close();
        cout << "User information saved to file." << endl;
    } else {
        cout << "Error: Unable to open the file." << endl;
    }

    c_project.createUser(temp_user_name,temp_user_email,temp_user_password, temp_user_role ) ;
    /* loginUser.set_user_name(temp_user_name);
    loginUser.set_user_email(temp_user_email);
    loginUser.set_user_password(temp_user_password); */

    cout<<"New user created successfully."<<endl;
    cout <<endl;
    cout<<"*********************************************************"<<endl;
}

void
loginForm (User& loginUser, bool& user_login, int current_user_id) {
    cout<<"******************* LOGIN FORM *************************"<<endl;
    string temp_user_email;
    string temp_user_password;

    cout << "Enter E-Mail: " ;
    cin  >> temp_user_email;
    cout << "Enter Password: " ;
    cin  >> temp_user_password;

    if ( loginUser.authenticateUser (temp_user_email, temp_user_password) ) {
        current_user_id = loginUser.authenticateUser (temp_user_email, temp_user_password);
        cout << "Logged into the account successfully." << endl;
    //    loginUser.set_user_email(temp_user_email);
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
        << "1. Manage Project" <<endl
        << "2. View Profile" <<endl
        << "3. Go Back"<<endl
        << "4. Logout"<<endl;
    
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
createTask(Project& c_project, User& loginUser) {
    cout<<"*******************  CREATE TASKS *************************"<<endl;
    string temp_name;
    string temp_due_date;
    int task_id;
    cout<<"Enter Task Name: ";
    cin >>temp_name;
    cout<<"Enter Due Date: ";
    cin>>temp_due_date;

    c_project.createTask(temp_name,temp_due_date);

    c_project.displayProjectDetails ();

    cout << "Enter Task ID: ";
    cin >> task_id;
    c_project.AddTask(task_id, loginUser.get_user_id());
    cout<<"***********************************************************"<<endl;
}
void
editTasks(User& loginUser){
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
manageProjects(User& loginUser,Project& c_project) {
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
                createTask(c_project,loginUser);
                cout<<"Creating a task. "<<endl;
                break;

                case 2:  //Edit a Task
                editTasks(loginUser);
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