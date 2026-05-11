#ifndef BOOK_H
#define BOOK_H

#include "BorrowableItem.h"

class Book : public BorrowableItem
{
protected:
  std::string ISBN;
  std::string authorName;


public:
  Book(const std::string &itemID, const std::string &title,
       const std::string &category, const std::string &ISBN, const std::string &authorName
       );

  std::string getISBN() const;
  std::string getAuthorName() const;

  void displayDetails() const;

    std::string getItemId() const override {
        return itemID;
    }
    std::string getCategory() const override {
        return category;
    }
};

#endif
