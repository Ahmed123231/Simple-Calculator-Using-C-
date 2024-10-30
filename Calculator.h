#ifndef CALCULATOR_H
#define CALCULATOR_H



void PrintWelcomeMessage(void);


double GetFirstOperand(void);

double GetSecondOperand(void);

char GetOperator(void);

double CalculateResult(double (*GetFirstOperand)(void), double (*GetSecondOperand)(void), char (*GetOperator)(void));

void PrintResult(double(*CalculateResult)(double (*GetFirstOperand)(void), double (*GetSecondOperand)(void), char (*GetOperator)(void)));

void RunCalculator(void);





#endif //CALCULATOR_H