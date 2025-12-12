#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <unordered_set>
#include "Storage.hp"
#include <chrono>
//Сласти
// учётные записи //
size_t userSize = 2;

size_t staffcount = 1;

std::string userStatus[3]{ "Супер админ", "админ", "сотрудник" };

std::string* loginArr = new std::string[userSize]{ "admin", "user" };

std::string* passArr = new std::string[userSize]{ "admin", "user" };


std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };

double* bonusArr = new double [userSize] {0.0, 0.0};

std::string currentStatus;

int currentId = 0;

void ShowUsers(int mode = 0);

void AddNewUser();

void DeleteUser()
{
	std::string chooseNumber, chekPass, choose;
	int userNumber = 0;
	int isAdmin = 0;
	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			if (userSize < 2)
			{
				std::cout << "нет пользователей для удаления";
				Sleep(2000);
				return;
			}
			ShowUsers();
			isAdmin = 1;
		}
		std::cout << "\nВыберите номер пользователя для смены пароля \"exit\"для выхода";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "отмена измения пароля!\n";
			Sleep(2000);
			break;
		}
		else if (IsNumber(choose))
		{
			userNumber = std::stoi(choose);
			if (userNumber < isAdmin || userNumber > userSize - 1)
			{
				std::cout << "пльзователь с таким номером не существует\n";
				Sleep(2000);
				break;
			}
			while (true)
			{
				system("cls");
				std::cout << "удаление пользователя:" << loginArr[userNumber] << "\n";
				std::cout << "для подтверждения введите пароль супер админа или \" "<< loginArr[userNumber] << "\n";
			}
		}
	}
}

void ChangePass()
{
	std::string newPass1, newPass2, choose;
	int userNumber = 0;
	int isAdmin = 0;

	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			ShowUsers(1);
			isAdmin = 0;
		}
		else
		{
			ShowUsers();
			isAdmin = 1;
		}
		std::cout << "\nВыберите номер пользователя для смены пароля \"exit\" для выхода";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "отмена измения пароля!\n";
			Sleep(2000);
			break;
		}
		else if (userNumber < isAdmin || userNumber > userSize - 1)
		{
			std::cout << "Пользователь с таким номером не существует\n";
			Sleep(2000);
		}
		else
		{
			while (true)
			{
				system("cls");
				std::cout << "Введите новый пароль для пользлвателя" << loginArr[userNumber] << ":";
				Getline(newPass1);
				std::cout << "Подтвердите пароль для пользователя" << loginArr[userNumber] << ":";
				Getline(newPass2);
				if (ChekPass(newPass1) && ChekPass(newPass2) && newPass1 == newPass2)
				{
					passArr[userNumber] == newPass1;
					std::cout << "успех\n";
					Sleep(1500);
					break;
				}
				else
				{
					std::cout << "повторите попытку\n";
					Sleep(2000);
				}
				else 
				{
					Err;
				}
			}
		}
	}
}

//конец//
//склад
size_t storageSize = 0;

bool staticStoradeCreated = false;

int* idArr;

unsigned int* coutArr;

double* priceArr;

std::string* nameArr;

void CreateStorage();

void ShowStorage(int mode);

template <typename Arr>


//конец склада
// служба
void start();

bool Login();

void ShowSuperAdminMenu();

inline void Getline(std::string& str);

inline void Err(int time = 1500);

void AddStorageItem();

void AddNewItem();

void ChangePrice();

void ChangeName();

bool CheakPack()
{
	std::unordered_set<char> specialSymbols;
	for (char i = 'A'; i <= 'Z'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char i = 'a'; i <= '-'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char symb : str)
	{
		if (!specialSymbols.count(symb))
		{
			std::wcout << "Некоректные символы в логине\n\n";
			Sleep(2000);
			return(false);
		}
	}
	return true;
}

void DeleteItem();

void ShowUsers(int mode);

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

bool logout();

void ShowIncome();
//конец службы
//продажи
size_t chekSize = 0;

int* idArrChack;

std::string* nameArrChak;

unsigned int* countArrChak;

double* priceArrChak;

double* totalpriceArrChak;

