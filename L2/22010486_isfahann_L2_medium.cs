using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace MediumLevel
{
    internal class Program
    {
        static void PrintMatrix(int[,] matrix)
        {
            int rows = matrix.GetLength(0);
            int cols = matrix.GetLength(1);

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    Console.Write(matrix[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
        static int[,] RotateMatrix(int[,] matrix)
        {
            int rows = (matrix.GetLength(0));
            int cols = (matrix.GetLength(1));

            int[,] mat = new int[cols, rows];

            for(int i = rows-1; i !=-1; i--)
            {
                int x = 0;
                for (int j = cols - 1; j != -1; j--)
                {
                    mat[x,i] = matrix[i,j];
                    x++;
                }
            }

            return mat;
        }


        static void Main(string[] args)
        {
            int[,] matrix = new int[,]
            {
                {1, 2, 3, 4 },
                {5, 6, 7, 8 },
                {9, 10, 11, 12 },
                {13, 14, 15, 16 }
            };

            int[,] rotated = RotateMatrix(matrix);
            PrintMatrix(rotated);
        }
    }
}
