#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <iostream>
#include <QString>
#include <QMessageBox>

#include <calculatordialog.h>
#include <calculator.h>

using namespace std;

CalculatorDialog::CalculatorDialog(QWidget *parent) : QDialog(parent)
{

    bracket_cnt = 0;
    // 界面创建与布局
    iniUI();
    // 信号与槽的关联
    // cout<<"iniUI"<<endl;
    iniSignalSlots();
    // cout<<"iniSignalSlots"<<endl;
    setWindowTitle("Calculator");
    // cout<<"setWindowTitle"<<endl;
}

CalculatorDialog::~CalculatorDialog()
{

}

void CalculatorDialog::iniUI()
{

    // 创建文本框
    // txtEdit = new QLineEdit();
    formulaEdit = new QLineEdit();
    // formulaEdit->setText("formulaEdit");
    formulaEdit->setAlignment(Qt::AlignRight);     // 设置显示字符串向右边对齐
    formulaEdit->setReadOnly(true);                // 设置对话框不能输入
    resultEdit = new QLineEdit();
    // resultEdit->setText("resultEdit");
    resultEdit->setAlignment(Qt::AlignRight);     // 设置显示字符串向右边对齐
    resultEdit->setReadOnly(true);                // 设置对话框不能输入

    // 逐行创建QPushButton，并水平布局
    bracketLeftBtn = new QPushButton(tr("("));    // 左括号
    bracketRightBtn = new QPushButton(tr(")"));   // 右括号
    backspaceBtn = new QPushButton(tr("<-"));        // 百分号
    clearBtn = new QPushButton(tr("C"));          // 清除
    QHBoxLayout *HLay1 = new QHBoxLayout;
    HLay1->addWidget(bracketLeftBtn);
    HLay1->addWidget(bracketRightBtn);
    HLay1->addWidget(backspaceBtn);
    HLay1->addWidget(clearBtn);

    num7Btn = new QPushButton(tr("7"));           // 数字7
    num8Btn = new QPushButton(tr("8"));           // 数字8
    num9Btn = new QPushButton(tr("9"));           // 数字9
    divisionBtn = new QPushButton(tr("/"));       // 除号
    QHBoxLayout *HLay2 = new QHBoxLayout;
    HLay2->addWidget(num7Btn);
    HLay2->addWidget(num8Btn);
    HLay2->addWidget(num9Btn);
    HLay2->addWidget(divisionBtn);

    num4Btn = new QPushButton(tr("4"));           // 数字4
    num5Btn = new QPushButton(tr("5"));           // 数字5
    num6Btn = new QPushButton(tr("6"));           // 数字6
    multiplicationBtn = new QPushButton(tr("*")); // 乘号
    QHBoxLayout *HLay3 = new QHBoxLayout;
    HLay3->addWidget(num4Btn);
    HLay3->addWidget(num5Btn);
    HLay3->addWidget(num6Btn);
    HLay3->addWidget(multiplicationBtn);

    num1Btn = new QPushButton(tr("1"));           // 数字1
    num2Btn = new QPushButton(tr("2"));           // 数字2
    num3Btn = new QPushButton(tr("3"));           // 数字3
    minusBtn = new QPushButton(tr("-"));;          // 减号
    QHBoxLayout *HLay4 = new QHBoxLayout;
    HLay4->addWidget(num1Btn);
    HLay4->addWidget(num2Btn);
    HLay4->addWidget(num3Btn);
    HLay4->addWidget(minusBtn);

    num0Btn = new QPushButton(tr("0"));           // 数字0
    dotBtn = new QPushButton(tr("."));            // 小数点
    equalsBtn = new QPushButton(tr("="));         // 等号
    plusBtn = new QPushButton(tr("+"));           // 加号
    QHBoxLayout *HLay5 = new QHBoxLayout;
    HLay5->addWidget(num0Btn);
    HLay5->addWidget(dotBtn);
    HLay5->addWidget(equalsBtn);
    HLay5->addWidget(plusBtn);

    // 创建垂直布局，并设置为主布局
    QVBoxLayout *VLay = new QVBoxLayout;
    // VLay->addWidget(txtEdit);
    VLay->addWidget(formulaEdit);
    VLay->addWidget(resultEdit);
    VLay->addLayout(HLay1);
    VLay->addLayout(HLay2);
    VLay->addLayout(HLay3);
    VLay->addLayout(HLay4);
    VLay->addLayout(HLay5);
    setLayout(VLay);
}

