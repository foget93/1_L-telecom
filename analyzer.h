#ifndef ANALYZER_H
#define ANALYZER_H

#include "abstractAlgorithm.h"

class Analyzer
{
public:
    Analyzer(abstractAlgorithm* algorithm = nullptr); //изменить nullptr или проверять
    ~Analyzer();
    QString executeAlgorithm(const QString& text);

private:
    abstractAlgorithm* p_algorithm;
};

#endif // ANALYZER_H
