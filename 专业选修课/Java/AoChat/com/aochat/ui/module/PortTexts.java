package com.aochat.ui.module;

import javax.swing.*;
public class PortTexts implements ComponentBasic {
    JTextField desText = new JTextField();

    public PortTexts(JPanel panel){
        add2Panel(panel);
    }

    @Override
    public void add2Panel(JPanel panel) {
        panel.add(desText);
    }

    @Override
    public void setPosition() {
        desText.setBounds(110, 40, 65, 30);
    }
}
