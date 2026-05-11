#include "UserDashboard.h"

UserDashboard::UserDashboard(Member& member) : member(&member)  {
    window = new Fl_Window(1450, 750, "User Dashboard");
    window->color(fl_rgb_color(128, 0, 128)); // Purple background

    title = new Fl_Box(650, 225, 200, 40, "LIBRARY");
    title->labelsize(26);
    title->labelfont(FL_BOLD);
    title->labelcolor(FL_WHITE);

    find = new Fl_Box(650, 270, 200, 30, "Find everything you want!");
    find->labelsize(16);
    find->labelcolor(FL_WHITE);
    find->align(FL_ALIGN_CENTER);

    note = new Fl_Box(650, 435, 200, 30, 
    "NOTE: You can borrow, return and reserve items via itemID. To learn itemID, use Search Item.");
    note->labelsize(16);
    note->labelcolor(FL_WHITE);
    note->align(FL_ALIGN_CENTER);

    borrowItemButton = new Fl_Button(250, 400, 150, 30, "Borrow Item");
    borrowItemButton->color(fl_rgb_color(0, 0, 0));  // Black background
    borrowItemButton->labelcolor(FL_WHITE); 
    borrowItemButton->callback(borrowItemCallback, this);

    returnItemButton = new Fl_Button(410, 400, 150, 30, "Return Item");
    returnItemButton->color(fl_rgb_color(0, 0, 0));  // Black background
    returnItemButton->labelcolor(FL_WHITE); 
    returnItemButton->callback(returnItemCallback, this);

    searchItemButton = new Fl_Button(570, 400, 150, 30, "Search Item");
    searchItemButton->color(fl_rgb_color(0, 0, 0));  // Black background
    searchItemButton->labelcolor(FL_WHITE);
    searchItemButton->callback(searchItemCallback, this);

    notificationButton = new Fl_Button(730, 400, 150, 30, "Notifications");
    notificationButton->color(fl_rgb_color(0, 0, 0));  // Black background
    notificationButton->labelcolor(FL_WHITE); 
    notificationButton->callback(notificationsCallback, this);

    reserveItemButton = new Fl_Button(890, 400, 150, 30, "Reserve Item");
    reserveItemButton->color(fl_rgb_color(0, 0, 0));  // Black background
    reserveItemButton->labelcolor(FL_WHITE); 
    reserveItemButton->callback(reserveItemCallback, this);

    cancelReservationButton = new Fl_Button(1050, 400, 150, 30, "Cancel Reservation");
    cancelReservationButton->color(fl_rgb_color(0, 0, 0));  // Black background
    cancelReservationButton->labelcolor(FL_WHITE); 
    cancelReservationButton->callback(cancelReservationCallback, this);

     // Logout Button
    logoutButton = new Fl_Button(650, 480, 150, 30, "Logout");
    logoutButton->color(fl_rgb_color(0, 0, 255)); //color for "Logout"
    logoutButton->labelcolor(FL_WHITE);
    logoutButton->callback([](Fl_Widget *, void *data) {
        Fl_Window *window = static_cast<Fl_Window *>(data);
        int response = fl_choice("Are you sure you want to logout?", "Cancel", "Yes", nullptr);
        if (response == 1) { // "Yes" selected
            window->hide();
        }
    }, window);

    advice = new Fl_Box(225, 600, 1000, 30, 
    "THE ONLY THING THAT YOU ABSOLUTELY HAVE TO KNOW, IS THE LOCATION OF THE LIBRARY. - ALBERT EINSTEIN.");
    advice->labelsize(18);
    advice->labelcolor(FL_WHITE);
    advice->align(FL_ALIGN_CENTER);
    

    window->end();
}

void UserDashboard::show() {
    window->show();
}

