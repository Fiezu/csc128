#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>

using namespace std;

char Choose_Packages();                                             // All of these are function declaration
void SmartphoneSpecification();                                       
void Receipt_Payment(char, char[], float, char[], char[],float&);
void PaymentMethod(char);

int main()
{
	int countCustomer,Total,Counter;
	char Packages,TypesOfSmartphone,TypeReceipt[20],TypeReceipt2[20],displayPackage[35],morePackage,Answer;
	float Price1,Price,TotalLatest,displayTotal;
	
	displayTotal=0.00;
	countCustomer=0;
	
	do
	{
		
		cout<<"WELCOME TO SMART SHOP 2.0"<<endl;
		Total=0;
		
		do
		{
			Packages=Choose_Packages();
			if(Packages=='A' || Packages=='a')
			{
				Counter=0;
				SmartphoneSpecification();
				
				while(Counter<=1)
				{
					cout<<"Choose type of smartphones [A-Samsung S8, B-Samsung J7, C-iPhone 8, D-iPhone 6, E-Oppo R9s, F-Oppo A37]: ";
					cin>>ws;
					cin>>TypesOfSmartphone;
					cout<<endl;
					
					if(TypesOfSmartphone=='A' || TypesOfSmartphone=='a')
					{
						Price1=3389.00;
						if(Counter==0)
						{
							strcpy(TypeReceipt,"Samsung Galaxy S8");
						}
						else
						{
							strcpy(TypeReceipt2,"Samsung Galaxy S8");
						}
					}
					else if(TypesOfSmartphone=='B' || TypesOfSmartphone=='b')
					{
						Price1=1089.00;
						if(Counter==0)
						{
							strcpy(TypeReceipt,"Samsung Galaxy J7");
						}
						else
						{
							strcpy(TypeReceipt2,"Samsung Galaxy J7");
						}
					}
					else if(TypesOfSmartphone=='C' || TypesOfSmartphone=='c')
					{
						Price1=3389.00;
						if(Counter==0)
						{
							strcpy(TypeReceipt,"iPhone 8");
						}
						else
						{
							strcpy(TypeReceipt2,"iPhone 8");
						}
					}
					else if(TypesOfSmartphone=='D' || TypesOfSmartphone=='d')
					{
						Price1=1389.00;
						if(Counter==0)
						{
							strcpy(TypeReceipt,"iPhone 6");
						}
						else
						{
							strcpy(TypeReceipt2,"iPhone 6");
						}
					}
					else if(TypesOfSmartphone=='E' || TypesOfSmartphone=='e')
					{
						Price1=2989.00;
						if(Counter==0)
						{
							strcpy(TypeReceipt,"Oppo R9s");
						}
						else
						{
							strcpy(TypeReceipt2,"Oppo R9s");
						}
					}
					else if(TypesOfSmartphone=='F' || TypesOfSmartphone=='f')
					{
						Price1=689.00;
						if(Counter==0)
						{
							strcpy(TypeReceipt,"Oppo A37");
						}
						else
						{
							strcpy(TypeReceipt2,"Oppo A37");
						}
					}
					else
					{
						cout<<"Wrong code!"<<endl;
						strcpy(displayPackage,"None");
						
						if(Counter==0 || Counter==1)
						{
							strcpy(TypeReceipt,"None");
							strcpy(TypeReceipt2,"None");
							Total=0.00;
							break;                        //is used as an immediate exit from the selection
						}
							
					}
					
					Total=Total + Price1;
					
					if(Counter==0)
					{
						cout<<"Choose your second smartphone: "<<endl;
					}
					
					
					Counter=Counter+1;
				}
					
				cout<<"\nYour first smartphone is "<<TypeReceipt<<" and second smartphone is "<<TypeReceipt2<<endl;
				Price=Total*0.9;
			}
			else if(Packages=='C' || Packages=='c')
			{
				SmartphoneSpecification();
				
				do
				{
					cout<<"Choose type of smartphones [A-Samsung S8, B-Samsung J7, C-iPhone 8, D-iPhone 6, E-Oppo R9s, F-Oppo A37]: ";
					cin>>ws;
					cin>>TypesOfSmartphone;
					cout<<endl;
					
					if(TypesOfSmartphone=='A' || TypesOfSmartphone=='a')
					{
						Price=3299.00;
						strcpy(displayPackage,"Samsung Galaxy S8");
					}
					else if(TypesOfSmartphone=='B' || TypesOfSmartphone=='b')
					{
						Price=999.00;
						strcpy(displayPackage,"Samsung Galaxy J7");
					}
					else if(TypesOfSmartphone=='C' || TypesOfSmartphone=='c')
					{
						Price=3299.00;
						strcpy(displayPackage,"iPhone 8");
					}
					else if(TypesOfSmartphone=='D' || TypesOfSmartphone=='d')
					{
						Price=1299.00;
						strcpy(displayPackage,"iPhone 6");
					}
					else if(TypesOfSmartphone=='E' || TypesOfSmartphone=='e')
					{
						Price=2899.00;
						strcpy(displayPackage,"Oppo R9s");
					}
					else if(TypesOfSmartphone=='F' || TypesOfSmartphone=='f')
					{
						Price=599.00;
						strcpy(displayPackage,"Oppo A37");
					}
					else
					{
						cout<<"Wrong code!"<<endl;
						strcpy(displayPackage,"None");
						Price=0.00;
					}
				}
				while (TypesOfSmartphone=='A' && TypesOfSmartphone=='a'&& TypesOfSmartphone=='B' && TypesOfSmartphone=='b' && TypesOfSmartphone=='C' && TypesOfSmartphone=='c' && TypesOfSmartphone=='D' && TypesOfSmartphone=='d' && TypesOfSmartphone=='E' && TypesOfSmartphone=='e' && TypesOfSmartphone=='F' && TypesOfSmartphone=='f');
			}
			else
			{
				cout<<"Wrong code!"<<endl;
				strcpy(displayPackage,"None");
			}
			Receipt_Payment(Packages,displayPackage,Price,TypeReceipt,TypeReceipt2,TotalLatest);   // The function call can be either list the parameters or leave it blank
			cout<<"Buy more package? [Y/N]: ";
			cin>>ws;
			cin>>morePackage;
		}
		while(morePackage=='Y' || morePackage=='y');
		
		PaymentMethod(morePackage);
		cout<<setprecision(2)<<fixed;                //setprecision(2)<<fixed is to manipulate the output into 2 decimal places
		cout<<"Final price: RM"<<TotalLatest<<endl;
		cout<<"\nDo you want to enter another visitor? [Y/N]: ";
		cin>>ws;
		cin>>Answer;
		cout<<endl;
		
		displayTotal=displayTotal + TotalLatest;
		countCustomer=countCustomer + 1;
	}
	while(Answer=='Y' || Answer=='y');
	
	cout<<"\nYOUR TOTAL CUSTOMER: "<<countCustomer<<endl;
	cout<<"TOTAL PAYMENT RECEIVED : RM"<<displayTotal<<endl;
	cout<<"The average of income per customer is : RM"<<displayTotal/countCustomer;
	
	getch();
	return 0;
}

