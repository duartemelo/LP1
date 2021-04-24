#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief Inserção de dados hardcode para testar as estruturas
 * 
 * @param concorrentes 
 * @param numConcorrentes 
 */
void testeInsercaoDados(Concorrente *concorrentes, int numConcorrentes)
{
    //1

    concorrentes[0].num = 1;
    strcpy(concorrentes[0].nome, "Joao");
    strcpy(concorrentes[0].carro, "Volkswagen Golf");
    concorrentes[0].valido = false;
    concorrentes[0].velocidadeMedia = 0;
    concorrentes[0].etapas[0].tempo = 0;
    concorrentes[0].etapas[1].tempo = 37203;
    concorrentes[0].etapas[2].tempo = 37203;
    concorrentes[0].etapas[3].tempo = 42000;
    concorrentes[0].etapas[4].tempo = 28465;

    strcpy(concorrentes[0].etapas[0].nomeEtapa, "P");
    strcpy(concorrentes[0].etapas[1].nomeEtapa, "E1");
    strcpy(concorrentes[0].etapas[2].nomeEtapa, "E2");
    strcpy(concorrentes[0].etapas[3].nomeEtapa, "E3");
    strcpy(concorrentes[0].etapas[4].nomeEtapa, "C");

    //2

    concorrentes[1].num = 2;
    strcpy(concorrentes[1].nome, "Barbara");
    strcpy(concorrentes[1].carro, "Fiat 500");
    concorrentes[1].valido = false;
    concorrentes[1].velocidadeMedia = 0;
    concorrentes[1].etapas[0].tempo = 0;
    concorrentes[1].etapas[1].tempo = 37203;
    concorrentes[1].etapas[2].tempo = 37203;
    concorrentes[1].etapas[3].tempo = 42000;
    concorrentes[1].etapas[4].tempo = 0; //etapa invalida

    strcpy(concorrentes[1].etapas[0].nomeEtapa, "P");
    strcpy(concorrentes[1].etapas[1].nomeEtapa, "E1");
    strcpy(concorrentes[1].etapas[2].nomeEtapa, "E2");
    strcpy(concorrentes[1].etapas[3].nomeEtapa, "E3");
    strcpy(concorrentes[1].etapas[4].nomeEtapa, "C");

    //3

    concorrentes[2].num = 3;
    strcpy(concorrentes[2].nome, "Julio");
    strcpy(concorrentes[2].carro, "Fiat Tipo");
    concorrentes[2].valido = false;
    concorrentes[2].velocidadeMedia = 0;
    concorrentes[2].etapas[0].tempo = 0;
    concorrentes[2].etapas[1].tempo = 35203;
    concorrentes[2].etapas[2].tempo = 37203;
    concorrentes[2].etapas[3].tempo = 42000;
    concorrentes[2].etapas[4].tempo = 26465;

    strcpy(concorrentes[2].etapas[0].nomeEtapa, "P");
    strcpy(concorrentes[2].etapas[1].nomeEtapa, "E1");
    strcpy(concorrentes[2].etapas[2].nomeEtapa, "E2");
    strcpy(concorrentes[2].etapas[3].nomeEtapa, "E3");
    strcpy(concorrentes[2].etapas[4].nomeEtapa, "C");

    //4

    concorrentes[3].num = 4;
    strcpy(concorrentes[3].nome, "Rita");
    strcpy(concorrentes[3].carro, "Fiat 500");
    concorrentes[3].valido = false;
    concorrentes[3].velocidadeMedia = 0;
    concorrentes[3].etapas[0].tempo = 0;
    concorrentes[3].etapas[1].tempo = 37203;
    concorrentes[3].etapas[2].tempo = 37203;
    concorrentes[3].etapas[3].tempo = 42000;
    concorrentes[3].etapas[4].tempo = 0; //etapa invalida

    strcpy(concorrentes[3].etapas[0].nomeEtapa, "P");
    strcpy(concorrentes[3].etapas[1].nomeEtapa, "E1");
    strcpy(concorrentes[3].etapas[2].nomeEtapa, "E2");
    strcpy(concorrentes[3].etapas[3].nomeEtapa, "E3");
    strcpy(concorrentes[3].etapas[4].nomeEtapa, "C");

    testeInsercaoDistanciaEtapas(concorrentes, numConcorrentes);
}

