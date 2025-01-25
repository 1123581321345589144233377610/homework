#include <iostream>
#include <thread>

void AddClient(unsigned int& numberOfClients, unsigned int &maximumClients) {
	using namespace std::chrono_literals;
	while (maximumClients > 0) {
		++numberOfClients;
		--maximumClients;
		std::cout << numberOfClients << std::endl;
		std::this_thread::sleep_for(1s);
	}
}

void RequestClient(unsigned int& numberOfClients) {
	using namespace std::chrono_literals;
	while (numberOfClients > 0) {
		--numberOfClients;
		std::cout << numberOfClients << std::endl;
		std::this_thread::sleep_for(2s);
	}
}

int main(int argc, char* argv[]) {
	unsigned int maximumNumberOfCustomers{}, numberOfCustomers{};
	std::cout << "Set the number of customers: ";
	std::cin >> maximumNumberOfCustomers;
	std::thread threadFirst{ AddClient, std::ref(numberOfCustomers), std::ref(maximumNumberOfCustomers)};
	std::thread threadSecond{ RequestClient, std::ref(numberOfCustomers)};
	threadFirst.detach();
	threadSecond.join();
	return EXIT_SUCCESS;
}