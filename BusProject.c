#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include<math.h>

void mainMenu();
int mainMenuSelect;
void companyLogin();//FIRMA GIRISI FONSKIYONU
int companyLoginSelect;
void userLogin();
int userLoginSelect;
void addBus();
int busCapacity;
int busCapacityArray[50];
int busCapacityCounter=0;
int busModelCounter=0;
char busModelArray[50][50];
char busModel;
int busNumberCounter=1;
int busNumberArray[50];
int personelNumberArray[50];
int personelNumber;
int personelNumberCounter=1;
void AddSeferInfo();
int busNumberSelect;
char str[]= "0123456789ABCDEF";
char rnd[]="07AAAA";
void expeditionArmchairInfo();
int startClockArray[];
int startClockCounter=0;
int startClock;
int startMinute = 07;
int startMinuteUser;
int finishClockArray[50];
int finishClockCounter=0;
char startCityArray[50][50];
char finishCityArray[50][50];
int startCityCounter=0;
int finishCityCounter=0;
int moneyArray[];
int moneyCounter=0;
int money;
int clockUser;
int clockUserFinish;
char rndCheck[50][50];
int rndCounter=0;
char expeditionSelect[50][50];



int main() //Ana menu
{mainMenu();

}
void mainMenu(){

printf("\n---------- ANA MENU ----------");
printf("\n\n1- FIRMA GIRISI");
printf("\n2- MUSTERI GIRISI");
printf("\n3- CIKIS");
printf("\n\nLUTFEN SECIM YAPINIZ -> ");
scanf("%d",&mainMenuSelect);

switch(mainMenuSelect){
case 1:
    companyLogin();
    break;
    case 2:
   userLogin();
    break;
    case 3:
    return 0;
    break;
    default:
        system("CLS");
        mainMenu();
        break;
}
}
void companyLogin(){

system("cls");
printf("---------- FIRMA GIRISI ----------");
printf("\n\n1-OTOBUS EKLE");
printf("\n2-SEFER BILGISI EKLE");
printf("\n3-SEFER/KOLTUK BILGISI");
printf("\n4-UST MENUYE DON");
printf("\n\nLUTFEN SECIM YAPINIZ ->");
scanf("%d",&companyLoginSelect);

switch(companyLoginSelect){
case 1:
   addBus();
    break;
    case 2:
   AddSeferInfo();
     break;
    case 3:
    expeditionArmchairInfo();
    break;
    case 4:
   mainMenu();
    break;
    default:
        system("CLS");
        companyLogin();
        break;
}

}
void userLogin(){

system("cls");
printf("---------- MUSTERI GIRISI ----------");
printf("\n\n1-SEFERLERI LISTELE");
printf("\n2-SEFER REZERVASYON YAP");
printf("\n3-REZERVASYON GOSTER");
printf("\n4-UST MENUYE DON");
printf("\n\nLUTFEN SECIM YAPINIZ ->");
scanf("%d",&userLoginSelect);

switch(userLoginSelect){
case 1:
    //SEFERLERI LISTELE
    break;
    case 2:
    //SEFER REZERVASYON YAP
    break;
    case 3:
    //REZERVASYON GOSTER
    break;
    case 4:
    //UST MENUYE DON
    break;
    default:
        system("CLS");
        userLogin();
        break;


}
}
void addBus(){
system("cls");
printf("\n---------- OTOBUS EKLE ----------");

printf("\n\nOTOBUS KAPASITESI : ");
scanf("%d",&busCapacityArray[busCapacityCounter]);
 busCapacityCounter++;



printf("\nOTOBUS MODELI : ");
scanf("%s",busModelArray[busModelCounter]);
 busModelCounter++;


printf("\nOTOBUS NUMARASI : %d",busNumberCounter);
busNumberArray[busNumberCounter]=busNumberCounter;
busNumberCounter++;

printf("\n");
if(busCapacityArray[busCapacityCounter-1]<=30 && busCapacityArray[busCapacityCounter-1]>0){
    printf("\nPERSONEL SAYISI : 2");
    personelNumberArray[personelNumberCounter]=2; personelNumberCounter++;
}
else if(busCapacityArray[busCapacityCounter-1]>31){
     printf("\nPERSONEL SAYISI : 3");
     personelNumberArray[personelNumberCounter]=3; personelNumberCounter++;
}

getch();
companyLogin();
}

