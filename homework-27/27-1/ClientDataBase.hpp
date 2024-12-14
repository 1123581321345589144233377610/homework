#pragma once
#include <iostream>
#include <pqxx/pqxx>

class ClientDataBase {
public:
	void CreateTables();

	void AddNewClient(const std::string& name, const std::string& surname, const std::string& email);

	void AddTelephone(const std::string& name, const std::string& surname, const std::string& telephone);

	void SetNewName(const std::string& oldName, const std::string& surname, const std::string& newName);

	void SetNewSurname(const std::string& oldSurname, const std::string& name, const std::string& newSurname);

	void SetNewEmail(const std::string& name, const std::string& surname, const std::string& newEmail);

	void DeleteTelephone(const std::string& telephone);

	void DeleteClient(const std::string& name, const std::string& surname);

	void FindClient(const std::string& name, const std::string& surname);
};