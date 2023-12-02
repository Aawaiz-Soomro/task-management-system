//
#include <iostream>
using namespace std;
#include <user.h>


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

    User
    searchUser (int id) {
        for (int i=1 ; i<=team_members_count_ ; i++) {
            if (id == team_members_[i].get_user_id ()) {
            team_members_[i].displayUserDetails ();
            return team_members_ [i] ;
            }
        }
    }

    User
    searchUser (string user_name) {
        for (int i=1 ; i<=team_members_count_ ; i++) {
            if (user_name == team_members_[i].get_user_name ()) {
            team_members_[i].displayUserDetails ();
            return team_members_ [i] ;        
            }
        }
    }

};
//