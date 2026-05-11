#include "AdminDashboard.h"

AdminDashboard::AdminDashboard(LibraryDatabase &db) : db(&db)
{
    window = new Fl_Window(1450, 750, "Admin Dashboard");
    window->color(fl_rgb_color(128, 0, 128)); // Purple background

    title = new Fl_Box(650, 225, 200, 40, "welcome to library");
    title->labelsize(24);
    title->labelfont(FL_BOLD);
    title->labelcolor(FL_WHITE);

    selectionText = new Fl_Box(650, 270, 200, 30, "Select what you want to do from below.");
    selectionText->labelsize(14);
    selectionText->labelcolor(FL_WHITE);
    selectionText->align(FL_ALIGN_CENTER);

    addItemButton = new Fl_Button(350, 350, 150, 30, "Add Item");
    addItemButton->color(fl_rgb_color(0, 0, 0)); // Black background
    addItemButton->labelcolor(FL_WHITE);
    addItemButton->callback(addItemCallback, this);

    addUserButton = new Fl_Button(510, 350, 150, 30, "Add User");
    addUserButton->color(fl_rgb_color(0, 0, 0)); // Black background
    addUserButton->labelcolor(FL_WHITE);
    addUserButton->callback(addUserCallback, this);

    deleteItemButton = new Fl_Button(670, 350, 150, 30, "Delete Item");
    deleteItemButton->color(fl_rgb_color(0, 0, 0)); // Black background
    deleteItemButton->labelcolor(FL_WHITE);
    deleteItemButton->callback(deleteItemCallback, this);

    deleteUserButton = new Fl_Button(830, 350, 150, 30, "Delete User");
    deleteUserButton->color(fl_rgb_color(0, 0, 0)); // Black background
    deleteUserButton->labelcolor(FL_WHITE);
    deleteUserButton->callback(deleteUserCallback, this);

    searchUserButton = new Fl_Button(990, 350, 150, 30, "Search User");
    searchUserButton->color(fl_rgb_color(0, 0, 0)); // Black background
    searchUserButton->labelcolor(FL_WHITE);
    searchUserButton->callback(searchUserCallback, this);

    // Logout Button
    logoutButton = new Fl_Button(670, 430, 150, 30, "Logout");
    logoutButton->color(fl_rgb_color(0, 0, 255)); // color for "Logout"
    logoutButton->labelcolor(FL_WHITE);
    logoutButton->callback([](Fl_Widget *, void *data)
                           {
        Fl_Window *window = static_cast<Fl_Window *>(data);
        int response = fl_choice("Are you sure you want to logout?", "Cancel", "Yes", nullptr);
        if (response == 1) { // "Yes" selected
            window->hide();
        } }, window);

    window->end();
}

void AdminDashboard::show()
{
    window->show();
}

