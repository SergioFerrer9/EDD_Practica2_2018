
package cliente;


public class NodoABB {
    int carnet;
    int Altura;
    int fe;
    int Nivel;
    int Contador;
    NodoABB izq;
    NodoABB der;  
    
        public NodoABB(int carnet){
            this.carnet=carnet;
            this.Altura=0;
            this.fe=0;
            this.Nivel=0;
            this.Contador=0;
            this.izq=null;
            this.der=null;
       
        }
    
}
