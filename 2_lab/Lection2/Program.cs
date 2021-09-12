using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lection2
{
    class Program
    {
        static void Main(string[] args)
        {
            //Завдання 1
            int[] arrayInit = new int [] { 1, 27, 13, 46, 5, 17 }; //array with initialisation
            int [] arrayNoInit; //array witout initialisation
            arrayNoInit = new int[5]; //memory allocation
            arrayNoInit[0] = 16; //appeal to elements of array
            arrayNoInit[1] = 33;
            arrayNoInit[2] = 38;
            arrayNoInit[3] = 52;
            arrayNoInit[4] = 41;
            int sum = 0;
            foreach (int value in arrayInit) {
                sum += value;
            }
            Console.WriteLine($"Сумма элементов массива с инициализацией {sum}");
            Console.WriteLine($"Сумма элементов массива без инициализации {arrayNoInit.Sum()}");
            Console.WriteLine($"Длинна массива с инициализациией {arrayInit.GetLength(0)}");
            Console.WriteLine($"Длинна массива без инициализации {arrayNoInit.GetLength(0)}");
            //Завдання 2
            int[,] dimensionalArrayInit = new int[,] { {6, 97, 63, 47, 35 },
                                                       {22, 29, 51, 2, 9},
                                                       {44, 36, 21, 13, 3} };
            Console.WriteLine($"Длинна двумерного массива с инициализацией {dimensionalArrayInit.GetLength(1)}");
            
            int result = 1;
            for (int i = 0; i < dimensionalArrayInit.GetLength(0); i++)
            {
                for(int j = 0; j < dimensionalArrayInit.GetLength(1); j++) { 
                if (i % 2 == 0)
                {

                    result *= dimensionalArrayInit[i,j];
                }
                }
            }
            Console.Write($" Произведение четных строк матрицы = {result}");
            

            Console.WriteLine(Environment.NewLine);

            int[,] dimensionalArrayNoInit;
            dimensionalArrayNoInit = new int [5,5];
            
            Random ran = new Random();
            for (int i = 0; i < dimensionalArrayNoInit.GetLength(0); i++) {
                for (int j = 0; j < dimensionalArrayNoInit.GetLength(1); j++) {
                    dimensionalArrayNoInit[i, j] = ran.Next(13, 79);
                    Console.Write("{0}\t", dimensionalArrayNoInit[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine($"Длинна двумерного массива без инициализации {dimensionalArrayNoInit.GetLongLength(1)}");

            Console.WriteLine("\n");

            Drugs paracetamol = new Drugs("Парацетамол", 5, 23);
            Console.WriteLine(paracetamol);
            Drugs gutallax = new Drugs("Гуталлакс", 15, 112);
            Console.WriteLine(gutallax);
                if (paracetamol.Equals(gutallax))
                    Console.WriteLine("Схожи");
                else
                    Console.WriteLine("Не схожи");
            
            Console.ReadKey();
        }
    }
}