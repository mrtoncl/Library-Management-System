#include "BorrowingTransaction.h"
#include "NotifySystem.h"
#include <iostream>
#include <ctime>
#include <cmath>

BorrowingTransaction::BorrowingTransaction(int transactionID, time_t borrowedDate, time_t dueDate, Member* member, BorrowableItem* item)
    : transactionID(transactionID), borrowedDate(borrowedDate), dueDate(dueDate), penalty(0.0), penaltyApplied(false), notifySystem(nullptr), member(member),item(item) {}

BorrowingTransaction::~BorrowingTransaction() {}

int BorrowingTransaction::calculateOverdue() {
    time_t now = time(0);
    double diffInDays = difftime(now, dueDate) / (60 * 60 * 24);
    if (diffInDays > 0) {
        return static_cast<int>(std::ceil(diffInDays));
    } else {
        return 0;
    }
}

void BorrowingTransaction::applyPenalty() {
    if (!penaltyApplied) {
        int overdueDays = calculateOverdue();
        if (overdueDays > 0) {
            double dailyPenaltyRate = 2.0;
            this->penalty = overdueDays * dailyPenaltyRate;
            if(notifySystem)
               notifySystem->sendNotification(1, "Penalty applied for BorrowingTransaction");
            std::cout << "Penalty applied: " << penalty << " for " << overdueDays << " overdue days." << std::endl;
            penaltyApplied = true;
        }else{
            if(notifySystem)
               notifySystem->sendNotification(2, "No penalty for BorrowingTransaction");
            std::cout << "No penalty applied, not yet overdue." << std::endl;
        }
    } else {
        std::cout << "Penalty already applied for this transaction." << std::endl;
    }
}
double BorrowingTransaction::getPenalty() {
    return penalty;
}

int BorrowingTransaction::getTransactionID() const {
    return transactionID;
}

time_t BorrowingTransaction::getBorrowedDate() const {
    return borrowedDate;
}

time_t BorrowingTransaction::getDueDate() const {
    return dueDate;
}
void BorrowingTransaction::setPenalty(double penalty) {
     this->penalty = penalty;
}

void BorrowingTransaction::borrowItem() {
   if(member && item)
   {
       member->borrowItem(item);
   }
    else{
         std::cout << "Member or Item not found" << std::endl;
    }
}
void BorrowingTransaction::returnItem() {
  if(member && item)
   {
       member->returnItem(item, notifySystem);
   }
   else{
        std::cout << "Member or Item not found" << std::endl;
   }
}