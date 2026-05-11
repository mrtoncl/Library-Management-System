#include "BorrowableItem.h"
#include <iostream>
using namespace std;

BorrowableItem::BorrowableItem(const std::string &itemID,
                                const std::string &title,
                               const std::string &category
                               )
    : itemID(itemID), title(title), category(category), currentStatus(0) {
    reservedUserID = "";
}

bool BorrowableItem::checkAvailability() const {
    return currentStatus == 0; // Available if status is 0
}

void BorrowableItem::setCurrentStatus(int newStatus) {
    if (newStatus < 0 || newStatus > 2) {
        throw std::invalid_argument("Invalid status value");
    }
    currentStatus = (newStatus);
}
void BorrowableItem::reserveItem(const std::string& userID) {
    if (currentStatus == 1) { // Borrowed but not reserved
        currentStatus = 2; // Borrowed and reserved
        reservedUserID = userID;
        cout << "Item reserved for user: " << userID << "\n";
    } else {
       cout << "Cannot reserve this item. Already reserved by other user.\n";
    }
}

void BorrowableItem::clearReservation() {
    if (currentStatus == 2) { // Reserved
        reservedUserID.clear();
        currentStatus = 0 ; // Mark as available
        cout << "Reservation cleared.\n";
    }
}

std::string BorrowableItem::getTitle() const {
    return title;
}

int BorrowableItem::getcurrentStatus()const {
    return currentStatus;
}

std::string BorrowableItem::getReservingUserID() const {
    return reservedUserID;
}
