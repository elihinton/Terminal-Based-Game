#include <cstdlib>
#include <ctime>
#include "ItemTest.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed random number generator

    ItemTest itemTest;
    itemTest.runTests();

    return 0;
}