// Add Item Callback with Submenu
void AdminDashboard::addItemCallback(Fl_Widget *widget, void *data)
{
    // Open a new window to select item type
    Fl_Window *miniWindow = new Fl_Window(400, 300, "Add Item");
    miniWindow->color(fl_rgb_color(0, 0, 0));

    // Create buttons for item types
    Fl_Button *bookButton = new Fl_Button(50, 50, 300, 40, "Add Book");
    Fl_Button *magazineButton = new Fl_Button(50, 120, 300, 40, "Add Magazine");
    Fl_Button *cdButton = new Fl_Button(50, 190, 300, 40, "Add CD");

    // Set callbacks for item types
    bookButton->callback([](Fl_Widget *, void *)
                         {
        Fl_Window* bookWindow = new Fl_Window(500, 400, "Add Book");
        bookWindow->color(fl_rgb_color(0, 0, 0));  // Black background

        Fl_Input* titleInput = new Fl_Input(100, 50, 300, 30, "Title:");
        titleInput->labelcolor(FL_WHITE);
        Fl_Input* categoryInput = new Fl_Input(100, 100, 300, 30, "Category:");
        categoryInput->labelcolor(FL_WHITE);
        Fl_Input* isbnInput = new Fl_Input(100, 150, 300, 30, "ISBN:");
        isbnInput->labelcolor(FL_WHITE);
        Fl_Input* authorInput = new Fl_Input(100, 200, 300, 30, "Author:");
        authorInput->labelcolor(FL_WHITE);
        Fl_Button* saveButton = new Fl_Button(200, 300, 100, 30, "Save");
        saveButton->callback([](Fl_Widget*, void* inputs) {
            Fl_Input** fields = static_cast<Fl_Input**>(inputs);
            std::string bookId = "103";
            std::string title = fields[0]->value();
            std::string category = fields[1]->value();
            std::string isbn = fields[2]->value();
            std::string author = fields[3]->value();
            LibraryDatabase::addBook(bookId, title, category, isbn, author);
            //addItemToDb("Book", title, category, isbn, author);

            if(title.empty() || category.empty() || isbn.empty() || author.empty()){
                fl_message("Please fill in all fields!");
                return;
            }

            fl_message("Book added successfully!");

            // Close the mini window
            Fl_Window *miniWindow = Fl::first_window();
            if (miniWindow) miniWindow->hide();
        }, new Fl_Input*[4]{ titleInput, categoryInput, isbnInput, authorInput });
        bookWindow->end();
        bookWindow->show(); });

    magazineButton->callback([](Fl_Widget *, void *)
                             {
        Fl_Window* magWindow = new Fl_Window(500, 400, "Add Magazine");
        magWindow->color(fl_rgb_color(0, 0, 0));  // Black background

        Fl_Input* titleInput = new Fl_Input(100, 50, 300, 30, "Title:");
        titleInput->labelcolor(FL_WHITE);
        Fl_Input* categoryInput = new Fl_Input(100, 100, 300, 30, "Category:");
        categoryInput->labelcolor(FL_WHITE);
        Fl_Input* issueInput = new Fl_Input(100, 150, 300, 30, "Issue No:");
        issueInput->labelcolor(FL_WHITE);
        Fl_Input* dateInput = new Fl_Input(100, 200, 300, 30, "Publication Date:");
        dateInput->labelcolor(FL_WHITE);
        Fl_Button* saveButton = new Fl_Button(200, 300, 100, 30, "Save");
        saveButton->callback([](Fl_Widget*, void* inputs) {
            Fl_Input** fields = static_cast<Fl_Input**>(inputs);
            std::string title = fields[0]->value();
            std::string category = fields[1]->value();
            std::string issue = fields[2]->value();
            std::string date = fields[3]->value();

            if(title.empty() || category.empty() || issue.empty() || date.empty()){
                fl_message("Please fill in all fields!");
                return;
            }
            fl_message("Magazine added successfully!");

            // Close the mini window
            Fl_Window *miniWindow = Fl::first_window();
            if (miniWindow) miniWindow->hide();
        }, new Fl_Input*[4]{ titleInput, categoryInput, issueInput, dateInput });
        magWindow->end();
        magWindow->show(); });

    cdButton->callback([](Fl_Widget *, void *)
                       {
        Fl_Window* cdWindow = new Fl_Window(500, 300, "Add CD");
        cdWindow->color(fl_rgb_color(0, 0, 0));  // Black background

        Fl_Input* titleInput = new Fl_Input(100, 50, 300, 30, "Title:");
        titleInput->labelcolor(FL_WHITE);
        Fl_Input* categoryInput = new Fl_Input(100, 100, 300, 30, "Category:");
        categoryInput->labelcolor(FL_WHITE);
        Fl_Input* artistInput = new Fl_Input(100, 150, 300, 30, "Artist:");
        artistInput->labelcolor(FL_WHITE);
        Fl_Button* saveButton = new Fl_Button(200, 250, 100, 30, "Save");
        saveButton->callback([](Fl_Widget*, void* inputs) {
            Fl_Input** fields = static_cast<Fl_Input**>(inputs);
            std::string title = fields[0]->value();
            std::string category = fields[1]->value();
            std::string artist = fields[2]->value();
            //addItemToDb("CD", title, category, artist);

            if(title.empty() || category.empty() || artist.empty()){
                fl_message("Please fill in all fields!");
                return;
            }
            fl_message("CD added successfully!");

            // Close the mini window
            Fl_Window *miniWindow = Fl::first_window();
            if (miniWindow) miniWindow->hide();
        }, new Fl_Input*[3]{ titleInput, categoryInput, artistInput });
        cdWindow->end();
        cdWindow->show(); });

    miniWindow->end();
    miniWindow->show();
}

