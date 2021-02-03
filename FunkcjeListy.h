#include <stdio.h>
#include <stdlib.h>

int iloscElementow = 0;

struct Element {
    int value;
    struct Element* next;
    struct Element* prev;
} *glowa, *ogon;

int wartosc;

void DodajNaKoniecListy(int wartosc);
void DodajNaPoczatekListy();
void DodajDoSrodka(int wartosc);
void UsunZListy();
void WypiszOdPoczatku();
void WypiszOdKonca();

void DodajNaKoniecListy(int wartosc) {
    struct Element* NowyElement = (struct Element*) malloc(sizeof(struct Element));
    NowyElement->value = wartosc;
    NowyElement->next = NULL;
    NowyElement->prev = NULL;

    if (glowa == NULL) {
        glowa = NowyElement;
        ogon = glowa;
    } else {
        NowyElement->prev = ogon;
        ogon->next = NowyElement;
        ogon = NowyElement;
    }

    ++iloscElementow;
}

void DodajDoSrodka(int wartosc)
{
    struct Element* nowyElement = (struct Element*) malloc(sizeof(struct Element));
    nowyElement->value = wartosc;

    struct Element* srodkowyElement = glowa;

    for (int i = 0, end = iloscElementow / 2 - 1; i < end; ++i)
        srodkowyElement = srodkowyElement->next;

    nowyElement->prev = srodkowyElement->prev;
    nowyElement->next = srodkowyElement->next;

    srodkowyElement->next = nowyElement;
}

void UsunZListy()
{
    if (ogon->prev != NULL)
    {
        struct Element* prev = ogon->prev;
        free(ogon);
        ogon = prev;
        ogon->next = NULL;
    }

    --iloscElementow;
}

void WypiszOdPoczatku() {
    struct Element* iterator = glowa;
    while (iterator != NULL) {
        printf("%d ", iterator->value);
        iterator = iterator->next;
    }
    printf("\n");
}

void WypiszOdKonca() {
    struct Element* iterator = ogon;
    while (iterator != NULL) {
        printf("%d ", iterator->value);
        iterator = iterator->prev;
    }
    printf("\n");
}

void DodajNaPoczatekListy() {
    struct Element* nowyElement = (struct Element*) malloc(sizeof(struct Element));
    nowyElement->value = --wartosc;

    nowyElement->prev = NULL;
    nowyElement->next = glowa;
    glowa->prev = nowyElement;
    glowa=nowyElement;
}