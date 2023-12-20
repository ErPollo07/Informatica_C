/*
RACCOGLITORE ESERCIZI
*/

#include <stdio.h>


void main()
{
    int continuare;
    int scelta;

    do {
        
        PrintMenu();
    
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);
    
        switch (scelta)
        {
        case 1:
            Es1(); break;
        case 2:
            Es2(); break;
        case 3:
            Es3(); break;
        case 4:
            Es4(); break;
        default:
            printf("Scelta non contemplata."); break;
        }
        
        printf("\n\nSe vuoi continuare inserire un numero diverso da 0: ");
        scanf("%d", &continuare);
        
    }while (continuare != 0);
}

void PrintMenu() {

    printf("Questi sono gli esercizi disponibili:\n");
    printf("    1. Somma pari dispari\n");
    printf("    2. Calcolatore di sconti\n");
    printf("    3. Somma media n positivi negativi\n");
    printf("    4. Somma numeri primi alterni\n");
    printf("**************************************\n\n");
}

void Es1() {
    
    int numero = 0;
    int lenght = 0;

    // somme
    double sommaPari = 0;
    double sommaDispari = 0;

    // lenght
    double lenghtPari = 0;
    double lenghtDispari = 0;

    // medie
    double mediaPari = 0;
    double mediaDispari = 0;

    printf("Inserisci il numero di numeri che vuoi inserire: ");
    scanf("%d", &lenght);

    if (lenght < 30) {
        while(lenght > 0) {
            printf("Inserisci un numero: ");
            scanf("%d", &numero);

            if (numero % 2 == 0) {
                sommaPari += numero;
                lenghtPari += 1;
            }
            else {
                sommaDispari += numero;
                lenghtDispari += 1;
            }

            lenght--;
        }

        if (lenghtPari > 0)
            mediaPari = sommaPari / lenghtPari;
        if (lenghtDispari > 0)
            mediaDispari = sommaDispari / lenghtDispari;
        
        if (mediaPari > 0)
            printf("La media dei numeri pari: %.2f\n", mediaPari);
        if (mediaDispari > 0)
            printf("La media dei numeri dispari: %.2f\n", mediaDispari);
    }
    else {
        printf("Non puoi inserire piú di 30 numeri");
    }
}

void Es2() {
    
    float prezzo, prezzoScontato;
    float sconto, sconto1000 = 20, scontoOltre1001 = 30;
    int continua;

    do {
        // Chiedo l'input fino a che il prezzo < 0
        do {
            printf("inserire l'importo: ");
            scanf("%f", &prezzo);
        } while (prezzo < 0);


        // Calcolo lo sconto e lo applico al prezzo
        if (prezzo < 500) {
            sconto = 10;
            prezzoScontato = prezzo - prezzo * (sconto / 100.0);
        }
        else if (prezzo >= 500 && prezzo < 1001) {
            sconto = 20;
            prezzoScontato = prezzo - prezzo * (sconto / 100.0);
        }
        else if (prezzo >= 1001) {
            sconto = 30;
            prezzoScontato = prezzo - prezzo * (sconto / 100.0);
        }

        // Stampo il prezzo inserito dall'utente e il prezzo con lo sconto applicato
        printf("Importo inseririto: %.2f\nimporto con sconto: %.2f\n", prezzo, prezzoScontato);

        printf("Vuoi inserire un altro importo: \n(1) SI\n(0) NO\n");
        scanf("%d", &continua);
    } while (continua);
}

void Es3() {
    
    int n;
    int numero = 0;

    double coutPositivi = 0, coutNegativi = 0;

    double sommaPositivi = 0, sommaNegativi = 0;
    double mediaPositivi = 0, mediaNegativi = 0;

    printf("Inserisci quanti numeri vuoi leggere: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        printf("Inserisci il numero: ");
        scanf("%d", &numero);

        if (numero > 0)
        {
            coutPositivi++;
            sommaPositivi += numero;
        }
        else
        {
            coutNegativi++;
            sommaNegativi += numero;
        }
    }

    if (coutPositivi > 0)
        mediaPositivi = sommaPositivi / coutPositivi;

    if (coutNegativi > 0)
        mediaNegativi = (sommaNegativi * -1) / coutNegativi;

    printf("La somma dei numeri positivi e': %.2f\nLa media dei numeri positivi e': %.2f\n", sommaPositivi, mediaPositivi);

    printf("La somma dei numeri negativi e': %.2f\nLa media dei numeri negativi e': %.2f\n", (sommaNegativi * -1), mediaNegativi);
}

void Es4() {
    
    int numero = 0;
    int c = 2;
    int somma = 0;
    int _flagPrimo;

    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++) {

        /* DEBUG
        printf("i: %d\n", i);
        */
        
        if (i > 1) {
            
            _flagPrimo = 1;
            
            /* DEBUG
            printf("sono entrato per valutare\n");
            */    

            // Valuta se primo
            for (int j = 2; j <= i / 2 && j != i; j++) {
                
                if (i % j == 0) {
                    _flagPrimo = 0;
                    break;
                }
            }

            /* DEBUG
            printf("Count: %d\n", c);
            */
           
            // se il numero é primo
            if (_flagPrimo) {
                // se il count é pari allora aggiorna la somma
                if (c % 2 == 0) somma += i;
                // Aggiorno il count
                c++;
            }
        }
        
        
        /* DEBUG
        printf("Flag: %d\n", _flagPrimo);
        printf("somma: %d\n\n", somma);
        */
    }
    
    printf("\nResult: %d\n", somma);
}
