#include <iostream>
#include "User.h"
using namespace std;

User::User(string userID, string userName, string email, string password, double penaltyRate)
    :   userID(userID), userName(userName), email(email), password(password),
         penaltyRate(penaltyRate)   {}

