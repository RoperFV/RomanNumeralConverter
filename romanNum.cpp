#include <iostream>
#include <algorithm>
#include <string>
using namespace std;




bool isValidDecimalNumber(string s) {

    for(int i = 0; i< s.length(); i++){

        if(isdigit(s[i])) {

           
        } else {
            return false;
        }
         
    }
    
    return true;

}

bool isValidRomanNumber(string s) {

    char romNum[14] = {'m', 'd', 'c', 'l', 'x', 'v', 'i', 'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    bool isRoman = false;
    int numCorrect = 0;

    for(int i = 0; i<s.length(); i++){
        for(int j = 0; j<sizeof(romNum); j++) {
            if(s[i] == romNum[j]){
                numCorrect++;

            }
        }
    }
    if(numCorrect == s.length()) {
        return true;
    } else {
        return false;
    }

}

string convertRomanToDecimal(string s) {

    
    char rom[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int nums[7] = {1000, 500, 100, 50, 10, 5, 1};
    int sNums[s.length()];

    transform(s.begin(), s.end(), s.begin(), ::toupper);

    int answer = 0;


    for(int i = 0; i < s.length(); i++) {
        for(int j = 0; j < sizeof(rom); j++) {
            if(s[i] == rom[j]) {
                sNums[i] = nums[j];
            }
        }
    }

    for(int i = 0; i < s.length(); i++) {
        if ((i+1) == s.length()) {
            answer = answer + sNums[i];

        } else {

            if(sNums[i] >= sNums[i+1]) {

                answer = answer + sNums[i];
            } else {

                answer = answer + sNums[i+1] - sNums[i];
                i++;
            }
        }
    }
    string end = to_string(answer);

    return end;

}


string convertDecimalToRoman(string s) {

    int size = s.length();
    string roman;
    char rom[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int decimal = stoi(s);

    while(true) {

        if(decimal >= 1000) {

            decimal = decimal - 1000;
            roman = roman + rom[0];
            
        } else if (decimal >= 900) {
            decimal = decimal - 900;
            roman = roman + 'C' + 'M';

        } else if (decimal >= 500) {

            decimal = decimal - 500;
            roman = roman + rom[1];
        } else if (decimal >= 400) {
            decimal = decimal - 400;
            roman = roman + 'C' + 'D';

        } else if (decimal >= 100) {

            decimal = decimal - 100;
            roman = roman + rom[2];
        } else if (decimal >= 90) {

            decimal = decimal - 90;
            roman = roman + 'X' + 'C';
        } else if (decimal >= 50) {

            decimal = decimal - 50;
            roman = roman + rom[3];
        } else if (decimal >= 40) {
            decimal = decimal - 90;
            roman = roman + 'X' + 'L';

        } else if (decimal >= 10) {

            decimal = decimal - 10;
            roman = roman + rom[4];
        } else if(decimal >= 9) {

            decimal = decimal - 90;
            roman = roman + 'I' + 'X';

        } else if (decimal >= 5) {

            decimal = decimal - 5;
            roman = roman + rom[5];
        } else if (decimal >= 4) {

            decimal = decimal - 90;
            roman = roman + 'I' + 'V';

        } else if (decimal >= 1) {

            decimal = decimal - 1;
            roman = roman + rom[6];
        } else {
            break;
        }
    }
/*
    int count = 0;
    while(true) {

        if(romanRep[count] > 0) {
                
            roman = roman + rom[count];
            romanRep[count] -= 1;
            if(romanRep[count] == 0) {
                count++;
            }
        } else {
            count++;
        }
        if (count == size) {

            break;
        }

    }
*/

    return roman;
}

int main() {

    string num;

    cout << "Hello!! Welcome to Roman Number Conversion" << endl;
    cout << "Please enter a value to convert:" << endl;

    getline(cin, num);

    if(isValidDecimalNumber(num)) {

        cout << "Valid Decimal" << endl;
        string roman = convertDecimalToRoman(num);
        cout << num << " in roman numeral form is: " << roman << endl;

    } else {

        cout << "Invalid Decimal" << endl;
    }

    if(isValidRomanNumber(num)) {

        cout << "Valid Roman Numeral" << endl;
        string decimal = convertRomanToDecimal(num);
        cout << num << " in decimal form is: " << decimal << endl;


    } else {

        cout << "Invalid Roman Numeral" << endl;
    }


    return 0;
}






