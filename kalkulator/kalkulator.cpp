#include <iostream> 
#include <string>
using namespace std;
void parser(string primer,string*fin_prim);
string* resh(string* fin_prim,int &razm);
int main()
{
	setlocale(LC_ALL, "Rus");
	string primer;
	double temp;
	cout << "Введите пример\n";
	cin >> primer;
	int razm = primer.length();
	string* fin_prim = new string[razm];
	parser(primer,fin_prim);
	while (razm > 1)
	{
		fin_prim= resh(fin_prim, razm);
		if (fin_prim == 0)
		{
			break;
		}
	}
	if (razm == 1)
	{
		cout << fin_prim[0];
	}
	else
	{
		cout << "\nНа 0 делить нельзя!;\n";
	}
}
void parser(string primer,string *fin_prim)
{
	string buf;
	for (int i = 0;i < primer.length();i++)
	{
		if (primer.at(i) >= '0' && primer.at(i) <= '9')
		{
			buf.push_back(primer.at(i));
		}
		else if (primer.at(i) != '\0')
		{
			if (primer.at(i) == '+')
			{
				fin_prim[i - 1] = buf;
				fin_prim[i] = '+';
			}
			else if (primer.at(i) == '-')
			{
				fin_prim[i - 1] = buf;
				fin_prim[i] = '-';
			}
			else if (primer.at(i) == '*')
			{
				fin_prim[i - 1] = buf;
				fin_prim[i] = '*';
			}
			else if (primer.at(i) == '/')
			{
				fin_prim[i - 1] = buf;
				fin_prim[i] = '/';
			}
			buf = "";
		}
	}
	fin_prim[primer.length()-1] = buf;
}
string *resh(string* fin_prim,int &razm)
{
	int a = 0;
	int count =0;
	for (int i = 0; i < razm; i++)
	{
		if (fin_prim[i] == "*")
		{
			int key = i;
			a = stoi(fin_prim[i - 1]) * stoi(fin_prim[i + 1]);
			string* temp_prim = new string[razm];
			for (int j = 0; j < razm; j++)
			{
				if (j == key - 1 || j == key || j == key + 1)
				{

				}
				else
				{
					temp_prim[count] = fin_prim[j];
					count++;
				}
			}
			delete[]fin_prim;
			razm = razm - 2;
			fin_prim = new string[razm];
			int counter = 0;
			for (int j = 0; j < razm; j++)
			{
				if (key - 1 == j)
				{
					fin_prim[j] = to_string(a);
				}
				else
				{
					fin_prim[j] = temp_prim[counter];
					counter++;
				}
			}
			return fin_prim;
		}
	}
	for (int i = 0; i < razm; i++)
	{
		if (fin_prim[i] == "/")
		{
			if (fin_prim[i + 1] == "0")
			{
				return 0;
			}
			int key = i;
			a = stoi(fin_prim[i - 1]) / stoi(fin_prim[i + 1]);
			string* temp_prim = new string[razm];
			for (int j = 0; j < razm; j++)
			{
				if (j == key - 1 || j == key || j == key + 1)
				{

				}
				else
				{
					temp_prim[count] = fin_prim[j];
					count++;
				}
			}
			delete[]fin_prim;
			razm = razm - 2;
			fin_prim = new string[razm];
			int counter = 0;
			for (int j = 0; j < razm; j++)
			{
				if (key - 1 == j)
				{
					fin_prim[j] = to_string(a);
				}
				else
				{
					fin_prim[j] = temp_prim[counter];
					counter++;
				}
			}
			return fin_prim;
		}
	}
	for (int i = 0; i < razm; i++)
	{
		if (fin_prim[i] == "+" && razm > 1)
		{
			int key = i;
			int a = stoi(fin_prim[i - 1]) + stoi(fin_prim[i + 1]);
			string* temp_prim = new string[razm];
			for (int j = 0; j < razm; j++)
			{
				if (j == key - 1 || j == key || j == key + 1)
				{

				}
				else
				{
					temp_prim[count] = fin_prim[j];
					count++;
				}
			}
			delete[]fin_prim;
			razm = razm - 2;
			fin_prim = new string[razm];
			int counter = 0;
			for (int j = 0; j < razm; j++)
			{
				if (key - 1 == j)
				{
					fin_prim[j] = to_string(a);
				}
				else
				{
					fin_prim[j] = temp_prim[counter];
					counter++;
				}
			}
			return fin_prim;
		}
	}
	for (int i = 0; i < razm; i++)
	{
	 if (fin_prim[i] == "-")
		{
			int key = i;
			a = stoi(fin_prim[i - 1]) - stoi(fin_prim[i + 1]);
			string* temp_prim = new string[razm];
			for (int j = 0; j < razm; j++)
			{
				if (j == key - 1 || j == key || j == key + 1)
				{

				}
				else
				{
					temp_prim[count] = fin_prim[j];
					count++;
				}
			}
			delete[]fin_prim;
			razm = razm - 2;
			fin_prim = new string[razm];
			int counter = 0;
			for (int j = 0; j < razm; j++)
			{
				if (key - 1 == j)
				{
					fin_prim[j] = to_string(a);
				}
				else
				{
					fin_prim[j] = temp_prim[counter];
					counter++;
				}
			}
			return fin_prim;
		}
	}
}