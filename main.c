#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"

int main(int argc, char const *argv[])
{
    int numConcorrentes, numEtapas;

    //array de concorrentes
    Concorrente *concorrentes;

    //array de concorrentes com ordenaçao de tempo decrescente (apenas com prova valida)
    Concorrente *concorrentesTempoDesc;

    //array de concorrentes com ordenação de tempo TOTAL crescente (apenas prova valida) 
    Concorrente *concorrentesTempoAsc;

    //array de concorrentes invalidos com ordenação por numero crescente (apenas provas invalidas)
    Concorrente *concorrentesInvalidosNumCresc;

    //array de concorrentes ordenaçao velocidade media decrescente
    Concorrente *concorrentesVelocidadeMediaDesc;

    
    //ler tempos.txt e colocar nos concorrentes os tempos
    FILE *tempos = fopen("tempos.txt", "r");
    if (tempos == NULL)
    {
        printf("Erro ao abrir ficheiro!\n");
    }

    int linha = 0;
    int idTemporario;
    char etapaInicial[3];
    char etapaFinal[3];
    int tempoTemporario;
    while (!feof(tempos))
    {
        //primeira linha
        if (linha == 0)
        {
            fscanf(tempos, "%d;%d", &numEtapas, &numConcorrentes);
            numEtapas = numEtapas + 1;
            //alocação de memória no array de concorrentes
            concorrentes = malloc(numConcorrentes * sizeof(Concorrente));
            //alocação de memória no array de etapas
            allocMemEtapas(concorrentes, numConcorrentes, numEtapas);
            //gera concorrentes com informações default
            geraConcorrentesDefault(concorrentes, numConcorrentes, numEtapas);
        }
        //outras linhas
        else
        {
            fscanf(tempos, "%d;%[^;];%[^;];%d", &idTemporario, etapaInicial, etapaFinal, &tempoTemporario);

            for (int i = 0; i < numConcorrentes; i++)
            {
                if (concorrentes[i].num == idTemporario)
                {
                    concorrentes[i].etapas[obterIndiceEtapa(concorrentes[i], etapaFinal, numEtapas)].tempo = tempoTemporario;
                }
            }
        }
        linha++;
    }

    //ler distancias.txt e colocar nos concorrentes as distâncias
    FILE *distancias = fopen("distancias.txt", "r");
    if (distancias == NULL)
    {
        printf("Erro ao abrir ficheiro!\n");
    }

    float distanciaTemporario;
    while (!feof(distancias))
    {
        fscanf(distancias, "%[^;];%[^;];%f", etapaInicial, etapaFinal, &distanciaTemporario);

        for (int i = 0; i < numConcorrentes; i++)
        {
            concorrentes[i].etapas[obterIndiceEtapa(concorrentes[i], etapaFinal, numEtapas)].distancia = distanciaTemporario;
        }
    }

    //ler informações.txt e colocar nos concorrentes as informações
    FILE *informacoes = fopen("informacoes.txt", "r");
    if (informacoes == NULL)
    {
        printf("Erro ao abrir ficheiro!\n");
    }

    char nome[20];
    char carro[20];

    while (!feof(informacoes))
    {
        fscanf(informacoes, "%d;%[^;];%[^\n]", &idTemporario, nome, carro);

        for (int i = 0; i < numConcorrentes; i++)
        {
            if (concorrentes[i].num == idTemporario)
            {
                strcpy(concorrentes[i].nome, nome);
                strcpy(concorrentes[i].carro, carro);
            }
        }
    }

    fclose(tempos);
    fclose(distancias);
    fclose(informacoes);

    //alocaçao de memoria no array concorrentes e no array de concorrentes com velocidade media decrescente
    //concorrentes = malloc(numConcorrentes * sizeof (Concorrente));
    concorrentesVelocidadeMediaDesc = malloc(numConcorrentes * sizeof(Concorrente));

    //inserçao de dados hardcoded (futuramente a partir de documento de texto)
    //testeInsercaoDados(concorrentes, numConcorrentes);

    definirVelocidadesMedias(concorrentes, numConcorrentes, numEtapas);

    //define concorrentes como validos, os que forem
    defineConcorrentesValidos(concorrentes, numConcorrentes, numEtapas);

    //numero de concorrentes com prova valida
    int numConcorrentesProvaValida = obterNumConcorrentesProvaValida(concorrentes, numConcorrentes, numEtapas);

    //alocaçao de memoria array concorrentes tempo desc (apenas concorrentes com prova valida)
    concorrentesTempoDesc = malloc(numConcorrentesProvaValida * sizeof(Concorrente));

    //alocaçao de memoria array concorrentes tempo asc (apenas concorrentes com prova valida)
    concorrentesTempoAsc = malloc(numConcorrentesProvaValida * sizeof(Concorrente));

    //alocaçao de memoria array concorrentes tempo numero crescente (apenas concorrentes com prova INvalida)
    concorrentesInvalidosNumCresc = malloc((numConcorrentes - numConcorrentesProvaValida) * sizeof(Concorrente));

    //copia o array concorrentes para concorrentesTempoDesc, para depois ser ordenado
    copiarArrayConcorrentesProvaValida(concorrentes, concorrentesTempoDesc, numConcorrentes, numEtapas);
    copiarArrayConcorrentesProvaValida(concorrentes, concorrentesTempoAsc, numConcorrentes, numEtapas);

    copiarArrayConcorrentesProvaInvalida(concorrentes, concorrentesInvalidosNumCresc, numConcorrentes, numEtapas);

    copiarArrayConcorrentes(concorrentes, concorrentesVelocidadeMediaDesc, numConcorrentes, numEtapas);

    //MENU
    menu(concorrentes, concorrentesTempoDesc, concorrentesTempoAsc, numConcorrentes, numConcorrentesProvaValida, numEtapas, concorrentesVelocidadeMediaDesc, concorrentesInvalidosNumCresc);

    free(concorrentes);
    free(concorrentesVelocidadeMediaDesc);

    free(concorrentesTempoDesc);
    free(concorrentesTempoAsc);
    free(concorrentesInvalidosNumCresc);

    freeMemEtapas(concorrentes, numConcorrentes);

    return 0;
}
