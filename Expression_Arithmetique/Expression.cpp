#include "Expression.h"

Expression::Expression(const string& expr):expression(expr)
{
}

bool Expression::estOperateur(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool Expression::estOperande(char c)
{
    return (isdigit(c) || isalpha(c));
}

bool Expression::verifierExpression()
{
    Stack<char> pile(10);
    bool Operande = false;  // Indique si le dernier caractère est un opérande
    bool Operateur = false; // Indique si le dernier caractère est un opérateur

    for (int i = 0; i < this->expression.length(); i++) {
        char c = this->expression[i];

        // Ignorer les espaces
        if (isspace(c)) continue;

        // Si c'est une parenthèse ouvrante, empiler
        if (c == '(' || c == '{' || c == '[') {
            pile.push(c);
            Operande = false;
            Operateur = false;
        }
        // Si c'est une parenthèse fermante, vérifier l'équilibre
        else if (c == ')' || c == '}' || c == ']') {
            if (pile.IsEmpty() ||
                (c == ')' && pile.Sommet() != '(') ||
                (c == '}' && pile.Sommet() != '{') ||
                (c == ']' && pile.Sommet() != '[')) {
                return false;  // Parenthèse mal appariée
            }
            pile.pop();
            Operande = true;
            Operateur = false;
        }
        // Si c'est un opérande (chiffre ou lettre)
        else if (estOperande(c)) {
            
            Operande = true;
            Operateur = false;
        }
        // Si c'est un opérateur
        else if (estOperateur(c)) {
            if (!Operande) {
                return false;  // Opérateur sans opérande avant lui 
            }
            Operateur = true;
            Operande = false;
        }
        // Si c'est un caractère invalide
        else {
            return false;  // Expression invalide
        }
    }

    // Vérifier si la pile est vide et que l'expression ne se termine pas par un opérateur
    return pile.IsEmpty() && Operande;
}
