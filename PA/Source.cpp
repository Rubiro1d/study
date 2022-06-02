#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> StrToArrInt(string str);
bool IsBadInMatrix(vector<vector<int>> checkedMatrix, int numberVert);
bool CanMakeStepTwo(vector<vector<int>>& S1, vector<vector<int>> Matrix, int numberVertices);
void PrintResult(vector<vector<int>> S1);
void DeleteDuplicates(vector<vector<int>>& S1, int numberVertices);


int main()
{
    int numberVertices = 5;
    vector<vector<int>> Matrix;

    while (false) //змінити на false, якщо треба використати шаблону матрицю
    {
        cout << "Write adjacency matrix\n";

        cout << "Write number of vertices\n";
        cin >> numberVertices;
        cin.ignore();
        if (!(numberVertices > 0 && numberVertices < 1000))
        {
            cout << "Incorrect data entered\n";
            system("pause");
            system("cls");
            continue;
        }

        for (int i = 0; i < numberVertices; i++)
        {
            string matrixRow;
            cout << int(i + 1);
            cout << " row" << endl;
            getline(cin, matrixRow);
            Matrix.push_back(StrToArrInt(matrixRow));
        }

        if (IsBadInMatrix(Matrix, numberVertices)) {
            system("pause");
            system("cls");
            continue;
        }
        break;
    }

   /*Matrix.push_back(vector<int> {0, 1, 0, 0, 1 });
     Matrix.push_back(vector<int> {0, 0, 1, 1, 0 });
     Matrix.push_back(vector<int> {0, 0, 0, 0, 0 });
     Matrix.push_back(vector<int> {0, 0, 1, 0, 0 });
     Matrix.push_back(vector<int> {0, 0, 0, 1, 0 });*/

    cout << "\n\n";
    for (int i = 0; i < numberVertices; i++)
    {
        for (int j = 0; j < numberVertices; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\n\n";

    vector<vector<int>> S1;
    vector<int> s1_tmp;
    bool flagColHasOne = false;

    for (int i = 0; i < numberVertices; i++)
    {
        for (int j = 0; j < numberVertices; j++)
        {
            if (Matrix[j][i] != 0)
            {
                flagColHasOne = true;
                continue;
            }
        }
        if (!flagColHasOne)
        {
            s1_tmp.push_back(i);
        }
        else
        {
            flagColHasOne = false;
        }
    }
    S1.push_back(s1_tmp);
    s1_tmp.clear();

    while (true)
    {
        if (!CanMakeStepTwo(S1, Matrix, numberVertices))
        {
            system("pause");
            break;
        }
    }

    DeleteDuplicates(S1, numberVertices);
    PrintResult(S1);

}

vector <int> StrToArrInt(string str)
{
    string strtemp = "";
    vector<int> numberInRow;
    for (int i = 0; i < str.size() + 1; i++)
    {
        if (str[i] != ' ' && str[i] != '\0')
        {
            strtemp += str[i];
        }
        else
        {
            if (strtemp.empty()) continue;
            numberInRow.push_back(stoi(strtemp));
            strtemp = "";
        }
    }
    return numberInRow;
}

bool IsBadInMatrix(vector<vector<int>> checkedMatrix, int numberVert)
{

    for (int i = 0; i < checkedMatrix.size(); i++)
    {
        if (checkedMatrix.size() != checkedMatrix[i].size() || checkedMatrix.size() != numberVert)
        {
            cout << "Error in Dimensionality Of Matrix\n";
            return true;
        }
        for (int j = 0; j < checkedMatrix[i].size(); j++)
        {
            if (!(checkedMatrix[i][j] == 0 || checkedMatrix[i][j] == 1))
            {
                cout << "Error, can be only 1 or 0 numbers\n";
                return true;
            }
        }
    }
    return false;
}

bool CanMakeStepTwo(vector<vector<int>>& S1, vector<vector<int>> Matrix, int numberVertices)
{
    vector<int> S2;
    for (int k = 0; k < S1[S1.size() - 1].size(); k++)
    {
        int i = S1[S1.size() - 1][k]; // вибірка записаних вершин, які є початковими
        for (int j = 0; j < numberVertices; j++)
        {
            if (Matrix[i][j] == 1)
            {
                S2.push_back(j);
            }
        }
    }

    if (S2.empty())
    {
        return false;
    }

    S1.push_back(S2);
    S2.clear();
    return true;
}

void PrintResult(vector<vector<int>> S1)
{
    cout << "\nCount of Tier: " << S1.size() << endl;
    for (int i = 0; i < S1.size(); i++)
    {
        for (int j = 0; j < S1[i].size(); j++)
        {
            cout << (S1[i][j] + 1) << "\t";
        }
        cout << endl;
    }
}

bool HasDuplicates(vector<int> vert, vector<int> vertTmp, int number)
{
    for (int i = 0; i < vert.size(); i++)
    {
        if (vert[i] == number)
        {
            return true;
        }
    }

    for (int i = 0; i < vertTmp.size(); i++)
    {
        if (vertTmp[i] == number)
        {
            return true;
        }
    }
    return false;
}

void DeleteNumberFromVector(vector<int>& vect, int pos)
{
    vect.erase(vect.begin() + pos); //-1?

}

void DeleteDuplicates(vector<vector<int>>& S1, int numberVertices)
{
    vector<int> vertices;
    vector<int> verticesTmp;

    for (int i = S1.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < S1[i].size(); j++)
        {
            if (!HasDuplicates(vertices, verticesTmp, S1[i][j]))
            {
                verticesTmp.push_back(S1[i][j]);
            }
            else
            {
                verticesTmp.clear();
                DeleteNumberFromVector(S1[i], j);
                j = -1;
                continue;
            }

        }
        vertices.insert(vertices.end(), verticesTmp.begin(), verticesTmp.end());
        verticesTmp.clear();

    }
}

