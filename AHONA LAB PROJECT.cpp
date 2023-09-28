
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class CPU;
class Motherboard;
class RAM;
class SSD;
class PCConfig;

class CPU {
  public:
    CPU() {}
    CPU(std::string name, double price) : name(name), price(price) {}
    std::string getName() { return name; }
    double getPrice() { return price; }
    void showInfo() {
        std::cout << "Model: " << name << "\n";
        std::cout << "Price: " << price << " BDT\n";
    }
    friend void AddCPUFromDummyFile();
  private:
    std::string name, socketType;
    double price;
};

class Motherboard {
  public:
    Motherboard() {}
    Motherboard(std::string name, double price) : name(name), price(price) {}
    std::string getName() { return name; }
    double getPrice() { return price; }
    void showInfo()
    {
        std::cout << "Model: " << name << "\n";
        std::cout << "Price: " << price << " BDT\n";
    }
    friend void AddMotherboardFromDummyFile();
  private:
    std::string name;
    double price;
};

class RAM {
  public:
    RAM() {}
    RAM(std::string name, int capacity, double price)
     : name(name), capacity(capacity), price(price) {}
    std::string getName() { return name; }
    int getCapacity() { return capacity; }
    double getPrice() { return price; }
    void showInfo() {
        std::cout << "Model: " << name << "\n";
        std::cout << "Capacity: " << capacity << " GB\n";
        std::cout << "Price: " << price << " BDT\n";
    }
    friend void AddRAMFromDummyFile();
  private:
    std::string name;
    int capacity;
    double price;
};

class SSD {
  public:
    SSD() {}
    SSD(std::string name, int capacity, double price)
     : name(name), capacity(capacity), price(price) {}
    std::string getName() { return name; }
    double getCapacity() { return capacity; }
    int getPrice() { return price; }
    void showInfo() {
        std::cout << "Model: " << name << "\n";
        std::cout << "Capacity: " << capacity << " GB\n";
        std::cout << "Price: " << price << " BDT\n";
    }
    friend void AddSSDFromDummyFile();
  private:
    std::string name;
    int capacity;
    double price;
};


class PCConfig {
  public:
    void addCPU(CPU& cpu) {
        cpuIsSelected = true;
        selectedCPU = cpu;
    }
    void addMotherboard(Motherboard& motherboard) {
        motherboardIsSelected = true;
        selectedMotherboard = motherboard;
    }
    void addRAM(RAM& ram, int quantity) {
        for (int i = 0; i < quantity; i++) {
            selectedRAM[numRAMs] = ram;
            numRAMs++;
        }
    }
    int getNumRAMs() { return numRAMs; }
    void addSSD(SSD& ssd, int quantity) {
        for (int i = 0; i < quantity; i++) {
            selectedSSD[numSSDs] = ssd;
            numSSDs++;
        }
    }
    int getNumSSDs() { return numSSDs; }
    void showInfo() {
        if (cpuIsSelected == true) {
            std::cout << "CPU: \n";
            selectedCPU.showInfo();
        }
        if (motherboardIsSelected == true) {
            std::cout << "Motherboard: \n";
            selectedMotherboard.showInfo();
        }
        if (numRAMs > 0) {
            std::cout << "RAM: \n";
            for (int i = 0; i < numRAMs; ++i) {
                selectedRAM[i].showInfo();
            }
        }
        if (numSSDs > 0) {
            std::cout << "SSD: \n";
            for (int i = 0; i < numSSDs; ++i) {
                selectedSSD[i].showInfo();
            }
        }
    }

    friend double CalculateTotalCost(PCConfig&);
  private:
    bool cpuIsSelected;
    CPU selectedCPU;
    bool motherboardIsSelected;
    Motherboard selectedMotherboard;
    RAM selectedRAM[100];
    SSD selectedSSD[100];
    int numRAMs = 0;
    int numSSDs = 0;
};

PCConfig customerConfig;

int cpuInRep, motherboardInRep, ramInRep, ssdInRep;
CPU cpuRepository[10];
Motherboard motherboardRepository[10];
RAM ramRepository[10];
SSD ssdRepository[10];

void AddCPUFromDummyFile() {
    cpuInRep = 0;
    cpuRepository[cpuInRep].name = "cpu_1";
    cpuRepository[cpuInRep].price = 12000.00;
    cpuInRep++;
    cpuRepository[cpuInRep].name = "cpu_2";
    cpuRepository[cpuInRep].price = 13000.00;
    cpuInRep++;
}

void AddMotherboardFromDummyFile() {
    motherboardInRep = 0;
    motherboardRepository[motherboardInRep].name = "motherboard_1";
    motherboardRepository[motherboardInRep].price = 1000.50;
    motherboardInRep++;
    motherboardRepository[motherboardInRep].name = "motherboard_2";
    motherboardRepository[motherboardInRep].price = 1200.50;
    motherboardInRep++;
}

