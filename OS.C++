#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class product{
    public:
        int productID;
        string name;
        float price;

        product(int id, string name, float price) 
        this ->productID = id;
        this->name = name;
        this->price = price;
}


// // Product class to represent each product in the store
// class Product {
// public:
//     int productID;
//     string name;
//     float price;

//     // Constructor to initialize a product
//     Product(int id, string name, float price) {
//         this->productID = id;
//         this->name = name;
//         this->price = price;
//     }

//     // Function to display the product details
//     void displayProduct() {
//         cout << "Product ID: " << productID << ", Name: " << name << ", Price: $" << price << endl;
//     }
// };

// // CartItem class to represent an item in the cart (product and quantity)
// class CartItem {
// public:
//     Product product;
//     int quantity;

//     // Constructor to initialize a cart item
//     CartItem(Product product, int quantity) : product(product), quantity(quantity) {}

//     // Calculate total price for this cart item
//     float totalPrice() {
//         return product.price * quantity;
//     }

//     // Function to display the cart item details
//     void displayCartItem() {
//         cout << "Product: " << product.name << ", Quantity: " << quantity << ", Total: $" << totalPrice() << endl;
//     }
// };

// // ShoppingCart class to manage the shopping cart
// class ShoppingCart {
// private:
//     vector<CartItem> items;

// public:
//     // Add product to cart
//     void addToCart(Product product, int quantity) {
//         CartItem cartItem(product, quantity);
//         items.push_back(cartItem);
//     }

//     // Display cart items
//     void viewCart() {
//         if (items.empty()) {
//             cout << "Your cart is empty!" << endl;
//             return;
//         }
//         cout << "\n--- Your Cart ---\n";
//         float total = 0.0;
//         for (auto& item : items) {
//             item.displayCartItem();
//             total += item.totalPrice();
//         }
//         cout << "\nTotal Amount: $" << total << endl;
//     }

//     // Checkout (calculate total price and clear cart)
//     void checkout() {
//         float total = 0.0;
//         for (auto& item : items) {
//             total += item.totalPrice();
//         }
//         cout << "\n--- Checkout ---\n";
//         cout << "Total Amount: $" << total << endl;
//         cout << "Thank you for shopping with us!\n";
//         items.clear();  // Empty the cart after checkout
//     }

//     // Function to clear the cart (if needed)
//     void clearCart() {
//         items.clear();
//     }
// };

// // ShoppingSystem class to handle product display and user actions
// class ShoppingSystem {
// private:
//     vector<Product> products;
//     ShoppingCart cart;

// public:
//     // Load products from a file (simulate a database)
//     void loadProducts() {
//         ifstream file("products.txt");
//         if (!file.is_open()) {
//             cout << "Error opening product file!" << endl;
//             return;
//         }
//         int id;
//         string name;
//         float price;
//         while (file >> id) {
//             file.ignore(); // Ignore newline character
//             getline(file, name);
//             file >> price;
//             products.push_back(Product(id, name, price));
//         }
//         file.close();
//     }

//     // Display all available products
//     void displayProducts() {
//         cout << "\n--- Available Products ---\n";
//         for (auto& product : products) {
//             product.displayProduct();
//         }
//     }

//     // Find a product by ID
//     Product* findProductByID(int productID) {
//         for (auto& product : products) {
//             if (product.productID == productID) {
//                 return &product;
//             }
//         }
//         return nullptr; // Product not found
//     }

//     // Start the shopping system
//     void run() {
//         loadProducts();

//         int choice;
//         while (true) {
//             cout << "\n--- Online Shopping System ---\n";
//             cout << "1. View Products\n";
//             cout << "2. Add Product to Cart\n";
//             cout << "3. View Cart\n";
//             cout << "4. Checkout\n";
//             cout << "5. Exit\n";
//             cout << "Enter your choice: ";
//             cin >> choice;

//             if (choice == 1) {
//                 displayProducts();
//             }
//             else if (choice == 2) {
//                 int productID, quantity;
//                 cout << "Enter Product ID to add to cart: ";
//                 cin >> productID;
//                 Product* product = findProductByID(productID);
//                 if (product) {
//                     cout << "Enter Quantity: ";
//                     cin >> quantity;
//                     cart.addToCart(*product, quantity);
//                     cout << "Product added to cart!\n";
//                 } else {
//                     cout << "Invalid Product ID.\n";
//                 }
//             }
//             else if (choice == 3) {
//                 cart.viewCart();
//             }
//             else if (choice == 4) {
//                 cart.checkout();
//             }
//             else if (choice == 5) {
//                 cout << "Exiting the system...\n";
//                 break;
//             } else {
//                 cout << "Invalid choice. Please try again.\n";
//             }
//         }
//     }
// };

// int main() {
//     ShoppingSystem system;
//     system.run();
//     return 0;
// }
