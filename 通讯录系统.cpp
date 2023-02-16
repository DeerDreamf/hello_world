#include<iostream>
using namespace std;
#include<string.h>

#define MAX 1000


struct person {
	string m_Name;
	int  m_Sex;		//1男   2女
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks {
	struct person personArray[MAX+1];
	int m_Size;
};

int isExist(Addressbooks* abs, string name);
int Ready();

//菜单显示
void ShowMenu() {
	cout << "******************************" << endl;
	cout << "*****   1.添加联系人  *****" << endl;
	cout << "*****   2.显示联系人  *****" << endl;
	cout << "*****   3.删除联系人  *****" << endl;
	cout << "*****   4.查找联系人  *****" << endl;
	cout << "*****   5.修改联系人  *****" << endl;
	cout << "*****   6.清空联系人  *****" << endl;
	cout << "*****   0.退出系统    *****" << endl;
	cout << "******************************" << endl;
}

//1.添加联系人
void addPerson(Addressbooks* abs) {
	//判断满没满
	if (abs->m_Size == MAX) {
		cout << "通讯录满了，无法添加！ " << endl;
		return;
	}
	else {
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << " 请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{	//输入1 or 2 就可以退出循环
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		
		//年龄
		cout << endl;
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout << endl;
		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << endl;
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新人数
		abs->m_Size++;

		cout << endl;
		cout << "添加成功" << endl;

		system("pause");
		system("cls");
	}
}

//2.显示联系人
void showPerson(Addressbooks * abs) {
	if (abs->m_Size == 0)		//判断有无联系人
		cout << "当前记录为空" << endl;
	else
	{
		for (int  i = 0; i < abs -> m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name ;
			
			cout << "\t性别： "  ;
			if (abs->personArray[i].m_Sex == 1)
				cout << "男" ;
			else
			{
				cout << "女";
			}
			cout << "\t年龄： " << abs->personArray[i].m_Age ;
			cout << "\t联系电话： " << abs->personArray[i].m_Phone;
			cout << "\t住址： " << abs->personArray[i].m_Addr << endl;

		}
	}
	system("pause");
	system("cls");			 //清屏
}

//3.删除联系人
void deletePerson(Addressbooks* abs) {
	cout << "请输入要删除的联系人" << endl;
	
	string name;
	cin >> name;
	
	//ret == -1 未找到
	//ret ！= 找到了
	int ret = isExist(abs, name);

	if (ret != -1) {
		//删除操作、
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(Addressbooks* abs) {
	cout << "请输入查找的联系人" << endl;
	string name;
	cin >> name;

	//判断是否存在
	int ret = isExist(abs, name);

	if (ret != -1) {
		cout << "姓名： " << abs->personArray[ret].m_Name;
		cout << "\t性别： " << abs->personArray[ret].m_Sex;
		cout << "\t年龄： " << abs->personArray[ret].m_Age;
		cout << "\t电话： " << abs->personArray[ret].m_Phone;
		cout << "\t地址： " << abs->personArray[ret].m_Addr << endl;
		}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(Addressbooks* abs) {
	cout << "请输入需要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别
		cout << endl;
		cout << " 请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;

		while (true)
		{	//输入1 or 2 就可以退出循环
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		//年龄
		cout << endl;
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		cout << endl;
		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		cout << endl;
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人
void cleanPerson(Addressbooks* abs) {
	cout << "请确认是否清空联系人" << endl;
	if (Ready() == 1) {
		abs->m_Size = 0;
		cout << "通讯录已清空" << endl;
	}
	else {
		cout << "已取消清空联系人" << endl;
	}
	system("pause");
	system("cls");
}

int Ready() {
	int i;
	cout << "1为清空，0为不清空" << endl;
	cin >> i;
	return i;
}

int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;		//没找到，返回-1
}

int main() {

	int select = 0;
	
	Addressbooks abs;
	abs.m_Size = 0;

	while (true) {
		ShowMenu();

		cin >> select;

		switch (select)
		{
		case 1:		//添加
			addPerson(&abs);
			break;

		case 2:		//显示
			showPerson(&abs);
			break;

		case 3:		//删除
			deletePerson(&abs);
			break;

		case 4:		//查找
			findPerson(&abs);
			break;

		case 5:		//修改
			modifyPerson(&abs);
			break;

		case 6: {		//清空
			cleanPerson(&abs);
			break;
		}

		case 0:		//退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}