void CalculatorDialog::iniSignalSlots()
{
    connect(bracketLeftBtn,SIGNAL(clicked()),this,SLOT(on_bracketLeftBtn()));
    connect(bracketRightBtn,SIGNAL(clicked()),this,SLOT(on_bracketRightBtn()));
    connect(backspaceBtn,SIGNAL(clicked()),this,SLOT(on_backspaceBtn()));
    connect(clearBtn,SIGNAL(clicked()),this,SLOT(on_clearBtn()));

    connect(num7Btn,SIGNAL(clicked()),this,SLOT(on_numBtn()));
    connect(num8Btn,SIGNAL(clicked()),this,SLOT(on_numBtn()));
    connect(num9Btn,SIGNAL(clicked()),this,SLOT(on_numBtn()));
    connect(divisionBtn,SIGNAL(clicked()),this,SLOT(on_divisionBtn()));

    connect(num4Btn,SIGNAL(clicked()),this,SLOT(on_numBtn()));
    connect(num5Btn,SIGNAL(clicked()),this,SLOT(on_numBtn()));
    connect(num6Btn,SIGNAL(clicked()),this,SLOT(on_numBtn()));
    connect(multiplicationBtn,SIGNAL(clicked()),this,SLOT(on_multiplicationBtn()));

    connect(num1Btn,SIGNAL(clicked()),this,SLOT(on_numBtn()));
    connect(num2Btn,SIGNAL(clicked()),this,SLOT(on_numBtn()));
    connect(num3Btn,SIGNAL(clicked()),this,SLOT(on_numBtn()));
    connect(minusBtn,SIGNAL(clicked()),this,SLOT(on_minusBtn()));

    connect(num0Btn,SIGNAL(clicked()),this,SLOT(on_numBtn()));
    connect(dotBtn,SIGNAL(clicked()),this,SLOT(on_dotBtn()));
    connect(equalsBtn,SIGNAL(clicked()),this,SLOT(on_equalsBtn()));
    connect(plusBtn,SIGNAL(clicked()),this,SLOT(on_plusBtn()));
}

void CalculatorDialog::on_numBtn()
{
    QPushButton *btn = dynamic_cast<QPushButton *>(sender());
    formulaStr.clear();
    formulaStr = formulaEdit->text();
    QString tmp = formulaStr.right(1);

    if (tmp.length() && tmp[0] == ')')
    {
        return;
    }
    formulaEdit->insert(btn->text());
}

void CalculatorDialog::on_bracketLeftBtn()
{
    formulaStr.clear();
    formulaStr = formulaEdit->text();
    QString tmp = formulaStr.right(1);

    if (tmp.length())
    {
        if (MatchingBoth(tmp,")0123456789.") != -1)
        {
            return;
        }
    }

    tmp = formulaStr.right(2);
    if (tmp.length() == 2) {
        // 前面不能有连续两次加减乘除
        if (tmp[0] == '+' || tmp[0] == '-' || tmp[0] == '*' || tmp[0] == '/' || tmp[0] == '(')
        {
            if (tmp[1] == '+' || tmp[1] == '-' || tmp[1] == '*' || tmp[1] == '/') {
                return;
            }
        }
    }
    formulaEdit->insert("(");
    bracket_cnt++;
}

void CalculatorDialog::on_bracketRightBtn()
{
    formulaStr.clear();
    formulaStr = formulaEdit->text();
    QString tmp = formulaStr.right(1);

    if (bracket_cnt == 0)
    {
        return;
    }

    if (tmp.length())
    {
        if (MatchingBoth(tmp,"+-*/.(") != -1)
        {
            return;
        }
    }
    else
    {
        return;
    }
    formulaEdit->insert(")");
    bracket_cnt--;
}

void CalculatorDialog::on_backspaceBtn()
{
    if (formulaEdit->text() != "")
    {
        formulaEdit->backspace();

    }
}

void CalculatorDialog::on_clearBtn()
{
    if (formulaEdit->text() != "" || resultEdit->text() != "")
    {
        formulaStr.clear();
        formulaEdit->clear();
        resultEdit->clear();
    }
}

