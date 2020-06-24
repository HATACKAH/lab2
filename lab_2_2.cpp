#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    Node *nextNode; //следующий элемент списка
    char number;    //Номер элемента
};

struct Main
{
    Node *firstNode;
    string inElement;
    string nameOfFile;
    int linelength = 0;
    int DeleteAll = 0;
    int pos = -1;
    int totalElements = 1;

    int readfile()
    {

        int flag = 0;
        ifstream inputFile;
        string line;
        inputFile.open(nameOfFile);
        if (inputFile.is_open())
        {
            getline(inputFile, line);
            linelength = line.length();
            Node *prevElement = new Node;
            ; // для проброса связки
            for (int j = 0; j < line.length(); ++j)
            {                          // Считываем строчку до конца
                Node *buff = new Node; // хранилище
                buff->number = line[j];
                if (flag == 0)
                {
                    firstNode = buff;
                    prevElement = buff;
                    flag = 1;
                }
                else if (buff->number != ' ')
                {
                    prevElement->nextNode = buff;
                    prevElement = buff;
                    totalElements++;
                }
            }
            inputFile.close();
        }
    }

    void printer()
    {
        ofstream out;
        int flag = 0; // первый символ
        out.open(nameOfFile);
        if (out.is_open())
        {
            if (DeleteAll == 1)
            {
                for (int i = 0; i < linelength; ++i)
                {
                    out << ' ';
                }
            }
            else
            {
                int counter = 0; // проверка текущей позиции
                Node *prevElements;
                for (int i = 0; i < totalElements; ++i)
                {
                    if (flag == 0)
                    {
                        out << firstNode->number;
                        prevElements = firstNode->nextNode;
                        flag = 1;
                        counter++;
                    }
                    else
                    {
                        out << prevElements->number;
                        prevElements = prevElements->nextNode;
                        counter++;
                    }
                    if (counter == pos)
                    {
                        for (int j = 0; j < inElement.length(); ++j)
                        {
                            out << inElement[j];
                        }
                    }
                }
            }
        }
        out.close();
    }
};

int Main()
{
    //code
}
