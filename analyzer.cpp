#include "analyzer.h"

/*
 * private:
 *      abstractAlgorithm* pAlgorithm;
 */
Analyzer::Analyzer(abstractAlgorithm* algorithm)
    : p_algorithm{algorithm}
{

}

Analyzer::~Analyzer()
{
    delete p_algorithm;
}

QString Analyzer::executeAlgorithm(const QString& text)
{
    if (p_algorithm)
        return p_algorithm->analysis(text);
    else return text;
}
