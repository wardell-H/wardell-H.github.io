#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
bool valid(const string& str)
{
    if (str.length() != 11) return false;
    if (str[0] != '1') return false;
    if (str[1] != '3' && str[1] != '4' && str[1] != '5' && str[1] != '6' && str[1] != '7' && str[1] != '8' && str[1] != '9') return false;
    for (int i = 2; i < 11; ++i) 
    {
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}
int main(int argc, char* argv[]) 
{
    if (argc != 3) 
    {
        cerr << "请给出文件名和前三位号码" << endl;
        return -1;
    }
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "无法打开输入文件" << endl;
        return -1;
    }
    string prefix(argv[2]);//前三位数  //汉字的ascii码有两个，不能用getchar()
    string line;
    string phone_num_max = "10000000000";
    in >> line;
    while (!in.eof())
    {
        getline(in, line);
        istringstream iss(line);
        string phone_num;
        iss >> phone_num;
        if (!iss) continue; // 空行
        if (valid(phone_num) && phone_num.substr(0, 3) == prefix)
        {
            if (phone_num_max.compare(4, 8, phone_num,4,8)<0)
            {
                phone_num_max = phone_num;
            }
           
        }

    }
    cout << phone_num_max<<endl;
    return 0;
}