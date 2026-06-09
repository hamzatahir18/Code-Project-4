#include <iostream>
#include <string>
using namespace std;

string userName;
string email;
string city;
string customerType;
string paymentMethod;

string products[8] = {
    "T-Shirt",
    "Jeans",
    "Shoes",
    "Watch",
    "Handbag",
    "Headphones",
    "Mobile Cover",
    "Perfume"
};

double prices[8] = {
    1200, 3500, 5000, 2500,
    4200, 3000, 700, 2800
};

double cartTotal = 0;

void registerUser()
{
    cout << "Enter User Name: ";
    cin.ignore();
    getline(cin, userName);

    cout << "Enter Email: ";
    cin >> email;

    cout << "Enter City: ";
    cin >> city;

    int choice;

    cout << "\n1. New Customer";
    cout << "\n2. Returning Customer";
    cout << "\nEnter Choice: ";
    cin >> choice;

    if(choice == 1)
        customerType = "New";
    else
        customerType = "Returning";

    cout << "\n1. Cash On Delivery";
    cout << "\n2. Debit/Credit Card";
    cout << "\nEnter Payment Method: ";
    cin >> choice;

    if(choice == 1)
        paymentMethod = "COD";
    else
        paymentMethod = "Card";
}

void displayProducts()
{
    cout << "\n========== PRODUCT LIST ==========\n";

    for(int i = 0; i < 8; i++)
    {
        cout << i + 1 << ". "
             << products[i]
             << " - Rs. "
             << prices[i]
             << endl;
    }
}

void addProductToCart()
{
    int productNo;
    int quantity;
    char choice;

    do
    {
        displayProducts();

        cout << "\nEnter Product Number: ";
        cin >> productNo;

        cout << "Enter Quantity: ";
        cin >> quantity;

        cartTotal =
        cartTotal +
        (prices[productNo - 1] * quantity);

        cout << "Add More Products? (Y/N): ";
        cin >> choice;

    }
    while(choice == 'Y' || choice == 'y');
}

double calculateProductTotal()
{
    return cartTotal;
}

double calculateGST(double total)
{
    return total * 0.17;
}

double calculateDeliveryCharges()
{
    if(city == "Lahore" ||
       city == "Karachi" ||
       city == "Islamabad")
    {
        return 250;
    }
    else
    {
        return 500;
    }
}

double calculateCustomerDiscount(double total)
{
    if(customerType == "New")
        return total * 0.05;
    else
        return total * 0.10;
}

double calculateOrderValueDiscount(double total)
{
    if(total >= 5000 && total <= 10000)
        return total * 0.05;

    else if(total > 10000)
        return total * 0.12;

    else
        return 0;
}

double calculatePaymentCharges(double amount)
{
    if(paymentMethod == "Card")
        return amount * 0.025;
    else
        return 0;
}

void displayCheckoutBill()
{
    double productTotal =
    calculateProductTotal();

    double gst =
    calculateGST(productTotal);

    double deliveryCharges =
    calculateDeliveryCharges();

    double customerDiscount =
    calculateCustomerDiscount(productTotal);

    double orderDiscount =
    calculateOrderValueDiscount(productTotal);

    double subTotal =
    productTotal +
    gst +
    deliveryCharges -
    customerDiscount -
    orderDiscount;

    double paymentCharges =
    calculatePaymentCharges(subTotal);

    double finalBill =
    subTotal +
    paymentCharges;

    cout << "\n========== CHECKOUT BILL ==========\n";

    cout << "User Name: "
         << userName << endl;

    cout << "Email: "
         << email << endl;

    cout << "City: "
         << city << endl;

    cout << "Customer Type: "
         << customerType << endl;

    cout << "\nProduct Total: Rs. "
         << productTotal << endl;

    cout << "GST: Rs. "
         << gst << endl;

    cout << "Delivery Charges: Rs. "
         << deliveryCharges << endl;

    cout << "Customer Discount: Rs. "
         << customerDiscount << endl;

    cout << "Order Value Discount: Rs. "
         << orderDiscount << endl;

    cout << "Payment Charges: Rs. "
         << paymentCharges << endl;

    cout << "\nFinal Payable Amount: Rs. "
         << finalBill << endl;

    cout << "===================================\n";
}

void displayUserDetails()
{
    cout << "\n========== USER DETAILS ==========\n";

    cout << "User Name: "
         << userName << endl;

    cout << "Email: "
         << email << endl;

    cout << "City: "
         << city << endl;

    cout << "Customer Type: "
         << customerType << endl;

    cout << "Payment Method: "
         << paymentMethod << endl;
}

int main()
{
    registerUser();

    int choice;

    do
    {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. View Products\n";
        cout << "2. Add Product To Cart\n";
        cout << "3. Calculate Checkout Bill\n";
        cout << "4. View User Details\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayProducts();
                break;

            case 2:
                addProductToCart();
                break;

            case 3:
                displayCheckoutBill();
                break;

            case 4:
                displayUserDetails();
                break;

            case 5:
                cout << "\nProgram Closed Successfully.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    }
    while(choice != 5);

    return 0;
}
