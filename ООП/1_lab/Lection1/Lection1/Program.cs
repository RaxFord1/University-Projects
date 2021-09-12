using System;

namespace Lection1
{
    class Program
    {
        static void Main(string[] args)
        {
            // Завдання 1
            // Оголошення мінімум 4 змінних різних типів.Для кожного типу використати ключеве слово мови С# та тип із .Net.
            int pi1=245;
            System.Single pi2= 3.141592653589793238462643F;
            System.String pi3 = "3,1415926535";
            double pi4 = 3.141592653589793238462643;
            Console.WriteLine($"int value: {pi1}\nfloat value {pi2} \ndouble value {pi4} \nstring value {pi3}");

            // Завдання 2
            // Оголошення змінних різних типів (reference та value). Демонстрацію різниці в роботі оператора присвоєння для цих типів.
            byte b1 = 250, b2 = 6, b3;
            b3 = (byte)(b1 + b2);
            Console.WriteLine($"Сумма байт = {b3}");
            
            Console.Write("Как ваши дела? \n -");
            string happiness = Console.ReadLine();
            
            Console.Write("Напишите желаемую оценку по ООП за С#: ");

            int mark = Convert.ToInt32(Console.ReadLine());

            Console.Write("Напишите желаемую оценку по ООП за JAVA: ");
            double mark2 = Convert.ToDouble(Console.ReadLine());

            Console.Write("Напишите желаемую оценку по ООП за Python: ");
            uint mark3 = Convert.ToUInt32(Console.ReadLine());

            Console.WriteLine($"Ваши оценки по С# - {mark}; Java - {mark2} Python - {mark3}");

            // Завдання 3
            // Демонстрацію роботи з методами для різних типів даних (тобто показати, що вбудовані типи є об‘єктами структур).
            string whole = "SomE TExt.";
            Console.WriteLine($"Before: \n * {whole} *\n After: \n * {whole.ToLower()} *");
            double new_pi = double.Parse(pi3);
            string new_pi2 = new_pi.ToString()+" This was pi.";
            
            Console.WriteLine(new_pi2);

            // Завдання 4
            // Явне та неявне перетворення типів.
            pi4 = pi2; // неявне
            pi1 = (int)pi4; // явне

            // Завдання 5
            // Використання ключових слів checked / unchecked
            checked
            {
                int a1 = (int)(pi2*pi4);
            }
            double a2 = unchecked( pi2 * pi4);


            // Завдання 6
            // Роботу з нульовими типами даних.
            int? j = null;
            Console.WriteLine("j=" + j);
            j = j ?? 69;
            Console.WriteLine("j =" + j);

            // Завдання 7
            // Використання ключового слова var.
            var weight = 562.3446F;
            Console.WriteLine(weight.GetType().ToString());

            // Завдання 8
            // Використання ключового слова var.Меню (використати оператор switch), яке дозволяє вибрати, що вводити з клавіатури – ім‘я чи вік студента та завершувати роботу.
            Console.WriteLine("Хотите закрыть сессию?");
            string selection = Console.ReadLine().ToLower();
            switch (selection)
            {
                case "да":
                    Console.WriteLine("Удачи)");
                    break;
                case "нет":
                    Console.WriteLine("Здравствуй небо в облаках...");
                    break;
                default:
                    Console.WriteLine("Ну бывает");
                    break;
            }

            // Завдання 9
            // Фрагмент коду, в якому вводиться з клавіатури Ваше ім‘я та вік. Надалі виведиться Ваше ім‘я та кількість років, збільшених вдвоє, на екран. Обробку віку треба виконати в двох варіантах:
            // Без передбачення помилки введення
            // Обробити помилку при введенні числа з клавіатури.
            Console.Write("Введите ваше имя: ");
            string name = Console.ReadLine();
            Console.Write("Введите ваш возраст: ");
            int age = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine($"{name}, Ваш возраст увеличенный вдвое: {age*2}?");
            try
            {
                Console.Write("Введите ваш возраст 2: ");
                int age2 = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine($"Ваш возраст увеличенный вдвое: {age * 2}?");
            } catch
            {
                Console.WriteLine($"Вы ввели не правильный возраст?");
            }

            // Завдання 10
            // Додатково для поглибленого вивчення: Огляд можливостей класу Environment
            Console.WriteLine("Next will be 1 empty line" + Environment.NewLine);//перехід на новий рядок

            string[] ms = Environment.GetLogicalDrives();
            foreach (string elem in ms)
                Console.WriteLine("derive" + elem);

            Console.WriteLine("PATH: " + Environment.GetEnvironmentVariable("PATH"));


            Console.ReadKey();
        }
    }
}
