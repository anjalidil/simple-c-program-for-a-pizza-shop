#include<stdio.h>
void inputData();
int calUPrice (int,char,int);
int calDiscount(int,char,int);
void disData(int);
int discountPrice,totalPrice;

int main()
{
	printf("\n\t\t\t\t\t\t\t\t\t   PIZZA KITCHEN\n\t\t\t\t\t\t\t\t\t  ===============\n\t\t\t\t\t\t\t\t\tNo:3,peradeniya road,\n\t\t\t\t\t\t\t\t\tKandy.\n\t\t\t\t\t\t\t\t\t081-2300678\n\n\n");
	inputData();
	return 0;
}
void inputData()
{
	int menuType,quantity,c;
	char size;
	
	for(c=1; menuType!=0;)//using for loop
	{
		printf("\t\t\tMenu\n\t\t\t~~~~~\n\t\t\t1: Hot butter cuttlefish pizza\t\t\t4: Tandoori chicken pizza\n\t\t\t\t\ti)Small: 1500.00\t\t\t\ti)Small: 1200.00\n\t\t\t\t\tii)Medium: 2000.00\t\t\t\tii)Medium: 1800.00\n\t\t\t\t\tiii)Large: 2500.00\t\t\t\tiii)Large: 2200.00\n\n\t\t\t2: Sausage delight pizza\t\t\t5: Spicy vegie pizza\n\t\t\t\t\ti)Small: 1000.00\t\t\t\ti)Small: 800.00\n\t\t\t\t\tii)Medium: 1500.00\t\t\t\tii)Medium: 1100.00\n\t\t\t\t\tiii)Large: 2000.00\t\t\t\tiii)Large: 1500.00\n\t\t\t3: Seafood pizza\t\t\t\t****3 or more : \n\t\t\t\t\ti)Small: 1500.00\t\t\t\t15 percent Discount for Large pizza\n\t\t\t\t\tii)Medium: 2000.00\t\t\t\t10 percent Discount for Medium pizza\n\t\t\t\t\tiii)Large: 2500.00\t\t\t\t5 percent Discount for Small pizza\n\n\t\t\tDesserts\n\t\t\t~~~~~~~~~\n\t\t\t6: Chocolate lava cake : 250.00\n\t\t\t7: Chocolate milkshake : 200.00\n\t\t\t8: Vanilla milkshake : 150.00\n");
		printf("\t\t\t0: Exit\n\n");
		
		printf(" Order number %d\n ~~~~~~~~~~~~~~\n",c);
		
		//promting user to input details
		printf("Enter menu code: ");
		scanf("%d",&menuType);
		//error handling
		if(!( menuType == 1 || menuType == 2 || menuType == 3 || menuType == 4 || menuType == 5 || menuType == 6 || menuType == 7 || menuType == 8))
		{
			printf("\nINVALID MENU CODE!please try again.\n\n");
			continue;
		}
		if(!(menuType == 6 || menuType == 7 || menuType == 8))
		{
			printf("Enter size(S/M/L): ");
			scanf(" %c",&size);
			//error handling
			if(!(size == 's' || size == 'S' || size == 'm' || size == 'M' || size == 'l' || size == 'L'))
			{
				printf("\nINVALID SIZE!please try again.\n\n");
			    continue;
			}
		}
		printf("Enter the quantity: ");
		scanf("%d",&quantity);
		c++;
		
		//calculating total income
		totalPrice += calDiscount(menuType,size,quantity);
		printf("\n Price: %d.00LKR\n Discount: %d.00LKR\n",calUPrice(menuType,size,quantity),discountPrice);
		printf(" Net price for the order: %d.00LKR\n\n",calDiscount(menuType,size,quantity));
	}
	disData(c);
}

int calUPrice(int menuType, char size, int quantity)
{
	int price;
	if(menuType == 1)
	{
		if(size == 's' || size == 'S')
		{
			price= quantity*1500.00;
		}
		if(size == 'm' || size == 'M')
		{
			price= quantity*2000.00;
		}	
		if(size == 'l' || size == 'L')
		{
			price= quantity*2500.00;
		}		
	}
	if(menuType == 2)
	{
		if(size == 's' || size == 'S')
		{
		    price= quantity*1000.00;
		}
		if(size == 'm' || size == 'M')
		{
			price= quantity*1500.00;
		}	
		if(size == 'l' || size == 'L')
		{
            price= quantity*2000.00;
		}		
	}
	if(menuType == 3)
	{
		if(size == 's' || size == 'S')
		{
		    price= quantity*1500.00;
		}
		if(size == 'm' || size == 'M')
		{
			price= quantity*2000.00;
		}	
		if(size == 'l' || size == 'L')
		{
            price= quantity*2500.00;
		}	
	}
	if(menuType == 4)
	{
		if(size == 's' || size == 'S')
		{
		    price= quantity*1200.00;
		}
		if(size == 'm' || size == 'M')
		{
			price= quantity*1800.00;
		}	
		if(size == 'l' || size == 'L')
		{
            price= quantity*2200.00;
		}	
	}
	if(menuType == 5)
	{
	    if(size == 's' || size == 'S')
		{
		    price= quantity*800.00;
		}
		if(size == 'm' || size == 'M')
		{
			price= quantity*1100.00;
		}	
		if(size == 'l' || size == 'L')
		{
            price= quantity*1500.00;
		}	
	}
	if(menuType == 6)
	{
		price=quantity*250.00;
	}
	if(menuType == 7)
	{
		price=quantity*200.00;
	}
	if(menuType == 8)
	{
		price=quantity*150.00;
	}
	return price;
}
int calDiscount(int menuType, char size, int quantity)
{
	int netPrice;
	
	//unit charge for current order
	if(menuType == 1 || menuType == 2 || menuType == 3 || menuType == 4 || menuType == 5)
	{
      if(quantity >=3)
	  {
		if( size == 's' || size == 'S')
	    {
	    	discountPrice=calUPrice(menuType,size,quantity)*5/100;
	    	netPrice = calUPrice(menuType,size,quantity) - discountPrice;
    	}
		if( size == 'm' || size == 'M')
	    {
    	    discountPrice=calUPrice(menuType,size,quantity)*10/100;
    	    netPrice = calUPrice(menuType,size,quantity) - discountPrice;
        }
		if( size == 'l' || size == 'L')
	    {
	    	discountPrice=calUPrice(menuType,size,quantity)*15/100;
	    	netPrice = calUPrice(menuType,size,quantity) - discountPrice;
        }
	  }
	  else
	  {
	  	discountPrice= 0.00;
  		netPrice = calUPrice(menuType,size,quantity);
   	  }
	}
	else
	{
		discountPrice= 0.00;
		netPrice = calUPrice(menuType,size,quantity);
	}
	return netPrice;
}
void disData(int c)
{

	//displaying count and income of the day
	printf("\n  Total order count: %d\n\n",--c);
	printf("*********************************  TOTAL INCOME: %d.00LKR  **********************************\n\n",totalPrice);
	
}