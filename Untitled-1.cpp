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
