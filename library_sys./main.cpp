#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"book.h"
using namespace std;

struct information
{
	int ID;
	string passward;
	string name;
};
void reservation(information);
bool login(information);
void addbook(library);
void display(int);
void searchbook(string,string);
void restore(string,string);
void bname(string);
void searchyear(string);

int main()
{
	cout << "============================" << endl;
	cout << "      �Ϯ��]�t��          " << endl;
	cout << "============================" << endl;
	int choose=0;
	bool check=false;
	while (check==false&&choose!=3)
	{
		cout << "1. �n�J" << endl;
		cout << "2. ���U" << endl;
		cout << "3. ���Q�h�Ϯ��]���" << endl;
		cout << "�п�� :";
		cin >> choose;
		while (choose == 1 || choose == 2||choose==3)
		{
			if (choose == 2)
			{
				cout << "============================" << endl;
				cout << "      �Ϯ��]�t��          " << endl;
				cout << "============================" << endl;
				information enroll;
				cout << "�п�J�W�r:";
				cin >> enroll.name;
				cout << "�п�J�K�X:";
				cin >> enroll.passward;
				cout << "�K�X�إߦ��\" << endl;
				reservation(enroll);
				break;
			}
			else if (choose == 1)
			{
				cout << "============================" << endl;
				cout << "      �Ϯ��]�t��          " << endl;
				cout << "============================" << endl;
				information compare;
				cout << "�п�J�W�r:";
				cin >> compare.name;
				cout << "�п�J�K�X:";
				cin >> compare.passward;
				if (compare.name == "admin"&&compare.passward == "admin")
				{
					cout << "�n�J���\!" << endl;
					int adm = 1;
					int count = 0;
					int i = 1;
					while (adm == 1 || adm == 2||adm==3)
					{
						cout << "============================" << endl;
						cout << "      �Ϯ��]�t��    " << compare.name << endl;
						cout << "============================" << endl;
						cout << "1. �s���Ҧ����y" << endl;
						cout << "2. �s�W���y" << endl;
						cout << "3. ���}" << endl;
						cout << "�п�ܡG";
						cin >> adm;
						if (adm == 2)
						{
							string  n, w, y;
							char r[7] = {"\0"};
							cout << "�п�J�ѦW:";
							cin >> n;
							cout << "�п�J�@��:";
							cin >> w;
							cout << "�п�J�~��:";
							cin >> y;
							library lib(i,n,w,y,r);
							cout << "�s�W���\!" << endl;
							count++;
							i++;
							addbook(lib);
						}
						if (adm == 1)
						{
							display(count);
						}
						if (adm == 3)
						{
							bool check = true;
							int a;
							cout << "�A�T�w�n���}��?" << endl;
							cout << "1. ���!" << endl;
							cout << "2. �A�ݤ@�U�n�F~" << endl;
							cout << "�п�� :";
							cin >> a;
							if (a == 1)
								break;
						}
					}
					check = true;
					break;
				}
				if (login(compare))
				{
					cout << "�n�J���\!" << endl;
					int function = 0;
					while(function!=1||function!=2 || function != 3 || function != 4 || function != 5)
					{
						
						cout << "============================" << endl;
						cout << "      �Ϯ��]�t��    " << compare.name << endl;
						cout << "============================" << endl;
						cout << "1. �s���Ҧ����y" << endl;
						cout << "2. �ɮ�" << endl;
						cout << "3. �ٮ�" << endl;
						cout << "4. �j�M�ѦW" << endl;
						cout << "5. �j�M�~��" << endl;
						cout << "6. ���}" << endl;
						cout << "�п�J :";
						cin >> function;
						if (function == 1)
						{
							display(0);
						}
						if (function == 2)
						{
							cout << "�п�J�ѦW :";
							string bookname;
							cin >> bookname;
							searchbook(bookname,compare.name);
						}
						if (function == 3)
						{
							cout << "�п�J�ѦW :";
							string bookname;
							cin >> bookname;
							restore(bookname, compare.name);
						}
						if (function == 4)
						{
							cout << "�п�J�ѦW :";
							string bookname;
							cin >> bookname;
							bname(bookname);
						}
						if (function == 5)
						{
							cout << "�п�J�~�� :";
							string year;
							cin >> year;
							searchyear(year);
						}
						if (function == 6)
						{
							bool check = true;
							int a;
							cout << "�A�T�w�n���}��?"<<endl;
							cout << "1. ���!" << endl;
							cout << "2. �A�ݤ@�U�n�F~" << endl;
							cout << "�п�� :";
							cin >> a;
							if(a==1)
								break;
						}
					}
					check = true;
					break;
				}
				else
				{
					cout << "��ըS���A�o�ӤH" << endl;
					break;
				}
			}
			else if (choose == 3)
			{
				cout << "�T�T ><" << endl;
				break;
			}
		}
	}
	system("pause");
}


void reservation(information enroll)
{
	ofstream outfile("Reservation.txt", ios::app);
	outfile << enroll.name << " " << enroll.passward << endl;
}

