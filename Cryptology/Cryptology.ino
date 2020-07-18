#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String harf, yeniKelime, bitDonustur, harfDonustur, al, hecele;
int temp,count = 0;  
char oku[100]; 

void setup() {                
  Serial.begin(9600);   
  //DNA("AAGTATAGTGCATTATTGACCGAGGACGCTAACTGGTCAT");
  //DNA("AGCTGAGGCACAATCGATTTACCGTTATTAAGCGGATATT");   
  Serial.println("Kriptoloji Yonteminiz...");
}

void loop() { 
  if (Serial.available() > 0) 
  {  
    oku[count] = (char)Serial.read();  
    if (oku[count++] == '\r')
    {         
      oku[count] = '\0';         
      Serial.println("1 . Metin ---> DNA"); Serial.print(oku); lcd.clear(); MetintoDNA(oku);
      //Serial.println("2 . DNA ---> Metin"); Serial.print(oku); lcd.clear(); DNAtoMetin(oku);        
      count = 0;                     
    }
  }
} 

void DNAtoMetin(String sequence)
{		 				
  for (int i=0; i<sequence.length(); i +=5)
  {
    bitDonustur = donustur(sequence.substring(i, i+5));
    harfDonustur = cozumle(yeniKelime);
    lcd.print(harfDonustur);    
  } 
} 

void MetintoDNA(String sequence)
{		  				
  for (int i=0; i<sequence.length(); i++)
  { 
    harfDonustur = butunlestir(sequence.substring(i,i+1)); 
    bitDonustur = olustur(harfDonustur);
    lcd.print(bitDonustur);			
  } 
} 	


String donustur(String kelime)
{
  yeniKelime = "";
  for (int i=0; i<kelime.length(); i++)
  {
    if (kelime.charAt(i) == 'A' || kelime.charAt(i) == 'T') temp=0;
    if (kelime.charAt(i) == 'G' || kelime.charAt(i) == 'C') temp=1;
    yeniKelime = yeniKelime + temp;
  }
  return yeniKelime;
}

String cozumle(String hecele)
{ 	 
  if (hecele.equals("00000")) harf = "A";  //0
  if (hecele.equals("00001")) harf = "B";  //1
  if (hecele.equals("00010")) harf = "C";  //2			
  if (hecele.equals("00011")) harf = "Ç";  //3			
  if (hecele.equals("00100")) harf = "D";  //4			
  if (hecele.equals("00101")) harf = "E";  //5			
  if (hecele.equals("00110")) harf = "F";  //6			
  if (hecele.equals("00111")) harf = "G";  //7
  if (hecele.equals("01000")) harf = "G";  //8
  if (hecele.equals("01001")) harf = "H";  //9
  if (hecele.equals("01010")) harf = "I";  //10
  if (hecele.equals("01011")) harf = "I";  //11
  if (hecele.equals("01100")) harf = "J";  //12
  if (hecele.equals("01101")) harf = "K";  //13
  if (hecele.equals("01110")) harf = "L";  //14
  if (hecele.equals("01111")) harf = "M";  //15			
  if (hecele.equals("10000")) harf = "N";  //16
  if (hecele.equals("10001")) harf = "O";  //17
  if (hecele.equals("10010")) harf = "Ö";  //18
  if (hecele.equals("10011")) harf = "P";  //19
  if (hecele.equals("10100")) harf = "R";  //20
  if (hecele.equals("10101")) harf = "S";  //21
  if (hecele.equals("10110")) harf = "S";  //22
  if (hecele.equals("10111")) harf = "T";  //23
  if (hecele.equals("11000")) harf = "U";  //24
  if (hecele.equals("11001")) harf = "Ü";  //25
  if (hecele.equals("11010")) harf = "V";  //26
  if (hecele.equals("11011")) harf = "Y";  //27
  if (hecele.equals("11100")) harf = "Z";  //28
  return harf;
}


String olustur(String kelime)
{				 
  yeniKelime = "";
  //Random rnd = new Random();
  for (int i=0; i<kelime.length(); i++)
  {
    if (kelime.charAt(i) == '0'){
      temp = random(2);
      if (temp == 0) al = "A";
      if (temp == 1) al = "T";
    }	
    if (kelime.charAt(i) == '1'){
      temp = random(2);
      if (temp == 0) al = "G";
      if (temp == 1) al = "C";
    } 	 
    yeniKelime = yeniKelime + al;
  }
  return yeniKelime;
}

String butunlestir(String harf)
{ 	 
  if (harf.equals("A")) hecele = "00000";  //0
  if (harf.equals("B")) hecele = "00001";  //1
  if (harf.equals("C")) hecele = "00010";  //2			
  if (harf.equals("Ç")) hecele = "00011";  //3			
  if (harf.equals("D")) hecele = "00100";  //4			
  if (harf.equals("E")) hecele = "00101";  //5			
  if (harf.equals("F")) hecele = "00110";  //6			
  if (harf.equals("G")) hecele = "00111";  //7
  if (harf.equals("G")) hecele = "01000";  //8
  if (harf.equals("H")) hecele = "01001";  //9
  if (harf.equals("I")) hecele = "01010";  //10
  if (harf.equals("I")) hecele = "01011";  //11
  if (harf.equals("J")) hecele = "01100";  //12
  if (harf.equals("K")) hecele = "01101";  //13
  if (harf.equals("L")) hecele = "01110";  //14
  if (harf.equals("M")) hecele = "01111";  //15			
  if (harf.equals("N")) hecele = "10000";  //16
  if (harf.equals("O")) hecele = "10001";  //17
  if (harf.equals("Ö")) hecele = "10010";  //18
  if (harf.equals("P")) hecele = "10011";  //19
  if (harf.equals("R")) hecele = "10100";  //20
  if (harf.equals("S")) hecele = "10101";  //21
  if (harf.equals("S")) hecele = "10110";  //22
  if (harf.equals("T")) hecele = "10111";  //23
  if (harf.equals("U")) hecele = "11000";  //24
  if (harf.equals("Ü")) hecele = "11001";  //25
  if (harf.equals("V")) hecele = "11010";  //26
  if (harf.equals("Y")) hecele = "11011";  //27
  if (harf.equals("Z")) hecele = "11100";  //28
  return hecele;
}
