import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;

public class RecordingStudio {
    private String name;
    private List<Singer> singers;

    public RecordingStudio(String name) {
        this.name = name;
        this.singers = new ArrayList<Singer>();
    }

    public void addSinger(Singer singer) {
        if (!singers.contains(singer)) {
            this.singers.add(singer);
        }
    }

    // Task 1
    public void writeTextInRockSong(Song song, String text) throws NotAppropriateCategoryException {
        if (song.getCategory() == "ROCK") {
            song.changeName(text);
        } else if (song.getCategory() != "ROCK") {
            throw new NotAppropriateCategoryException(song.getCategory());
        }
    }

    // Task 2
    public void saveSingersInFile(String filename) throws IOException {
        File receipt = new File(filename);
        FileWriter writer = new FileWriter(receipt.getAbsoluteFile());
        for (Singer singer : singers) {
            String name = singer.GetName();
            writer.write(name + "*");
        }
        writer.close();
    }

    // Task 3
    public void serializeSong(Song song, String filename) {

        try (FileOutputStream fos = new FileOutputStream(filename);
                ObjectOutputStream oos = new ObjectOutputStream(fos);) {
            oos.writeObject(song);
        } catch (FileNotFoundException ex) {
            System.err.println(ex);
        } catch (IOException ex) {
            System.err.println("IO error: " + ex);
        }

    }

    // Task 3
    public Song deserializeSong(String filename) {
        try (FileInputStream fis = new FileInputStream(filename);
                ObjectInputStream inputStream = new ObjectInputStream(fis);) {

            Song song = (Song) inputStream.readObject();
            return song;

        } catch (ClassNotFoundException ex) {
            System.err.println("Class not found: " + ex);
        } catch (IOException ex) {
            System.err.println("IO error: " + ex);
        }
        return null;
    }

    // Task 4
    public boolean readSongName(Song song, String targetString) {
        String toCheck = song.getName();
        if (toCheck.indexOf(targetString) >= toCheck.length() / 2) {
            System.out.println(toCheck.indexOf(targetString));
            return true;
        } else
            return false;
    }

    // Task 5
    public void recordSongs(Singer singer) {
        singer.start();
    }

    @Override
    public String toString() {
        return "Ide{" + "name='" + name + '\'' + ", singers=" + singers + '}';
    }
}
