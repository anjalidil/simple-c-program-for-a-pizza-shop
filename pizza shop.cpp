#include<iostream>
#include<fstream>
#include<windows.h>

using namespace std;
class order
{
	public:
	int menuType, quantity, orderCount;
	static int error; 
	double price;
	char size;
	void pizzaKitchen()
	{
		cout << "\n\t\t\t\t\t\t\t\t\t   PIZZA KITCHEN\n\t\t\t\t\t\t\t\t\t  ===============\n\t\t\t\t\t\t\t\t\tNo:3,peradeniya road,\n\t\t\t\t\t\t\t\t\tKandy.\n\t\t\t\t\t\t\t\t\t081-2300678\n\n\n";
	}
	void userInput()
	{
		cout << "\t\t\tMenu\n\t\t\t~~~~~\n\t\t\t1: Hot butter cuttlefish pizza\t\t\t4: Tandoori chicken pizza\n\t\t\t\t\ti)Small: 1500.00\t\t\t\ti)Small: 1200.00\n\t\t\t\t\tii)Medium: 2000.00\t\t\t\tii)Medium: 1800.00\n\t\t\t\t\tiii)Large: 2500.00\t\t\t\tiii)Large: 2200.00\n\n\t\t\t2: Sausage delight pizza\t\t\t5: Spicy vegie pizza\n\t\t\t\t\ti)Small: 1000.00\t\t\t\ti)Small: 800.00\n\t\t\t\t\tii)Medium: 1500.00\t\t\t\tii)Medium: 1100.00\n\t\t\t\t\tiii)Large: 2000.00\t\t\t\tiii)Large: 1500.00\n\t\t\t3: Seafood pizza\t\t\t\t****3 or more : \n\t\t\t\t\ti)Small: 1500.00\t\t\t\t15 percent Discount for Large pizza\n\t\t\t\t\tii)Medium: 2000.00\t\t\t\t10 percent Discount for Medium pizza\n\t\t\t\t\tiii)Large: 2500.00\t\t\t\t5 percent Discount for Small pizza\n\n\t\t\tDesserts\n\t\t\t~~~~~~~~~\n\t\t\t6: Chocolate lava cake : 250.00\n\t\t\t7: Chocolate milkshake : 200.00\n\t\t\t8: Vanilla milkshake : 150.00\n";
		cout << "\t\t\t0: Exit\n\n";

		cout << " Order number "<<orderCount<<"\n ~~~~~~~~~~~~~~\n";
		//prompting user to input details
		cout << "Enter menu code: ";  cin >> menuType;

		//error handling
		if (!(menuType == 1 || menuType == 2 || menuType == 3 || menuType == 4 || menuType == 5 || menuType == 6 || menuType == 7 || menuType == 8 || menuType == 0))
		{
			cout << "\nINVALID MENU CODE!please try again.\n\n";
			error = 1;
		} else {
			if (!(menuType == 0 || menuType == 6 || menuType == 7 || menuType == 8))
			{
				cout << "Enter size(S/M/L): ";  cin >> size;
				
				//error handling
				if (!(size == 's' || size == 'S' || size == 'M' || size == 'm' || size == 'l' || size == 'L'))
				{
					cout << "\nINVALID SIZE!please try again.\n\n";
					error = 1;	
				}
			}
			if (menuType != 0) {
				cout << "Enter the quantity: "; 	cin >> quantity;
			}	
		}	
	}
	virtual float calUPrice()=0;
};
int order::error=0; //0 for no errors, 1 for errors

