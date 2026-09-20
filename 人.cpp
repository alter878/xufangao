#include "人.h"
#include <iostream>

Person::Person() noexcept : name_{}, age_{0} {}

Person::Person(std::string name, int age) noexcept
    : name_{std::move(name)}, age_{age} {}

const std::string& Person::name() const noexcept {
    return name_;
}

void Person::setName(const std::string& name) noexcept {
    name_ = name;
}

int Person::age() const noexcept {
    return age_;
}

void Person::setAge(int age) noexcept {
    age_ = age;
}

void Person::sayHello(std::ostream& os) const {
    os << "你好，我叫 " << name_ << "，我今年 " << age_ << " 岁。" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name_ << " (" << p.age_ << ")";
    return os;
}

// 如果你想把 main 放在此文件中（也可以放在源.cpp），示例：
int main() {
    Person p("张三", 20);
    p.sayHello();
    // std::cout << p << std::endl;
    return 0;
}