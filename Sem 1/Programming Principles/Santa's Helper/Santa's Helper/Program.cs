using System.IO;

namespace Santa_s_Helper
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string path = @"C:\Users\Christophe\Desktop\santa.txt";
            string[] file = File.ReadAllLines(path);

            string[] name = new string[file.Length-1];
            int[] age = new int[file.Length - 1];
            string[] toy = new string[file.Length - 1];
            string[] candy = new string[file.Length - 1];
            int[] present = new int[file.Length - 1];

            for (int x = 1; x < file.Length; x++)
            {
                string[] parsed = file[x].Split(',');

                name[x - 1] = parsed[0];
                age[x - 1] = Convert.ToInt32(parsed[1]);
                toy[x - 1] = parsed[2];
                candy[x - 1] = parsed[3];
                present[x - 1] = Convert.ToInt32(parsed[4]);
            }

            double average = 0;

            for (int x = 0; x < age.Length; x++)
            {
                average += age[x];
            }
            average /= age.Length;
            Console.WriteLine($"Gemiddelde leeftijd is: {average:0.000}");

            Console.Write("Geef een naam in: ");
            string askedName = Console.ReadLine();
            bool found = false;
            int posAskedName = 0;

            while (!found)
            {
                if(posAskedName < name.Length && name[posAskedName].ToLower() == askedName.ToLower())
                {
                    found = true;
                    Console.WriteLine($"Kind {name[posAskedName]} wilt {toy[posAskedName]}");
                }
                else if(posAskedName >= name.Length)
                {
                    Console.WriteLine("Kind niet gevonden");
                    found = true;
                }

                posAskedName++;
            }
            
        }
    }
}
