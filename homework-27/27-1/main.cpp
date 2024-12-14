#include "ClientDataBase.hpp"

int main(int argc, char* argv[]) {
	try {
		ClientDataBase myDataBase;
		myDataBase.CreateTables();
		myDataBase.AddNewClient("Dima", "Shirokov", "myemail@yandex.ru");
		myDataBase.AddTelephone("Dima", "Shirokov", "88005353535");
		myDataBase.SetNewName("Dima", "Shirokov", "Edward");
		myDataBase.SetNewSurname("Shirokov", "Edward", "Hisenberg");
		myDataBase.SetNewEmail("Edward", "Hisenberg", "myemail@yahoo.com");
		myDataBase.DeleteTelephone("88005353535");
		myDataBase.DeleteClient("Edward", "Hisenberg");
		myDataBase.AddNewClient("Bill", "Gates", "microsoft@microsoft.com");
		myDataBase.FindClient("Bill", "Gates");
	}
	catch (const std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Error: Unknown Error!" << std::endl;
	}
	return EXIT_SUCCESS;
};