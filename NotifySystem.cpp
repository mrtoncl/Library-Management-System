#include "NotifySystem.h"
#include <iostream>
#include <vector>


void NotifySystem::sendNotification(int notificationID, const std::string& message) {
   for(size_t i=0; i < notifications.size(); ++i){
        if(notifications[i].notificationID == notificationID){
          std::cout << "Sending Notification ID " << notificationID << ": " << message << std::endl;
             return;
        }
    }
         std::cout << "Notification " << notificationID << " not found" << std::endl;
}
void NotifySystem::deleteNotification(int notificationID){
   for(size_t i=0; i < notifications.size(); ++i){
        if(notifications[i].notificationID == notificationID){
            notifications.erase(notifications.begin()+i);
            std::cout << "Notification " << notificationID << " deleted" << std::endl;
            return;
        }
    }
    std::cout << "Notification " << notificationID << " not found" << std::endl;

}
std::string NotifySystem::getNotification(int notificationID){
    for(size_t i=0; i < notifications.size(); ++i){
        if(notifications[i].notificationID == notificationID){
            return notifications[i].message;
        }
    }
      std::cout << "Notification " << notificationID << " not found" << std::endl;
    return "Notification not found";
}
void NotifySystem::createNotification(int notificationID, const std::string& message){
    Notification newNotification;
    newNotification.notificationID = notificationID;
    newNotification.message = message;
    notifications.push_back(newNotification);
    std::cout << "Notification " << notificationID << " created" << std::endl;
}


