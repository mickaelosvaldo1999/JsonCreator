#include <iostream>
#include <fstream>
#include <Pessoa.h>
#include "json/json.h"
using namespace std;

int main()
{
    //criando variáveis
    string chat;
    int num;
    //abrindo arquivo existente ou criando.
    fstream file("config.json",ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Arquivo criado!!" << endl;
        file.open("config.json", ios::out);
        file.close();
        file.open("config.json",ios::in | ios::out);
    } else {
        cout << "Arquivo ja existente!" << endl;
    }

    Json::StyledWriter styledWriter;
    Json::Value newValue;
    cout << "digite um nome: " << endl;
    cin >> chat;
    newValue["nome"] = chat;
    cout << "digite um id: " << endl;
    cin >> num;
    newValue["id"] = num;
    cout << "digite uma faculdade: " << endl;
    cin >> chat;
    newValue["faculdade"] = chat;
    cout << styledWriter.write(newValue) << "oi" << endl;
   if (file.is_open()) {
      Json::Value root;
      Json::Reader reader;
      reader.parse(file,root);
      root["pessoa"][root["pessoa"].size()] = newValue;
      cout << "arquivo inteiro: " << endl;
      cout << root << endl;
      //Impremindo todos os nomes na tela.
      for (int i = 0; i < root["pessoa"].size(); i++) {
        cout << "Nome em formato de variável: " << root["pessoa"][i]["nome"].asString() << endl;
      };
      file.close();
      //Escrevendo o novo arquivo.
      file.open("config.json", ios::out);
      file << root;
      file.close();
   }
    return 0;
}