double cash = 300 + rand() % 2000;

double cashIncome = 0.0;

double bankIncome = 0.0;

void Selling();

void CheckArrAppend();

void PrintCheck();

void StorageController();

//конец продаж
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	start();
	delete[]loginArr;
	delete[]passArr;
	delete[]statusArr;
	if (staticStoradeCreated)
	{
		delete[]idArr;
		delete[]nameArr;
		delete[]coutArr;
		delete[]priceArr;
	}
	return 0;
}

bool logout()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "для подтверждает выхода введите свой пароль или \"exit\" для возврата в меню:";
		Getline(choose);
		if (choose == "exit")
		{
			system("cls");
			return false;
		}
		else if (choose == passArr[currentId - 1] || choose == passArr[0])
		{
			system("cls");
			return true;
		}
		else
		{
			Err;
		}
	}
}

void PrintCheck()
{
	std::cout < "Id:\t" << std::left << std::setw(20) << "название товара\t\t" << "Цены за ед.:\t" << "кол-во:\t" << "Итого:\n";
	for (size_t i = 0; i < storageSize; i++)
	{
		std::cout << i + 1 << idArrCheck[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i] << "\t" << coutArrCheck[i] << "\t\t" << priceArrCheck[i] << "\t" << totalPriceArrCheck[i] << "\n";
	}
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
	coutArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];
	staticStoradeCreated = true;
	FillArray(idArr, id, storageSize);
	FillArray(priceArr, price, storageSize);
	FillArray(coutArr, count, storageSize);
	FillArray(nameArr, name, storageSize);
}

void ShowStorage(int mode)
{
	system("cls");
	std::cout << "Id товара:\t" << std::left << std::setw(20) << "название товара\t\t" << "Цены:\t" << "кол-во:\n";
	for (size_t i = 0; i < storageSize; i++)
	{
		std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << coutArr[i] << "\n";
		else if (mode == 1)
		{
			std::invalid_argument("StotageMode Error")
		}
		else if (mode == 2)
		{

		}
	}
}

bool Login()
{
	for (size_t i = 0; i < userSize; i++)
	{
		if (str == loginArr[i])
		{
			std::cout << "Такой логин уже есть";
		}
	}
}

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

		if (choose == "1" && storageSize > 0)
		{
			AddNewItem();
		}
		if (choose == "2" && storageSize > 0)
		{

		}
		if (choose == "3" && storageSize > 0)
		{

		}
		if (choose == "4" && storageSize > 0)
		{

		}
		if (choose == "5" && storageSize > 0)
		{
		}
		if (choose == "6")
		{

		}
		if (choose == "7")
		{
			void ChangeUsers();
		}

		if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			if (storageSize <= 0)
			{

			}
			Err();
		}
	}
}

void RemoveStorageItem();

bool IsNumber(const std::string& str);

bool ContainsSymbools(const std::string& atr)
{
	std::unordered_set<char> specialSymbols;
	for (char i = 'A'; i <= 'Z'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char symb : str)
	{
		if (!specialSymbols.count(symb))
		{
			std::wcout << "Некоректные символы в логине\n\n";
			Sleep(2000);
			return(false);
		}
	}
	return true;
}

inline void Getline(std::string& str);

inline void Err(int time = 2000);

void Changelogin()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - добавить нового пользователя\n";
		std::cout << "2 - изменить пароль пользователя\n";
		std::cout << "3 - удалить пользователя\n";
		std::cout << "0 - выйти из редактора\n";
		std::cout << "ввод:\n";
		if (choose == "1")
		{

		}
		if (choose == "2" && storageSize > 0)
		{
			ShowUsers();
		}
		if (choose == "3" && storageSize > 0)
		{

		}
		if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			if (choose == "exit");
			Err;
		}
	}
}

