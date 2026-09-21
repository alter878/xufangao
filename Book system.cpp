#include "Book.h"
#include "Reader.h"

#include <iostream>

int main() {
    Book book1(
        "B001",
        "C++程序设计",
        "谭浩强",
        "计算机",
        3,
        3
    );

    Book book2(
        "B002",
        "高等数学",
        "同济大学",
        "数学",
        2,
        2
    );

    Reader reader1(
        "R001",
        "张三",
        "13800000000"
    );

    Reader reader2(
        "R002",
        "李四",
        "13900000000"
    );

    std::cout << "===== 初始信息 =====" << std::endl;
    book1.display();
    book2.display();
    reader1.display();
    reader2.display();

    std::cout << "\n===== 借书操作 =====" << std::endl;
    reader1.borrowBook(book1);
    reader1.borrowBook(book2);

    std::cout << "\n===== 借书后信息 =====" << std::endl;
    book1.display();
    book2.display();
    reader1.display();

    std::cout << "\n===== 其他读者借书 =====" << std::endl;
    reader2.borrowBook(book1);

    std::cout << "\n===== 还书操作 =====" << std::endl;
    reader1.returnBook(book1);

    std::cout << "\n===== 最终信息 =====" << std::endl;
    book1.display();
    book2.display();
    reader1.display();
    reader2.display();

    return 0;
}