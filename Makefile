# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -I C:\fltk-1.4.0-1 -I C:\external_libs\fltk

# Linker Flags
LDFLAGS = -L C:\external_libs\fltk\lib -lfltk -lcomctl32 -lole32 -luuid -lgdi32 -lws2_32 -lgdiplus -lwinspool -lcomdlg32

# Output binary
TARGET = main

# Source files
SOURCES = main.cpp LoginScreen.cpp SignupScreen.cpp AdminDashboard.cpp UserDashboard.cpp \
          Member.cpp Book.cpp CD.cpp Magazine.cpp LibraryDatabase.cpp \
          NotifySystem.cpp Reservation.cpp BorrowingTransaction.cpp\
		  User.cpp BorrowableItem.cpp
# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJECTS) $(TARGET)

