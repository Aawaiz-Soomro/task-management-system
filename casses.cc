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

const int MAX_TASK_TAGS_ = 10;
class Task : public ProjectManangement {
    private:

    string task_name_;
    int task_id_;
    string task_due_date;
    string task_status_;
    Tags task_tags_ [MAX_TASK_TAGS_];
    int task_members_;


    Task ()  {

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
 
    void
    addTaskTags () {

    }


};

// seperate text file for tags to store all tags
class Tags {
    private:
    string tag_name;
    int tag_id;


};