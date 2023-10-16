import java.io.File;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.FloatControl;

public class MusicPlayer implements Runnable {
    private static final int SLEEP_TIME = 100;

    private Music current;
    private Clip clip;
    private boolean playing = false;

    public MusicPlayer(Music music) {
        this.current = music;
        new Thread(this).start();
    }

    public void play() {
        if (playing) return;

        playing = true;
        clip.start();
    }

    public void pause() {
        if (!playing) return;

        playing = false;
        clip.stop();
    }

    public void stop() {
        playing = false;
        clip.stop();
    }

    public boolean isPlaying() {
        return playing;
    }

    public Music getCurrent() {
        return current;
    }

    public void prev() {
        int prevIndex = MainWindow.getMusicList().indexOf(current) - 1;

        if (prevIndex < 0) {
            prevIndex = MainWindow.getMusicList().size() - 1;
        }

        current = MainWindow.getMusicList().get(prevIndex);
        loadMusic();
        play();
    }

    public void next() {
        int nextIndex = MainWindow.getMusicList().indexOf(current) + 1;

        if (nextIndex >= MainWindow.getMusicList().size()) {
            nextIndex = 0;
        }

        current = MainWindow.getMusicList().get(nextIndex);
        loadMusic();
        play();
    }

    public void seek(int progress) {
        if (clip != null && clip.isOpen()) {
            long position = clip.getMicrosecondLength() * progress / 100;
            clip.setMicrosecondPosition(position);
        }
    }

    private void loadMusic() {
        try {
            AudioInputStream stream = AudioSystem.getAudioInputStream(current.getFile());
            clip = AudioSystem.getClip();
            clip.open(stream);

            FloatControl gainControl = (FloatControl) clip.getControl(FloatControl.Type.MASTER_GAIN);
            gainControl.setValue(-20f);

            clip.addLineListener(event -> {
                if (event.getType() == javax.sound.sampled.LineEvent.Type.STOP) {
                    next();
                }
            });
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void run() {
        while (true) {
            if (clip != null && clip.isOpen() && playing) {
                long total = clip.getMicrosecondLength();
                long currentPos = clip.getMicrosecondPosition();
                int progress = (int) (currentPos * 100 / total);
                MainWindow.slider.setValue(progress);
            }

            try {
                Thread.sleep(SLEEP_TIME);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}