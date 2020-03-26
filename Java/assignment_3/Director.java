public class Director {
    int age;
    String name;

    Director() {
    }

    public void setDir(int age, String name) {
        this.age = age;
        this.name = name;
    }

    public void displayDir() {
        System.out.println("Director name: " + name);
        System.out.println("Director age: " + age);
    }

}