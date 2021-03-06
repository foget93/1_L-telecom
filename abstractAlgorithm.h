#ifndef ABSTRACTALGORITHM_H
#define ABSTRACTALGORITHM_H

#include <QString>

class abstractAlgorithm
{
public:
    virtual ~abstractAlgorithm() {}
    virtual QString analysis(const QString& text) = 0;
};



class algorithm_A : public abstractAlgorithm
{
    QString analysis(const QString& text) override final;
}; //кол-во повторений каждого символа символа.

class algorithm_B : public abstractAlgorithm
{
    QString analysis(const QString& text) override final;
}; //распределение слов по их длинам (кол-во слов длинной 1 символ, 2 символа и тд ).

//=======================================================================================

class Analyzer
{
public:
    Analyzer(abstractAlgorithm* algorithm = nullptr); //изменить nullptr или проверять
    ~Analyzer();
    QString executeAlgorithm(const QString& text);

private:
    abstractAlgorithm* p_algorithm;
};

#endif // ABSTRACTALGORITHM_H
