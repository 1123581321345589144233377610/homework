#include <iostream>
#include <pqxx/pqxx>

class ClientDataBase {
public:
	void CreateTables() {
		try {
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
		catch (const std::exception& exception) {
			std::cerr << exception.what() << std::endl;
		}
		catch (...) {
			std::cerr << "Error: Unknown Error!" << std::endl;
		}
	}

	void AddNewClient(const std::string &name, const std::string &surname, const std::string &email) {
		try {
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
		catch (const std::exception &exception) {
			std::cerr << exception.what() << std::endl;
		}
		catch (...) {
			std::cerr << "Error: Unknown Error!" << std::endl;
		}
	}

	void AddTelephone(const std::string &name, const std::string &surname, const std::string &telephone) {
		try {
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
		catch (const std::exception& exception) {
			std::cerr << exception.what() << std::endl;
		}
		catch (...) {
			std::cerr << "Error: Unknown Error!" << std::endl;
		}
	}

	void SetNewName(const std::string &oldName, const std::string &surname, const std::string &newName) {
		try {
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
		catch (const std::exception& exception) {
			std::cerr << exception.what() << std::endl;
		}
		catch (...) {
			std::cerr << "Error: Unknown Error!" << std::endl;
		}
	}

	void SetNewSurname(const std::string &oldSurname, const std::string &name, const std::string &newSurname) {
		try {
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
		catch (const std::exception& exception) {
			std::cerr << exception.what() << std::endl;
		}
		catch (...) {
			std::cerr << "Error: Unknown Error!" << std::endl;
		}
	}

	void SetNewEmail(const std::string &name, const std::string &surname, const std::string &newEmail) {
		try {
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
		catch (const std::exception& exception) {
			std::cerr << exception.what() << std::endl;
		}
		catch (...) {
			std::cerr << "Error: Unknown Error!" << std::endl;
		}
	}

	void DeleteTelephone(const std::string &telephone) {
		try {
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
		catch (const std::exception& exception) {
			std::cerr << exception.what() << std::endl;
		}
		catch (...) {
			std::cerr << "Error: Unknown Error!" << std::endl;
		}
	}

	void DeleteClient(const std::string &name, const std::string &surname) {
		try {
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
		catch (const std::exception& exception) {
			std::cerr << exception.what() << std::endl;
		}
		catch (...) {
			std::cerr << "Error: Unknown Error!" << std::endl;
		}
	}

	void FindClient(const std::string& name, const std::string &surname) {
		try {
			pqxx::connection c{
				"host=localhost "
				"port=5432 "
				"dbname=StaffInfo "
				"user=postgres "
				"password=postgres"
			};
			pqxx::work tx{ c };

			for (auto [name, surname, email] : tx.query<std::string, std::string, std::string>("SELECT name, surname, email FROM PersonalInfo WHERE name = '" + tx.esc(name) + "' AND surname = '" + tx.esc(surname) + "';")){
				std::cout << "NAME: " << name << " \t" << " SURNAME: " << surname << " \t " << "EMAIL: " << email << " \t" << std::endl;
			}
			tx.commit();
		}
		catch (const std::exception& exception) {
			std::cerr << exception.what() << std::endl;
		}
		catch (...) {
			std::cerr << "Error: Unknown Error!" << std::endl;
		}
	}
};

int main(int argc, char* argv[]) {
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
	return EXIT_SUCCESS;
};

