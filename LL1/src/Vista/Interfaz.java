
package Vista;

import java.awt.event.KeyEvent;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;
import java.util.Stack;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Pattern;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
import Modelos.GSVicio;
import Modelos.Gramatica;
import Modelos.Primero;
import Modelos.Siguiente;
import Modelos.TablaM;

public class Interfaz extends javax.swing.JFrame {

  
    TablaM tablaM;
    String S;

    public Interfaz() {
        this.setExtendedState(MAXIMIZED_BOTH);
        initComponents();
    }

 
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jPanel2 = new javax.swing.JPanel();
        tituloGram = new javax.swing.JLabel();
        gramOriginal = new javax.swing.JLabel();
        Cadena = new javax.swing.JTextField();
        Btn_Verificar = new javax.swing.JButton();
        escogerGram = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        JScrollPanel = new javax.swing.JScrollPane();
        JTablaM = new javax.swing.JTable();
        jScrollPane1 = new javax.swing.JScrollPane();
        JTable = new javax.swing.JTable();
        jScrollPane2 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();
        jScrollPane3 = new javax.swing.JScrollPane();
        jTextArea2 = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setBackground(new java.awt.Color(255, 255, 255));

        jPanel2.setBackground(new java.awt.Color(0, 0, 204));

        tituloGram.setFont(new java.awt.Font("Noto Sans", 1, 12)); // NOI18N
        tituloGram.setForeground(new java.awt.Color(255, 255, 254));
        tituloGram.setText("Gramatica original");

        gramOriginal.setFont(new java.awt.Font("Noto Sans", 0, 12)); // NOI18N
        gramOriginal.setForeground(new java.awt.Color(255, 255, 254));
        gramOriginal.setVerticalAlignment(javax.swing.SwingConstants.TOP);