void AddNewUser()
{
	std::string newlogin, newPass, newRole, choose;
	bool exit;
	while (true)
	{
		system("cls");
		std::cout << "Создание нового пользователя!\n\n";
		std::cout << "Введите логин нового пользователя:";
		Getline(newlogin);
		if (Changelogin(newlogin))
		{
            break;
		}

	}
	while (exit)
	{
		exit = true;
		while (true)
		{
			system("cls");

			std::wcout << "\t Создание нового пользователя";
			FillArray(idArrCheckTemp, idArrCheck, checkSize - 1);
			FillArray(nameArrCheckTemp, nameArrCheck, checkSize - 1);
			FillArray(countArrCheckTemp, countArrCheck, checkSize - 1);
			FillArray(priceArrCheckTemp, priceArrCheck, checkSize - 1);
			FillArray(totalPriceArrCheckTemp, totalPriceArrCheck, checkSize - 1);

			FillArray(idArr, id, storageSize);
			FillArray(priceArr, price, storageSize);
			FillArray(coutArr, cout, storageSize);
			FillArray(nameArr, name, storageSize);

			std::swap(idArrCheckTemp, idArrCheck);
			std::swap(nameArrCheckTemp, nameArrCheck);
			std::swap(countArrCheckTemp, countArrCheck);
			std::swap(priceArrCheckTemp, priceArrCheck);
			std::swap(totalPriceArrCheckTemp, totalPriceArrCheck);
		}
	}
}

bool ChakPass()
{
	std::unordered_set<char> specialSymbols;
	std::unordered_set<char> passSymbols('!', '0', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '/', '?', '|', '\\', '\=');
	int sybolsCount = 3;
	for (char i = 'a'; i <= 'z'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char symb : str)
	{
		if (!specialSymbols.count(symb))
		{
			std::wcout << "Некоректные символы в логине\n\n";
			Sleep(2000);
			return(false);
		}
	}
	for (char : str)
	{
		if (!passSymbols.count(symb))
		{
			SymbolsCount++;
			if (SymbolsCount == maxSymbolsCount)
			{
				return true;
			}
		}
	}
	std::wcout << "Требуется 3 специальных символа";
	Sleep(2000);
	return false;
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

void DeleteItem()
{
	std::string chooseId, choose;
	unsigned int id = 0;
	while (true)
	{
		if (IsNumber(chooseId))
		{
			if (id < 0 || id > storageSize - 1)
			{
			else
			{
				if (choose == "1")
				{
					std::string* nameArrTemp = new std::string[storageSize];
					unsigned int* countArrTemp = new unsigned int[storageSize];
					double* priceArrTemp = new double[storageSize];
					for (size_t i = 0, c = 0; i < storageSize; i++, c++)
					{
						if (id == c)
						{
							c++;
						}
						idArrTemp[i] = i + 1;
						nameArrTemp[i] = nameArr[c];
						countArrTemp[i] = coutArr[c];
						priceArrTemp[i] = priceArr[c];

						std::swap(idArr, idArrTemp);
						std::swap(nameArr, nameArrTemp);
						std::swap(coutArr, countArrTemp);
						std::swap(priceArr, priceArrTemp);
						delete[]idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
						std::cout << "Идёт подготовка";
						Sleep(2000);
						std::cout << "Товар успешно удалён\n\n";
						Sleep(1500);
						break;
					}
				}
			}
			}
		}
		
	}
}

void Selling()
{
	std::string chooseid, chooseCount;
	unsigned int id = 0, count = 0, index = -1, isFrist = false;
	double totalSum = 0.0;
	while (true)
	{
		ShowStorage();
		std::cout << "Введите ID товара для покупки или \"exit\" для завершения покупки:";
		Getline(chooseid);
		if (chooseid == "exit");
		{
			if (isFrist == false)
			{
				std::cout << "выход без покупок";
				Sleep(2000);
				break;
			}
			break;
		}
		PrintCheck();
		std::cout << "\nПодвердить покупку?\n 1-да\n 2-добавить ещё товар\n";
		if (IsNumber(chooseid))
		{
			id = std::stoi(chooseid) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "ошибка ID";
				Sleep(2000);
				continue;
			}
		}
		if (chooseCount == "exit")
		{
			std::cout << "Введите кол-во товара или \"exit для выбора другого товара\":";
			Getline(chooseCount);
			std::cout << "Отмена покупики" << nameArr[id] << "\n";
			Sleep(2000);
			continue;
		}
		if (IsNumber(chooseCount))
		{
			count = std::stoi(chooseCount);
			if (count < 0 || count > storageSize - 1)
			{
				std::cout << "ошибка ID";
				Sleep(2000);
				continue;
			}
			else
			{
				Err();
				continue;
			}
			CheckArrAppend();
			index++;
			idArrCheck[index] = idArr[id];
			nameArrCheck[index] = nameArr[id];
			priceArrCheck[index] = priceArr[id];
			countArrCheck[index] = count;
			totalPriceArrCheck[index] = count * priceArr[id];

			coutArr[id] - count;
			std::cout << "товар добавлен в чек\n\n";
			isFrist = true;
			Sleep(1000);
		}
	}
}

