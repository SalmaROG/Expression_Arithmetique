#include"Expression.h"

int main() {
    string expr;
    cout << "Entrez une expression arithmetique : ";
    getline(cin, expr);

    Expression exp(expr);

    if (exp.verifierExpression()) {
        cout << "L'expression est valide." << endl;
    }
    else {
        cout << "L'expression est invalide." << endl;
    }

    return 0;
}
