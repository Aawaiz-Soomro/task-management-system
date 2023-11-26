#include <iostream>
using namespace std;
#include <ctime>

class ProjectManangement {
    private:
    string project_name_;
    int project_id_;
    string project_due_date;
    int no_of_tasks_;
};

class ProjectTeam : public ProjectManangement {
    private:
    string team_members_ [20] ;
    string project_leader_name_;
};

const int MAX_TASK_TAGS_ = 5;
class Task : public ProjectManangement {
    private:

    string task_name_;
    int task_id_;
    string task_due_date;
    string task_status_;
    Tags task_tags_ [MAX_TASK_TAGS_];
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

        int due_day = stoi (task_due_date) / 1000000;
        int due_month = ( stoi (task_due_date) % 1000000) / 10000;
        int due_year = stoi (task_due_date) % 10000;


        
        if (today_year == due_year)
        if (today_month == due_month)
        // this block of code is only executed if todays year and month matches due dates year and month
        if (today_day > due_day)
        cout << "You are " <<today_day - due_day <<" days past your due date, please complete your task as soon as possible" ;
        else if (today_day + 3 >= due_day)  
        cout << "Please complete your task, you only have " <<due_day - today_day << " days to complete your task" ;

    }
    
    int count = 0;
    void
    addTaskTags (Tags new_task_tag ) {

        bool different = 1;
        for (int i=0 ; i<count ; i++) 
        if ( task_tags_ [i].get_tag_id_ () == new_task_tag.get_tag_id_ () ) {
        different = 0;
        cout << "This tag already exists in this task" <<endl ;
        break;
        }

        
        if ( different )
        if (count < MAX_TASK_TAGS_) {
        task_tags_ [count] = new_task_tag ;
        ++count;
        cout << "Tag: " <<new_task_tag.get_tag_name_ () <<" added succesfully" ;
        }
        else
        cout << "Maximum limit of 5 tags exceeded, please remove a tag to add another one" <<endl ;
    }

    void
    removeTaskTags (Tags new_task_tag ) {

        for (int i=0 ; i<count ; i++) {
        if ( task_tags_ [i].get_tag_id_ () == new_task_tag.get_tag_id_ () ) {
            task_tags_ [i].set_tag_id_ (0);
            task_tags_ [i].set_tag_name_ ("n/a");
            --count;
            break;
        }
        }

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

class User {
    private:
    int user_id_;
    string user_name_;
    string user_email_;
    string user_password_;
    
    public:
    User(string username,string email,string password,int userid):user_name_(username),user_email_(email),user_password_(password),user_id_(userid){}
    
    User()
    {
        user_name_="";
        user_email_="";
        user_password_="";
        user_id_ = 0;
    }

};