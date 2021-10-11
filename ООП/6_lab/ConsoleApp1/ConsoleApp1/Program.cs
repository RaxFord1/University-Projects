using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace L6
{
    sealed class Journal
    {
        int numofPages;
        string text;
        public Journal(int numOfPages, string txt)
        {
            this.numofPages = numOfPages;
            this.text = txt;
        }
        public Journal(int result)
        {
            this.numofPages = result;
        }
        public Journal()
        {

        }
        public Journal(Journal target)
        {
            this.text = target.text;
            this.numofPages = target.numofPages;
        }
        public static Journal operator - (Journal firstJournal, Journal secondJournal)
        {
            StringBuilder sb = new StringBuilder(firstJournal.text);
            foreach (char ch in secondJournal.text)
            {
                sb.Replace(ch, char.MinValue);
            }
            string finalString = sb.ToString();

            return new Journal(firstJournal.numofPages - secondJournal.numofPages, finalString);
        }

        public static Journal operator --(Journal target)
        {
            Journal ta = new Journal(target.numofPages);
            ta.numofPages++;
            return ta;
        }
        public static int operator -(Journal target, int val)
        {
            return target.numofPages - val;
        }
        public static bool operator ==(Journal target, string val)
        {
            return target.text == val;
        }
        public static bool operator !=(Journal target, string val)
        {
            return !(target == val);
        }

        public static explicit operator Journal(int value)
        {
            return new Journal(value);
        }
        public static implicit operator Int32(Journal target)
        {
            return target.numofPages;
        }
        public override string ToString()
        {
            return $"Num of pages: {numofPages} Text: {text}";
        }
    }
    static class ExtendingClass
    {
        public static int AdditionalMethod(this Journal t)
        {
            int a = 40;
            int b = 80;
            return a + b;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Journal t1 = new Journal(2, "Dima");
            Journal t2 = new Journal(3, "Dzundza");
            Journal inSub = new Journal(0, " ");
            Console.WriteLine(t1);
            Console.WriteLine(t2);
            inSub = t1 - t2;
            Console.WriteLine($"Minus {inSub.ToString()} {Environment.NewLine}");
            Journal t3 = new Journal(40, "Alexa");
            Console.WriteLine(t3);
            Journal t4 = new Journal(0, " ");
            t4 = t3--;
            Console.WriteLine($"Decrement: {t4} {Environment.NewLine}");
            Journal t5 = new Journal(100, "Mary");
            Console.WriteLine(t5);
            int d = t5 - 27;
            Console.WriteLine($"Minus to num {d} {Environment.NewLine}");
            Journal resultValue = (Journal)80;
            Console.WriteLine($"Implicit: {resultValue}");
            Int32 expValue = (Int32)resultValue;
            Console.WriteLine($"Explicit: {expValue}");
            Journal other = (Journal)44;
            Console.WriteLine($"Расширение в действии {other.AdditionalMethod()}");
            Journal[] myArray = { t1, t2, inSub, t3, t4, t5 };
            Console.WriteLine("Please, type in a string u are looking for.");
            string myLine = Console.ReadLine();
            bool found=false;
            foreach (var el in myArray)
            {
                if (el == myLine)
                {
                    Console.WriteLine("There is a string.");
                    found = true;
                    break;
                }
            }
            if (!found) { 
                Console.WriteLine($"There is no string like this."); 
            }
            
            ThereIs:
            Console.ReadKey();
        }
    }
}
