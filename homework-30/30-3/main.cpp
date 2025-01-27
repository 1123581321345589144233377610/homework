#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

template <class Type>
class Data {
protected:
	Type data{};
public:
	std::mutex mutex;
	Data(const Type& otherData) {
		data = otherData;
	}
	void PrintData() {
		std::cout << data << std::endl;
	}
	Type GetData() const {
		return data;
	}
	void SetData(const Type& otherData) {
		data = otherData;
	}
	void SwapDataFirstVariant(Data& dataFirst, Data& dataSecond) {
		std::lock(dataFirst.mutex, dataSecond.mutex);
		std::lock_guard<std::mutex> lockGuardFirst{ dataFirst.mutex, std::adopt_lock };
		std::lock_guard<std::mutex> lockGuardSecond{ dataSecond.mutex, std::adopt_lock };
		std::swap(dataFirst.data, dataSecond.data);
	}
	void SwapDataSecondVariant(Data& dataFirst, Data& dataSecond) {
		std::scoped_lock{ dataFirst.mutex, dataSecond.mutex };
		std::swap(dataFirst.data, dataSecond.data);
	}
	void SwapDataThirdVariant(Data& dataFirst, Data& dataSecond) {
		std::unique_lock<std::mutex> uniqueLockFirst{ dataFirst.mutex, std::defer_lock };
		std::unique_lock<std::mutex> uniqueLockSecond{ dataSecond.mutex, std::defer_lock };
		std::lock(uniqueLockFirst, uniqueLockSecond);
		std::swap(dataFirst.data, dataSecond.data);
	}
};

template <> 
class Data<std::vector<int>>{
protected:
	std::vector<int> data{};
public:
	std::mutex mutex;
	Data(const std::vector<int>& otherData) {
		data = otherData;
	}
	void PrintData(){
		for (size_t index{}; index < data.size(); ++index) {
			std::cout << data[index] << " ";
		}
		std::cout << std::endl;
	}
	void SwapDataFirstVariant(Data& dataFirst, Data& dataSecond) {
		std::lock(dataFirst.mutex, dataSecond.mutex);
		std::lock_guard<std::mutex> lockGuardFirst{ dataFirst.mutex, std::adopt_lock };
		std::lock_guard<std::mutex> lockGuardSecond{ dataSecond.mutex, std::adopt_lock };
		std::swap(dataFirst.data, dataSecond.data);
	}
	void SwapDataSecondVariant(Data& dataFirst, Data& dataSecond) {
		std::scoped_lock lock{ dataFirst.mutex, dataSecond.mutex };
		std::swap(dataFirst.data, dataSecond.data);
	}
	void SwapDataThirdVariant(Data& dataFirst, Data& dataSecond) {
		std::unique_lock<std::mutex> uniqueLockFirst{ dataFirst.mutex, std::defer_lock };
		std::unique_lock<std::mutex> uniqueLockSecond{ dataSecond.mutex, std::defer_lock };
		std::lock(uniqueLockFirst, uniqueLockSecond);
		std::swap(dataFirst.data, dataSecond.data);
	}
};

int main(int argc, char* argv[]) {
	std::vector<int> vectorFirst{ 1, 2, 3, 4 }, vectorSecond{ 6, 7, 8, 9 };
	Data<std::vector<int>> dataFirst(vectorFirst);
	Data<std::vector<int>> dataSecond(vectorSecond);
	std::cout << "------------ First variant ------------" << std::endl;
	std::cout << "First data: ";
	dataFirst.PrintData();
	std::cout << "Second data: ";
	dataSecond.PrintData();
	std::thread threadFirstFirstVariant{ [&]() { dataFirst.SwapDataFirstVariant(dataFirst, dataSecond); } };
	std::thread threadSecondFirstVariant{ [&]() { dataSecond.SwapDataFirstVariant(dataSecond, dataFirst); } };
	threadFirstFirstVariant.join();
	threadSecondFirstVariant.join();
	std::cout << "First data after double swapping: ";
	dataFirst.PrintData();
	std::cout << "Second data after double swapping: ";
	dataSecond.PrintData();
	std::cout << std::endl << "------------ Second variant ------------" << std::endl;
	std::cout << "First data: ";
	dataFirst.PrintData();
	std::cout << "Second data: ";
	dataSecond.PrintData();
	std::thread threadFirstSecondVariant{ [&]() { dataFirst.SwapDataSecondVariant(dataFirst, dataSecond); } };
	std::thread threadSecondSecondVariant{ [&]() { dataSecond.SwapDataSecondVariant(dataSecond, dataFirst); } };
	threadFirstSecondVariant.join();
	threadSecondSecondVariant.join();
	std::cout << "First data after double swapping: ";
	dataFirst.PrintData();
	std::cout << "Second data after double swapping: ";
	dataSecond.PrintData();
	std::cout << std::endl << "------------ Third variant ------------" << std::endl;
	std::cout << "First data: ";
	dataFirst.PrintData();
	std::cout << "Second data: ";
	dataSecond.PrintData();
	std::thread threadFirstThirdVariant{ [&]() { dataFirst.SwapDataSecondVariant(dataFirst, dataSecond); } };
	std::thread threadSecondThirdVariant{ [&]() { dataSecond.SwapDataSecondVariant(dataSecond, dataFirst); } };
	threadFirstThirdVariant.join();
	threadSecondThirdVariant.join();
	std::cout << "First data after double swapping: ";
	dataFirst.PrintData();
	std::cout << "Second data after double swapping: ";
	dataSecond.PrintData();
	return EXIT_SUCCESS;
}