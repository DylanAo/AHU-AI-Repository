package com.aochat.ui.module;

import javax.swing.*;

public class EnterTextArea implements ComponentBasic {
    JTextArea text = new JTextArea();

    public EnterTextArea(JPanel panel){

        add2Panel(panel);
    }

    public void add2Panel(JPanel panel){

        panel.add(text);
    }

    public void setPosition(){

        text.setBounds(180, 400, 600, 100);
    }
}
