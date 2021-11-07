using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class MyException : Exception
    {
        int errorCode;
        public MyException(string mess, int errorCode) : base(mess)
        {
            this.errorCode = errorCode;
        }
        public int ErrorCode() { return errorCode; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int first = 5, second = 0;
            try
            {
                try
                {
                    //int zeroDivision = first / second;
                    //object o = null;
                    //o.ToString();
                    //throw new MyException("my error", 22);
                    String[] s = null;
                    String sep = " ";
                    String j = String.Join(sep, s);
                }
                catch (DivideByZeroException ex)
                {
                    Console.WriteLine("Division by 0 occured\n" + ex.StackTrace);
                    throw new DivideByZeroException("Message", ex);
                }
                catch (ArgumentNullException ex) {
                    Console.WriteLine("Argument Null Exception Occured");
                }
                catch (NullReferenceException ex)
                {
                    Console.WriteLine("Null Reference Exception Occured");
                }
                catch (Exception ex)
                {
                    Console.WriteLine("Base catch worked: " + ex.Message);
                }
                finally
                {
                    var date1 = new DateTime(2008, 5, 1, 8, 30, 52);
                    Console.WriteLine(date1);
                }
                var numbers = new List<int>() { 1, 2, 3, 4, 5 };
                foreach (var number in numbers)
                {
                    int square = (int)Math.Pow(number, 2);
                    Console.WriteLine("{0}^{1}", number, square);
                    Console.WriteLine("Adding {0} to the collection...\n", square);
                    numbers.Add(square);
                }
            }
            catch (DivideByZeroException ex)
            {
                Console.WriteLine("Second division by 0 occured\n" + ex.InnerException);
            }
            catch (InvalidOperationException ex)
            {
                Console.WriteLine("Invalid Operation Exception Occured");
            }
            catch {
                Console.WriteLine("Exception upper level");
            }
            
        }
    }
}