/**
 * @brief Inserção de distancia das etapas (hardcode)
 * 
 * @param concorrentes 
 * @param numConcorrentes 
 */
void testeInsercaoDistanciaEtapas(Concorrente *concorrentes, int numConcorrentes)
{
    for (int i = 0; i < numConcorrentes; i++)
    {
        concorrentes[i].etapas[0].distancia = 0;      //partida
        concorrentes[i].etapas[1].distancia = 23.100; //e1
        concorrentes[i].etapas[2].distancia = 32.230; //e2
        concorrentes[i].etapas[3].distancia = 38.130; //e3
        concorrentes[i].etapas[4].distancia = 43.440; //C
    }
}

/**
 * @brief Lista um concorrente
 * 
 * @param concorrente recebe o concorrente
 * @param numEtapas recebe o numero de etapas
 */
void listarConcorrente(Concorrente concorrente, int numEtapas)
{
    printf("Numero: %d\n", concorrente.num);
    printf("Nome: %s\n", concorrente.nome);
    printf("Carro: %s\n", concorrente.carro);
    for (int j = 0; j < numEtapas; j++)
    {
        printf("Etapa %s: %.2fkm em ", concorrente.etapas[j].nomeEtapa, concorrente.etapas[j].distancia);
        escreveTempoFormatado(concorrente.etapas[j].tempo);
        printf("\n");
    }
    printf("Tempo total: ");
    escreveTempoFormatado(devolveTempoTotal(concorrente, numEtapas));
    printf("\n");
    printf("Distancia total: %.2fkm\n", devolveDistanciaTotal(concorrente, numEtapas));
    printf("Velocidade media: %.2f km/h\n", concorrente.velocidadeMedia);
    printf("Prova valida: %d\n", concorrente.valido);
}

/**
 * @brief Lista um array de concorrentes
 * 
 * @param concorrentes 
 * @param numConcorrentes 
 * @param numEtapas 
 */
void listarConcorrentes(Concorrente *concorrentes, int numConcorrentes, int numEtapas)
{
    for (int i = 0; i < numConcorrentes; i++)
    {
        listarConcorrente(concorrentes[i], numEtapas);
        printf("\n\n");
    }
}

/**
 * @brief Lista apenas concorrentes com prova valida
 * 
 * @param concorrentes Recebe um array de concorrentes
 * @param numConcorrentes Numero de concorrentes
 * @param numEtapas Numero de etapas
 */
void listarConcorrentesProvaValida(Concorrente *concorrentes, int numConcorrentes, int numEtapas)
{
    for (int i = 0; i < numConcorrentes; i++)
    {
        if (concorrentes[i].valido == true)
        {
            listarConcorrente(concorrentes[i], numEtapas);
            printf("\n\n");
        }
    }
}

/**
 * @brief Verifica se uma prova esta valida ou não
 * 
 * @param concorrente Recebe o concorrente
 * @param numEtapas Recebe o numero de etapas
 * @return true Retorna true se estiver valida
 * @return false Retorna false se nao estiver valida
 */
bool verificaProvaValida(Concorrente concorrente, int numEtapas)
{
    //verificar tempos
    int contador = 0;
    for (int i = 0; i < numEtapas; i++)
    {
        if (concorrente.etapas[i].tempo > 0)
        {
            contador++;
        }
    }

    if (contador != numEtapas - 1)
    {
        return false;
    }

    //se depois da confirmaçao anterior, a etapa "P" nao tiver indice 0, ou seja, outra etapa tem tempo 0, a prova fica invalida
    if (concorrente.etapas[obterIndiceEtapa(concorrente, "P", numEtapas)].tempo != 0)
    {
        return false;
    }

    //confirmar nomesEtapas

    contador = 0;

    //confirmacao P e C
    for (int i = 0; i < numEtapas; i++)
    {
        if (strcmp("P", concorrente.etapas[i].nomeEtapa) == 0)
        {
            contador++;
        }
        if (strcmp("C", concorrente.etapas[i].nomeEtapa) == 0)
        {
            contador++;
        }
    }

    //confirmacao E1, E2, E3, etc.
    for (int i = 0; i < numEtapas - 2; i++)
    {
        int numEtapa = i + 1;
        char caracter = 'E';
        char nomeEtapa[10];
        snprintf(nomeEtapa, 10, "%c%d", caracter, numEtapa);

        for (int j = 0; j < numEtapas; j++)
        {
            if (strcmp(nomeEtapa, concorrente.etapas[j].nomeEtapa) == 0)
            {
                contador++;
            }
        }
    }

    if (contador != numEtapas)
    {
        return false;
    }

    return true;
}