char Choose_Packages()                                              // Function definition must be used to call the calling module
{                                                                                                
	char Packages_;
	
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"| Packages |                       Details                           |"<<endl;
	cout<<"|          |>Buy 2 smartphones, a screen protector privacy worth RM60|"<<endl;
	cout<<"|     A    |>A phone casing worth RM30 for each smartphone           |"<<endl;
	cout<<"|          |>10% less from the total price and get a 10000 mAh       |"<<endl;
	cout<<"|          | powerbank worth RM65                                    |"<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"|     C    |>Buy 1 smartphone and get a screen protector worth RM50  |"<<endl;
	cout<<"|          |>A phone casing worth RM30 as a free gift                |"<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
	
	cout<<"Please choose your packages [A/C]: ";
	cin>>Packages_;
	cout<<endl;
	
	return Packages_;
}

void SmartphoneSpecification()
{
	cout<<"\n--------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|    Smartphone     |                    Specifications                      | Package A(RM) | Package C(RM) |"<<endl;
	cout<<"|------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| Samsung Galaxy S8 | RM3299, 5.8 inch, 4GB RAM, 12MP f/1.7,3000 mAh, 64GB   |     3389.00   |     3299.00   |"<<endl;
	cout<<"| Samsung Galaxy J7 | RM999, 5.5 inch, 3GB RAM, 13MP f/1.7, 3600 mAh, 16GB   |     1089.00   |      999.00   |"<<endl;
	cout<<"|     iPhone 8      | RM3299, 4.7 inch, 3GB RAM, 12MP f/1.8, 1821 mAh, 64GB  |     3389.00   |     3299.00   |"<<endl;
	cout<<"|     iPhone 6      | RM1299, 4.7 inch, 1GB RAM, 8MP f/2.2, 1810 mAh, 16GB   |     1389.00   |     1299.00   |"<<endl;
	cout<<"|     Oppo R9s      | RM2899, 5.5 inch, 4GB RAM, 16MP  f/1.7, 3010 mAh, 64GB |     2989.00   |     2899.00   |"<<endl;
	cout<<"|     Oppo A37      | RM599, 5.0 inch, 2GB RAM, 8MP f/2.0, 2630 mAh, 16GB    |      689.00   |      599.00   |"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\n";
}

