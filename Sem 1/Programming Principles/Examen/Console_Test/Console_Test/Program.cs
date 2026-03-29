namespace Console_Test
{
    internal class Program
    {
        static void Main(string[] args)
        {
            bool fix = false;
            string input;

            while(!fix)
            {
                Console.WriteLine("Coffee machine not working.");
                Console.WriteLine("Machine has power?");
                input = Console.ReadLine();

                if(input == "y")
                {
                    Console.WriteLine("Out of beans or water?");
                    input = Console.ReadLine();

                    if (input == "y")
                    {
                        fix = DeviceFixed();
                    }
                    else
                    {
                        Console.WriteLine("Filter warning?");
                        input = Console.ReadLine();

                        if (input == "y")
                        {
                            Console.WriteLine("Replace or clean filter");
                            fix = DeviceFixed();
                        }
                        else
                        {
                            Console.WriteLine("Send for repair");
                            fix = true;
                        }
                    }
                }
                else
                {
                    Console.WriteLine("Plug in and turn on\nDevice starts smoking!");
                }
            }

            bool DeviceFixed()
            {
                Console.WriteLine("Refill beans and water\nDevice fixed?");
                string input = Console.ReadLine();

                if (input == "y")
                {
                    Console.WriteLine("Fixed");
                    return true;
                }
                return false;
            }
        }
    }
}
