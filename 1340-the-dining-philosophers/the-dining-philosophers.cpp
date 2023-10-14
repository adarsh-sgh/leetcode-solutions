class DiningPhilosophers {
public:
    DiningPhilosophers() {
        
    }
    mutex mt[5];
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
                          int l = philosopher;
                        int r = (l + 1) % 5;
                    if(philosopher & 1){
                      
                        mt[l].lock();
                        mt[r].lock();
                        pickLeftFork();
                        pickRightFork();
                        eat();
                        putLeftFork();
                        putRightFork();
                        mt[l].unlock();
                        mt[r].unlock();
                    }else{
                        mt[r].lock();
                        mt[l].lock();
                        pickLeftFork();
                        pickRightFork();
                        eat();
                        putLeftFork();
                        putRightFork();
                        mt[r].unlock();
                        mt[l].unlock();
                    }
    }
};