package ll.pkg1;

import Modelos.Ll1;
import Vista.Interfaz;
import java.io.IOException;
import java.util.Scanner;

public class LL1 {

    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        Scanner leer = new Scanner(System.in);

        System.out.println("Presiona '1' para ingresar a la aplicación");

        int opcion = leer.nextInt();

        switch (opcion) {
            case 1:
                Interfaz interfaz = new Interfaz();
                interfaz.setVisible(true);
                break;
            case 2:
                Ll1 ll1 = new Ll1(test());
                ll1.resultados();
                while (true) {
                    leer = new Scanner(System.in);

                    System.out.println("Cadena a verificar:");
                    String cadena = leer.nextLine();

                    ll1.verificarCadena(cadena);

                    System.out.println("¿Verificar otra cadena?\n1. Si\n2. No");
                    int opCad = leer.nextInt();
                    if (opCad == 2) {
                        break;
                    }
                }
                break;
        }

    }

    private static String test() {
        return "E->E+T\n"
                + "E->T\n"
                + "T->T*F\n"
                + "T->F\n"
                + "F->i\n"
                + "F->(E)";
    }

}
