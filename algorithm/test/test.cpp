#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
struct Person
{
    string p_num;
    string p_first_name;
    string p_last_name;
};
struct last_name_count {
    string last_name="";
    int count=0;
};
bool cmp(Person p1, Person p2) {
    if (p1.p_num < p2.p_num)
        return p1.p_num < p2.p_num;

    else if (p1.p_num == p2.p_num)
        return p1.p_num < p2.p_num;

    else
        return false;
}
bool cmp_2(last_name_count  p1, last_name_count p2) {
    return p1.last_name < p2.last_name;
}
int main() {
    string result = "";
    vector<string> last_name;
    ifstream Fin("test.inp");
    vector<last_name_count> exist;
    int len;
    Fin >> len;
    //struct Person* person_info = new Person[len];
    vector<Person> person_info;

    int max_length_1 = 0;
    int max_length_2 = 0;
    for (int i = 0; i < len; i++) {
        Person person_i;
        Fin >> person_i.p_num;
        Fin >> person_i.p_first_name;
        Fin >> person_i.p_last_name;
        person_info.push_back(person_i);
    }
    Fin.close();

    sort(person_info.begin(), person_info.end(), cmp);
    for (int i = 0; i < len; i++) {


        last_name_count lnc;
        int count = 0;

        for (int j = 0; j < len; j++) {
            if (person_info[i].p_last_name == person_info[j].p_last_name) {
                count++;
            }
            if (max_length_1 <= person_info[i].p_first_name.length())
                max_length_1 = person_info[i].p_first_name.length();
        }
        if (count != 1) {
            if (find(last_name.begin(), last_name.end(), person_info[i].p_last_name) != last_name.end()) {
                continue;
            }
            lnc.count = count;
            lnc.last_name = person_info[i].p_last_name;
            last_name.push_back(person_info[i].p_last_name);
            exist.push_back(lnc);
        }

    }
    // cout << max_length_1;
    sort(exist.begin(), exist.end(), cmp_2);

    for (int i = 0; i < len; i++) {
        result += person_info[i].p_num += " ";
        result += person_info[i].p_first_name;
        for (int j = 0; j < (max_length_1 + 1) - person_info[i].p_first_name.length(); j++) {
            result += " ";
        }
        result += person_info[i].p_last_name += "\n";

    }

    if (exist.size() == 0) {
        result += "\n";
    }
    else {
        result += "\n";
        for (int i = 0; i < exist.size(); i++) {
            result += exist[i].last_name += " ";

            result += to_string(exist[i].count);
            if (i != exist.size()) {
                result += "\n";
            }
        }
    }
    // result.erase(result.size() - 1);
    ofstream writeFile("test.out");
    if (writeFile.is_open()) {
        writeFile << result;
        writeFile.close();
    }
    return 0;
}