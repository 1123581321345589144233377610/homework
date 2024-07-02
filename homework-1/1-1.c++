#include <iostream>
enum class months : int {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
};

int main() {
    unsigned short n;
    do {
        std::cout << "Enter the month number: ";
        std::cin >> n;
        if (n != 0 && ((n < 0) || (n > 12))) {
            std::cout << "Wrong number!" << std::endl;
            continue;
        }
        else {
            switch (static_cast<int> (n)) {
                case 1: std::cout << "January" << std::endl; break;
                case 2: std::cout << "February"  << std::endl; break;
                case 3: std::cout << "March" << std::endl; break;
                case 4: std::cout << "April" << std::endl; break;
                case 5: std::cout << "May" << std::endl; break;
                case 6: std::cout << "June" << std::endl; break;
                case 7: std::cout << "July" << std::endl; break;
                case 8: std::cout << "August" << std::endl; break;
                case 9: std::cout << "September" << std::endl; break;
                case 10: std::cout << "October" << std::endl; break;
                case 11: std::cout << "November" << std::endl; break;
                case 12 : std::cout << "December" << std::endl; break;
            }
        }
    } while (n != 0);
    std::cout << "Goodbye";
    return 0;
}