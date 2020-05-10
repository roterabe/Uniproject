import java.util.HashMap;
import java.util.Map;

public class Client {
    private String name = "";
    private Map<String, Integer> shopping_list = new HashMap<String, Integer>();

    Client(String name) {
        this.name = name;
    }

    void addToBuy(String item, int number) {
        int count = 0;
        count = shopping_list.containsKey(item) ? shopping_list.get(item) : 0;
        shopping_list.put(item, number + count);
    }

    void Buy(Shop s, Register r) {
        s.sell(shopping_list, r);
    }
}