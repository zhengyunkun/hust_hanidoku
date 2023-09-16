#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

#define CORRECT 0
#define WRONG -1

typedef struct numNode { //为翻转提供准备
    int x;
    int y;
} numNode;

using namespace std;

int a[61], holes = 15;

void createHanidoku(int a[])
{
    string str;
    ifstream fis ("Hanidoku.txt");
    if (!fis) cout << "can't open this file!\n";

    fis >> str;

    for (int i = 0; i < 61; i ++ )
        a[i] = str[5 + i] - '0';
}

void createStartinggrid(int a[], int b[], int holes)
{
    
    srand((unsigned)time(nullptr));
    for (int i = 0; i < 61; i ++ ) b[i] = a[i];

    int c[holes], cf;

    int flag = 0;

    for (int i = 0; i < holes; i ++ )
    {
        cf = rand() % 61; //生成0到60的随机数

        flag = 0;
        for (int m = 0; m < i; m ++ )
            if (cf == c[m])
                flag = 1;

        if (flag == 0)
        {
            b[cf] = 0;
            c[i] = cf;
        }
        else i -- ;
    }
}

void print(const int a[])
{
    cout << "         / \\ / \\ / \\ / \\ / \\\n";
    cout << "        |";
    for (int i = 0; i < 5; i ++ ) cout << ' ' << a[i] << " |";
    cout << endl;
    cout << "       / \\ / \\ / \\ / \\ / \\ / \\\n";
    cout << "      |";
    for (int i = 5; i < 11; i ++ ) cout << ' ' << a[i] << " |";
    cout << endl;
    cout << "     / \\ / \\ / \\ / \\ / \\ / \\ / \\\n";
    cout << "    |";
    for (int i = 11; i < 18; i ++ ) cout << ' ' << a[i] << " |";
    cout << endl;
    cout << "   / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\\n";
    cout << "  |";
    for (int i = 18; i < 26; i ++ ) cout << ' ' << a[i] << " |";
    cout << endl;
    cout << " / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\\n";
    cout << "|";
    for (int i = 26; i < 35; i ++ ) cout << ' ' << a[i] << " |";
    cout << endl;
    cout << " \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ /\n";
    cout << "  |";
    for (int i = 35; i < 43; i ++ ) cout << ' ' << a[i] << " |";
    cout << endl;
    cout << "   \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\ /\n";
    cout << "    |";
    for (int i = 43; i < 50; i ++ ) cout << ' ' << a[i] << " |";
    cout << endl;
    cout << "     \\ / \\ / \\ / \\ / \\ / \\ / \\ /\n";
    cout << "      |";
    for (int i = 50; i < 56; i ++ ) cout << ' ' << a[i] << " |";
    cout << endl;
    cout << "       \\ / \\ / \\ / \\ / \\ / \\ /\n";
    cout << "        |";
    for (int i = 56; i < 61; i ++ ) cout << ' ' << a[i] << " |";
    cout << endl;
    cout << "         \\ / \\ / \\ / \\ / \\ /\n";
}

//b是待输出的数组，把a数组逆时针旋转了60度
//a是待输出的数组，把b数组顺时针旋转了60度
void turnAnAngle(numNode a[][10], numNode b[][10])
{
	b[1][1] = a[1][5], b[1][2] = a[2][6], b[1][3] = a[3][7], b[1][4] = a[4][8], b[1][5] = a[5][9];
	b[2][1] = a[1][4], b[2][2] = a[2][5], b[2][3] = a[3][6], b[2][4] = a[4][7], b[2][5] = a[5][8], b[2][6] = a[6][8];//2
	b[3][1] = a[1][3], b[3][2] = a[2][4], b[3][3] = a[3][5], b[3][4] = a[4][6], b[3][5] = a[5][7], b[3][6] = a[6][7], b[3][7] = a[7][7];//3
	b[4][1] = a[1][2], b[4][2] = a[2][3], b[4][3] = a[3][4], b[4][4] = a[4][5], b[4][5] = a[5][6], b[4][6] = a[6][6], b[4][7] = a[7][6], b[4][8] = a[8][6];
	b[5][1] = a[1][1], b[5][2] = a[2][2], b[5][3] = a[3][3], b[5][4] = a[4][4], b[5][5] = a[5][5], b[5][6] = a[6][5], b[5][7] = a[7][5], b[5][8] = a[8][5], b[5][9] = a[9][5];
	b[6][1] = a[2][1], b[6][2] = a[3][2], b[6][3] = a[4][3], b[6][4] = a[5][4], b[6][5] = a[6][4], b[6][6] = a[7][4], b[6][7] = a[8][4], b[6][8] = a[9][4];
	b[7][1] = a[3][1], b[7][2] = a[4][2], b[7][3] = a[5][3], b[7][4] = a[6][3], b[7][5] = a[7][3], b[7][6] = a[8][3], b[7][7] = a[9][3];
	b[8][1] = a[4][1], b[8][2] = a[5][2], b[8][3] = a[6][2], b[8][4] = a[7][2], b[8][5] = a[8][2], b[8][6] = a[9][2];
	b[9][1] = a[5][1], b[9][2] = a[6][1], b[9][3] = a[7][1], b[9][4] = a[8][1], b[9][5] = a[9][1];
}

void createNode(numNode b[][10])
{
    for (int i = 1; i <= 9; i ++ )
        for (int j = 1; j <= 9; j ++ )
        {
            b[i][j].x = i;
            b[i][j].y = j;
        }
}

