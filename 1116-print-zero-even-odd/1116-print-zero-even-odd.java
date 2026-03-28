class ZeroEvenOdd 
{
    private int n;
    Semaphore zs;
    Semaphore es;
    Semaphore os;
    
    public ZeroEvenOdd(int n) 
    {
        this.n = n;
        this.os = new Semaphore(0);
        this.es = new Semaphore(0);
        this.zs = new Semaphore(1);
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException 
    {
        for(int i=1;i<=n;i++)
        {
            this.zs.acquire();
            printNumber.accept(0);
            if(i%2==0)
            {
                this.es.release();
            }
            else
            {
                this.os.release();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException 
    {
        for(int i=2;i<=n;i+=2)
        {
            this.es.acquire();
            printNumber.accept(i);
            if(i%2 == 0)
            {
                this.zs.release();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException 
    {
        for(int i=1;i<=n;i+=2)
        {
            this.os.acquire();
            printNumber.accept(i);
            if(i%2!=0)
            {
                this.zs.release();
            }
        }
    }
}