void StorageController()
{

}

void CheckArrAppend()
{
	checkSize++;
	int* idArrCheckTemp = new int[checkSize];
	std::string* nameArrCheckTemp = new std::string[checkSize];
	unsigned int* countArrCheckTemp = new unsigned int[checkSize];
	double* priceArrCheckTemp = new double[checkSize];
	double* totalPriceArrCheckTemp = new double[chekSize];

	FillArray(idArrCheckTemp, idArrCheck, checkSize - 1);
	FillArray(nameArrCheckTemp, nameArrCheck, checkSize - 1);
	FillArray(countArrCheckTemp, countArrCheck, checkSize - 1);
	FillArray(priceArrCheckTemp, priceArrCheck, checkSize - 1);
	FillArray(totalPriceArrCheckTemp, totalPriceArrCheck, checkSize - 1);

	std::swap(idArrCheckTemp, idArrCheck);
	std::swap(nameArrCheckTemp, nameArrCheck);
	std::swap(countArrCheckTemp, countArrCheck);
	std::swap(priceArrCheckTemp, priceArrCheck);
	std::swap(totalPriceArrCheckTemp, totalPriceArrCheck);
}

void ShowUsers(int mode)
{
	std::cout << "\t" << std::left << std::setw(10) << "Логин:\t" << "Пароль:\t" << "Роль:\n";
	for (size_t i = 1; i < userSize; i++)
	{
		std::cout << i << "\t" << std::left << std::setw(1) << loginArr[i] << "\t\t" << passArr[1] << "\t" << statusArr[i] << "\n";
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
		if (chooseId == "exit")
		{
			std::cout << "отмена операции пополнения";
			break;
		}
		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			std::cout << "Введите колличество товара для его пополнения:";
			Getline(chooseCount);
			id = std::stoi(chooseId);
			count = std::stoi(chooseCount);
			if (id < 1 || id > storageSize || count < 0 || count > 199)
			{
				std::cout << "некоректный id\n\n";
				std::cout << idArr[id] << "\t" << std::left << std::setw(25) << nameArr[id] << "\t" << coutArr[id] << "-->" << coutArr[id] + count << "\n\n";
				std::cout << "подтвердить?\n 1-да 2-нет\nвывод:";
				Getline(choose);
				if (choose == "1")
				{
					coutArr[id] += count;
				std::cout << "товар успешно пополнен";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose = "2")
				{
					std::cout << "некоректный ввод\n";
					Sleep(1500);
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
	while (true)
	{
		system("cls");
		std::cout << "\t добавление нового товара!\n\nВведите\"exit\" для прекращения операции";
		std::cout << "Введите название нового товара:";
		Getline(newName);
		if (newName == "exit")
		{
			std::cout << "операция добовления товара прервана";
			Sleep(1500);
			break;
		}
		if (newName.size() <= 0 || newName.size() >= 60)
		{
			std::cout << "ошибка имени. Максимальная длина 60 символов\n";
			Sleep(1500);
		}
		else
		{
			break;
		}
		while (exit)
		{
			system("cls");
			std::cout << "\t добавление нового товара!\n\nВведите\"exit\" для прекращения операции";
			std::cout << "Введите название нового товара:";
			Getline(newCount);
			if (newCount == "exit")
			{
				std::cout << "операция добовления товара прервана";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newCount))
			{
				count = std::stoi(newCount);
				if (count > 222)
				{
					std::cout << "ошибка максимального размера товара. Не более 222 ед.\n";
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
			system("cls");
			std::cout << "\t добавление нового товара!\n\nВведите\"exit\" для прекращения операции";
			std::cout << "Введите название нового товара:";
			Getline(newPrice);
			if (newPrice == "exit")
			{
				std::cout << "операция добовления товара прервана!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (IsNumber(newPrice))
			{
				count = std::stoi(newPrice);
				if (count > 222222)
				{
					std::cout << "ошибка максимального цены товара. Не более 222222 ед.\n";
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
						double* priceArrTemp = new double[storageSize];
						FillArray(idArrTemp, idArr, storageSize - 1);
						FillArray(nameArrTemp, nameArr, storageSize - 1);
						FillArray(coutArrTemp, coutArr, storageSize - 1);
						FillArray(priceArrTemp, priceArr, storageSize - 1);

						idArrTemp[storageSize - 1] = storageSize;
						nameArrTemp[storageSize - 1] = newName;
						coutArrTemp[storageSize - 1] = count;
						priceArrTemp[storageSize - 1] = price;

						std::swap(idArr, idArrTemp);
						std::swap(nameArr, nameArrTemp);
						std::swap(coutArr, coutArrTemp);
						std::swap(priceArr, priceArrTemp);
						delete[]idArrTemp, nameArrTemp, coutArrTemp, priceArrTemp;
						std::cout << "Идёт подготовка";
						Sleep(2000);
						std::cout << "Товар успешно добавлен\n\n";
						Sleep(1500);
						break;
					}
					else if (choose == "2")
					{
						std::cout << "Отмена\n\n";
						Sleep(1500);
						break;
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
		{
		else if (IsNumber(chooseId)
		{
			id = std::stoi(chooseId) - 1;
			if (id || id < storageSize)
			{

			}
			std::cout << std::left << std::setw(25) << nameArr[id] << "-->" << newName << "\n\n";
				std::cout << "подтвердить ? \n1 - да\n2 - нет\nВвод:";
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
}

void ShowIncome()
{
	system("cls");
	std::cout << "текущая прибыль за смену\n\n";
	std::cout << "наличный расчёт:\n\n" << cashIcome << "\n";
	std::cout << "безналичный счёт:\n\n";
}

void RemoveStorageItem()
{
	while (true)
	{
		std::cout << "Введите колличество товара для списания";
		Getline(chooseCout) - 1;
		if (IsNumber(chooseId) && IsNumber(chooseCout))
		{
			id = std::stoi(chooseId);
			count = std::stoi(chooseCount);
			if (id < 0 || id > storageSize - 1 || cout < 0 || coutArr[id])
			{
				std::cout << "некоректный id или колличество\\n";
				Sleep(1500);
				if (choose == "1")
			}
			else if (choose = "2")
			{
				std::cout << "некоректный ввод\n";
				Sleep(1500);
			}
			else
			{
				Err();
			}
		}
	}

}

void ChangePrice()
{
	std::string chooseId, newPrice, choose;
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
		else if (IsNumber(chooseId) && IsNumber(newPrice)
		{
			std::cout << "Введите новую цену товара:";
			Getline(newPrice);
			id = std::stoi(chooseId);
			count = std::stoi(newPrice);

			if (id < 1 || id > storageSize || price < 0.0 || price > 2000.0)
			{
				std::cout << "некоректный id\n\n";
				std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[id] << "\t" << coutArr[id] << "-->" << coutArr[id] + count << "\n\n";
				std::cout << "подтвердить?\n 1-да 2-нет\nвывод:";
				Getline(choose);
				if (choose == "1")
				{
					coutArr[id] += count;
				std:cout << "товар успешно пополнен";
					Sleep(1500);
					system("cls");
					break
				}
				else if (choose = "2")
				{
					std::cout << "некоректный ввод\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}

	}
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
		std::cout << "Ведите логин:";
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

inline void Err(int time = 2000)
{
	std::cout << "Некоректный вход";
	Sleep(time);
	system("cls");
}

void FillArray(Arr*& dimanicArr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		template <typename Arr>
		dinamicArr[i] = staticArr[i];
	}
}
