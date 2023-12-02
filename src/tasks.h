#ifndef TASKS_H
#define TASKS_H

#include <iostream>
#include <ctime>
using namespace std;



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

class Notes {
    private:
    string note_name_;
    int note_id_;
    string note_text_;

    public:
    int
    get_note_id_ () {
        return note_id_;
    }

    string
    get_note_name_ () {
        return note_name_;
    }

    void
    set_note_name_ (string new_note_name) {
        note_name_ = new_note_name;
    }

    void
    set_note_id_ (int new_note_id) {
        note_id_ = new_note_id;
    }
    
    void
    writeNote (string note_text) {
        note_text_ = note_text;
    }

    void
    displayNote () {
        cout << note_text_ <<endl;
    }

};

const int MAX_TASK_TAGS_ = 5;
const int MAX_TASK_NOTES_ = 5;
class Task  {
    private:
    int task_id_;
    string task_name_;
    string task_due_date_;
    string task_status_;
    Tags task_tags_ [MAX_TASK_TAGS_];
    int tags_count_ = 0;
    Notes task_notes_ [MAX_TASK_NOTES_];
    int notes_count_ = 0;
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
    addTaskNotes (Notes new_task_note ) {

        bool different = 1;
        for (int i=0 ; i<notes_count_ ; i++) 
        if ( task_notes_ [i].get_note_id_ () == new_task_note.get_note_id_ () ) {
        different = 0;
        cout << "This tag already exists in this task" <<endl ;
        break;
        }

        
        if ( different )
        if (notes_count_ < MAX_TASK_NOTES_) {
        task_notes_ [notes_count_] = new_task_note ;
        ++notes_count_;
        cout << "Tag: " <<new_task_note.get_note_name_ () <<" added succesfully" ;
        }
        else
        cout << "Maximum limit of 5 Notes exceeded, please remove a Note to add another one" <<endl ;
    }

    void
    removeTaskNotes (Notes new_task_note ) {

        for (int i=0 ; i<notes_count_ ; i++) {
        if ( task_notes_ [i].get_note_id_ () == new_task_note.get_note_id_ () ) {
            task_notes_ [i].set_note_id_ (0);
            task_notes_ [i].set_note_name_ ("n/a");
            --notes_count_;
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

        cout <<"Task Notes: " <<endl;
        for (int i=0 ; i<notes_count_; i++) {
        cout <<task_notes_ [i].get_note_id_ () <<" - " <<task_notes_ [i].get_note_name_ () ;
        }
    }

    void
    editTaskDueDate (string new_due_date) {
        task_due_date_ = new_due_date;
    }

};
#endif



// ---------------------------------------------------------------------------------------------------------------------------- //