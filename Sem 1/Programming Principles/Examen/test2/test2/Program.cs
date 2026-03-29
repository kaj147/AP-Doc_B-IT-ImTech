namespace test2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int input;
            bool stop = false;

            Console.WriteLine("Hoeveel films wilt u beheren");
            input = Convert.ToInt32(Console.ReadLine());

            while (!stop)
            {
                string[] title = new string[input];
                int[] rating = new int[input];

                for (int x = 0; x < input; x++)
                {
                    Random random = new Random();

                    rating[x] = random.Next(0, 11);

                    if (rating[x] >= 8)
                    {
                        title[x] = $"*Film{x}";
                    }
                    else if (rating[x] < 4)
                    {
                        title[x] = $"!Film{x}";
                    }
                    else
                    {
                        title[x] = $"Film {x}";
                    }
                }
                ReadAll(title, rating);

                Console.WriteLine("Voer filmnummer in (-1 is stoppen): ");
                input = Convert.ToInt32(Console.ReadLine());

                if (input == -1)
                {
                    stop = true;
                }
            }

            void ReadAll(string[] title, int[] rating)
            {
                for (int x = 0; x < title.Length; x++)
                {
                    if (rating[x] >= 8)
                    {
                        Console.ForegroundColor = ConsoleColor.Blue;
                    }
                    else if (rating[x] < 4)
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                    }
                    else
                    {
                        Console.ResetColor();
                    }

                    Console.WriteLine($"{title[x]}      Rating: {rating[x]}");
                }

                Console.ResetColor();
                Console.WriteLine($"\nGemiddelde: {Average(rating)}");

                HighestLowestCount(rating);
            }

            double Average(int[] rating)
            {
                double avg = 0;

                foreach (int x in rating)
                {
                    avg += x;
                }
                return avg /= rating.Length;
            }

            void HighestLowestCount(int[] rating)
            {
                int highest = 0;
                int lowest = 10;
                int count = 0;

                foreach (int x in rating)
                {
                    if (x > highest)
                    {
                        highest = x;
                    }
                    if (x < lowest)
                    {
                        lowest = x;
                    }
                    if (x >= 8)
                    {
                        count++;
                    }
                }

                Console.WriteLine($"Hoogste: {highest}\nLaagste: {lowest}\nAantal keer 8 of meer: {count}");
            }
        }
    }
}
