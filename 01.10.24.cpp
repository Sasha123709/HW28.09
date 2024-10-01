#include <iostream>
#include <string>
#include <cctype> 
#include <Windows.h>
using namespace std;
//

string filterAndLowercase(const string& str) {
    string result = "";
    for (char c : str) {
        if (isalpha(c)) {  
            result += tolower(c); 
        }
    }
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str1, str2;

   
    cout << "Введіть перший рядок ";
    getline(cin, str1);
    cout << "Введіть другий рядок ";
    getline(cin, str2);

   
    string filter1 = filterAndLowercase(str1);
    string filter2 = filterAndLowercase(str2);

    // Порівняння
    if (filter1 == filter2) {
        cout << "ІДЕНТИЧНІ" << endl;
    }
    else {
        cout << "НЕ ІДЕНТИЧНІ" << endl;
    }

    return 0;
}
