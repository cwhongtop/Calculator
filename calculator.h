#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QString>
#include <QStack>
#include <QQueue>

class Calculator
{
private:
    QQueue<QString> Split(const QString& formulaStr);      // 分离前缀
    QQueue<QString> Transfer(QQueue<QString>& infix); // 将中缀队列转换为后缀队列
    QString Calculate(QQueue<QString>& formulaStr);        // 将后缀队列计算出结果

    QString Calculate(QString& l,QString& op,QString& r);
    QString ValidNum(QString str);

public:
    Calculator();
    ~Calculator();

    QString Result(QString& formulaStr);
};

#endif // CALCULATOR_H
