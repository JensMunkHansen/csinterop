using Interop;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");
            var sc = InteropModule.GetVersion();
            Console.WriteLine(sc);
            var se = new SpaceExclusion();
            

            
        }
    }
}
