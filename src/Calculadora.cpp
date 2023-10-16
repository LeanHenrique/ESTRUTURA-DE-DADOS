#include"../include/Calculadora.h"


int prioridade(char c) {
    if (c == '~') {
        return 3; // Prioridade absoluta para ~
    }
    if (c == '&') {
        return 2; // Alta prioridade para &
    } else if (c == '|') {
        return 1; // Prioridade menor para |
    } 
    return 0; // Valor padrão para outros caracteres (como parênteses)
}

int potencia(int base, int expoente) {
    if (expoente == 0) {
        return 1; // Qualquer número elevado a 0 é 1.
    }
    if (expoente < 0) {
        return 1 / (base * potencia(base, -expoente - 1));
    }
    return base * potencia(base, expoente - 1);
}

//calcula as operações & e |
int Operacao(int a, int b, char op) {
    switch (op) {
        case '&':
            return (a * b);
        case '|':
            if (a == 1 && b == 1) {
                return a;
            }
            return (a + b);
        default:
            throw std::runtime_error("Operador inválido");
    }
}

//calcula a negação
int negacao(int a) {
    if (a == 0) {
        return 1;
    } else {
        return 0;
    }
}

//verifica se o caractere é um digito
bool VerificaDigito(char c) {
    return (c >= '0' && c <= '9');
}

//converte os valoress ASCII para inteiro
int ConverteInteiro(char c){
    return c - '0';
}

bool busca(string s, char c){
    for(int i = 0; i < static_cast<int>(s.size());i++){
         if(s[i] == c){
            return true;
         }
    }
    return false;
}

//guarda os quantificadores "a" ou "e" em uma string
string guardaQuant(string expressao){
   string resultado;
   for(int i = 0; i < static_cast<int>(expressao.size());i++){
         if(expressao[i] == 'e' || expressao[i] == 'a'){
            resultado += expressao[i];
         }
    }
    return resultado;
}

int OperacaoB(char c, int a, int b){
    switch (c){
    case 'a':
            if(a == 1 && b == 1){
                return 1;
            }
            return 0;
        case 'e':
            if (a == 1 || b == 1) {
                return 1;
            }
            return 0;
        default:
            throw std::runtime_error("Operador inválido");
    }
}



//trata a expressão de entrada com os valores correspondentes
string trataexpressao(string p, string s) {
   string resultado;

    for (int i = 0; i < static_cast<int>(p.size()); i++) {
        if (VerificaDigito(p[i])) {
            if (i + 1 < static_cast<int>(p.size()) && VerificaDigito(p[i + 1])) {
                int duploDigito = (p[i] - '0') * 10 + (p[i + 1] - '0');
                resultado += s[duploDigito];
                i++; // Pulando o próximo valor da expressão
            } else {
                int digit = p[i] - '0';
                resultado += s[digit];
            }
        } else {
            resultado += p[i];
        }
    }

    return resultado;
}

PilhaEncadeada posfixa(string p) {
    PilhaEncadeada aux; // Pilha auxiliar para operadores
    PilhaEncadeada pos; // Pilha de saída (resultado)
    TipoItem x , y;

    for (int i = 0; i < static_cast<int>(p.size()); i++) {
        x.SetChave(p[i]);

        switch (p[i]) {
            case '(':
                aux.Empilha(x);
                break; 

            case ')':
                while (!aux.Vazia() && aux.Topo().GetChave() != '(') {
                    if(aux.Topo().GetChave() == '~'){
                        y = pos.Desempilha();
                        int a = ConverteInteiro(y.GetChave());
                        y.SetChave(negacao(a)+'0');
                        pos.Empilha(y);
                    if (!aux.Vazia() && aux.Topo().GetChave() == '~') {
                    aux.Desempilha(); // Desempilhar o '('
                }

                        
                    }else{   
                    // Desempilhando e armazenando as variaveis com valor padrão
                    y = pos.Desempilha();
                    int a = ConverteInteiro(y.GetChave());
                    
                    y = pos.Desempilha();
                    int b = ConverteInteiro(y.GetChave());
                    
                    y = aux.Desempilha();
                    int op = y.GetChave();

                    int c = Operacao(a,b,op);

                    //empilhando as variaveis com valor ASCII
                    y.SetChave(c + '0');
                    pos.Empilha(y);
                }
                }

                if (!aux.Vazia() && aux.Topo().GetChave() == '(') {
                    aux.Desempilha(); // Desempilhar o '('
                }
                break;

            case '~':
            {
                //trata negação em caso do proximo valor ser um numero
                if(p[i+2] < static_cast<int>(p.size() ) && VerificaDigito(p[i+2])){
                x.SetChave(p[i + 2]);
                int digit = ConverteInteiro(x.GetChave());
                x.SetChave(negacao(digit) + '0');
                pos.Empilha(x);
                i = i+2; // Avance para o próximo caractere (o operando negado)
                if (!aux.Vazia() && aux.Topo().GetChave() == '~') {
                        aux.Desempilha(); // Desempilhar o '~'
                       }
                break;
            }else{ //empilha o operador caso o proximo valor não for um numero
                aux.Empilha(x);
            }     
             break;
            case '|':
            case '&':
                while (!aux.Vazia() &&  prioridade(aux.Topo().GetChave()) >= prioridade(x.GetChave())) {
                    //tratando negação
                    if(aux.Topo().GetChave() == '~'){
                        y = pos.Desempilha();
                        int a = ConverteInteiro(y.GetChave());
                        y.SetChave(negacao(a)+'0');
                        pos.Empilha(y);
                        if (!aux.Vazia() && aux.Topo().GetChave() == '~') {
                        aux.Desempilha(); // Desempilhar o '~'
                       }
                    }else{   
                    // Deempilhando e armazenando as variaveis com valor padrão
                    y = pos.Desempilha();
                    int a = ConverteInteiro(y.GetChave());
                    
                    y = pos.Desempilha();
                    int b = ConverteInteiro(y.GetChave());
                    
                    y = aux.Desempilha();
                    int op = y.GetChave();

                    int c = Operacao(a,b,op);

                    //empilhando as variaveis com valor ASCII
                    y.SetChave(c + '0');
                    pos.Empilha(y);
                  } 
                }
                aux.Empilha(x); // Empilhar o operador na pilha de operadores
                break;
          
            default:
                if (x.GetChave() != ' ') {
                    if ((VerificaDigito(p[i])))
                    {
                        pos.Empilha(x); // Empilhar operandos na pilha de saída

                    }     
                }
                break;
        }
    }
    }
   while  (!aux.Vazia()){
                    //tratando a negação
                    if(aux.Topo().GetChave() == '~'){
                        y = pos.Desempilha();
                        int a = ConverteInteiro(y.GetChave());
                        y.SetChave(negacao(a)+'0');
                        pos.Empilha(y);
                        if (!aux.Vazia() && aux.Topo().GetChave() == '~') {
                        aux.Desempilha(); // Desempilhar o '~'
                       }
                     
                    }else{   
                    // Dsempilhando e armazenando as variaveis com valor padrão
                    y = pos.Desempilha();
                    int a = ConverteInteiro(y.GetChave());
                    
                    y = pos.Desempilha();
                    int b = ConverteInteiro(y.GetChave());
                    
                    y = aux.Desempilha();
                    int op = y.GetChave();

                    int c = Operacao(a,b,op);

                    //empilhando as variaveis com valor ASCII
                    y.SetChave(c + '0');
                    pos.Empilha(y);
                } 
   }

    return pos; // Retornar a pilha de saída 
}

