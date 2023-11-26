#include <casses.cc>


int main () {
    
    int login_switch;
    bool user_login = 0;

    do {
        cout<< "1. Create New User" <<endl
            << "2. Login" <<endl;

        switch (login_switch) {

            case1:
            string user_name;
            string user_email;
            string user_password;

            cout << "Enter Username: " <<endl ;
            cin >> user_name;
            cout << "Enter Email: " ;
            cin >> user_email;
            cout << "Enter Password" ;
            User (user_name,user_email,user_password, 0) ;
            break;

            case2:
            cout << "Enter Username: " <<endl ;
            cin >> user_name;
            cin >> user_email;
            cout << "Enter Password" ;
            break;
            // call auth function;
        
        }
    } while (user_login == 0) ;
    
return 0;
}