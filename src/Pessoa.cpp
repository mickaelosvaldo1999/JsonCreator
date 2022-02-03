#include "Pessoa.h"
using namespace std;
Pessoa::Pessoa(string _nome,int _id)
{
    nome = _nome;
    id = _id;
}

Pessoa::~Pessoa()
{
    //dtor
}
void Pessoa::SetCreditCard(string _cd)
{
    CreditCard = _cd;
};

string Pessoa::GetCreditCard()
{
    return CreditCard;
};
