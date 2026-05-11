#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <fstream>
#include <sstream>
#include <random>
#include <FL/Fl_Input.H>
#include <FL/fl_ask.H>
#include <stdlib.h>
#include "BorrowableItem.h"
#include "User.h"
#include "Book.h"
#include "Magazine.h"
#include "CD.h"
#include "Member.h"

using namespace std;

class AdminDashboard {
public:
    AdminDashboard(LibraryDatabase &db);
    void show();
    string generateItemId();

    std::string generateUniqueItemId(AdminDashboard *screen);
    std::string generateUniqueUserId(AdminDashboard *screen);
    //void addItemToDb(const std::string& type,
    //const std::string& title, const std::string& category, const std::string& extra1, const std::string& extra2 = "");
    static void addItemCallback(Fl_Widget* widget, void* data);
    static void addUserCallback(Fl_Widget* widget, void* data);
    static void deleteItemCallback(Fl_Widget* widget, void* data);
    static void deleteUserCallback(Fl_Widget* widget, void* data);
    static void searchUserCallback(Fl_Widget* widget, void* data);
    //LibraryDatabase getDB();

    void deleteUserButtonCallback(Fl_Widget *widget, void *data);
    /*
    Addıtemdb yerine admindashboard ve daha pek çok class constructorlara database alacak. 
    Database mainde üretilecek ve diğer classlara adresi gönderilecek. 
    databasein içindeki fonksiyonlar kullanılarak item eklenecek. 

    */



private:
    Fl_Window* window;
    Fl_Box* title;
    Fl_Box* selectionText;
    Fl_Button* addItemButton;
    Fl_Button* addUserButton;
    Fl_Button* deleteItemButton;
    Fl_Button* deleteUserButton;
    Fl_Button* searchUserButton;
    Fl_Button* logoutButton;

    LibraryDatabase *db;
};

#endif

