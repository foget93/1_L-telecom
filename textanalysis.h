#ifndef TEXTANALYSIS_H
#define TEXTANALYSIS_H

#include <QString>

class textAnalysis
{
public:
    virtual ~textAnalysis() {}
    virtual void analysis(const QString& text) = 0;
};



class algorithm_A : public textAnalysis
{
    void analysis(const QString& text) override final;
}; //кол-во повторений каждого символа символа.

class algorithm_B : public textAnalysis
{
    void analysis(const QString& text) override final;
}; //распределение слов по их длинам (кол-во слов длинной 1 символ, 2 символа и тд ).

#endif // TEXTANALYSIS_H
