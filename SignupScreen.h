#ifndef SIGNUPSCREEN_H
#define SIGNUPSCREEN_H

#include "LibraryDatabase.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <string>
#include <stdlib.h>

class SignupScreen {
public:
    SignupScreen(LibraryDatabase &db);
    ~SignupScreen();
    void show();
    std::string generateUniqueId(SignupScreen *screen);

private:
    Fl_Window* window;
    Fl_Input* nameInput;
    Fl_Input* emailInput;
    Fl_Input* passwordInput;
    Fl_Button* signupButton;

    LibraryDatabase* db;
    static void signupCallback(Fl_Widget* widget, void* data);
};

#endif
