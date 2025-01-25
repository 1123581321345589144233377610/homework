#include <iostream>
#include <chrono>
#include <ctime>
#include <numeric>
#include <vector>
#include <thread>

void FillVectores(std::vector<int>& firstVector, std::vector<int>& secondVector, const size_t& sizeOfVectores) {
	std::srand(std::time(0));
	for (size_t index{}; index < sizeOfVectores; ++index) {
		firstVector.push_back(std::rand() % 100);
		secondVector.push_back(std::rand() % 100);
	}
}

void CountSumInAVector(const std::vector<int>& vector, const unsigned int& numberOfThreads) {
	std::vector<int> sumInAThread(numberOfThreads, 0);
	std::vector<std::thread> threads{};
	unsigned int step = vector.size() / numberOfThreads;
	for (size_t index{}; index < sumInAThread.size(); ++index) {
		std::thread thread{ [index, &sumInAThread, step, vector](){
				sumInAThread[index] = std::accumulate(vector.begin() + index * step, vector.begin() + (index + 1) * step, 0);
			}
		};
		threads.push_back(std::move(thread));
	}
	for (std::thread& thread : threads) {
		thread.join();
	}
	unsigned int sum{};
	for (size_t index{}; index < sumInAThread.size(); ++index) {
		sum += sumInAThread[index];
	}
}

void PrintTimeOfWork(const unsigned int& numberOfThreads) {
	std::vector<int> firstVector{}, secondVector{};
	size_t startSize{ 1000 };
	std::cout << numberOfThreads << "th threads" << "\t ";
	while (startSize <= 1000000) {
		FillVectores(firstVector, secondVector, startSize);
		auto start{ std::chrono::steady_clock::now() };
		CountSumInAVector(firstVector, numberOfThreads);
		CountSumInAVector(secondVector, numberOfThreads);
		auto end{ std::chrono::steady_clock::now() };
		std::chrono::duration<double> finalTime{ end - start };
		std::cout << finalTime.count() << "s\t ";
		startSize *= 10;
	}
	std::cout << std::endl;
}

int main() {
	std::cout << "Number of hardware cores - " << std::thread::hardware_concurrency() << std::endl << std::endl;
	std::cout << "\t           1000" << "\t           10000" << "\t   100000" << "\t   1000000" << std::endl;
	PrintTimeOfWork(1);
	PrintTimeOfWork(2);
	PrintTimeOfWork(4);
	PrintTimeOfWork(8);
	PrintTimeOfWork(16);
	return EXIT_SUCCESS;
}