void UserDashboard::borrowItemCallback(Fl_Widget *widget, void *data){

    Fl_Window *miniWindow = new Fl_Window(500, 300, "Borrow Item");
    miniWindow->color(fl_rgb_color(0, 0, 0));

    Fl_Input *itemIdInput = new Fl_Input(100, 50, 300, 30, "Item ID:");
    itemIdInput->labelcolor(FL_WHITE);

    Fl_Button *borrowButton = new Fl_Button(200, 210, 100, 30, "Borrow");
    borrowButton->color(fl_rgb_color(0, 0, 255)); 
    borrowButton->labelcolor(FL_WHITE);
    borrowButton->callback([](Fl_Widget *, void *inputs){
            // Access the Singleton LibraryDatabase instance
            LibraryDatabase* db = LibraryDatabase::getInstance();
            Fl_Input** fields = static_cast<Fl_Input**>(inputs);
            std::string itemId = fields[0]->value();

            if (itemId.empty()) {
                fl_message("Please fill in input fields.");
                return;
            }else if(db->existItem(itemId)){
                db.
            }

            //addItemToDb("Book", title, category, isbn, author);
            fl_message("Item borrowed successfully!"); 
            
            // Close the mini window
            Fl_Window *miniWindow = Fl::first_window();
            if (miniWindow) miniWindow->hide();
            
            },new Fl_Input *[1]{itemIdInput});
            

    miniWindow->end();
    miniWindow->show();
}

void UserDashboard::returnItemCallback(Fl_Widget *widget, void *data){
    Fl_Window *miniWindow = new Fl_Window(500, 300, "Return Item");
    miniWindow->color(fl_rgb_color(0, 0, 0));

    Fl_Input *itemIdInput = new Fl_Input(100, 50, 300, 30, "Item ID:");
    itemIdInput->labelcolor(FL_WHITE);

    Fl_Button *returnButton = new Fl_Button(200, 210, 100, 30, "Return");
    returnButton->color(fl_rgb_color(0, 0, 255)); 
    returnButton->labelcolor(FL_WHITE);
    returnButton->callback([](Fl_Widget *, void *inputs){
            Fl_Input** fields = static_cast<Fl_Input**>(inputs);
            std::string itemId = fields[0]->value();

            if (itemId.empty()) {
                fl_message("Please fill in input fields.");
                return;
            }

            //addItemToDb("Book", title, category, isbn, author);
            fl_message("Item returned successfully!"); 
            
            // Close the mini window
            Fl_Window *miniWindow = Fl::first_window();
            if (miniWindow) miniWindow->hide();
            
            },new Fl_Input *[1]{itemIdInput});
            

    miniWindow->end();
    miniWindow->show();
}

void UserDashboard::reserveItemCallback(Fl_Widget *widget, void *data){
    Fl_Window *miniWindow = new Fl_Window(500, 300, "Reserve Item");
    miniWindow->color(fl_rgb_color(0, 0, 0));

    Fl_Input *itemIdInput = new Fl_Input(100, 50, 300, 30, "Item ID:");
    itemIdInput->labelcolor(FL_WHITE);

    Fl_Button *reserveButton = new Fl_Button(200, 210, 100, 30, "Reserve");
    reserveButton->color(fl_rgb_color(0, 0, 255)); 
    reserveButton->labelcolor(FL_WHITE);
    reserveButton->callback([](Fl_Widget *, void *inputs){
            Fl_Input** fields = static_cast<Fl_Input**>(inputs);
            std::string itemId = fields[0]->value();

            if (itemId.empty()) {
                fl_message("Please fill in input fields.");
                return;
            }

            //addItemToDb("Book", title, category, isbn, author);
            fl_message("Item reserved successfully!This is your reservation Id. Keep it in case of canceling. "); 
            
            // Close the mini window
            Fl_Window *miniWindow = Fl::first_window();
            if (miniWindow) miniWindow->hide();
            
            },new Fl_Input *[1]{itemIdInput});
            

    miniWindow->end();
    miniWindow->show();
}

void UserDashboard::cancelReservationCallback(Fl_Widget *widget, void *data){
    Fl_Window *miniWindow = new Fl_Window(500, 300, "Cancel Reservation");
    miniWindow->color(fl_rgb_color(0, 0, 0));

    Fl_Input *reservationIdInput = new Fl_Input(100, 50, 300, 30, "Reservation ID:");
    reservationIdInput->labelcolor(FL_WHITE);

    Fl_Button *cancelButton = new Fl_Button(175, 210, 150, 30, "Cancel Reservation");
    cancelButton->color(fl_rgb_color(0, 0, 255)); 
    cancelButton->labelcolor(FL_WHITE);
    cancelButton->callback([](Fl_Widget *, void *inputs){
            Fl_Input** fields = static_cast<Fl_Input**>(inputs);
            std::string reservationId = fields[0]->value();

            if (reservationId.empty()) {
                fl_message("Please fill in input fields.");
                return;
            }

            //addItemToDb("Book", title, category, isbn, author);
            fl_message("Reservation cancelled successfully! "); 
            
            // Close the mini window
            Fl_Window *miniWindow = Fl::first_window();
            if (miniWindow) miniWindow->hide();
            
            },new Fl_Input *[1]{reservationIdInput});
            

    miniWindow->end();
    miniWindow->show();
}

