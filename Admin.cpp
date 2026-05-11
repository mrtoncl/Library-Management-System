#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Admin.h"

using namespace std;

Admin::Admin(string userID, string userName, string email, string password, double penaltyRate,
           LibraryDatabase* db)
    :   User(userID, userName, email, password, penaltyRate), database(db) {}

void Admin::loadItem(const BorrowableItem& item){
    database->loadItem(item);
}

void Admin::addItem(BorrowableItem* item){
    database->addItem(item);
}

void Admin::deleteItem(BorrowableItem* item) {
    database->deleteItem(item);
}

void Admin::addUser(const string& id, const string& name, const string& email, const int& password) {
    database->addUser(id,name,email,password);
}

void Admin::deleteUser(const string& userID) {
    database->deleteUser(userID);
}

void Admin::loadUser(const User& userID) {
    database->loadUser(userID);
}

void Admin::login() {
    cout << "Admin " << getUserName()  << " logged in.\n";
}

void Admin::logout() {
    cout << "Admin " << getUserName() << " logged out.\n";
}
