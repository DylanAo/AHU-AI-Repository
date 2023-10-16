import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.ArrayList;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.DefaultListCellRenderer;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JLabel;
import javax.swing.JSlider;
import javax.swing.JToggleButton;
import javax.swing.ListSelectionModel;
import javax.swing.SwingConstants;
import javax.swing.UIManager;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class MainWindow extends JFrame implements ActionListener, ChangeListener {
    private static final long serialVersionUID = 1L;

    public static ArrayList<Music> musicList = new ArrayList<Music>();
    public static ArrayList<Music> getMusicList() {
        return musicList;
    }
    JList<String> list;
    JLabel currentLabel;

    public static JSlider slider = new JSlider(SwingConstants.HORIZONTAL);
    private JPanel panelCenterTop, panelCenter, panelCenterBottom, panelSouth;

    MusicPlayer player;

    public MainWindow() {
        setTitle("Music Player");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 300);

        // Create the list of music files
        list = new JList<String>();
        JScrollPane scrollPane = new JScrollPane(list);

        JPanel buttonPanel = new JPanel(new FlowLayout());
        JButton addButton = new JButton("Add");
        JButton prevButton = new JButton("Prev");
        JButton playButton = new JButton("Play");
        JButton nextButton = new JButton("Next");

        addButton.addActionListener(this);
        prevButton.addActionListener(this);
        playButton.addActionListener(this);
        nextButton.addActionListener(this);

        currentLabel = new JLabel();

        slider = new JSlider(0, 100, 0);
        slider.addChangeListener(this);

        buttonPanel.add(addButton);
        buttonPanel.add(prevButton);
        buttonPanel.add(playButton);
        buttonPanel.add(nextButton);
        buttonPanel.add(currentLabel);
        buttonPanel.add(slider);

        // Add the components to the frame
        getContentPane().add(scrollPane, BorderLayout.CENTER);
        getContentPane().add(buttonPanel, BorderLayout.SOUTH);

        setVisible(true);
    }

    public static void main(String[] args) {
        new MainWindow();
    }

    public void actionPerformed(ActionEvent event) {
        String command = event.getActionCommand();

        if (command.equals("Add")) {
            JFileChooser fileChooser = new JFileChooser();
            fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
            int result = fileChooser.showOpenDialog(this);

            if (result == JFileChooser.APPROVE_OPTION) {
                File file = fileChooser.getSelectedFile();
                Music music = new Music(file);
                musicList.add(music);

                String[] musicNames = new String[musicList.size()];
                for (int i = 0; i < musicList.size(); i++) {
                    musicNames[i] = musicList.get(i).getName();
                }

                list.setListData(musicNames);
            }
        } else if (command.equals("Prev")) {
            player.prev();
            currentLabel.setText(player.getCurrent().getName());
        } else if (command.equals("Play")) {
            if (player == null) {
                if (!musicList.isEmpty()) {
                    player = new MusicPlayer(musicList.get(0));
                    currentLabel.setText(player.getCurrent().getName());
                }
            } else {
                if (player.isPlaying()) {
                    player.pause();
                } else {
                    player.play();
                }
            }
        } else if (command.equals("Next")) {
            player.next();
            currentLabel.setText(player.getCurrent().getName());
        }
    }

    public void stateChanged(ChangeEvent event) {
        int progress = slider.getValue();
        player.seek(progress);
    }
}