class foodPrice : public order
{
	protected:
	float calUPrice()
	{

		if (menuType == 1)
		{
			if (size == 's' || size == 'S')
			{
				price = quantity * 1500.00;
			}
			if (size == 'm' || size == 'M')
			{
				price = quantity * 2000.00;
			}
			if (size == 'l' || size == 'L')
			{
				price = quantity * 2500.00;
			}
		}
		if (menuType == 2)
		{
			if (size == 's' || size == 'S')
			{
				price = quantity * 1000.00;
			}
			if (size == 'm' || size == 'M')
			{
				price = quantity * 1500.00;
			}
			if (size == 'l' || size == 'L')
			{
				price = quantity * 2000.00;
			}
		}
		if (menuType == 3)
		{
			if (size == 's' || size == 'S')
			{
				price = quantity * 1500.00;
			}
			if (size == 'm' || size == 'M')
			{
				price = quantity * 2000.00;
			}
			if (size == 'l' || size == 'L')
			{
				price = quantity * 2500.00;
			}
		}
		if (menuType == 4)
		{
			if (size == 's' || size == 'S')
			{
				price = quantity * 1200.00;
			}
			if (size == 'm' || size == 'M')
			{
				price = quantity * 1800.00;
			}
			if (size == 'l' || size == 'L')
			{
				price = quantity * 2200.00;
			}
		}
		if (menuType == 5)
		{
			if (size == 's' || size == 'S')
			{
				price = quantity * 800.00;
			}
			if (size == 'm' || size == 'M')
			{
				price = quantity * 1100.00;
			}
			if (size == 'l' || size == 'L')
			{
				price = quantity * 1500.00;
			}
		}
		if (menuType == 6)
		{
			price = quantity * 250.00;
		}
		if (menuType == 7)
		{
			price = quantity * 200.00;
		}
		if (menuType == 8)
		{
			price = quantity * 150.00;
		}
		return price;
	}

};
class discount : public foodPrice
{
	public:
	double sr, mr, lr, netPrice, discountPrice , totalPrice;

	void calDiscount(double a, double b, double c)
	{
		sr = a;
		mr = b;
		lr = c;
		//unit charge for current order
		if (menuType == 1 || menuType == 2 || menuType == 3 || menuType == 4 || menuType == 5)
		{
			if (quantity >= 3)
			{
				if (size == 's' || size == 'S')
				{
					discountPrice = calUPrice() * sr;
					netPrice = calUPrice() - discountPrice;
				}
				if (size == 'm' ||  size == 'M')
				{
					discountPrice = calUPrice() * mr;
					netPrice = calUPrice() - discountPrice;
				}
				if (size == 'l' || size ==  'l')
				{
					discountPrice = calUPrice() * lr;
					netPrice = calUPrice() - discountPrice;
				}
			}
			else
			{
				discountPrice = 0.00;
				netPrice = calUPrice();
			}
		}
		else
		{
			discountPrice = 0.00;
			netPrice = calUPrice();
		}

	}
};
class netTotal : public discount
{
	public:
	void orderIncome()
	{

		totalPrice += netPrice;


		cout << "\n Price:" << price << "LKR\n Discount: " << discountPrice << "LKR\n";
		cout << " Net price for the order: " << netPrice << "LKR\n\n";
		
	}
	void writeData()
	{
		ofstream outf;
		outf.open("bill.txt",ios::app);
		
		outf<<orderCount<<endl;
		outf<<menuType<<endl;
		outf<<size<<endl;
		outf<<quantity<<endl;
		outf<<price<<endl;
		outf<<discountPrice<<endl;
		outf<<netPrice<<endl<<endl;
		
		outf.close();
		
	}
	void writeIncome()
	{
		ofstream outf;
		outf.open("INCOME.txt");
		
		outf<<orderCount<<endl;
		outf<<totalPrice<<endl;
		
		outf.close();
	}
	void display()
	{
		ifstream inf;
		inf.open("INCOME.txt");
		
		while(inf)
		{
			inf>>orderCount;
			inf>>totalPrice;
		}
		//displaying count and income of the day
		cout << "\n  Total order count: " <<orderCount-1<< "\n\n";
		cout << "*********************************  TOTAL INCOME: " << totalPrice << "LKR  **********************************\n\n";
	}

};
int main()
{

	netTotal b;
	b.pizzaKitchen();
	b.orderCount = 1;
	while (b.menuType != 0) //using ...while loop
	{
		b.error = 0;
		b.userInput();
		if (b.error == 1) {
			Sleep(500);//another comes after 0.5 seconds
   			system("cls");//clears the screen
			continue;
			
		}

		if (b.menuType != 0)
		{
			b.orderCount++;
			b.calDiscount(0.05, 0.1, 0.15);
			b.orderIncome();
			b.writeData();
			Sleep(4500);//after printing one . another comes after 4.5 seconds
			system("cls");//clears the screen
		}		
	} 
	Sleep(1500);//after printing one . another comes after 1.5 seconds
	system("cls");//clears the screen
    b.writeIncome();
	b.display();

	return 0;

}
