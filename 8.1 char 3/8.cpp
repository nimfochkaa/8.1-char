#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>  

using namespace std;

bool hasSQorQS(const char* str) {
    return strstr(str, "SQ") || strstr(str, "QS");
}

char* replaceSQorQS(const char* str) {
    size_t max_size = strlen(str) * 2 + 1;
    char* result = new char[max_size];
    result[0] = '\0';  

    const char* pos = str;
    while (*pos) {
        const char* sq_pos = strstr(pos, "SQ");
        const char* qs_pos = strstr(pos, "QS");

        if (!sq_pos && !qs_pos) {
            strncat(result, pos, max_size - strlen(result) - 1);
            break;
        }

        const char* found_pos = (sq_pos && (!qs_pos || sq_pos < qs_pos)) ? sq_pos : qs_pos;

        size_t len = found_pos - pos;
        strncat(result, pos, len);

        strncat(result, "***", max_size - strlen(result) - 1);

        pos = found_pos + 2;  
    }

    return result;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (hasSQorQS(str))
        cout << "The string contains 'SQ' or 'QS'." << endl;
    else
        cout << "The string does not contain 'SQ' or 'QS'." << endl;

    char* modifiedStr = replaceSQorQS(str);
    cout << "Modified string: " << modifiedStr << endl;

    delete[] modifiedStr;
    return 0;
}
