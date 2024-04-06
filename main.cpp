#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	char option;
	struct product
	{
		char name[24];
		float price;
		int qtd;
	};
	product products[4] = {
		{
			"Pastel",
			5.5
		},
		{
			"Bolo",
			6.0
		},
		{
			"Pizza",
			10.5
		},
		{
			"Suco",
			4.0
		}
	};

	product* my_products = new product[10];

	int count = 0;

	do {
		option = 'a';
		cout << "\nRapiZinho\n"
			<< "===========\n"
			<< "(A) Pastel\n"
			<< "(B) Bolo\n"
			<< "(C) Pizza\n"
			<< "(D) Suco\n"
			<< "(S) Sair\n"
			<< "===========\n"
			<< "Opção: [_]\b\b";
		cin >> option;
		option = tolower(option);
		char product_name[24];
		strcpy(product_name, products[option - 97].name);
		float product_price = products[option - 97].price;
		if (option >= 97 && option <= 100)
		{
			strcpy(my_products[count].name, product_name);
			my_products[count].price = product_price;

			cout << "\nPedido\n"
				<< "======\n"
				<< my_products[count].name << "\nR$"
				<< my_products[count].price << "\n"
				<< "======\n"
				<< "Quantidade: [_]\b\b";
			cin >> my_products[count].qtd;

			cout << "\nRapiZinho\n"
				<< "===========\n";
			for (int i = 0; i < count+1; i++) {
				cout << my_products[i].qtd << " x " << my_products[i].name << " de R$" << my_products[i].price << " = R$" << my_products[i].price * my_products[i].qtd << "\n";
			}
			cout << "===========\n";


			count++;
		}
	
	} while (option != 's');

	cout << "\nRapiZinho\n===========\n";
	float total = 6;
	for (int i = 0; i < count; i++)
	{
		total += my_products[i].price * my_products[i].qtd;
		cout << my_products[i].qtd << " x "
		<< my_products[i].name << " de R$"
		<< my_products[i].price << " = R$"
		<< my_products[i].price * my_products[i].qtd
		<< endl;
	}
	cout << "Taxa de entrega = R$6.00" << endl;
	cout << "===========\nTotal = R$" << total << endl;

	char pay;
	cout << "\n[P] Pix\n[C] Cartão\n\nPagamento: [p]\b\b";
	cin >> pay;
	cout << "\nRapiZinho\n===========\n";
	for (int i = 0; i < count; i++)
	{
		cout << my_products[i].qtd << " x "
			<< my_products[i].name << " de R$"
			<< my_products[i].price << " = R$"
			<< my_products[i].price * my_products[i].qtd
			<< endl;
	}
	cout << "Taxa de entrega = R$6.00" << endl;
	switch (pay) {
		case 'c': 
			cout << "Desconto de 5%" << endl;
			total *= 0.95;
			break;
		default:
			cout << "Desconto de 10%" << endl;
			total *= 0.9;
			break;
	}
	cout << "===========\nTotal = R$" << total << endl;
	cout << "\nConfirma Pedido (S/N): [s]\b\b";

	delete[] my_products;
}