void AddRAMFromDummyFile() {
    ramInRep = 0;
    ramRepository[ramInRep].name = "ram_1";
    ramRepository[ramInRep].capacity = 16;
    ramRepository[ramInRep].price = 8000;
    ramInRep++;
    ramRepository[ramInRep].name = "ram_2";
    ramRepository[ramInRep].capacity = 32;
    ramRepository[ramInRep].price = 12000;
    ramInRep++;
    ramRepository[ramInRep].name = "ram_3";
    ramRepository[ramInRep].capacity = 4;
    ramRepository[ramInRep].price = 2000;
    ramInRep++;
}

void AddSSDFromDummyFile() {
    ssdInRep = 0;
    ssdRepository[ssdInRep].name = "ssd_1";
    ssdRepository[ssdInRep].capacity = 128;
    ssdRepository[ssdInRep].price = 15000;
    ssdInRep++;
    ssdRepository[ssdInRep].name = "ssd_2";
    ssdRepository[ssdInRep].capacity = 256;
    ssdRepository[ssdInRep].price = 30000;
    ssdInRep++;
}

void LoadPcComponents() {
    AddCPUFromDummyFile();
    AddMotherboardFromDummyFile();
    AddRAMFromDummyFile();
    AddSSDFromDummyFile();
}
void ShowHomePage();
//polymorphism
class BC
{
public:
    int b;
    void show()
    {
        cout<<"b="<<b<<endl;
    }
};
class DC:public BC
{
public:
    int d;
    void show()
    {
        cout<<"b="<<b<<endl;
        cout<<"d="<<d<<endl;
    }
};
//inheritance
class M
{
protected:
    int m;
public:
    void get_m(int m)
    {
        this->m=m;
    }
};
class N
{
protected:
    int n;
public:
    void get_n(int n)
    {
        this->n=n;
    }
};
class P:public M,public N
{
public:
    void display()
    {
        cout<<m<<endl<<n<<endl<<m*n<<endl;
    }
};
//encapsulation
class student
{
private:
    string name;

public:
    void setname(string x)
    {
        name=x;
    }
    string getname()
    {
        return name;
    }

};

class point
{
    int x;
    public:
    point(int a)
    {
        this->x=a;
    }
    bool operator==(point A)
    {
        return (x==A.x);
    }
};
//abstruct class
class Balagurusami
{
public:
    string book;
    Balagurusami()
    {

    }
    Balagurusami(string book)
    {
        book=book;
    }
    virtual void example()
    {

    }
};
class C:public Balagurusami
{
public:
    C()
    {

    }
    void example()
    {
        cout<<"OOP PROJECT IS DONE BY ME"<<endl;
    }
};
class oops:public Balagurusami
{
public:
    oops()
    {

    }
    void example()
    {
        cout<<"OBJECT ORIENTED PROGRAMMING-COMPUTER MANAGEMENT SYSTEM DONE!!!"<<endl;
    }
};
//Abstruction
class mobileuser
{
public:
    void call()
    {
        cout<<"OOP project is very helpful to develop our skills"<<endl;
    }
    virtual void message()=0;
};

class Student : public mobileuser
{
public:
    void message()
    {
        cout<<"Hi,I am Ahona"<<endl;
    }
};

class teacher : public mobileuser
{
public:
    void message()
    {
        cout<<"BEST OF LUCK"<<endl;
    }
};
int main() {
    LoadPcComponents();
    ShowHomePage();
    BC *bptr;
    BC base;
    bptr=&base;
    bptr->b=100;
    cout<<"bptr points to the base objects"<<endl;
    bptr->show();

    DC derived;
    bptr=&derived;
    bptr->b=200;
    //bptr->d=200 don't work
    cout<<"Now bptr points derived object"<<endl;
    bptr->show();
    DC *dptr;
    dptr=&derived;
    dptr->d=300;
    cout<<"dptr is a derived type pointer"<<endl;
    bptr->show();
    cout<<"using ((DC*)bptr):"<<endl;
    ((DC*)bptr)->d=400;
    ((DC*)bptr)->show();

    int a,b;
    cout<<"Enter:";
    cin>>a>>b;
    M A;
    A.get_m(a);
    N B;
    B.get_n(b);
    P AS;
    AS.get_m(a);
    AS.get_n(b);
    AS.display();

    int d,c;
    cout<<"Enter:";
    cin>>d;
    cout<<"Enter:";
    cin>>c;
    point D(d),E(c);
    if(D==E)
        cout<<"Egual"<<endl;
    else
        cout<<"Not eqal"<<endl;

        Balagurusami* arr[2];
    C e1;
    oops e2;
    arr[0]=&e1;
    arr[1]=&e2;
    arr[0]->example();
    arr[1]->example();


    student S1;
    S1.setname("OOP PROJECT");
    cout<<S1.getname()<<endl;
    mobileuser *m;
    Student S;
    teacher t;
    m-> call();
    m=&S;
    m-> message();
    m=&t;
    m-> message();
    return 0;
}

