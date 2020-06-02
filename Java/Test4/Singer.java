import java.util.ArrayList;
import java.util.List;

public class Singer extends Thread {
    private String name;
    private List<Song> songs;

    public Singer(String name) {
        this.name = name;
        this.songs = new ArrayList<Song>();
    }

    public void addSong(Song song) {
        this.songs.add(song);
    }

    public void recordSongs() {
        for (Song song : songs) {
            System.out.println("Recording ... " + song);
        }
    }

    @Override
    public String toString() {
        return "Creator{" + "name='" + name + '\'' + '}';
    }

    @Override
    public void run() {
        System.out.println("Begin recording session...");
        try {
            recordSongs();
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Ending recording session...");

    }

    public String GetName() {
        return name;
    }

    public void start() {
        Thread t = new Thread(this);
        t.start();
    }
}
