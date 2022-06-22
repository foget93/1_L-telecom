#include <QCoreApplication>
#include <QStringList>
#include <QMultiMap>
#include <QStringList>
#include <QStringView>
#include <QFile>
#include <QTextStream>
#include <QMap>
#include <QRegularExpression>
#include <chrono>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    QFile file ("/home/dmitrii/Downloads/test.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "File is not open!\n";
        return -1;
    }
    auto begin = std::chrono::steady_clock::now();

    QTextStream in(&file);
    QString text;
    text = in.readAll();

//===============================================================
    QMap<QChar, size_t> mapSymbols;
    for (size_t i {0}; i < text.size(); ++i)
    {
        ++mapSymbols[text[i]];
    }

//    auto itSymbols = mapSymbols.constBegin();
//    while (itSymbols != mapSymbols.constEnd()) {
//        qDebug() << itSymbols.key() << " " << itSymbols.value();
//        ++itSymbols;
//    }

    for (auto it = mapSymbols.constBegin(); it != mapSymbols.constEnd(); it++)
        qDebug() << it.key() << "\t" << it.value();
//===============================================================

    QStringList str = text.split(QRegularExpression("\\W"), Qt::SkipEmptyParts);
    QMap<size_t, size_t> mapCountWords;
    for (const auto& s : str)
    {
        ++mapCountWords[s.length()];
        //qDebug() << *it;
    }
    for (auto it = mapCountWords.constBegin(); it != mapCountWords.constEnd(); it++)
        qDebug() << it.key() << "\t" << it.value();

    qDebug() << str.length();


    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    qDebug() << "The time: " << elapsed_ms.count() << " ms\n";
    return a.exec();
}
