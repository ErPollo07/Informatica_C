/*
Una banca vuole conoscere alcune informazioni sulle proprie azioni detenute in portafoglio.
Scrivere il programma in c che dopo aver inserito da tastiera la denominazione dell’azione e il suo prezzo
determini e visualizzi in Output:
1) La somma dei prezzi delle azioni;
2) La media dei prezzi delle azioni;
3) L’azione con il prezzo massimo;
4) L’azione con il prezzo minimo;
5) La media dei prezzi delle azioni con un importo compreso tra 2,50 e 3,50 euro, estremi inclusi.
L’inserimento termina con la parola “terminato”.
Il programma deve permettere il reinserimento del prezzo se è pari a zero o inferiore.


alcune azioni utili
Apple (AAPL)
Google (GOOGL)
Amazon (AMZN)

------COSA DEVE FARE IL PROGRAMMA------

###VAR###
double array nomeAzione(es: AzioniGoogle) {prezzo, prezzo, prezzo, prezzo ...}

###MAIN###
do:
    PrintMenuAzioni() : void -> stampa le azioni con il prezzo attuale
    Chiede quale azione INSERIMENTO (.lower() se si puó)
    L'utente inserisce il nome dell'azione tra parentesi e il suo prezzo in questo momento
while (INSERIMENTO != "terminato")
*/

#include <stdio.h>

#define BOUND 3


void PrintMenuAzioni() {
    printf("|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n");
    printf("*                ~ BENVENUTI ~                  *\n");
    printf("|    1 Azioni AAPL             - Prezzo 165.98  |\n");
    printf("*    2 Azioni GOOGL            - Prezzo 124.58  *\n");
    printf("|    3 Azioni AMZN             - Prezzo 132.92  |\n");
    printf("*                                               *\n");
    printf("|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n");
}

double Sum(double prezzi[], int bound) {
    double sum = 0;
    for (int i = 0; i < bound; i++) {
        sum += prezzi[i];
    }
    return sum;
}

double Media(double arrayAzioni[], int bound) {
    return Sum(arrayAzioni, bound) / bound;
}

double Min(double arrayAzioni[], int bound) {
    double valMin = arrayAzioni[0];

    for (int i = 0; i < bound; i++) {
        if (arrayAzioni[i] < valMin)
            valMin = arrayAzioni[i];
    }
    
    return valMin;
}

double Max(double arrayAzioni[], int bound) {
    double valMax = arrayAzioni[0];

    for (int i = 0; i < bound; i++) {
        if (arrayAzioni[i] < valMax)
            valMax = arrayAzioni[i];
    }
    
    return valMax;
}

void MediaTraValori(double arrayAzioni[], int bound, double valMax, double valMin) {
    double media;
    double sum = 0;
    double count = 0;


    for (int i = 0; i < bound; i++) {
        if (arrayAzioni[i] >= valMin && arrayAzioni[i] <= valMax)
            sum += arrayAzioni[i];
            count++;
    }

    if (count > 0) {
        media = sum / count;
        printf("La media dei valori compresi tra %f e %f e': %f", valMin, valMax, media);
    }
    else {
        printf("Non sono stati trovati valori tra %f e %f", valMin, valMax);
    }
}

int main() {


    double azioniApple[BOUND] = {1.48, 2.73, 3.24};
    double azioniGoogle[BOUND] = {2.45, 3.12, 1.89};
    double azioniAmazon[BOUND] = {3.76, 1.23, 2.98};

    double valoreMinimo = 2.50;
    double valoreMassimo = 3.50;
    int scelta;

    PrintMenuAzioni();

    printf("Inserisci una scelta: ");
    scanf("%d", &scelta);

    if (scelta == 1) {
        printf("La somma delle azioni e': %f\n", Sum(azioniApple, BOUND));
        printf("La media delle azioni e': %f\n", Media(azioniApple, BOUND));
        printf("Il valore minimo delle azioni e': %f\n", Min(azioniApple, BOUND));
        printf("Il valore massimo delle azioni e': %f\n", Max(azioniApple, BOUND));
        MediaTraValori(azioniApple, BOUND, valoreMinimo, valoreMinimo);
    } else if (scelta == 2) {
        printf("La somma delle azioni e': %f\n", Sum(azioniGoogle, BOUND));
        printf("La media delle azioni e': %f\n", Media(azioniGoogle, BOUND));
        printf("Il valore minimo delle azioni e': %f\n", Min(azioniGoogle, BOUND));
        printf("Il valore massimo delle azioni e': %f\n", Max(azioniGoogle, BOUND));
        MediaTraValori(azioniApple, BOUND, valoreMinimo, valoreMinimo);
    } else if (scelta == 3) {
        printf("La somma delle azioni e': %f\n", Sum(azioniAmazon, BOUND));
        printf("La media delle azioni e': %f\n", Media(azioniAmazon, BOUND));
        printf("Il valore minimo delle azioni e': %f\n", Min(azioniAmazon, BOUND));
        printf("Il valore massimo delle azioni e': %f\n", Max(azioniAmazon, BOUND));
        MediaTraValori(azioniApple, BOUND, valoreMinimo, valoreMinimo);
    } else {
        printf("Scelta non valida\n");
    }

    return 0;
}