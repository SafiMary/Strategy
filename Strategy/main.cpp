#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <memory>
#include <windows.h>
#include <algorithm>
#include <map>


//��������� ������ �����
class Stok
{
public:
	virtual ~Stok() {}
    virtual void addProduct() = 0;
    virtual void printProduct() = 0;
};

class Strategy
{
private:
    Stok* _stok;
 
public:
    Strategy(Stok* stok = nullptr) : _stok(stok)
    {
    }
    ~Strategy()
    {
        delete this->_stok;
    }
   
    void setStok(Stok* stok)
    {
        delete this->_stok;
        this->_stok = stok;
    }
    
    void BusinessLogistic() const
    {
        std::cout << "���������� �� ���������� ����\n";
        _stok->addProduct();
        std::cout << "������ ������: \n";
        _stok->printProduct();
    }
};

class SmallStok : public Stok
{
public:
    void addProduct() override {
        std::string name;
        std::cout << "������� ������������ �����" << std::endl;
        std::cin >> name;
        _Product.push_back(name);
    }
    void printProduct() override {
        for (auto& el : _Product) {
            std::cout << el << " ";
        }
    }
private:
    std::vector <std::string> _Product;
};
class BigStok : public Stok
{
    void addProduct() override {
        std::string name;
        std::cout << "������� ������������ �����" << std::endl;
        std::cin >> name;
        _Product.push_back(name);
    }
    void printProduct() override {
        for (auto& el : _Product) {
            std::cout << el << std::endl;
            std::cout << '\n';
        }
    }
private:
    std::vector <std::string> _Product;
};

void ClientCode()
{
    Strategy* strategy = new Strategy(new SmallStok);
    int input;
    std::cout << "�������� �����,  �� ������� ���������� ��������� ����\n";
    std::cout << "1. ����������� ���� �� ��������� �����\n";
    std::cout << "2. ����������� ���� �� ������� �����\n";
    std::cin >> input;
    switch (input){
    case 1:
    strategy->BusinessLogistic();
    std::cout << " ���������� ���� �� ��������� �����\n";
    delete strategy;
    std::cout << "\n"; break;
    case 2:
    strategy->setStok(new BigStok);
    strategy->BusinessLogistic();
    std::cout << " ���������� ���� �� ������� �����\n";
    delete strategy;
    std::cout << "\n"; break;
    default:
        std::cout << "3. ������ �����\n";
        break;
    }
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    ClientCode();






}