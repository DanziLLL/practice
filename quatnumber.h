#ifndef QUATNUMBER_H
#define QUATNUMBER_H
#include <QString>


class quatNumber
{
public:
    quatNumber();
    int value;
    QString add(quatNumber a, quatNumber b);
    QString sub(quatNumber a, quatNumber b);
    int converse();
    bool check(int val);
    bool set(int val);
    QString cutZeroes(QString n);
};

#endif // QUATNUMBER_H
