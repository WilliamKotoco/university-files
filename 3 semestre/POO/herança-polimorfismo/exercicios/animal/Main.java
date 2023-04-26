public class Main {

  public static void main(String[] args) {
    Gato gato = new Gato("Marcos", 4);
    Ovelha ovelha = new Ovelha("José", 4);
    Vaca vaca = new Vaca("Carlinhos", 4);

    Animal bichos[] = {gato, ovelha, vaca};

    if(vaca instanceof Animal && gato instanceof Animal && ovelha instanceof Animal)
    {
        System.out.println("vaca, gato e ovelha são animais");
    }
    System.out.println("-----------------------");

    for(int i = 0; i < bichos.length; i++)
    {
        System.out.println(bichos[i].name + "tem " + bichos[i].numberOfPaws 
        +" patas e faz ");
        bichos[i].emitirSom();

        System.out.println("");
    }
  }
}