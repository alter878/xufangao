#include "Book.h"
#include <iostream>
#include <stdexcept>

Book::Book(
    const std::string& id,
    const std::string& title,
    const std::string& author,
    const std::string& category,
    int totalCount,
    int availableCount
)
    : bookId(id),
    title(title),
    author(author),
    category(category),
    totalCount(totalCount),
    availableCount(availableCount) {
    if (totalCount < 0 || availableCount < 0) {
        throw std::invalid_argument("图书数量不能为负数");
    }

    if (availableCount > totalCount) {
        throw std::invalid_argument("可借数量不能大于总数量");
    }
}

std::string Book::getBookId() const {
    return bookId;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getCategory() const {
    return category;
}

int Book::getTotalCount() const {
    return totalCount;
}

int Book::getAvailableCount() const {
    return availableCount;
}

bool Book::borrowBook() {
    if (availableCount <= 0) {
        return false;
    }

    availableCount--;
    return true;
}

void Book::returnBook() {
    if (availableCount < totalCount) {
        availableCount++;
    }
}

void Book::display() const {
    std::cout << "图书编号：" << bookId
        << " | 书名：" << title
        << " | 作者：" << author
        << " | 分类：" << category
        << " | 总数量：" << totalCount
        << " | 可借数量：" << availableCount
        << std::endl;
}