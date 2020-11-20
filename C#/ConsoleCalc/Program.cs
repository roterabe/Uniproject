using System;

namespace ConsoleCalc
{
    class Program
    {
        delegate int Operation(int x, int y);

        static void Main(string[] args)
        {
            int i;

            for (i = 0; i <= 10; i++)

                Console.WriteLine(i);
        }
        static void fun(double d)
        {
            Console.WriteLine(d + " ");
        }

        public int Length
        {
            set
            {
                Length = value;
            }
        }
    }
}

