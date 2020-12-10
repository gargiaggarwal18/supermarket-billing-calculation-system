#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

static int count=12;

void mainmenu()
{
	printf("-----------------------------------------------------------------------------------------\n");
	printf("\t\t\tMAIN MENU\n");
	printf("-------------------------------------------------------------------------------------\n\n\n");
	printf("1. ADMINISTRATOR\n");
	printf("2. CUSTOMER \n");
	printf("3. EXIT \n");
	printf("------------------------------------------------------------------------------------------\n");
}



void administrator()
{
	printf("-------------------------------------------------------------------------------------------\n");
	printf("\t\t\tADMINISTRATOR BLOCK\n");
	printf("-------------------------------------------------------------------------------------------\n\n\n");
	printf("1. To add a new product\n");
	printf("2. To delete an existing product\n");
	printf("3. To modify an existing product\n");
	printf("4. To display all products\n");
	printf("5. To display product menu\n");
	printf("6. Back to main menu\n");
	printf("----------------------------------------------------------------------------------------------\n");
}


 struct details
    {
        char name[50];
        float price;
        int code;
        int discount;
        int quantity;
    };
    struct details item[50];



//these items would always be available in our stock
void available()
{
	strcpy(item[0].name,"tea");
	item[0].code=121;
	item[0].price=10;
	item[0].discount=5;
	strcpy(item[1].name,"coffee");
	item[1].code=222;
	item[1].price=30;
	item[1].discount=5;
	strcpy(item[2].name,"ghee");
	item[2].code=141;
	item[2].price=200;
	item[2].discount=10;
	strcpy(item[3].name,"butter");
	item[3].code=289;
	item[3].price=250;
	item[3].discount=0;
	strcpy(item[4].name,"cream");
	item[4].code=186;
	item[4].price=400;
	item[4].discount=15;
	strcpy(item[5].name,"soap");
	item[5].code=132;
	item[5].price=50;
	item[5].discount=5;
	strcpy(item[6].name,"honey");
	item[6].code=189;
	item[6].price=100;
	item[6].discount=0;
	strcpy(item[7].name,"sugar");
	item[7].code=299;
	item[7].price=80;
	item[7].discount=5;
	strcpy(item[8].name,"pista");
	item[8].code=149;
	item[8].price=300;
	item[8].discount=10;
	strcpy(item[9].name,"oil");
	item[9].code=281;
	item[9].price=150;
	item[9].discount=2;
	strcpy(item[10].name,"besan");
	item[10].code=123;
	item[10].price=40;
	item[10].discount=0;
	strcpy(item[11].name,"sauce");
	item[11].code=743;
	item[11].price=70;
	item[11].discount=5;
	
}


void product_Menu(int count)
{
	int i;
	printf("-------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\tSUPERMARKET\n");
	printf("--------------------------------------------------------------------------------------------\n");
	printf("--------------------------------------------------------------------------------------------\n");
	printf("\tSR_NO. \t\t| CODE \t\t| ITEM \t\t\t| PRICE \t| DISCOUNT %%\n");
	printf("---------------------------------------------------------------------------------------------\n");
	available();
	for(i=0;i<count;i++)
	printf("\t %d\t\t %d\t\t %s\t\t\t %f\t\t %d\t\n",i+1,item[i].code,item[i].name,item[i].price,item[i].discount);
	printf("----------------------------------------------------------------------------------------------\n");
}


void add(int count)
{
	
	do
	{
		printf("Enter product name:");
		scanf("%s",&item[count-1].name);
		printf("Enter product code:");
		scanf("%d",&item[count-1].code);
		printf("Enter product price:");
		scanf("%f",&item[count-1].price);
		printf("Enter discount on the given product (if any):");
		scanf("%d",&item[count-1].discount);
		
		
	}
	while(0);
	
	printf("%s added to the market successfully!!\n",item[count-1].name);
	printf("Now the total number of products available in the market are: %d\n",count);
	
	//1000 is the total limit of items that can be stored in a supermarket.
	
}



void delete()
{
	int i; 
	int num;
	
	product_Menu(count);

	printf("Enter a serial number of the product you would like to delete:\n");
	scanf("%d",&num);
	
	if(num>count)
	{
		printf("SORRY!!\n THIS SERIAL NUMBER DOES NOT EXISTS!!\n");
	}
	else if(num<13){
		printf("SORRY!!\n THIS SERIAL NUMBER CAN'T BE DELETED!!'\n");
	}
	else
	{
		for(i=0;i<count;i++)
		{
		if(item[i].code==item[num-1].code)
		{
			int j;
			for(j=i;j<count-1;j++){
				item[i].code=item[i+1].code;
				strcpy(item[i].name,item[i+1].name);
				item[i].price=item[i+1].price;
				item[i].discount=item[i+1].discount;
			}
			count--;
		}
		else{
			continue;
		}
		break;
		}
		printf("Product deleted successfully!!\n");
	}

 
}



