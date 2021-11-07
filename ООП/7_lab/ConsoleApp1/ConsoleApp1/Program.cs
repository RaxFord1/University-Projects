using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Book<T1, T2>
    {
        T1 name = default(T1);
        T2 numOfPages = default(T2);
        public static T2 weight;
        public Book(T1 name, T2 numOfPages)
        {
            this.name = name;
            this.numOfPages = numOfPages;
        }
        public void Sum()
        {
            Console.WriteLine((dynamic)name + (dynamic)numOfPages);
        }

    }
    public enum DayOfWeekday : int { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
    public static class Extensions
    {
        public static void IsWeekend(this DayOfWeekday dayOfWeekend)
        {
            switch (dayOfWeekend)
            {
                case DayOfWeekday.Saturday:
                    Console.WriteLine("YRA!!!");
                    break;
                case DayOfWeekday.Sunday:
                    Console.WriteLine("YRA!!!");
                    break;
            }
        }
    }

    class Program
    {
        public static void GetEnum(string dayOfWeekend)
        {
            DayOfWeekday day = (DayOfWeekday)Enum.Parse(typeof(DayOfWeekday), dayOfWeekend);
            Console.WriteLine($"day = {day}, number = {(int)day}");
        }
        public static void GetEnum(DayOfWeekday dayOfWeekend)
        {
            Console.WriteLine($"day = {dayOfWeekend}, number = {(int)dayOfWeekend}");
        }
        public static void GetEnum(int dayOfWeekend)
        {
            DayOfWeekday day = (DayOfWeekday)dayOfWeekend;
            Console.WriteLine($"day = {day}, number = {(int)day}");
        }
        static void Main(string[] args)
        {
            GetEnum("Monday");
            GetEnum(DayOfWeekday.Sunday);
            GetEnum(6);
            DayOfWeekday.Wednesday.IsWeekend();
            DayOfWeekday.Saturday.IsWeekend();

            Book<int, float> book1 = new Book<int, float>(5, 2.3f);
            book1.Sum();
            Book<int, float>.weight = 17.53f;
            Console.ReadKey();
        }
    }
}
