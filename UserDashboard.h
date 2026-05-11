#ifndef USERDASHBOARD_H
#define USERDASHBOARD_H
#include "Member.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <fstream>
#include <sstream>
#include <random>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Input.H>
#include <FL/fl_ask.H>
#include <stdlib.h>

class UserDashboard {
public:
    UserDashboard(Member& member);
    void show();
    static void borrowItemCallback(Fl_Widget* widget, void* data);
    static void returnItemCallback(Fl_Widget* widget, void* data);
    static void searchItemCallback(Fl_Widget* widget, void* data);
    static void notificationsCallback(Fl_Widget* widget, void* data);
    static void markAsReadCallback(Fl_Widget *widget, void *data);
    static void removeNotification(int index);
    static void reserveItemCallback(Fl_Widget* widget, void* data);
    static void cancelReservationCallback(Fl_Widget* widget, void* data);

private:
    Fl_Window* window;
    Fl_Box* title;
    Fl_Box* find;
    Fl_Box* note;
    Fl_Button* borrowItemButton;
    Fl_Button* returnItemButton;
    Fl_Button* searchItemButton;
    Fl_Button* notificationButton;
    Fl_Button* reserveItemButton;
    Fl_Button* cancelReservationButton;
    Fl_Button* logoutButton;
    Fl_Box* advice;
    Member* member;

};

#endif
