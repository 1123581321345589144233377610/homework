#include <iostream>
#include <string>
struct acc {
	int id;
	std::string name;
	double money;
};

void update_acc(acc &account, double new_money) {
	account.money = new_money;
}

int main() {
	acc account;
	double new_money;
	std::cout << "Enter the account number: ";
	std::cin >> account.id;
	std::cout << "Enter the name of the owner: ";
	std::cin >> account.name;
	std::cout << "Enter the balance: ";
	std::cin >> account.money;
	std::cout << "Enter a new balance: ";
	std::cin >> new_money;
	update_acc(account, new_money);
	std::cout << "Your account: " << account.name << ", " << account.id << ", " << account.money;
	return 0;
}