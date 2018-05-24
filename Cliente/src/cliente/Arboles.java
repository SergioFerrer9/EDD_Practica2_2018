
package cliente;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;


public class Arboles {
   
        NodoLista Primero;
        NodoLista Ultimo;
        Clave1 Primero1;
        Clave1 Ultimo1;
        Clave2 Primero2;
        Clave2 Ultimo2;
        
        NodoInfo PrimeroI = new  NodoInfo(0, 0, 0, 0);
        int contador=1;
        int correlativo=1;
        PrintWriter pw = null;
 
    
    
    public void Agregar_Lista(int id, String nombre, String clave) throws IOException{
    
        NodoLista nuevo= new NodoLista(id, nombre, clave);
        if(Primero==null){
            nuevo.ID=contador;
            nuevo.sig=null;
            nuevo.ant=null;
            Primero=nuevo;
            Ultimo=nuevo;
            contador++;
            
        }else{
            nuevo.ID=contador;
            nuevo.sig=null;
            nuevo.ant=Ultimo;
            Ultimo.sig=nuevo;
            Ultimo=nuevo;
            contador++;
        
        }
        
       Graficar_Lista(); 
        
    }
    
    public void Agregar_dato1(String dato1){
        Clave1 nuevo = new Clave1(dato1);
        if(Primero1==null){
            nuevo.sig=null;
            nuevo.ant=null;
            Primero1=nuevo;
            Ultimo1=nuevo;
        }else{
           nuevo.sig=null;
           nuevo.ant=Ultimo1;
           Ultimo1.sig=nuevo;
           Ultimo1=nuevo;
           
        }
    }
    
    public void Agregar_dato2(String dato2){
        Clave2 nuevo = new Clave2(dato2);
        if(Primero2==null){
            nuevo.sig=null;
            nuevo.ant=null;
            Primero2=nuevo;
            Ultimo2=nuevo;
        }else{
           nuevo.sig=null;
           nuevo.ant=Ultimo2;
           Ultimo2.sig=nuevo;
           Ultimo2=nuevo;
           
        }
    }
    
    

