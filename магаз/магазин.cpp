#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <unordered_set>
#include <chrono>

//Сласти

// учётные записи //
size_t userSize = 2;

size_t staffcount = 1;

std::string userStatus[3]{ "Супер админ", "админ", "сотрудник" };
std::string* loginArr = new std::string[userSize]{ "admin", "user" };
std::string* passArr = new std::string[userSize]{ "admin", "user" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
double* awardArr = new double[userSize] {0.0, 0.0};
unsigned int* userIdArr = new unsigned int[userSize] {1, 2, 3};
unsigned int* currentId = 0;
double* bonusArr = new double [userSize] {0.0, 0.0};
std::string currentStatus;
int currentId = 0;

void ChangeAccounts();
void ShowUsers(int mode = 0);
void AddNewUser();
void ChangePass();
void ChangeAccounts()
{
	while (true)
	{
		if (choose == "1")
		{
		else if (choose == "2" && userSize > 1)
		{
			ShowUsers();
		}
		else if (choose == "3" && userSize > 1)
		{
			ChangePass();
		}
		else if (choose == "4" && userSize > 1)
		{
			DeleteUser();
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			if (userSize <= 1)
			{
				std::cout << "Пльзователь не найден\n";
				Sleep(1500);
				break;
			}
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
		else if (IsNumber(choose))
		{
			if (userNumber < isAdmin || userNumber > userSize - 1)
			{
				Sleep(1500);
			}
			else
			{
				while (true)
				{
					system("cls");
					if (currentStatus == userStatus[0])
					{
						ShowUsers(1);
						isAdmin = 0;
					}
				}
				std::cout << "Введите новый пароль для пользлвателя" << loginArr[userNumber] << ":";
				Getline(newPass1);
				std::cout << "Подтвердите пароль для пользователя" << loginArr[userNumber] << ":";
				Getline(newPass2);
				if (CheckPass(newPass1) && CheckPass(newPass2) && newPass1 == newPass2)
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
					Err;
				}
			}
		}
	}
}
void DeleteUser();
//конец
//склад
size_t storageSize = 0;
size_t maxItemSize = 299;
bool staticStoradeCreated = false;

unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* coutArr = nullptr;
double* priceArr = nullptr;

bool isStoradeCreated = false;

void CreateStorage();
void ShowStorage(int mode);

template <typename Arr>
void FillArray(Arr* dynamicArr, Arr* staticArr, size_t size);
//конец склада

// служба
void start();
bool Login();
void ShowSuperAdminMenu();

std::unordered_set <char> specialSymbols;
std::unordered_set <char> passSymbols;

bool isPassSetCreated = false;
bool isSetCreated = false;

void AddStorageItem();
void ShowUserMenu();
void ShowIncome();
void SetSpecialSymbols();
void SetPassSymbols();

bool CheckPass(const std::string & str);
bool CheckLogin(const std::string & str);
bool IsNumber(const std::string & str);

inline void Getline(std::string & str);
inline void Err(int time = 1500);

void ChangePrice();
void ChangeName();
bool CheckPack(const std::string& str)
{
	std::unordered_set <char> specialSymbols;
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
		if (choose == "2" && storageSize > 0)
		{
			ChangeName();
		}
		if (choose == "3" && storageSize > 0)
		{
			DeleteItem();
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
				std::cout << "Склад пустой!\n";
			}
			Err;
		}
	}
}

bool logout();

void ShowIncome();
//конец службы
//продажи
size_t chekSize = 0;

int* idArrCheck;

std::string* nameArrCheck;

unsigned int* countArrCheck;

double* priceArrCheck;
double* totalpriceArrCheck;
double cash = 300 + rand() % 2000;
double cashIncome = 0.0;
double bankIncome = 0.0;

void Selling();
void CheckArrAppend();
void PrintCheck(double& totalSum);
void StorageController(const int& itemId, bool remove = true);

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
	delete[]salesArr;
	delete[]userIdArr;

	if (isStoradeCreated)
	{
	    delete[]idArr;
		delete[]nameArr;
		delete[]coutArr;
		delete[]priceArr;
	}
	return 0;
}

