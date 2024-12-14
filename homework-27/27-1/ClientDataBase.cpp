#include "ClientDataBase.hpp"

void ClientDataBase::CreateTables() {
	pqxx::connection c{
		"host=localhost "
		"port=5432 "
		"dbname=StaffInfo "
		"user=postgres "
		"password=postgres"
	};
	pqxx::work tx{ c };
	tx.exec("CREATE TABLE IF NOT EXISTS PersonalInfo( "
		"person_id SERIAL PRIMARY KEY, "
		"name TEXT NOT NULL, "
		"surname TEXT NOT NULL, "
		"email TEXT NOT NULL);"
	);
	tx.exec("CREATE TABLE IF NOT EXISTS Telephone( "
		"telephone_id SERIAL PRIMARY KEY, "
		"telephone TEXT, "
		"human_id INTEGER, "
		"FOREIGN KEY (human_id) REFERENCES PersonalInfo(person_id));"
	);
	tx.commit();
}

void ClientDataBase::AddNewClient(const std::string& name, const std::string& surname, const std::string& email) {
	pqxx::connection c{
		"host=localhost "
		"port=5432 "
		"dbname=StaffInfo "
		"user=postgres "
		"password=postgres"
	};
	pqxx::work tx{ c };
	tx.exec("INSERT INTO PersonalInfo(name, surname, email) "
		"VALUES ('" + tx.esc(name) + "', '" + tx.esc(surname) + "', '" + tx.esc(email) + "');"
	);
	tx.commit();
}

void ClientDataBase::AddTelephone(const std::string& name, const std::string& surname, const std::string& telephone) {
	pqxx::connection c{
		"host=localhost "
		"port=5432 "
		"dbname=StaffInfo "
		"user=postgres "
		"password=postgres"
	};
	pqxx::work tx{ c };
	tx.exec("INSERT INTO Telephone(telephone, human_id) "
		"VALUES ('" + tx.esc(telephone) + "', (SELECT person_id FROM PersonalInfo WHERE name = '" + tx.esc(name) + "' LIMIT 1));"
	);
	tx.commit();
}

void ClientDataBase::SetNewName(const std::string& oldName, const std::string& surname, const std::string& newName) {
	pqxx::connection c{
		"host=localhost "
		"port=5432 "
		"dbname=StaffInfo "
		"user=postgres "
		"password=postgres"
	};
	pqxx::work tx{ c };
	tx.exec("UPDATE PersonalInfo SET name = '" + tx.esc(newName) + "' WHERE name = '" + tx.esc(oldName) + "' AND surname = '" + tx.esc(surname) + "';");
	tx.commit();
}

void ClientDataBase::SetNewSurname(const std::string& oldSurname, const std::string& name, const std::string& newSurname) {
	pqxx::connection c{
		"host=localhost "
		"port=5432 "
		"dbname=StaffInfo "
		"user=postgres "
		"password=postgres"
	};
	pqxx::work tx{ c };
	tx.exec("UPDATE PersonalInfo SET surname = '" + tx.esc(newSurname) + "' WHERE name = '" + tx.esc(name) + "' AND surname = '" + tx.esc(oldSurname) + "';");
	tx.commit();
}

void ClientDataBase::SetNewEmail(const std::string& name, const std::string& surname, const std::string& newEmail) {
	pqxx::connection c{
		"host=localhost "
		"port=5432 "
		"dbname=StaffInfo "
		"user=postgres "
		"password=postgres"
	};
	pqxx::work tx{ c };
	tx.exec("UPDATE PersonalInfo SET email = '" + tx.esc(newEmail) + "' WHERE name = '" + tx.esc(name) + "' AND surname = '" + tx.esc(surname) + "';");
	tx.commit();
}

void ClientDataBase::DeleteTelephone(const std::string& telephone) {
	pqxx::connection c{
		"host=localhost "
		"port=5432 "
		"dbname=StaffInfo "
		"user=postgres "
		"password=postgres"
	};
	pqxx::work tx{ c };
	tx.exec("DELETE FROM Telephone WHERE telephone = '" + tx.esc(telephone) + "';");
	tx.commit();
}

void ClientDataBase::DeleteClient(const std::string& name, const std::string& surname) {
	pqxx::connection c{
		"host=localhost "
		"port=5432 "
		"dbname=StaffInfo "
		"user=postgres "
		"password=postgres"
	};
	pqxx::work tx{ c };
	tx.exec("DELETE FROM PersonalInfo WHERE name = '" + tx.esc(name) + "' AND surname = '" + tx.esc(surname) + "';");
	tx.commit();
}

void ClientDataBase::FindClient(const std::string& name, const std::string& surname) {
	pqxx::connection c{
		"host=localhost "
		"port=5432 "
		"dbname=StaffInfo "
		"user=postgres "
		"password=postgres"
	};
	pqxx::work tx{ c };

	for (auto [name, surname, email] : tx.query<std::string, std::string, std::string>("SELECT name, surname, email FROM PersonalInfo WHERE name = '" + tx.esc(name) + "' AND surname = '" + tx.esc(surname) + "';")) {
		std::cout << "NAME: " << name << " \t" << " SURNAME: " << surname << " \t " << "EMAIL: " << email << " \t" << std::endl;
	}
	tx.commit();
}