#include <QString>
#include "calculator.h"

#include <iostream>
using namespace std;

Calculator::Calculator()
{

}

Calculator::~Calculator()
{

}

QQueue<QString> Calculator::Split(const QString& formulaStr)
{   // 分离中缀
    QQueue<QString> infix;     // 中缀队列
    QString num = "";           // 数字

    for (int i = 0;i < formulaStr.length();i++)
    {
        if ( (formulaStr[i] == '.') || ((formulaStr[i] >= '0') && (formulaStr[i] <= '9')))
        {
            // 判断小数点和数字，连续的小数点和数字组成一个数
            num += formulaStr[i];
        }
        else if (formulaStr[i] == '(' || formulaStr[i] == ')'
            || formulaStr[i] == '*' || formulaStr[i] == '/')
        {
            // 判断括号和乘除号，若是则数字已完,将数入队,再将运算符入队
            if (!num.isEmpty())
            {
                infix.enqueue(num);
                num.clear();
            }
            infix.enqueue(formulaStr[i]);
        }
        else if (formulaStr[i] == '+' || formulaStr[i] == '-')
        {
            // 判断加减号，特殊处理
            if (i == 0)
            {
                // 表达式开头，是正负号
                num += formulaStr[i];
            }
            else if (formulaStr[i-1] == '(' || formulaStr[i-1] == '+' ||
            formulaStr[i-1] == '-' || formulaStr[i-1] == '*' || formulaStr[i-1] == '/')
            {
                // 前面是左括号或者运算符，是正负号
                num += formulaStr[i];
            }
            else
            {
                // 否则是加减运算符
                if (!num.isEmpty())
                {
                    infix.enqueue(num);
                    num.clear();
                }
                infix.enqueue(formulaStr[i]);
            }

        }
    }

    // 遍历完成，判断是否还有数字
    if (!num.isEmpty())
    {
        infix.enqueue(num);
        num.clear();
    }
    // cout<<"Split: "<<infix.size()<<endl;
    return infix;
}

QQueue<QString> Calculator::Transfer(QQueue<QString>& infix)
{
    // 将中缀队列转换为后缀队列
    QStack<QString> stack;
    QQueue<QString> suffix;
    bool num_ok;                // 表示是否转换成功
    QString tmp;

    while(!infix.isEmpty())
    {
        tmp = infix.dequeue();  // 出队列
        tmp.toDouble(&num_ok);

        if (num_ok == true)
        {
            stack.push(tmp);
        }
        else if(tmp == "+" || tmp == "-")
        {
            while (!stack.isEmpty() && (stack.top() != "("))
            {
                // 取出栈顶运算符并入队列
                suffix.enqueue(stack.pop());
            }
            stack.push(tmp);
        }
        else if(tmp == "*" || tmp == "/")
        {
            while (!stack.isEmpty() && (stack.top() != "(") &&
                (stack.top() != "+") && (stack.top() != "-"))
            {
                // 取出栈顶运算符并入队列
                suffix.enqueue(stack.pop());
            }
            stack.push(tmp);
        }
        else if(tmp == "(")
        {
            stack.push(tmp);
        }
        else if(tmp == ")")
        {
            while (!stack.isEmpty() && (stack.top() != "("))
            {
                // 取出栈顶运算符并入队列
                suffix.enqueue(stack.pop());
            }
            if(stack.top() == "(")
            {
                stack.pop();
            }
        }
    }

    // 遍历完成，判断栈里是否为空
    while (!stack.isEmpty() && (stack.top() != "("))
    {
        // 取出栈顶运算符并入队列
        suffix.enqueue(stack.pop());
    }

    // cout<<"Transfer: "<<suffix.size()<<endl;
    return suffix;
}

QString Calculator::ValidNum(QString str)
{
    QString num;

    if (str.indexOf(".") == -1)
    {
        // 判断是否小数
        return str;
    }

    while (str.length() > 1)
    {
        // 避免0被去掉
        num = str.right(1);
        if (num == "." || num == "0")
        {
            // 对于小数若末尾为小数点或0则去掉
            str.chop(1);
            if (num == ".")
            {
                return str;
            }
        }
        else
        {
            return str;
        }
    }

    return str;
}

QString Calculator::Calculate(QString& l,QString& op,QString& r)
{
    double left,right,result;
    QString resultStr = "";
    left = l.toDouble();
    right = r.toDouble();
    result = 0;

    if (op == "+")
    {
        result = left + right;
    }
    else if (op == "-")
    {
        result = left - right;
    }
    else if (op == "*")
    {
        result = left * right;
    }
    else if (op == "/")
    {
        if ((right > (-0.000000000000001)) && (right < (0.000000000000001)))
        {
            // cout<<"right: "<<right<<endl;
            return NULL;
        }
        else
        {
            result = left/right;
        }
    }

    resultStr = QString::number(result,10,5);
    // cout<<"result: "<<resultStr.toStdString()<<endl;
    // resultStr.sprintf("%f",result);
    return resultStr;
}

QString Calculator::Calculate(QQueue<QString>& suffix)
{
    QStack<QString> stack;
    QString tmp,L,R,op,result;
    bool num_ok;

    while (!suffix.isEmpty())
    {
        tmp = suffix.dequeue();
        tmp.toDouble(&num_ok);

        if (num_ok == true)
        {
            stack.push(tmp);
        }
        else
        {
            if (stack.size() < 2)
            {
                return "Error";
            }
            R = stack.pop();
            L = stack.pop();
            result = Calculate(L,tmp,R);
            if (result == NULL)
            {
                // cout<<"Calculate"<<endl;
                return result;
            }
            stack.push(result);
        }
    }

    if (stack.size() == 1)
    {
        QString str = stack.pop();
        // cout<<"Calculate: "<<str.toStdString()<<endl;
        return ValidNum(str);
    }
    else
    {
        return "Error";
    }
}

QString Calculator::Result(QString& formulaStr)
{
    // cout<<"Result: "<<formulaStr.toStdString()<<endl;
    QQueue<QString> infix = Split(formulaStr);
    infix = Transfer(infix);
    return Calculate(infix);
}
