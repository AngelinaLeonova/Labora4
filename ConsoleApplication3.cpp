// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <regex>
#include <string>
using namespace std;

class Admin
{
public:
	string spezial;

	Admin(string name = "")//Конструкт, с принимаемой переменной и ее знаечением по умолчанию
		: spezial(name)
	{
	}

	string getSpezial()
		const {return spezial;}//Метод получения значения 

};

class Info : public Admin
{
public:
	string title;
	int count;

	Info(string s1 = "", int k = 12, string spezial = "")
		: title(s1), count(k), Admin(spezial)
	{
		cout << " Конструктр работает" << endl;
	}
	void getNazvanie() const { cout << "Наименование отдела: " << title << endl << "Специализация: " <<  spezial << endl << "Количество сотрудников: " <<  count << endl; }
};



class Director : public Admin
{
public:
	string name;
	string secondName;
	string Otch;
	string position;

	Director(string s1 = "", string s2 = "", string s3 = "", string s4 = "")
		: name(s1), secondName(s3), Otch(s2), position(s4)
	{
		cout << " Конструктр работает" << endl;
	}
	void getDirector() const { cout << "Должность: " << position << endl << "Фамилия: " << secondName << endl << "Имя: " <<  name << endl << "Отчество: " <<  Otch << endl  ; }
};

class Strategy : public Admin
{
public:
	string zel;
	string zad;
	int god;

	Strategy(string s1 = "", string s2 = "", int s3 = 12 )
		: zel(s1), zad(s2), god(s3)
	{
		cout << " Конструктр работает" << endl;
	}
	void getStrategy() const { cout << "Цель стратегии отдела: " <<  zel << endl << "Задачи: " << zad << endl << "Планируемый год выполнения: " <<  god << endl; }
};
int main()
{
	system("chcp 1251");
	system("cls");
	string a, b, r, t;
	int c = 0, v = 0;
	cout << "Введите наименование отдела:" << endl;
	getline(cin, a);
	cout << "Введите специализацию отдела:" << endl;
	getline(cin, b);
	cout << "Введите количество сотрудников:" << endl;
	regex integers(R"(\d+)"); // формальный язык поиска и осуществления манимуляций с подстракими в тексте
	char input[80];
	do
	{
		memset(input, 0, 80);//Выделяем динамически память для строки // присовние начальных значений
		cin >> input;
		if (regex_match(input, input + strlen(input), integers))//Условие на соответствие регулярному выражения // возвращает длину строки // формальный язык поиска и осуществления манимуляций с подстракими в тексте
		{
			c = atoi(input);//atoi - Преобразуем строку в integer 
			break;
		}
		else
		{
			cout << "Ошибка! Введите число!";
		}
	} while (1);
	cout << "Введите цель специализации:" << endl;
	cin >> r;
	cout << "Введите задачи для выполнения:" << endl;
	cin >> t;
	cout << "Введите год выполнения:" << endl;
	regex integers1(R"(\d+)");
	char input1[80];
	do
	{
		memset(input1, 0, 80);//Выделяем динамически память для строки
		cin >> input1;
		if (regex_match(input1, input1 + strlen(input1), integers))//Условие на соответствие регулярному выражения
		{
			v = atoi(input1);//atoi - Преобразуем строку в integer 
			break;
		}
		else
		{
			cout << "Ошибка! Введите число!";
		}
	} while (1);
	//cin >> v;
	Strategy f2(r, t, v);
	Info fi(a, c, b);//Создаем экземпляр объекта Info заносим данные через конструктор(метод инициализации)
	Director Uspenskiy("Елена","Михайловна", "Ковалева", "Директор");
	fi.getNazvanie();//Запрашиваем метод getNazvanie 
	Uspenskiy.getDirector();
	f2.getStrategy();
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
