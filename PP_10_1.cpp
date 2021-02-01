#include<iostream>
#include<cstring>

using namespace std;

class item {
    int item_id;
    string item_name, item_type;
    float item_price;
    public:
        void get_item_data(string type);
        void display_item_data();
};
 
class sale {
    int per;
    float sales;
    public:
        void get_data() {
            cout << "\nSales";
            cout << "\n1 -> Increase  2 -> Decrease";
            cout << "\nChoice: ";
            cin >> per;
            if (per == 1) {
                cout << "\nEnter the percentage increase in sales for the past three months: ";
                cin >> sales;
            } else {
                cout << "\nEnter the percentage decrease in sales for the past three months: ";
                cin >> sales;
            }
        }
        void display_data() {
            if (per == 1) 
                cout << "\nSales for past three months increased by " << sales << "%";
            else
                cout << "\nSales for past three months decreased by " << sales << "%";
        }
};

class hwitem : protected item, protected sale {
    string hw_manufacturer;
    public: 
        void get();
        void put();
};

class switem : private item, private sale {
    string sw_manufacturer;
    public:
        void input_data();
        void print_data();
};

void item::get_item_data(string type) {
    item_type = type;
    cout << "\nEnter item id: ";
    cin >> item_id;
    cout << "\nEnter item name: ";
    cin >> item_name;
    cout << "\nEnter item price: ";
    cin >> item_price;
}

void item::display_item_data() {
    cout << "\nID: " << item_id << " \t Type: ";
    cout << item_type << " \t Price: " << item_price;
    cout << " \t Name: " << item_name;
}

void hwitem::get() {
    get_item_data("Hardware");
    cout << "\nEnter Hardware item manufacturer: ";
    cin >> hw_manufacturer;
    get_data();
}

void hwitem::put() {
    display_item_data();
    cout << "\nHardware manufacturer: " << hw_manufacturer;
    display_data();
    cout << endl;
}

void switem::input_data() {
    get_item_data("Software");
    cout << "\nEnter Software item manufacturer: ";
    cin >> sw_manufacturer;
    get_data();
}

void switem::print_data() {
    display_item_data();
    cout << "\nSoftware manufacturer: " << sw_manufacturer;
    display_data();
    cout << endl;
}

int main() {
    hwitem h[20];
    switem s[20];
    int choice, type, hardware, software;
    int hw_count = 0, sw_count = 0;
    char ch, c;
    do {
        cout << "\n1. Enter data of the items";
        cout << "\n2. Display data for items";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                do {
                    cout << "\n1 -> Hardware    2 -> Software";
                    cout << "\nChoice: ";
                    cin >> type;
                    if (type == 1) {
                        cout << "\nEnter number of items: ";
                        cin >> hardware;
                        for (int i = 0; i < hardware; i++) {
                            cout << "\n\nITEM " << i + 1 << endl;
                            h[i].get();
                            hw_count = hw_count + 1;
                        }
                    } else if (type == 2) {
                        cout << "\nEnter number of items: ";
                        cin >> software;
                        for (int i = 0; i < software; i++) {
                            cout << "\n\nITEM " << i + 1 << endl;
                            s[i].input_data();
                            sw_count = sw_count + 1;
                        }
                    }
                cout << "\nDo you want to enter more items(y/n): ";
                cin >> ch;
                } while (ch == 'y' || ch == 'Y');
                break;
            case 2:
                if (hw_count == 0 && sw_count > 0) {
                    cout << "\n\n\t Software items" << endl;
                    cout << "-----------------------------------------------------" << endl;
                    for (int i = 0; i < sw_count; i++) {
                        cout << endl;
                        s[i].print_data();
                    }
                    cout << "\n-----------------------------------------------------" << endl;
                } else if (sw_count == 0 && hw_count > 0) {
                    cout << "\n\t Hardware items" << endl;
                    cout << "-----------------------------------------------------" << endl;
                    for (int i = 0; i < hw_count; i++) {
                        cout << endl;
                        h[i].put();
                    }
                    cout << "\n-----------------------------------------------------" << endl;
                } else {
                    cout << "\n\t Hardware items" << endl;
                    cout << "-----------------------------------------------------" << endl;
                    for (int i = 0; i < hw_count; i++) {
                        cout << endl;
                        h[i].put();
                    }
                    cout << "\n-----------------------------------------------------" << endl;
                    cout << "\n\n\t Software items" << endl;
                    cout << "-----------------------------------------------------" << endl;
                    for (int i = 0; i < sw_count; i++) {
                        cout << endl;
                        s[i].print_data();
                    }
                    cout << "\n-----------------------------------------------------" << endl;
                }
            default:
                cout << "\nWrong choice";
        }
        cout << "\nDo you want to perform more operations(y/n): ";
        cin >> c;
    }while(c == 'y' || c == 'Y');
    return 0;
}