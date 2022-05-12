#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

int getNumeroLinhas(std::string nomeArquivo){
    std::ifstream arquivo{nomeArquivo};

    if(arquivo.is_open()==false){
      throw std::runtime_error{"Could not open file!"};
    }

    int numeroLinhas=0;
    std::string linha;

    while(getline(arquivo, linha)){
      numeroLinhas++;
    }

    arquivo.close();

    return numeroLinhas;
}


int getNumeroCaracteres(std::string nomeArquivo){
    std::ifstream arquivo{nomeArquivo};

    if(arquivo.is_open()==false){
      throw std::runtime_error{"Could not open file!"};
    }

    int numeroCaracteres=0;
    std::string linha;

    while(getline(arquivo, linha)){
      numeroCaracteres+=linha.length();
    }

    arquivo.close();

    return numeroCaracteres;
}

int getNumeroPalavras(std::string frase){
  int numeroPalavras=0;

  if(frase.length()==0){
    return numeroPalavras;
  }

  for(int i=0; frase[i]!='\0'; i++){
    if(frase[i]==' '){
      numeroPalavras++;
    }
  }

  return numeroPalavras+1;
}

int getNumeroEspacos(std::string frase){
  int numeroEspacos=0;

  for(char letra : frase){
    if(isspace(letra)){
      numeroEspacos++;
    }
  }

  return numeroEspacos;
}

int getNumeroVogais(std::string frase){
  int numeroVogais=0;

  char vogais[]={'a','e','i','o','u','A','E','I','O','U'};

  for(char letra : frase){
    for(char vogal : vogais){
      if(letra == vogal){
        numeroVogais++;
      }
    }
  }

  return numeroVogais;
}

void infoLinhas(std::string linha){
  std::cout << getNumeroEspacos(linha) << " ";
  std::cout << getNumeroVogais(linha) << std::endl;
}

void infoArquivoLinhas(std::string nomeArquivo){
  std::ifstream arquivo{nomeArquivo};

  if(arquivo.is_open()==false){
    throw std::runtime_error{"Could not open file!"};
  }

  std::string linha;

  while(getline(arquivo, linha)){
    infoLinhas(linha);
  }

  arquivo.close();
}

int main(){
    std::vector<std::string> linhas;
    std::string linha;

    int *numeroCaracteres=new int;
    int *numeroLinhasVazias=new int;

    while(std::cin.eof()==false){
      std::getline(std::cin, linha);
      linhas.push_back(linha);
      *numeroCaracteres+=linha.length();
      if(linha.empty()){
        *numeroLinhasVazias+=1;
      }
    }

    std::cout << linhas.size() << " ";
    std::cout << *numeroLinhasVazias << " ";
    std::cout << *numeroCaracteres << std::endl;

    delete numeroCaracteres;
    delete numeroLinhasVazias;

    for(std::string linha : linhas){
      infoLinhas(linha);
    }

    return 0;
}
