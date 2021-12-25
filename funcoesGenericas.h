#ifndef FUNCOESGENERICAS_H_INCLUDED
#define FUNCOESGENERICAS_H_INCLUDED

#define SIM 1
#define NAO 0

typedef struct{
    int dia, mes, ano;
} tipoData;

void lerSring(char msg[], char texto[], int tamanho, int obrigatorio);
int lerInteiro (char msg[], int limMin, int limMax);
float lerFloat (char msg[], float limMin, float limMax);
tipoData lerData(char msg[], int minAno, int maxAno);
void escreverData (tipoData data);
void limpaBuffer(void);

#endif // FUNCOESGENERICAS_H_INCLUDED
