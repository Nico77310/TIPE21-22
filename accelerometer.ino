int xpin = A3;         //Recolte les données analogique de la carte
int ypin = A2;
int zpin = A1;
int xvalue;
int yvalue;
int zvalue;

void setup() 
{
  Serial.begin(9600);  //Initialise les communication de série

}

void loop() 
{
  xvalue = analogRead(xpin);                 //Attribue a la variable 'xvalue' la valeur analogique de l'axe x
  int x = map(xvalue, 299, 400, -100, 100);  //Etape de calibrage; renvoie les valeurs analogique entre -100 et 100
  float xg = (float)x/(-100.00);             //Résultat en g 
  Serial.print(xg);                          //Renvoie le resultat
  //Serial.print("g   ");

  yvalue = analogRead(ypin);
  int y = map(yvalue, 267, 406, -100, 100);
  float yg = (float)y/(-100.00);
  Serial.print("\t");
  Serial.print(yg);
  //Serial.print("g   ");

  zvalue = analogRead(zpin);
  int z = map(zvalue, 283, 410, -100, 100);
  float zg = (float)z/(100.00);
  Serial.print("\t");
  Serial.println(zg);
  //Serial.println("g   ");
  delay(50);                                  //Échantillonage d'une période de 50ms

}
