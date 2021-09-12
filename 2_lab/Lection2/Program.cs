using System;

namespace Lection2
{
    class WorkerBase
    {
        protected string _name;
        protected int _age;
        public string Name { get { return _name; } set { _name = value; } }
        public int Age { get { return _age; } set { _age = value; } }
        public WorkerBase() { }
        public WorkerBase(string name, int age)
        {
            Name = name;
            Age = age;
        }
    }
    class Worker : WorkerBase
    {
        public Worker() { }
        public Worker(string name, int age) : base(name, age) { }
        public override string ToString()
        {
            return $"name: {Name}; age: {_age}";
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
    }
    public struct WorkerStruct
    {
        public WorkerStruct(string name, int age)
        {
            Name = name;
            Age = age;
        }
        public WorkerStruct(string name)
        {
            Name = name;
            Age = 18;
        }
        public WorkerStruct(int age)
        {
            Name = "";
            Age = age;
        }
        public string Name { get; set; }
        public int Age { get; set; }
        public override string ToString() => $"Name: {Name}; age: {Age}";
    }
    public struct WorkerStruct1
    {
        public WorkerStruct1(string name, int age)
        {
            Name = name;
            Age = age;
        }
        public string Name { get; set; }
        public int Age { get; set; }
    }

    /*struct a: WorkerStruct {
    }*/

