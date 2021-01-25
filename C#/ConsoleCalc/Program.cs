using System;


namespace ConsoleCalc
{
    interface IPerson

    {

        String FirstName

        { get; set; }

    }

    class Employee : IPerson

    {

        private String str;

        public String FirstName

        {

            get { return str; }

            set { str = value; }

        }

    }
    class Program
    {

        static void Main(string[] args)
        {
            int a = 5;
            int s = 0, c = 0;
            Proc(a, ref s, ref c);
            Console.WriteLine(s + " " + c);
        }
        static void Proc(int x, ref int ss, ref int cc)
        {
            ss = x * x;
            cc = x * x * x;
        }
    }
}

