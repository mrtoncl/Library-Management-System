#ifndef NOTIFYSYSTEM_H
#define NOTIFYSYSTEM_H

#include <string>
#include <vector>

#include "Admin.h"        
#include "Member.h"        
#include "BorrowingTransaction.h"
#include "BorrowableItem.h"  

class BorrowingTransaction;
/*
NotifySystem includes BorrowingTransaction and BorrowingTransaction also 
includes NotifySystem. This causes a circular dependency.
To fix this problem, i added this line. 
This solution is called forward declaration and can fix the problem.

Merve Ozkan
*/

class NotifySystem {
public:
    // Bildirim gönderme metodu
    void sendNotification(int notificationID, const std::string& message);
    // Bildirimi silme metodu
    void deleteNotification(int notificationID);
    // Bildirimi alma metodu
    std::string getNotification(int notificationID);
    // Bildirim oluşturma
    void createNotification(int notificationID, const std::string& message);

private:
  struct Notification{
      int notificationID;
      std::string message;
  };
    // Tüm notification'ları saklamak için bir vector
    std::vector<Notification> notifications;
};

#endif
