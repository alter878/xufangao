#pragma once
#include <string>

class Book {
private:
    std::string bookId;
    std::string title;
    std::string author;
    std::string category;
    int totalCount;
    int availableCount;

public:
    Book(
        const std::string& id,
        const std::string& title,
        const std::string& author,
        const std::string& category,
        int totalCount,
        int availableCount
    );

    std::string getBookId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getCategory() const;

    int getTotalCount() const;
    int getAvailableCount() const;

    bool borrowBook();
    void returnBook();

    void display() const;
};
