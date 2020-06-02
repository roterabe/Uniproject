

public class NotAppropriateCategoryException extends Exception{
    private String category;

    NotAppropriateCategoryException(String category) {
        this.category = category;
    }

    String getCategory() {
        return category;
    }

    @Override
    public String toString() {
        return "NotAppropriateCategoryException{" +
                "category is " + category +
                '}';
    }
}
