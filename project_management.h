#include <iostream>
#include <project_team.h>
#include <tasks.h> 
using namespace std;

const int MAX_NO_OF_TASKS = 5;
class ProjectManagement {
    private:
    string project_name_;
    int project_id_;
    ProjectTeam team_;
    string project_due_date_;
    int no_of_tasks_;
    Task project_tasks [MAX_NO_OF_TASKS] ;
    
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
