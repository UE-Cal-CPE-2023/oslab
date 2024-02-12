using System.Diagnostics;
class NCP2209_Lab1Cs
{
    static void Main(string[] args)
    {
        // Create a new process
        Process fork;

        try
        {
            // Start the process
            fork = execProcess("cmd", "/C whoami");

            // Print the process ID of both parent and child
            Console.WriteLine($"Parent PID is {Environment.ProcessId}");
            Console.WriteLine($"Child PID is {fork.Id}");

            // Wait for the process to finish
            fork.WaitForExit();
        }
        catch (Exception e)
        {
            Console.WriteLine("Failed to start fork! " + e.Message);
        }
    }
    
    private static Process execProcess(string command, string args)
    {
        Process p = new Process();
        p.StartInfo = new ProcessStartInfo(command, args);
        p.Start();

        return p;
    }
}