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
	cout << "      圖書館系統          " << endl;
	cout << "============================" << endl;
	int choose=0;
	bool check=false;
	while (check==false&&choose!=3)
	{
		cout << "1. 登入" << endl;
		cout << "2. 註冊" << endl;
		cout << "3. 不想去圖書館～～" << endl;
		cout << "請選擇 :";
		cin >> choose;
		while (choose == 1 || choose == 2||choose==3)
		{
			if (choose == 2)
			{
				cout << "============================" << endl;
				cout << "      圖書館系統          " << endl;
				cout << "============================" << endl;
				information enroll;
				cout << "請輸入名字:";
				cin >> enroll.name;
				cout << "請輸入密碼:";
				cin >> enroll.passward;
				cout << "密碼建立成功" << endl;
				reservation(enroll);
				break;
			}
			else if (choose == 1)
			{
				cout << "============================" << endl;
				cout << "      圖書館系統          " << endl;
				cout << "============================" << endl;
				information compare;
				cout << "請輸入名字:";
				cin >> compare.name;
				cout << "請輸入密碼:";
				cin >> compare.passward;
				if (compare.name == "admin"&&compare.passward == "admin")
				{
					cout << "登入成功!" << endl;
					int adm = 1;
					int count = 0;
					int i = 1;
					while (adm == 1 || adm == 2||adm==3)
					{
						cout << "============================" << endl;
						cout << "      圖書館系統    " << compare.name << endl;
						cout << "============================" << endl;
						cout << "1. 瀏覽所有書籍" << endl;
						cout << "2. 新增書籍" << endl;
						cout << "3. 離開" << endl;
						cout << "請選擇：";
						cin >> adm;
						if (adm == 2)
						{
							string  n, w, y;
							char r[7] = {"\0"};
							cout << "請輸入書名:";
							cin >> n;
							cout << "請輸入作者:";
							cin >> w;
							cout << "請輸入年分:";
							cin >> y;
							library lib(i,n,w,y,r);
							cout << "新增成功!" << endl;
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
							cout << "你確定要離開嗎?" << endl;
							cout << "1. 對啦!" << endl;
							cout << "2. 再待一下好了~" << endl;
							cout << "請選擇 :";
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
					cout << "登入成功!" << endl;
					int function = 0;
					while(function!=1||function!=2 || function != 3 || function != 4 || function != 5)
					{
						
						cout << "============================" << endl;
						cout << "      圖書館系統    " << compare.name << endl;
						cout << "============================" << endl;
						cout << "1. 瀏覽所有書籍" << endl;
						cout << "2. 借書" << endl;
						cout << "3. 還書" << endl;
						cout << "4. 搜尋書名" << endl;
						cout << "5. 搜尋年份" << endl;
						cout << "6. 離開" << endl;
						cout << "請輸入 :";
						cin >> function;
						if (function == 1)
						{
							display(0);
						}
						if (function == 2)
						{
							cout << "請輸入書名 :";
							string bookname;
							cin >> bookname;
							searchbook(bookname,compare.name);
						}
						if (function == 3)
						{
							cout << "請輸入書名 :";
							string bookname;
							cin >> bookname;
							restore(bookname, compare.name);
						}
						if (function == 4)
						{
							cout << "請輸入書名 :";
							string bookname;
							cin >> bookname;
							bname(bookname);
						}
						if (function == 5)
						{
							cout << "請輸入年份 :";
							string year;
							cin >> year;
							searchyear(year);
						}
						if (function == 6)
						{
							bool check = true;
							int a;
							cout << "你確定要離開嗎?"<<endl;
							cout << "1. 對啦!" << endl;
							cout << "2. 再待一下好了~" << endl;
							cout << "請選擇 :";
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
					cout << "歹勢沒有你這個人" << endl;
					break;
				}
			}
			else if (choose == 3)
			{
				cout << "掰掰 ><" << endl;
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
	cout << "id  書名    作者     年分  借閱者" << endl;
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
				cout << "借閱成功!" << endl;
			else
				cout << "此書已有人借閱!" << endl;
			remove("book.txt");
			ofstream outfile("book.txt", ios::out);
			outfile << reserve;
			break;
		}
		else
			continue;
	}
	if(check==false)
	cout << "查無此書!" << endl;
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
				cout << "此書不是你借的!" << endl;
			else
				cout << "還書成功" << endl;
			remove("book.txt");
			ofstream outfile("book.txt", ios::out);
			outfile << reserve;
			break;
		}
		else
			continue;
	}
	if (check == false)
		cout << "查無此書!" << endl;
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
			cout << "id  書名    作者     年分  借閱者" << endl;
			for (int j = i - 4; j < i-4+33; j++)
				cout << save[j];
			cout << endl;
			break;
		}
		else
			continue;
	}
	if (check == false)
		cout << "查無此書!" << endl;
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
			cout << "id  書名    作者     年分  借閱者" << endl;
			for (int j = i - 21; j < i - 21 + 33; j++)
				cout << save[j];
			cout << endl;
			break;
		}
		else
			continue;
	}
	if (check == false)
		cout << "查無此書!" << endl;
}