//#include <iostream>
//#include <string>
//#include <cctype> 
//#include <Windows.h>
//using namespace std;
////
//
//string filterAndLowercase(const string& str) {
//    string result = "";
//    for (char c : str) {
//        if (isalpha(c)) {  
//            result += tolower(c); 
//        }
//    }
//    return result;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    string str1, str2;
//
//   
//    cout << "Введіть перший рядок ";
//    getline(cin, str1);
//    cout << "Введіть другий рядок ";
//    getline(cin, str2);
//
//   
//    string filter1 = filterAndLowercase(str1);
//    string filter2 = filterAndLowercase(str2);
//
//    // Порівняння
//    if (filter1 == filter2) {
//        cout << "ІДЕНТИЧНІ" << endl;
//    }
//    else {
//        cout << "НЕ ІДЕНТИЧНІ" << endl;
//    }
//
//    return 0;
//}
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm> /
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string password;
    const int minLength = 8;  
    const int passwordLength = 12;  


    cout << "Введіть пароль: ";
    cin >> password;

  
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;

    if (password.length() < minLength) {
        cout << "Пароль надто короткий. Мінімум " << minLength << " символів." << endl;
    }
    else {
        for (char c : password) {
            if (islower(c)) hasLower = true;
            if (isupper(c)) hasUpper = true;
            if (isdigit(c)) hasDigit = true;
            if (ispunct(c)) hasSpecial = true;  
        }

        if (!hasLower) cout << "Пароль не містить символів нижнього регістру." << endl;
        if (!hasUpper) cout << "Пароль не містить символів верхнього регістру." << endl;
        if (!hasDigit) cout << "Пароль не містить цифр." << endl;
        if (!hasSpecial) cout << "Пароль не містить спеціальних символів." << endl;

        
        if (hasLower && hasUpper && hasDigit && hasSpecial) {
            cout << "Пароль є надійним!" << endl;
        }
        else {
            cout << "Пароль не є надійним." << endl;

           
            const string lower = "abcdefghijklmnopqrstuvwxyz";
            const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            const string digits = "0123456789";
            const string special = "!@#$%^&*()_+-=[]{}|;:'\",.<>?/";

            string newPassword;
            srand(time(NULL));

           
            newPassword += lower[rand() % lower.length()];
            newPassword += upper[rand() % upper.length()];
            newPassword += digits[rand() % digits.length()];
            newPassword += special[rand() % special.length()];

            
            string allChars = lower + upper + digits + special;
            for (int i = 4; i < passwordLength; i++) {
                newPassword += allChars[rand() % allChars.length()];
            }

            
            random_shuffle(newPassword.begin(), newPassword.end());

            cout << "Ваш новий надійний пароль: " << newPassword << endl;
        }
    }

    return 0;
}
