#include "Reader.h"
#include "Book.h"

#include <algorithm>
#include <iostream>

Reader::Reader(
    const std::string& id,
    const std::string& name,
    const std::string& phone
)
    : readerId(id),
    name(name),
    phone(phone) {
}

std::string Reader::getReaderId() const {
    return readerId;
}

std::string Reader::getName() const {
    return name;
}

std::string Reader::getPhone() const {
    return phone;
}

int Reader::getBorrowCount() const {
    return static_cast<int>(borrowedBookIds.size());
}

bool Reader::borrowBook(Book& book) {
    // 每位读者最多借5本书
    if (borrowedBookIds.size() >= 5) {
        std::cout << "借书失败：每位读者最多借5本书。"
            << std::endl;
        return false;
    }

    // 不能重复借阅同一本图书
    auto it = std::find(
        borrowedBookIds.begin(),
        borrowedBookIds.end(),
        book.getBookId()
    );

    if (it != borrowedBookIds.end()) {
        std::cout << "借书失败：您已经借阅过《"
            << book.getTitle() << "》。"
            << std::endl;
        return false;
    }

    // 图书库存不足
    if (!book.borrowBook()) {
        std::cout << "借书失败：《"
            << book.getTitle() << "》当前没有库存。"
            << std::endl;
        return false;
    }

    borrowedBookIds.push_back(book.getBookId());

    std::cout << "借书成功：《"
        << book.getTitle() << "》。"
        << std::endl;

    return true;
}

bool Reader::returnBook(Book& book) {
    auto it = std::find(
        borrowedBookIds.begin(),
        borrowedBookIds.end(),
        book.getBookId()
    );

    // 该读者没有借过这本书
    if (it == borrowedBookIds.end()) {
        std::cout << "还书失败：您没有借阅《"
            << book.getTitle() << "》。"
            << std::endl;
        return false;
    }

    book.returnBook();
    borrowedBookIds.erase(it);

    std::cout << "还书成功：《"
        << book.getTitle() << "》。"
        << std::endl;

    return true;
}

void Reader::display() const {
    std::cout << "读者编号：" << readerId
        << " | 姓名：" << name
        << " | 电话：" << phone
        << " | 当前借阅数量：" << borrowedBookIds.size()
        << std::endl;
}