import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class LoginFrame extends JFrame {
    private JTextField usernameField;
    private JPasswordField passwordField;

    public LoginFrame() {
        setTitle("登录");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(3, 2));

        JLabel usernameLabel = new JLabel("用户名:");
        usernameField = new JTextField();
        JLabel passwordLabel = new JLabel("密码:");
        passwordField = new JPasswordField();
        JButton loginButton = new JButton("登录");

        loginButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String username = usernameField.getText();
                String password = new String(passwordField.getPassword());

                // 验证用户名和密码
                boolean isValid = Database.verifyUser(username, password);

                //if (isValid) {
                //    StudentInfoFrame studentInfoFrame = new StudentInfoFrame();
                //    studentInfoFrame.setVisible(true);

                //    LoginFrame.this.dispose();
                //} else {
                //    JOptionPane.showMessageDialog(LoginFrame.this, "用户名或密码不正确", "错误", JOptionPane.ERROR_MESSAGE);
                //}
                if (!isValid) {
                    JOptionPane.showMessageDialog(LoginFrame.this, "用户名或密码不正确", "错误", JOptionPane.ERROR_MESSAGE);
                }

                StudentInfoFrame studentInfoFrame = new StudentInfoFrame();
                studentInfoFrame.setVisible(true);
                LoginFrame.this.dispose();
            }
        });

        add(usernameLabel);
        add(usernameField);
        add(passwordLabel);
        add(passwordField);
        add(new JLabel());
        add(loginButton);
    }
}