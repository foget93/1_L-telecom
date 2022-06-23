#include "analyzer.h"

/*
 * private:
 *      textAnalysis* pAlgorithm;
 */
Analyzer::Analyzer(textAnalysis* algorithm)
    : p_algorithm{algorithm}
{

}

Analyzer::~Analyzer()
{
    delete p_algorithm;
}

void Analyzer::executeAlgorithm(const QString& text)
{
    p_algorithm->analysis(text);
}
