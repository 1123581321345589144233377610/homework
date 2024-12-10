#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>

void print_letter_frequency(const std::string &str) {
	std::unordered_map<char, unsigned int> umap{};
	std::vector<std::pair<char, unsigned int>> vector{};
	std::for_each(str.begin(), str.end(), [&umap](const char &ch){ ++umap[ch]; });
	std::for_each(umap.begin(), umap.end(), [&vector](const auto& item) { vector.push_back(item); });
	std::sort(vector.begin(), vector.end(), [&vector](const auto& item_first, const auto& item_second) { return item_first.second > item_second.second; });
	std::for_each(vector.begin(), vector.end(), [&vector](const auto &item) { std::cout << item.first << ": " << item.second << std::endl; });
}

int main(int argc, char* argv[]) {
	print_letter_frequency("Hello world!!");
	return EXIT_SUCCESS;
}
