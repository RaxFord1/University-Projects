using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    sealed class Utils
    {
        public const string OSNAME = "WINDOWS";
        public void Print(string[] args)
        {
            foreach (var arg in args)
            {
                Console.WriteLine(arg);
            }
        }
    }

    abstract class Person
    {
        protected int age;
        protected string name;
        abstract public string Name { get; set; }
        abstract public int Age { get; set; }
    }

    partial class Worker : Person
    {
        int paidDays;
        override public int Age
        {
            get => this.age;
            set => this.age = value;
        }
        override public string Name
        {
            get => this.name;
            set => this.name = value;
        }
        public Worker() : this("", 0)
        {

        }
        public Worker(string name, int age)
        {
            this.name = name;
            this.age = age;
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            String str1 = "Dont like Funkner";
            char[] sim = { 'I', 'o' };
            String str2 = new String(sim);
            String str3 = str1.Insert(str1.Length, " Unless u like Shon.");
            String str4 = "Row";
            Console.WriteLine(str1);
            Console.WriteLine(str2);
            Console.WriteLine(str3);

            Console.WriteLine(str1[0]);
            Console.WriteLine(str1.StartsWith("Dont"));
            Console.WriteLine(str1.Substring(4, 5));
            Console.WriteLine(str1.ToLower());
            Console.WriteLine(str1.ToUpper());

            String intern1 = "Hello", intern2 = "Hello", intern3 = "people", intern4 = "people";
            Console.WriteLine(Object.ReferenceEquals(intern1, intern2));
            Console.WriteLine(Object.ReferenceEquals(intern1, intern4));
            Console.WriteLine("reference = " + String.IsInterned(intern1));

            str4 = Console.ReadLine();
            Console.WriteLine("reference = " + String.IsInterned(str4));

            Console.WriteLine("intern1 == intern2: " + intern1.Equals(intern2));
            Console.WriteLine("intern2 == intern4: " + intern2.Equals(intern4));



            Worker worker = new Worker();
            Worker worker2 = new Worker();
            Console.WriteLine("worker1 == worker2: " + worker.Equals(worker2));
            worker.Print();
            worker.Age = 55;
            Console.WriteLine("Age: " + worker.Age);
            Console.WriteLine(Utils.OSNAME);
            Console.ReadKey();
        }
    }
}
