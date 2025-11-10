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
size_t storageSize = 0;
bool staticstoradeCreated = false;
int* idArr;
std::string* nameArr;
int* coutArr;
double* priceArr;
void CreateStorage();

void start();
bool Login();
inline void Getline(std::string& str);
inline void Err(int time);
void CreateStorage();
template <typename Arr>
void FillArray(Arr*& dimanicArr, size_t size);
//конец склада
// служба
void ShowSuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 -начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнит склад\n";
		std::cout << "4 - Списать товар\n";
		std::cout << "5 - изменить цену\n";
		std::cout << "6 - редактировать персонал\n";
		std::cout << "7 - отчёт о приболи\n";
		std::cout << "8 - редактировать склад\n";
		std::cout << "0 - закрыть магазин\n";
		std::cout << "ввод:"
	}
}


void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[staticSize];
	"Земфир: оболочная нежность", "Пражский торт: Вечер в праге", "сахарное печение: хрустальные грёзы", "пряники: медово-горчичный",
	"брани: Малиновый рассвет", "набор для приготоаленния своего торта или пироженного: Сладкий конструктор", "Жевательно-миндальное печенье-меренга: сибирская резина"
	"Ассорти из изящных итальянских сладостей: Дольче Вита", "яркие леденцы: взрывная карамель", "шоколадки: грильяж в шоколаде";
	unsigned int count[staticSize]{ 20,12,65,34,21,8,32,43,23,6 };
	double price[staticSize]{ 143.3,210.4,452.1,377.3,116.8,287.2,140.4,210.3,899.9,1900.0 };
	storageSize = staticSize;
	idArr = new int[storageSize];
	nameArr = new std::string[storageSize];
	countArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];
	FillArray(idArr, id, storageSize);
	FillArray(priceArr,price, storageSize);
	FillArray(countArr, count, storageSize);
	FillArray(nameArr, name, storageSize);

}
void ShowStorage()
{
	std::cout < "ID\t" << std::left << std::setw(20) << "название товара\t\t" << "Ценв\t" << "кол-во\n";
	for (size_t i = 0; i < storageSize; i += )
	{
		std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t" << price
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	start();
	delete()loginArr, passArr, statusArr;
	if (staticStorageCreated)
	{
		delete[]idArr, nameArr, countArr, priceArr;
	}
	return 0;
}
void start()
{
	std::cout << "\n\n\n\t\t\tСласти\n\n\n";
	if (Login())
	{
		if (currentStatus == userStatus[0]);
		{
			std::cout << "выбирите склад\1-готовый\n2-создать новый склад\nВывод:";
			Getline(choose);
			if (choose == "1")
			{
				CreateStrage();
				break;
			}
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

template <typename Arr>
void FillArray(Arr *&dimanicArr, size_t size);
{
	for (size_t i = 0; i < size; i++)
	{
		dinamicArr[i] = staticArr[i];
	}
}
