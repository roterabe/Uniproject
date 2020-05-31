import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class SewingStudio {
    private static final int MAX_T = 3;
    private String name;
    private ArrayList<Worker> workers = new ArrayList<Worker>();
    private ArrayList<Clothing> clothes = new ArrayList<Clothing>();

    SewingStudio(String name) {
        this.name = name;
    }

    void addWorker(Worker e) {
        workers.add(e);
    }

    void beginSewing() {
        for (int i = 0; i < workers.size(); i++) {
            workers.get(i).getClothingPile(clothes);
        }
        beginProcess();
    }

    String getName() {
        return name;
    }

    void addClothing(Clothing e) {
        clothes.add(e);
    }

    void beginProcess() {
        // creates a thread pool with MAX_T no. of
        // threads as the fixed pool size(Step 2)
        ExecutorService pool = Executors.newFixedThreadPool(MAX_T);

        for (int i = 0; i < workers.size(); i++){
            pool.execute(workers.get(i));
        }
        // pool shutdown ( Step 4)
        awaitTerminationAfterShutdown(pool);
    }

    public void awaitTerminationAfterShutdown(ExecutorService threadPool) {
        threadPool.shutdown();
        try {
            if (!threadPool.awaitTermination(60, TimeUnit.SECONDS)) {
                threadPool.shutdownNow();
            }
        } catch (InterruptedException ex) {
            threadPool.shutdownNow();
            Thread.currentThread().interrupt();
        }
    }
}