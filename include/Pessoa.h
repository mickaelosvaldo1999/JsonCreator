#ifndef PESSOA_H
#define PESSOA_H
#include <string>
class Pessoa
{
    public:
        Pessoa(std::string _nome,int _id);
        virtual ~Pessoa();
        std::string nome;
        int id;
        void SetCreditCard(std::string _cd);
        std::string GetCreditCard();
    private:
        std::string CreditCard;
};

#endif // PESSOA_H