/**
 * @brief Recebe um array de concorrentes, e define os validos e os nao validos
 * 
 * @param concorrentes Array de concorrentes
 * @param numConcorrentes Numero de concorrentes
 * @param numEtapas Numero de etapas
 */
void defineConcorrentesValidos(Concorrente *concorrentes, int numConcorrentes, int numEtapas)
{
    for (int i = 0; i < numConcorrentes; i++)
    {
        if (verificaProvaValida(concorrentes[i], numEtapas) == true)
        {
            concorrentes[i].valido = true;
        }
    }
}

/**
 * @brief Retorna o numero de concorrentes com prova valida
 * 
 * @param concorrentes Recebe o array de concorrentes
 * @param numConcorrentes 
 * @param numEtapas 
 * @return int Numero de concorrentes com prova valida
 */
int obterNumConcorrentesProvaValida(Concorrente *concorrentes, int numConcorrentes, int numEtapas)
{
    int contador = 0;
    bool provaValida;
    for (int i = 0; i < numConcorrentes; i++)
    {
        provaValida = verificaProvaValida(concorrentes[i], numEtapas);
        if (provaValida == true)
        {
            contador++;
        }
    }
    return contador;
}

/**
 * @brief Lista um array de concorrentes, com prova valida, por tempo total decrescente
 * 
 * @param concorrentesTempoDesc 
 * @param numConcorrentes 
 * @param numEtapas 
 */
void listarOrdemTempoProvaValidaDesc(Concorrente *concorrentesTempoDesc, int numConcorrentes, int numEtapas)
{
    Concorrente temp;
    for (int i = 0; i < numConcorrentes - 1; i++)
    {
        for (int j = i + 1; j < numConcorrentes; j++)
        {
            if (devolveTempoTotal(concorrentesTempoDesc[j], numEtapas) > devolveTempoTotal(concorrentesTempoDesc[i], numEtapas))
            {
                temp = concorrentesTempoDesc[j];
                concorrentesTempoDesc[j] = concorrentesTempoDesc[i];
                concorrentesTempoDesc[i] = temp;
            }
        }
    }
}

/**
 * @brief Lista o array de concorrentes "concorrentesTempoAsc" por tempo ascendente
 * 
 * @param concorrentesTempoAsc 
 * @param numConcorrentes 
 * @param numEtapas  
 */
void listarOrdemTempoProvaValidaAsc(Concorrente *concorrentesTempoAsc, int numConcorrentes, int numEtapas)
{
    Concorrente temp;
    for (int i = 0; i < numConcorrentes - 1; i++)
    {
        for (int j = i + 1; j < numConcorrentes; j++)
        {

            if (devolveTempoTotal(concorrentesTempoAsc[j], numEtapas) < devolveTempoTotal(concorrentesTempoAsc[i], numEtapas))
            {
                temp = concorrentesTempoAsc[j];
                concorrentesTempoAsc[j] = concorrentesTempoAsc[i];
                concorrentesTempoAsc[i] = temp;
            }
        }
    }
}

/**
 * @brief Lista um array de concorrentes pelo numero ascendentemente
 * 
 * @param concorrentesInvalidosNumCresc 
 * @param numConcorrentes 
 * @param numEtapas 
 */
void listarOrdemNumeroAsc(Concorrente *concorrentesInvalidosNumCresc, int numConcorrentes, int numEtapas)
{
    Concorrente temp;

    for (int i = 0; i < numConcorrentes - 1; i++)
    {
        for (int j = i + 1; j < numConcorrentes; j++)
        {
            if (concorrentesInvalidosNumCresc[j].num < concorrentesInvalidosNumCresc[i].num)
            {
                temp = concorrentesInvalidosNumCresc[j];
                concorrentesInvalidosNumCresc[j] = concorrentesInvalidosNumCresc[i];
                concorrentesInvalidosNumCresc[i] = temp;
            }
        }
    }
}

/**
 * @brief Obtem o indice de uma etapa a partir do seu nome "P", "E1", "E2", etc.
 * 
 * @param concorrente Recebe o concorrente 
 * @param nomeEtapa Recebe o nome da etapa
 * @param numEtapas 
 * @return int Retorna o indice da etapa
 */
