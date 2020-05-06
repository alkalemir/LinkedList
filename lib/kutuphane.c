#include <stdlib.h>
#include <stdio.h>
#include "kutuphane.h"

node* make(int numb)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->a = numb;
    newNode->next = NULL;

    return newNode;
}

void menu()
{
    printf("Eleman eklemek için  [1]\n");
    printf("Eleman çıkarmak için [2]\n");
    printf("Diziyi basmak için   [3]\n");
    printf("Çıkmak için          [4]\n");
}

void case1()
{
    printf("Sıralı eleman ekle          [1]\n");
    printf("Belirli indexe eleman ekle  [2]\n");
    printf("Sona eleman ekle            [3]\n");
    printf("Geri dön                    [4]\n");
}

void case1_1()
{
    printf("Eklemek istediğiniz elemanı girin (cikis icin -1): ");

}

void case1_2()
{
    printf("Hangi indexe eklemek istiyorsunuz? : ");
}

void eleman_ekle(node** ilk, int sayi)
{
    if (*ilk == NULL)
    {
        *ilk = make(sayi);
    }
    else{
        node* iter = *ilk;
        node* olusacak = make(sayi);
        while(iter->next != NULL)
        {
            iter = (node *)iter->next;
        }
        iter->next = olusacak;
    }
}

void diziyi_bas(node* root)
{
    node* iter = root;
    printf("Dizi :\n");
    int i = 1;
    while(iter != NULL)
    {
        printf("\r%d. Eleman = %d\n", i, iter->a);
        iter = iter->next;
        i++;
    }
}

void araya_ekle(node** base, node* ilk, int sayi, int index)
{
    node* iter = ilk;
    node* eklenecek = make(sayi); 
    if(index == 1)
    {
        *base = eklenecek;
        (*base)->next = iter;
    }
    else{
        for (int i = 0; i < index-2; ++i)
        {
            iter = (node*)iter->next;
        }
        eklenecek->next = iter->next;
        iter->next = eklenecek;        
    }

}

void elemanSil(node** root, int index)
{
    node* iter2 = *root;
    if (index == 1)
    {
        iter2 = iter2->next;
        free(*root);
        *root = iter2;
        return;
    }
    node* iter = *root;
    for (int i = 0; i < index-2; ++i)
    {
        iter = iter->next;
    }
    iter->next = iter->next->next;

}

int elemanSayisi(node* root)
{
    node* iter = root;
    int i = 0;
    while(iter != NULL)
    {
        iter = (node*)iter->next;
        i++;
    }
    return i;
}

void siraliEleman(node** base, int sayi)
{
    if (*base == NULL)
    {
        *base = make(sayi);
        return;
    }
    else if ((*base)->a > sayi)
    {
        node *temp = make(sayi);
        temp->next = *base;
        *base = temp;
        return;
    }
    else{
        node *eklenecek = make(sayi);
        node *iter = *base;
        while(iter->next != NULL && iter->next->a < sayi)
        {
            iter = (node*)iter->next;
        }
        eklenecek->next = iter->next;
        iter->next = eklenecek;
    }
}