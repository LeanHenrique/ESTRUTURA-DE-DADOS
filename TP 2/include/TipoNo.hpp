#ifndef TIPONOH
#define TIPONOH

const int MAX_CONEXOES = 100;
class TipoNo {
public:
    TipoNo();
    void setItem(int item);
    int GetItem();
    TipoNo* GetProximo();
    void SetProximo(TipoNo* prox);
    int GetConexao(int i);
    void SetConexao(int conex);
    int GetCor();
    void SetCor(int c);
    int TotalConexao();
    int item;
    

private:
    TipoNo* proximo;
    int conexao[MAX_CONEXOES];
    int cor;
    int TotalConexoes;
};

#endif