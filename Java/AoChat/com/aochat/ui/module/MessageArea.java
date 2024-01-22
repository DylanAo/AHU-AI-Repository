package com.aochat.ui.module;

import javax.swing.*;

public class MessageArea implements ComponentBasic {
    public JTextArea message = new JTextArea();

    public MessageArea(JPanel panel) {
        add2Panel(panel);
    }

    @Override
    public void add2Panel(JPanel panel) {
        panel.add(message);
    }

    @Override
    public void setPosition() {
        message.setBounds(180, 25, 600, 350);
    }
}
