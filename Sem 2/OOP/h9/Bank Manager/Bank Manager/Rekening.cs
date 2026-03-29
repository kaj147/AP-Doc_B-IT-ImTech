using System;
using System.Collections.Generic;
using System.Text;

namespace Bank_Manager
{
    public class Rekening
    {
        public enum RekeningStaat { Geldig, Geblokkeerd }
        public string naamKlant { get; set; }
        public string Rekeningnummer { get; set; }
        private int balans;
        public int Balans
        {
            get { return balans; }
        }

        public RekeningStaat Staat { get; private set; } = RekeningStaat.Geldig;


        public void StortGeld(int bedrag)
        {
            if (Staat == RekeningStaat.Geldig)
                balans += bedrag;
            else
                Console.WriteLine("Fout: Rekening geblokkeerd");
        }

        public int HaalGeldAf(int bedrag)
        {
            if (Staat == RekeningStaat.Geldig)
            {
                if (balans < bedrag)
                {
                    balans = 0;
                    Console.WriteLine("Fout: Rekening leeg nu");
                    VeranderStaat();
                }

                else
                {
                    balans -= bedrag;
                    return bedrag;
                }
            }
            else
            {
                Console.WriteLine("Fout: Rekening geblokkeerd");
            }
            return 0;
        }

        public void ToonInfo()
        {
            Console.WriteLine($"Bankgegevens:\nNaam klant: {naamKlant}\nRekeningnummer: {Rekeningnummer}\nBalans: {balans}");
        }

        public void VeranderStaat()
        {
            if (Staat == RekeningStaat.Geldig)
                Staat = RekeningStaat.Geblokkeerd;
            else
                Staat = RekeningStaat.Geldig;
        }
    }
}