int obterIndiceEtapa(Concorrente concorrente, char nomeEtapa[], int numEtapas)
{
    int contador = 0;
    int indice = -1;
    while (strcmp(concorrente.etapas[contador].nomeEtapa, nomeEtapa) != 0 && contador < numEtapas)
    {
        contador++;
    }
    if (strcmp(concorrente.etapas[contador].nomeEtapa, nomeEtapa) == 0)
    {
        indice = contador;
    }
    return indice;
}

/**
 * @brief Copia um array de concorrentes para outro, porém apenas copia os concorrentes com prova valida
 * 
 * @param concorrentes Array original
 * @param concorrentesCopy Array copiado
 * @param numConcorrentes 
 * @param numEtapas 
 */
void copiarArrayConcorrentesProvaValida(Concorrente *concorrentes, Concorrente *concorrentesCopy, int numConcorrentes, int numEtapas)
{
    int contador = 0;
    for (int i = 0; i < numConcorrentes; i++)
    {
        if (concorrentes[i].valido == true)
        {
            concorrentesCopy[contador] = concorrentes[i];
            contador++;
        }
    }
}

/**
 * @brief Copia apenas concorrentes com prova invalida de um array para outro
 * 
 * @param concorrentes 
 * @param concorrentesCopy 
 * @param numConcorrentes 
 * @param numEtapas 
 */
void copiarArrayConcorrentesProvaInvalida(Concorrente *concorrentes, Concorrente *concorrentesCopy, int numConcorrentes, int numEtapas)
{
    int contador = 0;
    for (int i = 0; i < numConcorrentes; i++)
    {
        if (concorrentes[i].valido == false)
        {
            concorrentesCopy[contador] = concorrentes[i];
            contador++;
        }
    }
}

/**
 * @brief Copia um array de concorrentes para outro
 * @param concorrentes 
 * @param concorrentesCopy 
 * @param numConcorrentes 
 * @param numEtapas 
 */
void copiarArrayConcorrentes(Concorrente *concorrentes, Concorrente *concorrentesCopy, int numConcorrentes, int numEtapas)
{
    for (int i = 0; i < numConcorrentes; i++)
    {
        concorrentesCopy[i] = concorrentes[i];
    }
}

/**
 * @brief Escreve no ecrã a média de cada etapa (apenas de provas validas)
 * 
 * @param concorrentes 
 * @param numConcorrentes 
 * @param numEtapas 
 */
void mediaEtapasProvasValidas(Concorrente *concorrentes, int numConcorrentes, int numEtapas)
{
    int aux;
    for (int i = 0; i < numEtapas; i++)
    {
        int somatorio = 0;
        int contador = 0;
        float media;
        for (int j = 0; j < numConcorrentes; j++)
        {
            if (verificaProvaValida(concorrentes[j], numEtapas) == true)
            {
                somatorio += concorrentes[j].etapas[i].tempo;
                aux = j;
                contador++;
            }
        }
        media = somatorio / contador;

        printf("Media da etapa ");
        escreveNomeEtapaPorIndice(concorrentes[aux], i);
        printf(": %.2f\n", media);
    }
}

/**
 * @brief Escreve o nome da etapa a partir do seu indice
 * 
 * @param concorrente 
 * @param indiceEtapa 
 */
void escreveNomeEtapaPorIndice(Concorrente concorrente, int indiceEtapa)
{
    printf("%s", concorrente.etapas[indiceEtapa].nomeEtapa);
}

/**
 * @brief Devolve o indice do concorrente mais rapido
 * 
 * @param concorrentes 
 * @param numConcorrentes 
 * @param numEtapas 
 * @return int Indice do concorrente mais rapido
 */
int devolveIndiceConcorrenteMaisRapido(Concorrente *concorrentes, int numConcorrentes, int numEtapas)
{
    int indiceConcorrenteMaisRapido = 0;
    int menorTempo = devolveTempoTotal(concorrentes[indiceConcorrenteMaisRapido], numEtapas);

    for (int i = 1; i < numConcorrentes; i++)
    {
        if (devolveTempoTotal(concorrentes[i], numEtapas) < menorTempo)
        {
            indiceConcorrenteMaisRapido = i;
        }
    }
    return indiceConcorrenteMaisRapido;
}

