import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ChangePasswordDialog extends JDialog {
    private JPasswordField oldPasswordField;
    private JPasswordField newPasswordField;
    private JPasswordField confirmPasswordField;

    public ChangePasswordDialog(Frame owner) {
        super(owner, "修改密码", true);
        setSize(300, 200);
        setLocationRelativeTo(owner);
        setLayout(new GridLayout(4, 2));

        JLabel oldPasswordLabel = new JLabel("旧密码:");
        oldPasswordField = new JPasswordField();
        JLabel newPasswordLabel = new JLabel("新密码:");
        newPasswordField = new JPasswordField();
        JLabel confirmPasswordLabel = new JLabel("确认密码:");
        confirmPasswordField = new JPasswordField();
        JButton saveButton = new JButton("保存");

        saveButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String oldPassword = new String(oldPasswordField.getPassword());
                String newPassword = new String(newPasswordField.getPassword());
                String confirmPassword = new String(confirmPasswordField.getPassword());

                // 验证旧密码是否正确
                boolean isValid = Database.verifyPassword(oldPassword);

                if (isValid) {
                    // 验证新密码和确认密码是否匹配
                    if (newPassword.equals(confirmPassword)) {
                        // 保存新密码
                        Database.savePassword(newPassword);
                        JOptionPane.showMessageDialog(ChangePasswordDialog.this, "密码修改成功", "提示", JOptionPane.INFORMATION_MESSAGE);
                        ChangePasswordDialog.this.dispose();
                    } else {
                        JOptionPane.showMessageDialog(ChangePasswordDialog.this, "新密码与确认密码不匹配", "错误", JOptionPane.ERROR_MESSAGE);
                    }
                } else {
                    JOptionPane.showMessageDialog(ChangePasswordDialog.this, "旧密码不正确", "错误", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        add(oldPasswordLabel);
        add(oldPasswordField);
        add(newPasswordLabel);
        add(newPasswordField);
        add(confirmPasswordLabel);
        add(confirmPasswordField);
        add(new JLabel());
        add(saveButton);
    }
}