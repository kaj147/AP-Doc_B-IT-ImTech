namespace Pong
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.CursorVisible = false;
            bool gameOver = false;
            const int FPS = 50;   //20fps
            const int waitTime = 1000 / FPS;

            int balX = Console.WindowWidth / 2;
            int balY = Console.WindowHeight / 2;

            int vX = 1;
            int vY = 1;

            int scoreLUser = 0;
            int scoreRUser = 0;

            const int lUserX = 3;
            int lUserY = 5;

            int rUserX = Console.WindowWidth - 3;
            int rUserY = 5;

            while (!gameOver)
            {
                //input verwerken
                //polling
                if(Console.KeyAvailable)
                {
                    ConsoleKeyInfo input = Console.ReadKey();

                    switch (input.Key)
                    {
                        case ConsoleKey.Spacebar:
                            scoreLUser++;
                            break;

                        case ConsoleKey.Z:
                            if (lUserY - 1 >= 0)
                            {
                                lUserY--;
                            }
                            break;

                        case ConsoleKey.S:
                            if (lUserY + 5 < Console.WindowHeight)
                            {
                                lUserY++;
                            }
                            break;

                        case ConsoleKey.O:
                            if (rUserY - 1 >= 0)
                            {
                                rUserY--;
                            }
                            break;
                        case ConsoleKey.L:
                            if(rUserY + 5 < Console.WindowHeight)
                            {
                                rUserY++;
                            }
                            break;
                    }
                }

                //gamestate update
                if(balX + vX >= Console.WindowWidth || balX + vX < 0)
                {
                    vX = -vX;

                    if(vX > 0)
                    {
                        scoreRUser++;
                    }
                    else
                    {
                        scoreLUser++;
                    }
                }
                if(balY + vY >= Console.WindowHeight || balY + vY < 0)
                {
                    vY = -vY;
                }

                balX += vX;
                balY += vY;

                //render
                
                //render bal
                Console.SetCursorPosition(balX, balY);
                Console.BackgroundColor = ConsoleColor.White;
                Console.Write(" ");
                Console.ResetColor();

                //render score
                Console.SetCursorPosition(Console.WindowWidth / 2, 2);
                Console.Write($"{scoreLUser} - {scoreRUser}");

                //render sides
                for(int x = 0; x < 5; x++)
                {
                    Console.SetCursorPosition(lUserX, lUserY + x);
                    Console.BackgroundColor = ConsoleColor.White;
                    Console.Write(" ");
                    Console.ResetColor();
                }

                for (int x = 0; x < 5; x++)
                {
                    Console.SetCursorPosition(rUserX, rUserY + x);
                    Console.BackgroundColor = ConsoleColor.White;
                    Console.Write(" ");
                    Console.ResetColor();
                }


                //wait

                Thread.Sleep(waitTime);

                Console.Clear();
            }
        }
    }
}
