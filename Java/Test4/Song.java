import java.io.Serializable;

public class Song implements Serializable{
    public static final long songID = 12345;
    private String name;
    private transient Category category;
    private double duration;

    public Song(String name, Category category, double duration) {
        this.name = name;
        this.category = category;
        this.duration = duration;
    }

    String getName() {
        return name;
    }

    void changeName(String text) {
        this.name = this.name + text;
    }

    public String getCategory() {
        return category.name();
    }

    @Override
    public String toString() {
        return "Project{" + "name='" + name + '\'' + ", category=" + category + ", duration=" + duration + '}';
    }
}
