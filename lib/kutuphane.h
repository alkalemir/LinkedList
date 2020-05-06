#ifndef _INC_KUTUPHANE_H
#define _INC_KUTUPHANE_H
#define temizle system("clear");

typedef struct _node{
    int a;
    struct _node* next;
}node;

node* make(int numb);
void menu();
void case1();
void case1_1();
void case1_2();
void eleman_ekle(node** ilk, int sayi);
void diziyi_bas(node* root);
void araya_ekle(node** base, node* ilk, int sayi, int index);
void elemanSil(node** root, int index);
int elemanSayisi(node* root);
void siraliEleman(node** base, int sayi);

#endif