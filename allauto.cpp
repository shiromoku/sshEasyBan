#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << argc << " file must not null" << endl;
        return 0;
    }
    string fileName;
    fileName = argv[1];
    // ifstream fin("20200517");
    ifstream fin(fileName);
    string word;
    vector<string> user;
    vector<int> userCount;
    vector<string> IP;
    vector<int> IPCount;
    while (fin >> word)
    {
        if (!word.compare("user"))
        {
            fin >> word; //now word is user no 'user'

            int i = 0;
            for (auto it = user.begin(); it != user.end(); it++, i++)
            {
                string s = *it;
                if (!word.compare(s))
                {
                    userCount[i]++;
                    goto nexts;
                }
            }
            user.push_back(word);
            userCount.push_back(1);

        nexts:
            fin >> word; //drop 'from'
            fin >> word; //get ip
            i = 0;
            for (auto it = IP.begin(); it != IP.end(); it++, i++)
            {

                string s = *it;
                if (!word.compare(s))
                {
                    IPCount[i]++;
                    goto next;
                }
            }
            IP.push_back(word);
            IPCount.push_back(1);

        next:
            continue;
        }
    } //read all line of file

    int i = 0;
    ofstream banOut(fileName + "Banlist.txt");
    ofstream IPOut(fileName + "IP.xls");
    ofstream userOut(fileName + "user.xls");
    banOut << "vim /etc/hosts.deny"<<endl;
    for (auto it = IP.begin(); it != IP.end(); it++, i++)
    {
        // cout << *it << "\t\t" << IPCount[i] << endl;
        banOut << "sshd:" << *it << endl;
        IPOut << *it << "\t" << IPCount[i] << endl;
    }
    i = 0;
    for (auto it = user.begin(); it != user.end(); it++, i++)
    {
        userOut << *it << "\t" << userCount[i] << endl;
    }
    IPOut.close();
    userOut.close();
    fin.close();
    return 0;
}