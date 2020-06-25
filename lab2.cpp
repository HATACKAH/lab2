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
                Node *prevElements; //новый элемент, который должен стоять перед заданным


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
                    if (counter == pos-1)
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

int main() {
    string nameOfFile;
    Main line;
    cout
            << "hello! this programm can put in you list other element on position or delete this list. You need to write path to you file\n"
               "on first line, on second if you want to delete list write only YES, if you want to put in list, you need write element and\n"
               "on third line write number, after you want to put element.\n"
               "Example if i want to delete:\n"
               "C:\\Users\\test.txt\n"
               "YES\n"
               "Example if i want to insert element:\n"
               "C:\\Users\\test.txt\n"
               "1\n"
               "4\n";
    cin >> line.nameOfFile;
    cin >> line.inElement;
    if (line.inElement == "DEL") line.DeleteAll = 1;
    else cin >> line.pos;
    line.readfile(); 
    line.printer();
    return 0;
}
