public class Main {
    public static void main(String[] args) {
        CourierCompany ekont = new CourierCompany("Ekont");
        Box b = new Box(10, 10, 10);
        Material Na = new Material("Na", true);
        Material Sn = new Material("Sn", false);
        Element e = new Element(Na, 1);
        Element e1 = new Element(Sn, 2);
        Furniture f = new Furniture(b, "Alexandrovska 96", 2, "Videnov");
        Shoes s = new Shoes(b, "Alexandrovska 1", 5, true);
        f.addElement(e);
        f.addElement(e1);
        s.addElement(e);
        s.addElement(e1);
        ekont.addItem(f);
        ekont.addItem(s);
        ekont.totalEarnings();
        ekont.totalVolume();
        System.out.println(s.toString());
    }
}