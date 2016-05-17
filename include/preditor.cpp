#include "preditor.h"

Preditor::Preditor(int **matriz, int N_interacts, int predit) {
  this->saltos = matriz;
  this->interacoes = N_interacts;
  this->preditor = predit; // configurando qual o preditor 1 ou 2 bits
  this->resultados = new int*[4]; // suporta todos os saltos
  for(int x = 0;x < 4;x++)
  	this->resultados[x] = new int[N_interacts];
}

void Preditor::processar(void) {
  for(int x = 0;this->saltos[x] != nullptr;x++) { // debug
  	std::cout << "{[" << this->saltos[x][0] << "]";
  	for(int y = 1; y < this->interacoes; y++)
  	 std::cout << "|" << this->saltos[x][y] << "|";
  	std::cout << "}\n";
  }
  std::cout << "\n\n";

 for(int i = 0; this->saltos[i] != nullptr; i++) {
  this->limpar_cache();
  for(int j = 1; j < this->interacoes;j++) { // loop principal que percorre as interações
     if(this->checar_correlacao(i, j)) { // se a correlação diz que o salto exterior não foi tomado
     	this->resultados[i][j] = this->prever(this->saltos[i][j]); // salva o resultado dessa predição para a saida
     }
     else { // se o salto não deve ser tomado por conta de sua correlação...
        this->resultados[i][j] = -1; // -1 significa que esse salto não foi testado
     }
  }
 }

  for(int x = 0;this->saltos[x] != nullptr;x++) { // debug
  	std::cout << "{[" << this->saltos[x][0] << "]";
  	for(int y = 1; y < this->interacoes; y++)
  	 std::cout << "|" << resultados[x][y] << "|";
  	std::cout << "}\n";
  }

}

bool Preditor::checar_correlacao(int i, int j) {
   if(this->saltos[i][0] == 0) return true; // não tem correlação com ninguem
   if(this->saltos[i][0] < 10) { // nesse caso só tem correlação com um outro salto
     if(this->saltos[this->saltos[i][0]-1][j]) return false; // o salto com o qual esse tem correlação foi tomado 
     else return true; // ou não foi tomado
   }
   else { // tem correlação com mais de um salto
   	int *correlacts = extrair_correlacao(this->saltos[i][0]);
     for(int x = 1; x <= correlacts[0]; x++) // percorre todas as correlações
       if(this->saltos[correlacts[x]-1][j]) return false; // se em alguma correlação ouver impedimento retorna false
   	 return true;
   }
}

int *Preditor::extrair_correlacao(int relact) {
	int N = 1; // guarda o numero de correlações
	int casa;
	for(casa = 10; casa <= relact; casa *= 10)
	  N++; // descobrindo quantas correlações ele possui
	  casa /= 10; // agora tenho o valor correspondente a quantidade de casas que o relação possui

	int *retorno = new int[N+1];
	for(int x = N; x >= 0; x--) // zerando vetor
	  retorno[x] = 0;
	  
	for(int x = 1;N > 0;N--) {
	 if(casa < 10) { // caso especial que deve ser executado diferente
		 retorno[x] = relact;
		 retorno[0]++;
		 return retorno;
	 }
	 else { // caso básico em que ainda é nescessário extrair a correlação
		 while(relact > casa){
	      relact -= casa;
	      retorno[x]++; // a quantidade de loops corresponde a o valor daquela casa 
         }
     }
     casa /= 10;
     retorno[0]++;
     x++;
  }
  return retorno;
}

bool Preditor::prever(int x) {
   switch(this->preditor) {
   	case 1: // prever com apenas um bit
   	 return this->bit(x);
   	break;
   	case 2: // prever com dois bits
   	 return this->bits(x);
   	break;
   }
  return true;
}

bool Preditor::bits(int x) { // LOGICA IMPERFEITA NÃO ESTÁ PREVENDO CORRETAMENTE
   if(x == 0) { // o salto não deve ser tomado
    if(this->bitA && this->bitB) { // nesse caso deve mudar um dos bits
      this->bitB = false; // não inverte a predição ainda
       return true; // a predição diz que deve tomar
    }
    else { // só um dos dois bits está marcado como verdadeiro
     this->bitA = false;
     if(this->prediction) { // errou a segunda vez então altera para não tomar salto
      this->prediction = false;
      return true; // note que nessa situação a previsão mudou
     }
     else return false;
    }
   }
   else { // o salto deve ser tomado
    if(!this->bitA && !this->bitB) { // nesse caso deve mudar um dos bits
      this->bitB = true; // não inverte a predição ainda
       return false; // a predição diz que deve tomar
    }
    else { // só um dos dois bits está marcado como verdadeiro
     this->bitA = true;
     if(!this->prediction) { // errou a segunda vez então altera para não tomar salto
      this->prediction = true;
      return false; // note que nessa situação a previsão mudou
     }
     else return true;
    }
   }

   return true; // nunca deve chegar aqui
}

bool Preditor::bit(int x) {
   if(bitA) { // vai tomar o salto
   	if(x == 0) { // se errou na predição
   		bitA = false; // troca a decisão
   		return true; // mas retorna a predição que tinha
   	}
   	else
   		return true; // acertou
   }
   else { // não vai tomar o salto
    if(x == 1) { // se errou na predição
   		bitA = true; // troca a decisão
   		return false; // mas retorna a predição que tinha
   	}
   	else
   		return false; // acertou
   }
}

void Preditor::limpar_cache() {
this->prediction = true;
this->bitA = true;
this->bitB = true;
}
