class ZeroEvenOdd 
{
    private int n;
    Semaphore e;
    Semaphore o;
    Semaphore z;
    
    public ZeroEvenOdd(int n) 
    {
        this.n = n;
        this.e = new Semaphore(0);
        this.z = new Semaphore(1);
        this.o = new Semaphore(0);
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException 
    {
        for(int i=0;i<n;i++)
        {
            this.z.acquire();
            printNumber.accept(0);
            if(i%2==0)
            {
                this.o.release();
            }
            else
            {
                this.e.release();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException 
    {
        for(int i=2;i<=n;i+=2)
        {
            this.e.acquire();
            printNumber.accept(i);
            this.z.release();
        }   
    }

    public void odd(IntConsumer printNumber) throws InterruptedException 
    {
        for(int i=1;i<=n;i+=2)
        {
            this.o.acquire();
            printNumber.accept(i);
            this.z.release();
        }
    }
}