/**
 * @brief Devolve o indice do concorrente mais lento
 * 
 * @param concorrentes 
 * @param numConcorrentes 
 * @param numEtapas 
 * @return int Indice do concorrente mais lento
 */
int devolveIndiceConcorrenteMaisLento(Concorrente *concorrentes, int numConcorrentes, int numEtapas)
{
    int indiceConcorrenteMaisLento = 0;
    int maiorTempo = devolveTempoTotal(concorrentes[indiceConcorrenteMaisLento], numEtapas);

    for (int i = 1; i < numConcorrentes; i++)
    {
        if (devolveTempoTotal(concorrentes[i], numEtapas) > maiorTempo)
        {
            indiceConcorrenteMaisLento = i;
        }
    }
    return indiceConcorrenteMaisLento;
}

/**
 * @brief Devolve o tempo total da prova de um concorrente
 * 
 * @param concorrente 
 * @param numEtapas 
 * @return int Tempo total da prova
 */
int devolveTempoTotal(Concorrente concorrente, int numEtapas)
{
    int somatorio = 0;
    for (int i = 0; i < numEtapas; i++)
    {
        somatorio += concorrente.etapas[i].tempo;
    }
    return somatorio;
}

/**
 * @brief Devolve a distancia total de uma prova
 * 
 * @param concorrente 
 * @param numEtapas 
 * @return float Distancia total de uma prova
 */
float devolveDistanciaTotal(Concorrente concorrente, int numEtapas)
{
    float somatorio = 0;
    for (int i = 0; i < numEtapas; i++)
    {
        somatorio += concorrente.etapas[i].distancia;
    }
    return somatorio;
}

/**
 * @brief Procedimento que escreve o menu no ecrã
 * 
 * @param concorrentes 
 * @param concorrentesTempoDesc 
 * @param numConcorrentes 
 * @param numConcorrentesProvaValida 
 * @param numEtapas 
 * @param concorrentesVelocidadeMediaDesc 
 */
