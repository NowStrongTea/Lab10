#include <iostream>
#include <conio.h>

struct numberOfBanknotes
{
	int denomination;
	int amount;
};

// The function determines the number of each of the banknotes used for payout
void detTheNumOfBan(int n)
{
	numberOfBanknotes arrNumOfBan[7];
	//==================================================
	// Filling the array (number of banknotes)
	arrNumOfBan[0].denomination = 1;
	arrNumOfBan[0].amount = 0;
	for (int i = 1, j = 1; i < 7; i++)
	{
		arrNumOfBan[i].denomination = j *= 2;
		arrNumOfBan[i].amount = 0;
	}
	//==================================================
	// We determine the number of each of the banknotes used for payment
	int i = 6; // Array length numberOfBanknotes
	int tmp;
	while (n != 0)
	{
		tmp = n;
		tmp /= arrNumOfBan[i].denomination;
		arrNumOfBan[i].amount = tmp;
		tmp *= arrNumOfBan[i].denomination;
		n -= tmp;
		i--;
	}
	//==================================================
	// Display the number of banknotes used for payout to the console
	std::cout << "Denomination:\tamount:\n";
	for (int i = 0; i < 7; i++)
	{
		if (arrNumOfBan[i].amount != 0)
		{
			std::cout << arrNumOfBan[i].denomination << "\t\t";
			std::cout << arrNumOfBan[i].amount << '\n';
		}
	}
	//==================================================
}

int main()
{
	char exit = 'i';
	int n;
	while (exit != 'q')
	{
		std::cout << "Enter a natural number n: ";
		std::cin >> n;
		detTheNumOfBan(n);
		std::cout << "Press q to exit the program, press any other button to continue\n";
		exit = _getch();
		system("cls");
	}
	return 0;
}