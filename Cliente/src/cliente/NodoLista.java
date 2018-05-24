
package cliente;


public class NodoLista {
    int ID;
    String Nombre;
    String Clave;
    int Estado;
    NodoLista sig;
    NodoLista ant;
    NodoABB Raiz;
    
        public NodoLista(int id, String nombre, String Clave){
            this.ID=id;
            this.Nombre=nombre;
            this.Clave=Clave;
            this.Estado=0;
            this.sig=null;
            this.ant=null;
            this.Raiz=null;
        }
    
}
