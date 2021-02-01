#include <iostream>
#include <ctime>
#include <cstring>
   
using namespace std;

class store {
    int i, code[23], count, cd, len;
    int quantity[23];
    string item[23], name;
    float p, price[23], total;
    long long int number;
    time_t tt;
    struct tm *ti;
	public:
    	store() {
    		len = 0;
        	count = 0;
        	p = 0.0;
        	total = 0.0;
    	}
    	int check(int c)
    	{
        	for (i = 0; i < count; i++)
            	if (c == code[i])
                	return i;
        	return -1;
    	}
    	void get_data()
    	{ 
        	cout << "\n\tName of Customer: ";
        	getline(cin, name);
        	cout << "\n\tMobile number: ";
        	cin >> number;
    	}
    	void inc_dec_count(int a)
    	{
        	if (a == 1)
            	count++;
        	else
            	count--;
    	}
    	void menu();
    	void insert();
    	void remove();
    	void cart();
    	void checkout();
};

void store::menu()
{
    cout << "\n\t----------------------------------MENU-----------------------------------";
    cout << "\n\t-------------------------------------------------------------------------";
    cout << "\n\t\tCode \t\t\t Item \t\t\t Price" << endl;
    cout << "\n\t\t101  \t\t Stationary Kit \t\t 300.00";
    cout << "\n\t\t102  \t\t Pencil \t\t\t 3.00";
    cout << "\n\t\t103  \t\t Eraser \t\t\t 5.00";
    cout << "\n\t\t104  \t\t Ball Pen \t\t\t 10.00";
    cout << "\n\t\t105  \t\t Ink Pen \t\t\t 30.00";
    cout << "\n\t\t106  \t\t Ink \t\t\t\t 20.00";
    cout << "\n\t\t107  \t\t Refill \t\t\t 8.00";
    cout << "\n\t\t108  \t\t Notebooks \t\t\t 70.00";
    cout << "\n\t\t109  \t\t A4 size notebooks \t\t 90.00";
    cout << "\n\t\t110  \t\t Chips \t\t\t\t 20.00";
    cout << "\n\t\t111  \t\t Kurkure \t\t\t 20.00";
    cout << "\n\t\t112  \t\t Toothbrush \t\t\t 20.00";
    cout << "\n\t\t113  \t\t Toothpaste \t\t\t 40.00";
    cout << "\n\t\t114  \t\t Bathing soap \t\t\t 30.00";
    cout << "\n\t\t115  \t\t Detergent \t\t\t 70.00";
    cout << "\n\t\t116  \t\t Kulfi \t\t\t\t 20.00";
    cout << "\n\t\t117  \t\t Coca Cola \t\t\t 50.00";
    cout << "\n\t\t118  \t\t Maggi \t\t\t\t 30.00";
    cout << "\n\t\t119  \t\t Basketball \t\t\t 500.00";
    cout << "\n\t\t120  \t\t Volleyball \t\t\t 400.00";
    cout << "\n\t\t121  \t\t Tennis ball \t\t\t 50.00";
    cout << "\n\t\t122  \t\t Badminton Shuttle Cock Box \t 250.00";
    cout << "\n\t\t123  \t\t Football \t\t\t 400.00";
    cout << "\n\t-------------------------------------------------------------------------" << endl;
}

