#include "FindShops.hpp"

void FindShops(Wt::Dbo::Session& session, std::string nameOfPublisher) {
	Wt::Dbo::ptr<Publisher> publisher = session.find<Publisher>().where("name = ?").bind(nameOfPublisher);
	Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books = session.find<Book>().where("publisher_id = ?").bind(publisher);
	std::vector<Wt::Dbo::collection<Wt::Dbo::ptr<Stock>>> stocks;
	for (const auto& id : books) {
		stocks.push_back(session.find<Stock>().where("book_id = ?").bind(id.id()));
	}
	std::vector<Wt::Dbo::collection<Wt::Dbo::ptr<Shop>>> shops;
	for (const auto& column : stocks) {
		for (const auto& id : column) {
			shops.push_back(session.find<Shop>().where("id = ?").bind(id->shop));
		}
	}
	std::cout << "Shops with books of " << nameOfPublisher << std::endl;
	std::set<std::string> names;
	for (const auto& column : shops) {
		for (const auto& id : column) {
			names.insert(id->name);
		}
	}
	for (const auto& name : names) {
		std::cout << name << std::endl;
	}
}