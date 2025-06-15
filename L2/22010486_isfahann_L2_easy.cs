using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace EasyLevel
{
    public class Program
    {
        // Function to return the index of the row with the maximum number of 1s
        static int Max1sRow(int[,] array)
        {
            int maxCount = -1;
            int maxRowIndex = -1;
            int rows = array.GetLength(0);
            int cols = array.GetLength(1);

            for (int i = 0; i < rows; i++)
            {
                int count = 0;
                for (int j = 0; j < cols; j++)
                {
                    if (array[i, j] == 1)
                        count++;
                }

                if (count > maxCount)
                {
                    maxCount = count;
                    maxRowIndex = i;
                }
            }

            return maxRowIndex;
        }

        // Main method must be static
        static void Main(string[] args)
        {
            int[,] array = new int[,]
            {
                {0, 1, 1},
                {1, 1, 1},
                {0, 0, 1}
            };

            Console.WriteLine("Index of row with maximum 1s is " + Max1sRow(array));
        }
    }
}