void AdminDashboard::addUserCallback(Fl_Widget *widget, void *data)
{
    // Open a new window to add user
    Fl_Window *miniWindow = new Fl_Window(500, 300, "Add User");
    miniWindow->color(fl_rgb_color(0, 0, 0));

    Fl_Input *nameInput = new Fl_Input(100, 50, 300, 30, "Name& Surname:");
    nameInput->labelcolor(FL_WHITE);
    Fl_Input *emailInput = new Fl_Input(100, 100, 300, 30, "Email:");
    emailInput->labelcolor(FL_WHITE);
    Fl_Input *passwordInput = new Fl_Input(100, 150, 300, 30, "Password:");
    passwordInput->labelcolor(FL_WHITE);

    Fl_Button *saveButton = new Fl_Button(200, 210, 100, 30, "Save");
    saveButton->callback([](Fl_Widget *, void *inputs)
                         {
            Fl_Input** fields = static_cast<Fl_Input**>(inputs);
            std::string name = fields[0]->value();
            std::string email = fields[1]->value();
            std::string password = fields[2]->value();

            if (name.empty() || email.empty() || password.empty()) {
                fl_message("Please fill in all fields.");
                return;
            }

            //addItemToDb("Book", title, category, isbn, author);
            fl_message("User added successfully!"); 
            
            // Close the mini window
            Fl_Window *miniWindow = Fl::first_window();
            if (miniWindow) miniWindow->hide();
            },
                         new Fl_Input *[3]{nameInput, emailInput, passwordInput});

    miniWindow->end();
    miniWindow->show();
}

// Items will be deleted according their ıtem Id
// Because item id's are unique
void AdminDashboard::deleteItemCallback(Fl_Widget *widget, void *data)
{

    
    // Open a new window to delete item

    Fl_Window *miniWindow = new Fl_Window(500, 300, "Delete Item");
    miniWindow->color(fl_rgb_color(0, 0, 0));

    Fl_Input *itemIdInput = new Fl_Input(100, 50, 300, 30, "Item ID:");
    itemIdInput->labelcolor(FL_WHITE);

    Fl_Button *deleteButton = new Fl_Button(200, 210, 100, 30, "Delete");
    deleteButton->color(fl_rgb_color(0, 0, 255)); // Blue color for "Delete"
    deleteButton->labelcolor(FL_WHITE);
    deleteButton->callback([](Fl_Widget *, void *inputs)
                           {

                            // Access the Singleton LibraryDatabase instance
                                LibraryDatabase* db = LibraryDatabase::getInstance();
                               Fl_Input **fields = static_cast<Fl_Input **>(inputs);
                               std::string itemId = fields[0]->value();

                               if (itemId.empty())
                               {
                                   fl_message("Please fill in all fields.");
                                   return;
                               }else {
                                    
                               }

                               

                                db->deleteItem(itemId);
                               fl_message("Item deleted successfully!");

                               // Close the mini window
                               Fl_Window *miniWindow = Fl::first_window();
                               if (miniWindow)
                                   miniWindow->hide(); },
                           new Fl_Input *[1]{itemIdInput});

    miniWindow->end();
    miniWindow->show();
}

