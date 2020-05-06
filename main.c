#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib/kutuphane.h"


int main()
{  
    node *root = NULL;
    geridon:
    temizle
    menu();
    int ch;
    printf("Seçiminiz  : ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1:
            temizle
            case1();
            int secim;
            printf("Seciminiz : ");
            scanf("%d", &secim);
            switch(secim)
            {
                case 1:
                    temizle
                    while(1)
                    {
                        int sayi_3;
                        printf("Sıralı eklemek istediğiniz elemanı giriniz (cikis icin -1): ");
                        scanf("%d", &sayi_3);
                        if (sayi_3 != -1)
                        {           
                            siraliEleman(&root, sayi_3);
                        }
                        else{
                            goto geridon;
                        }
                    }

                    break;

                case 2:
                    temizle
                    while(1)
                    {
                        case1_1();
                        int sayi_2, index_no;
                        scanf("%d", &sayi_2);

                        if (sayi_2 == -1)
                        {
                            goto geridon;
                        }
                        else{
                            durumtekrari:
                            case1_2();
                            scanf("%d", &index_no);
                            int len = elemanSayisi(root);
                            if (index_no > len)
                            {
                                printf("İndex bulunamadı !!(Maks index : %d)\n", len);
                                goto durumtekrari;   
                            }
                            araya_ekle(&root, root, sayi_2, index_no);  
                        }    
                    }                               
                    break;

                case 3:
                    temizle
                    while(1)
                    {
                        
                        case1_1();
                        int sayi_1;
                        scanf("%d", &sayi_1);
                        if (sayi_1 == -1)
                        {
                           goto geridon; 
                        }
                        else{
                            eleman_ekle(&root, sayi_1);
                        }
                    }               
                    break;
                case 4:
                    goto geridon;
                    break;
                    
            }
            break;
        case 2:
            temizle
            while(1)
            {
                bas:;
                int len2;
                len2 = elemanSayisi(root);
                printf("Silinecek elemanın index numarasını girin(maks index %d) : ", len2);
                int index_no_2;
                scanf("%d", &index_no_2);
                if (index_no_2 > len2)
                {
                    printf("Hatalı index girdiniz !\n");
                    goto bas;
                }
                if (index_no_2 == -1)
                {
                    goto geridon;
                }
                else{
                    elemanSil(&root, index_no_2);
                    printf("Eleman başarıyla silindi..\n");
                    sleep(1);
                }
            }
            break;
        case 3:
            temizle
            diziyi_bas(root);
            sleep(5);
            goto geridon;
            break;
        
        case 4:
            temizle
            exit(1);
    }
}