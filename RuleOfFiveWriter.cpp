// Spencer Banasik
// 1/9/2025
// I'm tired of writing copy and move constructors.
// I'm tired of writing assignment and move assignment operator overloads.
// This will help automate this process.
#include <iostream>
#include <string>
#include <vector>
#include <span>

std::vector<std::string> member_vars;
std::vector<std::string> overwritten_vars;

std::string class_name = "";
std::string name_space = "";

void collect_class_name() {
    std::cout << "Enter namespace: \n";
    std::getline(std::cin, name_space);
    std::cout << "Enter class name: \n";
    std::getline(std::cin, class_name);
}

void collect_all_member_vars() {
    bool done = false;
    std::string buffer = "";
    char letter = '\0';
    while (!done) {
        std::cout << "Variable Name: \n";
        std::getline(std::cin, buffer);
        member_vars.push_back(buffer);
        std::cout << "Is it overwritten in moves? (y/n)\n";
        std::cin >> letter;
        std::cin.ignore();
        if (letter == 'y' || letter == 'Y')
            overwritten_vars.push_back(buffer);
        std::cout << "Another member variable? (y/n)\n";
        std::cin >> letter;
        std::cin.ignore();
        if (letter != 'y' && letter != 'Y')
            done = true;

        buffer = "";
        letter = '\0';
    }
}

void write_empty_constructor_decl() {
    std::cout << class_name << "() \n    : ";
    std::span<std::string> span{ member_vars.begin(), member_vars.end() - 1 };
    for (auto member : span) {
        std::cout << "    " << member << "(),\n";
    }
    std::cout << "    " << member_vars.back() << "() {}\n";
}

void write_copy_constructor_decl() {
    std::cout << class_name << "(" << class_name << "& other);\n";
}
void write_move_constructor_decl() {
    std::cout << class_name << "(" << class_name << "&& other) noexcept;\n";
}
void write_destructor_decl() {
    std::cout << "~" << class_name << "();\n";
}

void write_copy_constructor() {
    std::cout << name_space << class_name << "(" << class_name << "& other)\n"
        << "    : ";
    std::span<std::string> span{ member_vars.begin(), member_vars.end() - 1};

    for (auto member : span) {
        std::cout << "    " << member << "(other." << member << "),\n";
    }
    std::cout << "    " << member_vars.back() << "(other." << member_vars.back() << ") {\n}\n";
}

void write_copy_assignment() {
    std::cout << class_name << "& operator=(" << class_name << "& other) {\n"
        << "    if (this == &other)\n        return;\n";
    for (auto member : member_vars) {
        std::cout << "    " << member << " = other." << member << ";\n";
    }
    std::cout << "    return *this;\n;
    std::cout << "}\n";
}

void write_move_constructor() {
    std::cout << name_space << class_name << "(" << class_name << "&& other) noexcept\n"
        << "    : ";
    std::span<std::string> span{ member_vars.begin(), member_vars.end() - 1 };

    for (auto member : span) {
        std::cout << "    " << member << "(std::move(other." << member << ")),\n";
    }
    std::cout << "    " << member_vars.back() << "(std::move(other." << member_vars.back() << ")) {\n";
    for (auto member : overwritten_vars) {
        std::cout << "    other." << member << " = nullptr;\n";
    }
    std::cout << "}\n";
}
void write_move_assignment() {
    std::cout << class_name << "& operator=(" << class_name << "&& other) noexcept {\n"
        << "    if (this == &other)\n        return;\n";
    for (auto member : member_vars) {
        std::cout << "    " << member << " = std::move(other." << member << ");\n";
    }
    for (auto member : overwritten_vars) {
        std::cout << "    other." << member << " = nullptr;\n";
    }
    std::cout << "    return *this;\n;
    std::cout << "}\n";
}

int main() {
    char empty;
    collect_class_name();
    collect_all_member_vars();
    std::cout << "// Header File\n";
    write_empty_constructor_decl();
    write_copy_constructor_decl();
    write_move_constructor_decl();
    write_copy_assignment();
    write_move_assignment();
    write_destructor_decl();
    std::cout << "// Cpp File\n";
    write_copy_constructor();
    write_move_constructor();
    std::cin >> empty;
    return 0;
}