void store::insert()
{
    cout << "\n\tEnter the code of the item: ";
    cin >> cd;
    switch (cd)
    {
    case 101:
        cout << "\n\t101    Stationary Kit  150.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 150.00 * quantity[count];
        code[count] = 101;
        item[count] = "Stationary Kit";
        price[count] = p;
        total = total + p;
        break;
    case 102:
        cout << "\n\t102    Pencil  3.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 3.00 * quantity[count];
        code[count] = 102;
        item[count] = "Pencil";
        price[count] = p;
        total = total + p;
        break;
    case 103:
        cout << "\n\t003    Eraser  5.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 5.00 * quantity[count];
        code[count] = 103;
        item[count] = "Eraser";
        price[count] = p;
        total = total + p;
        break;
    case 104:
        cout << "\n\t104    Ball Pen  10.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 10.00 * quantity[count];
        code[count] = 104;
        item[count] = "Ball pen";
        price[count] = p;
        total = total + p;
        break;
    case 105:
        cout << "\n\t105    Ink Pen  30.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 30.00 * quantity[count];
        code[count] = 105;
        item[count] = "Ink Pen";
        price[count] = p;
        total = total + p;
        break;
    case 106:
        cout << "\n\t106    Ink  20.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 20.00 * quantity[count];
        code[count] = 106;
        item[count] = "Ink";
        price[count] = p;
        total = total + p;
        break;
    case 107:
        cout << "\n\t107    Refill  8.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 8.00 * quantity[count];
        code[count] = 107;
        item[count] = "Ink Pen";
        price[count] = p;
        total = total + p;
        break;
    case 108:
        cout << "\n\t108    Notebooks  70.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 70.00 * quantity[count];
        code[count] = 108;
        item[count] = "Notebooks";
        price[count] = p;
        total = total + p;
        break;
    case 109:
        cout << "\n\t109    A4 size notebooks  90.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 90.00 * quantity[count];
        code[count] = 109;
        item[count] = "A4 size notebooks";
        price[count] = p;
        total = total + p;
        break;
    case 110:
        cout << "\n\t110    Chips  20.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 20.00 * quantity[count];
        code[count] = 110;
        item[count] = "Chips";
        price[count] = p;
        total = total + p;
        break;
    case 111:
        cout << "\n\t111    Kurkure  20.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 20.00 * quantity[count];
        code[count] = 111;
        item[count] = "Kurkure";
        price[count] = p;
        total = total + p;
        break;
    case 112:
        cout << "\n\t012    Toothbrush  20.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 20.00 * quantity[count];
        code[count] = 112;
        item[count] = "Toothbrush";
        price[count] = p;
        total = total + p;
        break;
    case 113:
        cout << "\n\t113    Toothpaste  40.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 40.00 * quantity[count];
        code[count] = 113;
        item[count] = "Toothpaste";
        price[count] = p;
        total = total + p;
        break;
    case 114:
        cout << "\n\t014    Bathing soap  30.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 30.00 * quantity[count];
        code[count] = 114;
        item[count] = "Bathing soap";
        price[count] = p;
        total = total + p;
        break;
    case 115:
        cout << "\n\t115    Detergent  70.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 70.00 * quantity[count];
        code[count] = 115;
        item[count] = "Detergent";
        price[count] = p;
        total = total + p;
        break;
    case 116:
        cout << "\n\t116    Kulfi  20.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 20.00 * quantity[count];
        code[count] = 116;
        item[count] = "Kulfi";
        price[count] = p;
        total = total + p;
        break;
    case 117:
        cout << "\n\t117    Coca Cola  50.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 50.00 * quantity[count];
        code[count] = 117;
        item[count] = "Coca Cola";
        price[count] = p;
        total = total + p;
        break;
    case 118:
        cout << "\n\t118    Maggi  30.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 30.00 * quantity[count];
        code[count] = 118;
        item[count] = "Maggi";
        price[count] = p;
        total = total + p;
        break;
    case 119:
        cout << "\n\t119    Basketball  500.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 500.00 * quantity[count];
        code[count] = 119;
        item[count] = "Basketball";
        price[count] = p;
        total = total + p;
        break;
    case 120:
        cout << "\n\t120    Volleyball  400.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 400.00 * quantity[count];
        code[count] = 120;
        item[count] = "Volleyball";
        price[count] = p;
        total = total + p;
        break;
    case 121:
        cout << "\n\t121    Tennis ball  50.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 50.00 * quantity[count];
        code[count] = 121;
        item[count] = "Tennis ball";
        price[count] = p;
        total = total + p;
        break;
    case 122:
        cout << "\n\t122    Badminton Shuttle cock box  250.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 250.00 * quantity[count];
        code[count] = 122;
        item[count] = "Badminton Shuttle cock box";
        price[count] = p;
        total = total + p;
        break;
    case 123:
        cout << "\n\t123    Football  400.00";
        cout << "\n\tEnter the quantity: ";
        cin >> quantity[count];
        p = 400.00 * quantity[count];
        code[count] = 123;
        item[count] = "Football";
        price[count] = p;
        total = total + p;
        break;
    default:
        cout << "\n\tWrong choice";
    }
}

