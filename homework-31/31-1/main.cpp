#include <iostream>
#include <future>
#include <vector>

template<class Iterator>
Iterator Minimum(Iterator begin, Iterator end, std::promise<Iterator> promise) {
	Iterator minimum{begin};
	for (Iterator index{ begin }; index != end; std::advance(index, 1)) {
		if (*index < *minimum) {
			minimum = index;
		}
	}
	promise.set_value(minimum);
	return minimum;
}

template<class Iterator>
void SelectionSort(Iterator begin, Iterator end) {
	for (Iterator index{ begin }; index != end; std::advance(index, 1)) {
		std::promise<Iterator> promise;
		std::future<Iterator> future = promise.get_future();
		std::thread thread{ Minimum<Iterator>, index, end, std::move(promise) };
		thread.join();
		Iterator minimumIndex{ future.get() };
		std::iter_swap(minimumIndex, index);
	}
}

template<class Iterator>
void PrintData(Iterator begin, Iterator end) {
	for (Iterator index{ begin }; index != end; std::advance(index, 1)) {
		std::cout << *index << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[]) {
	std::vector<int> vector{ 4, 3, 2, 1 };
	SelectionSort<std::vector<int>::iterator>(vector.begin(), vector.end());
	PrintData<std::vector<int>::iterator>(vector.begin(), vector.end());
	return EXIT_SUCCESS;
}