#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <locale.h>
#include <time.h>
void etiket_cevirme(char path[100])
{
    srand(time(NULL));
    FILE *acilan;
    acilan=fopen(path,"w");
    int kod;
    kod=200+rand()%50;
    fprintf(acilan,"Dersin Kodu :%d",kod);
    printf("Dosya Oluþturuldu!!!\n Output güncellendi!!!");
    fclose(acilan);

}
void etiket_guncelleme(char icerik[1000],char yol[100],int baslangic_1,int bitis_1,char yeni_etiket_ad[30],char yeni_yol[100])
{
    char icerik_yeni[1000];
    for(int y=0; y<baslangic_1; y++)
    {
        icerik_yeni[y]=icerik[y];
    }
    strcat(icerik_yeni,yeni_etiket_ad);
    int boyut=strlen(icerik_yeni);
    int a=bitis_1-baslangic_1+1;
    int b=strlen(yeni_etiket_ad);
    int c=a-b;
    int d;
    d=bitis_1+c;
    for(int g=0; g<1000-(bitis_1+c)-10; g++)
    {
        icerik_yeni[g+boyut]=icerik[g+bitis_1+1];
    }
    FILE *dosya;
    dosya=fopen(yol,"w");
    if(dosya==NULL)
    {
        puts("Dosya Acilamadi");
    }
    else
    {
        fprintf(dosya,"%s",icerik_yeni);
    }
    fclose(dosya);
    rename(yol,yeni_yol);
    printf("Etiket ve dosya adi guncellendi");




}
void etiket_arama(char etiket[30],char adres[100],int yer,char aranan_etiket[30])
{
    if(strstr(etiket,aranan_etiket))
    {
        printf("%s etiketinde %s etiketi %s adresinde %d indisinde bulunmaktadir.\n",etiket,aranan_etiket,adres,yer);
    }

}
int kelime_arama(char icerik[1000],char yol[100],char istenen[20])
{
    char *ret=strstr(icerik,istenen);
    if(ret)
    {
        printf("\n%s kelimesi %s adresinde %d . indekste bulunaktadir.\n",istenen,yol,ret-icerik);
    }

}
struct yetim
{
    char ad[30];
};
struct istenen
{
    char ad[30];
};
struct etiket_son
{
    char ad[30];
    char adres[100];
    int baslangic;
};
struct etiket_konum
{
    char ad[30];
    char adres[100];
    char icerik[1000];
    int satir;
    int baslangic;
    int bitis;

};
struct dosya
{
    char ad[30];
    char adres[100];
    char icerik[1000];

};
int main()
{

    setlocale(LC_ALL,"Turkish");
    struct istenen istenen[50];
    struct yetim yetim[50];
    struct dosya dosya[50];
    struct dirent* entity;
    char d[3][100];
    strcpy(d[0],"C:/Users/samethan/Desktop/universite/ogretim_elemanlari/");
    strcpy(d[1],"C:/Users/samethan/Desktop/universite/bolumler/");
    strcpy(d[2],"C:/Users/samethan/Desktop/universite/dersler/");
    int a=0;
    int b=0;
    int c=0;
    char dosyaadi;
    for(int i=0; i<3; i++)
    {
        DIR* dir = opendir(d[i]);
        while((entity=readdir(dir)))
        {

            if(strstr(entity->d_name,".txt"))
            {


                if(strstr(d[i],"ogretim_elemanlari"))
                {

                    char path[100];
                    strcpy(dosya[a].ad,entity->d_name);
                    strcpy(dosya[a].adres,"C:/Users/samethan/Desktop/universite/ogretim_elemanlari/");
                    strcat(dosya[a].adres,entity->d_name);
                    strcpy(path,"C:/Users/samethan/Desktop/universite/ogretim_elemanlari/");
                    strcat(path,entity->d_name);
                    FILE *f;
                    if((f=fopen(path,"r"))!=NULL)
                    {

                        char satir[100];
                        while((fgets(satir,100,f))!=NULL)
                        {

                            strcat(dosya[a].icerik,satir);


                        }


                    }

                    else
                    {
                        printf("dosya acilmadi");
                    }


                    a++;

                }
                if(strstr(d[i],"bolumler"))
                {
                    char path[100];
                    strcpy(dosya[a+b].ad,entity->d_name);
                    strcpy(dosya[a+b].adres,"C:/Users/samethan/Desktop/universite/bolumler/");
                    strcat(dosya[a+b].adres,entity->d_name);
                    strcpy(path,"C:/Users/samethan/Desktop/universite/bolumler/");
                    strcat(path,entity->d_name);
                    FILE *f;
                    if((f=fopen(path,"r"))!=NULL)
                    {

                        char satir[100];
                        while((fgets(satir,100,f))!=NULL)
                        {
                            strcat(dosya[a+b].icerik,satir);
                        }
                    }
                    else
                    {
                        printf("dosya acilmadi");
                    }

                    b++;

                }
                if(strstr(d[i],"dersler"))
                {
                    char path[100];
                    strcpy(dosya[a+b+c].ad,entity->d_name);
                    strcpy(dosya[a+b+c].adres,"C:/Users/samethan/Desktop/universite/dersler/");
                    strcat(dosya[a+b+c].adres,entity->d_name);
                    strcpy(path,"C:/Users/samethan/Desktop/universite/dersler/");
                    strcat(path,entity->d_name);
                    FILE *f;
                    if((f=fopen(path,"r"))!=NULL)
                    {

                        char satir[100];
                        while((fgets(satir,100,f))!=NULL)
                        {

                            strcat(dosya[a+b+c].icerik,satir);
                        }
                    }
                    else
                    {
                        printf("dosya acilmadi");
                    }


                    c++;

                }





            }
        }
    }
    struct etiket_konum etiket[50];
    struct etiket_son etk[50];
    int toplam;
    int islem;
    int sayi=0;
    toplam=a+b+c;
    int baslangic=0;
    int bitis=0;
    int l=0;
    for(int x=0; x<toplam; x++)
    {
        char satirlar_etiket[1000];
        char etiket_yolu[100];
        strcpy(satirlar_etiket,dosya[x].icerik);
        strcpy(etiket_yolu,dosya[x].adres);
        for(int y=0; y<strlen(satirlar_etiket); y++)
        {

            if(satirlar_etiket[y]=='[')
            {
                if(satirlar_etiket[y+1]=='[')
                {
                    baslangic=y+2;
                    etiket[l].baslangic=baslangic;






                }
                if(satirlar_etiket[y+1]!='[')
                {
                    baslangic=0;
                }

            }
            if(satirlar_etiket[y]==']')
            {
                if(satirlar_etiket[y+1]==']')
                {
                    bitis=y-1;
                    etiket[l].bitis=bitis;
                    strcpy(etiket[l].adres,etiket_yolu);
                    strcpy(etiket[l].icerik,satirlar_etiket);
                    l++;
                }
                if(satirlar_etiket[y+1]!=']')
                {
                    bitis=0;

                }
            }



        }

    }

    int sayac=0;
    for(int u=0; u<50; u++)
    {
        int bas;
        int son;

        char icerik[1000];
        char et[28];
        char bos[28];
        bas=etiket[u].baslangic;
        son=etiket[u].bitis;
        strcpy(icerik,etiket[u].icerik);
        char c;
        int  boyut;
        boyut=son-bas;
        for(int r=0; r<boyut+1; r++)
        {
            et[r]=icerik[r+bas];
        }

        if(strstr(et,"a") || strstr(et,"A") || strstr(et,"e") || strstr(et,"E") || strstr(et,"H") || strstr(et,"h") || strstr(et,"i") || strstr(et,"I") || strstr(et,"d") || strstr(et,"D"))
        {
            sayac++;
        }
        strcpy(etk[u].ad,et);

        strcpy(etk[u].adres,etiket[u].adres);
        strcpy(etiket[u].ad,etk[u].ad);
        etk[u].baslangic=bas;
        memset(et,0,strlen(et));




    }


    //sayac etiket sayisi
    //toplam dosya adi sayisi
    //f yetim_istenen etiket sayisi

    int p,q;
    int f=0;

    for(p=0; p<sayac; p++)
    {
        char dosya_deneme[30];
        char etiket_deneme[30];
        int temp=0;
        for(q=0; q<toplam; q++)
        {

            strcpy(dosya_deneme,dosya[q].ad);
            strcpy(etiket_deneme,etk[p].ad);

            if(strstr(dosya_deneme,etiket_deneme)==NULL)
            {
                temp++;
            }

        }
        if(temp==toplam)
        {
            strcpy(yetim[f].ad,etiket_deneme);
            f++;
        }
    }
    int g=0;
    for(p=0; p<toplam; p++)
    {
        char dosya_deneme[30];
        char etiket_deneme[30];
        int temp=0;
        for(q=0; q<sayac; q++)
        {

            strcpy(dosya_deneme,dosya[p].ad);
            strcpy(etiket_deneme,etk[q].ad);

            if(strstr(dosya_deneme,etiket_deneme)==NULL)
            {
                temp++;
            }

        }
        if(temp==sayac)
        {
            strcpy(istenen[g].ad,dosya_deneme);
            g++;
        }
    }

    FILE *output;
    output=fopen("C:/Users/samethan/Desktop/universite/output.txt","w");
    if(output==NULL)
    {
        puts("Dosya Acilamadi");
    }
    else
    {
        fprintf(output,"Etiket Adi       Etiket yolu                                                      Etiket indisi\n");
        for(int i=0; i<sayac; i++)
        {
            fprintf(output,"%s   %s     %d\n",etk[i].ad,etk[i].adres,etk[i].baslangic);
        }
        fprintf(output,"Yetim Etiket Adi\n");
        for(int j=0; j<f; j++)
        {
            fprintf(output,"%s  \n",yetim[j].ad);
        }
    }
    fclose(output);
don:
    printf("Yapcaginiz islemi seciniz :\n1-Kelime Arama\n2-Etiket Arama\n3-Etiket Guncelleme\n4-Yetim Etiket Çevirme\n");
    scanf("%d",&islem);
    switch(islem)
    {
    case 1:
    {
        char istenen[20];
        printf("\n Aradiginiz Kelimeyi giriniz :\n");
        scanf("%s",istenen);
        for(int z=0; z<toplam; z++)
        {
            char satirlar[1000];
            char yol[100];
            strcpy(satirlar,dosya[z].icerik);
            strcpy(yol,dosya[z].adres);
            kelime_arama(satirlar,yol,istenen);
        }


        break;
    }
    case 2:
    {
        char aranan_etiket[30];
        printf("\n Yetim Etiket Listesi\n");
        for(int m=0; m<f; m++)
        {
            printf("%s\n",yetim[m].ad);
        }
        printf("\n İstenen Etiket Listesi\n");
        for(int n=0; n<g; n++)
        {
            printf("%s\n",istenen[n].ad);
        }

        printf("Aradiginiz etiketi giriniz :");
        fflush(stdin);
        gets(aranan_etiket);
        char etiket[30];
        char adres[100];
        int yer;
        for(int d=0; d<sayac; d++)
        {
            strcpy(etiket,etk[d].ad);
            strcpy(adres,etk[d].adres);
            yer=etk[d].baslangic;
            etiket_arama(etiket,adres,yer,aranan_etiket);

        }



        break;
    }
    case 3:
    {
        char degisen[30];
        fflush(stdin);
        printf("Guncellemek istediginiz etiketi giriniz :");
        gets(degisen);
        char yeni_etiket_ad[30];
        printf("Yeni etiketinizin adini giriniz : ");
        gets(yeni_etiket_ad);
        for(int t=0; t<sayac; t++)
        {
            if(strstr(degisen,etiket[t].ad)!=NULL)
            {

                char icerik[1000];
                char yol[100];
                char ad[30];
                char yeni_yol[100];
                strcpy(icerik,etiket[t].icerik);
                strcpy(yol,etiket[t].adres);
                strcpy(ad,etiket[t].ad);
                int baslangic_1,bitis_1;
                baslangic_1=etiket[t].baslangic;
                bitis_1=etiket[t].bitis;
                if(strstr(yol,"ogretim_elemanlari"))
                {
                    char yeni_yol[100];
                    strcpy(yeni_yol,"C:/Users/samethan/Desktop/universite/ogretim_elemanlari/");
                    strcat(yeni_yol,yeni_etiket_ad);
                    strcat(yeni_yol,".txt");
                }
                if(strstr(yol,"dersler"))
                {
                    char yeni_yol[100];
                    strcpy(yeni_yol,"C:/Users/samethan/Desktop/universite/dersler/");
                    strcat(yeni_yol,yeni_etiket_ad);
                    strcat(yeni_yol,".txt");
                }
                if(strstr(yol,"bolumler"))
                {

                    strcpy(yeni_yol,"C:/Users/samethan/Desktop/universite/bolumler/");
                    strcat(yeni_yol,yeni_etiket_ad);
                    strcat(yeni_yol,".txt");
                }

                etiket_guncelleme(icerik,yol,baslangic_1,bitis_1,yeni_etiket_ad,yeni_yol);
                output=fopen("C:/Users/samethan/Desktop/universite/output.txt","a");
                if(output==NULL)
                {
                    puts("Dosya Acilamadi");
                }
                else
                {
                    fprintf(output,"\nGüncel Liste\n");
                    fprintf(output,"Etiket Adi       Etiket yolu                                                      Etiket indisi\n");
                    for(int i=0; i<sayac; i++)
                    {
                        if(strstr(etiket[i].ad,degisen))
                        {
                            memset(etiket[i].ad,0,strlen(etiket[i].ad));
                            strcpy(etiket[t].ad,yeni_etiket_ad);
                        }
                        fprintf(output,"%s   %s     %d\n",etiket[i].ad,etiket[i].adres,etiket[i].baslangic);
                    }
                    fprintf(output,"Yetim Etiket Adi\n");
                    for(int j=0; j<f; j++)
                    {
                        if(strstr(yetim[j].ad,degisen))
                        {
                            memset(yetim[j].ad,0,strlen(yetim[j].ad));
                            strcpy(yetim[j].ad,yeni_etiket_ad);
                        }
                        fprintf(output,"%s  \n",yetim[j].ad);
                    }
                }
                fclose(output);
                printf("\nOutput güncellendi !!!!");

            }
        }


        break;
    }
    case 4:
    {
        char cevrilen_etiket[30];
        fflush(stdin);
        int s=0;
        printf("Normal etikete çevirmek istediðiniz yetim etiketini giriniz :\n");
        gets(cevrilen_etiket);
        char cevir_1[30];
        for(int k=0; k<f; k++)
        {
            strcpy(cevir_1,yetim[k].ad);

            if(strstr(cevir_1,cevrilen_etiket))
            {
                s=1;
                char path[100];
                strcpy(path,"C:/Users/samethan/Desktop/universite/dersler/");
                strcat(path,cevir_1);
                strcat(path,".txt");
                etiket_cevirme(path);
                memset(yetim[k].ad,0,strlen(cevir_1));
                break;

            }

        }
        if (s=1)
        {
            output=fopen("C:/Users/samethan/Desktop/universite/output.txt","a");
            if(output==NULL)
            {
                puts("Dosya Acilamadi");
            }
            else
            {
                fprintf(output,"\nGüncel Liste\n");
                fprintf(output,"Etiket Adi       Etiket yolu                                                      Etiket indisi\n");
                for(int i=0; i<sayac; i++)
                {
                    fprintf(output,"%s   %s     %d\n",etk[i].ad,etk[i].adres,etk[i].baslangic);
                }
                fprintf(output,"Yetim Etiket Adi\n");
                for(int j=0; j<f; j++)
                {
                    fprintf(output,"%s  \n",yetim[j].ad);
                }
            }
            fclose(output);
        }







        break;
    }
    default:
    {
        printf("Lutfen Gecerli Bir Secim Yapiniz !!!");
        goto don;
    }

    }


    return 0;
}