bool login(information compare)
{
	char save[200] = {};
	ifstream infile("Reservation.txt", ios::in);
	infile.read(save, 200);
	bool check = true;
	for (int i = 0; i < strlen(save); i++)
	{
		if (save[i] = compare.name[0])
		{
			bool ok = true;
			int k = 1;
			for (int j = i + 1; j < i + compare.name.size(); j++)
			{
				if (save[j] != compare.name[k])
				{
					ok = false;
					break;
				}
				k++;
			}
			if (ok == true)
			{
				int z = 1;
				bool pass = true;
				for (int k = i + compare.name.size() + 2; k < i + compare.name.size() + 1 + compare.passward.size(); k++)
				{
					if (save[k] != compare.passward[z])
					{
						pass = false;
						break;
					}
					z++;
				}
				if (pass == true)
					return true;
				else
				{
					return false;
				}
			}
		}
	}
	return false;
}

void addbook(const library lib)
{
	ofstream outfile("book.txt",  ios::app);
	outfile << lib.id << "   " << lib.name << "   " << lib.writer << "  " << lib.year << "  " << lib.reader<<endl;
	outfile.close();
}

void display(int count)
{
	ifstream infile("book.txt", ios::in);
	char x[500] = {};
	cout << "id  �ѦW    �@��     �~��  �ɾ\��" << endl;
	infile.read(x,sizeof(x));
	cout << x;
	infile.close();
}

void searchbook(string bookname,string name)
{
	ifstream infile("book.txt", ios::in);
	char save[500] = {};
	bool check = false;
	infile.read(save, 500);
	for (int i = 0; i < strlen(save); i++)
	{
		if (save[i] == bookname[0])
		{
			int k = 1;
			bool ok=true;
			for (int j = i + 1; j < i + bookname.size(); j++)
			{
				if (save[j] != bookname[k])
				{
					ok = false;
					break;
				}
				k++;
			}
			if (ok == false)
				check = false;
			else
				check = true;
		}
		if (check == true)
		{
			char reserve[500] = {};
			ifstream infile("book.txt", ios::in);
			infile.read(reserve,500);
			int z=0 ,a= 0;
			bool x = true;
			for (int k = i+23; k < i+name.size()+23; k++)
			{
				if (reserve[k] == ' ')
				{
					reserve[k] = name[z];
					z++;
					continue;
				}
				else
				{
					if (reserve[k] != name[a])
					{
						x = false;
						break;
					}
				}
			}
			if (x == true)
				cout << "�ɾ\���\!" << endl;
			else
				cout << "���Ѥw���H�ɾ\!" << endl;
			remove("book.txt");
			ofstream outfile("book.txt", ios::out);
			outfile << reserve;
			break;
		}
		else
			continue;
	}
	if(check==false)
	cout << "�d�L����!" << endl;
}

void restore(string bookname, string name)
{
	ifstream infile("book.txt", ios::in);
	char save[500] = {};
	bool check = false;
	infile.read(save, 500);
	//cout << save;
	for (int i = 0; i < strlen(save); i++)
	{
		if (save[i] == bookname[0])
		{
			int k = 1;
			bool ok = true;
			for (int j = i + 1; j < i + bookname.size(); j++)
			{
				if (save[j] != bookname[k])
				{
					ok = false;
					break;
				}
				k++;
			}
			if (ok == false)
				check = false;
			else
				check = true;
		}
		if (check == true)
		{
			char reserve[500] = {};
			ifstream infile("book.txt", ios::in);
			infile.read(reserve, 500);
			int z = 0;
			bool x = true;

			for (int k = i + 23; k < i + name.size() + 23; k++)
			{
				if (reserve[k] != name[z])
				{
					x = false;
					break;
				}
				reserve[k] = ' ';
				z++;
			}
			if (x == false)
				cout << "���Ѥ��O�A�ɪ�!" << endl;
			else
				cout << "�ٮѦ��\" << endl;
			remove("book.txt");
			ofstream outfile("book.txt", ios::out);
			outfile << reserve;
			break;
		}
		else
			continue;
	}
	if (check == false)
		cout << "�d�L����!" << endl;
}

void bname(string bookname)
{
	ifstream infile("book.txt", ios::in);
	char save[500] = {};
	infile.read(save, 500);
	bool check = false;
	for (int i = 0; i < strlen(save); i++)
	{
		if (save[i] == bookname[0])
		{
			int k = 1;
			bool ok=true;
			for (int j = i + 1; j < i + bookname.size(); j++)
			{
				if (save[j] != bookname[k])
				{
					ok = false;
					break;
				}
				k++;
			}
			if (ok == false)
				check = false;
			else
				check = true;
		}
		if (check == true)
		{
			cout << "id  �ѦW    �@��     �~��  �ɾ\��" << endl;
			for (int j = i - 4; j < i-4+33; j++)
				cout << save[j];
			cout << endl;
			break;
		}
		else
			continue;
	}
	if (check == false)
		cout << "�d�L����!" << endl;
}

void searchyear(string year)
{
	char save[500] = {};
	ifstream infile("book.txt", ios::in);
	infile.read(save, 500);
	bool check = false;
	for (int i = 0; i < strlen(save); i++)
	{
		if (save[i] == year[0])
		{
			bool ok = true;
			int k = 1;
			for (int j = i + 1; j < i + year.size(); j++)
			{
				if (save[j] != year[k])
				{
					ok = false;
					break;
				}
				k++;
			}
			if (ok == false)
				check = false;
			else
				check = true;
		}
		if (check == true)
		{
			cout << "id  �ѦW    �@��     �~��  �ɾ\��" << endl;
			for (int j = i - 21; j < i - 21 + 33; j++)
				cout << save[j];
			cout << endl;
			break;
		}
		else
			continue;
	}
	if (check == false)
		cout << "�d�L����!" << endl;
}