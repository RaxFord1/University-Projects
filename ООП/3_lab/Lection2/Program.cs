using System;

namespace Lection2
{
    class Worker
    {
        private int[] array1 = new int[5];
        private string _name;
        private int _age;
        public string Name { get => _name; set => _name = value; }
        public string Surname { get; set; }
        public int Age { get { return _age; } set { _age = value; } }
        public int Lenght { get => array1.Length; }
        public int this[int i]
        {
            get => array1[i]; set => array1[i] = value;
        }

        public override string ToString()
        {
            return $"name: {Name}; surname: {Surname}; age: {Age}";
        }
        public override bool Equals(object obj)
        {
            if ((obj == null) || !this.GetType().Equals(obj.GetType()))
            {
                return false;
            }
            else
            {
                Worker p = (Worker)obj;
                return (Name == p.Name) && (Age == p.Age);
            }
        }

        public Worker() { }
        public Worker(string name, int age)
        {
            Name = name;
            Age = age;
        }
        public Worker(string name, string surname, int age)
        {
            Name = name;
            Age = age;
            Surname = surname;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var rand = new Random();
            int max_rand_value = 10;
            Worker worker = new Worker();
            Worker worker2 = new Worker("Aleksandr","Vasilevich", 52);

            worker.Name = "Dima";
            worker.Surname = "Dzundza";
            worker.Age = 19;

            Console.WriteLine(worker.ToString());
            Console.WriteLine($"Name: {worker2.Name}");
            Console.WriteLine($"Surname: {worker2.Surname}");
            Console.WriteLine($"Age: {worker2.Age}");

            for (int i = 0; i < worker.Lenght; i++) worker[i] = (int)rand.Next(-max_rand_value, max_rand_value);
            for (int i = 0; i < worker.Lenght; i++) Console.Write(" " + worker[i] + ",");

            Console.WriteLine("\b \b");
            Console.ReadKey();
        }
    }
}
