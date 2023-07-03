class Foo {
public:
    mutex m;
    condition_variable cv;
    int turn = 1;
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        unique_lock<mutex> lck(m);
        printFirst();
        turn++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(m);
        // printSecond() outputs "second". Do not change or remove this line.
        if(turn != 2)cv.wait(lck);
        printSecond();
        turn++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
         unique_lock<mutex> lck(m);
        while(turn != 3)cv.wait(lck);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};