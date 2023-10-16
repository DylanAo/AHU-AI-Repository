import java.io.File;

public class Music {
    private File file;

    public Music(File file) {
        this.file = file;
    }

    public String getName() {
        return file.getName();
    }

    public File getFile() {
        return file;
    }
}