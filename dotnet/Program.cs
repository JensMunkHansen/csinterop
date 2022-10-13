using MyLibraryInterop;
using System;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");
            
            MyLibraryInterop.MyLibraryInterop.GetVersion();
            var sc = MyLibraryInterop.MyLibraryInterop.GetVersion();
            Console.WriteLine(sc);

            var bla = MyLibraryInterop.MyLibraryInterop.GetLongString();
            
            var se = new SpaceExclusion();
            // se.InitializeVertices()
        }
    }
}
