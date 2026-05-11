#ifndef CD_H
#define CD_H

#include "BorrowableItem.h"

class CD : public BorrowableItem
{
private:
  std::string artist;
  std::string genre;

public:
  CD(const std::string &itemID, const std::string &title,
      const std::string &category, const std::string &artist, const std::string &genre);

  std::string getArtist() const;
  std::string getGenre() const;

  // added every item to check if the codes working
  void displayDetails() const;
};

#endif
