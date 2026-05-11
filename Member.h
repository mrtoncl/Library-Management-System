#ifndef MEMBER_H
#define MEMBER_H

#include <list>
#include "User.h"
#include "BorrowableItem.h"
#include "NotifySystem.h"
#include "LibraryDatabase.h"

class NotifySystem;

class Member : public User{
private:
    double penaltyRate{};
    LibraryDatabase* database;
public:
    Member(string userID, string userName, string email, string password, LibraryDatabase* db);

    void borrowItem(BorrowableItem *item);
    void returnItem(BorrowableItem *item, NotifySystem *notifySystem);
    void reserveItem(BorrowableItem *item);

    double getPenaltyRate() const;
    void loadItem(const BorrowableItem& item);

    void login() override;
    void logout() override;

};

#endif 
