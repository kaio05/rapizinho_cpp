#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
ofstream fout;

int main()
{
	struct product
	{
		char name[24];
		float price;
		int qtd;
	};
	int tam = 4;
	product* pedido = new product[tam];

	int count = 0;
	char option;
	do {
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
		float product_price;
		switch (option)
		{
			case 'a':
				strcpy(product_name, "Pastel");
				product_price = 5.5;
				break;
			case 'b':
				strcpy(product_name, "Bolo");
				product_price = 6.0;
				break;
			case 'c':
				strcpy(product_name, "Pizza");
				product_price = 10.5;
				break;
			case 'd':
				strcpy(product_name, "Suco");
				product_price = 4.0;
				break;
			case 's': break;
			default: cout << "OPÇÃO INVÁLIDA, TENTE NOVAMENTE";
		}
		if (option >= 97 && option <= 100)
		{
			unsigned int product_qtd;

			cout << "\nPedido\n"
				<< "======\n"
				<< product_name << "\nR$"
				<< product_price << "\n"
				<< "======\n"
				<< "Quantidade: [_]\b\b";
			cin >> product_qtd;
			for (int i = 0; i < count+1; i++)
			{
				if (i < count && count > 0 && !strcmp(pedido[i].name, product_name))
				{
					pedido[i].qtd += product_qtd;
				}
				else if (i == 0 || i < count) {
					strcpy(pedido[count].name, product_name);
					pedido[count].price = product_price;
					pedido[count].qtd = product_qtd;
					count++;
					break;
				}
			}

			cout << "\nRapiZinho\n"
				<< "===========\n";
			for (int i = 0; i < count; i++) {
				cout << pedido[i].qtd << " x " << pedido[i].name << " de R$" << pedido[i].price << " = R$" << pedido[i].price * pedido[i].qtd << "\n";
			}
			cout << "===========\n";
		}
	
	} while (option != 's');

	cout << "\nRapiZinho\n===========\n";
	float total = 6;
	for (int i = 0; i < count; i++)
	{
		total += pedido[i].price * pedido[i].qtd;
		cout << pedido[i].qtd << " x "
		<< pedido[i].name << " de R$"
		<< pedido[i].price << " = R$"
		<< pedido[i].price * pedido[i].qtd
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
		cout << pedido[i].qtd << " x "
			<< pedido[i].name << " de R$"
			<< pedido[i].price << " = R$"
			<< pedido[i].price * pedido[i].qtd
			<< endl;
	}
	cout << "Taxa de entrega = R$6.00" << endl;
	switch (pay) {
		case 'c': 
			cout << "Desconto de 5% = " << 0.05 * total << endl;
			cout << "===========\nTotal = R$" << total * 0.95 << endl;
			break;
		default:
			cout << "Desconto de 10% = " << 0.1 * total << endl;
			cout << "===========\nTotal = R$" << total * 0.9 << endl;
			break;
	}
	char confirm;
	cout << "\nConfirma Pedido (S/N): [s]\b\b";
	cin >> confirm;
	if (confirm == 's' || confirm == 'S')
	{
		fout.open("pedido.txt");
		fout << "Pedido #1"
			 << "\n--------------------------------------------------\n";
		for (int i = 0; i < count; i++)
		{
				fout << pedido[i].qtd << " x " << pedido[i].name 
					<< " de R$" << pedido[i].price << " = R$" 
					<< pedido[i].price * pedido[i].qtd << endl;
				
		}
		fout << "Taxa de entrega = R$6.00" << endl;
		switch (pay) {
		case 'c':
			fout << "Desconto de 5% = R$" << total * 0.05 << endl;
			fout << "--------------------------------------------------\n";
			fout << "Total = R$" << total * 0.95;
			break;
		default:
			fout << "Desconto de 10% = R$" << total * 0.1 << endl;
			fout << "--------------------------------------------------\n";
			fout << "Total = R$" << total * 0.9;
			break;
		}
		fout.close();
	}
	delete[] pedido;
}