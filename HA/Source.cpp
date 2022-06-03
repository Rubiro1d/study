#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int>> FindIteratorsForLoop(int v, int n_1, int n_2);
bool IsCorrectIAndJ_v2(int i, int j);
bool IsCorrectIAndJ_v3(int i, int j, int n_1, int n_2);

int main()
{

    int n_2 = 5;
    int n_1 = 7;

    while (true)
    {
        cout << "Write i\n";
        cin >> n_2;
        cout << "Write j\n";
        cin >> n_1;
        cin.ignore();
        cout << "\n";

        if (!(n_2 > 0 && n_2 < 1000) || !(n_1 > 0 && n_1 < 100))
        {
            cout << "Incorrect data entered\n";
            system("pause");
            system("cls");
            continue;
        }
        break;
    }

    vector <vector<double>> x(n_2, vector<double>(n_1, 1));

    for (int v = 1; v <= 2 * n_1 + n_2 - 2; v++)
    {
        vector<pair<int, int>> IterIAndJ = FindIteratorsForLoop(v, n_1, n_2);
        for (auto it = IterIAndJ.begin(); it != IterIAndJ.end(); ++it)
        {
            //x - vector - start from 0
            int i = it->first - 1;
            int j = it->second - 1;

            if (!IsCorrectIAndJ_v3(i, j, n_1, n_2)) //v2
            {
                cout << x[i][j] << "\t";
                continue;
            }
            
            x[i][j] = x[i - 1][j] + x[i][j - 1] + x[i + 1][j - 1];

            cout << x[i][j] << "\t";
        }
        cout << endl;
        

    }
}

vector<pair<int, int>> FindIteratorsForLoop(int v, int n_1, int n_2)
{
    vector<pair<int, int>> IterIAndJTmp;
    for (int j = 1; j <= n_1; j++)
    {
        for (int i = 1; i <= n_2; i++)
        {
            if (j - 0.5 * (-i + v + 2) == 0) // j = 0.5*(-i+v+2)
            {
                IterIAndJTmp.push_back(pair<int, int>(i, j));
            }

        }
    }

    return IterIAndJTmp;
}

bool IsCorrectIAndJ_v2(int i, int j)
{
    if (i - 1 < 0 || i - 2 < 0 || j - 1 < 0)
    {
        return false;
    }

    return true;
}

bool IsCorrectIAndJ_v3(int i, int j, int n_1, int n_2)
{
    if (i - 1 < 0 || i + 1 >= n_2 || j - 1 < 0)
    {
        return false;
    }

    return true;
}