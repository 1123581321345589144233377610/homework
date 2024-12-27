#include "Tables.hpp"
#include "FindShops.hpp"

int main(int argc, char* argv[]) {
	try {
		std::string connectionString =
			"host=localhost "
			"port=5432 "
			"dbname=BookDB "
			"user=postgres "
			"password=postgres";
		auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
		Wt::Dbo::Session session;
		session.setConnection(std::move(postgres));
		session.mapClass<Publisher>("publisher");
		session.mapClass<Book>("book");
		session.mapClass<Shop>("shop");
		session.mapClass<Stock>("stock");
		session.mapClass<Sale>("sale");
		session.createTables();

		Wt::Dbo::Transaction transaction{ session };
		std::unique_ptr<Publisher> publisher1{ new Publisher() };
		publisher1->name = "Alpina";
		Wt::Dbo::ptr<Publisher> publisher1Ptr = session.add(std::move(publisher1));
		std::unique_ptr<Publisher> publisher2{ new Publisher() };
		publisher2->name = "Mann, Ivanov and Ferber";
		Wt::Dbo::ptr<Publisher> publisher2Ptr = session.add(std::move(publisher2));
		std::unique_ptr<Publisher> publisher3{ new Publisher() };
		publisher3->name = "Prosveshenie";
		Wt::Dbo::ptr<Publisher> publisher3Ptr = session.add(std::move(publisher3));

		std::unique_ptr<Book> book1{ new Book() };
		book1->title = "Don Kihot";
		book1->publisher = publisher1Ptr;
		Wt::Dbo::ptr<Book> book1Ptr = session.add(std::move(book1));
		std::unique_ptr<Book> book2{ new Book() };
		book2->title = "Dune";
		book2->publisher = publisher2Ptr;
		Wt::Dbo::ptr<Book> book2Ptr = session.add(std::move(book2));
		std::unique_ptr<Book> book3{ new Book() };
		book3->title = "The Great Gatsby";
		book3->publisher = publisher3Ptr;
		Wt::Dbo::ptr<Book> book3Ptr = session.add(std::move(book3));

		std::unique_ptr<Shop> shop1{ new Shop() };
		shop1->name = "Biblio Globus";
		Wt::Dbo::ptr<Shop> shop1Ptr = session.add(std::move(shop1));
		std::unique_ptr<Shop> shop2{ new Shop() };
		shop2->name = "Moskovskiy Dom Knigi";
		Wt::Dbo::ptr<Shop> shop2Ptr = session.add(std::move(shop2));
		std::unique_ptr<Shop> shop3{ new Shop() };
		shop3->name = "Falanster";
		Wt::Dbo::ptr<Shop> shop3Ptr = session.add(std::move(shop3));

		std::unique_ptr<Stock> stock1{ new Stock() };
		stock1->book = book1Ptr;
		stock1->shop = shop1Ptr;
		stock1->count = 1000;
		Wt::Dbo::ptr<Stock> stock1Ptr = session.add(std::move(stock1));
		std::unique_ptr<Stock> stock2{ new Stock() };
		stock2->book = book2Ptr;
		stock2->shop = shop2Ptr;
		stock2->count = 790;
		Wt::Dbo::ptr<Stock> stock2Ptr = session.add(std::move(stock2));
		std::unique_ptr<Stock> stock3{ new Stock() };
		stock3->book = book3Ptr;
		stock3->shop = shop3Ptr;
		stock3->count = 15;
		Wt::Dbo::ptr<Stock> stock3Ptr = session.add(std::move(stock3));

		std::unique_ptr<Sale> sale1{ new Sale() };
		sale1->price = 500;
		sale1->date_sale = "2024-12-27";
		sale1->count = 10;
		sale1->stock = stock1Ptr;
		Wt::Dbo::ptr<Sale> sale1Ptr = session.add(std::move(sale1));
		std::unique_ptr<Sale> sale2{ new Sale() };
		sale2->price = 1990;
		sale2->date_sale = "2024-12-27";
		sale2->count = 50;
		sale2->stock = stock2Ptr;
		Wt::Dbo::ptr<Sale> sale2Ptr = session.add(std::move(sale2));
		std::unique_ptr<Sale> sale3{ new Sale() };
		sale3->price = 999;
		sale3->date_sale = "2024-12-27";
		sale3->count = 5;
		sale3->stock = stock3Ptr;
		Wt::Dbo::ptr<Sale> sale3Ptr = session.add(std::move(sale3));

		std::string nameOfPublisher{};
		std::cout << "Enter a name of publisher: ";
		std::cin >> nameOfPublisher;
		FindShops(session, nameOfPublisher);
		transaction.commit();
	}
	catch (const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Error: Unknown Error!" << std::endl;
	}
	return EXIT_SUCCESS;
}