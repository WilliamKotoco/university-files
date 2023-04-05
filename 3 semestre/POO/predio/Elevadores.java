public class Elevadores {
    private int andarAtual = 1;

    public int getAndarAtual() {
        return andarAtual;
    }

    public void setAndarAtual(int andarAtual) {
        this.andarAtual = andarAtual;
    }

    public void Chamar(int andarAtual, int andarParaIr) throws  InterruptedException
    {
        System.out.println("O elevador mais próximo está no andar: " + getAndarAtual());
        Thread.sleep(5000);
        System.out.println("O elevador está chegando");
       Thread.sleep(2000);
        if( (andarAtual - andarParaIr) > 0)
            System.out.println("Descendo " + (andarAtual - andarParaIr) +" andares");
        else
            System.out.println("Subindo " + Math.abs(andarAtual - andarParaIr) +" andares");
        Thread.sleep(7000);
        System.out.println("Você está no andar " + andarParaIr);
        this.setAndarAtual(andarParaIr);


    }


}
