// #include "mainwindow.h"
#include <QApplication>
#include "calculatordialog.h"
#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    // cout<<"app"<<endl;
    // MainWindow w;
    // cout<<"w"<<endl;
    CalculatorDialog dlg;

    dlg.show();
    // dlg.exec();
    // cout<<"dlg"<<endl;
    // w.show();
    // cout<<"show"<<endl;
    // if(dlg.exec() == QDialog::Accepted)
    // {
    //     w.show();
    //     cout<<"show"<<endl;
    // }
    return app.exec();
}
