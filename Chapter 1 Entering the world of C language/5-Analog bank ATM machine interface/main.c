#include <stdio.h>

//Account Information Structure
struct account
{
	int account_num;	//account number
	int account_pwd;	//account password
	int account_balance;	//account balance
} user;				//global variable 'user'

//ATM account login function
int atm_login()
{
	int temp = 0;
	//Loop until the user to logs in successfully
	while (1)	
	{
		printf("Please enter you account:");
		scanf("%d", &temp);
		if (temp == user.account_num)
		{
			while (1)
			{
				printf("Please enter your password:");
				scanf("%d", &temp);
				if (temp == user.account_pwd)
				{
					printf("Login succeessfully!\n");
					return 1;
				}
				else
				{
					printf("Wrong password!Please try again!\n");
				}
			}
		}
		else
		{
			printf("No such account!Please try again!\n");
		}
	}
}

//print ATM menu
void atm_menu()
{
	printf("\n[1].Check balances\n");
	printf("[2].Withdraw money\n");
	printf("[3].Change password\n");
	printf("[4].Deposit\n");
	printf("[5].Exit\n");
}

//withdraw money function
void atm_withdraw()
{
	int amount = 0;
	while (1)
	{
		printf("PLease enter the withdraw amount:\n");
		scanf("%d", &amount);
		if (amount < user.account_balance)
		{
			user.account_balance -= amount;
			printf("The withdraw is successful,please accept your %d$", amount);
			return;
		}
		else
		{
			printf("Insufficient balance!Please enter again!\n");
		}
	}
}

//ATM change password function
void atm_modifyPwd()
{
	int temp = 0;
	printf("Please enter the original password:\n");
	scanf("%d", &temp);
	if (temp == user.account_pwd)
	{
		printf("Please enter the new password:\n");
		scanf("%d", &temp);
		printf("Enter again to confirm:\n");
		int again = 0;
		scanf("%d", &again);
		if (again == temp)
		{
			user.account_pwd = temp;
			printf("Changed!\n");
		}
		else
		{
			printf("The password entered twice are inconsistent!\n");
		}
	}
	else
	{
		printf("Wrong original password!\n");
	}
}

//deposit function
void atm_deposit()
{
	int temp = 0;
	printf("Please enter the deposit amount:\n");
	scanf("%d", &temp);
	if (temp > 0)
	{
		user.account_balance += temp;
		printf("Deposit successful!\n");
	}
	else
	{
		printf("Wrong amount!\n");
	}
}

//main function
int main()		
{
	user.account_num = 123456;
	user.account_pwd = 123456;
	user.account_balance = 10000;
	if (atm_login())
	{
		int user_choice = 0;
		while (1)
		{
			atm_menu();
			printf("I want to:");
			scanf("%d", &user_choice);
			switch (user_choice)
			{
				case 1:
					printf("Your balances is %d\n", user.account_balance);
					break;
				case 2:
					atm_withdraw();
					break;
				case 3:
					atm_modifyPwd();
					break;
				case 4:
					atm_deposit();
					break;
				case 5:
					printf("Bye!~\n");
					return 0;
					break;
				default:
					printf("Input error,please try again!\n");
					continue;
			}
		}
	}
	return 0;
}
