#include <iostream>
#include <ctime>
using namespace std;

class User;
class ProjectTeam;
class ProjectManagement;
class Task;
class Tags;


class ProjectTeam  {
    private:
    User team_members_ [5] ;
    int team_members_count_;
    User project_leader_;

    public:
    string
    get_project_leader_name_ () {
        return project_leader_.get_user_name ();
        }

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
    displayProjectTeam () {
        for (int i=0 ; i<5 ; i++) {
        cout <<"User " <<i <<": " <<endl; 
        team_members_[i].displayUserDetails();
        }
    }

    void
    searchUser (int id) {
        for (int i=1 ; i<=team_members_count_ ; i++) {
            if (id == team_members_[i].get_user_id ())
            team_members_[i].displayUserDetails ();
        }
    }

    void
    searchUser (string user_name) {
        for (int i=1 ; i<=team_members_count_ ; i++) {
            if (user_name == team_members_[i].get_user_name ())
            team_members_[i].displayUserDetails ();
        }
    }

};

class ProjectManagement {
    private:
    string project_name_;
    int project_id_;
    ProjectTeam team_;
    string project_due_date_;
    int no_of_tasks_;
    public:
    ProjectManagement()
    {
        project_name_="";
        project_id_=0;
        project_due_date_="";
    }
    ProjectManagement(string name,int id,ProjectTeam team,string due_date)
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
        cout <<"Project Leader: " <<team_.get_project_leader_name_() <<endl;
        cout <<"Project Team: "  <<endl;
        team_.displayProjectTeam ();
    }

    
};


// seperate text file for tags to store all tags
class Tags {
    private:
    string tag_name_;
    int tag_id_;

    public:
    int
    get_tag_id_ () {
        return tag_id_;
    }

    string
    get_tag_name_ () {
        return tag_name_;
    }

    void
    set_tag_name_ (string new_tag_name) {
        tag_name_ = new_tag_name;
    }

    void
    set_tag_id_ (int new_tag_id) {
        tag_id_ = new_tag_id;
    }


};

const int MAX_TASK_TAGS_ = 5;
class Task  {
    private:
    int task_id_;
    string task_name_;
    string task_due_date_;
    string task_status_;
    Tags task_tags_ [MAX_TASK_TAGS_];
    int tags_count_ = 0;
    int task_members_;

    public:

    Task ()  {}
    int
    get_task_id() {
        return task_id_;
    }

    void
    changeTaskStatus (int option) {
        switch (option) {

            case 1:
            task_status_ = "To-Do";
            break;

            case 2:
            task_status_ = "In-Progress";
            break;

            case 3:
            task_status_ = "Completed" ;
            break;

        }
    }

    void
    sendDueDateAlert () {
        
        //calculate current time using time.h library
        time_t current_time;
        struct tm* local_time;
        current_time = time(NULL);
        local_time = localtime(&current_time);
        //formatting time to DD/MM/YYYY
        char today_date [20];
        strftime(today_date, 20, "%d%m%Y", local_time);

        int today_day = stoi (today_date) / 1000000;
        int today_month = ( stoi (today_date) % 1000000) / 10000;
        int today_year = stoi (today_date) % 10000;

        int due_day = stoi (task_due_date_) / 1000000;
        int due_month = ( stoi (task_due_date_) % 1000000) / 10000;
        int due_year = stoi (task_due_date_) % 10000;

 
        if (today_year == due_year)
        if (today_month == due_month)
        // this block of code is only executed if todays year and month matches due dates year and month
        if (today_day > due_day)
        cout << "You are " <<today_day - due_day <<" days past your due date, please complete your task as soon as possible" ;
        else if (today_day + 3 >= due_day)  
        cout << "Please complete your task, you only have " <<due_day - today_day << " days to complete your task" ;

    }
    
    void
    addTaskTags (Tags new_task_tag ) {

        bool different = 1;
        for (int i=0 ; i<tags_count_ ; i++) 
        if ( task_tags_ [i].get_tag_id_ () == new_task_tag.get_tag_id_ () ) {
        different = 0;
        cout << "This tag already exists in this task" <<endl ;
        break;
        }

        
        if ( different )
        if (tags_count_ < MAX_TASK_TAGS_) {
        task_tags_ [tags_count_] = new_task_tag ;
        ++tags_count_;
        cout << "Tag: " <<new_task_tag.get_tag_name_ () <<" added succesfully" ;
        }
        else
        cout << "Maximum limit of 5 tags exceeded, please remove a tag to add another one" <<endl ;
    }

