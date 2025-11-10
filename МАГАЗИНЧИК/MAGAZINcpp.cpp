#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
//Сласти
// учётные записи //
size_t userSize = 2;
std::string userStatus[3]{"Супер админ", "админ", "сотрудник"};
std::string* loginArr = new std::string[userSize]{ "admin", "user"};
std::string* passArr = new std::string[userSize]{ "admin", "user"};
std::string* statusArr = new std::string[userSize]{userStatus[0], userStatus[2]};
std::string currentStatus;
//конец//
//склад
void CreateStorage();

void start();
bool Login();
inline void Getline(std::string& str);
inline void Err(int time);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	start();
	delete[]loginArr, passArr, statusArr;
	return 0;
}

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[staticSize];
	"Земфир: оболочная нежность", "Пражский торт: Вечер в праге", "сахарное печение: хрустальные грёзы", "пряники: медово-горчичный",
	"брани: Малиновый рассвет", "набор для приготоаленния своего торта или пироженного: Сладкий конструктор", "Жевательно-миндальное печенье-меренга: сибирская резина"
	"Ассорти из изящных итальянских сладостей: Дольче Вита", "яркие леденцы: взрывная карамель", "шоколадки: грильяж в шоколаде";
	unsigned int cout[staticSize]{ 20,12,65,34,21,8,32,43,23,6 };
	double price[staticSize]{ 143.3,210.4,452.1,377.3,116.8,287.2,140.4,210.3,899.9,1900.0 };
}

void start()
{
	std::cout << "\n\n\n\t\t\tСласти\n\n\n";
	if (Login())
	{
		if (currentStatus == userStatus[0]);
		{
			// создание склада\ создание нового склада и открыти магазина
		}
		else if (currentStatus == userStatus[1]);
		{
			// создание склада и открытие магазина
		}
		else if (currentStatus == userStatus[2]);
		{
			// создание склада
		}
	}

}
bool Login()
{
std::string login, pass;
while (true)
{
	std::cout << "ВВедите логин:";
	Getline(login);
	std::cout << "Введите пароль:";
	Getline(pass);
	if (login == loginArr[0] && pass == passArr[0])
	{
		std::cout << "пользователь:" << loginArr[0] << "\n\n вошёл в систему!\n";
		std::cout << "Ваш статус:" << statusArr[0] << "\n\n";
		currentStatus = statusArr[0];
		return true;
		if (login == "exit" && pass == "exit")
		{
			currentStatus = " ";
			return false;
		}
	}
	for (size_t i = 1; i < userSize; i++) 
	{
		if (login == loginArr[i] && pass == passArr[i])
		{
			std::cout << "пользователь:" << loginArr[0] << "\n\n вошёл в систему!\n";
			std::cout << "Ваш статус:" << statusArr[0] << "\n\n";
			return true;
		}
	}
	Err();
	}
}
inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');
}
inline void Err(int time = 1500)
{
	std::cout << "Некоректный вход";
	Sleep(time);
	system("cls");
}