void AddSeferInfo(){
system("cls");
    printf("---------- SEFER BILGISI EKLE ----------\n\n");
  srand(time(NULL));
    for(int i=0; i<4;i++){
    rnd[i+2]=str[(rand()%16)];
    }
strcpy(rndCheck[rndCounter],rnd);

 printf("\nSefer Numarasi : %s",rndCheck[rndCounter]);
 rndCounter++;
   for(int i =0; i<busNumberCounter-1;i++){
    printf("\n\n-------------------------------");
        printf("\nOtobus Numarasi : %d",busNumberArray[i+1]);
        printf("\nOtobus Modeli : %s",busModelArray[i]);
        printf("\nOtobusun Kapasitesi : %d",busCapacityArray[i]);
            printf("\nPersonel Sayisi : %d",personelNumberArray[i+1]);
            printf("\n\n-------------------------------\n");


   }

scanf("\n%d",&busNumberSelect);
printf("\n %d Otobus numarali otobusu sectiniz",busNumberSelect);

//SAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAT
printf("\nSaati giriniz : ");
scanf("%d",&clockUser);
startClockArray[startClockCounter]=clockUser;
startClockCounter++;
printf("\nDakikayi giriniz orn 07 : ");
scanf("%d",&startMinuteUser);
if(startMinuteUser==startMinute){

        minuteAgain:
    printf("\nTahmini varis suresi : ");
    scanf("%d",&clockUserFinish);
finishClockArray[finishClockCounter]=clockUserFinish;
finishClockCounter++;
    if(clockUserFinish-clockUser>4){
        printf("\nUzun Yol otobusu kullanmalisiniz");
    }
    else{
        printf("\nKisa yol otobusu kullanmalisiniz");
    }


}
else{
    printf("\nsefer bu saate gerceklesmez sefer saati %d:07 Olarak belirlenmistir",clockUser);
goto minuteAgain;
}
printf("\nBaslangic sehrini yaziniz : ");
scanf("%s",&startCityArray[startCityCounter]);
startCityCounter++;
printf("\nBitis sehrini yaziniz : ");
scanf("%s",&finishCityArray[finishCityCounter]);
finishCityCounter++;

printf("Toplam ne kadar hasilat istiyorsunuz ? : " );
scanf("%d",&money);
printf("\nKisi basi bilet fiyati : %d ",money/busCapacityArray[busNumberSelect-1]);
moneyArray[moneyCounter]=money/busCapacityArray[busNumberSelect-1];
moneyCounter++;
system("cls");
printf("\t\tSEFERINIZ EKLENDI");
printf("\n--------------------------------------------------------");
printf("\nSefer Numarasi : %s",rnd);
printf("\nYolcu kapasitesi %d",busCapacityArray[busNumberSelect-1]);
printf("\n%s ---------> %s",startCityArray[startCityCounter-1],finishCityArray[finishCityCounter-1]);
printf("\nKisi basi bilet fiyati : %d",money/busCapacityArray[busNumberSelect-1]);
printf("\nSefer suresi : %d",clockUserFinish-clockUser);
printf("\n--------------------------------------------------------\n");
printf("Ana menuye donmek icin lutfen bir tusa basin");
getch();
mainMenu();

}
void expeditionArmchairInfo(){
    system("cls");
    printf("---------- SEFER KOLTUK BILGISI ----------\n\n");
    printf("Butun sefer numaralari asagida siralanmistir\n");
    for(int i=0; i<=strlen(rndCheck);i++){
       printf("%s\n",rndCheck[i]);
    }
    expeditionSelectAgain :
    printf("\nLutfen secin yapiniz :");
    scanf("%s",&expeditionSelect);
    for(int i=0; i<=strlen(rndCheck);i++){
        if(expeditionSelect==rndCheck[i]){
            printf("\n%s numarali seferi sectiniz koltuk bilgisi asagida verilmistir");
            printf("\n1       2       3       4");
            printf("\nkapasite : ",busCapacityArray[i]);

        }
        else{
            printf("\nyanlis secim yaptiniz lutfen tekrar deneyin");
            goto expeditionSelectAgain;
        }
    }

}










