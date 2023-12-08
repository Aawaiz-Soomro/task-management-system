#include <iostream>
#include "global_functions.h"
int main () {

    int login_switch;
    Project current_project;
    User loginUser;
    bool user_login = 0;
    int current_user_id = 0;
    do {
        
        loginMenu (login_switch);
        switch (login_switch) {
            
        
            case 1:
            signupForm (loginUser, current_project);
            break;

            case 2:
            loginForm (current_project, user_login, current_user_id);
            while (user_login)  //when value of the user login will be updated so run the while loop!
                {
                    int project_switch;
                    projectMenu (project_switch);
                    current_user_id = 1;
                    switch(project_switch)
                    {
                        //current_user_id = 1;
                        /* case 1:    //Create a Project
                        createProject();
                        break;
                        
                        case 2:  //Add a Project
                        break; */

                        case 1:  //Manage Project
                        cout<<"******************** MANAGE PROJECT MENU ********************"<<endl;
                        manageProjects(loginUser,current_project, current_user_id);
                        cout<<"*************************************************************"<<endl;
                        break;

                        case 2:  //View Profile
                        cout<<"********************** VIEWING PROFILE ********************"<<endl;
                        current_project.viewProfile(current_user_id);
                        cout<<"***********************************************************"<<endl;
                        break;

                        case 3:
                        current_project.displayProjectDetails();

                        
                        case 4:  //Go Back
                        cout<<"Going back to the previous menu."<<endl;
                        user_login = 0;
                        loginForm(current_project,user_login, current_user_id);
                        break;

                        case 5:  //Logged out
                        cout<<"User logged out successfully."<<endl;
                        cout<<"Exiting the program."<<endl;
                        exit(0);
                        
                        default:
                        cout<<"Invalid option. Please try again."<<endl;
                        cout<<endl;
                
                    }

                } 
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