    public void Graficar_Lista(){
        FileWriter fichero = null;
        pw=null;
          try{
            
                fichero = new FileWriter("./Lista.dot");
                pw = new PrintWriter(fichero);
                pw.println("digraph g {");
                pw.println("node [");
                pw.println("fontsize = \"10\"");
                pw.println("shape = \"Mrecord\"");
                pw.println("];\n");
                pw.println("subgraph cluster_1 {");
                pw.println("node [style=filled];");
                NodoLista aux=Primero;
                int a=1;
                if(aux!=null){
                    while(aux!=null){
                        pw.println("\"nodoD"+a+"\"");
                        pw.print("[label=\"ID:"+aux.ID+"&#92;n Nombre:"+aux.Nombre+"\"");
                        if(aux.Estado==1){
                         pw.println(",fillcolor=cyan ];");
                        }else{
                         pw.println("];");
                        }
                        a++;
                        
                        
                        aux=aux.sig;
                    }
                }
                int b=1;
                int c=b+1;
                aux=Primero;
                if(aux!=null){
                    while(aux.sig!=null){
                        pw.println("\"nodoD"+b+"\"->\"nodoD"+c+"\";");
                        pw.println("\"nodoD"+c+"\"->\"nodoD"+b+"\";");
                        b++;
                        c++;
                        aux=aux.sig;
                    }
                }
                pw.print("color=\"orange\"\n");
                pw.print("style =\"filled, bold\"\n");
                pw.print("label =\"Lista de Arboles\"\n");
                pw.print("}");
                pw.println("}");
                fichero.close();
                String cmd = "dot -Tpng Lista.dot -o Lista.png";
              
                Runtime rt = Runtime.getRuntime();
                rt.exec(cmd);
                    
           
  
         } catch (IOException ex) {
                Logger.getLogger(Arboles.class.getName()).log(Level.SEVERE, null, ex);
            } finally {
                try {
                    fichero.close();
                } catch (IOException ex) {
                    Logger.getLogger(Arboles.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        
    }
    
    
///********************** Crear los Arboles ************************

    public boolean Buscar_Arbol(String Archivo, String clave){
        boolean dato=false;
        NodoLista aux=Primero;
        if(aux!=null){
            while(aux!=null){
                //aux.seleccion=0;
                if(aux.Nombre.equals(Archivo)==true){
                    dato=true;
                    break;
                }
             aux=aux.sig;   
            }
        }
        
        if(dato==true){
            return true;
        }else{
            try {
                Agregar_Lista(1, Archivo, clave);
                } catch (IOException ex) {
                Logger.getLogger(Arboles.class.getName()).log(Level.SEVERE, null, ex);
            }
            return false;
        }
     
    }
    
    public void Ajustar_FE(NodoABB actual, int Nivel){
        if(actual!=null){
                              
        
            actual.Nivel=Nivel;
            if(actual.izq!=null){
                Ajustar_FE(actual.izq, Nivel+1);
            }
            if(actual.der!=null){
                Ajustar_FE(actual.der, Nivel+1);
            }
            
            
        }
    }
    
    
    public void Agregar_En_ABB(String Archivo, int Carne){
        NodoLista aux=Primero;
        if(aux!=null){
            while(aux!=null){
                if(aux.Nombre.compareTo(Archivo)==0){
                    NodoABB nuevo = new NodoABB(Carne);
                    nuevo.Contador=correlativo++;
                    aux.Raiz=Insertar(nuevo,aux.Raiz);
                    System.err.println("Agregar en ABB...");
                     Ajustar_FE(aux.Raiz, 0);
                 break;   
                }
                
             aux=aux.sig;
            }
            
           
        }
    
    }

    public NodoABB Insertar(NodoABB nuevo, NodoABB Raiz) {
        if(Raiz==null){
            Raiz=nuevo;
        }else{
            NodoABB actual=Raiz;
            while(true){
                if(nuevo.carnet < actual.carnet){
                    if(actual.izq==null){
                        actual.izq=nuevo;
                        break;
                    }else{
                        actual=actual.izq;
                    }
                }else{
                    if(actual.der==null){
                        actual.der=nuevo;
                        break;
                    }else{
                        actual=actual.der;
                    }
                    
                }
            
            }
        }
        
     return  Raiz;
    }
 
 /// Graficar Lista Con Arboles Completa................................................   
    public void Graficar_Lista_Arboles(){
        FileWriter fichero = null;
        pw=null;
            try {
                
                fichero = new FileWriter("./Arboles.dot");
                pw = new PrintWriter(fichero);
                pw.println("digraph g {");
                pw.println("node [");
                pw.println("fontsize = \"10\"");
                pw.println("shape = \"Mrecord\"");
                pw.println("];\n");
                pw.println("subgraph cluster_1 {");
                pw.println("node [style=filled];");
                NodoLista aux=Primero;
                int a=1;
                if(aux!=null){
                    while(aux!=null){
                        pw.println("\"nodoD"+a+"\"");
                        pw.println("[label=\"ID:"+aux.ID+"&#92;n Nombre:"+aux.Nombre+"\",fillcolor=cyan ];");
                        a++;
                        
                                
                           Graficar_Arbol(aux.Raiz);
                            
                        aux=aux.sig;
                    }
                }       int b=1;
                int c=b+1;
                aux=Primero;
                if(aux!=null){
                    while(aux!=null){
                        if(aux!=Ultimo){
                        pw.println("\"nodoD"+b+"\"->\"nodoD"+c+"\";");
                        pw.println("\"nodoD"+c+"\"->\"nodoD"+b+"\";");
                        pw.println("\"nodoD"+b+"\"->\"nodoB"+aux.Raiz.Contador+"\";");
                        }else{
                        pw.println("\"nodoD"+b+"\"->\"nodoB"+aux.Raiz.Contador+"\";");
                        }
                        b++;
                        c++;
                        aux=aux.sig;
                    }
                }       
                
                
                
                pw.print("color=\"orange\"\n");
                pw.print("style =\"filled, bold\"\n");
                pw.print("label =\"Lista de Arboles\"\n");
                pw.print("}");
                pw.println("}");
                fichero.close();
                String cmd = "dot -Tpng Arboles.dot -o Arboles.png";
                Runtime rt = Runtime.getRuntime();
                rt.exec(cmd);
                
                
            } catch (IOException ex) {
                Logger.getLogger(Arboles.class.getName()).log(Level.SEVERE, null, ex);
            } finally {
                try {
                    fichero.close();
                } catch (IOException ex) {
                    Logger.getLogger(Arboles.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
  
      
    
    }

    public void Graficar_Arbol(NodoABB Raiz) {
        if(Raiz!=null){
            if(Raiz.izq==null && Raiz.der==null){
                pw.println("\"nodoB"+Raiz.Contador+"\" [label=\""+Raiz.carnet+"&#92;n"+"Nivel:"+Raiz.Nivel+"\"];");
            
            }else{
                pw.println("\"nodoB"+Raiz.Contador+"\" [label=\"<C0>|"+Raiz.carnet+"&#92;n"+"Nivel:"+Raiz.Nivel+"|<C1>\"];");
            }
            
            if(Raiz.izq!=null){
                Graficar_Arbol(Raiz.izq);
                pw.println("nodoB"+Raiz.Contador+":C0->nodoB"+Raiz.izq.Contador+";");
                
            }
            
            if(Raiz.der!=null){
                Graficar_Arbol(Raiz.der);
                 pw.println("nodoB"+Raiz.Contador+":C1->nodoB"+Raiz.der.Contador+";");
                
            }
        
        }
    }
   
    
///Inicializacion del Nodo de Informacion.....
public void Nodo_Info(){
   PrimeroI.Nivel=0;
   PrimeroI.Ramas=0;
   PrimeroI.Padres=0;
   PrimeroI.Hojas=0;

}

public void Informacion_ABB(NodoABB actual){
    if(actual!=null){
        
        if(actual.Nivel>PrimeroI.Nivel){
            PrimeroI.Nivel=actual.Nivel;
        }
        
        if(actual.izq!=null || actual.der!=null){
            PrimeroI.Padres++;
        }else if(actual.izq==null && actual.der==null){
            PrimeroI.Hojas++;
        }
        
        if(actual.izq!=null){
            PrimeroI.Ramas++;
            Informacion_ABB(actual.izq);
        }
        
        if(actual.der!=null){
            PrimeroI.Ramas++;
            Informacion_ABB(actual.der);
        }        
        
    }

}
    
    
///Graficar un Solo Arbol......................................................................
public void Graficar_Arbol_Individual(int ID){
    
    NodoLista aux=Primero;
    if(aux!=null){
        while(aux!=null){
            aux.Estado=0;
            if(aux.ID==ID){
                aux.Estado=1;
                 System.err.println("Arbol....");
                try {
                    FileWriter fichero = null;
                    pw=null;
                    fichero = new FileWriter("./Arbol.dot");
                    pw = new PrintWriter(fichero);
                    pw.println("digraph g {");
                    pw.println("node [");
                    pw.println("fontsize = \"10\"");
                    pw.println("shape = \"Mrecord\"");
                    pw.println("];\n");
                    pw.println("subgraph cluster_1 {");
                    pw.println("node [style=filled];");
                    
                    Graficar_Arbol(aux.Raiz);
                    Nodo_Info();
                    Informacion_ABB(aux.Raiz);
                    
                    pw.print("color=\"orange\"\n");
                    pw.print("style =\"filled, bold\"\n");
                    int Altura=PrimeroI.Nivel+1;
                    pw.print("label =\"Nombre: "+aux.Nombre+"&#92;n"+"Nivel: "+PrimeroI.Nivel+"&#92;n"+"Altura: "+Altura+"&#92;n"+"Ramas: "+PrimeroI.Ramas+"&#92;n"+"Nodos Padres: "+PrimeroI.Padres+"&#92;n"+"Nodos Hojas: "+PrimeroI.Hojas+"\"");
                    
                    
                    
                    
                    
                    pw.print("}");
                    pw.println("}");
                    fichero.close();
                    String cmd = "dot -Tpng Arbol.dot -o Arbol.png";
                    Runtime rt = Runtime.getRuntime();
                    rt.exec(cmd);
                    
                    fichero.close();
                        
                   
                } catch (IOException ex) {
                    Logger.getLogger(Arboles.class.getName()).log(Level.SEVERE, null, ex);
                }
            }           

        aux=aux.sig;    
        }
    }
 Graficar_Lista();
        
}

public String Comparar_Claves(String nombre, String clave){
    String Cadenas="";
    Primero1=null;
    Primero2=null;
    Ultimo2=null;
    Ultimo2=null;
    NodoLista aux=Primero;
    if(aux!=null){
        while(aux!=null){
            if(aux.Nombre.equals(nombre)==true){
                
               for (String Cadena1: clave.split("&&")) {
                  
                    for(String Cadena2: Cadena1.split(",")){
                        //System.err.println(Cadena2);
                        Agregar_dato1(Cadena2);
                    }
                 }
                
               
               for (String Cadena1: aux.Clave.split("&&")) {
                  
                    for(String Cadena2: Cadena1.split(",")){
                        //System.err.println(Cadena2);
                       Agregar_dato2(Cadena2);
                    }
                 }
               
               
             break;
            }
            
         aux=aux.sig;   
        }
    }
    
    Clave1 aux1=Primero1;
    Clave2 aux2=Primero2;
    
    if(aux1!=null && aux2!=null){
        while(aux1!=null){
            if(aux2!=null){
                if(aux1.dato1.equals(aux2.dato2)==true){
                    System.out.println("Correcto");                
                }else{
                    Cadenas+= "Se Cambio: "+aux1.dato1+" por:  "+aux2.dato2+"\n";
                }
              aux2=aux2.sig;
            }else{
                break;
            }          
            
         aux1=aux1.sig;
        }
    
    }

    
 return Cadenas;
}

    




    
}



