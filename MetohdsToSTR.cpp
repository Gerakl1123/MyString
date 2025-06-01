#include "MetohdsToSTR.h"


MyString MTSTR::CatLen(MyString& other, MyString& other2)
{
	MyString Cat;
	size_t len = strlen(other2.ch) + strlen(other.ch) + 1;

	Cat.ch = new char[len];

	strcpy_s(Cat.ch, len, other.ch);
	strcat_s(Cat.ch, len, other2.ch);

	return Cat;

}

char* MTSTR::push_end(MyString& item,char symbol)
{

	 size_t new_s = item.SizeA + 1;
	 char* newCh = new char[new_s + 1];
	 strcpy_s(newCh, new_s + 1,item.ch);

	 newCh[item.SizeA] = symbol;
	 newCh[new_s] = '\0';

	 delete[] item.ch;

	 item.ch = newCh;
	 item.SizeA = new_s;
	 
	return item.ch;
}

char* MTSTR::push_begin(MyString& item, char symbol)
{
	size_t new_s = item.SizeA + 1;
	char* newCh = new char[new_s + 1];

	for (size_t i = 0; i < new_s; i++)
	{
		newCh[i+1] = item.ch[i];
	}
	
	newCh[0] = symbol;
	newCh[new_s] = '\0';
	delete[] item.ch;

	item.ch = newCh;
	item.SizeA = new_s;

	return item.ch;
}

char* MTSTR::push_insert(MyString& item, char symbol,short index)
{
	size_t new_s = item.SizeA + 1;
	char* newCh = new char[new_s + 1];

	for (size_t i = 0; i < index; ++i) {
		newCh[i] = item.ch[i];
	}

	for (size_t i = index ; i < item.SizeA; ++i) {
		newCh[i + 1] = item.ch[i];
	}

	newCh[new_s] = '\0';

	delete[] item.ch;

	item.ch = newCh;
	item.SizeA = new_s;

	return item.ch;
}

char* MTSTR::erase(MyString& item, short index)
{
	
	size_t new_s = item.SizeA - 1;
	char* newCh = new char[new_s + 1];

	for (size_t i = 0; i < index; ++i) {
		newCh[i] = item.ch[i];
	}

	for (size_t i = index + 1; i < item.SizeA; ++i) {
		newCh[i - 1] = item.ch[i];
	}

	newCh[new_s] = '\0';

	delete[] item.ch;

	item.ch = newCh;
	item.SizeA = new_s;

	return item.ch;
}

void MTSTR::addToFile(MyString& item, const std::string& fileName)
{
	std::ofstream file(fileName,std::ios::app);

	try
	{
		if (!file.is_open())
		{
			throw std::ios_base::failure("Failed to open file");
		}
		file << item.ch << std::endl;
		file.close();
		std::cout << "Data written to file successfully." << std::endl;

	}
	catch (const std::ios_base::failure& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return;
	}
	

}

std::string MTSTR::readToFile(MyString& item, const std::string& fileName)
{
	std::ifstream file(fileName);
	std::string line;
	try
	{
		while (std::getline(file,line))
		{
			std::cout << line << "\n";
		}
	}
	catch (const std::ios::failure& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return "";
	}

	return line;
}

