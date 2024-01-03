#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct kullanici {
    char kullanici_adi[25];
    int sifre;
    int pincode;
    int numura;
};


int secim() {
    printf("-----------------------------------\n");
    printf("1 - Hesap olustur\n");
    printf("-----------------------------------\n");
    printf("2 - Hesaba giris yap\n");
    printf("-----------------------------------\n");
    printf("3 - Cikis\n");
    printf("-----------------------------------\n");
    printf("Lutfen bir islem seciniz: ");
}


struct kullanici kullanicilar[100];


int kullanici_sayisi = 0;

int main() {
    int son = 0;
    int cikis = 0;

    while (!cikis) {

        secim();


        int islem;

        scanf("%d", &islem);


        switch (islem) {
        case 1:

            printf("Kullanici adinizi olusturunuz:");
            scanf("%s", &kullanicilar[kullanici_sayisi].kullanici_adi);

            printf("Sifrenizi olusturunuz:");
            scanf("%d", &kullanicilar[kullanici_sayisi].sifre);

            printf("Pincode olusturunuz(Bu pinkodu hesabinizin sifresini unutmaniz durumunda tedbiren alinmaktadir !!!):");
            scanf("%d", &kullanicilar[kullanici_sayisi].pincode);

            printf("Numaranizi giriniz:");
            scanf("%d", &kullanicilar[kullanici_sayisi].numura);

            kullanici_sayisi++;

            printf("Hesap olusturma islemi basarili bisekilde tamamlandi.\n");
            break;

        case 2:
            printf("");

            int deneme = 0;


            while (deneme < 3) {
                printf("*==========================================*\n");

                printf("Kullanici adiniz giriniz:");
                scanf("%s", &kullanicilar[kullanici_sayisi].kullanici_adi);

                printf("Sifrenizi giriniz: ");
                scanf("%d", &kullanicilar[kullanici_sayisi].sifre);



                for (int i = 0; i < kullanici_sayisi; i++) {

                    if (strcmp(kullanicilar[i].kullanici_adi, kullanicilar[kullanici_sayisi].kullanici_adi) == 0 &&
                        kullanicilar[i].sifre == kullanicilar[kullanici_sayisi].sifre)
                    {
                        printf("****=======================****\n");
                        printf(" Hosgeldiniz %s.\n", kullanicilar[i].kullanici_adi);
                        printf("****=======================****\n");
                        cikis = 1;
                        break;
                    }
                }

                if (cikis) {
                    break;
                }

                deneme++;
                printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                printf("Sifreniz veya kullanici adi hatali. Lutfen tekrar deneyiniz. (Kalan deneme hakkiniz: %d)\n", 3 - deneme);
            }

            if (!cikis) {

                printf("**************************************************************************************************\n");
                printf("Cok fazla deneme yaptiniz sifrenizi degistirmek isterseniz  '1'/ cikmak isterseniz '2' basiniz:");
                scanf("%d", &islem);
                if (2 == islem)
                    break;
                else if (1 == islem); {
                    printf(")=================================(\n");
                    printf("Pincode giriniz:");
                    scanf("%d", &islem);
                    for (int i = 0; i < kullanici_sayisi; i++)
                    {

                        if (kullanicilar[i].pincode == islem) {
                            printf(")=================================(\n");
                            printf("yeni sifrenizi giriniz:");
                            scanf("%d", &islem);
                            kullanicilar[i].sifre = islem;

                            break;
                        }
                        else if (i >= kullanici_sayisi-1 && kullanicilar[i].pincode != islem)

                        {
                            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");


                            if (son == 0) {
                                printf("pincode hatali ):\n");
                                printf("Numaranizi giriniz:");
                                scanf("%d", &islem);
                            }
                            else if (son == 1)
                                break;
                            for (int a = 0;a < kullanici_sayisi;a++) {
                                if (kullanicilar[a].numura == islem)
                                {
                                    srand(time(NULL));

                                    int rastgele = rand() % 1000 + 1;
                                    printf("**********************************\n");
                                    printf("Tek kullanimlik sifre= %d\n", rastgele);
                                    printf("**********************************\n");
                                    printf("Tek kullanimlik sifrenizi giriniz:");
                                    scanf("%d", &islem);
                                    if (islem == rastgele) {


                                        printf(")=================================(\n");
                                        printf("yeni sifrenizi giriniz:");
                                        scanf("%d", &islem);
                                        kullanicilar[i].sifre = islem;

                                        son++;
                                        break;



                                    }

                                    else
                                        exit;
                                }
                            }



                        }
                    }

                }

            }
            break;

        case 3:
            cikis = 1;
            break;

        default: {
            printf("Gecerli bir islem seciniz.\n");
            break;
        }
        }
    }

    return 0;
}