void modify()
{
	int mod;
	printf("Enter Serial number:");
	scanf("%d",&mod);
	
	if(mod>count)
	{
		printf("SORRY!!\n THIS SERIAL NUMBER DOES NOT EXISTS\n");
	}
	else
	{
			
	printf("----------------------------------------------------------------------------------\n");
	printf("----------------------------------------------------------------------------------\n");
	printf("Product name:%s\n",item[mod-1].name);
	printf("Product code:%d\n\n",item[mod-1].code);
	printf("Price:%f\n",item[mod-1].price);
	printf("Discount(if any?):%d\n",item[mod-1].discount);
	printf("----------------------------------------------------------------------------------\n");
	printf("----------------------------------------------------------------------------------\n\n\n");
	
	printf("-----------------------------------------------------------------------------------\n");
	printf("\t\tMODIFY DETAILS\n");
	printf("------------------------------------------------------------------------------------\n");
	printf("Enter product name:");
	scanf("%s",&item[mod-1].name);
	printf("Enter product code:");
	scanf("%d",&item[mod-1].code);
	printf("Enter price of product:");
	scanf("%f",&item[mod-1].price);
	printf("Enter discount (if any?):");
	scanf("%d",&item[mod-1].discount);
	printf("-------------------------------------------------------------------------------------\n");
	
	}

}


void display_All(int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		printf("Product code : %d\n",item[i].code);
		printf("Product name:%s\n\n",item[i].name);
		printf("Price:%f\n",item[i].price);
		printf("Discount(if any?):%d\n",item[i].discount);
		printf("-----------------------------------------------------------------------------------\n");
		printf("-----------------------------------------------------------------------------------\n\n");
	}
	
}



void ADMINISTRATOR()
{
	do
				
		{
			int admin;
			//static int count=0;
			administrator();
			printf("What you want to do?\n");
			scanf("%d",&admin);	
						
			switch(admin)
			{
				case 1:
					{
						count++;
						add(count);
						printf("Press any key to continue.......\n");
						getch();
						break;
					}
				case 2:
					{
						delete();
						printf("Press any key to continue.......\n");
						getch();
						break;
					}
				case 3:
					{
						modify();
						printf("Press any key to continue.........\n");
						getch();
						break;
					}
				case 4:
					{
						display_All(count);
						printf("Press any key to continue.........\n");
						getch();
						break;
					}
				case 5:
					{
						product_Menu(count);
						printf("Press any key to continue.........\n");
						getch();
						break;
					}
				case 6:
					{
						main();
						break;
					}
				default:
					{
						printf("ERROR!! Wrong choice\nPlease enter correct choice(1-6)\n");
						printf("Press any key to continue.......\n");
						getch();
					}
			}
			
		}
					
		while(1);
}







void costumer()
{
	char status;
	static int flag=0;
	static int i=0;
	int code[1000],num;
	
	printf("------------------------------------------------------------------------------------------\n");
	printf("\t\tWELCOME TO OUR SUPERMARKET\n");
	printf("-------------------------------------------------------------------------------------------\n");
	printf("what do you want to buy?\n\n");
	
	
	product_Menu(count);
	
	printf("Place your order please!!\n\n");
	
	printf("---------------------------------------------------------------------------------------------\n");
	do
	{
		printf("Enter product sr no.:");
		scanf("%d",&code[i]);
		num=code[i];
		printf("Enter quantity:");
		scanf("%d",&item[num].quantity);
		printf("--------------------------------------------------------------------------------------------\n");
		i++;
		flag++;
		printf("do you want to buy more products(Y/N)?:");
		scanf("%s",&status);
		
	}
	while(status!='N');
	int number;
	float grand_total=0,total_price[1000],final_price[1000];
	
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\tBILL DETAILS\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\tSR_NO. \t\t| CODE \t\t| ITEM \t\t| PRICE \t| QUANTITY \t| DISCOUNT %% \t| TOTAL PRICE\t\n");
	printf("----------------------------------------------------------------------------------------------------------------------------------\n\n\n");

	for(i=0;i<flag;i++)
	{
		number=code[i];
		total_price[i]=(item[number-1].price*item[number].quantity);
		final_price[i]=total_price[i]-(total_price[i]*(((float)item[number-1].discount)/100));
		printf("\t%d \t\t %d\t\t %s\t\t %f\t\t %d\t\t %d\t\t %f\t\n",number,item[number-1].code,item[number-1].name,item[number-1].price,item[number].quantity,item[number-1].discount,final_price[i]);
		grand_total+=final_price[i];
	}
	
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\tGRAND TOTAL-%f\n",grand_total);
	printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
	
	
}


int main()
{
	int choice;
	
	do
	{
		mainmenu();
		printf("Are you a administrator or customer here?\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				{
					ADMINISTRATOR();
					
					printf("Press any key to continue.......\n");
					getch();
					break;
				}
			case 2:
				{
					costumer();
					printf("Press any key to continue.......\n");
					getch();
					break;
				}
			case 3:
				{
					exit(1);
				}
			default:
			   {
					printf("ERROR!! wrong option!!\n Please enter correct option(1-3)\n");
					printf("Press any key to continue\n");
					getch();
				}
		}
	}
	while(1);
	
	
	return 0;
}

