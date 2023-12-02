#include <iostream>
#include <string>
#include <ctime>
#include "project_team.h"
#include "tasks.h"
#include "user.h"

using namespace std;
void
loginMenu (int &login_switch) {
    cout<< "1. Create New User" <<endl
    << "2. Login" <<endl 
    << "3. Exit Program" <<endl ;
    cin >> login_switch;
}

void
signupForm () {
    string temp_user_name;
    string temp_user_email;
    string temp_user_password;

    cout << "Enter Username: "  ;
    cin >> temp_user_name;
    cout << "Enter Email: " ;
    cin >> temp_user_email;
    cout << "Enter Password: " ;
    cin >> temp_user_password;

    // newUser= User (temp_user_name,temp_user_email,temp_user_password) ;
    cout<<"New user created successfully."<<endl;
    cout <<endl;
}

void
loginForm () {
    string temp_user_email;
    string temp_user_password;

    cout << "Enter E-Mail: " ;
    cin >> temp_user_email;
    cout << "Enter Password: " ;
    cin >> temp_user_password;

    
    // Assuming you have an authenticateUser function
    // if (authenticateUser(temp_user_email, temp_user_password)) {
    cout << "Logged into the account successfully." << endl;
    // Set user_login to true or manage login status accordingly
    // user_login = true;
    // } else {
    //     cout << "Login failed. Please try again." << endl;
    // }
    cout << endl;
}

void
projectMenu (int &project_switch) {
    cout<< "1. Create a Project" <<endl
        << "2. Add Project" <<endl
        << "3. Manage Project" <<endl
        << "4. View Profile" <<endl
        << "5. Go Back"<<endl
        << "6. Logout"<<endl;
    
    cin >> project_switch;
}
void 
createProject() {
        string project_name;
        string project_due_date;
        ProjectTeam team;
        cout<<"Enter Project Name: "; 
        cin>>project_name;
        cout<<"Enter Project Due Date: ";
        cin>>project_due_date;    

    //    user.addProject(ProjectManagement(project_name,0, team,project_due_date));
        cout<<"Project have been successfully created."<<endl;
        cout<<endl;
}
void
editTasks(User& user){
    int edit_task_option;
    cout<< "1. Search for the Task"<<endl
        << "2. Add Tags"<<endl
        << "3. Notes and Comments"<<endl
        << "4. Go Back"<<endl;
    
    cin>>edit_task_option;
    switch(edit_task_option) {
        case 1:  //Search for the task
        break;

        case 2:  //Add tags
        break;

        case 3:  //Notes and comments
        break;

        case 4:  //Go Back
        cout<<"Going back."<<endl;
        break;

        default:
        cout<< "Invalid option. Please try again." << endl;
        
    }   
}
void
manageProjects() {
    int project_options;

  //  cout<<"Projects for User: "<<user.get_user_name()<<endl;
   // for(int i=0;i<user.get_project_count();i++) {
    //    cout<<user.get_project(i).get_project_id_()<<" - "<<user.get_project(i).get_project_name_()<<endl;

    //}
    
    cout<<"Select a Project: "<<endl;
    cin>>project_options;

    ProjectManagement selected_project;
    /* for(int i=0;i<user.get_project_count();i++)
    {
        if(user.get_project(i).get_project_id_() == project_options)
        {
            selected_project= user.get_project(i);
            break;
        }
    } */
    if (selected_project.get_project_id_() !=0)
    {
        int tasks_options;
            cout<< "1. Create a Task" << endl
                << "2. Edit a Task" << endl
                << "3. Go Back" << endl;

            cin>>tasks_options;

            switch(tasks_options)
            {
                case 1:  //Create a Task
                break;

                case 2:  //Edit a Task
                // editTask();
                break;

                case 3: //Go Back
                cout<<"Going back."<<endl;
                int project_switch;
                projectMenu(project_switch);
                break;

                default:
                cout<<"Invalid option. Please try again." << endl;
                

            }
        }
        else {
            cout << "Invalid project selection. Please try again." << endl;
        }
        
    }
int main () {

    int login_switch;
    User newUser;
    bool user_login = 0;

    do {
        
        loginMenu (login_switch);
        switch (login_switch) {
        
            case 1:
            signupForm ();
            break;

            case 2:
            loginForm (); 
            user_login=1;
            while (user_login)  //when value of the user login will be updated so run the while loop!
                {
                    int project_switch;
                    projectMenu (project_switch);

                    switch(project_switch)
                    {
                        case 1:    //Create a Project
                        createProject();
                        break;
                        
                        case 2:  //Add a Project
                        break;

                        case 3:  //Manage Projects
                        manageProjects();
                        break;

                        case 4:  //View Profile
                        cout<<"Viewing Profile."<<endl;
                        break;
                        
                        case 5:  //Go Back
                        cout<<"Going back."<<endl;
                        loginMenu(login_switch);
                        break;

                        case 6:  //Logged out
                        cout<<"User logged out successfully."<<endl;
                        cout<<"Exiting the program."<<endl;
                        exit(0);
                        
                        default:
                        cout<<"Invalid option. Please try again."<<endl;
                        cout<<endl;
                
                    }

                }    
           // }
           // else {
           //     cout<<"Login failed. Please try again."<<endl;

           // }
            
            
            break;
            
            case 3:
            cout<<"Exiting the program."<<endl;
            exit(0);

            default:
            cout<<"Invalid option. Please try again."<<endl;
        }

    } while (!user_login) ;

    return 0;
} 
// ---------------------------------------------------------------------------------------------------------------------------- //
