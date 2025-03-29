#include <iostream>
#include <vector>
#include <string>
using namespace std;

string deleteSpaces(string s)   //функция удаления пробелов
{
    size_t pos = s.find(' ');

    if (!s.empty()) //проверка на пустую строку
    {
        while (pos != string::npos)
        {
            if (pos != string::npos)
                s.erase(pos, 1);
            pos = s.find(' ');
        }
    }
    return s;
}

vector<double> splitString(string s, char delimiter = ',')  //функция парсинга
{
    vector<double> vd;
    s = deleteSpaces(s);
    double num;
    string part;
    size_t startPos = 0;
    size_t pos = s.find(delimiter);
    while (pos != std::string::npos)    //цикл выделения координат
    {
        part = s.substr(startPos, pos - startPos);
        if (part.length() > 0)
        {
            num = stod(part);   //преобразование строки в тип double
            vd.push_back(num);
        }
        startPos = pos + 1;
        pos = s.find(delimiter, pos + 1);
    }
    part = s.substr(startPos, s.length() - startPos);
    if (part.length() > 0)  //добавление последней координаты
    {
        num = stod(part);
        vd.push_back(num);
    }
    return vd;
}

void Print(vector<double> vd)   //функция вывода координат
{
    cout << 'X' << '\t' << 'Y' << endl;
    for (int i = 0; i < vd.size(); i+=2)
    {
        cout << vd[i] << '\t' << vd[i + 1] << endl;
    }
}

int main()
{
    vector<double> vd;

    string s = "192.56, -21.2, 17.08, 22.8, -0.01, 0.02, 33.2, 43.8, -12.1, 14.5";
    //string s = "192.56,   -21.2, 17.08,22.8"; 
    vd = splitString(s);
    Print(vd);
}