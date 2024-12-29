# Compiler and flags
CXX = g++
CXXFLAGS = -w -std=c++11

# Source files and object files for the main build
SRCS_MAIN = main.cpp Wizard.cpp Witch.cpp WarHammer.cpp StrengthPotion.cpp Shop.cpp Potion.cpp ManaPotion.cpp Location.cpp Knight.cpp Item.cpp HealPotion.cpp Guild.cpp GreatSword.cpp FireResistancePotion.cpp Enemy.cpp Dragon.cpp Character.cpp Beast.cpp Arena.cpp Weapon.cpp
OBJS_MAIN = $(SRCS_MAIN:.cpp=.o)

# Source files and object files for the test build
SRCS_TEST = UnitTest.cpp Witch.cpp WarHammer.cpp StrengthPotion.cpp Shop.cpp Potion.cpp ManaPotion.cpp Location.cpp Knight.cpp Item.cpp HealPotion.cpp Guild.cpp GreatSword.cpp FireResistancePotion.cpp Enemy.cpp Dragon.cpp Character.cpp Beast.cpp Arena.cpp Weapon.cpp Wizard.cpp
OBJS_TEST = $(SRCS_TEST:.cpp=.o)

# Executable names
EXEC_MAIN = main
EXEC_TEST = test

# Default target: builds both main and test executables
all: $(EXEC_MAIN) $(EXEC_TEST)

# Main executable build
$(EXEC_MAIN): $(OBJS_MAIN)
	$(CXX) $(CXXFLAGS) -o $(EXEC_MAIN) $(OBJS_MAIN)

# Test executable build
$(EXEC_TEST): $(OBJS_TEST)
	$(CXX) $(CXXFLAGS) -o $(EXEC_TEST) $(OBJS_TEST)

# Compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executables
clean:
	rm -f $(OBJS_MAIN) $(OBJS_TEST) $(EXEC_MAIN) $(EXEC_TEST)

# Phony targets (not actual files)
.PHONY: all clean
