//Pin eşleşmeleri
//  Su Sensörü HW-038
//  + --> 7
//  - --> GND
//  S --> A5
//  LED
//  Kısa Bacak --> GND
//  Uzun Bacak --> LED1-8, LED2-9,LED3-10

const int wPowerP = 7; //Su sensörü güç pini
const int wSignalP = A5; //Su sensörü sinyal pini

const int lOneP = 8; //1. LED
const int lTwoP = 9; //2. LED
const int lThreeP = 10; //3. LED
int ledVars[3] = {lOneP, lTwoP, lThreeP}; //LED pinlerini tutan dizi

const int waterMin = 0; //Minimum su seviyesi
const int waterMax = 470; //Maksimum su seviyesi
int waterVal = 0; //Su değeri
int waterLev = 0; //Su seviyesi

void setup() 
{
  //LED pinleri çıkış olarak başlatılır.
  for(int i = 0; i < 3; i++)
  {
    pinMode(ledVars[i], OUTPUT);
  }

  //Su sensörü güç pini çıkış olarak başlatılır.
  pinMode(wPowerP, OUTPUT);
  //Su sensörünü kapatır.
  digitalWrite(wPowerP, LOW);
}

void loop() 
{
  //Su sensörünü açar.
  digitalWrite(wPowerP, HIGH);
  delay(10);
  //Su seviyesi değerini ölçer.
  waterVal = analogRead(wSignalP);
  //Su sensörünü kapatır.
  digitalWrite(wPowerP, LOW);

  //Su seviyesi değerini 0-3 arasında bir seviyeye dönüştürür.
  waterLev = map(waterVal, waterMin, waterMax, 0, 3); 

  //Su seviyesine göre LED yakar.
  LedOn(waterLev);

  delay(3000);

  //Tüm LED'leri söndürür.
  LedOff();
}

//Verilen sayıya göre LED yakan fonksiyon.
void LedOn(int n)
{
  for(int i = 0; i < n; i++)
  {
    digitalWrite(ledVars[i],HIGH);
  }
}

//Tüm LED'leri söndüren fonksiyon.
void LedOff()
{
  for(int i = 0; i < 3; i++)
  {
    digitalWrite(ledVars[i],LOW);
  }
}