//将语义编码转化为自然顺序编码
int TransLiteral(int x)
{
    int a[10] = {0, 5, 6, 7, 8, 9, 8, 7, 6, 5};
    int b[10] = {0, 0, 5, 11, 18, 26, 35, 43, 50, 56};

    for (int i = 1; i <= 9; i ++ )
        for (int j = 1; j <= a[i]; j ++ )
            if (x >= 100 * i + 10 * j + 1 && x <= 100 * i + 10 * j + 9)
                return x - (100 * i + 10 * j) + 9 * (j - 1) + 9 * b[i];

    return 0;
}

//行约束
void lineDis(ofstream &in, numNode b[][10])
{
    //范式，1到9行的约束
    for (int p = 1; p <= 9; p ++ )
    {
        int cf = p;
        if (p >= 6 && p <= 9) cf = 10 - p;
        //必填数字
        for (int i = 5 - (cf - 1); i <= 5 + (cf - 1); i ++ )
        {
            for (int j = 1; j <= 5 + (cf - 1); j ++ )
                in << TransLiteral(100 * b[p][j].x + b[p][j].y * 10 + i) << ' ';
            in << 0 << endl;
        }

        //约束方案的子句
        for (int i = 1; i <= 4 - (cf - 1); i ++ )
        {
            for (int j = 6 + (cf - 1); j < 6 + (cf - 1) + i; j ++ )
            {
                for (int k = 1; k <= 5 + (cf - 1); k ++ )
                    in << TransLiteral(100 * b[p][k].x + 10 * b[p][k].y + i) << ' ';
                for (int k = 1; k <= 5 + (cf - 1); k ++ )
                    in << TransLiteral(100 * b[p][k].x + 10 * b[p][k].y + j) << ' ';
                in << 0 << endl;
            }
        }

        //每两格的数字不能重复
        for (int i = 1; i <= 9; i ++ )
            for (int j = 1; j <= 5 + (cf - 1); j ++ )
                for (int k = j + 1; k <= 5 + (cf - 1); k ++ )
                    in << - TransLiteral(100 * b[p][j].x + b[p][j].y * 10 + i) << ' ' << - TransLiteral(100 * b[p][k].x + b[p][k].y * 10 + i) << ' ' << 0 << endl;
    } 
}

//同一格只能填一个数字
void Singularity(ofstream &in)
{
    for (int p = 1; p <= 9; p ++ )
    {
        int cf = p;
        if (p >= 6 && p <= 9) cf = 10 - p;

        for (int j = 1; j <= 5 + (cf - 1); j ++ )
        {
            for (int l = 1; l <= 9; l ++ ) in << TransLiteral(100 * p + 10 * j + l) << ' ';
                in << 0 << endl;
            for (int i = 1; i <= 9; i ++ )
            {
                for (int k = i + 1; k <= 9; k ++ )
                    in << - TransLiteral(100 * p + 10 * j + i) << ' ' << - TransLiteral(100 * p + 10 * j + k) << ' ' << 0 << endl;
            }
        }
    }
}

string ToCnf(int a[][9], int holes)
{
    ofstream in ("sudoku.cnf");//定义输入文件
    if(!in.is_open())
        cout << "Can't open this file!\n";

    in << "p" << " " << "cnf" << " " << 549 << " " << 5211 + 61 - holes + 2257 << " " << endl;

    //数独中所有的单子句
    for (int i = 0; i < 9; i ++ )
    {
        for (int j = 0; j < 9; j ++ )
            if (a[i][j] != -1 && a[i][j] != 0)
                in << TransLiteral((i + 1) * 100 + (j + 1) * 10 + a[i][j]) << ' ' << 0 << endl;
    }

    Singularity(in); //单格数字约束
    
    numNode bp[10][10], b[10][10];
    createNode(b);
    //行约束
    lineDis(in, b);

    //右对角线约束
    turnAnAngle(b, bp);
    lineDis(in, bp);

    //左对角线约束
    turnAnAngle(b, bp), turnAnAngle(bp, b);
    lineDis(in, b);

    in.close();
    return string("");
}

void changeGrid(int hani[][9], int b[])
{
    for (int i = 0; i < 5; i ++ ) hani[0][i] = b[i];
    for (int i = 5; i < 11; i ++ ) hani[1][i - 5] = b[i];
    for (int i = 11; i < 18; i ++ ) hani[2][i - 11] = b[i];
    for (int i = 18; i < 26; i ++ ) hani[3][i - 18] = b[i];
    for (int i = 26; i < 35; i ++ ) hani[4][i - 26] = b[i];
    for (int i = 35; i < 43; i ++ ) hani[5][i - 35] = b[i];
    for (int i = 43; i < 50; i ++ ) hani[6][i - 43] = b[i];
    for (int i = 50; i < 56; i ++ ) hani[7][i - 50] = b[i];
    for (int i = 56; i < 61; i ++ ) hani[8][i - 56] = b[i];
}

int main()
{
    int a[61], b[61], holes, hani[9][9];
    memset(hani, -1, sizeof hani);
    cout << "\n***********************input the number of holes***************************\n" << endl;
    cin >> holes;

    createHanidoku(a);
    print(a);
    createStartinggrid(a, b, holes);
    cout << "**************************initialize the sudoku****************************" << endl;
    print(b);

    changeGrid(hani, b);

    for (int i = 0; i < 9; i ++ )
    {
        for (int j = 0; j < 9; j ++ ) cout << hani[i][j] << ' ';
        cout << endl;
    }

    string str = ToCnf(hani, holes);

    return 0;
}