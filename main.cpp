#include<iostream>
using namespace std;

struct video
{
	char ten[100];
	int dungluong; // mb
	int theloai; //1: hoat hinh, 2: am nhac, 3: ki su
	int sophut; // thoi luong phut
};
struct node
{
	video info;
	node* next;
};
struct list
{
	node* head;
	node* tail;
};
void menu(list& l);
node* GetNode();
void InsertTail(list& l);
void Xuat1video(video k);
void OutPut(list l);
void Timvideo(list l);
void xoavideo(list& l);
void sapxep(list& l);
int tinhtong(list l);
void suaten(list& l);
void main()
{
	list l;
	l.head = l.tail = NULL;
	menu(l);
}
void menu(list& l)
{
	int luachon;
	do {
		system("cls");
		cout << "\t\t================MENU=======================" << endl;
		cout << "\t1.Them 1 video" << endl;
		cout << "\t2.Xuat danh sach video" << endl;
		cout << "\t3.Tim video theo ten" << endl;
		cout << "\t4.Xoa video co dung luong lon hon 50" << endl;
		cout << "\t5.Sap xep video theo dung luong" << endl;
		cout << "\t6.Tinh tong thoi luong cua video" << endl;
		cout << "\t7.Sua ten video" << endl;
		cout << "\t0.Ket thuc chuong trinh!" << endl;
		cout << "\t\t==================END MENU====================" << endl << endl;
		cout << "Nhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon>7)
		{
			cout << "Lua chon khong hop le!" << endl;
			system("pause");
		}
		else if (luachon == 1)
		{
			InsertTail(l);
			cout << "Them thanh cong!" << endl;
			system("pause");
		}
		else if (luachon == 2)
		{
			cout << "\n\t\tTHONG TIN CUA CAC VIDEO LA: " << endl;
			OutPut(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			Timvideo(l);
			system("pause");
		}
		else if (luachon == 4)
		{
			xoavideo(l);
			system("pause");
		}
		else if (luachon == 5)
		{
			sapxep(l);
			system("pause");
		}
		else if (luachon == 6)
		{
			cout << "\nTong thoi luong cua toan bo video trong danh sach la: " << tinhtong(l) << endl;
			system("pause");

		}
		else if (luachon == 7)
		{
			suaten(l);
			system("pause");

		}
	} while (luachon != 0);
}
node* GetNode()
{
	cin.ignore();
	node* p = new node;
	cout << "Nhap ten video: ";
	cin.getline(p->info.ten, 100);
	cout << "Nhap dung luong cua video: ";
	cin >> p->info.dungluong;
	cout << "Nhap the loai video(1: hoat hinh, 2: am nhac, 3: ki su): ";
	cin >> p->info.theloai;
	cout << "Nhap so phut cua video: ";
	cin >> p->info.sophut;
	p->next = NULL;
	return p;
}
void InsertTail(list& l)
{
	node* p = GetNode();
	if (l.head == NULL)
		l.head = l.tail = p;
	else {
		l.tail->next = p;
		l.tail = p;
	}
}
void Xuat1video(video k)
{
	cout << "Ten video : " << k.ten << endl;
	cout << "Dung luong video: " << k.dungluong << endl;
	cout << "The loai: ";
	if (k.theloai == 1)
		cout << "hoat hinh" << endl;
	else if (k.theloai == 2)
		cout << "am nhac" << endl;
	else if (k.theloai == 3)
		cout << "ki su" << endl;
	cout << "so phut cua video: " << k.sophut << endl;
}
void OutPut(list l)
{
	node* p = l.head;
	int count = 0;
	while (p != NULL)
	{
		cout << "\nThong tin cua video thu " << ++count << ": " << endl;
		Xuat1video(p->info);
		p = p->next;
	}
}
void Timvideo(list l)
{
	cin.ignore();
	char temp[100];
	cout << "Nhap ten video muon tim: ";
	cin.getline(temp, 100);
	node* p = l.head;
	while (p != NULL)
	{
		if (strcmp(p->info.ten, temp) == 0)
			break;
		p = p->next;
	}
	if (p != NULL)
	{
		cout << "\n\t\tTHONG TIN VIDEO BAN CAN TIM LA: " << endl;
		Xuat1video(p->info);
	}
	else {
		cout << "\n\t\tKHONG CO VIDEO BAN MUON TIM!" << endl;
	}
}
void xoavideo(list& l)
{
	if (l.head == NULL)
	{
		cout << "Danh Sach Rong!" << endl;
		return;
	}
	node* k = NULL;
	for (node* p = l.head; p != NULL;)
	{
		if (l.head->info.dungluong > 50)
		{
			node* q = l.head;
			l.head = l.head->next;
			if (l.head == NULL)
				l.tail = NULL;
			delete q;
			p = p->next;
		}
		else if (p->info.dungluong > 50)
		{
			node* q = p;
			k->next = p->next;
			if (p == l.tail)
				l.tail = k;
			p = p->next;
			delete q;
		}
		else
		{
			k = p;
			p = p->next;
		}
	}
	cout << "Xoa Thanh Cong!" << endl;
}
void sapxep(list& l)
{
	int luachon;
	cout << "ban muon sap xep tang dan, hay giam dan theo dung luong(1: tang dan,0: giam dan): ";
	cin >> luachon;
	if (luachon == 1)
	{
		for (node* p = l.head; p != NULL; p = p->next)
			for (node* q = p->next; q != NULL; q = q->next)
				if (p->info.dungluong > q->info.dungluong)
					swap(p->info, q->info);
		cout << "Sap xep thanh cong!" << endl;
	}
	else if (luachon == 0)
	{
		for (node* p = l.head; p != NULL; p = p->next)
			for (node* q = p->next; q != NULL; q = q->next)
				if (p->info.dungluong < q->info.dungluong)
					swap(p->info, q->info);
		cout << "Sap xep thanh cong!" << endl;

	}
	else {
		cout << "Lua chon khong hop le!" << endl;
	}
}
int tinhtong(list l)
{
	int sum = 0;
	node* p = l.head;
	while (p != NULL)
	{
		sum += p->info.sophut;
		p = p->next;
	}
	return sum;
}
void suaten(list& l)
{
	cin.ignore();
	char tempname[100];
	cout << "Nhap ten video muon sua: ";
	cin.getline(tempname, 100);
	node* p = l.head;
	while (p != NULL)
	{
		if (strcmp(p->info.ten, tempname) == 0)
			break;
		p = p->next;
	}
	if (p == NULL)
		cout << "Khong Tim Thay!" << endl;
	else
	{
		cout << "Nhap ten muon sua: ";
		cin.getline(p->info.ten,100);
		cout << "Doi Ten Thanh Cong!" << endl;
	}

}
