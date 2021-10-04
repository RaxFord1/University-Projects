using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Template
    {
        protected int numOfPages;
        protected string[] text;
        protected int maxNumberOfCharactersOnPage;
        public Template() {
        
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
        public virtual void Out(double i) {
            Console.WriteLine("Book Out double");
        }
        public virtual void Out(int i)
        {
            Console.WriteLine("Book Out int");
        }
    }
    class Magazine:Book{
        public new void Out() {
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
    class PrintedEdition : Book {
        public override void Out() {
            Console.WriteLine("PrintedEdition override Out");
        }
        public override void Out(int i) {
            Console.WriteLine("PrintedEdition override Out int");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
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
            Book[] books = { magazine, bookPrintedEdition, printedEdition,bookMagazine, book };

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
        }
    }
}