void store::remove()
{
    int pos;
    cout << "\n\tEnter the code of the item you want to remove: ";
    cin >> cd;
    pos = check(cd);
    if (pos == -1)
        printf("\n\tThe item is not present in the cart");
    else
        total = total - price[pos];
    for (i = pos; i < count - 1; i++)
    {
        code[i] = code[i + 1];
        item[i] = item[i + 1];
        price[i] = price[i + 1];
    }
}

void store::cart()
{
    cout << "\n\t----------------------------------CART-----------------------------------";
    cout << "\n\t-------------------------------------------------------------------------";
    cout << "\n\t\tCode  \t\t\t Item \t\t\t Price\n";
    for (i = 0; i < count; i++) {
    	len = item[i].length();
    	if (len <= 6)
        	cout << "\n\t\t" << code[i] << "  \t\t " << item[i] << " \t\t\t " << price[i] << " \n\t\t\t Quantity -> " << quantity[i];
        else
        	cout << "\n\t\t" << code[i] << "  \t\t " << item[i] << " \t\t " << price[i] << " \n\t\t\t Quantity -> " << quantity[i];
    }
    cout << "\n\n\t\tAmount payable: " << total;
    cout << "\n\t-------------------------------------------------------------------------";
}

void store::checkout()
{
    time(&tt); // system time
    ti = localtime(&tt); // system time
    cout << asctime(ti); // system time
    cout << "\n\t----------------------------------BILL-----------------------------------";
    cout << "\n\n\t\t Name: " << name << " \t Mobile no: " << number;
    cout << "\n\n\t\t Date and time: " << asctime(ti);
    cout << "\n\t-------------------------------------------------------------------------";
    cout << "\n\t\tCode  \t\t\t Item \t\t\t Price\n";
    for (i = 0; i < count; i++) {
    	len = item[i].length();
    	if (len <= 6)
        	cout << "\n\t\t" << code[i] << "  \t\t " << item[i] << " \t\t\t " << price[i] << " \n\t\t\t Quantity -> " << quantity[i];
        else
        	cout << "\n\t\t" << code[i] << "  \t\t " << item[i] << " \t\t " << price[i] << " \n\t\t\t Quantity -> " << quantity[i];
    }
    cout << "\n\n\t\tAmount payable: " << total;
    cout << "\n\t-------------------------------------------------------------------------";
}

int main()
{
    store s;
    char c = 'y', ch;
    int choice, how_many;
    do {
        fflush(stdin);
        s.get_data();
        fflush(stdin);
        do {
            fflush(stdin);
            cout << "\n\n\t1. Insert elements to the cart";
            cout << "\n\t2. Remove elements from the cart";
            cout << "\n\t3. View the cart";
            cout << "\n\t4. Checkout and generate the bill";
            cout << "\n\tEnter the serial no of your choice: ";
            fflush(stdin);
            cin >> choice;
            switch (choice) {
                case 1:
                    s.menu();
                    cout << "\n\tHow many items do you want to insert: ";
                    fflush(stdin);
                    cin >> how_many;
                    for (int i = 0; i < how_many; i++) {
                        s.insert();
                        s.inc_dec_count(1);
                    }
                    s.cart();
                    break;
                case 2:
                    s.cart();
                    cout << "\n\tHow many items do you want to remove: ";
                    fflush(stdin);
                    cin >> how_many;
                    for (int i = 0; i < how_many; i++) {
                        s.remove();
                        s.inc_dec_count(0);
                    }
                    s.cart();
                    break;
                case 3:
                    s.cart();
                    break;
                case 4:
                    s.checkout();
                    c = 'n';
                    break;
                default:
                    cout << "\n\tWrong choice";
            }
            fflush(stdin);
        }while(c == 'y');
        cout << "\nDo you want to take a new customer(y/n): ";
        fflush(stdin);
        cin >> ch;
    }while(ch == 'y' || ch == 'Y');
    return 0;
}
