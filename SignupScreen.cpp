#include "SignupScreen.h"
#include "LoginScreen.h"
#include <FL/fl_ask.H>

// Constructor
SignupScreen::SignupScreen(LibraryDatabase &db) : db(&db)
{
    window = new Fl_Window(1450, 750, "Sign Up");
    window->color(fl_rgb_color(128, 0, 128));

    nameInput = new Fl_Input(650, 225, 200, 30, "Name:");
    emailInput = new Fl_Input(650, 265, 200, 30, "Email:");
    passwordInput = new Fl_Input(650, 305, 200, 30, "Password:");
    passwordInput->type(FL_SECRET_INPUT);

    signupButton = new Fl_Button(650, 345, 100, 30, "Sign Up");
    signupButton->callback(signupCallback, this);

    window->end();
}

// Destructor
SignupScreen::~SignupScreen()
{
    delete window;
    delete nameInput;
    delete emailInput;
    delete passwordInput;
    delete signupButton;
}

// Show the window
void SignupScreen::show()
{
    window->show();
}

// Sign Up Button Callback
void SignupScreen::signupCallback(Fl_Widget *widget, void *data)
{
    SignupScreen *screen = static_cast<SignupScreen *>(data);
    std::string name = screen->nameInput->value();
    std::string email = screen->emailInput->value();
    std::string password = screen->passwordInput->value();

    if (name.empty() || email.empty() || password.empty())
    {
        fl_message("Please fill in all fields!");
        return;
    }
    else if (screen->db->existUser(email)) 
    {
        fl_message("User already exists!");
        return;
    }
    else
    {
        // Generate a unique user ID
        std::string userId = screen->generateUniqueId(screen);

        // Add user to the database with the generated userId
        screen->db->addUser(userId, name, email, stoi(password));

        fl_message(("Account successfully created! User ID is " + userId).c_str());
            
        }

    // Display a success message
    
    

    screen->window->hide();
}

// Function to generate a unique user ID (4-digit random number)
std::string SignupScreen::generateUniqueId(SignupScreen *screen)
{
    int randomInt;
    do
    {
        randomInt = std::rand() % 10000;  // Random number between 0 and 9999
    } while (screen->db->existUser(std::to_string(randomInt)));  // Check if the ID already exists

    return std::to_string(randomInt);  // Return the ID as a string
}
