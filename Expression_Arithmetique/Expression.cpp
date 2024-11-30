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
    bool Operande = false;  // Indique si le dernier caract�re est un op�rande
    bool Operateur = false; // Indique si le dernier caract�re est un op�rateur

    for (int i = 0; i < this->expression.length(); i++) {
        char c = this->expression[i];

        // Ignorer les espaces
        if (isspace(c)) continue;

        // Si c'est une parenth�se ouvrante, empiler
        if (c == '(' || c == '{' || c == '[') {
            pile.push(c);
            Operande = false;
            Operateur = false;
        }
        // Si c'est une parenth�se fermante, v�rifier l'�quilibre
        else if (c == ')' || c == '}' || c == ']') {
            if (pile.IsEmpty() ||
                (c == ')' && pile.Sommet() != '(') ||
                (c == '}' && pile.Sommet() != '{') ||
                (c == ']' && pile.Sommet() != '[')) {
                return false;  // Parenth�se mal appari�e
            }
            pile.pop();
            Operande = true;
            Operateur = false;
        }
        // Si c'est un op�rande (chiffre ou lettre)
        else if (estOperande(c)) {
            
            Operande = true;
            Operateur = false;
        }
        // Si c'est un op�rateur
        else if (estOperateur(c)) {
            if (!Operande) {
                return false;  // Op�rateur sans op�rande avant lui 
            }
            Operateur = true;
            Operande = false;
        }
        // Si c'est un caract�re invalide
        else {
            return false;  // Expression invalide
        }
    }

    // V�rifier si la pile est vide et que l'expression ne se termine pas par un op�rateur
    return pile.IsEmpty() && Operande;
}