void menu(Concorrente *concorrentes, Concorrente *concorrentesTempoDesc, Concorrente *concorrentesTempoAsc, int numConcorrentes, int numConcorrentesProvaValida, int numEtapas, Concorrente *concorrentesVelocidadeMediaDesc, Concorrente *concorrentesInvalidosNumCresc)
{
    int opcao;
    escreveTextoMenu();
    scanf("%d", &opcao);
    while (opcao != (-1))
    {
        switch (opcao)
        {
        case 1:
            listarConcorrentes(concorrentes, numConcorrentes, numEtapas);
            break;
        case 2:
            listarOrdemTempoProvaValidaDesc(concorrentesTempoDesc, numConcorrentesProvaValida, numEtapas);
            listarConcorrentes(concorrentesTempoDesc, numConcorrentesProvaValida, numEtapas);
            break;
        case 3:
            printf("%d\n", numConcorrentes);
            break;
        case 4:
            printf("%d\n", numConcorrentesProvaValida);
            break;
        case 5:
            mediaEtapasProvasValidas(concorrentesTempoDesc, numConcorrentesProvaValida, numEtapas);
            break;
        case 6:
            listarConcorrente(concorrentesTempoDesc[devolveIndiceConcorrenteMaisRapido(concorrentesTempoDesc, numConcorrentesProvaValida, numEtapas)], numEtapas);
            break;
        case 7:
            listarConcorrente(concorrentesTempoDesc[devolveIndiceConcorrenteMaisLento(concorrentesTempoDesc, numConcorrentesProvaValida, numEtapas)], numEtapas);
            break;
        case 8:
            printf("%dms\n", menorTempoProva(concorrentes, numConcorrentes, numEtapas));
            break;
        case 9:
            ordenaConcorrentesVelocidadeMediaDesc(concorrentesVelocidadeMediaDesc, numConcorrentes, numEtapas);
            listarConcorrentesProvaValida(concorrentesVelocidadeMediaDesc, numConcorrentes, numEtapas);
            break;
        case 10:
            listarOrdemTempoProvaValidaAsc(concorrentesTempoAsc, numConcorrentesProvaValida, numEtapas);
            listarOrdemNumeroAsc(concorrentesInvalidosNumCresc, numConcorrentes - numConcorrentesProvaValida, numEtapas);
            escreveTabela(concorrentesTempoAsc, concorrentesInvalidosNumCresc, numConcorrentes, numConcorrentesProvaValida, numEtapas);
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
        sleep(3);
        escreveTextoMenu();
        scanf("%d", &opcao);
    }
}

/**
 * @brief Texto do menu
 * 
 */
void escreveTextoMenu()
{
    printf("1 - Listar todos os concorrentes\n");
    printf("2 - Listar concorrentes com prova valida pelo tempo descendente\n");
    printf("3 - Num concorrentes em prova (valida ou nao)\n");
    printf("4 - Num concorrentes em prova com prova valida\n");
    printf("5 - Media etapas provas validas:\n");
    printf("6 - Concorrente mais rapido (prova valida):\n");
    printf("7 - Concorrente mais lento (prova valida):\n");
    printf("8 - Menor tempo em que e possivel efetuar a prova na totalidade:\n");
    printf("9 - Listar velocidades medias de toda a prova, por ordem decrescente (provas validas):\n");
    printf("10 - Tabela classificativa da prova:\n");
    printf("Opcao (-1 para sair): ");
}

/**
 * @brief Alocação de memória nos arrays de etapas
 * 
 * @param concorrentes 
 * @param numConcorrentes 
 * @param numEtapas 
 */
void allocMemEtapas(Concorrente *concorrentes, int numConcorrentes, int numEtapas)
{
    for (int i = 0; i < numConcorrentes; i++)
    {
        concorrentes[i].etapas = malloc(sizeof(Etapa) * numEtapas);
    }
}

/**
 * @brief Liberta a memória do array de etapas
 * 
 * @param concorrentes 
 * @param numConcorrentes 
 */
void freeMemEtapas(Concorrente *concorrentes, int numConcorrentes)
{
    for (int i = 0; i < numConcorrentes; i++)
    {
        free(concorrentes[i].etapas);
    }
}

/**
 * @brief Menor tempo em que é possivel realizar a prova (independentemente de ter sido feita por concorrentes com provas validas ou não / pega nos tempos mais rapidos de cada etapa)
 * 
 * @param concorrentes 
 * @param numConcorrentes 
 * @param numEtapas 
 * @return int 
 */
int menorTempoProva(Concorrente *concorrentes, int numConcorrentes, int numEtapas)
{
    int somatorio = 0, menorTempo, contador;
    for (int i = 1; i < numEtapas; i++)
    {
        contador = 0;
        while (concorrentes[contador].etapas[i].tempo == 0)
        {
            contador++;
        }
        menorTempo = concorrentes[contador].etapas[i].tempo;
        for (int j = contador + 1; j < numConcorrentes; j++)
        {
            if (concorrentes[j].etapas[i].tempo < menorTempo && concorrentes[j].etapas[i].tempo != 0)
            {
                menorTempo = concorrentes[j].etapas[i].tempo;
            }
        }
        somatorio += menorTempo;
    }
    return somatorio;
}

/**
 * @brief Define velocidades medias dos concorrentes
 * 
 * @param concorrentes 
 * @param numConcorrentes 
 * @param numEtapas 
 */
void definirVelocidadesMedias(Concorrente *concorrentes, int numConcorrentes, int numEtapas)
{
    float distanciaTotal = devolveDistanciaTotal(concorrentes[0], numEtapas);
    for (int i = 0; i < numConcorrentes; i++)
    {
        float tempoTotal = (float)devolveTempoTotal(concorrentes[i], numEtapas);
        tempoTotal = tempoTotal * 2.7777777777778E-7;
        float velocidadeMedia = distanciaTotal / tempoTotal;
        concorrentes[i].velocidadeMedia = velocidadeMedia;
    }
}

/**
 * @brief Ordena o array "concorrentesVelocidadeMediaDesc" pela velocidade media decrescentemente
 * 
 * @param concorrentesVelocidadeMediaDesc 
 * @param numConcorrentes 
 * @param numEtapas 
 * @return true 
 * @return false 
 */
bool ordenaConcorrentesVelocidadeMediaDesc(Concorrente *concorrentesVelocidadeMediaDesc, int numConcorrentes, int numEtapas)
{
    Concorrente temp;

    //working
    for (int i = 0; i < numConcorrentes - 1; i++)
    {
        for (int j = i + 1; j < numConcorrentes; j++)
        {
            if (concorrentesVelocidadeMediaDesc[j].velocidadeMedia > concorrentesVelocidadeMediaDesc[i].velocidadeMedia)
            {
                temp = concorrentesVelocidadeMediaDesc[j];
                concorrentesVelocidadeMediaDesc[j] = concorrentesVelocidadeMediaDesc[i];
                concorrentesVelocidadeMediaDesc[i] = temp;
            }
        }
    }

    return true;
}

/**
 * @brief Escreve tabela classificativa
 * 
 * @param concorrentesTempoAsc 
 * @param concorrentesInvalidosNumCresc 
 * @param numConcorrentes 
 * @param numConcorrentesProvaValida 
 * @param numEtapas 
 */
void escreveTabela(Concorrente *concorrentesTempoAsc, Concorrente *concorrentesInvalidosNumCresc, int numConcorrentes, int numConcorrentesProvaValida, int numEtapas)
{
    int tempoLider = devolveTempoTotal(concorrentesTempoAsc[0], numEtapas);
    int tempoAnterior = tempoLider;
    int aux;
    //cabeçalho
    printf("Posicao\t\tNumero\t\tNome\t\tCarro\t\tTempo prova\tDi. Ant.\tDi. Ldr.\n");
    for (int i = 0; i < numConcorrentesProvaValida; i++)
    {
        if (i > 0)
        {
            tempoAnterior = devolveTempoTotal(concorrentesTempoAsc[i - 1], numEtapas);
        }
        printf("%d\t\t", i + 1);
        printf("%d\t\t", concorrentesTempoAsc[i].num);
        printf("%s\t\t", concorrentesTempoAsc[i].nome);
        printf("%s\t\t", concorrentesTempoAsc[i].carro);

        escreveTempoFormatado(devolveTempoTotal(concorrentesTempoAsc[i], numEtapas));
        printf("\t\t");

        escreveTempoFormatado(devolveTempoTotal(concorrentesTempoAsc[i],numEtapas)-tempoAnterior);
        printf("\t\t");
        
        escreveTempoFormatado(devolveTempoTotal(concorrentesTempoAsc[i], numEtapas) - tempoLider);
        printf("\n");
        aux = i;
    }

    for (int i = 0; i < (numConcorrentes - numConcorrentesProvaValida); i++)
    {
        printf("%d\t\t", i + aux + 2);
        printf("%d\t\t", concorrentesInvalidosNumCresc[i].num);
        printf("%s\t\t", concorrentesInvalidosNumCresc[i].nome);
        printf("%s\t\t", concorrentesInvalidosNumCresc[i].carro);
        printf("DESC\t\t");
        printf("DESC\t\t");
        printf("DESC\t\t");
        printf("\n");
    }
}

/**
 * @brief Gera concorrentes com dados default, para depois ser possivel inserir dados nos mesmos
 * 
 * @param concorrentes 
 * @param numConcorrentes 
 * @param numEtapas 
 */
void geraConcorrentesDefault(Concorrente *concorrentes, int numConcorrentes, int numEtapas)
{
    for (int i = 0; i < numConcorrentes; i++)
    {
        concorrentes[i].num = i + 1;
        concorrentes[i].valido = false;
        strcpy(concorrentes[i].etapas[0].nomeEtapa, "P");
        concorrentes[i].etapas[0].tempo = 0;
        concorrentes[i].etapas[0].distancia = 0;
        strcpy(concorrentes[i].etapas[numEtapas - 1].nomeEtapa, "C");
        concorrentes[i].etapas[numEtapas - 1].tempo = 0;
        concorrentes[i].etapas[numEtapas - 1].distancia = 0;

        for (int j = 1; j < numEtapas - 1; j++)
        {
            int numEtapa = j;
            char caracter = 'E';
            char nomeEtapa[10];
            snprintf(nomeEtapa, 10, "%c%d", caracter, numEtapa);
            strcpy(concorrentes[i].etapas[j].nomeEtapa, nomeEtapa);
            concorrentes[i].etapas[j].tempo = 0;
            concorrentes[i].etapas[j].distancia = 0;
        }
    }
}

/**
 * @brief Escreve o tempo em ms no formato minutos:segundos.decimas
 * 
 * @param tempo Recebe o tempo em ms
 */
void escreveTempoFormatado(int tempo)
{
    int minutos;
    float segundos;
    minutos = tempo / 60000;
    segundos = (float)(tempo - (minutos * 60000)) / 1000;
    printf("%d:%.1f", minutos, segundos);
}