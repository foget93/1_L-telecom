#include <QCoreApplication>

#include <QFile>
#include <QTextStream>


#include "analyzer.h"
#include "server.h"

int main(int argc, char *argv[])
{


    QCoreApplication a(argc, argv);
    Server server;
//    //QFile file ("/home/dmitrii/Downloads/test.txt");
//    QFile file ("C:\\Users\\Дмитрий\\Desktop\\Новый текстовый документ (2).txt");
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        qDebug() << "File is not open!\n";
//        return -1;
//    }


//    QTextStream in(&file);
//    QString text;
//    text = in.readAll();

//    qDebug() << text;
////============================================================


//    Analyzer testAlg1 (new algorithm_A);
//    qDebug() << testAlg1.executeAlgorithm(text);

//    Analyzer testAlg2 (new algorithm_B);
//    qDebug() << testAlg2.executeAlgorithm(text);



    return a.exec();
}
