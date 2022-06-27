#include "abstractAlgorithm.h"
#include <QMap>
#include <QDebug>
#include <QRegularExpression>
#include <chrono>

QString algorithm_A::analysis(const QString& text)
{
    QString result = "===new===\n";
    auto begin = std::chrono::steady_clock::now();

    QMap<QChar, qsizetype> mapSymbols;
    for (qsizetype i {0}; i < text.length(); ++i)
        ++mapSymbols[text[i]];

    for (auto it = mapSymbols.constBegin(); it != mapSymbols.constEnd(); it++)
        result += it.key() + '\t' + QString::number(it.value()) + '\n';
        //qDebug() << it.key() << "\t" << it.value();
    result += "========================================================\n";
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //qDebug() << result;

    qDebug() << "The time: " << elapsed_ms.count() << " ms\n";

    qDebug() << text.length() <<"\n===================================================";
    return result;
}

//======================================================================================

QString algorithm_B::analysis(const QString& text)
{
    QString result;
    auto begin = std::chrono::steady_clock::now();
    auto exp = QRegularExpression(QString("\\W"), QRegularExpression::UseUnicodePropertiesOption); //для винды, проверить убунту
    QStringList str = text.split(exp, Qt::SkipEmptyParts);
    QMap<size_t, size_t> mapCountWords;
    for (const auto& s : str)
    {
        ++mapCountWords[s.length()];
        //qDebug() << *it;
    }
    for (auto it = mapCountWords.constBegin(); it != mapCountWords.constEnd(); it++)
        result += QString::number(it.key()) + '\t' + QString::number(it.value()) + '\n';
        //qDebug() << QString::number(it.key()) + " " + QString::number(it.value()) + ' ';
    result += "========================================================";
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    //qDebug() << result;


    qDebug() << "The time: " << elapsed_ms.count() << " ms\n";
    qDebug() << text.length() <<"\n===================================================";

    return result;
}

//======================================================================================

Analyzer::Analyzer(abstractAlgorithm* algorithm)
    : p_algorithm{algorithm}
{

}

Analyzer::~Analyzer()
{
    if (p_algorithm)
        delete p_algorithm;
}

QString Analyzer::executeAlgorithm(const QString& text)
{
    if (p_algorithm)
        return p_algorithm->analysis(text);
    else return text;
}
