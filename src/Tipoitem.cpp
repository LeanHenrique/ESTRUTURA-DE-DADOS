#include"../include/TipoItem.h"
#include <iostream>

using namespace std;

TipoItem::TipoItem()
{
chave = ' '; // indica um item vazio
}
TipoItem::TipoItem(TipoChave c)
{
chave = c;
}
void TipoItem::SetChave(TipoChave c)
{
chave = c;
}
TipoChave TipoItem::GetChave()
{
return chave;
}
void TipoItem::Imprime()
{
cout << chave << endl;
}