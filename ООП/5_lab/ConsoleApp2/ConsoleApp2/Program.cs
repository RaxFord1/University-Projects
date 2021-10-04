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

    class Template
    {
        protected int numOfPages;
        protected string[] text;
        protected int maxNumberOfCharactersOnPage;
        public Template()
        {

        }

        public void Out()
        {
            Console.WriteLine("Template Out");
        }

    }

    class Book : Template
    {
        public Book()
        {

        }
        public void Convert(Object obj)
        {
            Book book = obj as Book;
            if (book != null)
            {
                Console.WriteLine("Can convert");
            }
            else
            {
                Console.WriteLine("Cannot convert");
            }
        }
        public void Convert2(Template obj)
        {
            Book book = obj as Book;
            if (book != null)
            {
                Console.WriteLine("Can convert");
            }
            else
            {
                Console.WriteLine("Cannot convert");
            }
        }
        public new virtual void Out()
        {
            Console.WriteLine("Book Out");
        }
        public virtual void Out(double i)
        {
            Console.WriteLine("Book Out double");
        }
        public virtual void Out(int i)
        {
            Console.WriteLine("Book Out int");
        }
    }
    class Magazine : Book
    {
        public new void Out()
        {
            Console.WriteLine("Magazine new Out");
        }
        public new void Out(int i)
        {
            Console.WriteLine("Magazine new Out int");
        }
        public new void Out(double i)
        {
            Console.WriteLine("Magazine new Out double");
        }
    }
    class PrintedEdition : Book
    {
        public override void Out()
        {
            Console.WriteLine("PrintedEdition override Out");
        }
        public override void Out(int i)
        {
            Console.WriteLine("PrintedEdition override Out int");
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

            Book book1 = new Book();
            Book book2 = new Book();
            Book book3 = new Book();
            book1.Convert(book1);
            book2.Convert2(book3);

            Console.WriteLine();
            Console.WriteLine("Polimorfism");
            Magazine magazine = new Magazine();
            PrintedEdition printedEdition = new PrintedEdition();
            Book bookPrintedEdition = new PrintedEdition();
            Book bookMagazine = new Magazine();
            Book book = new Book();
            Book[] books = { magazine, bookPrintedEdition, printedEdition, bookMagazine, book };

            foreach (var b in books)
            {
                b.Out();
            }
            magazine.Out();
            printedEdition.Out();
            Console.WriteLine();
            Console.WriteLine("Out with arg");
            foreach (var b in books)
            {
                b.Out(5);
            }
            magazine.Out(5);
            printedEdition.Out(5);
            Console.WriteLine();
            Console.WriteLine("Out with arg double");
            foreach (var b in books)
            {
                b.Out(5.7);
            }
            magazine.Out(5.5);
            printedEdition.Out(5.5);


            Console.ReadKey();
            Console.ReadKey();
        }
    }
}
