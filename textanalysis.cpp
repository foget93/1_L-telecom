#include "textanalysis.h"
#include <QMap>
#include <QDebug>
#include <QRegularExpression>
#include <chrono>

void algorithm_A::analysis(const QString &text)
{
    auto begin = std::chrono::steady_clock::now();

    QMap<QChar, std::size_t> mapSymbols;
    for (qsizetype i {0}; i < text.length(); ++i)
        ++mapSymbols[text[i]];

    for (auto it = mapSymbols.constBegin(); it != mapSymbols.constEnd(); it++)
        qDebug() << it.key() << "\t" << it.value();

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    qDebug() << "The time: " << elapsed_ms.count() << " ms\n";

    qDebug() << text.length() <<"\n===================================================";
}

//======================================================================================

void algorithm_B::analysis(const QString &text)
{
    auto begin = std::chrono::steady_clock::now();

    QStringList str = text.split(QRegularExpression("\\W"), Qt::SkipEmptyParts);
    QMap<qsizetype, qsizetype> mapCountWords;
    for (const auto& s : str)
    {
        ++mapCountWords[s.length()];
        //qDebug() << *it;
    }
    for (auto it = mapCountWords.constBegin(); it != mapCountWords.constEnd(); it++)
        qDebug() << it.key() << "\t" << it.value();

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    qDebug() << "The time: " << elapsed_ms.count() << " ms\n";

    qDebug() << text.length() <<"\n===================================================";
}
