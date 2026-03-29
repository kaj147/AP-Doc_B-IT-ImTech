namespace h9
{
    internal class Program
    {
        static void Main(string[] args)
        {
            StudentData studentData;
            studentData.name = "Alex";
            studentData.scores = new int[] { 14, 16, 11 };

            double avg = CalcAvg(studentData);
            Console.WriteLine($"Avg is: {avg} van student: {studentData.name}");
        }

        static double CalcAvg(StudentData data)
        {
            double avg = data.scores.Average();
            return avg;
        }
    }
}