    /*class a: WorkerStruct {
    }*/
    class Program
    {
        static void Main(string[] args)
        {
            var rand = new Random();
            int max_rand_value = 10;
            //Завдання 1
            int[] array1 = new int[] { 5, 8, 1, 30 }; // Инициализация
            int[] array2; //Без инициализации
            array2 = new int[6]; //Расположение в памяти
            array2[0] = 0; //Присвоение каждому елементу значение
            array2[1] = 2;
            array2[2] = 35;
            array2[3] = 33;
            array2[4] = 46;
            array2[5] = 99;
            int product = 1;
            for (uint i = 0; i < array1.Length; i++)
            {
                product *= array1[i];
            }
            Console.WriteLine($"Произведение с инициализацией {product}");
            Console.WriteLine($"Длинна массива с инициализациией {array1.Length}");
            Console.WriteLine();
            product = 1;
            foreach (var value in array2)
            {
                product *= value;
            }
            Console.WriteLine($"Произведение без инициализации {product}");
            Console.WriteLine($"Длинна массива без инициализации {array2.GetLength(0)}");
            Console.WriteLine();
            //Завдання 2
            int[,] squaredArray1 = new int[,] { {1, 2, 3, 4 },
                                                {5, 6, 7, 8},
                                                {9, 10, 11, 12} };
            Console.WriteLine($"Высота двумерного массива с инициализацией {squaredArray1.GetLength(0)}");
            Console.WriteLine($"Длинна двумерного массива с инициализацией {squaredArray1.GetLength(1)}");

            int result = 0;
            for (int i = 0; i < squaredArray1.GetLength(0); i++)
                for (int j = 0; j < squaredArray1.GetLength(1); j++)
                    if (j % 2 != 0)
                        result += squaredArray1[i, j];
            Console.WriteLine($"Сумма нечётных столбцов матрицы с инициализацией = {result}");

            Console.WriteLine();

            Console.Write("Введите n: ");
            string input = Console.ReadLine();
            Console.WriteLine();
            int n, m;
            int.TryParse(input, out n);
            Console.Write("Введите m: ");
            input = Console.ReadLine();
            Console.WriteLine();
            int.TryParse(input, out m);
            int[,] squaredArray2 = new int[n, m];
            Console.WriteLine("Rank: " + squaredArray2.Rank);

            for (int i = 0; i < squaredArray2.GetLength(0); i++)
                for (int j = 0; j < squaredArray2.GetLength(1); j++)
                {
                    squaredArray2[i, j] = rand.Next(max_rand_value);
                    Console.WriteLine($"i:{i}, j:{j}, value:{squaredArray2[i, j]}");
                }
            Console.WriteLine($"Высота двумерного массива без инициализацией {squaredArray1.GetLength(0)}");
            Console.WriteLine($"Длинна двумерного массива без инициализации {squaredArray2.GetLength(1)}");

            result = 0;
            for (int i = 0; i < squaredArray2.GetLength(0); i++)
                for (int j = 0; j < squaredArray2.GetLength(1); j++)
                    if (i % 2 != 0)
                        result += squaredArray2[i, j];
            Console.WriteLine($" Сумма нечётных строк матрицы без инициализации = {result}");

            Console.WriteLine(Environment.NewLine);


            int r;
            while (true)
            {
                Console.Write("Введите количество строк: ");
                input = Console.ReadLine();
                Console.WriteLine();
                if (int.TryParse(input, out r))
                {
                    break;
                }
                Console.WriteLine("Вы ввели не правильное количество строк! Повторите попытку!");
            }
            // Создание и заполнение массива
            int[][] jagged = new int[r][];
            for (int i = 0; i < r; i++)
            {
                while (true)
                {
                    Console.Write($"Введите количество столбчиков в {i}-ой строке: ");
                    input = Console.ReadLine();
                    Console.WriteLine();
                    if (int.TryParse(input, out m))
                    {
                        jagged[i] = new int[m];
                        for (int j = 0; j < m; j++)
                        {
                            jagged[i][j] = rand.Next(max_rand_value);
                        }
                        break;
                    }
                    Console.WriteLine("Вы ввели не правильное количество столбцов! Повторите попытку!");
                }
            }
            result = 0;
            for (int i = 0; i < jagged.GetLength(0); i++)
                for (int j = 0; j < jagged[i].Length; j++)
                    if (j % 2 != 0)
                        result += jagged[i][j];

            Console.WriteLine($"Сумма нечётных столбцов матрицы = {result}");

            Console.WriteLine(Environment.NewLine);

            int value_to_cmp;
            while (true)
            {
                Console.Write($"Введите значение для сравнения: ");
                input = Console.ReadLine();
                Console.WriteLine();
                if (int.TryParse(input, out value_to_cmp))
                {
                    break;
                }
                Console.WriteLine("Вы ввели не правильное значение для сравнения! Повторите попытку!");
            }
            int repeats = 0;
            foreach (var value in array1)
            {
                if (value == value_to_cmp)
                {
                    repeats += 1;
                }
            }
            Console.WriteLine($"Колво повторов в 1D масиве- {repeats}!");

            repeats = 0;
            foreach (var value in squaredArray1)
                if (value == value_to_cmp)
                    repeats += 1;
            Console.WriteLine($"Колво повторов в 2D масиве - {repeats}!");

            repeats = 0;
            foreach (var row in jagged)
                foreach (var value in row)
                    if (value == value_to_cmp)
                        repeats += 1;
            Console.WriteLine($"Колво повторов в 2D невыровняном масиве - {repeats}!");

            Console.WriteLine();

            Console.ReadKey();
            Console.Clear();
            
            WorkerBase wb1 = new WorkerBase("Кристина", 12);
            WorkerBase wb2 = new WorkerBase("Кристинаa", 12);

            Console.WriteLine($"wb1: {wb1.ToString()}");
            Console.WriteLine($"wb1 == wb2: {wb1.Equals(wb2)}");
            Console.WriteLine($"wb2 == wb1: {wb2.Equals(wb1)}");
            Console.WriteLine($"wb1 == wb1: {wb1.Equals(wb1)}");
            Console.WriteLine();

            Worker w1 = new Worker();
            Worker w2 = new Worker("Дмитро", 18);
            w1.Name = "Дмитро";
            w1.Age = 19;
            Console.WriteLine($"w1: {w1.ToString()}");
            Console.WriteLine($"w2: {w2.ToString()}");
            Console.WriteLine($"w1 == w2: {w1.Equals(w2)}");
            Console.WriteLine($"w2 == w1: {w2.Equals(w1)}");
            Console.WriteLine($"w2 == w2: {w2.Equals(w2)}");
            Console.WriteLine();

            WorkerStruct ws1 = new WorkerStruct("Андрей", 15);
            WorkerStruct ws2 = new WorkerStruct("Игорь");
            WorkerStruct ws3 = new WorkerStruct(75);

            Console.WriteLine($"ws1: {ws1.ToString()}");
            Console.WriteLine($"ws2: {ws2.ToString()}");
            Console.WriteLine($"ws3: {ws3.ToString()}");

            //w1._name; - Буде помилка через модифікатор доступу
            Console.ReadKey();
        }
    }
}