#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<iostream>
#include<string.h>
#define MAX_INPUT_LEN 80
int basx , basy , sonx , sony;
char a[MAX_INPUT_LEN][MAX_INPUT_LEN];
char sec[MAX_INPUT_LEN][MAX_INPUT_LEN];
int c;   //klavyeden girilen karakter
int i=0; // yatay eksendeki hareketi kontol ediyor
int j=93;// dikey eksendeki hareketi kontrol ediyor
int enterj=93;
int t=0;//Bulundugun satiri tutar
int satir=0;     // toplam satir
int imlec=8;     // yazinin nereye yazildigini takip ediyor
int the_end = 0;
int girdisayisi=0;
char dizi[20];
char dizi2[20];
int m;
int dosyaAcTespit=0;
void goruntule(int satir)
{
    setcolor(15);
    settextstyle(8,0,1);//6,8*,11**
    setfillstyle(SOLID_FILL,15);
    int j=93;
    bar(0,93,3000,3000);
    setcolor(4);
    for(int i=((t/25)*(t%25)); i<satir; i++)
    {
        printf("\n%d .satir ==%s\n",i,a[i]);
        outtextxy(8,j, a[i]);
        j=j+20;
    }
}
void yukariYonTusu()
{
// Bulundugu sutundan  yukariya dogru en fazla 1.satira kadar gider
    if(t>0)
    {
        t--;
       if(t<=25){
                 j=enterj;
                j=j-20;
                }
                  enterj=enterj-20;
        //i nin bulundugu sutunnosu usteki satirin eleman sayisindan buyukse ,yukari tusunu  üsteki cümlenin sonuna goturur.
        if(i>=strlen(a[t]))
        {
            i=strlen(a[t]);
            imlec=i*10+8;
        }
        printf(" Yukari t:%d,i:%d\n",t,i);
        goruntule(satir+1);
    }
}
void asagiYonTusu()
{
//Eger bulundugun satirdan sonra bir satir varsa, i nin bulundugu sutun nosu altaki satirýn eleman sayisindan buyukse
    //i yi alttaki satirin sonuna ekle

    if(i>=strlen(a[t+1]) && (satir-t>=1))
    {
        t++;
        i=strlen(a[t]);
        imlec=i*10+8;
         enterj=enterj+20;
            if(t<=25)
            j=j+20;
        goruntule(satir+1);
    }
    else if(strlen(a[t+1])>i && (satir-t>=1))
    {
        t++;
        imlec=i*10+8;
        enterj=enterj+20;
            if(t<=25)
            j=j+20;
        goruntule(satir+1);
    }
}
void sagYonTusu()
{
//Bulundugun indis satir sonu degilse saga dogru ilerler
    if(a[t][i]!='\0')
    {
        i++;
        imlec=imlec+10;
        printf("Sag t:%d,i:%d\n",t,i);
        goruntule(satir+1);
    }
    //bulundugun satirin sonuna gelindiginde bir sonraki satirin basindan baslar
    else if(a[t][i]=='\0' && (satir-t>=1))
    {
        t++;
        i=0;
        imlec=8;
       enterj=enterj+20;
            if(t<=25)
            j=j+20;
        printf("Sag t:%d,i:%d\n",t,i);
        goruntule(satir+1);
    }
}
void solYonTusu()
{
    if(i>0)
    {
        i--;
        imlec=imlec-10;
    }
    //Sola dogru ilerlerken satirdaki cumle biterse ust satirin sonuna gider
    else if(i==0 && t>0)
    {
        t--;
        i=strlen(a[t]);
        imlec=i*10+8;
        if(t<=25){
                 j=enterj;
                j=j-20;
                }
                  enterj=enterj-20;
        goruntule(satir+1);
    }
    printf("Sol t:%d,i:%d\n",t,i);
}
void enterTusu()
{
//Enter tusuna basildiginda satir sayisini arttirir, bir onceki satirin eleman sayisini tutar,sutunu arttirir,alttaki
    //satirin 0.indisinden baslar
    satir++;
    printf("t onceki:%d\n",t);
    printf("\n");
    int p;
    for(p=satir; p>t; p--)
    {
        strcat(a[p+1],a[p]);
        a[p][0]='\0';

    }
    a[satir+1][0]='\0';

    for(int g=i,kes=0; g<=strlen(a[t]); g++)
    {
        a[t+1][kes]=a[t][g];
        kes++;
    }
    a[t][i]='\0';
    t++;
    if(t<26)
          j=j+20;
          enterj=enterj+20;
    goruntule(satir+1);
    i=0;
    imlec=8;
}
void silmeTusu()
{
//Silme isleminde dizide eleman kalmazsa sutun azaltirilarak bir ust satirin sonuna gidilir
    //silme islemine ordan devam edilir.

    if(i==0)
    {
        if(j>=113)
        {
           if(t<=25){
                 j=enterj;
                j=j-20;
                }
                  enterj=enterj-20;
            t--;
            i=strlen(a[t]);
            imlec=i*10+8;
            int p;
            for(p=t; p<=satir; p++)
            {
                strcat(a[p],a[p+1]);
                a[p+1][0]='\0';
            }
            satir--;
            goruntule(p-1);
        }
    }
    else  if(i)
    {
        int b;
        if(a[t][i]!='\0')
        {
            for(b=i; a[t][b]!='\0'; b++)
            {
                a[t][b-1]=a[t][b];
            }
            a[t][b-1]='\0';
            i--;
            imlec=imlec-10;
            if(i<0 &&t>0)
            {
                if(j>=113)
                {
                   if(t<=25){
                 j=enterj;
                j=j-20;
                }
                  enterj=enterj-20;
                    t--;
                    i=strlen(a[t]);
                    imlec=i*10+8;
                }
                int p;
                for(p=t; p<=satir; p++)
                {
                    strcat(a[p],a[p+1]);
                    a[p+1][0]='\0';
                }
                satir--;
                goruntule(p-1);
            }
        }
        else
        {
            a[t][i-1]='\0';
            i--;
            imlec=imlec-10;
        }
        printf("I:%d\n",i);
        bar(0,j,3000,j+20);
    }
}
void yaziYazma()
{
    if (i< MAX_INPUT_LEN && c >= ' ' && c <= '~')
    {
        //sag,sol,ileri tuslarina basildigina tuslara ait karakterleri diziye dail etmez

        if(i==79)
        {
            t++;
            j=j+20;
            i=0;
            imlec=i*10+8;
            satir++;
            goruntule(satir);
        }
        else if(a[t][i]!='\0')
        {
            if(strlen(a[t])<79)
            {
                for(int m=strlen(a[t]); m>=i; m--)
                {
                    a[t][m+1]=a[t][m];
                }
                a[t][strlen(a[t])+2]='\0';
                a[t][i]=c;
                i++;
                imlec=imlec+10;
            }
            printf("else if i:%d\n",i);
            printf("strlen(a[%d]):%d\n",t,strlen(a[t]));

        }
        else
        {

            a[t][i] = c;
            a[t][i+1] = '\0';
            i++;
            imlec=imlec+10;
            printf("else i:%d\n",i);
        }
    }
}
void dosyaKaydet(char ad[20],int x,int y,int x1,int y1)
{
    char karakter;
    int i,j;
    FILE *dosya;
    FILE *dosya2;
    dosya=fopen(ad,"w");  //ikili dosyalari yazma yetkisiyle açmak için kullanilir.
    dosya2=fopen("isimler.txt","a");
    if(dosya!=NULL)
    {
        for(i=x; i<x1; i++)
        {
            for(j=y; j<=y1; j++)
            {
                karakter=a[i][j];
                putc(karakter,dosya);
            }
            fprintf(dosya,"\n");
        }
        fclose(dosya);
    }
    if(dosya2!=NULL)
    {
        fprintf(dosya2,"%s %d\n",ad,x1);
        fclose(dosya2);
    }
}
void dosyaAc(char name[20],int x,int y,int y1)
{
    char karakter;
    int b,c;
    char adi[7];
    int  y2;
    int i=0;
    FILE *dosya2;
    FILE *dosya;
    dosya2=fopen("isimler.txt","r");
    while(fscanf(dosya2,"%10s %10d\n",adi,&y2)!=EOF)
    {
        if(adi[i]==name[i])
        {
            satir=y2;// dosyada isimlere gore tutulan toplam satir
            // printf("kemal\n");
        }
        i++;
    }
    fclose(dosya2);
    if((dosya=fopen(name,"r"))== NULL)
    {
        puts("Dosyasi acilmadi. !\n");
        puts("Dosya ismini kontrol ediniz.!\n");
        dosyaAcTespit=1;
    }
    else if(dosya!='\0')
    {
        for(b=x; b<satir; b++)
        {
            for(c=y; c<y1; c++)
            {

                karakter=getc(dosya);
                a[b][c]=karakter;
            }
            fprintf(dosya,"\n");
        }
        printf("Dosya Acma islemi tamamlandi.\n");
        printf("%s %d\n",adi,satir);
        goruntule(satir+1);
        fclose(dosya);
    }
}
int dosyaSilme()
{
  int durumu;
   char dosyaismi[25];

   printf("Silmek istediginiz dosya ismini giriniz: \n"); scanf("%s",dosyaismi);
   durumu = remove(dosyaismi);
   if( durumu == 0 )
      printf("Dosya silme islemi tamamlandi");
   else
   {
      printf("Dosya silinemedi\n");
      printf("Dosya ismini kontrol ediniz\n");
   }

   return 0;

}
void dosyaKaydetAc(int index)
{
    char isim[20];
    char str[20];
    girdisayisi++;
    int kaydet;
    setcolor(15);
    if(index==0)
    {
        int kayit;
        printf("------Dosya Kaydetme-----\n");
        printf("Dosya kaydetme(1),iptal(herhangi bir tus): ");
        scanf("%d",&kayit);
        if(kayit==1)
        {
            if(girdisayisi==1)
            {
                printf("Dosya ismini giriniz:");
                scanf("%s",isim);
                strcpy(dizi2,isim);
                dosyaKaydet(isim,0,0,satir,79);
                printf("Kaydetme islemi tamamlandi.\n");
                printf("\n");
                m=1;
            }
            else
            {

                printf("Kaydet(0)/Farkli Kaydet(1): ");
                scanf("%d",&kaydet);
                if(kaydet==0)
                {

                    if(m==1)
                    {
                        dosyaKaydet(dizi2,0,0,satir,79);

                    }
                    else if(m==4)
                    {
                        dosyaKaydet(dizi,0,0,satir,79);
                    }

                    printf("Kaydetme islemi tamamlandi.\n");
                    printf("\n");
                }
                else if(kaydet==1)
                {

                    printf("Dosya ismini giriniz: ");
                    scanf("%s",isim);
                    dosyaKaydet(isim,0,0,satir,79);
                    printf("Kaydetme islemi tamamlandi.\n");
                    printf("\n");
                }
            }

        }
        else
        {
            printf("Dosya kaydetme islemi iptal edildi");
            girdisayisi=0;
        }
    }
    else if(index==1)
    {
         m=4;
        int ac;
        printf("-----Dosya Acma----\n");
         printf("Dosya acma(1),iptal(herhangi bir tus): "); scanf("%d",&ac);
        if(ac==1){
        printf("Acilacak dosya ismini giriniz: \n");
        scanf("%s",str);
        strcpy(dizi,str);
        dosyaAc(str,0,0,80);
        if(dosyaAcTespit==0){
         i=0;
        imlec=8;
        j=93;
        enterj=93;
        t=0;
        }
        else{
            dosyaAcTespit=0;
        }
        }
         else
        {
             printf("Dosya acma islemi iptal edildi");
             girdisayisi=0;
        }
        printf("\n");
    }
    else if(index==2){
        printf("Dosyayi kaydeymek istiyormusunuz?\n");
        printf("Kaydet(1)/Kaydetme(herhangi bir tus): ");
        scanf("%d",&kaydet);
        if(kaydet==1)
        {
            printf("Dosya ismini giriniz: ");
            scanf("%s",isim);
            dosyaKaydet(isim,0,0,satir,79);
            printf("Kaydetme islemi tamamlandi.\n");
            setbkcolor(WHITE);
            setcolor(15);
            setfillstyle(SOLID_FILL,15);
            bar(0,93,900,1000);
            printf("Yeni Sayfa olusturuldu.\n");
            printf("\n");

        }
         else
        {
            setbkcolor(WHITE);
            setcolor(15);
            setfillstyle(SOLID_FILL,15);
            for(int i=0; i<=satir; i++){
                a[i][0]='\0';
            }
            i=0;
            imlec=8;
            j=93;
            enterj=93;
            satir=0;
            t=0;
            goruntule(satir);
            printf("Dosya kaydedilmedi.\n");
            printf("Yeni Sayfa olusturuldu.\n");
            printf("\n");
            girdisayisi=0;
        }
    }
     else if(index==3){
        int sil;
        printf("-----Dosya Silme----\n");
        printf("Dosya silme(1),iptal(herhangi bir tus): "); scanf("%d",&sil);
        if(sil==1){
           dosyaSilme();
        }
        else{
            printf("Dosya silme islemi iptal edildi");
            girdisayisi=0;
        }

    }
}
//Secili metni istenilen indise yapistirir baslangic
void yapistir()
{

   if(a[t][i]=='\0'){
        for(int x=i,say=0; x<i+strlen(sec[0]); x++,say++){
            a[t][x]=sec[0][say];
             a[t][x+1]='\0';
        }
     i=strlen(a[t]);
     imlec=i*10+8;
   }
else if(a[t][i]!='\0'){
    if(strlen(a[t])!=79){
        for(int x=strlen(a[t]); x>=i; x--){
              a[t][x+strlen(sec[0])]=a[t][x];
                printf("a[%d][%d]:%d\n",t,x+strlen(sec[0]),a[t][x+strlen(sec[0])]);
        }

         for(int y=i,say=0; y<i+strlen(sec[0]); y++,say++){
            a[t][y]=sec[0][say];
         }
         i=i+strlen(sec[0]);
         imlec=i*10+8;
    }
}

}
//Secili metni isetenilen indise yapistirir son
//Secili metni kopyalar  Ü tusuna basilinca baslangic
void kopyala()
{
int secy=0;
if(sonx>=basx){
        for(int j=basy; j<=sony; j++){
            for(int i=basx; i<sonx; i++){
                    sec[0][secy]=a[j][i];
                    printf("sec[%d][%d]:%c\n",j,secy,a[j][i]);
                    secy++;
                }
        }
   }
else {
     for(int j=basy; j<=sony; j++){
        for(int i=sonx; i<basx; i++){
            sec[0][secy]=a[j][i];
             printf("sec[%d][%d]:%c\n",j,secy,a[j][i]);
              secy++;
        }
     }
}
printf("Kopyalama islemi yapildi\n");
}
//Secili metni kopyalar  Ü tusuna basilinca son
//Secili metni kesme ç tusuna basilinca baslangic
void kes(){
    kopyala();
    if(basx!='\0' && sonx!='\0'){
           if(basx>=sonx){
                int m;
                int k;
            for( m=basx,k=sonx; a[t][m]!='\0'; m++,k++){
                  a[t][k]=a[t][m];
            }
            a[t][k]='\0';
            i=sonx;
            imlec=i*10+8;
            goruntule(satir+1);
         }
    else if(sonx>basx){
         int m;
         int k;
            for( m=sonx,k=basx; a[t][m]!='\0'; m++,k++){
                  a[t][k]=a[t][m];
            }
            a[t][k]='\0';
            i=basx;
            imlec=i*10+8;
            goruntule(satir+1);

    }
      }
 else if(basx!='\0' || sonx!='\0'){
    if(basx>=sonx){
        a[t][sonx]='\0';
    }
  else if(sonx>basx){
       a[t][basx]='\0';
  }
  goruntule(satir);
 }


}
//Secili metni kesme ç tusuna basilinca son
//İstenilen araliktaki metni secer baslangic ü tusuna basinca
void Sec()
{
basx=i;
basy=t;
printf("Seciliyor\n");
do{
    setcolor(4);

   outtextxy (8,j, a[t]);
           rectangle(i+imlec,j,i+imlec,j+18);
        c = getch();
        if (c == 0 || c == 224)
        {
        switch (getch ())
        {
            case  72: //yukari yon tusu
                     yukariYonTusu();
            break;
            case  77://sag yon tusu
                     sagYonTusu();

            break;
            case   75: //sol yon tusu

                    solYonTusu();
            break;
            case   80://Asagi yon tusu
                    asagiYonTusu();
            break;
            default:
                   printf("%d\n",c);
                break;
            }
        }
   }while(c !=252);// ü harfi
 sonx=i;
 sony=t;
 setcolor(7);
 rectangle(basx*11+8,basy*20+113,sonx*11+8,sony*20+116);
  printf(" Basx:%d,Basy:%d,Sonx:%d,Sony:%d\n",basx,basy,sonx,sony);
  printf("Secme islemi yapildi\n");
}
//istenilen araliktaki metni secer son ü tusuna basinca
void Yazma()
{
    settextstyle(8,0,1);
    a[t][0]='\0';                   // screen back ground
    do
    {
        setbkcolor(15);
        setcolor(4);

        outtextxy (8,j, a[t]);
        rectangle(i+imlec,j,i+imlec,j+18);
        c = getch();
        if (c == 0 || c == 224)
        {
            switch (getch ())
            {
            case  72: //yukari yon tusu
                yukariYonTusu();
                break;
            case  77://sag yon tusu
                sagYonTusu();

                break;
            case   75: //sol yon tusu

                solYonTusu();
                break;
            case   80://Asagi yon tusu
                asagiYonTusu();
                break;
            case KEY_F2:
                dosyaKaydetAc(0);
                break;
            case KEY_F3:
                dosyaKaydetAc(1);
                break;
            case KEY_F4:
                dosyaKaydetAc(2);
                break;
             case KEY_F5:
                dosyaKaydetAc(3);
                break;
            default:
                printf("%d\n",c);
                break;
            }
        }
       else{
   switch (c)
   {
        case 8: /* backspace */
                 silmeTusu();
        break;
        case 13: /* return */
                 enterTusu();
        break;
        case 252:/*Secme ü harfi*/
                 Sec();
         break;
       case 38:/*& Shift+6*/
                 kopyala();
       break;
       case 47:/*/Shift+7*/
                 yapistir();
       break;
       case 43:/*+ Shift+4*/
                  kes();
       break;

        default:
              yaziYazma();
   }
}
    }
    while (!the_end);
}
void kaydetAcYeniSayfaSilme()
{
    int j=20;
    for(int i=0; i<4; i++)
    {

        setfillstyle(SOLID_FILL,7);
        setcolor(15);
        bar(j,30,j+40,70);
        rectangle(j,30,j+40,70);
        // setbkcolor(3);
        j+=60;
    }

}
void secKopyalaYapistirKes()
{
    int j=380;
    for(int i=0; i<4; i++)
    {

        setfillstyle(SOLID_FILL,7);
        setcolor(15);
        bar(j,30,j+40,70);
        rectangle(j,30,j+40,70);
        // setbkcolor(3);
        j+=60;
    }

}
void CizmeAraci()
{
    setfillstyle(SOLID_FILL,7);           //dolgu deseni,renk doldurur
    setcolor(15);
    //Kaydetme tusunun icini cizme baslangic

    setcolor(8);
    setfillstyle(SOLID_FILL,8);
    bar(23,32,57,68);
    rectangle(23,32,57,68);

    setcolor(15);
    setfillstyle(SOLID_FILL,15);
    bar(28,32,52,49);
    rectangle(28,32,52,49);

    setcolor(7);
    for(int i=0; i<15; i+=4)
    {
        line(28,35+i,52,35+i);
    }
    setcolor(15);
    setfillstyle(SOLID_FILL,15);
    bar(32,55,48,70);
    rectangle(32,55,48,70);

    setcolor(8);
    setfillstyle(SOLID_FILL,8);
    bar(35,57,40,68);
    rectangle(35,57,40,68);
    //Kaydetme tusunun icini cizme son

    //Acma tusunun icini cizme baslangic

    setcolor(4);
    setfillstyle(SOLID_FILL,4);
    bar(95,32,118,65);
    rectangle(95,32,118,65);
    for(int i=0; i<6; i++)
    {
        setcolor(7);
        line(104-i,32+i,90,32+i);
        //   line(95-i,33,95-i,33-i);
    }
    setcolor(4);
    bar(83,38,118,65);
    rectangle(95,38,118,65);


    setcolor(15);
    setfillstyle(SOLID_FILL,15);
    bar(85,42,115,65);
    rectangle(85,42,115,65);

    setcolor(4);
    setfillstyle(SOLID_FILL,4);
    bar(83,45,104,65);
    rectangle(83,45,104,65);
    for(int i=0; i<=9; i++)
    {
        setcolor(15);
        line(95+i,42+i,95+i,45);
        line(95+i,43,95+i,43+i);
    }
    setcolor(4);
    setfillstyle(SOLID_FILL,4);
    bar(83,53,118,65);
    rectangle(83,53,118,65);
    //Acma tusunun icini cizme son

    //Sayfa yenileme icini doldurma baslangic
    setcolor(15);
    setfillstyle(SOLID_FILL,15);
    bar(145,35,175,65);
    rectangle(145,35,175,65);
    for(int i=0; i<=10; i++)
    {
        setcolor(7);
        line(165+i,32+i,165+i,35);
        line(165+i,33,165+i,33+i);
    }
    line(165,32,165,45);
    line(165,45,175,45);
    //Sayfa yenileme icini doldurma son

    //silme butonunun icini cizme baslangic
     setcolor(0);
     setfillstyle(SOLID_FILL,15);
     bar(216,33,222,36);
     rectangle(216,33,223,36);
     setfillstyle(SOLID_FILL,15);
     bar(208,36,230,41);
     rectangle(208,36,230,41);
     setfillstyle(SOLID_FILL,15);
     bar(208,41,230,65);
     rectangle(208,41,230,65);
     line(213,45,213,62);
     line(217,45,217,62);
     line(221,45,221,62);
     line(225,45,225,62);
   //silme butonunun icini cizme son

    setcolor(0);
    setbkcolor(3);
    outtextxy(20,74,"Kaydet");
    outtextxy(90,74,"Ac");
    outtextxy(133,74,"Yeni Sayfa");
    outtextxy(212,74,"Sil");
    outtextxy(30,12,"F2");
    outtextxy(95,12,"F3");
    outtextxy(152,12,"F4");
    outtextxy(212,12,"F5");
    setcolor(15);
    setfillstyle(SOLID_FILL,15);
}
void Ekran()
{
    setfillstyle(SOLID_FILL,15);
    settextstyle(SMALL_FONT,HORIZ_DIR,5);
    setcolor(15);
    bar(0,90,3000,3000);
    // renk ve cizim araclarinin oldugu yer baslangic
    setfillstyle(SOLID_FILL,3);
    setcolor(15);
    bar(0,5,1050,90);
// renk ve cizim araclarinin oldugu yer son
    kaydetAcYeniSayfaSilme();
    secKopyalaYapistirKes();
    CizmeAraci();
    Yazma();
}
main()
{
    /*
    int num;
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"Not Defteri");
    */
    initwindow(900,625,"Mini Notepad",0,0,false,true);
    setbkcolor(15);
    cleardevice();
    Ekran();
    closegraph();
}
