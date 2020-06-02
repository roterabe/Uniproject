import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        Song s = new Song("Living on a ", Category.ROCK, 120.0);
        Song s1 = new Song("Another one bites the ", Category.POP, 120.0);
        RecordingStudio r = new RecordingStudio("The Blues");
        Singer sing = new Singer("Bon Jovi");
        Singer sing1 = new Singer("Queen");
        r.addSinger(sing);
        r.addSinger(sing1);
        sing.addSong(s);
        sing1.addSong(s1);
        String filename = "Songs.ser";
        String filename1 = "Singers.txt";

        try {
            r.writeTextInRockSong(s, "prayer");
        } catch (Exception e) {
            System.err.println(e);
        }

        try {
            r.writeTextInRockSong(s1, "dust");
        } catch (Exception e) {
            System.err.println(e);
        }

        System.out.println(s.toString());

        r.serializeSong(s, filename);
        r.serializeSong(s1, filename);
        Song song2 = r.deserializeSong(filename);
        System.out.println(song2.toString());

        r.recordSongs(sing);
        r.recordSongs(sing1);

        System.out.println(r.readSongName(s, "prayer"));

        try {
            r.saveSingersInFile(filename1);
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}