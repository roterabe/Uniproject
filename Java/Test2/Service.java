
public class Service {
    String priority;
    double price = 0;
    double percent = 0;
    final double dds = 20;

    Service(String priority, int price) {
        this.priority = priority;
        this.price = price;

        if (priority != "LOW" && priority != "MEDIUM" && priority != "HIGH") {
            this.priority = "LOW";
        }
    }

    double servicePriceWithoutTax() {
        double res = 0;
        if (isHigh()) {
            percent = 20;
            res = price + price * percent / 100;
            return res;
        }
        if (isMedium()) {
            percent = 10;
            res = price + price * percent / 100;
            return res;
        }
        return price;
    }

    double servicePrice() {
        return servicePriceWithoutTax() + servicePriceWithoutTax() * dds / 100;
    }

    boolean isHigh() {
        if (priority == "HIGH") {
            return true;
        }
        return false;
    }

    boolean isMedium() {
        if (priority == "MEDIUM") {
            return true;
        }
        return false;
    }
}

class Cleaning extends Service {
    double area;

    Cleaning(String priority, int price, double area) {
        super(priority, price);
        this.area = area;
    }

    @Override
    double servicePriceWithoutTax() {
        return super.servicePriceWithoutTax() * area;
    }

    @Override
    double servicePrice() {
        return super.servicePrice();
    }

    double servicePriceHigh() {
        if (!isHigh() && !isMedium()) {
            percent = 20;
            return servicePrice() + servicePrice() * percent / 100;
        }
        if (!isHigh()) {
            percent = 20;
            double newpr = price * area + price*area * dds/100;
            return newpr + newpr * (percent / 100);
        }
        return servicePrice();
    }

    boolean moreExpensive(Cleaning c) {
        if (price >= c.price) {
            return true;
        }
        return false;
    }

}