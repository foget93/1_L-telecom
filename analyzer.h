#ifndef ANALYZER_H
#define ANALYZER_H

#include "textanalysis.h"

class Analyzer
{
public:
    Analyzer(textAnalysis* algorithm = nullptr); //изменить nullptr или проверять
    ~Analyzer();
    void executeAlgorithm(const QString& text);

private:
    textAnalysis* p_algorithm;
};

#endif // ANALYZER_H
