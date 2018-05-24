
package cliente;


import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.ImageIcon;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.JSONValue;
import java.util.Iterator;
import javax.swing.JOptionPane;



public class Cliente extends javax.swing.JFrame {

    
    Arboles arboles= new Arboles();
    boolean estado=false;
    int Contador_hilo=0;
    public Cliente() throws IOException {
        initComponents();        
       
       
        
    }


    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        scrollPane1 = new java.awt.ScrollPane();
        jLabel1 = new javax.swing.JLabel();
        scrollPane2 = new java.awt.ScrollPane();
        jLabel2 = new javax.swing.JLabel();
        jButton3 = new javax.swing.JButton();
        jTextField1 = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        jButton4 = new javax.swing.JButton();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jMenuItem2 = new javax.swing.JMenuItem();
        jMenu2 = new javax.swing.JMenu();
        jMenuItem1 = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jButton1.setText("Enviar");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("Mostrar Arboles");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        scrollPane1.add(jLabel1);

        scrollPane2.add(jLabel2);

        jButton3.setText("Conectar");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jTextField1.setFont(new java.awt.Font("Dialog", 1, 11)); // NOI18N
        jTextField1.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyTyped(java.awt.event.KeyEvent evt) {
                jTextField1KeyTyped(evt);
            }
        });

        jLabel4.setFont(new java.awt.Font("Dialog", 1, 11)); // NOI18N
        jLabel4.setText("ID Arbol ");

        jButton4.setText("Arbol ");
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });

        jMenu1.setText("Bloque");

        jMenuItem2.setText("Peticion Bloque");
        jMenuItem2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem2ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem2);

        jMenuBar1.add(jMenu1);

        jMenu2.setText("Acerca d");

        jMenuItem1.setText("Datos Generales");
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem1ActionPerformed(evt);
            }
        });
        jMenu2.add(jMenuItem1);

        jMenuBar1.add(jMenu2);

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(scrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 737, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(scrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 221, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(46, 46, 46)
                                .addComponent(jButton3, javax.swing.GroupLayout.PREFERRED_SIZE, 124, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jLabel4)))
                        .addContainerGap(21, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                    .addComponent(jButton4, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(jButton1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(jButton2, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                .addGap(33, 33, 33))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addComponent(jTextField1, javax.swing.GroupLayout.PREFERRED_SIZE, 118, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addContainerGap())))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(11, 11, 11)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(jLabel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jTextField1))
                        .addGap(70, 70, 70)
                        .addComponent(jButton1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButton2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButton4)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 318, Short.MAX_VALUE)
                        .addComponent(jButton3))
                    .addComponent(scrollPane2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(scrollPane1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );

        jTextField1.getAccessibleContext().setAccessibleName("");
        jTextField1.getAccessibleContext().setAccessibleDescription("");

        pack();
    }// </editor-fold>//GEN-END:initComponents

    ///Boton Envier...
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        
       Enviar_Mensaje_UDP("HOLA....");
        
    }//GEN-LAST:event_jButton1ActionPerformed
    
    ///Cargar Imagen.......
    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        Mostrar_Graficas();
  
    
    }//GEN-LAST:event_jButton2ActionPerformed
    
    /// Activar Servidor.......
    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
       if(Contador_hilo==0){
        Contador_hilo++;
        Hilo hilo = new Hilo();
        hilo.start();
        
        
       }
    }//GEN-LAST:event_jButton3ActionPerformed
    
    ///Mostrar Arbol Individual....
    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed
        if(jTextField1.getText().compareTo("")!=0){
            int ID=Integer.parseInt(jTextField1.getText());
            arboles.Graficar_Arbol_Individual(ID);
         
         }
        Mostrar_Arbol();
        Mostrar_Lista();
        
     
        
    }//GEN-LAST:event_jButton4ActionPerformed

    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
         JOptionPane.showMessageDialog(null, "USAC. \nIngenieria en Ciencias y Sistemas.\n"
                + "Estructuras de Datos \"B\" .\nPrimer Semestre 2018\n"
                + "Nombre:Sergio Alfonso Ferrer Garcia.\nCarne:200915305\n"
                + "Practica # 2", "Usuario", JOptionPane.INFORMATION_MESSAGE);
    }//GEN-LAST:event_jMenuItem1ActionPerformed
    
    
   /// Peticion del Bloque....
    private void jMenuItem2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem2ActionPerformed
    
        String respuesta = JOptionPane.showInputDialog("Nombre del Arbol");
        if(arboles.Buscar_Arbol(respuesta,"")==true){
            int resp = JOptionPane.showConfirmDialog(null, "¿Esta seguro?", "Alerta!", JOptionPane.YES_NO_OPTION);
            if(resp==0){
                System.err.println("Enviar");
                String Bloque="{"
                            +"\"tipo-operacion\":"+2+","
                            +"\"nombre\":"+"\""+respuesta+"\","
                            +"\"llave-unica\":\"\","
                            +"\"pre-orden\":[],"
                            +"\"post-orden\":[],"
                            +"\"in-orden\":[]"
                            + "}";
                
                Enviar_Mensaje_UDP(Bloque);
            }

        }
    }//GEN-LAST:event_jMenuItem2ActionPerformed

    private void jTextField1KeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_jTextField1KeyTyped
        char validar=evt.getKeyChar();
        if(Character.isLetter(validar)){
            getToolkit().beep();
            evt.consume();
           
        }
    }//GEN-LAST:event_jTextField1KeyTyped

    public void Mostrar_Graficas(){
        
        ImageIcon img2 = new ImageIcon("./Arboles.png");
        img2.getImage().flush();
        jLabel1.setIcon(img2);
        jLabel1.repaint();
              
        
        ImageIcon img = new ImageIcon("./Lista.png");
        img.getImage().flush();
        jLabel2.setIcon(img);
        jLabel2.repaint();
        
      
    }
    
    public void Mostrar_Arbol(){
    
        
        ImageIcon img2 = new ImageIcon("./Arbol.png");
        img2.getImage().flush();
        jLabel1.setIcon(img2);
        jLabel1.repaint();
    
    }
    
    public void Mostrar_Lista(){
        ImageIcon img = new ImageIcon("./Lista.png");
        img.getImage().flush();
        jLabel2.setIcon(img);
        jLabel2.repaint();
    }
    
    
    ///Enviar Mensaje UDP.....................
    public void Enviar_Mensaje_UDP(String msn){
         try {
      
            
            DatagramSocket miSocket = new DatagramSocket();
            byte[] mensaje = msn.getBytes();
            InetAddress host = InetAddress.getByName("127.0.0.1");
            int puerto = 9107;
            DatagramPacket miPaquete = new DatagramPacket(mensaje, msn.length(),host,puerto);
            miSocket.send(miPaquete);
        
            
            
        } catch (SocketException ex) {
            Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
        } catch (UnknownHostException ex) {
            Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    ///Resivier Mensajes UDP......................
    public void Resivir_Mensaje_UDIP(){
             try {
                DatagramSocket miSocket = new DatagramSocket(9108);
                int b = 1024*30;
                byte[] buffer = new byte[b];
                while(true){

                    DatagramPacket peticion = new DatagramPacket(buffer,buffer.length);
                    miSocket.receive(peticion);

                  //  System.err.println(new String(peticion.getData(),0,peticion.getLength()));
                    String Bloque=new String(peticion.getData(),0,peticion.getLength());
                   // Bloque=Bloque.replace("-","");
                  //  System.out.println(Bloque);
                    
                    Leer_JSON(Bloque);
                    
                   
                   
                }
            } catch (SocketException ex) {
                Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
            } catch (IOException ex) {
                Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
            }
    
    
    }
    
    public void Leer_JSON(String Json){
        Object obj = JSONValue.parse(Json);
        JSONObject jsonObject = (JSONObject) obj;
       
        long Tipo = (long) jsonObject.get("tipo-operacion");
      //  System.out.println("tipo-operacion "+Tipo);
        
        String Nombre = (String) jsonObject.get("nombre");
       // System.out.println("nombre "+Nombre);
        String KEY = (String) jsonObject.get("llave-unica");
        
        if(arboles.Buscar_Arbol(Nombre,KEY)==false){
          
            String LLave = (String) jsonObject.get("llave-unica");
          //  System.out.println("llave-unica"+LLave);
            JSONArray PreOrden = (JSONArray) jsonObject.get("pre-orden");
            Iterator interator = PreOrden.iterator();
          //  System.out.println("pre-orden");
            while(interator.hasNext()){
                JSONObject json = (JSONObject) interator.next();
                long Carnet =(long) json.get("carnet");
                
                arboles.Agregar_En_ABB(Nombre, (int) Carnet);
              //  System.out.println(Carnet);
            }
            arboles.Graficar_Lista_Arboles();
            arboles.Graficar_Lista();

        }else{
           
           String Cadenas = arboles.Comparar_Claves(Nombre, KEY);
           System.err.println(Nombre);
           System.out.println(KEY);
           if(Cadenas.equals("")){
                JOptionPane.showMessageDialog(null, "*** La Clave-Unica es correcta  ***");
   
           }else{
               JOptionPane.showMessageDialog(null,Cadenas, "Error en la Clave-Unica", JOptionPane.WARNING_MESSAGE);
           }
            
        }
        
        
        
    }
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Cliente.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Cliente.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Cliente.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Cliente.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    new Cliente().setVisible(true);
                } catch (IOException ex) {
                    Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JMenuItem jMenuItem2;
    private javax.swing.JTextField jTextField1;
    private java.awt.ScrollPane scrollPane1;
    private java.awt.ScrollPane scrollPane2;
    // End of variables declaration//GEN-END:variables

    void setJSON(String json) {
        System.err.println(json);
        
    }
    
    
    class Hilo extends Thread{
    
    
    public void run(){
          
           
        while(true){
            
            Resivir_Mensaje_UDIP();
            
        }
       
    
    }

}
    
    
    
    
    
}



