#include <stdio.h>
#include <string.h>
#include "funcoesGenericas.h"

void lerSring(char msg[], char texto[], int tamanho, int obrigatorio)
{
    int tamTexto;

    do
    {
        printf("%s", msg);
        fgets(texto, tamanho, stdin);
        tamTexto = strlen(texto);
        if (tamTexto == 1 && obrigatorio == SIM) // significa que o utilizador só clicou no ENTER
            printf("\nERRO: O Campo é Obrigatório.\n");
    }
    while (tamTexto == 1 && obrigatorio == SIM);

    if (texto[tamTexto-1] != '\n')
        limpaBuffer();
    else
        texto[tamTexto-1] = '\0';
}

void escreverData (tipoData data)
{
    printf("%02d/%02d/%d", data.dia, data.mes, data.ano);
}

tipoData lerData(char msg[], int minAno, int maxAno)
{
    tipoData data;
    int controlo, maxDia, erro=0;

    do
    {
        erro = 0;
        do
        {
            printf("%s", msg);
            controlo = scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
            limpaBuffer();
            if (controlo != 3) // retorno do scanf
                printf("\nERRO: Formato de Data Inválido.\n");
        }
        while (controlo != 3);

        if (data.ano < minAno || data.ano > maxAno)
        {
            printf("\nERRO: Ano Inválido\n");
            erro = 1;
        }
        else
        {
            switch(data.mes)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                maxDia = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                maxDia = 30;
                break;
            case 2:
                if (data.ano%400==0 || (data.ano%4==0 && data.ano%100!=0))
                    maxDia = 29;
                else
                    maxDia = 28;
                break;
            default:
                printf("\nERRO: Mês Inválido.\n");
                erro = 1;
            }
            if (data.dia < 1 || data.dia > maxDia)
            {
                printf("\nERRO: Dia inválido.\n");
                erro = 1;
            }
        }
    }
    while (erro);

    return data;
}


int lerInteiro (char msg[], int limMin, int limMax)
{
    int num, controlo;

    do
    {
        printf("%s [%d, %d]: ", msg, limMin, limMax);
        controlo = scanf("%d", &num);
        limpaBuffer();
        if (controlo != 1 || num < limMin || num > limMax)
            printf("\n\nERRO: O valor introduzido está fora do intervalo solicitado.");
    }
    while (controlo != 1 || num < limMin || num > limMax);
    return num;
}

float lerFloat (char msg[], float limMin, float limMax)
{
    float num;
    int controlo;

    do
    {
        printf("%s [%.2f, %.2f]: ", msg, limMin, limMax);
        controlo = scanf("%f", &num);
        limpaBuffer();
        if (controlo != 1 || num < limMin || num > limMax)
            printf("\n\nERRO: O valor introduzido está fora do intervalo solicitado.");
    }
    while (controlo != 1 || num < limMin || num > limMax);
    return num;
}


void limpaBuffer(void)
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}
