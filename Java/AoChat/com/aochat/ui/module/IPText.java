package com.aochat.ui.module;

import javax.swing.*;

public class IPText implements ComponentBasic {
    JTextField text = new JTextField();

    public IPText(JPanel panel){

        add2Panel(panel);
    }

    public void add2Panel(JPanel panel){

        panel.add(text);
    }

    public void setPosition(){

        text.setBounds(5, 40, 100, 30);
    }
}
