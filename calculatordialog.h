#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

class CalculatorDialog : public QDialog
{
    Q_OBJECT

private:

    // 文本框定义
    // QLineEdit *txtEdit;
    QLineEdit *formulaEdit;
    QLineEdit *resultEdit;

    QPushButton *bracketLeftBtn;    // 左括号
    QPushButton *bracketRightBtn;   // 右括号
    QPushButton *backspaceBtn;        // 百分号
    QPushButton *clearBtn;          // 清除
    QPushButton *num7Btn;           // 数字7
    QPushButton *num8Btn;           // 数字8
    QPushButton *num9Btn;           // 数字9
    QPushButton *divisionBtn;       // 除号
    QPushButton *num4Btn;           // 数字4
    QPushButton *num5Btn;           // 数字5
    QPushButton *num6Btn;           // 数字6
    QPushButton *multiplicationBtn; // 乘号
    QPushButton *num1Btn;           // 数字1
    QPushButton *num2Btn;           // 数字2
    QPushButton *num3Btn;           // 数字3
    QPushButton *minusBtn;          // 减号
    QPushButton *num0Btn;           // 数字0
    QPushButton *dotBtn;            // 小数点
    QPushButton *equalsBtn;         // 等号
    QPushButton *plusBtn;           // 加号

    // UI 初始化与创建
    void iniUI();
    // 初始化信号与槽的链接
    void iniSignalSlots();

private slots:

    // 定义各按钮的槽函数
    void on_numBtn();           // 数字7
    void on_bracketLeftBtn();    // 左括号
    void on_bracketRightBtn();   // 右括号
    void on_backspaceBtn();      // 百分号
    void on_clearBtn();          // 清除
    void on_divisionBtn();       // 除号
    void on_multiplicationBtn(); // 乘号
    void on_minusBtn();          // 减号
    void on_dotBtn();            // 小数点
    void on_equalsBtn();         // 等号
    void on_plusBtn();           // 加号

    // 输入公式
    // void formulaInput(char *ch);
    // 结果输出
    // void resultOutput();

public:

    QString formulaStr;
    int bracket_cnt;

    CalculatorDialog(QWidget *parent = 0);
    ~CalculatorDialog();
    int LastMatchingBoth(QString& str1,const char* str2);
    int MatchingBoth(QString& str1,const char* str2);
};

#endif //CALCULATORDIALOG_H