void CalculatorDialog::on_divisionBtn()
{

    formulaStr.clear();
    formulaStr = formulaEdit->text();
    QString tmp = formulaStr.right(1);

    if (tmp.length())
    {
        if (MatchingBoth(tmp,"(.+-*/") != -1)
        {
            return;
        }
    }
    else
    {
        return;
    }

    formulaEdit->insert("/");
}

void CalculatorDialog::on_multiplicationBtn()
{
    formulaStr.clear();
    formulaStr = formulaEdit->text();
    QString tmp = formulaStr.right(1);

    if (tmp.length())
    {
        if (MatchingBoth(tmp,"(.+-*/") != -1)
        {
            return;
        }
    }
    else
    {
        return;
    }

    formulaEdit->insert("*");
}

void CalculatorDialog::on_minusBtn()
{
    formulaStr.clear();
    formulaStr = formulaEdit->text();
    QString tmp = formulaStr.right(1);

    if (tmp.length() && tmp[0] == '.')
    {
        return;
    }

    tmp = formulaStr.right(2);
    if (tmp.length() == 2) {
        // 前面不能有连续两次加减乘除
        if (tmp[0] == '+' || tmp[0] == '-' || tmp[0] == '*' || tmp[0] == '/' || tmp[0] == '(')
        {
            if (tmp[1] == '+' || tmp[1] == '-' || tmp[1] == '*' || tmp[1] == '/') {
                return;
            }
        }
    }
    formulaEdit->insert("-");
}

void CalculatorDialog::on_dotBtn()
{
    formulaStr.clear();
    formulaStr = formulaEdit->text();
    QString tmp = formulaStr.right(1);

    if (tmp.length())
    {   // 小数点前只能是数字
        if (MatchingBoth(tmp,"0123456789") == -1)
        {   // 没有找到数字
            return;
        }
    }
    else
    {
        formulaEdit->insert("0.");
        return;
    }

    int pos = LastMatchingBoth(formulaStr,"+-*/.()");   // 反向查找
    if (pos != -1 && formulaStr[pos] == '.')
    {
        return;
    }

    formulaEdit->insert(".");
}
void CalculatorDialog::on_equalsBtn()
{
    QString result = "";
    formulaStr.clear();
    formulaStr = formulaEdit->text();
    Calculator calculator;
    result = calculator.Result(formulaStr);

    if (result == "Error")
    {
        QMessageBox::warning(this,"Warning","Error!",QMessageBox::Yes);
    }
    else if (result == NULL)
    {
        QMessageBox::warning(this,"Warning","Divisor cannot be zero!",QMessageBox::Yes);
    }
    else
    {
        // cout<<result<<endl;
        // string s = result.toStdString();
        // cout<<s<<endl;
        formulaEdit->insert("=");
        resultEdit->insert(result);
    }

    // resultEdit->clear();
    // resultEdit->insert(formulaEdit->text());
    // formulaEdit->insert("=");
}

void CalculatorDialog::on_plusBtn()
{
    formulaStr.clear();
    formulaStr = formulaEdit->text();
    QString tmp = formulaStr.right(1);

    if (tmp.length() && tmp[0] == '.')
    {
        return;
    }
    else if (tmp.length() == 0)
    {
        return;
    }

    tmp = formulaStr.right(2);
    if (tmp.length() == 2) {
        // 前面不能有连续两次加减乘除
        if (tmp[0] == '+' || tmp[0] == '-' || tmp[0] == '*' || tmp[0] == '/' || tmp[0] == '(')
        {
            if (tmp[1] == '+' || tmp[1] == '-' || tmp[1] == '*' || tmp[1] == '/') {
                return;
            }
        }
    }

    formulaEdit->insert("+");
}

int CalculatorDialog::LastMatchingBoth(QString& str1,const char* str2)
{   // 反向匹配str1 和str2，判断str1中是否有str2中的字符
    for (int i = str1.length();i >= 0;i--)
    {
        for (unsigned int j = 0;j < strlen(str2);j++)
        {
            if (str1[i] == str2[j])
            {
                return i;
            }
        }
    }

    return -1;
}

int CalculatorDialog::MatchingBoth(QString& str1,const char* str2)
{   // 匹配str1 和str2，判断str1中是否有str2中的字符
    for (int i = 0;i < str1.length();i++)
    {
        for (unsigned int j = 0;j < strlen(str2);j++)
        {
            if (str1[i] == str2[j])
            {
                return i;
            }
        }
    }

    return -1;
}
