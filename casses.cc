#include <iostream>
#include <ctime>
using namespace std;


class ProjectManangement {
    private:
    string project_name_;
    int project_id_;
    ProjectTeam team_;
    string project_due_date_;
    int no_of_tasks_;
    public:
    ProjectManangement()
    {
        project_name_="";
        project_id_=0;
        project_due_date_="";
    }
    ProjectManangement(string name,int id,ProjectTeam team,string due_date)
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
    //    cout <<"Project Team: "  <<endl;
    }
};

class ProjectTeam : public ProjectManangement {
    private:
    string team_members_ [20] ;
    string project_leader_name_;

    public:
    string
    get_project_leader_name_ () {
        return project_leader_name_;
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
class Task : public ProjectManangement {
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
    string user_name_;
    string user_email_;
    string user_password_;
    ProjectManangement project_ [5];
    int project_count;
    
    public:
    User(string username,string email,string password):user_name_(username),user_email_(email),user_password_(password) {
        user_count_++;
    }
    
    User()
    {
        user_id_ = user_count_;
        user_name_="";
        user_email_="";
        user_password_="";
        user_count_ ++;
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
    add_project (ProjectManangement newproject ) {
        project_ [ project_count ] = newproject;
        project_count++;
    }


};
int
User :: user_count_ = 0;

void
loginMenu (int &login_switch) {
    cout<< "1. Create New User" <<endl
    << "2. Login" <<endl ;
    cin >> login_switch;
}

void
signupForm (string &temp_user_name, string &temp_user_email, string &temp_user_password) {

    cout << "Enter Username: "  ;
    cin >> temp_user_name;
    cout << "Enter Email: " ;
    cin >> temp_user_email;
    cout << "Enter Password: " ;
    cin >> temp_user_password;

    User (temp_user_name,temp_user_email,temp_user_password) ;
    cout<<"New user created successfully."<<endl;
    cout <<endl;
}

void
loginForm (string &temp_user_email, string &temp_user_password) {

    cout << "Enter E-Mail: " ;
    cin >> temp_user_email;
    cout << "Enter Password: " ;
    cin >> temp_user_password;
}


int main () {

    int login_switch;
    string temp_user_name;
    string temp_user_email;
    string temp_user_password;
    bool user_login = 0;

    do {
        
        loginMenu (login_switch);

        switch (login_switch) {
        
            case 1:
            signupForm (temp_user_name, temp_user_email, temp_user_password);
            break;

            case 2:
            loginForm (temp_user_email, temp_user_password);
            break;
            
            do
            {
                int project_switch;
                string project_name;
                int project_id;
                string project_due_date;
                ProjectTeam team;
                cout<< "1. Create a Project" <<endl
                    << "2. Add Project" <<endl
                    << "3. Manage Project" <<endl
                    << "4. View Profile" <<endl;
                switch(project_switch)
                {
                    case 1:    // Create a Project
                    cout<<"Enter Project Name: "; 
                    cin>>project_name;
                    cout<<"Enter Project Id: ";
                    cin>>project_id;
                    cout<<"Enter Project Due Date: ";
                    cin>>project_due_date;
                    ProjectManangement(project_name,0,team,project_due_date);
                    cout<<"Project have been successfully created."<<endl;
                    break;
                    
                    case 2:  //Add a Project

                    break;

                    case 3:  //Manage Projects
                    
                    



                }
            } while (1);
            user_login = 1;
            cout <<endl;
            break;
            // call auth function;
        
        }

    } while (user_login == 0) ;
    if(user_login=1)
    {
        
        
    }
return 0;
}