#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <chrono>
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
void CreateStorage();
void ShowStorage(int mode);
template <typename Arr>
void FillArray(Arr*& dimanicArr, size_t size);
void AddStorageItem();
void AddNewItem();
void ChangePrice();
void ChangeName();
void DeleteItem();
void ChangeStorage()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - добавить новый товар\n";
		std::cout << "2 - изменить имя товара\n";
		std::cout << "3 - удалить товар\n";
		std::cout << "0 - выйти из редактора\n";
		std::cout << "ввод:\n";
		if (choose == "1")
		{
			AddNewItem();
		}
		if (choose == "2")
		{

		}
		if (choose == "3")
		{

		}
		if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			Err;
		}
	}
}

//конец склада
// служба
void start();
bool Login();
void ShowSuperAdminMenu();
void RemoveStorageItem();
bool IsNumber(const std::string& str);
inline void Getline(std::string& str);
inline void Err(int time = 2000);
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
		std::cout << "0 - закрыть смену\n";
		std::cout << "ввод:";
		Getline(choose);

		if (choose == "1")
		{
			AddNewItem();
		}
		if (choose == "2")
		{

		}
		if (choose == "3")
		{

		}
		if (choose == "4")
		{
			
		}
		if (choose == "5")
		{
		}
		if (choose == "6")
		{
			
		}
		if (choose == "7")
		{
			
		}

		if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			Err();
		}
	}
}
bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		Err();
		std::cout << "ошибка длины числа. от 1 до 9 цифр включительно\n\n";
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "Введённые данные не являются числом\n\n";
			return false;
		}
	}
	return true;
}
void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[staticSize];
	"Земфир: оболочная нежность", "Пражский торт: Вечер в праге", "сахарное печение: хрустальные грёзы", "пряники: медово-горчичный",
		"брани: Малиновый рассвет", "набор для приготовленния своего торта: Сладкий конструктор", "Жевательно-миндальное печенье-меренга: сибирская резина"
		"Ассорти из изящных итальянских сладостей: Дольче Вита", "яркие леденцы: взрывная карамель", "шоколадки: грильяж в шоколаде";
	unsigned int count[staticSize]{ 20,12,65,34,21,8,32,43,23,6 };
	double price[staticSize]{ 143.3,210.4,452.1,377.3,116.8,287.2,140.4,210.3,899.9,1900.0 };
	storageSize = staticSize;
	idArr = new int[storageSize];
	nameArr = new std::string[storageSize];
	countArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];
	FillArray(idArr, id, storageSize);
	FillArray(priceArr, price, storageSize);
	FillArray(countArr, count, storageSize);
	FillArray(nameArr, name, storageSize);
}
void DeleteItem()
{
	std::string chooseId, choose;
	unsigned int id = 0;
	while (true)
	{
		if (IsNumber(chooseId))
			if
}
void ShowStorage(int mode)
{
	system("cls");
	std::cout < "Id товара:\t" << std::left << std::setw(20) << "название товара\t\t" << "Цены:\t" << "кол-во:\n";
	for (size_t i = 0; i < storageSize; i++)
	{
		std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << countArr[i] << "\n";

	}
	else if (mode == 1)
	{
	std::invalid_argument("StotageMode Error")
	}
	else if (mode == 2)
 
	}
}
void AddStorageItem()
{
	std::string chooseId;
	std::string chooseCount;
	int id = 0;
	unsigned int count = 0;
	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите id товара:";
		Getline(chooseId);
		if (choose == "exit")
		{
			std::cout << "отмена операции пополнения";
			break;
		}
		std::cout << "Введите колличество товара для его пополнения:";
		Getline(chooseCount);
		if (IsNumber(chooseId) && IsNumber(chooseCount)
		{
			id = std::stoi(chooseId);
			count = std::stoi(chooseCount);
			if (id < 1 || id > storageSize || cout < 0 || count > 199)
			{
				std::cout << "некоректный id\n\n";
				std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[id] << "\t" << countArr[id] << "-->" << countAA[id] + count << "\n\n";
				std::cout << "подтвердить?\n 1-да 2-нет\nвывод:";
				Getline(choose);
				if (choose == "1")
				{
					countArr[id] += count;
				std:cout << "товар успешно пополнен";
					sleep(1500);
					system("cls");
					break
				}
				else if (choose = "2")
				{
					std::cout << "некоректный ввод\n";
					sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
		
	}
}
void AddNewItem()
{
	std::string newName, newPrice, newCount, choose;
	double prince = 0.0;
	unsigned int count = 0;
	bool exit = true;
	wile(true)
	{
		system("cls")
			std::cout << "\t добавление нового товара!\n\nВведите\"exit\" для прекращения операции"
			std::cout << "Введите название нового товара:";
		Getline(newName);
		if (newName == "exit")
		{
			std::cout << "операция добовления товара прервана";
			sleep(1500);
			break;
		}
		if (newName.size() <= 0 || newName.size() >= 60)
		{
			std::cout << "ошибка имени. Максимальная длина 60 символов\n";
			sleep(1500);
		}
		else
		{
			break;
	    }
		while (exit)
		{
			system("cls")
				std::cout << "\t добавление нового товара!\n\nВведите\"exit\" для прекращения операции"
				std::cout << "Введите название нового товара:";
			Getline(newCount);
			if (newCount == "exit")
			{
				std::cout << "операция добовления товара прервана";
				sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newCount))
			{
				count = std::stoi(newCount);
				if (count > 222)
				{
					std::cout << "ошибка максимального размера товара. Не более 222 ед.\n"
					Sleep(1500);
				}
				else
				{
					break;
				}
			}
		}

		while (exit)
		{
			system("cls")
				std::cout << "\t добавление нового товара!\n\nВведите\"exit\" для прекращения операции"
				std::cout << "Введите название нового товара:";
			Getline(newPrice);
			if (newPrice == "exit")
			{
				std::cout << "операция добовления товара прервана!\n\n";
				sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newPrice))
			{
				count = std::stoi(newPrice);
				if (count > 222222)
				{
					std::cout << "ошибка максимального цены товара. Не более 222222 ед.\n"
						Sleep(1500);
				}
				else
				{
					break;
				}
				system("pause");
				if (exit)
				{
					std::cout << "Новый товар:" << newName << "\n";
					std::cout << "кол-во:" << count << "\n";
					std::cout << "Цена:" << price << "\n";
					std::cout << "Подведрить?\n1-да\n2-нет\nВвод:";
					Getline(choose);
					if (choose == "1")
					{
						storageSize++;
						unsigned int idArrTemp = new unsigned int[storageSize];
						std::string* nameArrTemp = new std::string[storageSize];
						unsigned int* coutArrTyemp = new unsigned int[storageSize];
						double* priceArrTemp = new double[storageSize].
						FillArray(idArrTemp, idArr, storageSize - 1);
						FillArray(nameArrTemp, nameArr, storageSize - 1);
						FillArray(icountArrTemp, countArr, storageSize - 1);
						FillArray(priceArrTemp, priceArr, storageSize - 1);
						
						idArrTemp[storageSize - 1] = storageSize;
						nameArrTemp[storageSize - 1] = newName;
						countArrTemp[storageSize - 1] = count;
						priceArrTemp[storageSize - 1] = price;

						std::swap(idArr, idArrTemp);
						std::swap(nameArr, nameArrTemp);
						std::swap(countArr, countArrTemp);
						std::swap(priceArr, priceArrTemp);
						delete[]idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
						std::cout << "Идёт подготовка";
						Sleep(2000);
						std::cout << "Товар успешно добавлен\n\n";
						Sleep(1500);
						break
					}
					else if (chose == "2")
					{
						std::cout << "Отмена\n\n";
						Sleep(1500);
						break
					}
					else
					{
						Err;
					}
				}
				if (exit == false)
				{
					break;
				}
			}
		}
	}
}
void ChangeName()
{
	while (true)
	{
		if (newName.Size() < +0 || newName.size >= 60)
		else if (IsNumber(chooseId)
		{
			id = std::stoi(chooseId) - 1;
			if (id || id < storageSize)
			{

			}
			std::cout << std::left << std::setw(25) << nameArr[id] << "-->" << newName << "\n\n";
			std::cout << "gдтвердить?\n1-да\n2-нет\nВвод:";
			Getline(choose);
			if (choose == "1")
			{
				nameArr[id] = newName;
				std::cout << "Смена имени завершина\n";
				sleep(2000);
				break;
			}
		}
	}
}
void RemoveStorageItem()
{
	while (true)
	{
		std::cout << "Введите колличество товара для списания";
		Getline(chooseCount) - 1;
		if (IsNumber(chooseId) && IsNumber(chooseCount)
		{
			id = std::stoi(chooseId);
			count = std::stoi(chooseCount);
			if (id < 0 || id > storageSize - 1 || cout < 0 || countArr[id])
			{
			std::cout << "некоректный id или колличество\\n";
			sleep(1500);
			if (choose == "1")
			}
				else if (choose = "2")
				{
					std::cout << "некоректный ввод\n";
					sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}

	}
	}
}
void ChangePrice()
{
	std::string chooseId,newPrice,choose;
	int id = 0;
	double prince = 0.0;
	unsigned int count = 0;
	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите id товара:";
		Getline(chooseId);
		if (choose == "exit")
		{
			std::cout << "отмена операции пополнения";
			break;
		}
		std::cout << "Введите новую цену товара:";
		Getline(newPrice);
		else if (IsNumber(chooseId) && IsNumber(newPrice)
		{
			id = std::stoi(chooseId);
			count = std::stoi(newPrice);
			if (id < 1 || id > storageSize || price < 0.0 || price > 2000.0)
			{
				std::cout << "некоректный id\n\n";
				std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[id] << "\t" << countArr[id] << "-->" << countAA[id] + count << "\n\n";
				std::cout << "подтвердить?\n 1-да 2-нет\nвывод:";
				Getline(choose);
				if (choose == "1")
				{
					countArr[id] += count;
				std:cout << "товар успешно пополнен";
					sleep(1500);
					system("cls");
					break
				}
				else if (choose = "2")
				{
					std::cout << "некоректный ввод\n";
					sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}

	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	start();
	delete()loginArr, passArr, statusArr;
	if (staticStorageCreate)
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
	Err()
}
inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');
}
inline void Err(int time = 2000)
{
	std::cout << "Некоректный вход";
	Sleep(time);
	system("cls");
}

template <typename Arr>
void FillArray(Arr *&dimanicArr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		dinamicArr[i] = staticArr[i];
	}
}
