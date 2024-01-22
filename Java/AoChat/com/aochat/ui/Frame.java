package com.aochat.ui;

import com.aochat.ui.module.*;
import com.aochat.ui.module.Labels;
import com.aochat.ui.module.Menu;

import javax.swing.*;
import java.awt.*;

public class Frame {
    JPanel rootPanel = new JPanel();  // 新建根窗口
    JFrame frame = new JFrame("AoChat"); // 初始化窗口，并命名
    Menu menuBar = new Menu(rootPanel, frame);  // 新建菜单栏

    IPText ipText = new IPText(rootPanel);  // 新建IP输入栏

    PortTexts portTexts = new PortTexts(rootPanel); // 新建端口输入栏

    EnterTextArea enterTextArea = new EnterTextArea(rootPanel);  // 新建信息输入栏

    public MessageArea messageArea = new MessageArea(rootPanel);  // 新建消息输入栏

    Labels labels = new Labels(rootPanel);  // 新建信息栏

    Buttons buttons = new Buttons(rootPanel, menuBar);  // 新建按钮组

    public Frame(){
        panelInit(); // 窗口初始化
        setPosition();  // 设置每个组件位置
        addActionListener(); // 添加监听器
    }

    private void panelInit(){
        // 窗口初始化

        // 设置图标
        Toolkit took = Toolkit.getDefaultToolkit();
        Image image = took.getImage("src/img/icon.png");
        frame.setIconImage(image);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  // 关闭窗口时关闭进程
        frame.setContentPane(rootPanel);  // 容器添加到面板
        frame.setResizable(false);  // 不准改大小
        frame.setSize(800, 600);  // 设置窗口大小
        frame.setVisible(true); // 显示窗口
    }


    private void setPosition(){
        // 设置每个组件位置
        rootPanel.setLayout(null);// 禁用布局器
        menuBar.setPosition();
        enterTextArea.setPosition();
        ipText.setPosition();
        portTexts.setPosition();
        messageArea.setPosition();
        labels.setPosition();
        buttons.setPosition();
    }

    private void addActionListener(){
        // 添加监听器
        menuBar.addActionListener();
        buttons.addButtonActionListener(enterTextArea, ipText, portTexts, messageArea, labels, menuBar.ipHistorySet);
    }
}