void UserDashboard::searchItemCallback(Fl_Widget *widget, void *data){
    // Open a new window to select item type
    Fl_Window *miniWindow = new Fl_Window(400, 300, "Search Item");
    miniWindow->color(fl_rgb_color(0, 0, 0));

    // Create buttons for item types
    Fl_Button *bookButton = new Fl_Button(50, 50, 300, 40, "Search Book");
    Fl_Button *magazineButton = new Fl_Button(50, 120, 300, 40, "Search Magazine");
    Fl_Button *cdButton = new Fl_Button(50, 190, 300, 40, "Search CD");

    // Set callbacks for item types
    bookButton->callback([](Fl_Widget *, void *)
                         {
        Fl_Window* bookWindow = new Fl_Window(500, 400, "Search Book");
        bookWindow->color(fl_rgb_color(0, 0, 0));  // Black background

        Fl_Input* titleInput = new Fl_Input(100, 50, 300, 30, "Title:");
        titleInput->labelcolor(FL_WHITE);
        Fl_Input* categoryInput = new Fl_Input(100, 100, 300, 30, "Category:");
        categoryInput->labelcolor(FL_WHITE);
        Fl_Input* isbnInput = new Fl_Input(100, 150, 300, 30, "ISBN:");
        isbnInput->labelcolor(FL_WHITE);
        Fl_Input* authorInput = new Fl_Input(100, 200, 300, 30, "Author:");
        authorInput->labelcolor(FL_WHITE);
        Fl_Button* saveButton = new Fl_Button(200, 300, 100, 30, "Search");
        saveButton->callback([](Fl_Widget*, void* inputs) {
            Fl_Input** fields = static_cast<Fl_Input**>(inputs);
            std::string title = fields[0]->value();
            std::string category = fields[1]->value();
            std::string isbn = fields[2]->value();
            std::string author = fields[3]->value();
            //addItemToDb("Book", title, category, isbn, author);

            if (title.empty() || category.empty() || isbn.empty() || author.empty()) {
                fl_message("Please fill in all input fields.");
                return;
            }

            fl_message("Book found successfully! This is item ID for this book.");

            // Close the mini window
            Fl_Window *miniWindow = Fl::first_window();
            if (miniWindow) miniWindow->hide();
        }, new Fl_Input*[4]{ titleInput, categoryInput, isbnInput, authorInput });
        bookWindow->end();
        bookWindow->show(); });

    magazineButton->callback([](Fl_Widget *, void *)
                             {
        Fl_Window* magWindow = new Fl_Window(500, 400, "Search Magazine");
        magWindow->color(fl_rgb_color(0, 0, 0));  // Black background

        Fl_Input* titleInput = new Fl_Input(100, 50, 300, 30, "Title:");
        titleInput->labelcolor(FL_WHITE);
        Fl_Input* categoryInput = new Fl_Input(100, 100, 300, 30, "Category:");
        categoryInput->labelcolor(FL_WHITE);
        Fl_Input* issueInput = new Fl_Input(100, 150, 300, 30, "Issue No:");
        issueInput->labelcolor(FL_WHITE);
        Fl_Input* dateInput = new Fl_Input(100, 200, 300, 30, "Publication Date:");
        dateInput->labelcolor(FL_WHITE);
        Fl_Button* saveButton = new Fl_Button(200, 300, 100, 30, "Search");
        saveButton->callback([](Fl_Widget*, void* inputs) {
            Fl_Input** fields = static_cast<Fl_Input**>(inputs);
            std::string title = fields[0]->value();
            std::string category = fields[1]->value();
            std::string issue = fields[2]->value();
            std::string date = fields[3]->value();

            if (title.empty() || category.empty() || issue.empty() || date.empty()) {
                fl_message("Please fill in all input fields.");
                return;
            }

            fl_message("Magazine found successfully! This is item ID for this magazin.");

            // Close the mini window
            Fl_Window *miniWindow = Fl::first_window();
            if (miniWindow) miniWindow->hide();
        }, new Fl_Input*[4]{ titleInput, categoryInput, issueInput, dateInput });
        magWindow->end();
        magWindow->show(); });

    cdButton->callback([](Fl_Widget *, void *)
                       {
        Fl_Window* cdWindow = new Fl_Window(500, 300, "Search CD");
        cdWindow->color(fl_rgb_color(0, 0, 0));  // Black background

        Fl_Input* titleInput = new Fl_Input(100, 50, 300, 30, "Title:");
        titleInput->labelcolor(FL_WHITE);
        Fl_Input* categoryInput = new Fl_Input(100, 100, 300, 30, "Category:");
        categoryInput->labelcolor(FL_WHITE);
        Fl_Input* artistInput = new Fl_Input(100, 150, 300, 30, "Artist:");
        artistInput->labelcolor(FL_WHITE);
        Fl_Button* saveButton = new Fl_Button(200, 250, 100, 30, "Search");
        saveButton->callback([](Fl_Widget*, void* inputs) {
            Fl_Input** fields = static_cast<Fl_Input**>(inputs);
            std::string title = fields[0]->value();
            std::string category = fields[1]->value();
            std::string artist = fields[2]->value();
            //addItemToDb("CD", title, category, artist);

            if (title.empty() || category.empty() || artist.empty() ) {
                fl_message("Please fill in all input fields.");
                return;
            }

            fl_message("CD found successfully! This is item ID for this CD.");

            // Close the mini window
            Fl_Window *miniWindow = Fl::first_window();
            if (miniWindow) miniWindow->hide();
        }, new Fl_Input*[3]{ titleInput, categoryInput, artistInput });
        cdWindow->end();
        cdWindow->show(); });

    miniWindow->end();
    miniWindow->show();
}

