using System;
using System.Linq;

class WordScrambler {
    static string[] wordList = { "computer", "science", "programming", "language", "keyboard" };
    static Random rand = new Random();

    static string Scramble(string word) {
        return new string(word.ToCharArray().OrderBy(x => rand.Next()).ToArray());
    }

    static void Main() {
        int score = 0;

        for (int round = 1; round <= 5; round++) {
            string word = wordList[rand.Next(wordList.Length)];
            string scrambled = Scramble(word);

            Console.WriteLine("Scrambled Word: " + scrambled);
            Console.Write("Guess: ");
            string guess = Console.ReadLine();

            if (guess == word) {
                Console.WriteLine("Correct");
                score++;
            } else {
                Console.WriteLine("Wrong. Word was: " + word);
            }
        }

        Console.WriteLine("Score: " + score + "/5");
    }
}
