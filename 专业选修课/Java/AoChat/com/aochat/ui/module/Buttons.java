package com.aochat.ui.module;

import com.aochat.internet.Send;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.LinkedHashSet;
import java.util.regex.Pattern;

public class Buttons{
    public String sendTxt;
    public static String ip;
    public static int desPort;

    boolean validIpAndPort;

    Menu menuBar;


    JButton sendButton = new JButton("发送");

    JButton newIPButton = new JButton("确认");

    JButton clearButton = new JButton("清空");

    public Buttons(JPanel panel, Menu menuBar){
        add2Panel(panel);
        setPosition();
        this.menuBar = menuBar;
        validIpAndPort = false;

    }

    public void setPosition(){
        sendButton.setBounds(720, 520, 60, 30);
        newIPButton.setBounds(113,70,60,30);
        clearButton.setBounds(650, 520, 60, 30);
    }

    public void add2Panel(JPanel panel){
        panel.add(sendButton);
        panel.add(newIPButton);
        panel.add(clearButton);
    }


    public void addButtonActionListener(EnterTextArea enterTextArea, IPText ipArea, PortTexts portArea, MessageArea messageArea, Labels labels, LinkedHashSet ipHistorySet){
        sendButton.addActionListener(new sendButtonMenuActionListener(enterTextArea, messageArea));
        newIPButton.addActionListener(new newIPActionListener(ipArea, portArea, labels, ipHistorySet));
        clearButton.addActionListener(new clearButtonActionListener(messageArea));
    }

    class sendButtonMenuActionListener implements ActionListener{

        EnterTextArea enterTextArea;
        MessageArea messageArea;

        Labels labels;

        public sendButtonMenuActionListener(EnterTextArea enterTextArea, MessageArea messageArea) {

            this.enterTextArea = enterTextArea;
            this.messageArea = messageArea;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            if (!validIpAndPort) {
                JOptionPane.showMessageDialog(null,"请检查输入IP与端口","警告",JOptionPane.WARNING_MESSAGE);
            }else {
                sendTxt = enterTextArea.text.getText();
                enterTextArea.text.setText("");
                new Thread(new Send(8889,ip, desPort, sendTxt)).start();
                messageArea.message.setText(messageArea.message.getText() + "\n" + "发送:" + sendTxt);
            }
        }
    }

    class newIPActionListener implements ActionListener{
        IPText ipArea;
        PortTexts portArea;

        Labels labels;

        LinkedHashSet ipHistorySet;
        public newIPActionListener(IPText ipArea, PortTexts portArea, Labels labels, LinkedHashSet ipHistorySet){
            this.ipArea = ipArea;
            this.portArea = portArea;
            this.labels = labels;
            this.ipHistorySet = ipHistorySet;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            validIpAndPort = true;
            ip = ipArea.text.getText();
            try{
                desPort = Integer.parseInt(portArea.desText.getText());
            } catch (Exception exception){
                JOptionPane.showMessageDialog(null,"请检查输入端口是否正确","警告",JOptionPane.WARNING_MESSAGE);
                validIpAndPort = false;
            }

            if (isValidIP(ip)){
                labels.setText("发送至:" + ip + ':' + desPort);
            }else {
                JOptionPane.showMessageDialog(null,"请检查输入IP是否正确","警告",JOptionPane.WARNING_MESSAGE);
                validIpAndPort = false;
            }

            if (validIpAndPort){
                ipHistorySet.add(ip + ':' + portArea.desText.getText());
                menuBar.refreshIpHistoryMenu();
            }
        }
    }

    class clearButtonActionListener implements ActionListener{
        MessageArea messageArea;

        public clearButtonActionListener(MessageArea messageArea) {

            this.messageArea = messageArea;
        }

        @Override
        public void actionPerformed(ActionEvent e) {

            messageArea.message.setText("");
        }
    }

    private boolean isValidIP(String ip) {

        if ((ip != null) && (!ip.isEmpty())) {
            return Pattern.matches("^([1-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])(\\.(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])){3}$", ip);
        }else {
            return false;
        }
    }

    public static void setIpAndPort(String IpAndPort){
        String []arr = IpAndPort.split(":");
        ip = arr[0];
        desPort = Integer.parseInt(arr[1]);

    }
}
