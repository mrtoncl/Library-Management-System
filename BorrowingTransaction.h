#ifndef BORROWINGTRANSACTION_H
#define BORROWINGTRANSACTION_H

#include <ctime>
#include <string>
#include <iostream>
#include "NotifySystem.h"
#include "BorrowableItem.h"
#include "Member.h" 

class NotifySystem;
/*
NotifySystem includes BorrowingTransaction and BorrowingTransaction also 
includes NotifySystem. This causes a circular dependency.
To fix this problem, i added this line. 
This solution is called forward declaration and can fix the problem.

Merve Ozkan
*/

class Member;

class BorrowingTransaction {
private:
    int transactionID;
    time_t borrowedDate;
    time_t dueDate;
    double penalty;

    bool penaltyApplied;
    NotifySystem *notifySystem;
    Member *member; 
    BorrowableItem *item; 

public:
    // Constructor
    BorrowingTransaction(int transactionID, time_t borrowedDate, time_t dueDate, Member* member, BorrowableItem* item);

    // Destructor
    ~BorrowingTransaction();

    // Geçikme süresini hesapla
    int calculateOverdue();

    // Ceza uygula
    void applyPenalty();
    // Cezayı al
     double getPenalty();

    void borrowItem();

    void returnItem();

    // Getter methodlar
    int getTransactionID() const;
    time_t getBorrowedDate() const;
    time_t getDueDate() const;
    void setPenalty(double penalty);


};

#endif