void Selling()
{
	std::string chooseId, chooseCount, choose, chooseCash;
	unsigned int id = 0, count = 0, index = -1,
		double totalSum = 0.0;
	bool isFrist = false;
	checkSize = 0;
	while (true)
	{
		ShowStorage();
		std::cout << "Введите ID товара для покупки или \"exit\" для завершения покупки:";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			if (isFrist == false)
			{
				std::cout << "выход без покупок";
				Sleep(2000);
				break;
			}
			if (IsNumber(chooseId))
			{
				id = std::stoi(chooseId) - 1;
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
				CheckArrAppend();
				index++;
				idArrCheck[index] = idArr[id];
				nameArrCheck[index] = nameArr[id];
				priceArrCheck[index] = priceArr[id];
				countArrCheck[index] = count;
				totalPriceArrCheck[index] = count * priceArr[id];
				coutArr[id] = count;

				std::cout << "товар добавлен в чек\n\n";
				isFrist = true;
				Sleep(1000);
			}
			if (choose == "1")
			{
				PrintCheck();
				std::cout << "\nПодвердить покупку?\n 1-да\n 2-добавить ещё товар\n3-отмена\nВвод:\n";
				Getline(choose);
				while (true)
				{
					system("cls");
					std::cout << "Выберите способ оплаты\n1-Наличными\n2безнал\n3-отмена\nВвод:";
					Getline(choose);
					if (choose == "1")
					{
						std::cout << "Введите кол-во наличных";
						Getline(chooseCash);
						if (IsNumber(chooseCash))
						{
							if
							{
								money = std::stod(chooseCash);
								if (money < totalSum)
								{
									std::cout << "Недостаточно средств!\n";
									Sleep(1500);
									continue;
								}
								else if (money - totalSum > cash)
								{
									std::cout << "Нет возможности  дать сдачу. Повторите попытку\n";
									Sleep(1500);
									continue;
								}
								else
								{
									std::cout << "Ваши" << money << "\n";
									Sleep(400);
									std::cout << "оплата прошла успешно";
								}
							else
							{
								awardArr[currentId] += totalSum;
								system("cls");
								break;
							}
							}
						}
					else if (choose = "2")
					{
						std::cout << "Приложите карту\n\n";
						if (rand() % 10 <= 2)
						{
							std::cout << "\nСоединение не установлено. Повторите попытку\n";
						}
						else
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::wcout << i + 1 << "\t";
								Sleep(1000);
							}
							std::cout << "Ваши" << money << "\n";
							Sleep(400);
							std::cout << "оплата прошла успешно";
							bankIcome += totakSum;
							awardArr[currentId] += totalSum;
						}
						else if (choose == "3")
						{
							std::cout << "отмена покупки!\n";
							StorageReturner();
							Sleep(1500);
							system("cls");
							return;
						}
						else
						{
							delete[]idArrCheck;
							delete[]nameArrCheck;
							delete[]countArrCheck;
							delete[]priceArrCheck;
							delete[]totalPriceArrCheck;
							system("cls");
							Err();
							continue;
						}
						}
						else
						{
							Err;
							continue;
						}
					}
					else if (choose = "Den" || choose = "den")
					{
						std::cout << "Ден оплатил вам чек.всего доброго!\n";
						Sleep(1500);
					}
					else
					{
						Err;
					}
				}
			}
		}
	}
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

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[staticSize]
	{
		"Земфир: оболочная нежность", "Пражский торт: Вечер в праге", "сахарное печение: хрустальные грёзы", "пряники: медово-горчичный"
	    "брани: Малиновый рассвет", "набор для приготовленния своего торта: Сладкий конструктор", "Жевательно-миндальное печенье-меренга: сибирская резина"
	    "Ассорти из изящных итальянских сладостей: Дольче Вита", "яркие леденцы: взрывная карамель", "шоколадки: грильяж в шоколаде", "Настройка \"Сласти\""
	};

	unsigned int count[staticSize]{ 20,12,65,34,21,8,32,43,23,6};
	double price[staticSize]{ 143.3,210.4,452.1,377.3,116.8,287.2,140.4,210.3,899.9,1500.0};

	storageSize = staticSize;

	idArr = new int[storageSize];
    nameArr = new std::string[storageSize];
    countArr = new unsigned int[storageSize];
	priceArr = new double[storageSize];

	staticStoradeCreated = true;

	FillArray(idArr, id, storageSize);
	FillArray(priceArr, price, storageSize);
	FillArray(countArr, count, storageSize);
	FillArray(nameArr, name, storageSize);
}
void ShowStorage(int mode)
{
	system("cls");
	if (mode == 0)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "название товара\t\t" << "Цена\t" << "Кол-во\n";
		for (size_t i = 0; i < storageSize; i++)
		{
		    std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\t" << coutArr[i] << "\n";
		}
		system("pause");
		system("cls");
	}
	else if (mode == 1)
	{
		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << coutArr[i] << "\n";
		}
	}
	else if (mode == 2)
	{
	    std::cout << "Id товара:\t" << std::left << std::setw(20) << "название товара\t\t" << "Цены:\t" << "кол-во:\n";
		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << coutArr[i] << "\n" << "\t" << priceArr[i] << "\n";
		}
	}
	else if (mode == 3)
	{
		std::cout << "Id:\t" << std::left << std::setw(25) << "название товара\t\t" << "\n";
		for (size_t i = 0; i, storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\n";
		}
	}
	else
	{
		std::cout << "StotageMode Error\n\n";
	}
}

