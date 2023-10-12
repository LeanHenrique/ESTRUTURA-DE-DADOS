#ifndef TIPOITEMH
#define TIPOITEMH



typedef int TipoChave; // TipoChave é um CHAR
class TipoItem
{
public:
TipoItem();
TipoItem(TipoChave c);
void SetChave(TipoChave c);
TipoChave GetChave();
void Imprime();
private:
TipoChave chave;
// outros membros
};


#endif