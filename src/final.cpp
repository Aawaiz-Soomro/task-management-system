#include <iostream>
#include "global_functions.h"

int main () {

    int login_switch;
    Project current_project;
    User loginUser;
    bool user_login = 0;

    do {
        
        loginMenu (login_switch);
        switch (login_switch) {
        
            case 1:
            signupForm (loginUser, current_project);
            break;

            case 2:
            loginForm (loginUser, user_login); 

            while (user_login)  //when value of the user login will be updated so run the while loop!
                {
                    int project_switch;
                    projectMenu (project_switch);

                    switch(project_switch)
                    {
                        /* case 1:    //Create a Project
                        createProject();
                        break;
                        
                        case 2:  //Add a Project
                        break; */

                        case 3:  //Manage Project
                        cout<<"******************** MANAGE PROJECT MENU ********************"<<endl;
                        manageProjects(loginUser);
                        cout<<"*************************************************************"<<endl;
                        break;

                        case 4:  //View Profile
                        cout<<"********************** VIEWING PROFILE ********************"<<endl;
                        loginUser.viewProfile();
                        cout<<"***********************************************************"<<endl;
                        break;
                        
                        case 5:  //Go Back
                        cout<<"Going back to the previous menu."<<endl;
                        user_login = 0;
                        loginForm(loginUser, user_login);
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