void Receipt_Payment(char Packages1, char displayPackage1[20], float price,char TypeReceipt_[20],char TypeReceipt2_[20],float& Total_Latest)
{
	
	cout<<"*********************************************************************"<<endl;
	cout<<"Your package: "<<Packages1<<endl;
	
	if(Packages1=='A' || Packages1=='a')
	{
		cout<<"Your first phone is "<<TypeReceipt_<<endl;
		cout<<"Second phone is "<<TypeReceipt2_<<endl;
	}
	else
	{
		cout<<"Your smartphone: "<<displayPackage1<<endl;
	}
	
	cout<<setprecision(2)<<fixed;
	Total_Latest=Total_Latest + price;
	cout<<"Your total is : RM"<<Total_Latest<<endl;
	cout<<"*********************************************************************"<<endl;
}

void PaymentMethod(char answer)
{
	char Payment, Name[30],Address[50],Information;
	
	if(answer=='n' || answer=='N')
	{
		cout<<endl<<"\nPAYMENT METHOD"<<endl;
		cout<<"*Free Delivery Service in Peninsular Malaysia and Sabah Sarawak*"<<endl;
	
		do
		{
			cout<<"Please choose payment method[A-CashOnDelivery,B-BankIn] :";
			cin>>ws;
			cin>>Payment;
			cout<<endl;
		
			if(Payment=='A' || Payment=='a')
			{
				cout<<"Meet at Segamat"<<endl;
				cout<<"1 Shopping Complex, First Floor, Jalan Kolam Air, Kampung Gubah, 85000 Segamat District, Johor, Malaysia"<<endl;
				cout<<"From 9.00a.m.-11.00a.m"<<endl;
				cout<<"For further information please contact 012-281 3154(Aqil)"<<endl;
			}
			else if(Payment=='B' || Payment=='b')
			{
				cout<<"Please bank in at 12-256-10-045316-0(Bank Islam)"<<endl;
				cout<<"Please type in your name: ";
				cin>>ws;
				cin.getline(Name,30);
				cout<<endl;
			
				do
				{
					cout<<"Please type in your shipping address: ";
					cin>>ws;
					cin.getline(Address,50);
					cout<<endl;
					
					cout<<"************************************************"<<endl;
					cout<<"Your name: "<<Name<<endl;
					cout<<"Please check and confirm your address: "<<Address<<endl;
					cout<<"************************************************"<<endl;
					cout<<"Your information is correct? [Y/N]: ";
					cin>>ws;
					cin>>Information;
					cout<<endl;
				}
				while(Information=='N' || Information=='n');
			}
			else
			{
				cout<<"Wrong code!"<<endl;
			}
		}	
		while(Payment=='A'&&Payment=='a'&&Payment=='B'&&Payment=='b');
	}
	else
	{
		cout<<"Wrong code!"<<endl;
	}
	
	
}
