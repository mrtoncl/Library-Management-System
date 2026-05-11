#ifndef BORROWABLEITEM_H
#define BORROWABLEITEM_H

#include <string>

using namespace std;


class BorrowableItem
{

protected:
  std::string itemID;
  std::string title;
  std::string category;
  int currentStatus;
  std::string reservedUserID;


public:
    virtual ~BorrowableItem() = default;
    virtual std::string getItemId() const = 0;
    virtual std::string getCategory() const = 0;
  BorrowableItem(const std::string &itemID,
                 const std::string &title,
                 const std::string &category
                 );


  bool checkAvailability() const;
    void setCurrentStatus(int status);
  void reserveItem(const std::string& userID);
  void clearReservation();
  string getReservingUserID() const;

  string getTitle() const;
  int getcurrentStatus() const;


//Reservations will be held by database
};

#endif
