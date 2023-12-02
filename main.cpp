#include <tasks.h>
#include <global_functions.h>
#include <project_team.h>
#include <project_management.h>
#include <user.h>

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