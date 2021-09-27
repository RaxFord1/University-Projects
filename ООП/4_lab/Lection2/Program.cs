using System;

namespace Lection2
{
    public static class TemperatureConverter
    {
        public static double CelsiusToFahrenheit(string temperatureCelsius)
        {
            double celsius = Double.Parse(temperatureCelsius);
            double fahrenheit = (celsius * 9 / 5) + 32;
            return fahrenheit;
        }

        public static double FahrenheitToCelsius(string temperatureFahrenheit)
        {
            double fahrenheit = Double.Parse(temperatureFahrenheit);
            double celsius = (fahrenheit - 32) * 5 / 9;
            return celsius;
        }
    }
    class Worker
    {
        int paidDays;
        double salary;
        const int maxWorkingDays = 24;
        public static string dzen = "I have no dzen.";
        readonly int minWorkingDays;
        int[] firstHalf = new int[15];
        int[] secondHalf = new int[15];
        static Worker() => dzen = "Beautiful is better than ugly.";
        public Worker(int _paidDays, double _salary, int _minWorkingDays = 3)
        {
            paidDays = _paidDays; // 22
            salary = _salary;
            minWorkingDays = _minWorkingDays;
            firstHalf = new int[(int)(_paidDays/2)];
            secondHalf = new int[(int)(_paidDays+1/2)];
        }
        public void Hours(int x)
        {
            Console.WriteLine("x input = " + x);
            x = 16;
            Console.WriteLine("x out doesn't change = " + x);
        }
        public void Hours(ref int x)
        {
            Console.WriteLine("x input = " + x);
            x = 8;
            Console.WriteLine("x out = " + x);
        }
        public void Weekend(out int x)
        {
            x = (int)(30 - paidDays);
        }
        public int Salary(params int[] salary_per_day)
        {
            int sum = 0;
    
            for (int i=0; i<salary_per_day.Length; i++)
            {
                sum += salary_per_day[i];
            }
            return sum;
        }

        public double CalculateTaxes(int daysWorked, double tax = 0.3, double fee = 0.1)
        { 
            // tax - налог на ЗП, fee - Сборы на что-то там
            if (daysWorked < minWorkingDays)
            {
                return 0;
            }
            double premium = (daysWorked > maxWorkingDays) ? 300 : 700;
            double salaryWithoutTaxes = salary * ((31 - daysWorked) - paidDays);
            double taxes = salaryWithoutTaxes * tax;
            double fees = salaryWithoutTaxes * fee;
            double salaryAfterTaxes = salaryWithoutTaxes - taxes - fees;
            Console.WriteLine($"Salary withour taxes = {salaryWithoutTaxes}; " + 
                            $"Taxes = {taxes}; " + 
                            $"Fees = {fees}; " + 
                            $"Salary after taxes = {salaryAfterTaxes}.");

            return salaryAfterTaxes;
        }
        public static string Print(params string[] args)
        {
            string result = dzen+"\n";
            foreach (var i in args) 
                result += i + "\n";
            return result;
        }

        public int this[int n]{
            get {
                if (n > firstHalf.Length-1 && n < firstHalf.Length-1 + secondHalf.Length-1) {
                    return secondHalf[n - firstHalf.Length];
                } else if (n < firstHalf.Length-1 && n >= 0) {
                    return firstHalf[n];
                }
                return 0;
            }
            set {
                if (n > firstHalf.Length && n < firstHalf.Length + secondHalf.Length-1)
                {
                    secondHalf[n - firstHalf.Length] = value;
                }
                else if (n < firstHalf.Length && n >= 0)
                {
                    firstHalf[n] = value;
                }
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var rand = new Random();
            int max_rand_value = 10;

            Console.WriteLine(Worker.dzen);

            Worker worker = new Worker(22, 1500);
            int firstDaySalary = 100;
            int secondDaySalary = 1000;
            int thirdDaySalary = 2500;
            int fourthDaySalary = 750;
            int fifthDaySalary = 904;
            double salary = worker.Salary(firstDaySalary, secondDaySalary, thirdDaySalary, fourthDaySalary, fifthDaySalary);
            Console.WriteLine($"Salary for last 5 days: = {salary}.");

            int howMuchHoursDoesWorkerWorks = 0;
            worker.Hours(howMuchHoursDoesWorkerWorks);
            Console.WriteLine($"howMuchHoursDoesWorkerWorks out value : {howMuchHoursDoesWorkerWorks}.");
            worker.Hours(ref howMuchHoursDoesWorkerWorks);
            Console.WriteLine($"Worker works {howMuchHoursDoesWorkerWorks} hours.");

            double toPay = worker.CalculateTaxes(5, fee: 0.2, tax: 0.4);
            Console.WriteLine($"Worker needs to be paid: {toPay} bucks");

            double toPay2 = worker.CalculateTaxes(5, fee: 0.05);
            Console.WriteLine($"Worker needs to be paid 2: {toPay2} bucks");

            int weekDays;
            worker.Weekend(out weekDays);
            Console.WriteLine($"Worker have {weekDays} resting days in month.");

            worker.Weekend(out var weekDays2);
            Console.WriteLine($"2.0 Worker have {weekDays2} resting days in month.");

            int[] firstArray = { 5, 2, 6, 7, 1, 4, 5, 9, 2 };
            int[] secondArray = new int[3];

            Array.Copy(firstArray, secondArray, 3);
            Console.WriteLine("Copied array: ");
            foreach (int value in secondArray)
                Console.Write($" {value},");
            Console.WriteLine("\b \b");

            Console.WriteLine("Sorted array");
            Array.Sort(firstArray);
            foreach (int value in firstArray)
                Console.Write($" {value},");
            Console.WriteLine("\b \b");

            Array.Clear(firstArray, 0, 3);
            Console.WriteLine($"First array elements after clear: ");
            foreach (int value in firstArray)
                Console.Write($" {value},");
            Console.WriteLine("\b \b");

            Console.WriteLine(Worker.Print("Explicit is better than implicit",
                "Simple is better than complex",
                "Complex is better than complicated"));

            for (int i = 0; i < 30; i++)
                worker[i] = rand.Next(-max_rand_value, max_rand_value);

            for (int i = 0; i < 30; i++)
                Console.Write($" i{i}: { worker[i]},");
            Console.WriteLine("\b \b");

            Console.WriteLine($"Temp: {TemperatureConverter.FahrenheitToCelsius("35")} "); 

            Console.ReadKey();
        }
    }
}
