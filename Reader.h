#pragma once
#include <string>
#include <vector>

class Book;

class Reader {
private:
    std::string readerId;
    std::string name;
    std::string phone;
    std::vector<std::string> borrowedBookIds;

public:
    Reader(
        const std::string& id,
        const std::string& name,
        const std::string& phone
    );

    std::string getReaderId() const;
    std::string getName() const;
    std::string getPhone() const;
    int getBorrowCount() const;

    bool borrowBook(Book& book);
    bool returnBook(Book& book);

    void display() const;
};