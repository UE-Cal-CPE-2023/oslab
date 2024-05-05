using System;
class lab3
{
    static void Main()
    {
        int[] buffer = new int[10];
        int bufsize = 10, inIndex = 0, outIndex = 0, produce, consume, choice = 0;
        while (choice != 3)
        {
            Console.WriteLine("\n1. Produce \t 2. Consume \t3. Exit");
            Console.Write("\nEnter your choice: ");
            choice = Convert.ToInt32(Console.ReadLine());
            switch (choice)
            {
                case 1:
                    if ((inIndex + 1) % bufsize == outIndex)
                        Console.WriteLine("\n Buffer is Full");
                    else
                    {
                        Console.Write("\nEnter the value: ");
                        produce = Convert.ToInt32(Console.ReadLine());
                        buffer[inIndex] = produce;
                        inIndex = (inIndex + 1) % bufsize;
                    }
                    break;
                case 2:
                    if (inIndex == outIndex)
                        Console.WriteLine("\n Buffer is Empty");
                    else
                    {
                        consume = buffer[outIndex];
                        Console.WriteLine($"\n The consumed value is {consume}");
                        outIndex = (outIndex + 1) % bufsize;
                    }
                    break;
            }
        }
    }
}
