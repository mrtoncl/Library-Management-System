#ifndef ADMIN_H
#define ADMIN_H

#include<list>
#include "User.h"
#include "Member.h"
#include "BorrowableItem.h"
#include "LibraryDatabase.h"

class LibraryDatabase;

class Admin : public User{
    private:
        LibraryDatabase* database;
    public:
        Admin(string userID, string userName, string email, string password,double penaltyRate, LibraryDatabase* database);
        void addItem(BorrowableItem* item);
        void deleteItem(BorrowableItem* item);
        void loadItem(const BorrowableItem& item);
        void addUser(const string& id, const string& name, const string& email, const int& password);
        void deleteUser(const string& userID);
        void loadUser(const User& userID);

        void searchItem(const string& title) const;

        void login() override;
        void logout() override;
        
};

#endif
