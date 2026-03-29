using System.Security.Cryptography.X509Certificates;

namespace Bank_Manager
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Rekening rek1 = new Rekening();
            Rekening rek2 = new Rekening();


            rek1.naamKlant = "T";
            rek1.Rekeningnummer = "1";
            rek1.StortGeld(800);

            rek2.naamKlant = "K";
            rek2.Rekeningnummer = "2";
            rek2.StortGeld(800);

            rek1.ToonInfo();
            rek2.ToonInfo();

            while (true)
            {
                Console.WriteLine();

                Console.Write("Bedrag: ");
                int bedrag = Convert.ToInt32(Console.ReadLine());
                rek2.StortGeld(rek1.HaalGeldAf(bedrag));

                Console.WriteLine();

                rek1.ToonInfo();
                rek2.ToonInfo();
            }
        }
    }   
}
