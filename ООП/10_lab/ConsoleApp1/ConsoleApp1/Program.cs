using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Journal: IDisposable
    {
        static string size = "10x10";
        string path;
        bool disposed;

        StreamReader file;
        public Journal(string path)
        {
            file = new StreamReader(path);
        }
        ~Journal()
        {
            Dispose(disposing: false);
        }
        public string GetText()
        {
            return file.ReadLine();
        }
        
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this); //we dont need to call it when cleaning up
        }
        protected virtual void Dispose(bool disposing)
        {
            if (!this.disposed)
            {
                if (disposing)
                {
                    //managed
                    size = null;
                }
                //unmanaged resources
                path = null;
                file.Close();
                file.Dispose();
                disposed = true;
            }
        }
    }
class Program
    {
        static void Main(string[] args)
        {
            Journal journal = new Journal("D:/Num.txt");
            journal = null;
            GC.Collect();
            using (Journal journal2 = new Journal("D:/Num.txt"))
            {
                Console.WriteLine(journal2.GetText()); 
            }

            using (StreamReader file = new StreamReader("D:/Num.txt"))
            {
                int counter = 0;
                string ln;

                while ((ln = file.ReadLine()) != null)
                {
                    Console.WriteLine(ln);
                    counter++;
                }
                file.Close();
                Console.WriteLine($"File has {counter} lines.");
            }
            GC.Collect(1, GCCollectionMode.Forced);
            Console.ReadKey();
        }
    }
}
