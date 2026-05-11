#include <iostream>
#include "Member.h"
#include "NotifySystem.h"
using namespace std;

Member::Member(string userID, string userName, string email, string password, LibraryDatabase* db)
    :   User(userID, userName, email, password, penaltyRate), database(db) {}

void Member::borrowItem(BorrowableItem* item) {
    if (!item->checkAvailability()) {
        cout << "Item is not available for borrowing.\n";
        return;
    }

    if (!item->getReservingUserID().empty() && item->getReservingUserID() != this->getUserID()) {
        cout << "Item is reserved by another user.\n";
        return;
    }

    item->setCurrentStatus(1); // Set status to borrowed
    cout << "You have successfully borrowed: " << item->getTitle() << "\n";
}

void Member::returnItem(BorrowableItem* item, NotifySystem* notifySystem) {
    int currentStatus = item->getcurrentStatus();

    if (currentStatus == 0) {
        cout << "This item is not currently borrowed.\n";
        return;
    }

    if (currentStatus == 2) { // Borrowed and reserved
        cout << "Item has been returned and reserved for user: " 
             << item->getReservingUserID() << "\n";
        item->setCurrentStatus(1); // Maintain reserved status
    } else {
        item->setCurrentStatus(0); // Set status to available
        cout << "Item has been successfully returned.\n";
    }
}

void Member::reserveItem(BorrowableItem* item) {
    if (item->getcurrentStatus() == 0) {
        std::cout << "Item is available. You can borrow it directly, no need for reserving!\n";
    } else if (item->getcurrentStatus() == 1) {
        item->setCurrentStatus(2);
        std::cout << "Item has been reserved for you: " << item->getTitle() << "\n";
    } else {
        std::cout << "Item is already reserved by another member.\n";
    }
}

void Member::loadItem(const BorrowableItem& item){
    database->loadItem(item);
}

double Member::getPenaltyRate() const {
    return penaltyRate;
}
void Member::login() {
    cout << "Member " << getUserName() << " logged in.\n";
}

void Member::logout() {
    cout << "Member " << getUserName() << " logged out.\n";
}


