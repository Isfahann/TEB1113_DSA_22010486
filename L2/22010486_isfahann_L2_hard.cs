using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace HardLevel
{
    internal class Program
    {
        static void PrintMatrix(int[,] matrix)
        {
            int r = matrix.GetLength(0);
            int c = matrix.GetLength(1);

            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    Console.Write(matrix[i, j] + " ");
                }
                Console.WriteLine();
            }
        }

        static int[,] FindOne(int[,] matrix)
        {
            int rows = matrix.GetLength(0);
            int cols = matrix.GetLength(1);

            int[,] mat = new int[rows, cols];

            bool[] rowMarker = new bool[rows];
            bool[] colsMarker = new bool[cols];

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (matrix[i, j] == 1)
                    {
                        rowMarker[i] = true;
                        colsMarker[j] = true;
                    }
                }
            }

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (rowMarker[i] || colsMarker[j])
                    {
                        mat[i, j] = 1;
                    }
                    else
                    {
                        mat[i, j] = matrix[i, j];
                    }
                }
            }
            return mat;
        }


        public static void Main(string[] args)
        {
            int[,] matrix = new int[,]
            {
            { 1, 0, 0, 1, 0},
            { 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 1},
            { 1, 0, 0, 1, 0}
            };

            int[,] markOne = FindOne(matrix);
            PrintMatrix(markOne);
        }
    }
}
