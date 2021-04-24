typedef enum{
    false,
    true
} bool;

typedef struct{
    char nomeEtapa[10];
    int tempo;
    float distancia; 
}Etapa;

typedef struct{
    int num;
    char nome[20];
    char carro[20];
    Etapa *etapas;
    bool valido;
    float velocidadeMedia;
}Concorrente;



void testeInsercaoDados(Concorrente *concorrentes, int numConcorrentes);
void testeInsercaoDistanciaEtapas(Concorrente *concorrentes, int numConcorrentes);
void listarConcorrentes(Concorrente *concorrentes, int numConcorrentes, int numEtapas);
void listarConcorrentesProvaValida(Concorrente *concorrentes, int numConcorrentes, int numEtapas);
bool verificaProvaValida(Concorrente concorrente, int numEtapas);
int obterNumConcorrentesProvaValida(Concorrente *concorrentes, int numConcorrentes, int numEtapas);
void listarConcorrente(Concorrente concorrente, int numEtapas);
int obterIndiceEtapa(Concorrente concorrente, char nomeEtapa[], int numEtapas);




void  listarOrdemTempoProvaValidaDesc(Concorrente *concorrentesTempoDesc, int numConcorrentes, int numEtapas);
void listarOrdemTempoProvaValidaAsc(Concorrente *concorrentesTempoAsc, int numConcorrentes, int numEtapas);

void listarOrdemNumeroAsc(Concorrente *concorrentesInvalidosNumCresc, int numConcorrentes, int numEtapas);




void copiarArrayConcorrentes(Concorrente *concorrentes, Concorrente *concorrentesCopy, int numConcorrentes, int numEtapas);
void copiarArrayConcorrentesProvaValida(Concorrente *concorrentes, Concorrente *concorrentesCopy, int numConcorrentes, int numEtapas);
void copiarArrayConcorrentesProvaInvalida(Concorrente *concorrentes, Concorrente *concorrentesCopy, int numConcorrentes, int numEtapas);
void defineConcorrentesValidos(Concorrente *concorrentes, int numConcorrentes, int numEtapas);
void mediaEtapasProvasValidas(Concorrente *concorrentes, int numConcorrentes, int numEtapas);
void escreveNomeEtapaPorIndice(Concorrente concorrente, int indiceEtapa);
int devolveIndiceConcorrenteMaisRapido(Concorrente *concorrentes, int numConcorrentes, int numEtapas);
int devolveIndiceConcorrenteMaisLento(Concorrente *concorrentes, int numConcorrentes, int numEtapas);
void menu(Concorrente *concorrentes, Concorrente *concorrentesTempoDesc, Concorrente *concorrentesTempoAsc, int numConcorrentes, int numConcorrentesProvaValida, int numEtapas, Concorrente *concorrentesVelocidadeMediaDesc, Concorrente *concorrentesInvalidosNumCresc);
int devolveTempoTotal(Concorrente concorrente, int numEtapas);
void escreveTextoMenu();
void allocMemEtapas(Concorrente *concorrentes, int numConcorrentes, int numEtapas);
void freeMemEtapas(Concorrente *concorrentes, int numConcorrentes);
int menorTempoProva(Concorrente *concorrentes, int numConcorrentes, int numEtapas);
void definirVelocidadesMedias(Concorrente *concorrentes, int numConcorrentes, int numEtapas);
float devolveDistanciaTotal(Concorrente concorrente, int numEtapas);
bool ordenaConcorrentesVelocidadeMediaDesc(Concorrente *concorrentesVelocidadeMediaDesc, int numConcorrentes, int numEtapas);

void escreveTabela(Concorrente *concorrentesTempoAsc, Concorrente *concorrentesInvalidosNumCresc, int numConcorrentes, int numConcorrentesProvaValida, int numEtapas);
void geraConcorrentesDefault(Concorrente *concorrentes, int numConcorrentes, int numEtapas);

void escreveTempoFormatado(int tempo);