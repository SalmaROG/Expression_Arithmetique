#include"Stack.h"
#include <string>
#include <cctype>
class Expression {
private:
    string expression;
public:
    Expression(const string& expr);
    bool estOperateur(char c);
    bool estOperande(char c);
    bool verifierExpression();
};