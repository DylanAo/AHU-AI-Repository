import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class StudentInfoFrame extends JFrame {
    public StudentInfoFrame() {
        setTitle("学生信息");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("操作");
        JMenuItem passwordMenuItem = new JMenuItem("修改密码");
        JMenuItem infoMenuItem = new JMenuItem("学生信息");
        JMenuItem gradeMenuItem = new JMenuItem("成绩管理");

        // 修改密码菜单项点击事件
        passwordMenuItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                ChangePasswordDialog dialog = new ChangePasswordDialog(StudentInfoFrame.this);
                dialog.setVisible(true);
            }
        });

        // 学生信息菜单项点击事件
        infoMenuItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(StudentInfoFrame.this, "显示学生信息");
            }
        });

        // 成绩管理菜单项点击事件
        gradeMenuItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                GradeManagementDialog dialog = new GradeManagementDialog(StudentInfoFrame.this);
                dialog.setVisible(true);
            }
        });

        menu.add(passwordMenuItem);
        menu.add(infoMenuItem);
        menu.add(gradeMenuItem);
        menuBar.add(menu);

        setJMenuBar(menuBar);
    }
}