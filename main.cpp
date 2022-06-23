#include <QCoreApplication>

#include <QFile>
#include <QTextStream>


#include "analyzer.h"


int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    QFile file ("/home/dmitrii/Downloads/test.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "File is not open!\n";
        return -1;
    }


    QTextStream in(&file);
    QString text;
    text = in.readAll();

//============================================================


    Analyzer testAlg1 (new algorithm_A);
    testAlg1.executeAlgorithm(text);

    Analyzer testAlg2 (new algorithm_B);
    testAlg2.executeAlgorithm(text);



    return a.exec();
}
