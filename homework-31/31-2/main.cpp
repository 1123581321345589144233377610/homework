#include <iostream>
#include <future>
#include <vector>

template<class Iterator, class Function>
void ForEach(Iterator begin, Iterator end, Function function) {
	if (begin == end) {
		*begin = function(*begin);
		return;
	}
	else {
		Iterator middle{ begin };
		std::advance(middle, (end - begin) / 2);
		auto result = std::async(ForEach<Iterator, Function>, begin, middle, function);
		result.get();
		for (Iterator index{ middle }; index != end; std::advance(index, 1)) {
			*index = function(*index);
		}
		return;
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
	std::vector<int> vector{ 1, 2, 3, 4 };
	ForEach(vector.begin(), vector.end(), [&](int value) { return value * value; });
	PrintData(vector.begin(), vector.end());
	return EXIT_SUCCESS;
}