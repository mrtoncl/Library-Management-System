#include "LoginScreen.h"
#include "SignupScreen.h"  // Include SignupScreen header
#include "AdminDashboard.h"
#include "UserDashboard.h"
#include <FL/fl_ask.H>  // Include this header for fl_message

// Constructor
LoginScreen::LoginScreen(LibraryDatabase &db) : db(&db) {
    
    window = new Fl_Window(1450, 750, "Login Screen");
    window->color(fl_rgb_color(128, 0, 128)); // Purple background

    title = new Fl_Box(650, 180, 200, 40, "Library Login");
    title->labelsize(24);
    title->labelfont(FL_BOLD);
    title->labelcolor(FL_WHITE);

    note = new Fl_Box(650, 245, 200, 30, 
    "Your username is your userID.");
    note->labelsize(16);
    note->labelcolor(FL_WHITE);
    note->align(FL_ALIGN_CENTER);

    usernameInput = new Fl_Input(650, 285, 200, 30, "Username:");
    usernameInput->align(FL_ALIGN_LEFT);

    passwordInput = new Fl_Input(650, 335, 200, 30, "Password:");
    passwordInput->align(FL_ALIGN_LEFT);
    passwordInput->type(FL_SECRET_INPUT);

    loginButton = new Fl_Button(700, 375, 100, 30, "Login");
    loginButton->callback(loginCallback, this);

    signupText = new Fl_Box(650, 440, 200, 30, "Don't have an account? Sign Up.");
    signupText->labelsize(14);
    signupText->labelcolor(FL_WHITE);
    signupText->align(FL_ALIGN_CENTER);

    signupButton = new Fl_Button(700, 475, 100, 30, "Sign Up");
    signupButton->callback(signupCallback, this);

    window->end();
}

// Destructor
LoginScreen::~LoginScreen() {
    delete window;
    delete usernameInput;
    delete passwordInput;
    delete loginButton;
    delete signupButton;
    delete signupText;
    delete title;
}

// Show the window
void LoginScreen::show() {
    window->show();
}

// Login Button Callback
void LoginScreen::loginCallback(Fl_Widget* widget, void* data) {
    LoginScreen* screen = static_cast<LoginScreen*>(data);
    LibraryDatabase* db = static_cast<LibraryDatabase*>(data);
    std::string username = screen->usernameInput->value();
    std::string password = screen->passwordInput->value();

    // Hardcoded credentials check (you can replace this with a database check)
    if(username == "1111" && password == "25356"){
        AdminDashboard adminDashboard(*db);
        adminDashboard.show();
    } else if(screen->db->existUserById(username)){
        Member* user = db->getUser(username); 

        UserDashboard userDashboard(*user);
        userDashboard.show();
    }else{
        fl_message("Invalid username or password!");
    }

    /*
    if (username == "admin" && password == "adminpass") {
        AdminDashboard adminDashboard;
        adminDashboard.show();
    } else if (username == "user" && password == "userpass") {
        UserDashboard userDashboard;
        userDashboard.show();
    } else {
        fl_message("Invalid username or password!");  // This line should work now
    }*/
}

// Sign Up Button Callback
void LoginScreen::signupCallback(Fl_Widget* widget, void* data) {
    // Create SignupScreen on the heap
    LoginScreen* screen = static_cast<LoginScreen*>(data);
    LibraryDatabase* db = screen->db;

    SignupScreen* signupScreen = new SignupScreen(*db);
    signupScreen->show();
}




