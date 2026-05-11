#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "BorrowableItem.h"

class Magazine : public BorrowableItem
{
private:
  std::string issueNumber;
  std::string publicationDate;

public:
  Magazine(const std::string &itemID, const std::string &title,
            const std::string &category, const std::string &issueNumber, const std::string &publicationDate);

  std::string getIssueNumber() const;
  std::string getPublicationDate() const;
  void displayDetails() const;
};

#endif
