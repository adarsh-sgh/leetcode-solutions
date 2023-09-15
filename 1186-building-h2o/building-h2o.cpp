class H2O {
public:
    H2O() {
        
    }
    mutex m;
    condition_variable cv;
    int hexcess = 0;
    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex>lock(m);
        cv.wait(lock,[&](){
            return hexcess < 2;
        });
        hexcess++;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex>lock(m);
        cv.wait(lock,[&](){
            return hexcess >= 0;
        });
        hexcess -= 2;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
         cv.notify_all();
    }
};