// Sample Notifications Data
std::vector<std::string> notifications = {
    "Your borrowed book 'C++ Primer' is due in 3 days.",
    "Your reservation for 'Data Structures and Algorithms' has been confirmed.",
    "Reminder: Please return the overdue magazine."
};

// Function to Remove Notification
void UserDashboard::removeNotification(int index) {
    if (index >= 0 && index < notifications.size()) {
        notifications.erase(notifications.begin() + index);
    }
}

// Callback for "Mark as Read" Button
void UserDashboard::markAsReadCallback(Fl_Widget *widget, void *data) {
    int *index = static_cast<int *>(data);
    removeNotification(*index);

    fl_message("Notification marked as read!");
 
    // Get the button that was clicked
    Fl_Button *button = (Fl_Button*)widget;
    
    // Change the label of the button to "Marked"
    button->label("Marked");

    button->color(fl_rgb_color(100, 100, 100));  // Grey color for marked
    button->labelcolor(fl_rgb_color(255, 255, 255));  // White text
    
    // Redraw the button to apply the changes
    button->redraw();
}

// Callback Function for Notifications Button
void UserDashboard::notificationsCallback(Fl_Widget *widget, void *data) {
    Fl_Window *notificationsWindow = new Fl_Window(600, 400, "Notifications");
    notificationsWindow->color(fl_rgb_color(0, 0, 0)); // Black background

    Fl_Scroll *scroll = new Fl_Scroll(5, 5, 590, 380);
    scroll->type(Fl_Scroll::VERTICAL);
    scroll->color(fl_rgb_color(0,0,0));

    int y = 10;
    for (size_t i = 0; i < notifications.size(); ++i) {
        Fl_Box *notificationBox = new Fl_Box(10, y, 460, 30, notifications[i].c_str());
        notificationBox->box(FL_FLAT_BOX);
        notificationBox->labelsize(12);
        notificationBox->labelfont(FL_HELVETICA);
        notificationBox->labelcolor(fl_rgb_color(255, 255, 255));
        notificationBox->color(fl_rgb_color(0,0,0));

        Fl_Button *markAsReadButton = new Fl_Button(505, y, 85, 30, "Mark as Read");
        markAsReadButton->labelcolor(fl_rgb_color(255, 255, 255));
        markAsReadButton->color(fl_rgb_color(0,0,0));
        markAsReadButton->callback(markAsReadCallback, new int(i));

        y += 40; // Space between notifications
    }

    scroll->end();
    notificationsWindow->end();
    notificationsWindow->show();
}
