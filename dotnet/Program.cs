using Microsoft.CSharp.RuntimeBinder;
using System;

namespace SampleInterop
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");

            MyLibraryInterop.GetVersion();
            var sc = MyLibraryInterop.GetVersion();
            Console.WriteLine(sc);

            var bla = MyLibraryInterop.GetLongString();

            var se = new SpaceExclusion();
            try
            {
                se.Throwing();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.GetType());
                // e.Message
            }
        }
    }
}
