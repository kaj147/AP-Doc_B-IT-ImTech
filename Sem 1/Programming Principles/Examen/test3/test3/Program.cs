namespace test3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int workers;
            double price;

            Console.WriteLine("Geef het aantal werknemers:");
            workers = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Geef prijs per bezoeker:");
            price = Convert.ToDouble(Console.ReadLine());

            Hoofdmethode(workers, price);

            void Hoofdmethode(int workers, double price)
            {
                int visitors = 0;
                double money = 0;

                bool open = KanOpen(workers);

                if (open)
                {
                    visitors = BerekenBezoekersCapaciteit(workers);
                    money = BerekenDagOmzet(visitors, price);
                }
                ToonRapport(workers, open, visitors, money);
            }

            bool KanOpen(int workers)
            {
                if (workers >= 20)
                {
                    return true;
                }

                return false;
            }

            int BerekenBezoekersCapaciteit(int workers)
            {
                int visitors = workers * 50;
                return visitors;
            }

            double BerekenDagOmzet(int visitors, double ticket = 30)
            {
                double money = visitors * ticket;
                return money;
            }

            void ToonRapport(int workers, bool open, int visitors, double money)
            {
                Console.WriteLine("\n=== Dagrapport Pretpark ===");
                Console.WriteLine($"Werknemers: {workers}");
                if (open)
                {
                    Console.WriteLine("Park open: Ja");
                    Console.WriteLine($"Max. bezoekers: {visitors}\nVerwachte omzet: {money:### ### ###} euro");
                }
                else
                {
                    Console.WriteLine("Park open: Nee");
                }
            }
        }
    }
}
