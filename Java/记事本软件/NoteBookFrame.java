import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class NoteBookFrame extends JFrame {
    // 创建窗口，控件
    JPanel panel = new JPanel(); // 新建一个窗口
    JButton button_read = new JButton("读取");  //创建按钮读取
    JButton button_save = new JButton("保存");  //创建按钮保存

    JTextField pathTextField = new JTextField(20); //添加单行文本框控件,路径用
    JTextArea stringTextArea = new JTextArea(); //添加单行文本框控件，编写的文本用

    JLabel pathLabel = new JLabel("请在下方输入保存或读取路径");
    JLabel textLabel = new JLabel("请在下方输入编写的文本");

    JLabel copyrightLabel = new JLabel("Written by ChenAo");





    public NoteBookFrame(String title){
        // 初始化
        JFrame frame = new JFrame(title); // 初始化窗口，并命名
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  // 关闭窗口时关闭进程
        frame.setContentPane(panel);  // 面板给容器里面

        // 在面板中添加控件
        //添加按钮
        panel.add(button_read);
        panel.add(button_save);

        //添加文本框控件
        panel.add(pathTextField);
        panel.add(stringTextArea);

        // 标签添加到面板
        panel.add(pathLabel);
        panel.add(textLabel);
        panel.add(copyrightLabel);


        //添加监视
        // 添加按钮监视
        button_read.addActionListener(new ActionListener_ButtonRead());
        button_save.addActionListener(new ActionListener_ButtonSave());


        //手工进行布置
        panel.setLayout(null);// 禁用布局器
        textLabel.setBounds(5, 5, 200, 20);
        stringTextArea.setBounds(5, 25, 350, 200);
        pathLabel.setBounds(5, 230, 200, 20);
        pathTextField.setBounds(5, 255, 350, 20);
        button_read.setBounds(100, 280, 60, 30);
        button_save.setBounds(180, 280, 60, 30);
        copyrightLabel.setBounds(130,320,200,30);

        // 设置窗口
        frame.setSize(375, 400);  // 设置窗口大小
        frame.setVisible(true); // 显示窗口
    }





    // 保存监视控件
    class ActionListener_ButtonSave implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            file saveFile = new file(pathTextField.getText());// 读取路径文本框的内容作为写文件的路径
            saveFile.write(stringTextArea.getText()); // 读取内容文本框的内容并写入文件
        }
    }

    // 读取监视控件
    class ActionListener_ButtonRead implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            file newFile = new file(pathTextField.getText()); // 读取路径文本框的内容作为读文件的路径
            stringTextArea.setText(newFile.read());  // 把文件读取到内容给文件文本框
        }
    }
}