    void
    removeTaskTags (Tags new_task_tag ) {

        for (int i=0 ; i<tags_count_ ; i++) {
        if ( task_tags_ [i].get_tag_id_ () == new_task_tag.get_tag_id_ () ) {
            task_tags_ [i].set_tag_id_ (0);
            task_tags_ [i].set_tag_name_ ("n/a");
            --tags_count_;
            break;
        }
        }
    }

    void
    displayTaskDetails () {
        cout <<"Task ID: " <<task_id_ <<endl;
        cout <<"Task Name: " <<task_name_ <<endl;
        cout <<"Task Due Date: " <<task_due_date_ <<endl;
        cout <<"Task Status: " <<task_status_ <<endl;

        cout <<"Task Tags: " <<endl;
        for (int i=0 ; i<tags_count_; i++) {
        cout <<task_tags_ [i].get_tag_id_ () <<" - " <<task_tags_ [i].get_tag_name_ () ;
        
        }
    }


};


class User {
    private:
    static int user_count_;
    int user_id_;
    static int vacant_id_slots_ [10];
    static int vacant_id_slots_counter_;
    string user_name_;
    string user_email_;
    string user_password_;
    ProjectManagement project_ [5];
    int project_count;
    
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
        return project_count;
    }
    
    string 
    get_user_name() {
        return user_name_;
    }

    ProjectManagement& get_project(int index) {
        return project_[index];
    }

    void
    display_projects_ () {
        for (int i=0 ; i < project_count ; i++) {
        cout <<endl <<project_ [i].get_project_id_ () <<" - " <<project_ [i].get_project_name_ () ;  
        }
    }

    void
    viewProfile () {
        cout <<"Projects: " <<endl;

    }

    void
    generateReport () {}


    void
    addProject (ProjectManagement newproject ) {
        project_ [ project_count ] = newproject;
        project_count++;
    }

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

// ---------------------------------------------------------------------------------------------------------------------------- //

void
loginMenu (int &login_switch) {
    cout<< "1. Create New User" <<endl
    << "2. Login" <<endl 
    << "3. Exit Program" <<endl ;
    cin >> login_switch;
}

void
signupForm (User& newUser) {
    string temp_user_name;
    string temp_user_email;
    string temp_user_password;

    cout << "Enter Username: "  ;
    cin >> temp_user_name;
    cout << "Enter Email: " ;
    cin >> temp_user_email;
    cout << "Enter Password: " ;
    cin >> temp_user_password;

    newUser= User (temp_user_name,temp_user_email,temp_user_password) ;
    cout<<"New user created successfully."<<endl;
    cout <<endl;
}

void
loginForm (User& user) {
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
createProject(User &user) {
        string project_name;
        string project_due_date;
        ProjectTeam team;
        cout<<"Enter Project Name: "; 
        cin>>project_name;
        cout<<"Enter Project Due Date: ";
        cin>>project_due_date;    

        user.addProject(ProjectManagement(project_name,0, team,project_due_date));
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
manageProjects(User& user) {
    int project_options;

  //  cout<<"Projects for User: "<<user.get_user_name()<<endl;
    for(int i=0;i<user.get_project_count();i++) {
        cout<<user.get_project(i).get_project_id_()<<" - "<<user.get_project(i).get_project_name_()<<endl;

    }
    
    cout<<"Select a Project: "<<endl;
    cin>>project_options;

    ProjectManagement selected_project;
    for(int i=0;i<user.get_project_count();i++)
    {
        if(user.get_project(i).get_project_id_() == project_options)
        {
            selected_project= user.get_project(i);
            break;
        }

    }
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
                editTasks(user);
                break;

                case 3: //Go Back
                cout<<"Going back."<<endl;
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
            signupForm (newUser);
            break;

            case 2:
            loginForm (newUser); 
            user_login=1;
            while (user_login)  //when value of the user login will be updated so run the while loop!
                {
                    int project_switch;
                    projectMenu (project_switch);

                    switch(project_switch)
                    {
                        case 1:    //Create a Project
                        createProject(newUser);
                        break;
                        
                        case 2:  //Add a Project
                        break;

                        case 3:  //Manage Projects
                        manageProjects(newUser);
                        break;

                        case 4:  //View Profile
                        cout<<"Viewing Profile."<<endl;
                        break;
                        
                        case 5:  //Go Back
                        cout<<"Going back."<<endl;
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