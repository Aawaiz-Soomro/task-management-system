#ifndef TASKS_H
#define TASKS_H

#include <iostream>
#include <fstream>
#include <ctime>
#include "project.h"
using namespace std;



// seperate text file for tags to store all tags
class Tags {
    private:
    string tag_name_;
    int tag_id_;

    public:

    Tags () {
        tag_id_ = 0;
        tag_name_ = "";
    }

    Tags (string name) {
        tag_name_ = name;
        tag_id_++;
    }

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

    Notes () {
        note_id_ = 0;
        note_name_ = "";
        note_text_ = "";
    }

    Notes (string name, string text) {
        note_name_ = name;
        note_text_ = text;
    }

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

class PublicNotes : public Notes {
    string note_author;
    public:
    PublicNotes (string name, string text, string author) : Notes (name, text) {
            note_author = author;
    }
    PublicNotes () {}

    void
    displayNote () {
    cout << note_author <<": " <<endl;
    Notes::displayNote() ;
    }
};

class PrivateNotes : public Notes {
    public:
    PrivateNotes (string name, string text) : Notes (name, text) {}
    PrivateNotes () {}

};
const int MAX_NO_OF_TASKS = 5;
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
    PublicNotes public_task_notes_ [MAX_TASK_NOTES_];
    PrivateNotes private_task_notes_ [MAX_TASK_NOTES_];
    int public_notes_count_;
    int private_notes_count_ ;
    int task_members_;
    static int task_count;

    public:

    Task ()  {

        task_id_ = 0;
        task_name_ = "";
        task_due_date_ = "";
        task_status_ = "";
    }
    
    int
    createTask (string name, string due_date) {
        if (task_count < MAX_NO_OF_TASKS) {
            task_id_ = task_count + 1; 
            task_name_ = name;
            task_due_date_ = due_date;
            task_status_ = "To-do";
            cout<<"Task created successfully."<<endl;
            return task_id_;
        }
    }
    
    int
    get_task_id() {
        return task_id_;
    }

    void
    set_task_id (int new_task_id) {
        task_id_ = new_task_id;
    }

    void
    changeTaskStatus (string task_status) {
        task_status_ = task_status;
    }

    void
    sendDueDateAlert (string user_email) {
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

        string body = "";
 
        if (today_year == due_year)
        if (today_month == due_month)
        // this block of code is only executed if todays year and month matches due dates year and month
        if (today_day > due_day) {
            /* body = "You are " + std::to_string(today_day - due_day) + " days past your due date for Task id: " +
            task_id + " named: " + task_name + ", please complete your task as soon as possible"; */
        cout << "You are " <<today_day - due_day <<" days past your due date for Task id: " <<task_id_ <<" named: " <<task_name_ <<", please complete your task as soon as possible" ; 
        }
        else if (today_day + 3 >= due_day) {
        cout << "Please complete your task, you only have " <<due_day - today_day << " days to complete your task: " <<task_id_ <<" named: " <<task_name_ ;
        /* body = "Please complete your task, you only have " + std::to_string(due_day - today_day) + " days to complete your task: " +
               task_id + " named: " + task_name; */
        }
        else
        return;

    //    sendEmail(user_email, subject, body);
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
        cout << "Tag: " <<new_task_tag.get_tag_name_ () <<" added succesfully" <<endl;
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
    addTaskNotes (PublicNotes new_task_note ) {

        if (public_notes_count_ < MAX_TASK_NOTES_) {
        public_task_notes_ [public_notes_count_] = new_task_note ;
        ++public_notes_count_;
        cout << "Tag: " <<new_task_note.get_note_name_ () <<" added succesfully" <<endl;
        }
        else
        cout << "Maximum limit of 5 Notes exceeded, please remove a Note to add another one" <<endl ;
    }

    void
    addTaskNotes (PrivateNotes new_task_note ) {

        if (public_notes_count_ < MAX_TASK_NOTES_) {
        private_task_notes_ [private_notes_count_] = new_task_note ;
        ++private_notes_count_;
        cout << "Tag: " <<new_task_note.get_note_name_ () <<" added succesfully" <<endl;
        }
        else
        cout << "Maximum limit of 5 Notes exceeded, please remove a Note to add another one" <<endl ;
    }

    /* void
    removeTaskNotes (Notes new_task_note ) {

        for (int i=0 ; i<notes_count_ ; i++) {
        if ( public_task_notes_ [i].get_note_id_ () == new_task_note.get_note_id_ () ) {
            public_task_notes_ [i].set_note_id_ (0);
            public_task_notes_ [i].set_note_name_ ("n/a");
            --notes_count_;
            break;
        }
        }
    } */

    void
    displayTaskDetails () {
        cout <<"Task ID: " <<task_id_ <<endl;
        cout <<"Task Name: " <<task_name_ <<endl;
        cout <<"Task Due Date: " <<task_due_date_ <<endl;
        cout <<"Task Status: " <<task_status_ <<endl;

        cout <<"Task Tags: " <<endl;
        cout <<"Tags count is: " <<tags_count_ <<endl;
        cout <<"Task tags [0] Name: " <<task_tags_ [0].get_tag_name_ ();
        cout <<"Task tags [0] ID: " <<task_tags_ [0].get_tag_id_ ();
        cout <<"Task tags [1] Name: " <<task_tags_ [1].get_tag_name_ ();
        cout <<"Task tags [1] ID: " <<task_tags_ [1].get_tag_id_ ();
        for (int i=0 ; i<tags_count_; i++) {
        cout <<task_tags_ [i].get_tag_id_ () <<" - " <<task_tags_ [i].get_tag_name_ () <<endl ;
        }

        /* cout <<"Task Notes: " <<endl;
        for (int i=0 ; i<public_notes_count_; i++) {
        cout <<public_task_notes_ [i].get_note_id_ () <<" - " <<public_task_notes_ [i].get_note_name_ () ;
        } */
    }

    void
    editTaskDueDate (string new_due_date) {
        task_due_date_ = new_due_date;
    }

    void
    displayPrivateNotes () {
        for (int i=0 ; i< this ->private_notes_count_ ; i++) {
            private_task_notes_ [i].displayNote();
        }
    }

    void
    displayPublicNotes () {
        for (int i=0 ; i< this ->public_notes_count_ ; i++) {
            public_task_notes_ [i].displayNote();
        }
    }

    friend class Project;
};

int
Task :: task_count = 0;

#endif  
// ---------------------------------------------------------------------------------------------------------------------------- //