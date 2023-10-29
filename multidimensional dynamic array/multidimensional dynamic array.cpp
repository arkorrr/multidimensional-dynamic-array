#include <iostream>

using namespace std;

struct Info 
{
    string name;
    string phoneNumber;
};

//Task1
void CreateArrA(int cols, int rows, int** MasA)
{
    for (int i = 0; i < cols; ++i)
    {
        MasA[i] = new int[rows];
    }
}

void CreateArrB(int cols, int rows, int** MasB)
{
    for (int i = 0; i < rows; ++i)
    {
        MasB[i] = new int[cols];
    }
}

void FullArrayAndCout(int cols,int rows,int** MasA)
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cin >> MasA[i][j];
        }
    }

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << MasA[i][j] << " ";
        }
        cout << endl;
    }
}

void DeleteArrA(int** MasA,int cols)
{
    for (int i = 0; i < cols; ++i)
    {
        delete[] MasA[i];
    }
    delete[] MasA;
}

void DeleteArrB(int** MasB, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] MasB[i];
    }
    delete[] MasB;
}

void TransportArrAndCout(int cols,int rows, int** MasA, int** MasB)
{
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            MasB[j][i] = MasA[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << MasB[i][j] << " ";
        }
        cout << endl;
    }
}

//Task2

void searchName()
{

}

int main() 
{
    //Task1
    int cols, rows;
    cin >> cols;
    cin >> rows;
    int** MasA = new int* [cols];
    int** MasB = new int* [rows];
    CreateArrA(cols, rows, MasA);
    CreateArrB(cols, rows, MasB);
    FullArrayAndCout(cols, rows, MasA);
    TransportArrAndCout(cols, rows, MasA, MasB);
    DeleteArrA(MasA, cols);
    DeleteArrB(MasB, rows);

    //Task2 Я добавил возможность изменять имя пользователя если он нашёл его в базе данных. 
    //Для номер телефона так-же сама но я не добавлял эту возможность для данного кода.
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    Info* Information = new Info[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter name: ";
        cin >> Information[i].name;
        cout << "Enter phone number: ";
        cin >> Information[i].phoneNumber;
    }

    string searchName;
    bool TOrF = true;
    cout << "Enter name which you want to find: ";
    cin >> searchName;
    int indexOfName = 0;
    for (int i = 0; i < n; i++) {
        if (Information[i].name == searchName) 
        {
            cout << "This name is in the database." << endl;
            TOrF = true;
            indexOfName = i;
            break;
        }
        else
            cout << "This name was not founded in the database." << endl;
    }
    int change;
    string newname;
    if (TOrF == true)
    {
        cout << "If you want to change your name in database enter 1: " << endl;
        cout << "If you dont want to change your name enter 0: " << endl;
        cin >> change;
    }
    if (change == 1)
    {
        cout << "Enter your new name: " << endl;
        cin >> newname;
        Information[indexOfName].name = newname;
    }

    string searchNumber;
    cout << "Enter phone number which you want to find: ";
    cin >> searchNumber;
    for (int i = 0; i < n; i++) {
        if (Information[i].phoneNumber == searchNumber) 
        {
            cout << "Phone number is in the database." << endl;
            break;
        }
        else
            cout << "This phone number was not founded in the database." << endl;
    }
    

    delete[] Information;
   

    return 0;
}

