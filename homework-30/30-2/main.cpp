#include <chrono>
#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <random>
#include <thread>
#include <mutex>

std::mutex mutex;

void DrawRace(const unsigned int& distance, const unsigned int& numberOfAThread) {
	using namespace std::chrono_literals;
	unsigned int temproraryDistance{ distance };
	std::random_device randomDevice;
	std::mt19937 generate(randomDevice());
	std::uniform_int_distribution<> distribution(1, 4);
	std::thread::id threadId{ std::this_thread::get_id() };
	auto start{ std::chrono::steady_clock::now() };
	std::ostringstream output{};
	while (temproraryDistance > 0) {
		unsigned int randomStep{ static_cast<unsigned int>(std::min(static_cast<unsigned int>(distribution(generate)), temproraryDistance)) };
		temproraryDistance -= randomStep;
		{
			std::lock_guard<std::mutex> lock{ mutex };
			output << "\rThread " << numberOfAThread <<  " ID: " << std::setw(5) << std::left << threadId << " : [";
			for (unsigned int index{}; index < distance - temproraryDistance; ++index) {
				output << "\u25A0";
			}
			for (unsigned int index{}; index < temproraryDistance; ++index) {
				output << " ";
			}
			output << "] ";
		}
		{
			std::lock_guard<std::mutex> lock{ mutex };
			std::cout << "\033[" << numberOfAThread + 1 << ";1H";
			std::cout << "\033[K";
			std::cout << output.str() << std::flush;

		}
		std::this_thread::sleep_for(500ms);
	}
	auto end{ std::chrono::steady_clock::now() };
	std::chrono::duration<double> finalTime{ end - start };
	{
		std::lock_guard<std::mutex> lock{ mutex };
		std::cout << "\033[" << numberOfAThread + 1 << ";1H";
		std::cout << "\033[K";
		std::cout << "Thread " << numberOfAThread << " ID: " << std::setw(5) << std::left << threadId << " finished. Time: " << finalTime.count() << "s" << std::flush;
	}
}

int main(int argc, char* argv[]){
	using namespace std::chrono_literals;
	unsigned int distance{}, numberOfAThreads{};
	std::cout << "Enter a length of a distance: ";
	std::cin >> distance;
	std::cout << "Enter a number of threads: ";
	std::cin >> numberOfAThreads;
	std::cout << "\033[2J";
	std::vector<std::thread> threads(numberOfAThreads);
	for (size_t index{}; index < numberOfAThreads; ++index) {
		threads.emplace_back(DrawRace, distance, index);
	}
	for (auto& thread : threads) {
		if (thread.joinable()) {
			thread.join();
		}
	}
	std::cout << "\033[" << numberOfAThreads + 2 << ";1H";
	return EXIT_SUCCESS;
}