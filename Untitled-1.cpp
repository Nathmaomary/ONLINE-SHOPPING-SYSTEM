// Product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    Product(int id, const std::string& name, double price);
    int getId() const;
    std::string getName() const;
    double getPrice() const;

private:
    int id;
    std::string name;
    double price;
};

#endif

// Product.cpp
#include "Product.h"

Product::Product(int id, const std::string& name, double price)
    : id(id), name(name), price(price) {}

int Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

// User.h
#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string& username, const std::string& password);
    bool authenticate(const std::string& password) const;
    std::string getUsername() const;

private:
    std::string username;
    std::string password;
};

#endif

// User.cpp
#include "User.h"

user::User(const std::string& username, const std::string& password)
    : username(username), password(password) {}

bool User::authenticate(const std::string& password) const {
    return this->password == password;
}

std::string User::getUsername() const {
    return username;
}



// ShoppingCart.h
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "Product.h"

class ShoppingCart {
public:
    void addProduct(const Product& product);
    void removeProduct(int productId);
    double calculateTotal() const;
    void displayCart() const;

private:
    std::vector<Product> products;
};

#endif

// ShoppingCart.cpp
#include "ShoppingCart.h"
#include <iostream>

void ShoppingCart::addProduct(const Product& product) {
    products.push_back(product);
}

void ShoppingCart::removeProduct(int productId) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == productId) {
            products.erase(it);
            break;
        }
    }
}

double ShoppingCart::calculateTotal() const {
    double total = 0;
    for (const auto& product : products) {
        total += product.getPrice();
    }
    return total;
}

void ShoppingCart::displayCart() const {
    std::cout << "Products in Cart: \n";
    for (const auto& product : products) {
        std::cout << "ID: " << product.getId() << ", Name: " << product.getName() 
                  << ", Price: $" << product.getPrice() << std::endl;
    }
}

// System.h
#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "User.h"
#include "Product.h"
#include "ShoppingCart.h"

class System {
public:
    void registerUser(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
    void addProductToCart(int productId);
    void displayProducts() const;
    void checkout() const;

private:
    std::vector<User> users;
    std::vector<Product> products;
    ShoppingCart cart;
    User* loggedInUser = nullptr;
};

#endif

// System.cpp
#include "System.h"
#include <iostream>

void System::registerUser(const std::string& username, const std::string& password) {
    users.push_back(User(username, password));
    std::cout << "User " << username << " registered successfully!\n";
}

bool System::loginUser(const std::string& username, const std::string& password) {
    for (auto& user : users) {
        if (user.getUsername() == username && user.authenticate(password)) {
            loggedInUser = &user;
            std::cout << "Login successful!\n";
            return true;
        }
    }
    std::cout << "Invalid username or password.\n";
    return false;
}

void System::addProductToCart(int productId) {
    for (const auto& product : products) {
        if (product.getId() == productId) {
            cart.addProduct(product);
            std::cout << "Product added to cart!\n";
            return;
        }
    }
    std::cout << "Product not found.\n";
}

void System::displayProducts() const {
    std::cout << "Available Products:\n";
    for (const auto& product : products) {
        std::cout << "ID: " << product.getId() << ", Name: " << product.getName() 
                  << ", Price: $" << product.getPrice() << std::endl;
    }
}

void System::checkout() const {
    if (!loggedInUser) {
        std::cout << "You must log in to checkout.\n";
        return;
    }

    cart.displayCart();
    std::cout << "Total: $" << cart.calculateTotal() << std::endl;
    std::cout << "Thank you for your purchase, " << loggedInUser->getUsername() << "!\n";
}
