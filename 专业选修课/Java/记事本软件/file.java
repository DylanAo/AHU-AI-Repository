import java.io.*;

public class file {
    private String file_path;

    public file(String file_path) {
        this.file_path = file_path;
    }

    String read() {
        String readStr = "";
        try {
            String str;
            BufferedReader in = new BufferedReader(new FileReader(this.file_path));
            while ((str = in.readLine()) != null) {
                readStr += str;
                readStr += '\n';
            }
        } catch (IOException e) {

        }
        return readStr;
    }

    void write(String str) {
        try {
            BufferedWriter out = new BufferedWriter(new FileWriter(this.file_path));
            out.write(str);
            out.close();
        } catch (IOException e) {

        }
    }
}
