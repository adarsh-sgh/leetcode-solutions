class FooBar {
private:
    int n;
    bool turnOfBar = 0;
    mutex m;
    condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            unique_lock<mutex>lock(m);
            cv.wait(lock,[&]{return !turnOfBar;});
        	printFoo();
            turnOfBar = !turnOfBar;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
             unique_lock<mutex>lock(m);
            cv.wait(lock,[&]{return turnOfBar;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turnOfBar = !turnOfBar;
            cv.notify_all();
        }
    }
};