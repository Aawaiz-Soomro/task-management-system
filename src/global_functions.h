#ifndef GLOBAL_FUNCTIONS_H
#define GLOBAL_FUNCTIONS_H

#include <iostream>
#include <fstream>
// #include <curl/curl.h>
#include <string>
#include "project.h"
#include "tasks.h"
#include "user.h"
using namespace std;

/* void sendEmail(const std::string& recipient, const std::string& subject, const std::string& body) {
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        // Set the SMTP server details
        curl_easy_setopt(curl, CURLOPT_URL, "smtps://smtp.gmail.com:465");
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, "<aawaizsoomro502@gmail.com>");
        curl_easy_setopt(curl, CURLOPT_USERNAME, "<aawaizsoomro502@gmail.com>");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "<password>");

        // Set recipient email
        struct curl_slist* recipients = nullptr;
        recipients = curl_slist_append(recipients, recipient.c_str());
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        // Set email content
        std::string emailData = "Subject: " + subject + "\r\n\r\n" + body;
        curl_easy_setopt(curl, CURLOPT_READDATA, &emailData);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        // Perform the email send
        res = curl_easy_perform(curl);

        // Cleanup
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }

    if (res != CURLE_OK) {
        std::cerr << "Email sending failed: " << curl_easy_strerror(res) << std::endl;
    }
} */

int user_count=0;
void
loginMenu (int &login_switch) {
    cout<<"******************* LOGIN MENU *************************"<<endl;
    cout<< "1. Create New User" <<endl
        << "2. Login" <<endl 
        << "3. Exit Program" <<endl 
        <<"********************************************************"<<endl;
    cin >> login_switch;
}
/*
bool
authenticateUser (string check_email, string check_password,int check_user_id) {
    ifstream userFile("users.txt");
    if (userFile.is_open()) {
    string field, stored_email, stored_password;
    int stored_user_id;
        while (userFile >> field) {
            if (field == "Email:") {
                userFile >> stored_email;
                
            }
            else if (field == "Password:") {
                userFile >> stored_password;
            }
            else if (field == "ID:") {
                userFile >> stored_user_id;
                // Check the credentials
                if (check_email == stored_email && check_password == stored_password && check_user_id == stored_user_id) {
                    cout << "Stored Email Is: " <<stored_email <<endl;
                    cout << "Stored Password Is: " <<stored_email <<endl;
                    cout << "Stored User ID Is :"<<stored_user_id <<endl;
                    userFile.close();
                    cout <<"Logged In" <<endl;
                    return 1;
                }
                
            }
            
        }
    userFile.close();
    } else {
        cout << "Error: Unable to open the file." << endl;
    }
    return 0;
} */
bool authenticateUser (string check_email, string check_password, int check_user_id) {
    ifstream userFile("users.txt");
    if (userFile.is_open()) {
        string field, stored_email, stored_password;
        int stored_user_id;
        while (userFile >> field) {
            if (field == "Email:") {
                userFile >> stored_email;
            }
            else if (field == "Password:") {
                userFile >> stored_password;
            }
            else if (field == "ID:") {
                userFile >> stored_user_id;
            }
            // Check the credentials after reading all fields for a user
            if (!stored_email.empty() && !stored_password.empty() && stored_user_id != 0) {
                if (check_email == stored_email && check_password == stored_password) {
                    cout << "Stored Email Is: " << stored_email << endl;
                    cout << "Stored Password Is: " << stored_password << endl;
                    cout << "Stored User ID Is :"<< stored_user_id << endl;
                    check_user_id = stored_user_id;
                    userFile.close();
                    cout <<"Logged In" << endl; 
                    return 1;
                }
                // Reset the stored values for the next user
                stored_email = "";
                stored_password = "";
            }
        }
        userFile.close();
    } else {
        cout << "Error: Unable to open the file." << endl;
    }
    return false;
}


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

    // int new_user_id = ++user_count;
    int new_user_id = c_project.createUser(temp_user_name,temp_user_email,temp_user_password, temp_user_role ) ;
    ofstream userFile("users.txt", ios::app);  // Open file in append mode
    if (userFile.is_open()) {
        userFile << "ID: " << new_user_id <<endl
                 << "Username: " << temp_user_name <<endl
                 << "Email: " << temp_user_email <<endl
                 << "Password: " << temp_user_password << endl
                 << "UserRole: " << temp_user_role << endl
                 << "------------------------------"<<endl;
        userFile.close();
        cout << "User information saved to file." << endl;
    } else {
        cout << "Error: Unable to open the file." << endl;
    }

    /* loginUser.set_user_name(temp_user_name);
    loginUser.set_user_email(temp_user_email);
    loginUser.set_user_password(temp_user_password);
    */
    loginUser.set_user_id(new_user_id);
    cout<<"New user created successfully."<<endl;
    cout<<new_user_id;
    cout <<endl;
    cout<<"*********************************************************"<<endl;
}

