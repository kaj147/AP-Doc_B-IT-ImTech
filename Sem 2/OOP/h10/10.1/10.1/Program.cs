namespace _10._1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            LengthConv conv = new LengthConv();
            conv.lIM = 5;

            Console.WriteLine($"Length in meter: {conv.lIM}m, in km: {conv.lIKM}km, in cm: {conv.lICM}cm, in feet: {conv.lIF}feet");
        }
    }
}
