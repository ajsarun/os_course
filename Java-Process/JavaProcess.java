import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
public class JavaProcess {
    public static void main(String[] args) throws IOException, InterruptedException {
        ProcessBuilder builder = new ProcessBuilder("ls", "-l");
        //ProcessBuilder builder = new ProcessBuilder("./child");
        Process process = builder.start();

        BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
        String line;
        while ((line = reader.readLine()) != null) {
            System.out.println(line);
        }
        int exitCode = process.waitFor();
        System.out.println("Exited with code: " + exitCode);
    }
}