double CalculateTotalCost(PCConfig& config) {
    double totalCost = 0.0;
    totalCost = config.selectedCPU.getPrice() + config.selectedMotherboard.getPrice();
    for (int i = 0; i < config.numRAMs; ++i) {
        totalCost += config.selectedRAM[i].getPrice();
    }
    for (int i = 0; i < config.numSSDs; ++i) {
        totalCost += config.selectedSSD[i].getPrice();
    }
    return totalCost;
}

void ShowCpuPage();
void ShowMotherboardPage();
void ShowRamPage();
void ShowSsdPage();
void CheckOut();

void ShowHomePage() {
    std::cout << std::endl;
    std::cout << "------------------------------------------\n";
    std::cout << "|    COMPUTER MANAGEMENT SYSTEM    |\n";
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Current PC config you have selected" << std::endl;
    std::cout << std::endl;
    customerConfig.showInfo();
    std::cout << std::endl;
    std::cout << "Select your components (Chronologically recommended)" << std::endl;
    std::cout << std::endl;
    std::cout << "Core components:" << std::endl;
    std::cout << "1. CPU" << std::endl;
    std::cout << "2. Motherboard" << std::endl;
    std::cout << "3. Ram" << std::endl;
    std::cout << "4. SSD" << std::endl;
    std::cout << "Enter 5 to checkout!!";
    std::cout << std::endl;
    std::cout << std::endl;
    while (true) {
        std::cout << "Input: ";
        int userInput;
        std::cin >> userInput;
        switch (userInput) {
            case 1:
                ShowCpuPage();
                return;
            case 2:
                ShowMotherboardPage();
                return;
            case 3:
                ShowRamPage();
                return;
            case 4:
                ShowSsdPage();
                return;
            case 5:
                CheckOut();
                return;
            default:
                std::cout << "Invalid response! Input again: \n";
        }
    }
}

void ShowCpuPage() {
    int CPUIndex;
    std::string userInput;
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "|    COMPUTER MANAGEMENT SYSTEM    |" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Select your desired CPU" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < cpuInRep; i++) {
        std::cout << i + 1 << ".\n";
        cpuRepository[i].showInfo();
    }
    std::cout << std::endl;
    while(true) {
        std::cin >> CPUIndex;
        if (CPUIndex < 1 || CPUIndex > cpuInRep) {
            std::cout << "Invalid response! Please try again!!" << std::endl;
        } else {
            break;
        }
    };

    customerConfig.addCPU(cpuRepository[CPUIndex - 1]);
    ShowHomePage();
}

void ShowMotherboardPage() {
    int motherboardIndex;
    std::string userInput;
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "|    COMPUTER MANAGEMENT SYSTEM    |" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Select your desired Motherboard" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < motherboardInRep; i++) {
        std::cout << i + 1 << ".\n";
        motherboardRepository[i].showInfo();
    }
    std::cout << std::endl;
    while(true) {
        std::cin >> motherboardIndex;
        if (motherboardIndex < 1 || motherboardIndex > motherboardInRep) {
            std::cout << "Invalid response! Please try again" << std::endl;
        } else {
            break;
        }
    }
    customerConfig.addMotherboard(motherboardRepository[motherboardIndex - 1]);
    ShowHomePage();
}

void ShowRamPage() {
    int ramIndex, quantity;
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "|    COMPUTER MANAGEMENT SYSTEM    |" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Select your desired RAM" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < ramInRep; i++) {
        std::cout << i + 1 << ".\n";
        ramRepository[i].showInfo();
    }
    std::cout << std::endl;
    std::cout << "Select: ";
    while(true) {
        std::cin >> ramIndex;
        if (ramIndex < 1 || ramIndex > ramInRep) {
            std::cout << "Invalid response! Please try again!!" << std::endl;
        } else {
            break;
        }
    }
    std::cout << "Select Quantity: ";
    std::cin >> quantity;
    customerConfig.addRAM(ramRepository[ramIndex - 1], quantity);
    ShowHomePage();
}

void ShowSsdPage() {
    int ssdIndex, quantity;
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "|    COMPUTER MANAGEMENT SYSTEM    |" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Select your desired SSD" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < ssdInRep; i++) {
        std::cout << i + 1 << ".\n";
        ssdRepository[i].showInfo();
    }
    std::cout << std::endl;
    std::cout << "Select: ";
    while(true) {
        std::cin >> ssdIndex;
        if (ssdIndex < 1 || ssdIndex > ssdInRep) {
          std::cout << "Invalid response! Please try again!!" << std::endl;
        } else {
            break;
        }
    }
    std::cout << "Quantity: ";
    std::cin >> quantity;
    customerConfig.addSSD(ssdRepository[ssdIndex - 1], quantity);
    ShowHomePage();
}

void CheckOut() {
    std::cout << "Congrats!!!!" << std::endl;
    std::cout << "Current PC config you have selected" << std::endl;
    std::cout << std::endl;
    customerConfig.showInfo();
    std::cout << std::endl;
    std::cout << "Total price:: " << CalculateTotalCost(customerConfig) << std::endl;
    std::cout << std::endl;
    std::cout << "BYE BYE!!";
}
