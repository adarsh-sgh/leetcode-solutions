class ZeroEvenOdd {
private:
    int n;
    int x = 0;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }
    mutex m;
    condition_variable cv;
    // printNumber(x) outputs "x", where x is an integer.
    void run(function<void(int)>print,function<bool(int)>cond){
        while(x<2*n){
        unique_lock<mutex>lock(m);
        cv.wait(lock,[&](){
            return cond(x) || x>=2 * n;
        });

        if(x>= 2* n){
            // cv.notify_all();
            break;
        }

        print(x);
        x++;
        cv.notify_all();
        }
    }
    void zero(function<void(int)> printNumber) {
        run([&](int x){
            printNumber(0);
        },[](int x){return ~x & 1;});
    }

    void even(function<void(int)> printNumber) {
        run([&](int x){
            printNumber((x+1)/2);
        },[](int x){return (x & 1) && (~((x+1)/2) & 1) ;});
    }

    void odd(function<void(int)> printNumber) {
        run([&](int x){
            printNumber((x+1)/2);
        },[](int x){return (x & 1) && (((x+1)/2) & 1) ;});

    }
};