void
loginForm (Project& c_project, bool& user_login, int &current_user_id) {
    cout<<"******************* LOGIN FORM *************************"<<endl;
    string temp_user_email;
    string temp_user_password;

    cout << "Enter E-Mail: " ;
    cin  >> temp_user_email;
    cout << "Enter Password: " ;
    cin  >> temp_user_password;

    int retrieved_user_id=0;
    bool auth_user_id = authenticateUser(temp_user_email,temp_user_password,retrieved_user_id);
    
    if (auth_user_id ) {
        current_user_id = retrieved_user_id;
        cout<< "Logged into the account successfully. "<<endl;
        user_login =1;
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

PrivateNotes
global_createPrivateNote (string priv_note_name,string priv_note_text) {
    PrivateNotes pn1 (priv_note_name, priv_note_text) ;
    return pn1 ;
}

PublicNotes
global_createPublicNote (string priv_note_name,string priv_note_text, string author) {
    PublicNotes pn1 (priv_note_name, priv_note_text, author) ;
    return pn1 ;
}

void
editTasks(User& loginUser, Project &c_project, int current_user_id){
    cout<<"*******************  EDIT TASKS *************************"<<endl;
    int edit_task_option;
    int task_option = 0;
    string pub_note_name,pub_note_text,author;
    string priv_note_name,priv_note_text;

    do {
        
        cout<< "1. Search for the Task"<<endl
            << "2. Add Tags"<<endl
            << "3. Add Private Notes" <<endl 
            << "4. Add Public Notes"<<endl
            << "5. Change Task Status"<<endl
            << "6. Go Back"<<endl;
    
        cin>>edit_task_option;
        switch(edit_task_option) {
            case 1:  //Search for the task
            cout<<"Searching for the task. "<<endl;
            break;

            case 2:  //Add tags
            cout<<"Adding tags. "<<endl;
            
            int task_id;
            // c_project.displayTasks();
            c_project.displayUserTasks(current_user_id);
            cout << "Select the task to add tags: ";
            cin  >> task_id;

            if (c_project.taskExists(task_id)) {
                Tags new_task_tag;
                c_project.addTaskTags(current_user_id,task_id,new_task_tag);
            } else {
                cout<<"Invalid task selection. Please try again. "<<endl;
            }
            break;

            case 3:  //Private Notes
            cout<<"Adding Private Notes. "<<endl;
            cout << "Enter note name: ";
            cin >> priv_note_name;
            cout << "Enter note text: ";
            cin >> priv_note_text;
            //global_createPrivateNote (priv_note_name,priv_note_text) ;
            //PrivateNotes private_notes(priv_note_name,priv_note_text);
            c_project.addTaskNotes(current_user_id,task_id, global_createPrivateNote (priv_note_name,priv_note_text) );
            break;

            case 4:  //Public Notes
            cout<<"Adding Public Notes. "<<endl;
            cout << "Enter Note Name: ";
            cin  >> pub_note_name;
            cout << "Enter Note text: ";
            cin  >> pub_note_text;
            cout << "Enter Author Name: ";
            cin  >> author;
            //PublicNotes public_notes(pub_note_name,pub_note_text,author);
            //c_project.addTaskNotes(current_user_id,task_id,public_notes);
            c_project.addTaskNotes(current_user_id,task_id, global_createPublicNote (pub_note_name,pub_note_text,author) );
            break;

            case 5:  //Task status change 
            cout <<"Select the task that you want to edit." <<endl;
            c_project.displayUserTasks (current_user_id);
            cout <<endl <<"Select your Task status selection: " <<endl ;
            cout<<"1. To-Do" <<endl
                <<"2. In-Progress" <<endl
                <<"3. Completed" <<endl ;

            
            
            switch (task_option) {

            case 1:
            c_project.changeTaskStatus (current_user_id, 0, "To-Do");
            break;

            case 2:
            c_project.changeTaskStatus (current_user_id, 0, "In-Progress");
            break;

            case 3:
            c_project.changeTaskStatus (current_user_id, 0, "Completed");
            break;

            default:
            cout<< "Invalid option. Please try again." << endl;        
            }   
            break;

            case 6: //Go back
            cout<<"Going back to the previous menu."<<endl;
    
        }
    cout<<"*********************************************************"<<endl;
    } while (edit_task_option!=6); 
}   
    
void
manageProjects(User& loginUser,Project& c_project, int c_user_id) {
    int project_options;

  //  cout<<"Projects for User: "<<user.get_user_name()<<endl;
   // for(int i=0;i<user.get_project_count();i++) {
    //    cout<<user.get_project(i).get_project_id_()<<" - "<<user.get_project(i).get_project_name_()<<endl;

    //}
    
     //cout<<"Select a Project: "<<endl;
    // cin>>project_options;

    //Project selected_project;
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
                editTasks(loginUser, c_project, c_user_id);
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