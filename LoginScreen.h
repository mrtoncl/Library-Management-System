#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include "LibraryDatabase.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <string>


class LoginScreen {
public:
    LoginScreen(LibraryDatabase &db);
    ~LoginScreen();
    void show();

private:
    Fl_Window* window;
    Fl_Box* title;
    Fl_Box* note;
    Fl_Input* usernameInput;
    Fl_Input* passwordInput;
    Fl_Button* loginButton;
    Fl_Box* signupText;
    Fl_Button* signupButton;

    LibraryDatabase *db;

    static void loginCallback(Fl_Widget* widget, void* data);
    static void signupCallback(Fl_Widget* widget, void* data);
};

#endif