        Cadena.setBackground(new java.awt.Color(0, 0, 204));
        Cadena.setFont(new java.awt.Font("Noto Sans", 0, 12)); // NOI18N
        Cadena.setForeground(new java.awt.Color(255, 255, 254));
        Cadena.setBorder(javax.swing.BorderFactory.createMatteBorder(0, 0, 2, 0, new java.awt.Color(255, 255, 255)));
        Cadena.setCaretColor(new java.awt.Color(255, 255, 254));
        Cadena.setSelectedTextColor(new java.awt.Color(255, 255, 254));
        Cadena.setSelectionColor(new java.awt.Color(255, 255, 254));
        Cadena.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CadenaActionPerformed(evt);
            }
        });
        Cadena.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                CadenaKeyPressed(evt);
            }
        });

        Btn_Verificar.setBackground(new java.awt.Color(255, 255, 255));
        Btn_Verificar.setForeground(new java.awt.Color(60, 63, 65));
        Btn_Verificar.setText("Verificar");
        Btn_Verificar.setBorder(new javax.swing.border.MatteBorder(null));
        Btn_Verificar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                Btn_VerificarActionPerformed(evt);
            }
        });

        escogerGram.setBackground(new java.awt.Color(255, 255, 255));
        escogerGram.setForeground(new java.awt.Color(60, 63, 65));
        escogerGram.setText("Escoger gramatica");
        escogerGram.setBorder(new javax.swing.border.MatteBorder(null));
        escogerGram.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                escogerGramActionPerformed(evt);
            }
        });

        jLabel2.setFont(new java.awt.Font("URW Gothic", 1, 12)); // NOI18N
        jLabel2.setForeground(new java.awt.Color(255, 255, 254));
        jLabel2.setText("Cadena a verificar");

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(gramOriginal, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(tituloGram)
                        .addGap(34, 34, 34))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(Cadena, javax.swing.GroupLayout.PREFERRED_SIZE, 153, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGap(16, 16, 16))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                                .addComponent(escogerGram, javax.swing.GroupLayout.PREFERRED_SIZE, 153, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addContainerGap())))))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(Btn_Verificar, javax.swing.GroupLayout.PREFERRED_SIZE, 153, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(40, 40, 40)
                .addComponent(escogerGram, javax.swing.GroupLayout.PREFERRED_SIZE, 29, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(27, 27, 27)
                .addComponent(jLabel2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(Cadena, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(47, 47, 47)
                .addComponent(Btn_Verificar, javax.swing.GroupLayout.PREFERRED_SIZE, 28, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGap(26, 26, 26)
                        .addComponent(gramOriginal, javax.swing.GroupLayout.DEFAULT_SIZE, 444, Short.MAX_VALUE))
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(tituloGram)
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );

        jLabel3.setBackground(new java.awt.Color(255, 255, 255));
        jLabel3.setFont(new java.awt.Font("Noto Sans", 1, 14)); // NOI18N
        jLabel3.setText("Gramatica Limpia");

        jLabel4.setFont(new java.awt.Font("Noto Sans", 1, 14)); // NOI18N
        jLabel4.setText("Primeros y Siguientes");

        JScrollPanel.setBackground(new java.awt.Color(255, 255, 255));

        JTablaM.setFont(new java.awt.Font("Noto Sans", 0, 12)); // NOI18N
        JTablaM.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {

            }
        ));
        JScrollPanel.setViewportView(JTablaM);

        JTable.setFont(new java.awt.Font("Noto Sans", 0, 12)); // NOI18N
        JTable.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Pila", "Entrada", "Salida"
            }
        ));
        jScrollPane1.setViewportView(JTable);

        jTextArea1.setEditable(false);
        jTextArea1.setBackground(new java.awt.Color(255, 255, 254));
        jTextArea1.setColumns(20);
        jTextArea1.setRows(5);
        jTextArea1.setBorder(null);
        jScrollPane2.setViewportView(jTextArea1);

        jTextArea2.setEditable(false);
        jTextArea2.setBackground(new java.awt.Color(255, 255, 254));
        jTextArea2.setColumns(20);
        jTextArea2.setRows(5);
        jTextArea2.setBorder(null);
        jScrollPane3.setViewportView(jTextArea2);

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(22, 22, 22)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 545, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addGap(213, 213, 213)
                                        .addComponent(jLabel3)))
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(jScrollPane3))
                                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 211, Short.MAX_VALUE)
                                        .addComponent(jLabel4)
                                        .addGap(174, 174, 174))))
                            .addComponent(JScrollPanel))
                        .addGap(30, 30, 30))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(304, 304, 304)
                        .addComponent(jScrollPane1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)))
                .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(jLabel4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.DEFAULT_SIZE, 245, Short.MAX_VALUE)
                    .addComponent(jScrollPane3))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(JScrollPanel, javax.swing.GroupLayout.PREFERRED_SIZE, 187, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(37, 37, 37)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                .addContainerGap())
            .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void escogerGramActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_escogerGramActionPerformed
        JFileChooser chooser = new JFileChooser();
        chooser.showOpenDialog(null);
        File archivo = chooser.getSelectedFile();
        DefaultTableModel TableModel = new DefaultTableModel();
        String Header[] = {"Pila", "Entrada", "Salida"};
        TableModel.setColumnIdentifiers(Header);
        JTable.setModel(TableModel);
        if (archivo == null) {
            JOptionPane.showMessageDialog(null, "No ha selecionado ningun archivo",
                    "No hay archivo", JOptionPane.ERROR_MESSAGE);
        } else {
            try {
                // Usar Archivo
                Gramatica gramatica = new Gramatica(archivo);
                // Imprimir gramatica
                imprimirGramOriginal(gramatica);
                GSVicio gSVicio = new GSVicio(gramatica);
                S = gSVicio.getnTInicial();
                // Imprimir gramatica sin vicio
                imprimirGramSVicio(gSVicio);

                Primero primeros = new Primero(gSVicio);
                Siguiente siguientes = new Siguiente(gSVicio, primeros);

                //Imprimir primeros y siguientes
                imprimirPrimYSig(gSVicio, primeros, siguientes);

                tablaM = new TablaM(gSVicio, primeros, siguientes);
                // Imprimir tabla M
                imprimirTablaM(gSVicio);
            } catch (FileNotFoundException ex) {
                Logger.getLogger(Interfaz.class.getName()).log(Level.SEVERE, null, ex);
            } catch (IOException ex) {
                Logger.getLogger(Interfaz.class.getName()).log(Level.SEVERE, null, ex);
            }

        }
    }//GEN-LAST:event_escogerGramActionPerformed

    private void Btn_VerificarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_Btn_VerificarActionPerformed
        verificarCadena();
    }//GEN-LAST:event_Btn_VerificarActionPerformed

    private void CadenaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CadenaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_CadenaActionPerformed

    private void CadenaKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_CadenaKeyPressed
        if (evt.getKeyCode() == KeyEvent.VK_ENTER) {
            verificarCadena();
        }
    }//GEN-LAST:event_CadenaKeyPressed

    private void imprimirGramOriginal(Gramatica gramatica) {
        String textoGramatica = "<html>";
        for (String llave : gramatica.getNoTerminales()) {
            ArrayList<String> producciones = gramatica.getProducciones().get(llave);
            for (String produccion : producciones) {
                textoGramatica += "<p>" + llave + "->" + produccion + "</p>";
            }
        }
        textoGramatica += "</html>";
        gramOriginal.setText(textoGramatica);
    }

    private void imprimirGramSVicio(GSVicio gSVicio) {
        String textoGramaticaSV = "";
        for (String llave : gSVicio.getNoTerminales()) {
            ArrayList<String> producciones = gSVicio.getProducciones().get(llave);
            for (String produccion : producciones) {
                textoGramaticaSV += llave + "->" + produccion + "\n";
            }
        }
        jTextArea1.setText(textoGramaticaSV);
    }

    private void imprimirPrimYSig(GSVicio gSVicio, Primero primeros, Siguiente siguientes) {
        String textoPrimYSigte = "";
        for (String llave : gSVicio.getNoTerminales()) {
            Set<String> conjunto = primeros.getPrimeros().get(llave);
            textoPrimYSigte += "PRIMERO(" + llave + ")=" + conjunto + "\n";
        }
        textoPrimYSigte += "\n";
        for (String llave : gSVicio.getNoTerminales()) {
            Set<String> conjunto = siguientes.getSiguientes().get(llave);
            textoPrimYSigte += "SIGUIENTE(" + llave + ")=" + conjunto + "\n";
        }
        jTextArea2.setText(textoPrimYSigte);
    }

    private void imprimirTablaM(GSVicio gSVicio) {
        DefaultTableModel modeloTablaM = new DefaultTableModel();
        String[] cabezera = new String[gSVicio.getTerminales().size() + 2];
        cabezera[0] = "No terminal|Terminal";
        int i = 1;
        for (String terminal : gSVicio.getTerminales()) {
            cabezera[i] = terminal;
            i++;
        }
        cabezera[cabezera.length - 1] = "$";
        modeloTablaM.setColumnIdentifiers(cabezera);
        for (String noTerminal : gSVicio.getNoTerminales()) {
            Object[] fila = new Object[gSVicio.getTerminales().size() + 2];
            fila[0] = noTerminal;
            int j = 1;
            for (String terminal : gSVicio.getTerminales()) {
                fila[j] = tablaM.getTablaM(noTerminal, terminal);
                j++;
            }
            fila[fila.length - 1] = tablaM.getTablaM(noTerminal, "$");
            modeloTablaM.addRow(fila);
        }
        JTablaM.setModel(modeloTablaM);
    }

    private void verificarCadena() {
        DefaultTableModel TableModel = new DefaultTableModel();
        String Header[] = {"Pila", "Entrada", "Salida"};
        TableModel.setColumnIdentifiers(Header);

        String check = Cadena.getText() + "$";
        check = check.replaceAll("&", "");

        Stack<String> stack = new Stack<String>();
        stack.push("$");
        stack.push(S);
        String X, a;
        do {
            a = check.charAt(0) + "";
            X = stack.peek();
            if (esTerminal(X + "") || X.equals('$')) {
                if (X.equals(a)) {
                    TableModel.addRow(new Object[]{getStack(stack), check, " "});
                    stack.pop();
                    check = check.substring(1);
                } else {
                    TableModel.addRow(new Object[]{getStack(stack), check, "Error"});
                    JOptionPane.showMessageDialog(null, "Error, cadena invalida",
                            "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
//                    TableModel = new DefaultTableModel();
//                    TableModel.setColumnIdentifiers(Header);
                    break;
                }
            } else {
                HashMap<String, String> Hash = tablaM.getTablaM().get(X + "");
                String Prod = Hash.get(a + "");
                if (Prod == null) {
                    TableModel.addRow(new Object[]{getStack(stack), check, "Error"});
                    JOptionPane.showMessageDialog(null, "Error, cadena invalida",
                            "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
                    break;
                }
                TableModel.addRow(new Object[]{getStack(stack), check, Prod});
                if (!Prod.equals("")) {
                    String f = Prod.charAt(0) + "";
                    if (f.equals(X) || (f.concat("'").equals(X))) {
                        stack.pop();
                        String p;
                        String h = Prod.charAt(1) + "";
                        if (h.equals("'")) {
                            p = Prod.substring(4);
                        } else {
                            p = Prod.substring(3);
                        }
                        boolean sw = true;
                        if (!p.equals("&")) {
                            for (int i = p.length() - 1; i >= 0; i--) {
                                String comp = p.charAt(i) + "";
                                if (comp.equals("'")) {
                                    sw = false;
                                } else if (sw == false) {
                                    stack.push(p.charAt(i) + "'");
                                    sw = true;
                                } else {
                                    stack.push(p.charAt(i) + "");
                                }
                            }
                        }
                    } else {
                        TableModel.addRow(new Object[]{getStack(stack), check, "Error"});
                        JOptionPane.showMessageDialog(null, "Error, cadena invalida",
                                "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
//                        TableModel = new DefaultTableModel();
//                        TableModel.setColumnIdentifiers(Header);
                        break;
                    }
                } else {
                    TableModel.addRow(new Object[]{getStack(stack), check, "Error"});
                    JOptionPane.showMessageDialog(null, "Error, cadena invalida",
                            "ERROR_MESSAGE", JOptionPane.ERROR_MESSAGE);
//                    TableModel = new DefaultTableModel();
//                    TableModel.setColumnIdentifiers(Header);
                    break;
                }
            }
        } while (!X.equals("$"));

        if (X.equals("$") && stack.empty()) {
            JOptionPane.showMessageDialog(null, "Cadena valida",
                    "Exito", JOptionPane.INFORMATION_MESSAGE);
        }
        JTable.setModel(TableModel);
    }

    private boolean esTerminal(String cadena) {
        return Pattern.matches("[A-Z]", cadena) ? false : true;
    }

    public String getStack(Stack<String> S) {
        Iterator value = S.iterator();
        String m = "";
        while (value.hasNext()) {
            m = m + value.next();
        }
        return m;
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
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Interfaz().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Btn_Verificar;
    private javax.swing.JTextField Cadena;
    private javax.swing.JScrollPane JScrollPanel;
    private javax.swing.JTable JTablaM;
    private javax.swing.JTable JTable;
    private javax.swing.JButton escogerGram;
    private javax.swing.JLabel gramOriginal;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JTextArea jTextArea1;
    private javax.swing.JTextArea jTextArea2;
    private javax.swing.JLabel tituloGram;
    // End of variables declaration//GEN-END:variables
}
