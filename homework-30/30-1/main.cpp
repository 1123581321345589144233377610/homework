#include <atomic>
#include <iostream>
#include <thread>

void AddClient(std::atomic<unsigned int> &numberOfClients, std::atomic<unsigned int> &maximumClients) noexcept{
	using namespace std::chrono_literals;
	while (maximumClients > 0) {
		numberOfClients.fetch_add(1);
		maximumClients.fetch_sub(1);
		std::cout << numberOfClients.load() << std::endl;
		std::this_thread::sleep_for(1s);
	}
}

void RequestClient(std::atomic<unsigned int> &numberOfClients) noexcept{
	using namespace std::chrono_literals;
	while (numberOfClients > 0) {
		numberOfClients.fetch_sub(1);
		std::cout << numberOfClients.load() << std::endl;
		std::this_thread::sleep_for(2s);
	}
}

int main(int argc, char* argv[]) {
	std::atomic<unsigned int> maximumNumberOfCustomers, numberOfCustomers;
	unsigned int temproraryValue{};
	std::cout << "Set the number of customers: ";
	std::cin >> temproraryValue;
	maximumNumberOfCustomers.store(temproraryValue);
	std::thread threadFirst{ AddClient, std::ref(numberOfCustomers), std::ref(maximumNumberOfCustomers) };
	std::thread threadSecond{ RequestClient, std::ref(numberOfCustomers) };
	threadFirst.detach();
	threadSecond.join();
	return EXIT_SUCCESS;
}