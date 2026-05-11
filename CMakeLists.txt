cmake_minimum_required(VERSION 3.27)
project(201projectV1)

set(CMAKE_CXX_STANDARD 23)

# Find FLTK package
find_package(FLTK REQUIRED)

# Include FLTK headers
include_directories(${FLTK_INCLUDE_DIR})

add_executable(201projectV1 main.cpp
        User.cpp
        User.h
        UserDashboard.cpp
        UserDashboard.h
        Admin.cpp
        Admin.h
        Member.cpp
        Member.h
        BorrowableItem.cpp
        BorrowableItem.h
        Book.cpp
        Book.h
        NotifySystem.cpp
        NotifySystem.h
        BorrowingTransaction.cpp
        BorrowingTransaction.h
        Magazine.cpp
        Magazine.h
        CD.cpp
        CD.h
        LibraryDatabase.h
        LibraryDatabase.cpp
        Reservation.cpp
        Reservation.h
        AdminDashboard.cpp
        AdminDashboard.h
        SignupScreen.cpp
        SignupScreen.h
        LoginScreen.cpp
        LoginScreen.h
)

# Link the FLTK libraries to the target
target_link_libraries(201projectV1 ${FLTK_LIBRARIES})
