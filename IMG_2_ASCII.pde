// Aby kód fungoval, je potřeba vytvořit složku "data" ve stejné složce, kde je tento kód
// Do složky "data" se dají obrázky, které se budou měnit na ASCII
// Velikost okna MUSÍ BÝT STEJNÁ jako velikost obrázku

//Ovládání:
//  R -> červený filtr
//  G -> zelený filtr
//  B -> modrý filtr
//  0 -> převede obrázek a ukončí program

// Při úspěšném převodu se ve složce projektu objeví "image.txt" s ASCII obrázkem

PImage img;
PrintWriter output;

String a = " ";

boolean small = true;               // !! Jestli 1 pixel bude představovat 1 znak (false) nebo 2 znaky (true) !!

boolean cred = true;
boolean cgreen = false;
boolean cblue = false;
float col;

void setup() {
  size(sirka, vyska);               // !! Velikost okna = přesná velikost obrázku
  img = loadImage("obrazek.png");   // !! Změna obrázku
}

void draw() {
  loadPixels();
  img.loadPixels();
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      int pos = x+y*width;
      
      if (cred == true){
        col = red(img.pixels[pos]);
      }
      if (cgreen == true){
        col = green(img.pixels[pos]);
      }
      if (cblue == true){
        col = blue(img.pixels[pos]);
      }
      
      pixels[pos] = color(col, col, col);
    }
  }
  img.updatePixels();
  updatePixels();
}

void keyPressed() {
  if (key == '0'){
    output = createWriter("image.txt");
    loadPixels();
    img.loadPixels();
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++){
        int pos = x+y*width;
        float red = red(img.pixels[pos]);
        if (red >= 0){
          a = "@";
        }
        if (red > 25){
          a = "&";
        }
        if (red > 50){
          a = "#";
        }
        if (red > 75){
          a = "$";
        }
        if (red > 100){
          a = "x";
        }
        if (red > 125){
          a = "i";
        }
        if (red > 150){
          a = ";";
        }
        if (red > 175){
          a = ":";
        }
        if (red > 200){
          a = "*";
        }
        if (red > 225){
          a = ".";
        }
        output.print(a);
        if (small == true){
          output.print(a);
        }
      }
     output.println();
    }
    img.updatePixels();
    updatePixels();
    output.flush();
    output.close();
    exit();
  }

  if (key == 'r') {
    cred = true;
    cgreen = false;
    cblue = false;
  }
  if (key == 'g') {
    cred = false;
    cgreen = true;
    cblue = false;
  }
  if (key == 'b') {
    cred = false;
    cgreen = false;
    cblue = true;
  }
}
