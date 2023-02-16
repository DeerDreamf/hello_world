#include<iostream>
using namespace std;
#include<string.h>

#define MAX 1000


struct person {
	string m_Name;
	int  m_Sex;		//1��   2Ů
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

//�˵���ʾ
void ShowMenu() {
	cout << "******************************" << endl;
	cout << "*****   1.�����ϵ��  *****" << endl;
	cout << "*****   2.��ʾ��ϵ��  *****" << endl;
	cout << "*****   3.ɾ����ϵ��  *****" << endl;
	cout << "*****   4.������ϵ��  *****" << endl;
	cout << "*****   5.�޸���ϵ��  *****" << endl;
	cout << "*****   6.�����ϵ��  *****" << endl;
	cout << "*****   0.�˳�ϵͳ    *****" << endl;
	cout << "******************************" << endl;
}

//1.�����ϵ��
void addPerson(Addressbooks* abs) {
	//�ж���û��
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼���ˣ��޷���ӣ� " << endl;
		return;
	}
	else {
		//��Ӿ�����ϵ��

		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		cout << " �������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{	//����1 or 2 �Ϳ����˳�ѭ��
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		
		//����
		cout << endl;
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		cout << endl;
		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << endl;
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//��������
		abs->m_Size++;

		cout << endl;
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");
	}
}

//2.��ʾ��ϵ��
void showPerson(Addressbooks * abs) {
	if (abs->m_Size == 0)		//�ж�������ϵ��
		cout << "��ǰ��¼Ϊ��" << endl;
	else
	{
		for (int  i = 0; i < abs -> m_Size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name ;
			
			cout << "\t�Ա� "  ;
			if (abs->personArray[i].m_Sex == 1)
				cout << "��" ;
			else
			{
				cout << "Ů";
			}
			cout << "\t���䣺 " << abs->personArray[i].m_Age ;
			cout << "\t��ϵ�绰�� " << abs->personArray[i].m_Phone;
			cout << "\tסַ�� " << abs->personArray[i].m_Addr << endl;

		}
	}
	system("pause");
	system("cls");			 //����
}

//3.ɾ����ϵ��
void deletePerson(Addressbooks* abs) {
	cout << "������Ҫɾ������ϵ��" << endl;
	
	string name;
	cin >> name;
	
	//ret == -1 δ�ҵ�
	//ret ��= �ҵ���
	int ret = isExist(abs, name);

	if (ret != -1) {
		//ɾ��������
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(Addressbooks* abs) {
	cout << "��������ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	//�ж��Ƿ����
	int ret = isExist(abs, name);

	if (ret != -1) {
		cout << "������ " << abs->personArray[ret].m_Name;
		cout << "\t�Ա� " << abs->personArray[ret].m_Sex;
		cout << "\t���䣺 " << abs->personArray[ret].m_Age;
		cout << "\t�绰�� " << abs->personArray[ret].m_Phone;
		cout << "\t��ַ�� " << abs->personArray[ret].m_Addr << endl;
		}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(Addressbooks* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�Ա�
		cout << endl;
		cout << " �������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;

		while (true)
		{	//����1 or 2 �Ϳ����˳�ѭ��
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		//����
		cout << endl;
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�绰
		cout << endl;
		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//סַ
		cout << endl;
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ��
void cleanPerson(Addressbooks* abs) {
	cout << "��ȷ���Ƿ������ϵ��" << endl;
	if (Ready() == 1) {
		abs->m_Size = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	else {
		cout << "��ȡ�������ϵ��" << endl;
	}
	system("pause");
	system("cls");
}

int Ready() {
	int i;
	cout << "1Ϊ��գ�0Ϊ�����" << endl;
	cin >> i;
	return i;
}

int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	return -1;		//û�ҵ�������-1
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
		case 1:		//���
			addPerson(&abs);
			break;

		case 2:		//��ʾ
			showPerson(&abs);
			break;

		case 3:		//ɾ��
			deletePerson(&abs);
			break;

		case 4:		//����
			findPerson(&abs);
			break;

		case 5:		//�޸�
			modifyPerson(&abs);
			break;

		case 6: {		//���
			cleanPerson(&abs);
			break;
		}

		case 0:		//�˳�
			cout << "��ӭ�´�ʹ��" << endl;
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