#include <LedControl.h>

const int dinP = 7; //Dot Matrix DIN pin
const int csP = 6; //Dot Matrix CS pin
const int clkP = 5; //Dot Matrix CLK pin

LedControl display = LedControl(dinP, clkP, csP); //Dot Matrix objesi
const int DotLocationColumn = 2; //Çok boyutlu resim dizisinin sütun sayısı

//8x8 dot matrix ekranı üzerinde yakılacak noktaların konumunu bulunduran çok boyutlu diziler
//Her dizi bir resmi temsil etmektedir.
//0 - 7 arasında değerler verilebilir.
int DotLocation[4][DotLocationColumn] = {{0,2},{0,3},{1,2},{1,3}}; //{{sütun,satır},{sütun,satır},{sütun,satır},{sütun,satır}}
int DotLocation2[4][DotLocationColumn] = {{2,2},{2,3},{3,2},{3,3}}; 
int DotLocation3[2][DotLocationColumn] = {{4,2},{4,3}}; 
int DotLocation4[3][DotLocationColumn] = {{6,2},{6,3},{7,2}}; 

void setup() {
  //Dot matrix ekranını temizler ve parlaklığını ayarlar.
  display.clearDisplay(0);
  display.shutdown(0, false);
  display.setIntensity(0, 5);
}

void loop() {
  //Her resim 333 ms ara ile dot matrix ekranı üzerinde gösterilir.
  CreateImage(DotLocation, 4, DotLocationColumn);
  delay(333);
  CreateImage(DotLocation2, 4, DotLocationColumn);
  delay(333);
  CreateImage(DotLocation3, 2, DotLocationColumn);
  delay(333);
  CreateImage(DotLocation4, 3, DotLocationColumn);
  delay(333);
}

//Resmi göstermek için kullanılan fonksiyon
void CreateImage(int DotLocation[][2], int DotLocationRow, int DotLocationColumn)
{
  //Verilen noktalara göre resmi göstermek için kullanılacak byte dizisi
  uint8_t image[8] = {
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000
  };

  //Verilen noktaları yakmak için yapılan bitleri sola kaydırma işlemi
  for(int i = 0; i < DotLocationRow; i++)
  {
    image[DotLocation[i][0]] |= (1 << DotLocation[i][1]);
  }

  //Bit kaydırma işlemi sonrası ortaya çıkan diziyi gösteren for döngüsü
  for (int i = 0; i < 8; i++) 
  {
    for (int j = 0; j < 8; j++) 
    {
      display.setLed(0, i, j, bitRead(image[i], 7 - j));
    }
  }
}