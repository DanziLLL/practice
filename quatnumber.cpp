#include "quatnumber.h"

quatNumber::quatNumber()
{
    value = 0;
}

QString quatNumber::add(quatNumber a, quatNumber b) {
    QString numA = QString::number(a.value);
    QString numB = QString::number(b.value);
    QString res = "";
    int len, digA, digB, digR;
    bool transition = false;
    if (numA.length() < numB.length()) {
        len = numB.length() + 1;
        numB = "0" + numB;
        for (int i = 0; i <= len - numA.length(); i++) { //making numbers length equal
            numA = "0" + numA;
        }
    }
    else if ( numB.length() < numA.length()) {
        len = numA.length() + 1;
        numA = "0" + numA;
        for (int i = 0; i <= len - numB.length(); i++) { //making numbers length equal
            numB = "0" + numB;
        }
    }
    else if (numA.length() == numB.length()) {
        len = numA.length() + 1;
        numA = "0" + numA;
        numB = "0" + numB;
    }
    for (int j = len - 1; j >= 0; j--) {
        digA = numA.at(j).unicode() - 48;
        digB = numB.at(j).unicode() - 48;
        digR = digA + digB + (int)transition;
        transition = false;
        if (digR > 3) { // transit 1 to next greater digit
            digR = digR - 4;
            transition = true;
        }
        res = QString::number(digR) + res;
    }
    return this->cutZeroes(res);
}

QString quatNumber::sub(quatNumber a, quatNumber b) {
    QString numA = QString::number(a.value);
    QString numB = QString::number(b.value);
    QString res = "";
    int len, digA, digB, digR;
    bool transition = false;
    if (a.value < b.value) {
        return "ERROR";
    }
    else if ( numB.length() < numA.length()) {
        len = numA.length();
        for (int i = 0; i <= len - numB.length(); i++) { //making numbers length equal
            numB = "0" + numB;
        }
    }
    else if (numA.length() == numB.length()) {
        len = numA.length() + 1;
        numA = "0" + numA;
        numB = "0" + numB;
    }
    for (int j = len - 1; j >= 0; j--) {
        digA = numA.at(j).unicode() - 48;
        digB = numB.at(j).unicode() - 48;
        digR = digA - digB - (int)transition;
        transition = false;
        if (digR < 0) {
            digR = digR + 4;
            transition = true;
        }
        res = QString::number(digR) + res;
    }
    return this->cutZeroes(res);
}

int quatNumber::converse() {
    int res = 0;
    QString s = QString::number(this->value);
    for (int i = (s.length() - 1); i >= 0; i--) {
        int n = s.at(i).unicode() - 48; // converting char to integer
        res += n * (int)pow(4, (s.length() - i - 1));
    }
    return res;
}

bool quatNumber::check(int val) {
    QString s = QString::number(val);
    for (int i = 0; i < s.length(); i++) {
        int n = s.at(i).unicode() - 48; // converting char to integer
        if ((n >= 4) || (n < 0)) {
            return false;
        }
    }
    return true;
}

bool quatNumber::set(int val) {
    if (this->check(val)) { // if quaternary number is ok, we set its value to origin object
        this->value = val; // and return from function with code "true"
        return true;
    }
    return false;
}

QString quatNumber::cutZeroes(QString n) {
    int i = 0;
    while (n.at(0) == '0') {
        if (n.length() == 1) {
            break;
        }
        n.remove(0, 1);
        i++;
    }
    return n;
}