void AdminDashboard::deleteUserCallback(Fl_Widget *widget, void *data){
    // Open a new window to delete user

    Fl_Window *miniWindow = new Fl_Window(500, 300, "Delete User");
    miniWindow->color(fl_rgb_color(0, 0, 0));

    Fl_Input *userIdInput = new Fl_Input(100, 50, 300, 30, "User ID:");
    userIdInput->labelcolor(FL_WHITE);

    Fl_Button *deleteButton = new Fl_Button(200, 210, 100, 30, "Delete");
    deleteButton->color(fl_rgb_color(0, 0, 255)); // Blue color for "Delete"
    deleteButton->labelcolor(FL_WHITE);
    deleteButton->callback([](Fl_Widget *, void *inputs){
            // Access the Singleton LibraryDatabase instance
            LibraryDatabase* db = LibraryDatabase::getInstance();
            Fl_Input** fields = static_cast<Fl_Input**>(inputs);
            std::string userId = fields[0]->value();

            if (userId.empty()) {
                fl_message("Please fill in all fields.");
                return;
            }

            db->deleteUser(userId);
            fl_message("User deleted successfully!"); 
            
            // Close the mini window
            Fl_Window *miniWindow = Fl::first_window();
            if (miniWindow) miniWindow->hide();
            
            },new Fl_Input *[1]{userIdInput});
            

    miniWindow->end();
    miniWindow->show();
}



void AdminDashboard::searchUserCallback(Fl_Widget *widget, void *data)
{
    // Open a new window to search user

    Fl_Window *miniWindow = new Fl_Window(500, 300, "Search User");
    miniWindow->color(fl_rgb_color(0, 0, 0));

    Fl_Input *userIdInput = new Fl_Input(100, 50, 300, 30, "User ID:");
    userIdInput->labelcolor(FL_WHITE);

    Fl_Button *searchButton = new Fl_Button(200, 210, 100, 30, "Search");
    searchButton->color(fl_rgb_color(0, 0, 255)); // Blue color for "Delete"
    searchButton->labelcolor(FL_WHITE);
    searchButton->callback([](Fl_Widget *, void *inputs)
                           {

                            // Access the Singleton LibraryDatabase instance
                                LibraryDatabase* db = LibraryDatabase::getInstance();
                               Fl_Input **fields = static_cast<Fl_Input **>(inputs);
                               std::string userId = fields[0]->value();

                               if (userId.empty())
                               {
                                   fl_message("Please fill in all fields.");
                                   return;
                               }else if(db->existUserById(userId)){
                                Member* user = db->getUser(userId); 
                                fl_message(("User found successfully!\nEmail: " + user->getEmail() + 
                                "\nPassword: " + user->getPassword()).c_str()  );
                               }

                                
                               // addItemToDb("Book", title, category, isbn, author);
                               //fl_message("User found successfully!");

                               // Close the mini window
                               Fl_Window *miniWindow = Fl::first_window();
                               if (miniWindow)
                                   miniWindow->hide(); },
                           new Fl_Input *[1]{userIdInput});

    miniWindow->end();
    miniWindow->show();
}

// Function to generate a unique user ID (4-digit random number)
std::string AdminDashboard::generateUniqueUserId(AdminDashboard *screen)
{
    int randomInt;
    do
    {
        randomInt = std::rand() % 10000;  // Random number between 0 and 9999
    } while (screen->db->existUser(std::to_string(randomInt)));  // Check if the ID already exists

    return std::to_string(randomInt);  // Return the ID as a string
}

// Function to generate a unique item Id
std::string AdminDashboard::generateUniqueItemId(AdminDashboard *screen)
{
    int randomInt;
    do
    {
        randomInt = std::rand() % 10000; // Random number between 0 and 9999
    } while (screen->db->existItem(std::to_string(randomInt))); // Check if the ID already exists

    return std::to_string(randomInt); // Return the ID as a string
}
/*
LibraryDatabase AdminDashboard:: getDB(){
    return *db;
}*/