void RemoveStorageItem();

bool ContainsSymbools(const std::string & str)
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
			std::cout << "Некоректные символы в логине\n\n";
			Sleep(2000);
			return(false);
		}
	}
	return true;
}

inline void Getline(std::string & str);
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
			DeleteUser();
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
void ShowUsers(int mode)
{
	if (mode == 0)
	{
		std::cout << "ID\t" << std::left << std::setw(12) << "Логин\t\t" << "Пароль\t\t\t" << "Роль\n";
		for (size_t i = 1; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(8) << loginArr[i] << "\t\t" << passArr[i] << "\t\t\t" << statusArr[i] << "\n";
		}
		Sleep(1500);
	}
	else if (mode == 1)
	{
		for (size_t i = 0; i < storageSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(8) << loginArr[i] << "\t" << passArr[i] << "\n";
		}
	}
}
void AddNewUser()
{
	std::string newlogin, newPass, newRole, choose;
	bool exit;
	while (true)
	{
		exit = true;
		while (true)
		{
			exit = true;
			while (true)
			{
				system("cls");
				std::cout << "Создание нового пользователя!\n\n";
				std::cout << "Выберите роль нового пользователя или \"exit\" для выхода";
				std::cout << "1 - Админ\n2-Сотрудник\nВвод:";
				Getline(newlogin);
				if (newlogin == "exit")
				{
					std::cout << "Создание нового пользователя прервано!\n\n";
					Sleep(1500);
					exit = false;
					break;
				}
				Getline(choose);
				if (choose == "1")
				{
					newRole = userStatus[1];
					break;
				}
				else if (choose == "2")
				{
					newRole = userStatus[2];
					break;
				}
				if (CheckLogin(newlogin))
				{
					break;
				}
				else
				{
					Err();
				}

			}
		}
		while (exit)
		{
			exit = true;
			while (true)
			{
				exit = true;
				while (exit)
				{
					system("cls");

					std::cout << "\tСоздание нового пользователя\t";
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

					if (choose = "1")
					{
						if (newRole == userStatus[2])
						{
							staffcount++;
						}
						userSize++;

						std::string* loginArrTemp = new std::string[userSize];
						std::string* passArrTemp = new std::string[userSize];
						std::string* statusArrTemp = new std::string[userSize];
						double* awardArrTemp = new double[userSize];
						unsigned int* userIdArrTemp = new unsigned int[userSize];

						FillArray(loginArrTemp, loginArr, userSize - 1);
						FillArray(passArrTemp, passArr, userSize - 1);
						FillArray(statusArrTemp, statusArr, userSize - 1);
						FillArray(awardArrTemp, awardArr, userSize - 1);
						FillArray(userIdArrTemp, userIdArr, userSize - 1);

						loginArrTemp[userSize - 1] = newlogin;
						passArrTemp[userSize - 1] = newPass;
						statusArrTemp[userSize - 1] = newRole;
						awardArrTemp[userSize - 1] = 0.0;
						userIdArrTemp[userSize - 1] = userSize;

						std::swap[loginArr, loginArrTemp];
						std::swap[passArr, passArrTemp];
						std::swap[statusArr, statusArrTemp];
						std::swap[awardArr, awardArrTemp];
						std::swap[userIdArr, userIdArrTemp];

						delete[]loginArrTemp;
						delete[]passArrTemp;
						delete[]statusArrTemp;
						delete[]awardArrTemp;
						delete[]userIdArrTemp;

						std::cout << "Идёт подготовка...";
						Sleep(2000);
						break;

					}
					else if (choose == "2")
					{
						std::cout << "отмена\n";
						Sleep(1500);
					}
					else
					{
						Err;
					}
				}
			}
		}
		while (exit)
		{
			std::cout << "Пользователь:" << newlogin << "\n";
			std::cout << "Пароль:" << newPass << "\n"; userSize++;
			std::cout << "Роль:" << newRole << "\n\n";
			std::cout << "Подтвердить?\n1-да\n2-нет\nВвод:";
			Getline(choose);
			if (choose == "1")
			{
				if (choose == "exit")
				{
				else if (IsNumber(choose))
				{
					while (true)
					{
						if (checkPass == "exit")
						{
							Sleep(1500);
							break;
						}
						else if (checkPass == pasArr[0])
						{
							if (statusArr[userNumber] == userStatus[2])
							{
								staffCout--;
							}
							userSize--;
							std::string* statusArrTemp = new std::string[userSize];
							std::string* passArrTemp = new std::string[userSize];
							std::string* statusArrTemp = new std::string[userSize];
							double* awardArrTemp = new double[userSize];
							unsigned int* userIdArrTemp = new unsigned int[userSize];

							for (size_t = 0, c = 0; i < userSize; i++, c++)
							{
								if (userNumber == с)
								{
									с++;
									loginArrTemp[i] = loginArr[c];
									passArrTemp[i] = pasArr[c];
									statusArrTemp[i] = statusArr[c];
									awardArrTemp[i] = awardArr[c];
									userIdArrTemp[i] = userIdArr[c];

									std::swap[loginArrTemp, loginArr];
									std::swap[passArrTemp, passArr];
									std::swap[statusArrTemp, statusArr];
									std::swap[awardArrTemp, awardArr];
									std::swap[userIdArrTemp, userIdArr];

									delete[]loginArrTemp;
									delete[]passArrTemp;
									delete[]statusArrTemp;
									delete[]awardArrTemp;
									delete[]userIdArrTemp;
									std::cout << "Идёт подготовка...";
									Sleep(2000);
									std::cout << "пользователь успешно удалён\n";
									Sleep(1500);
									break;
								}
							}
						}
					}
				}
				}
			}
			else if (choose == "2")
			{
				std::cout << "отмена\n";
				Sleep(1500);
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
void DeleteUser()
{
	std::string chooseNumber, checkPass, choose;
	int userNumber = 0;
	int isAdmin = 0;
	while (true)
	{
		if (choose = "exit")
		{
		else if (IsNumber(choose))
		{
			if (userNumber < isAdmin || userNumber > userSize - 1)
		    {
			   std::cout << "Пользователь с таким номером не существует\n";
			   Sleep(2000);
		    }
		}
		}
		while (true)
		{
			system("cls");
			if (currentStatus == userStatus[1] && statusArr[userNumber] != userStatus[2])
			{
				std::cout << "удаление пользователя:" << loginArr[userNumber] << "\n";
				std::cout << "для подтверждения введите пароль супер админа или \"exit\ для выхода" << loginArr[userNumber] << "\n";
				std::cout << "нельзя удалить администратора\n";
				Sleep(1500);
				break;
			}
			Getline(checkPass);
			if (checkPass == "exit")
			{
				std::cout << "отмена удаления" << loginArr[i] << "\n\n";
				Sleep(1500);
				break;
			}
			else if (checkPass == passArr[0])
			{
				//----
			}
			else
			{
				std::cout << "Некорректный пароль\n";
				Sleep(1500);
			}
			if (currentStatus == userStatus[0])
			{
				if (userSize < 2)
				{
					ShowUsers();
					isAdmin = 0;
					std::cout << "нет доступных пользователей для удаления";
					Sleep(2000);
					return;
				}
			}
			else if (currentStatus == userStatus[0])
				{
					ShowUsers();
					isAdmin = 1;
					std::cout << "\nВыберите номер пользователя для смены пароля \"exit\"для выхода";
					Getline(choose);
			if (choose == "exit")
			{
				std::cout << "отмена удаления пользователя!\n";
				Sleep(2000);
				break;
			}
				}
			}
	   }
	}
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
				Sleep(1500);
			}
			else
			{
				std::cout << "удаляемый товар:" << std::left << std::setw(25) << nameArr[id] << "\n\n";
				std::cout << "Подтвердить?\n1-да\n2-нет\nВвод:";
				Getline(choose);
				if (choose == "1")
				{
					storageSize--;
					unsigned int* idArrTemp = new unsigned int[storageSize];
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
				else if (choose == "2")
				{
					std::cout << "отмена операции удаления!\n";
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
void StorageController(const int& itemId, bool remove = true)
{

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
					Getline(chooseCount);
					if (chooseCount == "1")
					{
						coutArr[id] += count;
						std::cout << "товар успешно пополнен";
						Sleep(1500);
						system("cls");
						break;
					}
					else if (chooseCount = "2")
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
				if (exit)
				{
					system("pause");
					std::cout << "Новый товар:" << newName << "\n";
					std::cout << "кол-во:" << count << "\n";
					std::cout << "Цена:" << newPrice << "\n";
					std::cout << "Подведрить?\n1-да\n2-нет\nВвод:";
					Getline(choose);
					if (choose == "1")
					{
						storageSize++;
						unsigned int idArrTemp = new unsigned int[storageSize];
						std::string* nameArrTemp = new std::string[storageSize];
						unsigned int* countArrTyemp = new unsigned int[storageSize];
						double* priceArrTemp = new double[storageSize];

						FillArray(idArrTemp, idArr, storageSize - 1);
						FillArray(nameArrTemp, nameArr, storageSize - 1);
						FillArray(countArrTemp, coutArr, storageSize - 1);
						FillArray(priceArrTemp, priceArr, storageSize - 1);

						idArrTemp[storageSize - 1] = storageSize;
						nameArrTemp[storageSize - 1] = newName;
						countArrTemp[storageSize - 1] = count;
						priceArrTemp[storageSize - 1] = newPrice;

						std::swap(idArr, idArrTemp);
						std::swap(nameArr, nameArrTemp);
						std::swap(countArr, countArrTemp);
						std::swap(priceArr, priceArrTemp);
						delete[]idArrTemp;
						delete[]nameArrTemp;
						delete[]countArrTemp;
						delete[]priceArrTemp;
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
		if (newName.Size() < +0 || newName.Size >= 60)
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
				Sleep(2000);
				break;
			}
		}
		}
	}
}
void RemoveStorageItem()
{
	while (true)
	{
		std::cout << "Введите колличество товара для списания";
		Getline(chooseCout) - 1;
		if (IsNumber(chooseid) && IsNumber(chooseCout))
		{
			id = std::stoi(chooseId);
			count = std::stoi(chooseCount);
			if (id < 0 || id > storageSize - 1 || count < 0 || coutArr[id])
			{
				std::cout << "некоректный id или колличество\\n";
				Sleep(1500);
				if (choose == "1")
			}
			else if (choose = "2")
			{
				std::cout << "некоректный ввод\n";
				Sleep(1500);
				Err;
			}
		}
	}

}
void ChangePrice()
{
	std::string chooseId, newPrice, choose;
	int Id = 0;
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
			count = std::stoi(newPrice)

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
void CheckArrAppend()
{
	CheckSize++;
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

	delete[]idArrCheckTemp;
	delete[]nameArrCheckTemp;
	delete[]countArrCheckTemp;
	delete[]priceArrCheckTemp;
	delete[]totalPriceArrCheckTemp;
}
void PrintCheck(double& totalSum)
{
	std::cout < "Id:\t" << std::left << std::setw(20) << "название товара\t\t" << "Цены за ед.:\t" << "кол-во:\t" << "Итого:\n";
	for (size_t i = 0; i < storageSize; i++)
	{
		std::cout << i + 1 << idArrCheck[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i] << "\t" << coutArrCheck[i] << "\t\t" << priceArrCheck[i] << "\t" << totalPriceArrCheck[i] << "\n";
	}
}
void StorageReturner()
{
	for (size_t i = 0; i < checkSize; i++)
	{
		countArr[idArrCheck[i] - 1] += countArrCheck[i];
	}
	delete[]idArrCheck;
	delete[]nameArrCheck;
	delete[]countArrCheck;
	delete[]priceArrCheck;
	delete[]totalPriceArrCheck;

	idArrCheck = nullptr;
	nameArrCheck = nullptr;
	countArrCheck = nullptr;
	princeArrCheck = nullptr;
	totalPriceArrCheck = nullptr;
	CheckSize = 0;
}
void start()
{
	std::cout << "\n\n\n\t\t\tСласти\n\n\n";
	std::string choose;
	if (Login())
	{
		if (currentStatus == userStatus[0])
		{
			while (true)
			{
				std::cout << "выберите склад\1-готовый\n2-создать новый склад\nВвод:";
				Getline(choose);
				if (choose = "1")
				{
					if
					{
						CreateStorage();
					}
					system("cls");
					ShowSupreAdminMenu();
					break;
				}
				else if (choose == "2")
				{
					// новый склад с нуля
					break;
				}
				else
				{
					Err();
				}
			}
		}
		else if (currentStatus == userStatus[1])
		{
			if (staticStorageSteated == false)
			{
				CreateStorage();
			}
			// создание склада и открытие магазина
		}
		else if (currentStatus == userStatus[2])
		{
			if (staticStorageSteated == false)
			{
				CreateStorage();
			}
			// создание склада и открытие магазина
		}
		else
		{
			system("cls");
			std::cout << "Введите пароль за смену:";
			Getline(choose);
			if (choose == passArr[0])
			{
				system("cls");
				std::cout << "Итоговая приболь за смену:" << cashIcome + bankIcome << "рублей";
				std::cout << "Завершение работы магазина\n\n";
			}
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
		if (login == "exit" && pass == "exit")
		{
			currentStatus = "";
			return false;
		}
		if (login == loginArr[0] && pass == passArr[0])
		{
			std::cout << "пользователь:" << loginArr[0] << "\n\nВошёд в систему!\n";
			std::cout << "Ваш статус:" << statusArr[0] << "\n\n";
			currentStatus = statusArr[0];
			return true;
		}
		for (size_t i = 1; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				std::cout << "Пользователь:" << loginArr[i] << "\n\n Добро пожаловать! Вы вошёли в систему!\n";
				std::cout << "Ваш статус:" << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				return true;
			}
		}
		Err();
	}
}

void ShowSuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать товар\n";
		std::cout << "5 - изменить цену\n";
		std::cout << "6 - редактировать склад\n";
		std::cout << "7 - редактировать персонал\n";
		std::cout << "8 - отчёт о приболи\n";
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
			ChangeUsers();
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
bool CheckLogin(const std::string& str)
{
	if (str.empty() || str.size() >= 20)
	{
		std::cout << "недопустимая для чего-то";
	}
	std::unordered_set<char> specialSymbols;
	for (char i = 'A'; i <= 'Z'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char i = 'a'; i <= 'z'; i++)
	{

	}
}
bool CheckPass(const std::string& str)
{

	if (str.size() < 5 || str.size() > 19)
	{
		std::cout << "Недопустимая длина пароля! от 5 до 19\n";
		Sleep(1500);
		return false;
	}
	int numCount = 0, symCount = 0;
	std::unordered_set<char> specialSymbols{ '!', '0', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '/', '?', '|', '\\', '\=' };
	int symbolsCount = 0, maxSymbolsCount;
	for (char i = 'A'; i <= 'Z'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char sym : str)
	{
		if (!passSymbols.count(sym))
		{
			std::cout << "Некоректные символы в логине\n\n";
			Sleep(2000);
			return(false);
			symbolsCount++;
				if (symbolsCount == maxSymbolsCount)
				{
					return true;
				}
		}
		return true;
	}
	std::cout << "Требуется 3 специальных символа";
	Sleep(2000);
	return false;
}

void ShowIncome()
{
	system("cls");
	std::cout << "текущая прибыль за смену\n\n";
	std::cout << "наличный расчёт:" << cashIncome << "\n";
	std::cout << "безналичный счёт:" << bankIncome << "\n";
	std::cout << "Итого:" << cashIncome + bankIncome << "\n\n";
	std::cout << "Сумма ваших продаж:" << awardArr[curretId] << "\n";
}
void SetSpecialSymbols()
{
	for (char i = '0'; i <= '9'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char i = 'A'; i <= 'Z'; i++)
	{
		specialSymbols.insert(i);
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		specialSymbols.insert(i);
	}
	isSetCreated = true;
}

inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');
}

inline void Err(int time = 2000)
{
	std::cout << "Некоректный вход\n";
	Sleep(time);
	system("cls");
}

template<typename Arr>
void FillArray(Arr* dynamicArr, Arr* staticArr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}
