#ifndef USER_H
#define USER_H

using namespace std;

#include <string>

class User{
    private:
        string userID;
        string userName;
        string password;
        string email;
        double penaltyRate = 0;



    public:
        virtual ~User() = default;

        User(string userID, string userName, string email, string password, double penaltyRate);
        virtual void login() = 0;
        virtual void logout() = 0;


    string getUserID() const {
            return userID;
        };
    string getUserName() const {
            return userName;
        };
    string getEmail() const {
            return email;
        };
    string getPassword() const {
            return password;
        };



};

#endif
